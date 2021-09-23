/*
 ============================================================================
 Name        : TrabajoPracticoUno.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================

 Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
 1. Ingresar 1er operando (A=x)
 2. Ingresar 2do operando (B=y)
 3. Calcular todas las operaciones
 a) Calcular la suma (A+B)
 b) Calcular la resta (A-B)
 c) Calcular la division (A/B)
 d) Calcular la multiplicacion (A*B)
 e) Calcular el factorial (A!)
 4. Informar resultados
 a) “El resultado de A+B es: r”
 b) “El resultado de A-B es: r”
 c) “El resultado de A/B es: r” o “No es posible dividir por cero”
 d) “El resultado de A*B es: r”
 e) “El factorial de A es: r1 y El factorial de B es: r2”
 5. Salir
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteca.h"

int main(void) {
	setbuf(stdout, NULL);
	int continuar = 1;

	int menu;
	float x;
	float y;

	float suma;
	float resta;
	float division;
	char resultadoDivision[100];
	float multiplicacion;

	int factorialX;
	char strFactorialX[100];
	int factorialY;
	char strFactorialY[100];

	int banderaCaseUno = 0;
	int banderaCaseDos = 0;

	do {

		menu = ImprimirMenu(x, y); //Me devuelve una opcion del 1 al 5
		switch (menu) {
		case 1:
			x = IngresarFlotante("Ingresar el primer valor: ");
			banderaCaseUno = 1;
			break;

		case 2:
			y = IngresarFlotante("Ingresar el segundo valor: ");
			banderaCaseDos = 1;
			break;

		case 3:
			if (banderaCaseUno == 1 && banderaCaseDos == 1) {
				suma = CalcularSuma(x, y); //Suma.
				resta = CalcularResta(x, y); //Resta.
				if(y==0){ //division
					strcpy(resultadoDivision, "No se puede dividir por 0 (Cero).");
				}else{
					division = CalcularDivision(x, y);
					sprintf(resultadoDivision, "%.2f", division); // Lo mismo que itoa pero para float.
				}
				multiplicacion = CalcularMultiplicacion(x, y); //Multiplicacion.

				if (ValidarEnteroODecimal(x) && x < 11) {  //Factorial.
					factorialX = CalcularFactorial(x);
					itoa(factorialX, strFactorialX, 10); // convierte un valor numerico en una cadena de texto de base 10.
				} else {
					strcpy(strFactorialX,
							"No se pudo calcular el factorial A, el numero debe ser menor a 10 y sin decimales.");
				}

				if (ValidarEnteroODecimal(y) && y < 11) {
					factorialY = CalcularFactorial(y);
					itoa(factorialY, strFactorialY, 10); // convierte un valor numerico en una cadena de texto de base 10.

				} else {
					strcpy(strFactorialY,
							"No se pudo calcular el factorial B, el numero debe ser menor a 10 y sin decimales.");
				}
				printf("\n--------------------------------------------------\n"
						"-------Se calcularon todas las operaciones.-------\n"
						"--------------------------------------------------\n");
			} else {
				printf("\n--------------------------------------------------\n"
						"------- Falta ingresar un valor o varios. --------\n"
						"--------------------------------------------------\n");

			}
			break;

		case 4:
			if (banderaCaseUno == 1 && banderaCaseDos == 1) {
				printf("--------------------------------------------------\n"
						"--------------------RESULTADOS--------------------\n"
						"--------------------------------------------------\n"
						"El resultado de la suma es: %.2f\n"
						"El resultado de la resta es: %.2f\n"
						"El resultado de la division es: %s\n"
						"El resultado de la multiplicacion es: %.2f\n"
						"El factorial A es: %s\n"
						"El factorial B es: %s\n\n", suma, resta, resultadoDivision,
						multiplicacion, strFactorialX, strFactorialY);
				printf("Desea continuar?: "
						"Presionar 1 para continuar o 2 para salir. ");
				scanf("%d", &continuar);
				if(continuar == 2){
					printf("\nGracias por usar la calculadora del Cracken");
				}


			} else {
				printf("\n--------------------------------------------------\n"
						"------- Falta ingresar un valor o varios. --------\n"
						"--------------------------------------------------\n");
			}

			break;
		case 5:
			printf("Gracias por usar la calculadora del Cracken");
			break;
		}
	} while (menu < 5 && continuar == 1);

	return EXIT_SUCCESS;
}
/*
 * Atajos:
 * 			CTRL + MAY + O = Organizador de imports (añadiéndolos si faltan).
 * 			CTRL + D = Eliminar linea.
 * 			CROL + MAY + C = Comenta el texto seleccionado.
 * 			Alt + Flechita ↑↓ = intercambia la linea actual.
 */

