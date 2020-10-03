/*
 ============================================================================
 Name        : TP2.c
 Author      : Juan Dietz
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

#include "arrayemployees.h"
#include "printstring.h"

#define SIZE 1000


int main()
{
    char option;
    int  salir=0;
    int  stAdd;
    int  stSort;
    int  stUpdate;
    int  stRemove;
    int  stInit=1;

    sEmployee employeeList[SIZE]; //vector donde se cargarán datos de empleados

    stInit=initList(employeeList, SIZE); //se inicializa la lista con valores por defecto como por ejemplo que todos los campos comienzan estando vacios

    if(stInit==1)
    {
        pErrorInit();
    }

    pLine();
    pWelcome();
    pLine();
    pAnyKey();

    option=getche();

    system("cls");

    while(salir==0)
    {
        stAdd=1;
        stSort=1;
        stUpdate=1;
        stRemove=1;

        pMenuOptions();

        fflush(stdin);
        option=getch();

        system("cls");

        switch (option)
        {
        case '1':
            stAdd=addEmployee(employeeList, SIZE); //Dar de alta a un empleado
            stSort=sortEmployee(employeeList, SIZE); //Ordenarlos por apellido
            if(stAdd==1)
            {
                pErrorAdd();
            }
            if(stSort==1)
            {
                pErrorSort();
            }
            break;

        case '4':
            listEmployee(employeeList, SIZE); //Listar todos los empleados
            break;

        case '2':
            stUpdate=updateEmployee(employeeList, SIZE); //Modifica un empleado
            stSort=sortEmployee(employeeList, SIZE); //Los ordena por apellido
            if(stUpdate==1)
            {
                pErrorUpdate();
            }
            if(stSort==1)
            {
                pErrorSort();
            }
            break;

        case '3':
            stRemove=removeEmployee(employeeList, SIZE); //Dar de baja a un empleado, este continua estando en la base de datos pero luego no se lista con los demás
            if(stRemove==1)
            {
                pErrorRemove();
            }
            break;

        case '5':
            pConfirmExit();
            fflush(stdin);
            option=getch();
            if(option=='Y')
            {
                salir=1;
            }else if(option=='n')
            {
                system("cls");
            }else
            {
                pInvalidOption();
                system("pause");
            }
            break;

        default:
            pInvalidOption();
            break;
        }
    }

    return 0;
}
