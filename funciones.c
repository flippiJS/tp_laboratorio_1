#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>

//Ingreso

int operando()
{
    int num;
    char dato[10];
    system("cls");
    printf("\n------------------------------------\n");
    printf("Ingrese un operando \n");
    printf("------------------------------------\n");
	scanf("%s", &dato);
    fflush(stdin);
    printf("------------------------------------\n");
    printf("Numero guardado! \n");
    printf("------------------------------------\n");

    return atoi(&dato[0]);
}

//Menu
int menu(numero1,numero2){
    int opcion;
    printf("\n-----Menu----");
    printf("\n 1- Ingresar 1er operando (A=%i)", numero1);
    printf("\n 2- Ingresar 2do operando (B=%i)", numero2);
    printf("\n 3- Calcular la suma (A+B)");
    printf("\n 4- Calcular la resta (A-B)");
    printf("\n 5- Calcular la division (A/B)");
    printf("\n 6- Calcular la multiplicacion (A*B)");
    printf("\n 7- Calcular el factorial (A!)");
    printf("\n 8- Calcular todas las operaciones");
    printf("\n 9- Salir");
    printf("\n--------------");
    printf("\n Seleccione una opcion:");
    scanf("%d",&opcion);
    fflush(stdin);
    return opcion;
}


//Suma
int suma(numero1,numero2){
    int resul;
    resul = numero1+numero2;
    return resul;
}

//Resta
int resta(numero1,numero2){
    int resul;
    resul = numero1-numero2;
    return resul;
}
//Division
float divido(numero1,numero2){
    float resul;
    resul = (float)numero1 / (float)numero2;
    return resul;
}
//Multiplicacion
int multiplico(numero1,numero2){
    int resul;
    resul = numero1*numero2;
    return resul;
}

//Factorizado
double factorial(numero1){

    double resultado=1;
    double factorial;
    factorial=numero1;
    while(factorial>1){
    resultado=resultado*factorial;
    factorial=factorial-1;
}
    return resultado;
}

