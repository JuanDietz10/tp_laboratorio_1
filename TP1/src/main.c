
/*
En el archivo principal o main, se ubica la lógica del programa, sin incluir funciones o cadenas de caracteres,
los cuales deberían ir en un archivo aparte para luego llamar a dichas funciones cuando sea necesario utilizarlas.
*/

#include <stdio.h>
//#include <stdio ext.h>
#include <stdlib.h>
//#include <stdbool.h>
//#include <conio.h>
#include "operations.h"
#include "menu.h"
#include "validations.h"
#include "strings_eng.h"

int main()
{
	setbuf(stdout, NULL);

    int   valueA;
    int   valueB;

    float result;
    char  confirm;

    //IMPORTANTE: En Linux en lugar de fflush() se debe utilizar la funci�n __fpurge(), para lo cual es necesario incluir el archivo stdio_ext.h


    system("cls"); //Limpiar pantalla. system("clear"); para Linux


    welcome();
    while(!scanf("%c", &confirm));

    while( inputInt(&valueA, MSG_INPUT_VALUE_A, MSG_INVALID_CHAR_INPUT, -9999999, 9999999, 10) != 0); // state!=1 valida que se haya ingresado un numero correctamente

    while( inputInt(&valueB, MSG_INPUT_VALUE_B, MSG_INVALID_CHAR_INPUT, -9999999, 9999999, 10) != 0); // state!=1 valida que se haya ingresado un numero correctamente

    system("cls");


    printf("\n A=%d \t B=%d", valueA, valueB);


    printf("\n\n%s\n", MSG_CALCULATE);
	while(!scanf("%c", &confirm));

	system("cls");

	printf("\n A=%d \t B=%d", valueA, valueB);

	printf("\n----------------------------------------\n");

	result=add(valueA, valueB);
	printf("\n%s%.0f\n", MSG_PRINT_SUM, result);

	result=subtract(valueA, valueB);
	printf("\n%s%.0f\n", MSG_PRINT_SUBTRACTION, result);

	result=multiply(valueA, valueB);
	printf("\n%s%.0f\n", MSG_PRINT_MULTIPLICATION, result);

	if( divide(valueA, valueB, &result) != 0)
	{
		printf("\n%s\n", MSG_ERROR_DIVISION_ZERO);
	}else
	{
		printf("\n%s%.2f\n", MSG_PRINT_DIVISION, result);
	}

	if(valueA<0)
	{
		printf("\n%s\n", MSG_ERROR_FACT_NEGATIVE);
	}else
	{
		result=factorial(valueA);
		printf("\n%s%.0f\n", MSG_PRINT_FACTORIAL_A, result);
	}

	if(valueB<0)
	{
		printf("\n%s\n", MSG_ERROR_FACT_NEGATIVE);
	}else
	{
		result=factorial(valueB);
		printf("\n%s%.0f\n", MSG_PRINT_FACTORIAL_B, result);
	}

	printf("\n----------------------------------------\n");


	printf("\n%s\n\t", MSG_EXIT_CONFIRM);
    while(!scanf("%c", &confirm));

    system("cls");

    printf("%s\n", MSG_GOODBYE);

    return 0;
}
