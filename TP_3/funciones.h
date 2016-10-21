#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "defines.h"

/********************************
*                               *
*       FUNCIONES               *
*                               *
/*******************************/


int menu(void);

EMovie* newMovie(EMovie* movie, int count);

int exportToFile(EMovie* movie, int count);

EMovie* importFromFile(EMovie* movie, int* count);

void upMovie(EMovie* auxMovie, int count);

void getMovie(EMovie* movie, int count);

int exportToHTML(EMovie* movie, int count);

int editMovie(EMovie* movie, int count);

int removeMovie(EMovie* movie, int count);


/********************************
*                               *
*       VALIDACIONES            *
*                               *
/*******************************/



float getFloat(char mensaje[]);

int getInt(char text[]);

char getChar(char text[]);

int isNumber(char str[]);

int onlyString(char str[]);

int esAlfaNumerico(char str[]);

int isPhone(char str[]);

void getString(char mensaje[],char input[]);

int getStringLetras(char text[],char input[]);

int getStringNumeros(char text[],char input[]);

void toUpperCase(char *sPtr);


#endif // FUNCIONES_H_INCLUDED
