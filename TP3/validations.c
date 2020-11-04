/*
 * validations.c
 *
 *  Created on: 29 oct. 2020
 *      Author: Juan Dietz
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "validations.h"

int nameToUpper(char* cadena, int len)
{
	int ret = -1;

	if(cadena != NULL && strlen (cadena) > 0 && len > 0)
	{
		int i;

		char name[len];

		strcpy(name, cadena);

		strlwr(name);

		name[0]=toupper(name[0]);

		for(i=0;i<strlen(name)-1;i++)
		{
			if(isspace(name[i]))
			name[i+1]=toupper(name[i+1]);
		}
		strcpy(cadena, name);
	}

	return ret;
}


int inputInt(int* pResult, char* inputMessage, char* errorMessage, int min, int max, int retries)
{
	int ret = -1;

	if(pResult != NULL && inputMessage != NULL && strlen (inputMessage) > 0 && strlen (errorMessage) > 0 && errorMessage != NULL && min <= max && retries >= 0)
	{
		int bufferInt;

		do
		{
			if(retries < 0)
			{
				printf("\tSe acabaron sus intentos\n\n");
				//printf("\t Volver...\n");
			}
			printf("\t%s\n", inputMessage);

			if(getInt(&bufferInt)==0 && bufferInt >= min && bufferInt <= max) //
			{
				*pResult=bufferInt;
				ret=0;
				break;
			}else
			{
				puts(errorMessage);
				retries--;
			}
		}while(retries>=0);
	}

	return ret;
}


/** \brief Valida que se guarda una cadena con formato de nombre compuesto, y lo guarda por referencia en pString
 *
 * \param Valor correspondiente a la direccion de memoria de pString
 * \param Valor correspondiente a la longitud de la cadena
 * \param Valor correspondiente a la direccion de memoria de inputMessage
 * \param Valor correspondiente a la direccion de memoria de errorMessage
 * \param Valor correspondiente a la variable retries
 * \return Devuelve si hubo error o no
 *
 */
int inputName(char* pString, int len, char* inputMessage, char* errorMessage, int retries)
{
	int ret = -1;

	if(pString != NULL && len > 0 && inputMessage!=NULL && strlen (inputMessage) > 0 && strlen (errorMessage) > 0 && errorMessage!=NULL && retries>=0)
	{
		char bufferChar[len];

		do
		{
			if(retries < 0)
			{
				printf("\tSe acabaron sus intentos\n\n");
				//printf("\t Volver...\n");
			}

			printf("\t%s\n", inputMessage);

			if(!(getChar(bufferChar, len)) && isName(bufferChar))
			{
				nameToUpper(bufferChar, len);
				strcpy(pString, bufferChar);
				ret=0;
				break;
			}else
			{
				puts(errorMessage);
				retries--;
			}
		}while(retries>=0);
	}

	return ret;
}



/** \brief Valida si se trata e un numero o si es una cadena de caracteres
 *
 * \param Valor correspondiente a la direccion de memoria de pString
 * \return Devuelve si hubo error o no
 *
 */
int isNumber(char* pString)
{
	int ret = 1;

	if (pString != NULL && strlen (pString) > 0)
	{
		int i=0;
		int count = 0;

		if (pString[0] == '\n' && strlen (pString) == 1)
		{
			ret = 0;
		}else
		{
			while (pString[i] != '\0' )
			{
				if(pString[i] == '.')
				{
					count++;
				}

				if ((pString[i] < '0' || pString[i] > '9') || count > 1)
				{
					if(!(i==0 && pString[i] == '-' && strlen(pString) > 1)) //Valida que si en la posicion anterior al numero hay un signo (-) se trata de un numero negativo y no lo descarta como char
					{
						ret = 0;
						break ;
					}
				}
				i++;
			}
		}


	}
	return ret;
}

/** \brief Valida si tiene los caracteres correspondientes a un nombre
 *
 * \param Valor correspondiente a la direccion de memoria de pString
 *
 * \return Devuelve si hubo error o no
 *
 */
int isName(char* pString)
{
	int ret = 0;

	if (pString != NULL && strlen (pString) > 1)
	{
		int i=0;

		while (pString[i] != '\0' )
		{
			if ((pString[i] >= 65 && pString[i] <= 90) || (pString[i] >= 97 && pString[i] <= 122))
			{
				ret = 1;
				break ;
			}
			i++;
		}
	}
	return ret;
}


/** \brief Valida que si la cadena esta compuesta solo por números, entonces transforma el contenido a int y lo pasa a pResultado por referencia
 *
 * \param Valor correspondiente a la direccion de memoria de pResult
 * \return Devuelve si hubo error o no
 *
 */
int getInt(int* pResult)
{
	int ret=-1;
	char buffer[64];
	if (pResult != NULL)
	{
		if (getChar(buffer, sizeof (buffer))==0 && isNumber(buffer)) // obtiene una cadena y si es un numero la transforma a entero
		{
			*pResult = atoi (buffer);
			ret = 0;
		}
	}
	return ret;
}



/* ------------------------------------------------------------------------------------------------------------------ */
/* Chars */

/** \brief Obtiene una cadena de caracteres y reemplaza el \n por \0
 *
 * \param Valor correspondiente a la direccion de memoria de cadena
 * \param Valor correspondiente a la longitud
 *
 * \return Devuelve si hubo error o no
 *
 */
int getChar(char* cadena, int longitud)
{
	int ret=-1;
	fflush (stdin);
	if (cadena != NULL && longitud > 0 && strlen (cadena) > 0 && fgets(cadena,longitud,stdin)==cadena)
	{
		fflush (stdin); // fflush o __fpurge
		if (strlen (cadena) > 1 && cadena[ strlen (cadena)-1] == '\n')
		{
			cadena[ strlen (cadena)-1] = '\0' ;
		}
	ret=0;
	}
	return ret;
}



/** \brief Valida que sea un char para ingresar una opcion
 *
 * \param caracter es un valor correspondiente a la direccion de memoria de un caracter
 * \param inputmessage es un Valor correspondiente a la direccion de memoria de un string
 * \param inputmessage es un Valor correspondiente a la direccion de memoria de un string
 * \param errormessage es un Valor correspondiente a la direccion de memoria de un string
 * \param Valor correspondiente a retries
 *
 * \return Devuelve si hubo error o no
 *
 */
int inputCharOpcion(char* caracter, char* inputMessage, char* errorMessage, int retries)
{
	int ret = -1;

	if(caracter != NULL && inputMessage != NULL && strlen(inputMessage) > 0 && errorMessage != NULL && strlen(errorMessage) > 0 && retries >= 0)
	{
		char caracterSwap = -1;

		printf("\n%s\n", inputMessage);
		fflush(stdin);
		scanf("%c", &caracterSwap);

		caracterSwap = toupper(caracterSwap);
		*caracter = caracterSwap;
		ret = 0;
	}

	return ret;
}


