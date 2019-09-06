
/*
En el archivo principal o main, se ubica la lógica del programa, sin incluir funciones o cadenas de caracteres,
los cuales deberían ir en un archivo aparte para luego llamar a dichas funciones cuando sea necesario utilizarlas.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <conio.h>
#include "operations.h"
#include "menu.h"
#include "inout.h"

int main()
{
    int   state=0;

    int   valueA;
    int   valueB;

    float result;
    bool  exit=0;
    char  operation;


    system("cls"); //Limpiar pantalla. system("clear"); para Linux

    welcome();

    do
    {
        fflush(stdin); //Limpia el buffer. __fpurge(stdin); para Linux
        printInputValueA();
        state=scanf("%d", &valueA); //Se ingresa el primer valor numerico de tipo entero. Cuando la variable valueA recibe correctamente un numero valido, el estado de scanf pasa a ser 1
        system("cls");

    }while(state!=1); // state!=1 valida que se haya ingresado un numero correctamente

    do
    {
        system("cls");
        fflush(stdin);
        printInputValueB();
        state=scanf("%d", &valueB);

    }while(state!=1); // state!=1 valida que se haya ingresado un numero

    system("cls");

    while(exit==0) //Mientras la variable Exit, que es e tipo booleano, sea igual a cero, el programa ejecutará las sentencias para realizar operaciones o seleccionar nuevos valores
    {
    	printValues(valueA, valueB);

    	menuOptions();

    	fflush(stdin);

    	printInputOperation();
    	operation=getch(); //le asigna a la variable operation un caracter ingreaso por teclado

        system("cls");

    	printLine();

    	switch(operation) //Mediante la selecion de caracteres, elegimos que operacion realizar con los valores previamente ingresados
    	{
    	    case '+':
    	        result=add(valueA, valueB);
    	        printSum(result);
    	        break;

            case '-':
                result=subtract(valueA, valueB);
                printSubtraction(result);
                break;

            case '*':
                result=multiply(valueA, valueB);
                printMultiplication(result);
                break;

            case '/':
                if(valueB!=0)
                {
                    result=divide(valueA, valueB);
                    printDivision(result);
                }else
                {
                    printErrorDivByCero();
                }
                break;

            case 'a':
                if(valueA<0)
                {
                    printErrorFactNegative();
                }else
                {
                    result=factorial(valueA);
                    printFactorialA(result);
                }

        	    break;

            case 'b':
        	    if(valueB<0)
                {
                    printErrorFactNegative();
                }else
                {
                    result=factorial(valueB);
                    printFactorialB(result);
                }

        	    break;

            case 'c':                 //En caso de que se ingrese el caracter 'c', se volverá a pedir en ingreso de las variableas
                system("cls");

                do
                {
                    fflush(stdin);
                    printInputValueA();
                    state=scanf("%d", &valueA); //Cuando la variable valor1 recibe correctamente un numero valido, el estado de scanf pasa a ser 1
                    system("cls");

                }while(state!=1); // state!=1 valida que se haya ingresado un numero correctamente

                do
                {
                    system("cls");
                    fflush(stdin);
                    printInputValueB();
                    state=scanf("%d", &valueB);

                }while(state!=1); // state!=1 valida que se haya ingresado un numero correctamente

                system("cls");
                break;

            case 'S':
            case 'E':
            	system("cls");
            	printExitConfirm();

            	fflush(stdin);
            	operation=getch();

            	if(operation=='n')
            	{
            		system("cls");
            		break;
            	}

            	if(operation=='S'||operation=='Y')
            	{
            		exit=1;
            		system("cls");
            		printGoodbye();
            		break;
            	}

            default:
            	printInvalidOperation();
            	break;
    	}

    	printLine();
    }

    return 0;
}
