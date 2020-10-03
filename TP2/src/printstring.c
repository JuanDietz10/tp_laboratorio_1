/*
 * printstring.c
 *
 *  Created on: 27 sep. 2020
 *      Author: John
 */


#include <stdio.h>

#include "printstring.h"
#include "conststring.h"

void pWelcome(void)
{
    printf("\t\t\t\t%s\n", MSG_WELCOME);
}

void pMenuOptions(void)
{
    printf("\n\n\t\t\t%s\n", MSG_LOGO);
    printf("\n\n\t\t\t%s\n", MSG_MENU_TIT);
    printf("\t\t\t%s\n",     MSG_CODE);
    printf("\n\t\t\t%s\n",   MSG_MENU_ADD);
    printf("\t\t\t%s\n",     MSG_MENU_UPDATE);
    printf("\t\t\t%s\n",     MSG_MENU_REMOVE);
    printf("\t\t\t%s\n",     MSG_MENU_LIST);
    printf("\t\t\t%s\n",     MSG_MENU_EXIT);
}

void pInputName(void)
{
    printf("\t%s\n", MSG_INPUT_NAME);
}

void pInputLastname(void)
{
    printf("\t%s\n", MSG_INPUT_LASTNAME);
}

void pInputSalary(void)
{
    printf("\t%s\n", MSG_INPUT_SALARY);
}

void pInputSector(void)
{
    printf("\t%s\n", MSG_INPUT_SECTOR);
}

void pNoSpace(void)
{
    printf("\t%s\n", MSG_NO_SPACE);
}

void pInputSuccessful(void)
{
    printf("\t\t\t%s\n", MSG_INPUT_SUCCESSFUL);
}


void pLine(void)
{
    printf("\t%s\n", LINE);
}



void pAnyKey(void)
{
    printf("\t%s\n", MSG_PRESS_ENTER);
}

void pListEmployees(void)
{
    printf("\n\t%s", MSG_OUTPUT_MENU);
    printf("\n%s",   LINE);
}

void pErrorAdd(void)
{
    printf("\t%s\n", MSG_ERROR_ADD);
}

void pErrorSort(void)
{
    printf("\t%s\n", MSG_ERROR_SORT);
}

void pErrorRemove(void)
{
    printf("\t%s\n", MSG_ERROR_REMOVE);
}

void pErrorUpdate(void)
{
    printf("\t%s\n", MSG_ERROR_UPDATE);
}


void pUpdateMenu(void)
{
    printf("\n\t%s\n", MSG_UPNAME);
    printf("\t%s\n",   MSG_UPLNAME);
    printf("\t%s\n",   MSG_UPSALARY);
    printf("\t%s\n",   MSG_UPSECTOR);
    printf("\t%s\n",   MSG_UPEXIT);
}
void pNoMatchId(void)
{
    printf("\t%s\n", MSG_NO_MATCH_ID);
}
void pUpdateDone(void)
{
    printf("\n\t%s\n", MSG_UPDONE);
}
void pInvalidOption(void)
{
    printf("\t%s\n", MSG_INVALID_OPTION);
}

void pConfirmExit(void)
{
    printf("\t%s\n", MSG_CONFIRM_EXIT);
}

void pErrorInit(void)
{
    printf("\t%s\n", MSG_ERROR_INIT);
}
