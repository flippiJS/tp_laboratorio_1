#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/ArrayList.h"

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

    if(pList != NULL && pElement != NULL)
    {
        if(!resizeUp(pList))
        {
            pList->pElements[pList->size] = pElement;

            pList->size++;

            retorno = 0;

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

    if(pList != NULL)
    {
        free(pList->pElements);

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

    if(pList!=NULL){

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

    if(pList != NULL && index >= 0 && index < pList->size){

        retorno = pList->pElements[index];
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
    int i;
    int retorno = -1;

    if(pList != NULL && pElement != NULL)
    {
        for(i=0; i < pList->size; i++)
        {
            if(pList->pElements[i] == pElement)
            {
                retorno = 1;
                break;
            }
            else
            {
                retorno = 0;
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

    if(pElement != NULL && pList != NULL && index >= 0 && index <= pList->size)
    {
        pList->pElements[index] = pElement;

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

    void *auxiliar;

    if(pList != NULL && index >= 0 && index < pList->size )
    {
        if(pList->reservedSize - AL_INCREMENT > pList->size)
        {
            auxiliar = realloc(pList->pElements,sizeof(void *)*(pList->reservedSize - AL_INCREMENT));

            if(auxiliar != NULL)

                pList->pElements = auxiliar;
        }

        pList->pElements[index] = NULL;

        pList->size--;

        retorno =0;
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
    int retorno = -1;

    ArrayList *pAux;

    if(pList != NULL)
    {
        pAux = realloc(pList->pElements,sizeof(void*)*AL_INITIAL_VALUE);

        retorno = 0;

        if(pAux != NULL){

            pList->size = 0;

            free(pList->pElements);

            pList->pElements = pAux;
        }
        else {
            retorno = -1;
        }
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
    ArrayList* retorno = NULL;

    if(pList != NULL)
    {
        retorno = al_newArrayList();

        if(retorno != NULL)
        {
            for(i=0; i<= pList->size; i++){

                al_add(retorno,al_get(pList,i));
            }
        }
    }
    return retorno;
}



/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)
{
    int retorno = -1;

    if(pList != NULL && pElement != NULL && index >= 0 && index <= pList->size)
    {
        expand(pList,index);

        pList->set(pList, index, pElement);

        retorno = 0;

        pList->size = pList->size + 1;
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
    int i;
    int retorno = -1;

    if(pList != NULL && pElement != NULL)
    {
        for(i=0;i < pList->size; i++)
        {
            if(pList->pElements[i] == pElement)
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
        if(pList->size == 0){

            retorno=1;

        }else{

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

    if(pList != NULL && index >= 0 && index < pList->size)
    {
        retorno = pList->pElements[index];

        pList->pElements[index] = NULL;
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
    ArrayList* retorno = NULL;

    if(pList != NULL && from >= 0 && to <= pList->size && from < to )
    {
        retorno = al_newArrayList();

        if(retorno != NULL)
        {
            for(i=from; i < to; i++)
            {
                al_add(retorno,al_get(pList,i));
            }
        }
    }
    return retorno ;
}


/** \brief Returns true if pList list contains all of the elements of pList2
* \param pList ArrayList* Pointer to arrayList
* \param pList2 ArrayList* Pointer to arrayList
* \return int Return (-1) if Error [pList or pList2 are NULL pointer]
*                  - (0) if Not contains All - (1) if is contains All
*/
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int i;
    int retorno = -1;

    if(pList != NULL && pList2 != NULL)
    {
        retorno = 1;

        for(i=0; i < pList2->size; i++)
        {
            if(al_contains(pList,al_get(pList2,i))!= 1)
            {
                retorno = 0;
                break;
            }
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
    int retorno = -1;

    void *aux;

    if(pList!=NULL && ( order==1 || order==0 ) && pFunc!=NULL)
    {
        int i,j;

        for(i=0; i < pList->size - 1 ; i++)
        {
            for(j= i + 1; j < pList->size; j++)
            {
                if(order == 1 && pFunc(pList->pElements[i],pList->pElements[j]) > 0)
                {
                    aux = pList->pElements[i];

                    pList->pElements[i] = pList->pElements[j];

                    pList->pElements[j] = aux;

                    retorno = 0;
                }
                else if( !order && pFunc (pList->pElements[i],pList->pElements[j]) < 0)
                {
                    aux = pList->pElements[i];

                    pList->pElements[i] = pList->pElements[j];

                    pList->pElements[j] = aux;

                    retorno = 0;
                }
            }
        }
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
    void *auxiliar;

    if(pList != NULL)
    {
        if(pList->size == pList->reservedSize)
        {
            auxiliar = realloc(pList->pElements,sizeof(void*)*(pList->reservedSize + AL_INCREMENT));

            if(auxiliar != NULL)
            {
                pList->pElements = auxiliar;

                pList->reservedSize = pList->reservedSize + AL_INCREMENT;

                retorno = 0;
            }
        }
        else
        {
           retorno = 0;
        }
    }

    return retorno;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int retorno = -1;
    void *auxiliar;

    if(pList != NULL)
    {
        if(pList->reservedSize - pList->size > AL_INCREMENT)
        {
            auxiliar = realloc(pList->pElements,sizeof(void*)*(pList->size + AL_INCREMENT));

            if(auxiliar != NULL)
            {
                pList = auxiliar;
                retorno = 0;
            }
        }
        else
            retorno = 0;
    }

}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int i;
    int retorno = -1;

    if(pList != NULL && index >= 0 && index <= pList->size)
    {
        for(i=index; i <= pList->size; i++)
        {
            pList->pElements[i] = pList->pElements[i+1];
        }

        pList->size--;

        retorno = 0;
    }
    return retorno;
}
