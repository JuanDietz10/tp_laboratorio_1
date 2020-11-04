#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "constants.h"
#include "validations.h"
#include "parser.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.dat (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.dat (modo binario).
    10. Salir
*****************************************************/

int main()
{
    setbuf(stdout, NULL);

    LinkedList* miLista = NULL;

    int opcion;
    int exit = 1;

    miLista = ll_newLinkedList();

    do
    {
    	menuPrincipal();
    	opcion = -1;
    	inputInt(&opcion, MSG_INGRESE_OPC, MSG_ERROR_OPC, OPCPMIN, OPCPMAX, 0);
    	system("cls");

    	switch(opcion)
		{
    	case 1:
    		if(controller_loadFromText(PATH_CSV, miLista))
    		{
    			printf("\n%s\n", MSG_ERROR_LOAD);
    		}
    		else
    		{
    			printf("\n%s\n", MSG_LIST);
    		}
			break;

    	case 2:
    		if(controller_loadFromBinary(PATH_BIN, miLista))
			{
				printf("\n%s\n", MSG_ERROR_LOAD);
			}
			else
			{
				printf("\n%s\n", MSG_LIST);
			}
			break;

    	case 3:
    		if(controller_addEmployee(miLista))
			{
            	system("cls");
				printf("\n%s\n", MSG_ERROR_ADD);
			}
			else
			{
	        	system("cls");
				printf("\n%s\n", MSG_ADD);
			}
			break;

    	case 4:
    		if(controller_ListEmployee(miLista))
    		{
				printf("\n%s\n", MSG_ERROR_LIST);
			}

    		if(controller_editEmployee(miLista))
    		{
            	system("cls");
				printf("\n%s\n", MSG_ERROR_EDIT);
			}
			else
			{
	        	system("cls");
				printf("\n%s\n", MSG_EDIT);
			}
			break;

    	case 5:
        	if(controller_ListEmployee(miLista))
			{
				printf("\n%s\n", MSG_ERROR_LIST);
			}

    		if(controller_removeEmployee(miLista))
    		{
            	system("cls");
				printf("\n%s\n", MSG_ERROR_REM);
			}
			else
			{
	        	system("cls");
				printf("\n%s\n", MSG_REM);
			}
			break;

    	case 6:
        	if(controller_ListEmployee(miLista))
			{
				printf("\n%s\n", MSG_ERROR_LIST);
			}
			break;

    	case 7:
    		if(controller_sortEmployee(miLista))
    		{
				system("cls");
				printf("\n%s\n", MSG_ERROR_SORT);
			}
			else
			{
				system("cls");
				printf("\n%s\n", MSG_SORT);
			}
			break;

    	case 8:
    		if(controller_saveAsText(PATH_CSV, miLista))
    		{
				printf("\n%s\n", MSG_ERROR_SAVE);
			}
			else
			{
				printf("\n%s\n", MSG_SAVE);
			}
			break;

    	case 9:
    		if(controller_saveAsBinary(PATH_BIN, miLista))
			{
				printf("\n%s\n", MSG_ERROR_SAVE);
			}
			else
			{
				printf("\n%s\n", MSG_SAVE);
			}
			break;

    	case 0:
    		exit = 0;
    		break;

    	default:
    		break;
		}

    }while(exit);

    return 0;
}
