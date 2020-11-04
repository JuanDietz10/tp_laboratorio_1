#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "validations.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret = -1;

	if(pArrayListEmployee != NULL && pFile != NULL)
	{
		char idStr[50];
		char nombre[51];
		char horasStr[40];
		char sueldoStr[70];

		Employee* lectura = NULL;
		lectura = (Employee*) malloc(sizeof(Employee));

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, horasStr, sueldoStr);

		if(isNumber(idStr) && (lectura = employee_newParametros(idStr, nombre, horasStr, sueldoStr)) != NULL)
		{
			ll_add(pArrayListEmployee, lectura);
		}

		while(!feof(pFile))
		{
			fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", idStr, nombre, horasStr, sueldoStr);
			if((lectura = employee_newParametros(idStr, nombre, horasStr, sueldoStr)) != NULL)
			{
				if(!ll_add(pArrayListEmployee, lectura))
					ret = 0;
			}
		}
	}
    return ret;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret = -1;

    Employee* lectura = NULL;

	while(!feof(pFile))
	{
	    lectura = (Employee*) malloc(sizeof(Employee));
		if(fread(lectura, sizeof(Employee),1,pFile))
		{
			if(!ll_add(pArrayListEmployee, lectura))
				ret = 0;
		}
	}
	ret = 0;
    return ret;
}

int parser_BinaryFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int len;
	int i;

	Employee* lectura = NULL;

	len = ll_len(pArrayListEmployee);

	for(i=0;i<len;i++)
	{
		lectura = ll_get(pArrayListEmployee, i);
		fwrite(lectura, sizeof(Employee),1,pFile);
	}
	ret = 0;
    return ret;
}

int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int ret = -1;
	int len;
	int i;

	int  id;
	char nombre[51];
	int  horas;
	int  sueldo;

	Employee* lectura = NULL;
	lectura = (Employee*) malloc(sizeof(Employee));

	len = ll_len(pArrayListEmployee);

	for(i=0;i<len;i++)
	{
		lectura = ll_get(pArrayListEmployee, i);

		if(!employee_getId(lectura, &id) &&
		   !employee_getNombre(lectura, nombre) &&
		   !employee_getHorasTrabajadas(lectura, &horas) &&
		   !employee_getSueldo(lectura, &sueldo))
		{
			fprintf(pFile, "%d,%s,%d,%d\n", id, nombre, horas, sueldo);
			ret = 0;
		}
	}
	return ret;
}
