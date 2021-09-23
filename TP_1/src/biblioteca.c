/*
 * biblioteca.c
 *
 *  Created on: 10 sep. 2021
 *      Author: Mati
 */

#include "biblioteca.h"

#include <stdio.h>

int ImprimirMenu(float x, float y) {

	int opcion;

	printf("\n**************************************************\n");
	printf("**************************************************\n\n");

	printf("1) Ingresar 1er Operando: (A = %.2f)\n", x);
	printf("2) Ingresar 2do operando: (B = %.2f)\n", y);
	printf("3) Calcular todas las operaciones.\n");
	printf("  a_ Calcular la suma (A+B)\n");
	printf("  b_ Calcular la resta (A-B)\n");
	printf("  c_ Calcular la division (A/B)\n");
	printf("  d_ Calcular la multiplicacion (A*B)\n");
	printf("  e_ Calcular el factorial (A!)\n");
	printf("4) Informar resultados.\n");
	printf("5) Salir\n\n");

	printf("**************************************************\n");
	printf("**************************************************\n\n");
	opcion = IngresarFlotante("Elegir una opcion: ");

	while(opcion>5){
		opcion = IngresarFlotante("Error, ingresar una opcion del 1 al 5: ");
	}

	return opcion;
}

float IngresarFlotante(char mensaje[]) {
	float unFlotante;
	printf("%s", mensaje);
	scanf("%f", &unFlotante);
	return unFlotante;
}

float CalcularSuma(float x, float y) {
	float resultadoSuma;
	resultadoSuma = x + y;
	return resultadoSuma;
}

float CalcularResta(float x, float y) {
	float resultadoResta;
	resultadoResta = x - y;
	return resultadoResta;
}

float CalcularDivision(float x, float y) {

	float resultadoDivision;
	resultadoDivision = x / y;
	return resultadoDivision;
}

float CalcularMultiplicacion(float x, float y) {
	float resultadoMultiplicacion;
	resultadoMultiplicacion = x * y;
	return resultadoMultiplicacion;
}

int ValidarEnteroODecimal(float numerito) {
	int entero;
	entero = numerito;
	int retorno = 1;
	if (numerito - entero) {
		return 0;
	}
	return retorno;
}

int CalcularFactorial(float numerito) {
	int factorial = 1;
	for (int i = 1; i <= numerito; i++) {
		factorial = factorial * i;
	}
	return factorial;
}
