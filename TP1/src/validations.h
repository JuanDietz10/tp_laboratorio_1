/*
 * validations.h
 *
 *  Created on: 29 ago. 2020
 *      Author: Juan Dietz
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

int inputInt (int*  pResult, char* inputMessage, char* errorMessage, int min, int max, int retrys);
int getChar  (char* cadena,  int   longitud);
int getInt   (int*  pResult);
int isNumber (char* pString);


#endif /* VALIDATIONS_H_ */
