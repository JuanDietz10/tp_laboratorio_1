/*
 * validations.h
 *
 *  Created on: 29 oct. 2020
 *      Author: Juan Dietz
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

int inputInt(int* pResult, char* inputMessage, char* errorMessage, int min, int max, int retries);
int inputName(char* pString, int len, char* inputMessage, char* errorMessage, int retries);
int isNumber(char* pString);
int isName(char* pString);
int getInt(int* pResult);
int getChar(char* cadena, int longitud);
int inputCharOpcion(char* caracter, char* inputMessage, char* errorMessage, int retries);
int nameToUpper(char* cadena, int len);

#endif /* VALIDATIONS_H_ */
