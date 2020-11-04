#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "constants.h"
#include "validations.h"
#include "parser.h"
#include "controller.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		int len;
		int id;
		FILE* pFile = NULL;
		Employee* lectura = NULL;
		lectura = (Employee*)malloc(sizeof(Employee));

		pFile = fopen(path,"r");
		if(!parser_EmployeeFromText(pFile, pArrayListEmployee))
			ret = 0;
		fclose(pFile);


		if(ret == 0 && (len = ll_len(pArrayListEmployee)) > 0 && (lectura = ll_get(pArrayListEmployee, --len)) && !(employee_getId(lectura, &id)))
		{
			if(controller_saveLastId(PATH_ID, id))
			{
				ret = -1;
			}
		}
		else
		{
			ret = -1;
		}
	}
    return ret;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		int len;
		int id;
		FILE* pFile = NULL;
		Employee* lectura = NULL;
		lectura = (Employee*)malloc(sizeof(Employee));

		pFile = fopen(path,"rb");
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
			ret = 0;
		fclose(pFile);

		if(ret == 0 && (len = ll_len(pArrayListEmployee)) > 0 && (lectura = ll_get(pArrayListEmployee, --len)) && !(employee_getId(lectura, &id)))
		{
			if(controller_saveLastId(PATH_ID, id))
			{
				ret = -1;
			}
		}
		else
		{
			ret = -1;
		}
	}
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		FILE* pFile = NULL;

		pFile = fopen(path,"w");
		if(!parser_TextFromEmployee(pFile, pArrayListEmployee))
			ret = 0;
		fclose(pFile);
	}
	return ret;;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret = -1;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		FILE* pFile = NULL;

		pFile = fopen(path,"wb");
		if(!parser_BinaryFromEmployee(pFile, pArrayListEmployee))
			ret = 0;
		fclose(pFile);
	}
	return ret;
}



/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;

	if(pArrayListEmployee != NULL)
	{
		int id = 0;
		Employee* lectura = NULL;
		lectura = (Employee*)malloc(sizeof(Employee));

		controller_loadLastId(PATH_ID, &id);

		if((lectura = employee_new()) != NULL && !employee_setId(lectura, ++id))
		{
			if(!ll_add(pArrayListEmployee, lectura) && !controller_saveLastId(PATH_ID, id))
				ret = 0;
		}

	}
    return ret;
}

int controller_loadLastId(char* path, int* id)
{
	int ret = -1;

	if(path != NULL && id != NULL)
	{
		char idStr[50];

		FILE* pFile;

		pFile = fopen(path,"r");
		fscanf(pFile, "%[^\n]", idStr);
		fclose(pFile);

		if(isNumber(idStr))
		{
			*id = atoi(idStr);
			ret = 0;
		}
	}
	return ret;
}

int controller_saveLastId(char* path, int id)
{
	int ret = -1;

	if(path != NULL && id > 0)
	{
		FILE* pFile;

		pFile = fopen(path,"w");
		fprintf(pFile, "%d\n", id);
		fclose(pFile);
		ret = 0;
	}
	return ret;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;

	if(pArrayListEmployee != NULL)
	{
		int id;
		int maxId;
		int index;

		Employee* lectura = NULL;
		lectura = (Employee*)malloc(sizeof(Employee));

		if(controller_loadLastId(PATH_ID, &maxId))
			maxId = 100000;

		if(!inputInt(&id, MSG_INGRESE_ID, MSG_ERROR_ID, 1, maxId, RETRIES) && !employee_indexFromId(pArrayListEmployee, id, &index))
		{
			lectura = (Employee*) ll_get(pArrayListEmployee, index);
			if(!employee_set(lectura))
			{
				if(!ll_set(pArrayListEmployee, index, lectura))
					ret = 0;
			}
		}
	}
    return ret;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int ret = 0;

	if(pArrayListEmployee != NULL)
	{
		int  id;
		int  maxId;
		char opcionChar;
		int  index;

		if(controller_loadLastId(PATH_ID, &maxId))
			maxId = 100000;

		if(!inputInt(&id, MSG_INGRESE_ID, MSG_ERROR_ID, 1, maxId, RETRIES))
		{
			list_anEmployee(pArrayListEmployee, id);
			printf("\n Sera eliminado, desea continuar? ('Y' para confirmar)");

			if(!inputCharOpcion(&opcionChar, MSG_INGRESE_OPC, MSG_ERROR_OPC, RETRIES) &&
				(opcionChar == 'y' || opcionChar == 'Y') &&
				!employee_indexFromId(pArrayListEmployee, id, &index))
			{
				if(!ll_remove(pArrayListEmployee, index))
					ret = 0;
			}
		}
	}
    return ret;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;

	if(pArrayListEmployee != NULL)
	{
		int len;
		int i;

		int id = 0;
		int horas;
		int sueldo;

		char nombre[LENNOMBRE];

		Employee* lectura = NULL;

		printf("---------------Lista de empleados---------------\n");
		printf("------------------------------------------------");
		printf("\n%8s %23s %6s %8s\n", "ID", "Nombre", "Horas", "Sueldo");
		printf("------------------------------------------------\n");

		len = ll_len(pArrayListEmployee);
		for(i=0; i<len; i++)
		{
			lectura = (Employee*)malloc(sizeof(Employee));

			if((lectura = (Employee*) ll_get(pArrayListEmployee,i)) &&
			   !employee_getId(lectura, &id) &&
			   !employee_getNombre(lectura, nombre) &&
			   !employee_getHorasTrabajadas(lectura, &horas) &&
			   !employee_getSueldo(lectura, &sueldo))
			{
				printf("%8d %23s %6d %8d\n", id, nombre, horas, sueldo);
			}
			else
			{
				printf("-----Error al leer los datos-----");
			}

		}
		printf("------------------------------------------------");
		printf("\n%8s %23s %6s %8s\n", "ID", "Nombre", "Horas", "Sueldo");
		printf("------------------------------------------------\n");
		printf("---------------Lista de empleados---------------\n");
		ret = 0;
	}
    return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret = -1;

	if(pArrayListEmployee != NULL)
	{
		int  opcion;
		char opcionChar;
		int  exit = 1;
		int  order = 1;

		do
		{
			menuOrdenar();
			opcion = -1;
			if(inputInt(&opcion, MSG_INGRESE_OPC, MSG_ERROR_OPC, OPCMIN, OPCMAX, RETRIES))
				break;

			switch(opcion)
			{
			case 1:
				printf("\n La lista se ordenara por defecto de forma ascendente. Desea orderar de manera descendente? ('Y/n')");

				if(inputCharOpcion(&opcionChar, MSG_INGRESE_OPC, MSG_ERROR_OPC, RETRIES))
					break;

				if(opcionChar == 'y' || opcionChar == 'Y')
				{
					order = 0;
				}
				printf("Loading...");
				if(!ll_sort(pArrayListEmployee, employee_compareById, order))
					ret = 0;
				exit = 0;
	        	system("cls");
				break;

			case 2:
				printf("\n La lista se ordenara por defecto de forma ascendente. Desea orderar de manera descendente? ('Y/n')");

				if(inputCharOpcion(&opcionChar, MSG_INGRESE_OPC, MSG_ERROR_OPC, RETRIES))
					break;

				if(opcionChar == 'y' || opcionChar == 'Y')
				{
					order = 0;
				}
				printf("Loading...");
				if(!ll_sort(pArrayListEmployee, employee_compareByName, order))
					ret = 0;
				exit = 0;
	        	system("cls");
				break;
			case 3:
				printf("\n La lista se ordenara por defecto de forma ascendente. Desea orderar de manera descendente? ('Y/n')");

				if(inputCharOpcion(&opcionChar, MSG_INGRESE_OPC, MSG_ERROR_OPC, RETRIES))
					break;

				if(opcionChar == 'y' || opcionChar == 'Y')
				{
					order = 0;
				}
				printf("Loading...");
				if(!ll_sort(pArrayListEmployee, employee_compareByHour, order))
					ret = 0;
				exit = 0;
	        	system("cls");
				break;
			case 4:
				printf("\n La lista se ordenara por defecto de forma ascendente. Desea orderar de manera descendente? ('Y/n')");

				if(inputCharOpcion(&opcionChar, MSG_INGRESE_OPC, MSG_ERROR_OPC, RETRIES))
					break;

				if(opcionChar == 'y' || opcionChar == 'Y')
				{
					order = 0;
				}
				printf("Loading...");
				if(!ll_sort(pArrayListEmployee, employee_compareBySalary, order))
					ret = 0;
				exit = 0;
	        	system("cls");
				break;

			case 5:
				ret = 0;
				exit = 0;
				system("cls");
				break;

			default:
				break;
			}
		}while(exit);
	}
    return ret;
}



