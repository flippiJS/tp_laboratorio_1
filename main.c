#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "funciones.h"

int main()
{
    int opcion,resSuma,resResta,resMulti;
    float resDivi;
    double resFacto;
    int numero1 = 0;
    int numero2 = 0;

    do{
        opcion = menu(numero1,numero2);
        switch(opcion)
        {
            case 1:
                numero1 = operando();
                break;
            case 2:
                numero2 = operando();
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
                if(numero2 == 0){
                    system("cls");
                    printf("\n------------------------------------");
                    printf("\n No se puede dividir por 0 \n");
                    printf("------------------------------------\n");
                } else {
                    resDivi = divido(numero1,numero2);
                    system("cls");
                    printf("\n------------------------------------");
                    printf("\n El resultado de la division es: %f \n",resDivi);
                    printf("------------------------------------\n");
                }
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
                printf("\n El resultado del factorizado es: %lf \n",resFacto);
                printf("------------------------------------\n");
                break;
            case 8:
                if(numero2 == 0 && numero1 < 1){
                    resSuma = suma(numero1,numero2);
                    resResta = resta(numero1,numero2);
                    resMulti = multiplico(numero1,numero2);
                    system("cls");
                    printf("\n------------------------------------");
                    printf("\n Todas las operaciones: \n");
                    printf("------------------------------------\n");
                    printf("\n El resultado de la Suma es: %d \n",resSuma);
                    printf("\n El resultado de la Resta es: %d \n",resResta);
                    printf("\n No es posible dividir por 0 \n");
                    printf("\n El resultado de la Multiplicacion es: %d \n",resMulti);
                    printf("\n No es posible calcular el factorial de 0 o negativo \n");
                    printf("------------------------------------\n");
                } else if(numero1 < 1) {
                    resSuma = suma(numero1,numero2);
                    resResta = resta(numero1,numero2);
                    resDivi = divido(numero1,numero2);
                    resMulti = multiplico(numero1,numero2);
                    system("cls");
                    printf("\n------------------------------------");
                    printf("\n Todas las operaciones: \n");
                    printf("------------------------------------\n");
                    printf("\n El resultado de la Suma es: %d \n",resSuma);
                    printf("\n El resultado de la Resta es: %d \n",resResta);
                    printf("\n El resultado de la Division es: %f \n",resDivi);
                    printf("\n El resultado de la Multiplicacion es: %d \n",resMulti);
                    printf("\n No es posible calcular el factorial de 0 o negativo \n");
                    printf("------------------------------------\n");
                } else if (numero2 == 0){
                    resSuma = suma(numero1,numero2);
                    resResta = resta(numero1,numero2);
                    resMulti = multiplico(numero1,numero2);
                    resFacto = factorial(numero1);
                    system("cls");
                    printf("\n------------------------------------");
                    printf("\n Todas las operaciones: \n");
                    printf("------------------------------------\n");
                    printf("\n El resultado de la Suma es: %d \n",resSuma);
                    printf("\n El resultado de la Resta es: %d \n",resResta);
                    printf("\n No es posible dividir por 0 \n");
                    printf("\n El resultado de la Multiplicacion es: %d \n",resMulti);
                    printf("\n El resultado del Factorizado es: %lf \n",resFacto);
                    printf("------------------------------------\n");
                } else {
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
                    printf("\n No es posible dividir por 0 \n");
                    printf("\n El resultado de la Multiplicacion es: %d \n",resMulti);
                    printf("\n El resultado del Factorizado es: %lf \n",resFacto);
                    printf("------------------------------------\n");
                }
                break;
            case 9:
                break;
        }
    }while(opcion != 9);

    printf("Adios!");

    return 0;
}
