
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "constants.h"
#include "validations.h"

Employee* employee_new()
{
	Employee* lectura = NULL;

	lectura = (Employee*) malloc(sizeof(Employee));

	char nombre[LENNOMBRE];
	int  horas;
	int  sueldo;

	int  exit = 1;

	do
	{
		if(inputName(nombre,LENNOMBRE, MSG_INGRESE_NOMBRE, MSG_ERROR_NOMBRE, RETRIES))
			break;
		if(inputInt(&horas, MSG_INGRESE_HORAS, MSG_ERROR_HORAS, HORASMIN, HORASMAX, RETRIES))
			break;
		if(inputInt(&sueldo, MSG_INGRESE_SUELDO, MSG_ERROR_SUELDO, SUELDOMIN, SUELDOMAX, RETRIES))
			break;

		if(employee_setNombre(lectura, nombre) ||
		   employee_setHorasTrabajadas(lectura, horas) ||
		   employee_setSueldo(lectura, sueldo))
			lectura = NULL;

		exit = 0;

	}while(exit);

	return lectura;
}


Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* lectura = NULL;

	if(idStr != NULL && nombreStr != NULL && horasTrabajadasStr != NULL && sueldoStr != NULL)
	{
		lectura = (Employee*) malloc(sizeof(Employee));

		if(employee_setId(lectura, atoi(idStr)) ||
		   employee_setHorasTrabajadas(lectura, atoi(horasTrabajadasStr)) ||
		   employee_setSueldo(lectura, atoi(sueldoStr)) ||
		   employee_setNombre(lectura, nombreStr))
			lectura = NULL;
	}
	return lectura;
}

int employee_indexFromId(LinkedList* pArrayLinkedList, int id, int* index)
{
	int ret = -1;

	if(pArrayLinkedList != NULL && id > 0 && index != NULL)
	{
		int i;
		int len;
		int idLectura;
		Employee* lectura = NULL;

		len = ll_len(pArrayLinkedList);

		for(i=0;i<len;i++)
		{
			lectura = ll_get(pArrayLinkedList, i);

			if(!employee_getId(lectura, &idLectura) && id == idLectura)
			{
				if((*index = ll_indexOf(pArrayLinkedList, lectura)))
					ret = 0;
				break;
			}
		}
	}

	return ret;
}

int employee_set(Employee* this)
{
	int ret = -1;

	if(this != NULL)
	{
		int exit = 1;
		int id;
		int horas;
		int sueldo;
		int opcion;

		char nombre[LENNOMBRE];

		id = this->id;
		horas = this->horasTrabajadas;
		sueldo = this->sueldo;
		strcpy(nombre, this->nombre);

		do
		{
			printf("Editando: %4d %15s %8d %8d\n", id, nombre, horas, sueldo);
	    	menuModificar();
			opcion = -1;
			if(inputInt(&opcion, MSG_INGRESE_OPC, MSG_ERROR_OPC, OPCMIN, OPCMAX, RETRIES))
				ret = -1;

			switch(opcion)
			{
				case 1:
					inputName(nombre,LENNOMBRE, MSG_INGRESE_NOMBRE, MSG_ERROR_NOMBRE, RETRIES);
					break;
				case 2:
					inputInt(&horas, MSG_INGRESE_HORAS, MSG_ERROR_HORAS, HORASMIN, HORASMAX, RETRIES);
					break;
				case 3:
					inputInt(&sueldo, MSG_INGRESE_SUELDO, MSG_ERROR_SUELDO, SUELDOMIN, SUELDOMAX, RETRIES);
					break;
				case 4:
					if(!employee_setNombre(this, nombre) &&
					   !employee_setHorasTrabajadas(this, horas) &&
					   !employee_setSueldo(this, sueldo))
						ret = 0;
					exit = 0;
					break;
				case 5:
					exit = 0;
					ret = 0;
					break;
				default:
					exit = 0;
					break;
			}
		}while(exit);
	}
	return ret;
}


int list_anEmployee(LinkedList* miLista, int id)
{
	int ret = -1;

	if(miLista != NULL && id > 0)
	{
		int i = 0;
		int horas;
		int sueldo;
		int index;

		char nombre[LENNOMBRE];

		Employee* lectura = NULL;
		lectura = (Employee*)malloc(sizeof(Employee));

		if(!employee_indexFromId(miLista, id, &index))
			lectura = (Employee*) ll_get(miLista, index);

		if(!employee_getNombre(lectura, nombre) &&
		   !employee_getHorasTrabajadas(lectura, &horas) &&
		   !employee_getSueldo(lectura, &sueldo))
			printf("%d) %4d %15s %8d %8d\n", i+1, id, nombre, horas, sueldo);
	}
	return ret;
}

int employee_compareById(void* Emp1, void* Emp2)
{
	int ret = 0;

	Employee* E1 = NULL;
	Employee* E2 = NULL;

	E1 = (Employee*)Emp1;
	E2 = (Employee*)Emp2;

	if(E1->id > E2->id)
	{
		ret = 1;
	}
	else
	{
		if(E1->id < E2->id)
		{
			ret = -1;
		}
	}
	return ret;
}

int employee_compareByName(void* Emp1, void* Emp2)
{
	int ret = 0;

	Employee* E1 = NULL;
	Employee* E2 = NULL;

	E1 = (Employee*)Emp1;
	E2 = (Employee*)Emp2;

	if(strcmp(E1->nombre, E2->nombre) > 0)
	{
		ret = 1;
	}
	else
	{
		if(strcmp(E1->nombre, E2->nombre) < 0)
		{
			ret = -1;
		}
	}
	return ret;
}

int employee_compareByHour(void* Emp1, void* Emp2)
{
	int ret = 0;

	Employee* E1 = NULL;
	Employee* E2 = NULL;

	E1 = (Employee*)Emp1;
	E2 = (Employee*)Emp2;

	if(E1->horasTrabajadas > E2->horasTrabajadas)
	{
		ret = 1;
	}
	else
	{
		if(E1->horasTrabajadas < E2->horasTrabajadas)
		{
			ret = -1;
		}
	}
	return ret;
}

int employee_compareBySalary(void* Emp1, void* Emp2)
{
	int ret = 0;

	Employee* E1 = NULL;
	Employee* E2 = NULL;

	E1 = (Employee*)Emp1;
	E2 = (Employee*)Emp2;

	if(E1->sueldo > E2->sueldo)
	{
		ret = 1;
	}
	else
	{
		if(E1->sueldo < E2->sueldo)
		{
			ret = -1;
		}
	}
	return ret;
}


//void employee_delete();

int employee_setId(Employee* this,int id)
{
	int ret = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		ret = 0;
	}
	return ret;
}
int employee_getId(Employee* this,int* id)
{
	int ret = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		ret = 0;
	}
	return ret;
}

int employee_setNombre(Employee* this,char* nombre)
{
	int ret = -1;

	if(this != NULL && nombre > 0)
	{
		strcpy(this->nombre, nombre);
		ret = 0;
	}
	return ret;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int ret = -1;

	if(this != NULL && nombre != NULL)
	{
		strcpy(nombre, this->nombre);
		ret = 0;
	}
	return ret;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int ret = -1;

	if(this != NULL && horasTrabajadas > 0)
	{
		this->horasTrabajadas = horasTrabajadas;
		ret = 0;
	}
	return ret;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ret = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas = this->horasTrabajadas;
		ret = 0;
	}
	return ret;
}

int employee_setSueldo(Employee* this,int sueldo)
{
	int ret = -1;

	if(this != NULL && sueldo > 0)
	{
		this->sueldo = sueldo;
		ret = 0;
	}
	return ret;
}

int employee_getSueldo(Employee* this,int* sueldo)
{
	int ret = -1;

	if(this != NULL && sueldo != NULL)
	{
		*sueldo = this->sueldo;
		ret = 0;
	}
	return ret;
}




