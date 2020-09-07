
#include <stdio.h>
#include "strings_eng.h"
#include "menu.h"

void menuOptions(void)
{
        printf("\n\n%s\n", LINE);
        printf("\n%s\n"  , MSG_CODE);
        printf("\n%s"    , MSG_SUM);
        printf("\n%s"    , MSG_SUBTRACTION);
        printf("\n%s"    , MSG_DIVISION);
        printf("\n%s"    , MSG_MULTIPLICATION);
        printf("\n%s"    , MSG_FACTORIAL_A);
        printf("\n%s"    , MSG_FACTORIAL_B);
        printf("\n%s"    , MSG_CHANGE_VALUES);
        printf("\n\n%s"  , MSG_EXIT);

        return;
}
