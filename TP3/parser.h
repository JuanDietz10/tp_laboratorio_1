/*
 * parser.h
 *
 *  Created on: 29 oct. 2020
 *      Author: Juan Dietz
 */

#ifndef PARSER_H_
#define PARSER_H_

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_BinaryFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee);
int parser_TextFromEmployee(FILE* pFile , LinkedList* pArrayListEmployee);

#endif /* PARSER_H_ */
