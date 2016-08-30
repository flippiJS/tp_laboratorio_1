#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    int op,resSuma,resResta,resDivi,resMulti,resFacto;
    int numero1 = 0;
    int numero2 = 0;

    do{
        op=menu(numero1,numero2);
        switch(op)
        {
            case 1:
                numero1=operando();
                break;
            case 2:
                numero2=operando();
                break;
            case 3:
                resSuma = suma(numero1,numero2);
                system("cls");
                printf("\n------------------------------------");
                printf("\n El resultado de la suma es: %d \n",resSuma);
                printf("------------------------------------\n");
                break;
            case 4:
                resResta = resta(numero1,numero2);
                system("cls");
                printf("\n------------------------------------");
                printf("\n El resultado de la resta es: %d \n",resResta);
                printf("------------------------------------\n");
                break;
            case 5:
                resDivi = divido(numero1,numero2);
                system("cls");
                printf("\n------------------------------------");
                printf("\n El resultado de la division es: %d \n",resDivi);
                printf("------------------------------------\n");
                break;
            case 6:
                resMulti = multiplico(numero1,numero2);
                system("cls");
                printf("\n------------------------------------");
                printf("\n El resultado de la multiplicacion es: %d \n",resMulti);
                printf("------------------------------------\n");
                break;
            case 7:
                resFacto = factorial(numero1);
                system("cls");
                printf("\n------------------------------------");
                printf("\n El resultado del factorizado es: %d \n",resFacto);
                printf("------------------------------------\n");
                break;
            case 8:
                resSuma = suma(numero1,numero2);
                resResta = resta(numero1,numero2);
                resDivi = divido(numero1,numero2);
                resMulti = multiplico(numero1,numero2);
                resFacto = factorial(numero1);
                system("cls");
                printf("\n------------------------------------");
                printf("\n Todas las operaciones: \n");
                printf("------------------------------------\n");
                printf("\n El resultado de la Suma es: %d \n",resSuma);
                printf("\n El resultado de la Resta es: %d \n",resResta);
                printf("\n El resultado de la Division es: %d \n",resDivi);
                printf("\n El resultado de la Multiplicacion es: %d \n",resMulti);
                printf("\n El resultado del Factorizado es: %d \n",resFacto);
                break;
            case 9:
                break;
        }
    }while(op != 9);

    printf("Adios!");

    return 0;
}
