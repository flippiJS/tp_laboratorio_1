#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAXIMO_INGRESO 20
#define ALTA 1

int main()
{
    int edadHasta18 = 0;
    int edad19a35 = 0;
    int edadMayor35 = 0;
    int i;
    char seguir='s';
    char auxPersona[128];
    char auxPersonaDNI[128];
    int opcion = 0;
	ABMPersona Persona[MAXIMO_INGRESO];
	inicializar(Persona,MAXIMO_INGRESO);

    while(seguir=='s')
    {
        printf("----------------\n");
        printf("Menu\n");
        printf("----------------\n");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir\n");
        printf("----------------\n");
        printf("Selecciona una opcion:\n");
        scanf("%d",&opcion);
        fflush(stdin);
        if(!isdigit(opcion)){
            printf("Debes seleccinar una opcion correcta\n");
        }
        switch(opcion)
        {
            case 1:
                system("cls");
                int lugar = buscarLugarLibre(Persona,MAXIMO_INGRESO);
                printf("\n-Ingrese NOMBRE: \n");
                fflush(stdin);
                gets(Persona[lugar].Nombre);
                    if(onlyChar(Persona[lugar].Nombre) == 0){
                        printf("Debes ingresar un Nombre correcto\n");
                        break;
                    }
                //
                obtenerCadena("\n-Ingrese DNI: ",auxPersonaDNI);
                if(!checkNum(auxPersonaDNI,11))
                {
                    system("cls");

                    printf("Debes ingresar un DNI valido.\n");

                    break;
                }
                Persona[lugar].Dni = atoi(auxPersonaDNI);
                //
                for(i=0; i<MAXIMO_INGRESO; i++)
                {
                    if(Persona[i].Estado == 1 && Persona[i].Dni == Persona[lugar].Dni)
                    {
                        printf("\nYa existe el DNI ingresado! \n\n");
                        goto end;
                    }
                }
                fflush(stdin);
                obtenerCadena("\n-Ingrese EDAD: ",auxPersona);
                if(!checkNum(auxPersona,4))
                {
                    system("cls");

                    printf("Debes ingresar una edad valida.\n");

                    break;
                }
                Persona[lugar].Edad = atoi(auxPersona);
                if(!checkInt(Persona[lugar].Edad,0,99))
                {
                    system("cls");

                    printf("Debes ingresar una edad valida\n");

                    break;
                }//
                Persona[lugar].Estado = 1;

                system("cls");

                printf("\nGuardado con exito! \n\n");

                //Sumamos Flag de Fecha para Graficar

                if(Persona[lugar].Edad < 18){
                    edadHasta18++;

                }else if(Persona[lugar].Edad > 18 && Persona[lugar].Edad < 35){
                    edad19a35++;

                }else if(Persona[lugar].Edad > 35){
                    edadMayor35++;
                }
                end:
                break;
            case 2:
                    system("cls");
                    int x = 0;
                    int dni = 0;
                    char auxPersonaDNI[128];
                    int indice=0;
                    obtenerCadena("\n-Ingrese DNI a borrar: ",auxPersonaDNI);
                    if(!checkNum(auxPersonaDNI,11))
                    {
                        system("cls");

                        printf("Debes ingresar un DNI valido.\n");
                        break;
                    }
                    dni = atoi(auxPersonaDNI);

                for(x=0; x<MAXIMO_INGRESO; x++)
                {
                    if(Persona[x].Estado == 1 && Persona[x].Dni == dni)
                    {
                        indice=x;
                        break;
                    }

                }
                if(x==MAXIMO_INGRESO)
                {
                   printf("\nNo se encuentra el DNI ingresado!\n\n");
                   break;
                }
                printf("\nBorrado con exito!\n\n");

                if(Persona[indice].Edad < 18){
                    edadHasta18--;

                }else if(Persona[indice].Edad > 18 && Persona[indice].Edad < 35){
                    edad19a35--;

                }else if(Persona[indice].Edad > 35){
                    edadMayor35--;
                }
                    Persona[indice].Estado = 2;
                break;
            case 3:
                mostrarLista(Persona);
                break;
            case 4:
                graficarLista(edadHasta18,edad19a35,edadMayor35);
                break;
            case 5:
                seguir = 'n';
                break;

            default:
                system("cls");
                break;
        }
    }

    return 0;
}
void inicializar(ABMPersona Persona[],int longitud){
	int i = 0;
	for(i=0; i<longitud; i++)
    {
        Persona[i].Estado = 0;
	}
}

