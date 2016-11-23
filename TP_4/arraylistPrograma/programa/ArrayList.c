#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//_______________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* retorno = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            pList->add=al_add;
            pList->len=al_len;
            pList->set=al_set;
            pList->remove=al_remove;
            pList->clear=al_clear;
            pList->clone=al_clone;
            pList->get=al_get;
            pList->contains=al_contains;
            pList->push=al_push;
            pList->indexOf=al_indexOf;
            pList->isEmpty=al_isEmpty;
            pList->pop=al_pop;
            pList->subList=al_subList;
            pList->containsAll=al_containsAll;
            pList->deleteArrayList = al_deleteArrayList;
            pList->sort = al_sort;
            retorno = pList;
        }
        else
        {
            free(pList);
        }
    }

    return retorno;
}


/** \brief  Add an element to arrayList and if is nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 */
int al_add(ArrayList* pList,void* pElement)
{
    int retorno = -1;

    int cantidad = 0;

    if(pList != NULL && pElement != NULL)
    {
        if(pList->size == pList->reservedSize)
        {
            cantidad = resizeUp(pList);
        }

        if(cantidad != -1)
        {
            *((pList->pElements) + pList->size) = pElement;

            pList->size += 1;

            retorno=0;
        }
    }

    return retorno;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    int retorno = -1;

    int i;

    if(pList != NULL)
    {
        for(i=0; i < pList->size; i++)
        {
            free((pList->pElements)+i);
        }

        free(pList);

        retorno = 0;
    }

    return retorno;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)
{
    int retorno = -1;

    if(pList!=NULL)
    {
        retorno = pList->size;
    }

    return retorno;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList , int index)
{
    void* retorno = NULL;

    if(pList != NULL && index >= 0 && index <= pList->size)
    {
        retorno = *((pList->pElements)+index);
    }

    return retorno;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int retorno = -1;
    int i;

    if(pList != NULL && pElement != NULL)
    {
        retorno = 0;

        for(i=0; i < pList->size; i++)
        {
            if(pElement == pList->get(pList,i))
            {
                retorno = 1;
            }
        }
    }

    return retorno;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)
{
    int retorno = -1;

    if(pList != NULL && pElement != NULL && index>=0 && index<=pList->size)
    {
        if(index == pList->size)
        {
            al_add(pList,pElement);

        } else
        {
            *((pList->pElements)+index) = pElement;
        }

        retorno = 0;
    }

    return retorno;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)
{
    int retorno = -1;

    if(pList != NULL && index >= 0 && index < pList->size)
    {
        contract(pList,index);

        retorno = 0;
    }

    return retorno;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)
{
    int retorno = -1,i;

    if(pList != NULL)
    {
        for(i=0; i<=pList->size; i++)
        {
            *((pList->pElements) + i) = NULL;
        }

        pList->size = 0;

        retorno = 0;
    }

    return retorno;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)
{
    int i;

    ArrayList* retorno;

    retorno = al_newArrayList();

    if(pList != NULL && retorno!= NULL)
    {
        for(i=0;i<pList->size;i++)
        {
            al_add(retorno,al_get(pList,i));
        }
    }
    else
    {
         if(pList == NULL)
         {
             retorno = NULL;
         }

    }

    return retorno;
}

/** \brief Inserts the element at the specified position
 *
 * \param pList ArrayList* Pointer to arrayList
 *
 * \param index int Index of the element
 *
 * \param pElement void* Pointer to element
 *
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */

int al_push(ArrayList* pList, int index, void* pElement)
{
    int retorno = -1;

    if(pList != NULL && pElement != NULL && index>=0 && index<=pList->size)
    {
        expand(pList,index);

        pList->set(pList, index, pElement);

        retorno = 0;

        pList->size = pList->size +1;
    }

    return retorno;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int retorno = -1;

    int i;

    void* aux = pElement;

    if(pList != NULL && pElement != NULL)
    {
        for(i=0; i <= pList->size; i++)
        {
            if(aux == *(pList->pElements+i))
            {
                retorno = i;

                break;
            }
        }
    }

    return retorno;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)
{
    int retorno = -1;

    if(pList != NULL)
    {
        if(pList->size==0)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }
    }

    return retorno;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)
{
    void* retorno = NULL;


    if(pList != NULL && index>=0 && index <= pList->size)
    {
        retorno = pList->get(pList,index);

        contract(pList,index);
    }

    return retorno;
}

/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    int i;

    void* datos;

    ArrayList* list;

    list = al_newArrayList();

    if(pList != NULL && from >= 0 && to <= pList->size && to > from && to > 0 && from < pList->size)
    {
        for(i=from; i<=to; i++)
        {
            datos = pList->get(pList,i);
            pList->add(list,datos);
        }
    }
    else
    {
            al_deleteArrayList(list);
            list = NULL;
    }
    return list;
}


/** \brief Returns true if pList list contains all of the elements of pList2
* \param pList ArrayList* Pointer to arrayList
* \param pList2 ArrayList* Pointer to arrayList
* \return int Return (-1) if Error [pList or pList2 are NULL pointer]
*                  - (0) if Not contains All - (1) if is contains All
*/
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int retorno = -1;
    int contador = 0;
    int i;
    void* dato;

    if(pList != NULL && pList2 != NULL)
    {

        for(i=0; i<=pList2->size; i++)
        {
            dato = al_get(pList2,i);
            if(al_contains(pList,dato) == 1)
            {
                contador = contador +1;
            }
        }

        if(contador==pList2->size)
        {
            retorno=1;
        }
        else
        {
            retorno=0;
        }

    }

    return retorno;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)
{
    int retorno = -1, i,j,r;
    void* dato1, *dato2, *auxP;

    if(pList != NULL && pFunc != NULL && (order ==0 ||order ==1) )
    {
        for(i=0; i<pList->size-1; i++)
        {
            for(j=i+1; j<pList->size; j++)
            {
                dato1 = *((pList->pElements)+i);
                dato2 = *((pList->pElements)+j);
                r=pFunc(dato1, dato2);

                if(r==1 && order == 1)
                {
                    auxP=*((pList->pElements)+i);
                    *((pList->pElements)+i)=*((pList->pElements)+j);
                    *((pList->pElements)+j)=auxP;
                }
                if(r==-1 && order == 0)
                {
                    auxP=*((pList->pElements)+i);
                    *((pList->pElements)+i)=*((pList->pElements)+j);
                    *((pList->pElements)+j)=auxP;
                }
            }
        }
        retorno = 0;
    }
    return retorno;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)
{
    int retorno = -1;

    void* resize;

    if(pList != NULL)
    {
        resize = realloc(pList->pElements,sizeof(void*) * (pList->reservedSize+ AL_INCREMENT));

        if(resize != NULL)
        {
            pList->reservedSize += 10;
            retorno = 0;
            pList->pElements = resize;
        }
    }
    return retorno;

}

/** \brief  Expand an array list
 *
 * \param pList ArrayList* Pointer to arrayList
 *
 * \param index int Index of the element
 *
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int retorno = -1, expandir = 0,i;

    if(pList->size == pList->reservedSize)
    {
        expandir = resizeUp(pList);
    }

    if(pList != NULL && index >= 0 && index <= pList->size && expandir != -1)
    {
        for(i=pList->size+1 ; i>=index; i--)
        {
            *((pList->pElements)+1+i) =  *((pList->pElements)+i);
        }
        retorno = 0;
    }

    return retorno;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int retorno = -1,i;

    if(pList != NULL && index >= 0 && index <= pList->size)
    {
        for(i=index; i <= pList->size; i++)
        {
            *((pList->pElements)+i) =  *((pList->pElements)+i+1);
        }

        pList->size = pList->size -1;
    }

    return retorno;
}

