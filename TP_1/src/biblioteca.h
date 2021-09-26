/*
 * biblioteca.h
 *
 *  Created on: 10 sep. 2021
 *      Author: Mati
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_

/// @fn float IngresarFlotante(char[]).
/// @brief Pide y devuelve un numero flotante.
///
/// @param El texto que se muestra al pedir el numero flotante.
/// @return El numero ingresado.
float IngresarFlotante(char[]);

/// @fn int ImprimirMenu(float, float).
/// @brief Imprime em pantalla el menu de opciones.
///
/// @param Imprime valor de A.
/// @param Imprime el valor de B.
/// @return Retorna la opcion elegida.
int ImprimirMenu(float, float);

/// @fn float CalcularSuma(float, float).
/// @brief Suma A + B
///
/// @param Valor de A.
/// @param  Valor de B.
/// @return Resultado de la suma.
float CalcularSuma(float, float);

/// @fn float CalcularResta(float, float).
/// @brief Resta A - B.
///
/// @param Valor de A.
/// @param Valor de B.
/// @return Resultado de la resta.
float CalcularResta(float, float);

/// @fn float CalcularDivision(float, float).
/// @brief Divide A / B.
///
/// @param Valor de A.
/// @param Valor de B.
/// @return Resultado de la division.
float CalcularDivision(float, float);

/// @fn float CalcularMultiplicacion(float, float).
/// @brief Multiplica A * B.
///
/// @param Valor de A.
/// @param Valor de B.
/// @return
float CalcularMultiplicacion(float, float);

/// @fn int ValidarEnteroODecimal(float).
/// @brief Valida un numero decimal.
///
/// @param Numero flotante a validar.
/// @return Retora 1 si es sin decimal | Retorna 0 si es con decimal.
int ValidarEnteroODecimal(float);

/// @fn int CalcularFactorial(float).
/// @brief Calcula el factorial de un numero.
///
/// @param Numero flotante a validar.
/// @return Retorna el factorial.
int CalcularFactorial(float);

#endif /* BIBLIOTECA_H_ */
