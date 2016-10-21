#include "defines.h"
#include "funciones.h"

/********************************
*                               *
*       FUNCIONES               *
*                               *
/********************************

/**
* \brief Muestra el menú principal y espera por la entrada de la opción seleccionada
* \param void
* \return int Devuelve el número de opción elegido por el usuario o -1 en caso de opcion incorrecta.
*/
int menu(void){

	char input[200];

	system("cls");

	printf(MENU_OPTIONS);

	scanf("%s", input);

	if(isdigit(input[0])){
		return atoi(&input[0]);
	}else{
		return -1;
	}
}

/**
* \brief Agrega espacio en memoria y una nueva pelicula
* \param EMovie* Vector que se guardara a pelicula
* \param int count Contador de cantidad de peliculas guardadas
* \return EMovie* Devuelve la pelicula creada o NULL en caso de no poder creearla
*/

EMovie* newMovie(EMovie* movie, int count){

	movie = (EMovie*) realloc(movie, sizeof(EMovie) * count);

	if(movie != NULL){

        upMovie(movie, count);

	}else{

		printf("\n Error al crear espacio.\n");
		system("pause");

	}
	return movie;
}

/**
* \brief Guarda en el archivo de datos los registros cargados
* \param EMovie* Vector donde se almacenan las peliculas
* \param int count Contador de cantidad de peliculas guardadas
* \return int 0 si pudo guardarlo correctamente o -1 en caso de error
*/

int exportToFile(EMovie* movie, int count)
{
    int retorno = -1;
	FILE* archivo;

	archivo = fopen("./database.dat", "w");

	if(archivo != NULL){

        fwrite(movie, sizeof(EMovie), count, archivo);
        retorno = 0;

	} else {

		printf("\n Error al guardar el archivo ./database.dat \n\n");
		system("pause");
	}

	return retorno;
}

/**
* \brief Importa desde el archivo los registros que este tiene cargados
* \param EMovie* Vector donde se almacenan las peliculas
* \param int count puntero al contador de cantidad de peliculas guardadas
* \return EMovie* movie con las peliculas cargadas o NULL en caso de error
*/

EMovie* importFromFile(EMovie* movie, int* count){

    EMovie* retorno = NULL;
    int size;
	FILE* file;
	int i;

	file = fopen("./database.dat", "r");

	if(file != NULL){

        fseek(file, 0, SEEK_END);
        size = ftell(file);
        (*count) = size / sizeof(EMovie);
        fseek(file, 0, SEEK_SET);
        movie = (EMovie*) realloc(movie, sizeof(EMovie) * (*count));

        if(movie==NULL){
            printf("\n No se pudo asignar espacio en memoria para la carga de datos. \n");
            system("pause");
            retorno = NULL;
            goto end;
        }

        for(i=0; i<(*count); i++){

            fread(&movie[i], sizeof(EMovie), 1, file);

        }

        retorno = movie;

    } else {
        printf("\n No existe ningun archivo de datos de peliculas \n");
        system("pause");
    }

    end:

	return retorno;
}

/**
* \brief Pide los datos al usuarios para ser cargados en el Vector
* \param EMovie* Vector donde se almacenan las peliculas
* \param int count puntero al contador de cantidad de peliculas guardadas
* \return void
*/

void upMovie(EMovie* auxMovie, int count)
{
    count = count-1;
	char aux[500];

	system("cls");

    printf("\n******************* \n");
	printf("\n NUEVA PELICULA\n");
    printf("\n******************* \n");

	auxMovie[count].id = count;

	printf("\nIngrese el titulo: ");
    fflush(stdin);
	gets(aux);
	strcpy(auxMovie[count].titulo, aux);

	printf("\nIngrese el genero: ");
	fflush(stdin);
	gets(aux);
	strcpy(auxMovie[count].genero, aux);

	printf("\nIngrese la descripcion: ");
	fflush(stdin);
	gets(aux);
	strcpy(auxMovie[count].descripcion, aux);

    printf("\nIngrese la duracion (Minutos): ");
    scanf("%d", &auxMovie[count].duracion);
    fflush(stdin);

    printf("\nIngrese el puntaje (1 a 10): ");
    scanf("%3d", &auxMovie[count].puntaje);
    fflush(stdin);

	printf("\nIngrese la URL de Portada: ");
	fflush(stdin);
	gets(aux);
	strcpy(auxMovie[count].urlPortada, aux);
}

/**
* \brief Lista en pantalla todas las peliculas que hay en el Vector
* \param EMovie* Vector donde se almacenan las peliculas
* \param int count puntero al contador de cantidad de peliculas guardadas
* \return void
*/

void getMovie(EMovie* movie, int count){

    system("cls");
	int i;

    printf("\nLISTADO DE PELCULAS CARGADAS: \n");

	for(i=0; i<count; i++){
        if(movie[i].id != -1){
        printf("\n******************* \n");

		printf("ID: %d\n", movie[i].id);

		printf("TITULO: %s\n", movie[i].titulo);

		printf("GENERO: %s\n", movie[i].genero);

		printf("DESCRIPCION: %s\n", movie[i].descripcion);

		printf("DURACION(minutos): %d\n", movie[i].duracion);

		printf("PUNTAJE: %d\n", movie[i].puntaje);

		printf("URL PORTADA:\n%s\n", movie[i].urlPortada);

        printf("\n******************* \n");
        }
	}
}

/**
* \brief Exporta a un archivo index.html todas las peliculas que hay en el Vector
* \param EMovie* Vector donde se almacenan las peliculas
* \param int count puntero al contador de cantidad de peliculas guardadas
* \return int 0 si exporto con exito o  -1 en caso de error
*/
int exportToHTML(EMovie* movie, int count){

	int i;
    int retorno = -1;
	FILE *web;

	web = fopen("./index.html", "w");

	if(web == NULL){

		printf("\n Error al crear el archivo ./index.html");
		system("pause");

	} else {

        fprintf(web, "%s", WEB_HEAD);

        for(i=0; i<count; i++){
            if(movie[i].id != -1){
            fprintf(web, "%s", WEB_URL_IMG);
            fprintf(web, "%s", movie[i].urlPortada);

            fprintf(web, "%s", WEB_TITULO);
            fprintf(web, "%s", movie[i].titulo);

            fprintf(web, "%s", WEB_GENERO);
            fprintf(web, "%s", movie[i].genero);

            fprintf(web, "%s", WEB_PUNTAJE);
            fprintf(web, "%d", movie[i].puntaje);

            fprintf(web, "%s", WEB_DURACION);
            fprintf(web, "%d", movie[i].duracion);

            fprintf(web, "%s", WEB_DESCRIPCION);
            fprintf(web, "%s", movie[i].descripcion);

            fprintf(web, "%s", WEB_CIERRE_ARTICLE);
            }
        }
        fprintf(web, "%s", WEB_BODY);

        fclose(web);
        retorno = 0;
	}

	return retorno;
}

/**
* \brief Edita un registro de una pelicula por ID
* \param EMovie* Vector donde se almacenan las peliculas
* \param int count puntero al contador de cantidad de peliculas guardadas
* \return int 0 si edito con exito o  -1 en caso de error
*/

int editMovie(EMovie* movie, int count){

	system("cls");
	char aux[500];
	int auxId,auxInt;
	int i;
	int retorno = -1;
    printf("\n******************* \n");
	printf("\n MODIFICAR\n");
    printf("\n******************* \n");
	printf("\nIngrese el ID de la pelicula: ");
	scanf("%d", &auxId);
	fflush(stdin);

	for(i=0; i<count; i++){

		if(movie[i].id == auxId){

			printf("\n  ID: %d\n", movie[i].id);
            printf("Ingrese el nuevo titulo: ");
            fflush(stdin);
            gets(aux);
            strcpy(movie[i].titulo, aux);

            printf("Ingrese el nuevo genero: ");
            fflush(stdin);
            gets(aux);
            strcpy(movie[i].genero, aux);

            printf("Ingrese la nueva descripcion: ");
            fflush(stdin);
            gets(aux);
            strcpy(movie[i].descripcion, aux);

            printf("Ingrese la nueva duracion (Minutos) : ");
            scanf("%d", &auxInt);
            fflush(stdin);
            movie[i].duracion = auxInt;

            printf("Ingrese el nuevo puntaje (1 a 10): ");
            scanf("%d", &auxInt);
            fflush(stdin);
            movie[i].puntaje = auxInt;

            printf("Ingrese la nueva URL de Portada: ");
            fflush(stdin);
            gets(aux);
            strcpy(movie[i].urlPortada, aux);

            retorno = 0;
		}
	}

	return retorno;
}


/**
* \brief Elimina logicamente una pelicula por ID
* \param EMovie* Vector donde se almacenan las peliculas
* \param int count puntero al contador de cantidad de peliculas guardadas
* \return int 0 si elimino con exito o  -1 en caso de error
*/
int removeMovie(EMovie* movie, int count){

    system("cls");
	int i,auxId;
	int retorno = -1;

    printf("\n******************* \n");
	printf("\n BORRAR\n");
    printf("\n******************* \n");
	printf("\nIngrese el ID de la pelicula: ");
	scanf("%d", &auxId);
	fflush(stdin);

	for(i=0; i<count; i++){
		if(movie[i].id == auxId){
			movie[i].id = -1;
			retorno = 0;
		}
	}

	return retorno;
}

/********************************
*                               *
*       VALIDACIONES            *
*                               *
/********************************

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float getFloat(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char text[])
{
    int auxiliar;

    printf("%s",text);

    scanf("%d",&auxiliar);

    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char getChar(char text[])
{
    char auxiliar;

    printf("%s",text);

    fflush(stdin);

    scanf("%c",&auxiliar);

    return auxiliar;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int isNumber(char str[])
{
   int i=0;

   int retorn = 1;

   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           retorn = 0;
       i++;
   }

   return retorn;
}
/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacios y letras o 0 si no lo es
 *
 */
int onlyString(char str[])
{
   int i= 0;

   int retorn = 1;

   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           retorn = 0;
       i++;
   }

   return retorn;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[])
{
   int i=0;
   int retorn = 1;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           retorn = 0;
       i++;
   }

   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int isPhone(char str[])
{
   int i=0;

   int count=0;

   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            count++;
       i++;
   }
   if(count==1){
        return 1;
   }
    return 0;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    scanf ("%s", input);
}

/**
 * \brief Pide un string y lo devuelve
 * \param text Es el mensaje a ser mostrado
 * \param input Array donde cargará el string ingresado
 * \return 1 si el texto contiene solo letras 0 si no
 */
int getStringLetras(char text[],char input[])
{
    char aux[200];
    int retorn = 0;
    getString(text,aux);

    if(onlyString(aux))
    {
        strcpy(input,aux);
        retorn = 1;
    }
    return retorn;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int getStringNumeros(char text[],char input[])
{
    char aux[200];
    getString(text,aux);
    if(isNumber(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Pasa a mayuscula una cadena de string
 * \param Array de string
 * \return void
 */
void toUpperCase(char *sPtr)
{
  while ( *sPtr != '\0' ) {
    *sPtr = toupper ((unsigned char) *sPtr );
    ++sPtr;
  }
}
