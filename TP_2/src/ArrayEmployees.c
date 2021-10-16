
#include "utn2.h"
#include "ArrayEmployees.h"

#include <stdio.h>
#include <string.h>



int initEmployees(eEmployee listaEmployee[], int tam) {
	int retorno=0;
	for (int i = 0; i < tam; i++) {
		listaEmployee[i].isEmpty = VACIO;
		retorno=1;
	}
	return retorno;
}

int AddEmployees(eEmployee listaEmployee[], int tam, int id, char name[], char lastName[], float salary, int sector) {
	int i;
	int retorno=0;
	for (i = 0; i < tam; i++) {
		if (listaEmployee[i].isEmpty == VACIO) {
			listaEmployee[i].id = id;
			strcpy(listaEmployee[i].name, name);
			strcpy(listaEmployee[i].lastName, lastName);
			listaEmployee[i].salary = salary;
			listaEmployee[i].sector = sector;
			listaEmployee[i].isEmpty = CARGADO;
			retorno=1;
			break;
		}
	}
	return retorno;
}

void MostrarEmployee(eEmployee employee) {
	printf("%-3d %-10s %-11s %-12.2f %-10i \n", employee.id, employee.name,
			employee.lastName, employee.salary, employee.sector);
}

int PrintEmployees(eEmployee listaEmployee[], int tam) {
	int retorno=0;
	char id[15] = "ID";
	char nombre[15] = "Name";
	char lastName[15] = "LastName";
	char salario[15] = "Salary";
	char sector[15] = "Sector";
	printf("\n%-3s %-10s %-11s %-12s %-10s \n \n", id, nombre, lastName,
			salario, sector);
	for (int i = 0; i < tam; i++) {
		if (listaEmployee[i].isEmpty == CARGADO) {
			MostrarEmployee(listaEmployee[i]);
			retorno=1;
		}
	}
	return retorno;
}

void PedirUnEmpleado(int *contadorId, char auxName[], char auxLastName[],float* auxSalary, int *auxSector) {
	*contadorId = *contadorId + 1;
	utn_getNombre(auxName, 50, "Ingresar nombre: ", "Nombre incorrecto.\n", 99);
	utn_getNombre(auxLastName, 50, "Ingresar apellido: ", "Apellido incorrecto.\n", 99);
	utn_getNumeroFlotante(auxSalary, "Ingresar salario: ", "Salario invalido.\n", 0, 999999, 99);
	utn_getNumero(auxSector, "Ingresar sector: ", "Sector incorrecto.\n", 0, 99999, 99);
}

int FindEmployeedById(eEmployee listaEmployee[], int tam, int id) {
	int retorno = 0;
	for (int i = 0; i < tam; i++) {
		if (id == listaEmployee[i].id && listaEmployee[i].isEmpty == CARGADO) {
			retorno = listaEmployee[i].id;
		}
	}
	return retorno;
}

int RemoveEmployee(eEmployee listaEmployee[], int tam, int id) {
	int retorno=0;
	int aux;
	aux = FindEmployeedById(listaEmployee, tam, id);
	if (aux == 0) {
		printf("\nEl ID no existe.\n\n");
	} else {
		for (int i = 0; i < tam; i++) {
			if (listaEmployee[i].isEmpty == CARGADO
					&& listaEmployee[i].id == id) {
				listaEmployee[i].isEmpty = VACIO;
				printf("\nEmpleado %d removido con exito\n", id);
				break;
			}
		}
		retorno =1;
	}
	return retorno;
}

int SortEmployees(eEmployee ListaEmployee[], int tam, int order) {
	eEmployee auxEmployee;
	int retorno=0;
	for (int i = 0; i < tam - 1; i++) {
		for (int j = i + 1; j < tam; j++) {
			switch (order) {
			case 0:
				if (strcmp(ListaEmployee[i].lastName, ListaEmployee[j].lastName)
						< 0) {
					auxEmployee = ListaEmployee[i];
					ListaEmployee[i] = ListaEmployee[j];
					ListaEmployee[j] = auxEmployee;
				}
				if (strcmp(ListaEmployee[i].lastName, ListaEmployee[j].lastName)
						== 0
						&& ListaEmployee[i].sector < ListaEmployee[j].sector) {
					auxEmployee = ListaEmployee[i];
					ListaEmployee[i] = ListaEmployee[j];
					ListaEmployee[j] = auxEmployee;
				}
				break;
			case 1:
				if (strcmp(ListaEmployee[i].lastName, ListaEmployee[j].lastName)
						> 0) {
					auxEmployee = ListaEmployee[i];
					ListaEmployee[i] = ListaEmployee[j];
					ListaEmployee[j] = auxEmployee;
				}
				if (strcmp(ListaEmployee[i].lastName, ListaEmployee[j].lastName)
						== 0
						&& ListaEmployee[i].sector > ListaEmployee[j].sector) {
					auxEmployee = ListaEmployee[i];
					ListaEmployee[i] = ListaEmployee[j];
					ListaEmployee[j] = auxEmployee;
				}
			}
			retorno = 1;
		}
	}
	PrintEmployees(ListaEmployee, tam);
	return retorno;
}

float SumarSalarios(eEmployee listaEmployee[], int tam) {
	float auxEmployerSuma = 0;
	for (int i = 0; i < tam; i++) {
		if (listaEmployee[i].isEmpty == CARGADO) {
			auxEmployerSuma = auxEmployerSuma + listaEmployee[i].salary;
		}
	}
	return auxEmployerSuma;
}

float ObtenerPromedioSalarios(eEmployee listaEmplyee[], int tam) {
	float contadorIdCargados = 0;
	float resultadoSuma;
	float promedio;
	for (int i = 0; i < tam; i++) {
		if (listaEmplyee[i].isEmpty == CARGADO) {
			contadorIdCargados = contadorIdCargados + 1;
		}
	}
	resultadoSuma = SumarSalarios(listaEmplyee, tam);
	promedio = resultadoSuma / contadorIdCargados;
	return promedio;
}

int ObtenerCantidadEmployerMayorPromedio(eEmployee listaEmployee[], int tam) {
	int promedio;
	int contador = 0;
	promedio = ObtenerPromedioSalarios(listaEmployee, tam);
	for (int i = 0; i < tam; i++) {
		if (listaEmployee[i].isEmpty == CARGADO
				&& listaEmployee[i].salary > promedio) {
			contador = contador + 1;
		}
	}
	return contador;
}

void ModificarEmployee(eEmployee listaEmployee[], int tam, int id) {
	int opcion;
	id = FindEmployeedById(listaEmployee, tam, id);
	for (int i = 0; i < tam; i++) {
		if (id == listaEmployee[i].id) {
			utn_getNumero(&opcion, "Elegir: \n"
					"1 para modificar el nombre: \n"
					"2 para modificar el apellido: \n"
					"3 para modificar el salario: \n"
					"4 para modificar el sector: ", "Opcion incorrecta.\n", 1, 4, 99);

			switch (opcion) {
			case 1:
				utn_getNombre(listaEmployee[i].name, 50, "Ingresar nombre: ", "Nombre incorrecto.\n", 99);
				break;
			case 2:
				utn_getNombre(listaEmployee[i].lastName, 50, "Ingresar apellido: ", "apellido incorrecto.\n", 99);
				break;
			case 3:
				utn_getNumeroFlotante(&listaEmployee[i].salary, "Ingresar salario: ", "Salario incorrecto.\n", 0, 999999, 99);
				break;
			case 4:
				utn_getNumero(&listaEmployee[i].sector, "Ingresar sector: ", "Sector incorrecto.\n", 0, 99999, 99);
				break;
			}
		}
	}
	if (id == 0) {
		printf("El ID no existe.\n");
	}
}

int VerificarEmployeeCargado(eEmployee listaEmployee[], int tam) {
	int retorno = 0;
	for (int i = 0; i < tam; i++) {
		if (listaEmployee[i].isEmpty == CARGADO) {
			retorno = 1;
		}

	}
	return retorno;
}

