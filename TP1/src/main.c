
/*
En el archivo principal o main, se ubica la logica del programa, sin incluir funciones o cadenas de caracteres,
los cuales deberan ir en un archivo aparte para luego llamar a dichas funciones cuando sea necesario utilizarlas.
*/

#include <stdio.h>
//#include <stdio ext.h>
#include <stdlib.h>
#include "operations.h"
#include "menu.h"
#include "validations.h"
#include "strings_esp.h"
//#include "strings_eng.h"
#include "constants.h"


int main()
{
	setbuf(stdout, NULL);

	int   valueA = 0;
	int   valueB = 0;

	int   stateAdd = 0;
	int   stateSubt = 0;
	int   stateDiv = 1;
	int   stateMult = 0;
	int   stateFactA = 0;
	int   stateFactB = 0;

	int   exit;
	int   input;

	int   resultSum = 0;
	int   resultSubt = 0;
	int   resultMult = 0;
	float resultDiv = 0;
	int   resultFactA = 1;
	int   resultFactB = 1;

    //IMPORTANTE: En Linux en lugar de fflush() se debe utilizar la función __fpurge()


	system("cls"); //Limpiar pantalla. system("clear"); para Linux


	printf("\n-----------------------------------------\n");
	printf("%s\n"  , MSG_WELCOME);
	printf("-----------------------------------------\n\n");

	do
	{
		exit=0;

		menu(&valueA, &valueB);

		inputInt(&input, MSG_INPUT_OPTION, MSG_INVALID_CHAR_INPUT, 1, 5, RETRIES);

		system("cls");

		switch(input)
		{
			case 1:
				inputInt(&valueA, MSG_INPUT_VALUE_A, MSG_INVALID_CHAR_INPUT, -DOMAIN, DOMAIN, RETRIES);
				break;

			case 2:
				inputInt(&valueB, MSG_INPUT_VALUE_B, MSG_INVALID_CHAR_INPUT, -DOMAIN, DOMAIN, RETRIES);
				break;

			case 3:
				stateAdd=add(valueA, valueB, &resultSum);
				stateSubt=subtract(valueA, valueB, &resultSubt);
				stateMult=multiply(valueA, valueB, &resultMult);
				stateDiv=divide(valueA, valueB, &resultDiv);
				stateFactA=factorial(valueA, &resultFactA);
				stateFactB=factorial(valueB, &resultFactB);
				break;

			case 4:
				if(stateAdd)
				{
					printf("\n%s\n", MSG_ERROR_GENERAL);
				}else
				{
					printf("\n%s%d\n", MSG_PRINT_SUM, resultSum);
				}


				if(stateSubt)
				{
					printf("\n%s\n", MSG_ERROR_GENERAL);
				}else
				{
					printf("\n%s%d\n", MSG_PRINT_SUBTRACTION, resultSubt);
				}


				if(stateMult)
				{
					if(stateMult == -1)
					{
						printf("\n%s\n", MSG_ERROR_GENERAL);
					}else
					{
						printf("\n%s\n", MSG_ERROR_MULT_OVERFLOW);
					}
				}else
				{
					printf("\n%s%d\n", MSG_PRINT_MULTIPLICATION, resultMult);
				}


				if(stateDiv)
				{
					printf("\n%s\n", MSG_ERROR_DIVISION_ZERO);
				}else
				{
					printf("\n%s%.4f\n", MSG_PRINT_DIVISION, resultDiv);
				}


				if(stateFactA)
				{
					if(stateFactA == -1)
					{
						printf("\n%s\n", MSG_ERROR_FACT_NEGATIVE);
					}else
					{
						printf("\n%s\n", MSG_ERROR_FACT_OVERFLOW);
					}
				}else
				{
					printf("\n%s%d\n", MSG_PRINT_FACTORIAL_A, resultFactA);
				}


				if(stateFactB)
					{
						if(stateFactB == -1)
						{
							printf("\n%s\n", MSG_ERROR_FACT_NEGATIVE);
						}else
						{
							printf("\n%s\n", MSG_ERROR_FACT_OVERFLOW);
						}
					}else
					{
						printf("\n%s%d\n", MSG_PRINT_FACTORIAL_B, resultFactB);
					}
				break;

			case 5:
				exit=1;
				break;

		}
	}while(!exit);

	puts(MSG_GOODBYE);

	return 0;
}
