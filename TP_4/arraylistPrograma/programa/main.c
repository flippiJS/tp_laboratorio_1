#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


#include "Estructuras.h"
#include "ArrayList.h"
#include "implemetation.h"


int main(void)
{
    ArrayList* usuarios = al_newArrayList();
    ArrayList* tweets = al_newArrayList();

    /** CARGAMOS DATOS DESDE ARCHIVOS */

    if(cargaArchivo(usuarios, "usuarios.dat", 1)){

        printf("Cargado con exito base de datos de usuarios...\n");

    }else{

        printf("No se pudo cargar la base de datos de usuarios...\n\n\n");
    }

    if(cargaArchivo(tweets, "tweets.dat", 2)){

        printf("Cargado con exito base de datos de tweets...\n\n\n");

    }else{

        printf("No se pudo cargar la base de datos\n\n\n");
    }


    ArrayList* tweetsOriginales = tweets->clone(tweets);
    ArrayList* usuariosOriginales = usuarios->clone(usuarios);

    system("pause");
    system("cls");


    char guardar;
    int opcion;
    char seguir='s';

    while(seguir == 's')
    {
        printf("\n---------------MENU------------------------\n\n");
        printf(" [1]- Nuevo Usuario\n [2]- Modificar Usuario\n [3]- Borrar Usuario\n [4]- Tweetear \n [5]- Re-Tweetear\n [6]- Estadisticas\n [7]- Ir a los Tweets\n [8]- Salir\n ");
        printf("\n-------------------------------------------\n");
        printf("\nOpcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
        printf("\n-------------------------------------------\n");
        fflush(stdin);

        switch(opcion)
        {
        case 1:
            nuevoUsuario(usuarios);
            system("pause");
            system("cls");
            break;
        case 2:
            modificaUsuario(usuarios);
            system("pause");
            system("cls");
            break;
        case 3:
            borrarUsuario(usuarios);
            system("pause");
            system("cls");
            break;
        case 4:
            nuevoTweet(usuarios,tweets);
            system("pause");
            system("cls");
            break;
        case 5:
            reTweet(usuarios,tweets);
            system("pause");
            system("cls");
            break;
        case 6:
            informarContenido(usuarios,usuariosOriginales,tweets,tweetsOriginales);
            system("pause");
            system("cls");
            break;
        case 7:
            listarContenido(usuarios,tweets);
            system("pause");
            system("cls");
            break;
        case 8:
            printf("\nDesea guardar los cambios?: (S/N)");

            guardar = tolower(getche());

            if(guardar == 's')
            {
                if(guardarArchivo(usuarios, "usuarios.dat", 1))
                {
                    printf("\nSe guardaron los usuarios con exito\n");
                }
                else
                {
                    printf("\nNo se pudo guardar, Error\n");
                }

                if(guardarArchivo(tweets, "tweets.dat", 2))
                {
                    printf("\nSe guardaron los tweets con exito\n");
                }
                else
                {
                    printf("\nNo se pudo guardar, Error\n");
                }

            }
            else
            {
                printf("\nCONTENIDO NO GUARDADO!\n");
            }
            usuarios->deleteArrayList(usuarios);
            tweets->deleteArrayList(tweets);
            seguir='n';
            break;
        default:
            printf("Opcion no valida, vuelva a intentarlo.\n\n");

            system("pause");

            system("cls");
            break;
        }
    }
}
