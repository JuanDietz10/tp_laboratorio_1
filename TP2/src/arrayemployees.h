/*
 * arrayemployees.h
 *
 *  Created on: 27 sep. 2020
 *      Author: John
 */

#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int   id;
    char  name[51];
    char  lastName[51];
    float salary;
    int   sector;
    int   isEmpty;
}sEmployee;

int initList(sEmployee* list, int len);
int addEmployee(sEmployee* list, int len);
int findSpace(sEmployee list[], int len);
int listEmployee(sEmployee* list, int len);
int printList(sEmployee list);
int findEmployee(int id, sEmployee list[], int len);
int removeEmployee(sEmployee* list, int len);
int showEmployee(int id, sEmployee list[], int len);
int genID(sEmployee list[], int len);
int getMax(int value, int max);
int sortEmployee(sEmployee* list, int len);
int updateEmployee(sEmployee* list, int len);


#endif /* ARRAYEMPLOYEES_H_ */
