
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
#include "inout.h"
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

    do
    {
        fflush(stdin); //Limpia el buffer. __fpurge(stdin); para Linux
        system("cls");

    }while( inputInt(&valueA, MSG_INPUT_VALUE_A, MSG_INVALID_CHAR_INPUT, -9999999, 9999999, 10) != 0); // state!=1 valida que se haya ingresado un numero correctamente

    do
        {
            fflush(stdin); //Limpia el buffer. __fpurge(stdin); para Linux
            system("cls");

    }while( inputInt(&valueB, MSG_INPUT_VALUE_B, MSG_INVALID_CHAR_INPUT, -9999999, 9999999, 10) != 0); // state!=1 valida que se haya ingresado un numero correctamente

    system("cls");


	printValues(valueA, valueB);

	do
	{
		printCalculate();
	}while(!scanf("%c", &confirm));

	system("cls");

	printValues(valueA, valueB);

	printLine();

	result=add(valueA, valueB);
	printSum(result);

	result=subtract(valueA, valueB);
	printSubtraction(result);

	result=multiply(valueA, valueB);
	printMultiplication(result);

	if( divide(valueA, valueB, &result) != 0)
	{
		printErrorDivByCero();
	}else
	{
		printDivision(result);
	}

	if(valueA<0)
	{
		printErrorFactNegative();
	}else
	{
		result=factorial(valueA);
		printFactorialA(result);
	}

	if(valueB<0)
	{
		printErrorFactNegative();
	}else
	{
		result=factorial(valueB);
		printFactorialB(result);
	}

    printLine();

    do
    	{
    		printExitConfirm();
    	}while(!scanf("%c", &confirm));

    system("cls");

    printGoodbye();

    return 0;
}
