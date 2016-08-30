//Saludo

void saludar(void)
{
    system("cls");
    printf("Hola hola!");
    return;
}

//Ingreso

int operando()

{   int num;
    system("cls");
    printf("\n------------------------------------\n");
    printf("Ingrese un operando \n");
    printf("------------------------------------\n");
    scanf("%d",&num);
    printf("\n Numero Guardado! \n");
    printf("------------------------------------\n");
    return num;
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
    printf("\n---------");
    printf("\n Seleccione una opcion:");
    scanf("%d",&opcion);

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
int divido(numero1,numero2){
    int resul;
    resul = numero1/numero2;
    return resul;
}
//Multiplicacion
int multiplico(numero1,numero2){
    int resul;
    resul = numero1*numero2;
    return resul;
}

//Factorizado
int factorial(numero1){

    int resultado=1;
    int factorial;
    factorial=numero1;
    while(factorial>1){
    resultado=resultado*factorial;
    factorial=factorial-1;
}
    return resultado;
}

