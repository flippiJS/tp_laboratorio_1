#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"
#define MAXIMO_INGRESO 20
#define ALTA 1

/**
 * \brief Verifica si en el array de estrucutra hay espacio libre
 * \param str Array con la cadena a ser analizada
 * \return el valor del indice libre si no muestra error
 *
 */
// Buscamos el lugar libre
int buscarLugarLibre(ABMPersona Persona[], int longitud)
{
    int bandera=0;

    int i = 0;

    for(i=0; i<longitud; i++)
    {
        if(Persona[i].Estado==0)
        {
           bandera=i;
           break;
        }
    }
    if(i==longitud)
    {
        printf("No hay mas espacio para guardar\n");
    }
    return bandera;
}
//Damos de Alta a una persona

/**
 * \brief Carga una nueva persona
 * \param Array con la cadena estructura
 * \return void
 *
 */

void cargaPersona(ABMPersona Persona[])
{
        int edadHasta18=3;
    int edad19a35=5;
    int edadMayor35=6;
    int i;
        system("cls");
        int lugar = buscarLugarLibre(Persona,MAXIMO_INGRESO);
        printf("\n-Ingrese NOMBRE: ");
        fflush(stdin);
        gets(Persona[lugar].Nombre);
            if(onlyChar(Persona[lugar].Nombre) == 0){
                printf("Debes ingresar un Nombre correcto\n");
                return 0;
            }

        printf("\n-Ingrese DNI: ");
        scanf("%d",&Persona[lugar].Dni);
        for(i=0; i<MAXIMO_INGRESO; i++)
        {
            if(Persona[i].Estado == 1 && Persona[i].Dni == Persona[lugar].Dni)
            {
                printf("\nYa existe el DNI ingresado! \n\n");
                return 0;
            }

        }
        fflush(stdin);
        printf("\n-Ingrese EDAD: ");
        scanf("%d",&Persona[lugar].Edad);
        Persona[lugar].Estado = 1;
        system("cls");
        printf("\nGuardado con exito! \n\n");

        //Sumamos Flag de Fecha para Graficar

        if(Persona[lugar].Edad<18){
            edadHasta18++;

        }else if(Persona[lugar].Edad <= 19 && Persona[lugar].Edad >= 35){
            edad19a35++;

        }else if(Persona[lugar].Edad > 35){
            edadMayor35++;
        }
}

// Borramos a la persona

/**
 * \brief Borra a una persona por DNI
 * \param Array con la cadena estructura
 * \return void
 *
 */
void bajaPersona(ABMPersona Persona[])
{
    int i;
    int dni;
    int indice=0;

    system("cls");
    printf("\n-Ingrese DNI a borrar:");
    scanf("%d",&dni);

    for(i=0; i<MAXIMO_INGRESO; i++)
    {
        if(Persona[i].Estado == 1 && Persona[i].Dni == dni)
        {
            indice=i;
            break;
        }

    }
    if(i==MAXIMO_INGRESO)
    {
       printf("\nNo se encuentra el DNI ingresado!\n\n");
       return 0;
    }
    printf("\nBorrado con exito!\n\n");
        Persona[indice].Estado = 2;
}
//Ordenaamos por Nombre

/**
 * \brief Muestra todos los registros guardados
 * \param Array con la cadena estructura
 * \return void.
 *
 */
void mostrarLista(ABMPersona Persona[])
{
    system("cls");

    int i,j;

    ABMPersona aux;

    for(i=0; i<MAXIMO_INGRESO-1; i++)
    {
        for(j=i+1; j<MAXIMO_INGRESO; j++)
        {

            if(strcmp(Persona[i].Nombre, Persona[j].Nombre)>0)
            {
                aux=Persona[i];
                Persona[i]=Persona[j];
                Persona[j]=aux;
            }
        }
    }
    for(i=0; i<MAXIMO_INGRESO; i++)
    {
        if(Persona[i].Estado != 0 && Persona[i].Estado != 2)
        {

            printf("\n----------------\n");
            printf("DNI: %d\n", Persona[i].Dni);
            printf("NOMBRE: %s\n", Persona[i].Nombre);
            printf("EDAD: %d\n", Persona[i].Edad);
            printf("----------------\n");
        }
    }
}

// Graficamos

/**
 * \brief Muestra grafico por edades
 * \param Array con
 * \return void
 *
 */

void graficarLista(int hasta18 ,int de19a35,int mayorDe35)
{
    system("cls");
    printf("\n--------------------\n");
    printf("GRAFICO POR EDADES");
    printf("\n--+-----------------\n");
    int i, flag=0, mayor;
if(hasta18 >= de19a35 && hasta18 >= mayorDe35)
    {
        mayor = hasta18;
    }else
    {
        if(de19a35 >= hasta18 && de19a35 >= mayorDe35)
        {
            mayor = de19a35;
        }
        else
        {
        mayor = mayorDe35;
        }
    }

    for(i=mayor; i>0; i--)
    {
        if(i<10){
            printf("%02d|",i);
        }
        else
            printf("%02d|",i);

        if(i<= hasta18)
        {
            printf("*");
        }
        if(i<= de19a35)
        {
            flag=1;
            printf("\t*");
        }
        if(i<= mayorDe35)
        {
            if(flag==0)
                printf("\t\t*");
            if(flag==1)
                printf("\t*");

        }
        printf("\n");
    }
    printf("--+-----------------");
    printf("\n  |<18\t19-35\t>35");
    printf("\n   %d\t%d\t%d\n\n", hasta18, de19a35, mayorDe35);
}

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float aux;

    printf("%s",mensaje);

    scanf("%f",&aux);

    return aux;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param  el mensaje a ser mostrado
 * \return Devuelve el numero ingresado
 *
 */
int getInt(char mensaje[])
{
    int aux;

    printf("%s",mensaje);

    scanf("%d",&aux);

    return aux;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return Devuelve el caracter ingresado
 *
 */
char getChar(char mensaje[])
{
    char auxiliar;

    printf("%s",mensaje);

    fflush(stdin);

    scanf("%c",&auxiliar);

    return auxiliar;
}


/**
 * \brief Comprueba que sean numeros
 * \param str es la cadena que se desea comprobar
 * \return Devuelve el valor 1 si contiene solo numeros y 0 si no
 *
 */

int onlyNum(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}
/**
 * \brief Comprueba que sean letras y espacios
 * \param str es la cadena que se desea comprobar
 * \return Devuelve el valor 1 si contiene solo letras y 0 si no
 *
 */
int onlyChar(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
    if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}



