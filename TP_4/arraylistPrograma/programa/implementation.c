#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Estructuras.h"
#include "ArrayList.h"
#include "implemetation.h"

/** \brief Muestra por pantalla un usuario y obtiene la opcion seleccionada
 *
 * \param menu: texto a mostrar por pantalla
 *
 * \return int - opcion elegida por el usuario
 */
int mostrarMenu(char *menu)
{
    int opcion;

    printf("\n---------------MENU------------------------\n\n");
    printf("%s",menu);
    printf("\n-------------------------------------------\n");

    printf("\nOpcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}

/** \brief Da de alta un usuario
 *
 * \param usuarios: arraylist donde se guardan los usuarios
 *
 * \return void
 */

void nuevoUsuario(ArrayList *usuarios)
{
    int id;

    char name[100];
    char nick[100];
    char pass[100];
    char mail[100];

    User *usuario;

    printf("\n==================\nNUEVO USUARIO\n==================\n");
    printf("Ingrese nombre: ");
    gets(name);
    printf("Ingrese nombre de usuario: ");
    gets(nick);
    printf("Ingrese password: ");
    gets(pass);
    printf("Ingrese email: ");
    gets(mail);

    id = usuarios->size;

    usuario = newUser(name, nick,pass,mail, id);

    usuarios->add(usuarios,usuario);

    printf("\n\nSE CREO USUARIO CORRECTAMENTE\n\n");
}

/** \brief Mdifica un usuario, pidiendo el nombre de usuario
 *         permitiendo modificar Nombre, Mail y/o Clave de acceso
 *
 * \param usuarios: arraylist donde se guardan los usuarios
 *
 * \return void
 */

void modificaUsuario(ArrayList *usuarios)
{
    int i;
    int estado = 0;

    char nickAux[100];
    char nameAux[100];
    char passAux[100];
    char mailAux[100];

    User *usuario;

    if(usuarios->size==0)
    {
        printf("NO HAY USUARIOS!!!\n\n");
    }
    else
    {
        printf("\n==================\nEDITAR USUARIO\n==================\n");
        printf("Ingrese su nombre de usuario: ");
        gets(nickAux);
        fflush(stdin);
        for(i=0; i<usuarios->size; i++)
        {

            usuario = usuarios->get(usuarios,i);

            if(strcmp(nickAux,usuario->nick) == 0)
            {
                estado = 1;
                printf("Ingrese su nuevo nombre: ");
                gets(nameAux);
                printf("Ingrese su nueva password: ");
                gets(passAux);
                printf("Ingrese su nuevo eMail: ");
                gets(mailAux);

                usuario = newUser(nameAux, usuario->nick,passAux,mailAux, usuario->id);

                usuarios->set(usuarios,usuario->id,usuario);
            }
        }
        if(estado == 0)
        {
            printf("\n\nNO SE PUDO GUARDAR\n\n");
        }
        else
        {
            printf("\n\nSE MODIFICO CORRECTAMENTE\n\n");
        }
    }
}

/** \brief Menu de borrado de usuarios.
 *
 * \param usuarios: arraylist donde se guardan los usuarios
 *
 * \return void
 */

void borrarUsuario(ArrayList * usuarios)
{
    int opcion,i;
    char usuarioAux1[100];
    char usuarioAux2[100];

    User *usuario;
    User *usuario2;


    if(usuarios->size==0)
    {
        printf("No se encontraron usuarios cargados.\n\n");
    }
    else
    {
        printf("Ingrese su nombre de usuario: ");
        gets(usuarioAux1);
        fflush(stdin);
        for(i=0; i < usuarios->size; i++)
        {

            usuario = usuarios->get(usuarios,i);

            if(strcmp(usuarioAux1,usuario->nick) == 0)
            {
                printf("\n==================\nELIMINAR USUARIO\n==================\n");
                opcion = mostrarMenu("[1]- Borrar un usuario\n[2]- Borrar y mostrar\n[3]- Borrar todos los usuarios \n[4]- Volver\n\n");
                fflush(stdin);
                printf("\n-------------------------------------------\n");

                switch(opcion)
                {
                case 1:
                    printf("Ingrese el usuario a borrar: ");

                    gets(usuarioAux2);
                    fflush(stdin);

                    for(i=0; i<usuarios->size; i++)
                    {

                        usuario = usuarios->get(usuarios,i);

                        if(strcmp(usuarioAux2,usuario->nick) == 0)
                        {
                            printf("USUARIO BORRADO\n\n");
                            usuarios->remove(usuarios,i);
                        }
                    }
                    break;

                case 2:
                    printf("Ingrese el usuario a borrar: ");

                    gets(usuarioAux2);

                    fflush(stdin);

                    for(i=0; i < usuarios->size; i++)
                    {
                        usuario = usuarios->get(usuarios,i);

                        if(strcmp(usuarioAux2,usuario->nick) == 0)
                        {
                            usuario2 = usuarios->pop(usuarios,i);

                            printf("USUARIO %s BORRADO\n\n",usuario2);
                        }
                    }
                    break;
                case 3:
                    usuarios->clear(usuarios);
                    printf("TODOS LOS USUARIOS HAN SIDO BORRADOS\n\n");
                    break;

                case 4:
                    goto end;
                    break;

                default:
                    printf("OPCION NO VALIDA\n\n");
                    system("pause");
                    system("cls");
                    break;
                }
            }
            else
            {
                printf("USUARIO NO ENCONTRADO\n\n");
            }
        }

    }

end: ;
}

/** \brief Creacion de un nuevo tweet
 *
 * \param listaUsuarios: arraylist donde se guardan los usuarios
 *
 * \param listaTweets: arraylist donde se guardan los tweets
 *
 * \return void
 */

void nuevoTweet(ArrayList *listaUsuarios,ArrayList *listaTweets)
{
    int i,id;
    char nickAux[100];
    char passAux[100];
    char commentAux[250];
    User *usuario;
    ETweets *tweet;

    printf("Ingrese su nombre de usuario: ");

    gets(nickAux);
    fflush(stdin);
    printf("Ingrese su password: ");
    gets(passAux);
    fflush(stdin);

    for(i=0; i<listaUsuarios->size; i++)
    {
        usuario = listaUsuarios->get(listaUsuarios,i);

        if((strcmp(nickAux,usuario->nick) == 0) && (strcmp(passAux,usuario->password) == 0))
        {
            system("cls");
            printf("\n==================\n NUEVO TWEET \n==================\n");
            printf("Escriba su tweet: ");
            gets(commentAux);
            fflush(stdin);

            id = listaTweets->size;

            tweet = newComment(commentAux, usuario->id,id);

            if(listaTweets->size > 0)
                listaTweets->push(listaTweets,0,tweet);
            else
                listaTweets->add(listaTweets,tweet);

        }
    }
}

/** \brief Asigna un ReTweet
 *
 * \param usuarios: arraylist donde se guardan los usuarios
 *
 * \param tweets: arraylist donde se guardan los tweets
 *
 * \return void
 */

void reTweet(ArrayList *usuarios,ArrayList *tweets)
{
    int i,id;
    char nickAux[100];
    char passAux[100];
    User *usuario;
    ETweets *tweet;

    printf("Ingrese su nombre de usuario: ");
    gets(nickAux);
    fflush(stdin);
    printf("Ingrese su password: ");
    gets(passAux);
    fflush(stdin);

    for(i=0; i<usuarios->size; i++)
    {
        usuario = usuarios->get(usuarios,i);

        if((strcmp(nickAux,usuario->nick) == 0) && (strcmp(passAux,usuario->password) == 0))
        {
            printf("Ingrese el numero de tweet: ");
            scanf("%d",&id);
            break;
        }
    }

    for(i=0; i < tweets->size; i++)
    {
        tweet = tweets->get(tweets,i);

        if(id == tweet->id)
        {
            tweet->likes++;

            printf("ReTweeteado con Exito!\n\n") ;
        }

    }


}

/** \brief Menu de funciones para informar datos en pantalla.
 * \param usuarios: arraylist donde se guardan los usuarios
 * \param tweets: arraylist donde se guardan los tweets
 * \param usuariosOriginales: arraylist donde se guardan los usuarios que se tenian al iniciar el programa
 * \param tweetsOriginales: arraylist donde se guardan los tweets que se tenian al iniciar el programa
 */
int informarContenido(ArrayList *usuarios,ArrayList *usuariosOriginales,ArrayList *tweets,ArrayList *tweetsOriginales)
{
    int i,j, opcion;
    int cantidadAMostrar = 5;
    ETweets* comment;
    ETweets *commentAux;
    User *usuario;
    User *userAux;
    ArrayList* pArray;

    opcion=mostrarMenu("[1]- Ver cantidad de usuarios activos\n[2]- Ver usuarios activos\n[3]- Ver cantidad tweets por usuario \n[4]- Ver ultimos cambios (LOG)\n[5]- Ver usuarios historicos\n");
    fflush(stdin);
    printf("\n-------------------------------------------\n");

    switch(opcion)
    {
    case 1:
        if(usuarios->isEmpty(usuarios) == 0)
        {
            printf("Hay %d usuarios registrados.\n\n",usuarios->len(usuarios));
        }

        if(usuarios->isEmpty(usuarios) == 1)
        {
            printf("No hay usuarios registrados.\n\n");
        }
        break;
    case 2:
        for(i=0; i < usuarios->size; i++)
        {
            printUser(usuarios->get(usuarios,i));
        }
        printf("\n");
        break;
    case 3:
        for(i=0; i<usuarios->size; i++)
        {
            usuario= usuarios->get(usuarios,i);
            printUser(usuarios->get(usuarios,i));

            for(j=0; j<tweets->size; j++)
            {
                comment = (tweets->get(tweets,j));
                if(usuario->id == comment->idUsuario)
                {
                    printf("Indice: %d. tweet: %s Nick:%s Cantidad de likes:%d\r\n\n",tweets->indexOf(tweets,*(tweets->pElements+j)),comment->comments,usuario->name,comment->likes);
                }
            }
        }
        printf("\n");

        break;

        {
        case 4:
            if((al_containsAll(usuarios, usuariosOriginales)) && (al_containsAll(tweets, tweetsOriginales)) && usuarios->size == usuariosOriginales->size && tweets->size == tweetsOriginales->size)
            {
                printf("No hay cambios recientes.\n\n");
            }
            else
            {
                for(i=0; i<usuarios->size; i++)
                {
                    userAux = usuarios->get(usuarios,i);
                    if(usuarios->contains(usuariosOriginales,userAux)==0)
                    {
                        printf("\n-----USUARIOS-----\nNombre= %s\nNombre de Usuario= %s\n",userAux->name, userAux->nick);
                    }
                }
                for(i=0; i<tweets->size; i++)
                {
                    commentAux = tweets->get(tweets,i);

                    if(tweets->contains(tweetsOriginales,commentAux)==0)
                    {
                        printf("\n-----TWEETS-----\nTweet= %s\nReTweets= %d\n",commentAux->comments, commentAux->likes);
                    }
                }
            }
            printf("\n");
            break;
        case 5:
            if(usuarios->size < cantidadAMostrar)
            {
                cantidadAMostrar = usuarios->size;
            }

            pArray = usuarios->subList(usuarios,0,cantidadAMostrar);

            printf("Los primeros usuarios fueron:");
            for(i=0; i<cantidadAMostrar; i++)
            {
                userAux = pArray->get(pArray,i);
                printf("\n\n[%d]\n\nNOMBRE = %s \n\nUSUARIO= %s",i+1,userAux->name,userAux->nick);
            }
            printf("\n\n\n");

            break;
        default:
            printf("No existe esa opcion... Reintente\n\n");
            system("pause");
            system("cls");
            break;
        }
    }
    return 0;
}

/** \brief LISTAR: Realiza un solo listado de los tweets con sus ReTweets
 *
 * \param usuarios: arraylist donde se guardan los usuarios
 *
 * \param tweets: arraylist donde se guardan los tweets
 *
 * \return void
 */

void listarContenido(ArrayList *usuarios,ArrayList *tweets)
{
    int i,j;
    ArrayList *clonarUsuarios;
    ETweets *tweet;
    User *userAux;

    clonarUsuarios = usuarios->clone(usuarios);

    al_sort(clonarUsuarios,compareUser,1);

    for(i=0; i<clonarUsuarios->size; i++)
    {
        userAux=al_get(clonarUsuarios,i);

        for(j=0; j<tweets->size; j++)
        {
            tweet = (tweets->get(tweets,j));

            if(userAux->id == tweet->idUsuario)
            {
                printf("\n====================================\nTweet #%d\n====================================\n\n @%s: %s \n\n\n====================================\n%d ReTweets\r\n\n====================================\n\n\n\n",j+1,userAux->nick,tweet->comments,tweet->likes);
            }
        }
    }
    clonarUsuarios->deleteArrayList(clonarUsuarios);
}

/** \brief Funcion para la carga iniciar de datos guardados en un archivo,
 * \param pList: arrayList donde se guardara la data levantada por la funcion
 * \param nombreArchivo: Nombre del archivo que contiene los datos.
 * \param opcion: parametro utilizado para diferenciar si el dato es un usuario (1) o tweet (2)
 * \return int
 */
int cargaArchivo(ArrayList* pList,char* nombreArchivo, int opcion)
{
    int flag = 1;
    int retorno = 1;
    FILE *archivo;
    User* users;
    ETweets* tweets;

    if(pList != NULL)
    {
        archivo = fopen(nombreArchivo, "rb");

        if(archivo == NULL)
        {
            flag = 0;
            archivo = fopen(nombreArchivo, "wb");
            if(archivo == NULL)
            {
                retorno = 0;
            }
        }

        if(flag == 1 && opcion == 1)
        {
            while(!feof(archivo))
            {
                users = malloc(sizeof(User));
                fread(users, sizeof(User),1,archivo);
                if(feof(archivo))
                {
                    break;
                }
                pList->add(pList, users);
            }
        }

        if(flag == 1 && opcion == 2)
        {
            while(!feof(archivo))
            {
                tweets = malloc(sizeof(ETweets));
                fread(tweets, sizeof(ETweets),1,archivo);
                pList->add(pList, tweets);
            }
        }
        fclose(archivo);
    }

    return retorno;
}

/** \brief Funcion para la guardar datos en un archivo,
 * \param pList: arrayList donde se encuentra la data a guardar
 * \param nombreArchivo: Nombre del archivo.
 * \param opcion: parametro utilizado para diferenciar si el dato es un usuario (1) o tweet (2)
 * \return int
 */
int guardarArchivo(ArrayList* pList, char* nombreArchivo, int opcion)
{
    int i;
    int retorno = 1;
    FILE *archivo;
    User* users;
    ETweets* tweets;

    if(pList != NULL)
    {
        archivo = fopen(nombreArchivo, "wb");
        if( archivo != NULL)
        {
            if(opcion ==1)
            {
                for(i = 0; i< pList->len(pList); i++)
                {
                    users = al_get(pList, i);
                    if(users != NULL)
                    {
                        fwrite(users, sizeof(User),1, archivo);
                    }
                }
            }
            if(opcion == 2)
            {
                for(i = 0; i< pList->len(pList); i++)
                {
                    tweets = al_get(pList, i);
                    if(tweets != NULL)
                    {
                        fwrite(tweets, sizeof(ETweets), 1, archivo);
                    }
                }
            }
            fclose(archivo);
        }
        else
        {
            retorno = -1;
        }
    }
    return retorno;
}
