/*
 * arrayemployees.c
 *
 *  Created on: 27 sep. 2020
 *      Author: John
 */



#include "ArrayEmployees.h"
#include "printstring.h"
#include "conststring.h"
#include "constants.h"
#include "validations.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <math.h>

#define DIGITS 4

int initList(sEmployee* list, int len)
{
    for(int i=0; i<len; i++)
    {
        list[i].isEmpty=1;
        list[i].id=0;
    }

    return 0;
}


int findEmployeeIndex(int id, sEmployee list[], int len)
{
    int index=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0 && list[i].id==id)
        {
            index=i;
            break;
        }
    }
    return index;
}



int findEmployeeId(int id, sEmployee list[], int len)
{
    int index=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0 && list[i].id==id)
        {
            index=list[i].id;
            break;
        }
    }
    return index;
}




int findSpace(sEmployee list[], int len)
{
    int index=-1;

    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==1)
        {
            index=i;
            break;
        }

    }
    return index;
}




int sortEmployee(sEmployee* list, int len)
{
    sEmployee employee;

    for(int i= 0; i < len-1 ; i++)
    {
        for(int j= i+1; j <len; j++)
        {
            if( list[i].isEmpty == 0 && list[j].isEmpty == 0 && strcmp(list[i].lastName, list[j].lastName)>0 )
            {
                employee = list[i];
                list[i] = list[j];
                list[j] = employee;
            }
        }
    }
    return 0;
}



int removeEmployee(sEmployee* list, int len)
{
    int id;
    int index=1;
    int salir=0;
    char answer;

    printf("\n\t%s\t", MSG_INPUT_ID);
    scanf("%d", &id);
    index=findEmployeeIndex(id, list, len);

    while(index==-1)
    {
        printf("\n%s", MSG_NO_MATCH_ID);

        printf("\n\t%s\t", MSG_INPUT_ID);
        scanf("%d", &id);

        index=findEmployeeIndex(id, list, len);
    }

    while(salir==0)
    {
        system("cls");

        showEmployee(id, list, len);

        printf("\n\n\t%s", MSG_CONFIRM_REMOVE);

        fflush(stdin);
        answer=getch();

        if(answer=='Y')
        {
            list[index].isEmpty=1;
            system("cls");
            printf("\n\t%s\n", MSG_DELETE_SUCCESSFUL);
            salir=1;
            system("pause");
            system("cls");
        }else if(answer=='n')
        {
            system("cls");
            printf("\n\t%s\n", MSG_OP_CANCELLED);
            salir=1;
            system("pause");
            system("cls");
        }else
        {
            system("cls");
            printf("\n\n\t%s", MSG_INVALID_OPTION);
        }
    }
    return 0;
}



sEmployee newEmployee(int id, char name[], char lastName[], float salary, int sector, int isEmpty)
{
    sEmployee employee;

    employee.id=id;
    strcpy(employee.name, name);
    strcpy(employee.lastName, lastName);
    employee.salary=salary;
    employee.sector=sector;
    employee.isEmpty=isEmpty;

    return employee;
}



int getMax(int value, int max)
{
    if(value>max)
    {
        max=value;
    }
    return max;
}



int genID(sEmployee list[], int len)
{
    int max=pow(10, DIGITS-1); //fuerzo a que el legajo tenga la cantidad de digitos mínima que yo desee

    for(int i=0; i<len; i++)
    {
        max=getMax(list[i].id, max);
    }
    return max+1;
}



int addEmployee(sEmployee* list, int len)
{
	int   leName = 51;
    char  name[leName];
    char  lastName[leName];
    float salary=0;
    int   sector=0;
    int   isEmpty;
    int   id;

    int index=-1;
    index=findSpace(list, len);

    id=genID(list, len);

    if(index!=-1)
    {
        inputName(name, leName, MSG_INPUT_NAME, MSG_ERROR_ADD, RETRIES);

        inputName(lastName, leName, MSG_INPUT_LASTNAME, MSG_ERROR_ADD, RETRIES);

        pInputSalary();
        scanf("%f", &salary);

        inputInt(&sector, MSG_INPUT_SECTOR, MSG_ERROR_ADD, 1, 99, RETRIES);

        isEmpty=0;

        list[index]= newEmployee(id, name, lastName, salary, sector, isEmpty);

        system("cls");

        pInputSuccessful();

        showEmployee(id, list, len);

        printf("\n\t\t\t%s\n", MSG_MENU_SHOW);

        system("pause");

        system("cls");

    }else
    {
        pNoSpace();
    }
    return 0;
}




int showEmployee(int id, sEmployee list[], int len)
{
    int index;
    int isE;

    index=findEmployeeIndex(id, list, len);
    isE=list[index].isEmpty;
    if(isE!=1)
    {
        pListEmployees();
        printList(list[index]);
    }

    return index;
}



int listEmployee(sEmployee* list, int len)
{
    printf("\t\t\t%s\n", MSG_MENU_SHOW);
    printf("\n\t\t\t\t%s\n", MSG_OUTPUT_MENU_TIT);
    pListEmployees();
    for(int i=0; i<len; i++)
    {
        if(list[i].isEmpty==0)
        {
            printList(list[i]);
        }
    }
    return 0;
}



int printList(sEmployee list)
{
    printf("\n %9d %20s %19s %18.2f %16d", list.id, list.name, list.lastName, list.salary, list.sector);
    printf("\n%s", LINE);

    return 0;
}




int updateEmployee(sEmployee* list, int len)
{
    int   index;
    int   id;
    int   option;
    int   sector;
    int   salir=0;
    char  name[51];
    char  lastName[51];
    float salary;

    system("cls");

    printf("\n\t%s\t", MSG_INPUT_ID);
    scanf("%d", &id);
    index=findEmployeeIndex(id, list, len);

    while(index==-1)
    {
        printf("\n%s", MSG_NO_MATCH_ID);

        printf("\n\t%s\t", MSG_INPUT_ID);
        scanf("%d", &id);

        index=findEmployeeIndex(id, list, len);
    }

    while(salir==0)
    {
        system("cls");
        showEmployee(id, list, len);

        pUpdateMenu();

        scanf("%d", &option);

        switch (option)
        {
        case 1:
            pInputName();
            fflush(stdin);
            gets(name);
            strcpy(list[index].name, name);
            pUpdateDone();
            break;

        case 2:
            pInputLastname();
            fflush(stdin);
            gets(lastName);
            strcpy(list[index].lastName, lastName);
            system("cls");
            showEmployee(id, list, len);
            pUpdateDone();
            break;

        case 3:
            pInputSalary();
            scanf("%f", &salary);
            list[index].salary = salary;
            system("cls");
            showEmployee(id, list, len);
            pUpdateDone();
            break;

        case 4:
            pInputSector();
            scanf("%d", &sector);
            list[index].sector = sector;
            system("cls");
            showEmployee(id, list, len);
            pUpdateDone();
            break;

        case 5:
            salir=1;
            system("cls");
            break;

        default:
            pInvalidOption();
            system("pause");
            break;
        }

    }
    return 0;
}
