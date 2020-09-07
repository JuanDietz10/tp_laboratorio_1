/*
 * validations.h
 *
 *  Created on: 29 ago. 2020
 *      Author: John
 */

#ifndef VALIDATIONS_H_
#define VALIDATIONS_H_

int inputInt       (int*   pResult,    char* inputMessage, char* errorMessage, int   min,      int   max,   int retrys);
int getFloat       (float* pResult,    char* inputMessage, char* errorMessage, float min,      float max,   int retrys);
int getCharByNum   (char*  pResult,    char* inputMessage, char* errorMessage, char  min,      char  max,   int retrys);
int getCharByType  (char*  pResult,    char* inputMessage, char* errorMessage, char  typeChar, int   retrys           );
int getChar        (char*  cadena,     int   longitud                                                                 );
int getInt         (int*   pResultado                                                                                 );
int isNumber       (char*  cadena                                                                                     );


#endif /* VALIDATIONS_H_ */
