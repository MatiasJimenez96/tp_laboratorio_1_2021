

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#define CARGADO 1
#define VACIO 0
typedef struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;

} eEmployee;
/// @fn int initEmployees(eEmployee[], int)
/// @brief Inicializa la lista de employee en vacio.
///
/// @param listaEmployees Lista de los empleados.
/// @param tam Tamaño de la lista.
/// @return Retorna 0 si no se inicializo o 1 si se pudo.
int initEmployees(eEmployee listaEmployees[], int tam);

/// @fn int AddEmployees(eEmployee[], int, int, char[], char[], float, int)
/// @brief Agrega en una lista existente de empleados los valores recibidos como parámetros* en la primera posición vacía.
///
/// @param listaEmployee Lista de empleados.
/// @param tam Tamaño de la lista.
/// @param id ID del empleado.
/// @param name Nombre del empleado.
/// @param lastName Apellido del empleado.
/// @param salary Salario del empleado.
/// @param sector Sector del empleado
/// @return Retorna 0 si no se pudo cargar o 1 si se cargo correctamente.
int AddEmployees(eEmployee listaEmployee[], int tam, int id, char name[], char lastName[], float salary, int sector);

/// @fn void MostrarEmployee(eEmployee)
/// @brief Muestra un empleado.
///
/// @param employee Empleado
void MostrarEmployee(eEmployee employee);

/// @fn int PrintEmployees(eEmployee[], int)
/// @brief Imprime la lista de empleado.
///
/// @param listaEmployee Lista de empleados.
/// @param tam Tamaño de la lista
/// @return Retorna 1 si se imprime correctamente o 0 en caso negativo.
int PrintEmployees(eEmployee listaEmployee[], int tam);

/// @fn void PedirUnEmpleado(int*, char[], char[], float*, int*)
/// @brief Pide un empleado.
///
/// @param contadorId Genera automaticamen un id de forma ascendente y lo devuelve por puntero.
/// @param auxName	Nombre del empleado.
/// @param auxLastName Apellido del empleado.
/// @param auxSalary Salario del empleado y lo devuelve por puntero.
/// @param auxSector Sector del empleado y lo devuelve por puntero.
void PedirUnEmpleado(int* contadorId, char auxName[], char auxLastName[], float* auxSalary, int* auxSector);

/// @fn int FindEmployeedById(eEmployee[], int, int)
/// @brief Busca un empleado por id en la lista.
///
/// @param listaEmployee Lista de empleados.
/// @param tam Tamaño de la lista.
/// @param id ID a buscar.
/// @return Retorna 0 Si el empleado  no exite o un numero > 0 Si el empleado EXISTE siendo este el ID del mismo.
int FindEmployeedById(eEmployee listaEmployee[], int tam, int id);

/// @fn int RemoveEmployee(eEmployee[], int, int)
/// @brief Elimina un empleado de la lista por medio de su id.
///
/// @param listaEmployee Lista de empleados.
/// @param tam Tamaño de la lista.
/// @param id ID a eliminar
/// @return Retorna 0 Si no se pudo eliminar empleado o 1 si se elimino correctamente
int RemoveEmployee(eEmployee listaEmployee[], int tam, int id);

/// @fn int SortEmployees(eEmployee[], int, int)
/// @brief Ordena la lista de empleados por apellido y sector de forma ascendente o descendente segun elija el usuario.
///
/// @param ListaEmployee Lista de empleados.
/// @param tam Tamaño de la lista.
/// @param order 1 para orden ascendente o 0 para descendente
/// @return Retorna 0 si no se pudo ordenar o 1 si se ordeno correctamente.
int SortEmployees(eEmployee ListaEmployee[], int tam, int order);

/// @fn float SumarSalarios(eEmployee[], int)
/// @brief Suma los salarios de la lista de los empleados.
///
/// @param listaEmployee Lista de empleados.
/// @param tam Tamaño de la lista.
/// @return Retorna la suma de todos los salarios.
float SumarSalarios(eEmployee listaEmployee[], int tam);

/// @fn float ObtenerPromedioSalarios(eEmployee[], int)
/// @brief Calcula el promedio de salarios de la lista.
///
/// @param listaEmplyoee Lista de empleados.
/// @param tam Tamaño de la lista
/// @return Retorna el promedio.
float ObtenerPromedioSalarios(eEmployee listaEmplyoee[], int tam);

/// @fn int ObtenerCantidadEmployerMayorPromedio(eEmployee[], int)
/// @brief Calcula la cantidad de empleados que superan el promedio de salarios.
///
/// @param listaEmployee Lista de empleados.
/// @param tam Tamaño de la lista.
/// @return  Retorna el resultado
int ObtenerCantidadEmployerMayorPromedio(eEmployee listaEmployee[], int tam);

/// @fn void ModificarEmployee(eEmployee[], int, int)
/// @brief Modifica empleados por ID.
///
/// @param listaEmployee Lista de empleados.
/// @param tam Tamaño de la lista.
/// @param id ID del empleado a modificar.
void ModificarEmployee(eEmployee listaEmployee[], int tam, int id);

/// @fn int VerificarEmployeeCargado(eEmployee[], int)
/// @brief Verifica si hay empleados cargados en la lista.
///
/// @param listaEmployee Lista de empleados
/// @param tam Tamaño de la lista.
/// @return Retorna 1 si hay al menos un empleado cargado o 0 si no hay.
int VerificarEmployeeCargado(eEmployee listaEmployee[], int tam);
#endif /* ARRAYEMPLOYEES_H_ */
