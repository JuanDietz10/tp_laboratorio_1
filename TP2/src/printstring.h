/*
 * printstring.h
 *
 *  Created on: 27 sep. 2020
 *      Author: John
 */

#ifndef PRINTSTRING_H_
#define PRINTSTRING_H_


void pWelcome(void);

void pMenuOptions  (void);
void pListEmployees(void);

void pInputName    (void);
void pInputLastname(void);
void pInputSalary  (void);
void pInputSector  (void);
void pNoSpace      (void);

void pInputSuccessful(void);

void pLine  (void);
void pSpace (void);
void pAnyKey(void);

void pErrorAdd   (void);
void pErrorRemove(void);
void pErrorSort  (void);
void pErrorUpdate(void);
void pErrorInit  (void);

void pUpdateMenu   (void);
void pUpdateDone   (void);
void pInvalidOption(void);
void pConfirmExit  (void);

void pNoMatchId(void);


#endif /* PRINTSTRING_H_ */
