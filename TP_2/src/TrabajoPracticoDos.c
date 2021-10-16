/*
 ============================================================================
 Name        : TrabajoPracticoDos.c
 Author      : Matias
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "utn2.h"
#include "ArrayEmployees.h"


#define TAM 1000

int main(void) {
	setbuf(stdout, NULL);

	int opcion;
	char auxName[51];
	char auxLastName[51];
	float auxSalary;
	int auxSector;
	int contadorId = 0;
	int idBuscado;
	int order;
	int opcionCaseFour;
	float sumaSalarios;
	float promedio;
	int contadorEmployerMayorAlPromedio;

	eEmployee listaEmployees[TAM];

	initEmployees(listaEmployees, TAM);

	do {
		printf("\n1) ALTA: \n");
		printf("2) MODIFICIAR: \n");
		printf("3) BAJA: \n");
		printf("4) INFORMAR: \n");
		utn_getNumero(&opcion, "Ingresar una opcion: ", "Opcion incorrecta", 1, 4, 99);

		switch (opcion) {
		case 1:
			PedirUnEmpleado(&contadorId, auxName, auxLastName, &auxSalary,
					&auxSector);
			AddEmployees(listaEmployees, TAM, contadorId, auxName, auxLastName,
					auxSalary, auxSector);
			break;

		case 2:
			if (VerificarEmployeeCargado(listaEmployees, TAM) == 1) {
				utn_getNumero(&idBuscado, "Ingresar un ID: ", "ID incorrecto\n", 1, 1000, 99);
				ModificarEmployee(listaEmployees, TAM, idBuscado);

			} else {
				printf("\nNo hay empleados cargados.\n");
			}

			break;

		case 3:
			if (VerificarEmployeeCargado(listaEmployees, TAM) == 1) {
				utn_getNumero(&idBuscado, "Ingresar ID a buscar: ", "ID incorrecto.\n", 1, 1000, 99);
				RemoveEmployee(listaEmployees, TAM, idBuscado);
			} else {
				printf("\nNo hay empleados cargados.\n");
			}
			break;

		case 4:
			if (VerificarEmployeeCargado(listaEmployees, TAM) == 1) {
				printf(
						"1. Listado de los empleados ordenados alfabéticamente por apellido y sector.\n");
				printf(
						"2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n");
				utn_getNumero(&opcionCaseFour, "Ingresar una opcion: ", "Opcion incorrecta.\n", 1, 2, 99);
				switch (opcionCaseFour) {
				case 1:
					utn_getNumero(&order, "Seleccionar 1 para orden ascendente o 0 para orden descendente: ", "Opcion incorrecta.\n", 0, 1, 99);
					SortEmployees(listaEmployees, TAM, order);
					break;
				case 2:
					sumaSalarios = SumarSalarios(listaEmployees, TAM);
					promedio = ObtenerPromedioSalarios(listaEmployees, TAM);
					contadorEmployerMayorAlPromedio =
							ObtenerCantidadEmployerMayorPromedio(listaEmployees,
							TAM);
					printf("\nLa suma de los salarios es: %.2f \n",
							sumaSalarios);
					printf("El promedio es: %.2f \n", promedio);
					printf(
							"La cantidad de empleados que superan el promedio es: %d \n \n",
							contadorEmployerMayorAlPromedio);
				}
			} else {
				printf("\nNo hay empleados cargados.\n");
			}
			break;
		}

	} while (opcion != 5);

	return EXIT_SUCCESS;
}

