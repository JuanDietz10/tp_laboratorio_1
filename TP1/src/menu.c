
#include <stdio.h>
#include "strings_esp.h"
//#include "strings_eng.h"

void menu(int* a, int* b)
{
	printf("\n1. Ingresar 1er operando (A=%d)", *a);
	printf("\n2. Ingresar 2do operando (B=%d)", *b);
	printf("\n3. Calcular todas las operaciones");
	printf("\n4. Informar resultados");
	printf("\n5. Salir\n");

	return;
}
