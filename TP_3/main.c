/********************************
*                               *
*  TP 3 - Franco Lippi - 1F     *
*                               *
/*******************************/


#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include "defines.h"

int main()
{
	int count = 0;

	EMovie *movie = NULL;

    int option=0;

    movie = importFromFile(movie, &count);

   do{
		option = menu();

		switch(option){
            case MENU_OPTIONS_1:
                count++;
				movie = newMovie(movie,count);
                exportToFile(movie,count);
                printf("\n******************* \n");
                printf("\n Se ha guardado con exito.\n");
                printf("\n******************* \n");
                system("pause");
                break;

            case MENU_OPTIONS_2:
                if(count != 0){
                    if(removeMovie(movie, count) == -1) {
                        printf("\n******************* \n");
                        printf("\n ID no valido.\n");
                        printf("\n******************* \n");
                        system("pause");
                    }else {
                        exportToFile(movie,count);
                        printf("\n******************* \n");
                        printf("\n Se ha borrado con exito los datos.\n");
                        printf("\n******************* \n");
                        system("pause");
                    }
                }
                break;

            case MENU_OPTIONS_3:
                if(count != 0){
                    if(editMovie(movie, count) == -1) {
                        printf("\n******************* \n");
                        printf("\n ID no valido.\n");
                        printf("\n******************* \n");
                        system("pause");
                    }else {
                        exportToFile(movie,count);
                        printf("\n******************* \n");
                        printf("\n Se ha modificado con exito los datos.\n");
                        printf("\n******************* \n");
                        system("pause");
                    }
                }
                break;

            case MENU_OPTIONS_4:
                if(exportToHTML(movie, count) == 0){
                    printf("\n******************* \n");
					printf("\n Se ha exportado con exito los datos.\n");
                    printf("\n******************* \n");
                	system("pause");
                }
                break;

			case MENU_OPTIONS_5:
                getMovie(movie, count);
                system("pause");
                break;

			case MENU_OPTIONS_6:

                break;

			default:
			    printf(MENU_ERROR"\n");
				system("pause");
				break;
        }
    } while(option!=6);

    return 0;
}
