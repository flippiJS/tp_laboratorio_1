#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Muestra un mensaje en pantalla saludando al usuario
 *
 * \param void
 * \return void
 *
 */
void saludar(void);



/** \brief Solicita un número al usuario
 *
 * \param void
 * \return El número ingresado por el usuario
 *
 */
int operando();



/** \brief Muestra el menu de opciones
 *
 * \param Primer numero
 * \param Segundo numero
 * \return La opcion seleccionada por el usuario
 *
 */
int menu(int,int);



/** \brief Calcula la suma de 2 numeros
 *
 * \param Primer numero
 * \param Segundo numero
 * \return El resultado de la operacion
 *
 */
int suma(int,int);



/** \brief Calcula la resta de 2 numeros
 *
 * \param Primer numero
 * \param Segundo numero
 * \return El resultado de la operacion
 *
 */
int resta(int,int);



/** \brief Calcula la division de 2 numeros
 *
 * \param Primer numero
 * \param Segundo numero
 * \return El resultado de la operacion
 *
 */
int divido(int,int);



/** \brief Calcula la mutliplicacion de 2 numeros
 *
 * \param Primer numero
 * \param Segundo numero
 * \return El resultado de la operacion
 *
 */
int multiplico(int,int);



/** \brief Calcula el factorial de 1 numeros
 *
 * \param Numero
 * \return El resultado de la operacion
 *
 */
int factorial(int);



#endif // FUNCIONES_H_INCLUDED
