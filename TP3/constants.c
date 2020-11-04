/*
 * constants.c
 *
 *  Created on: 31 oct. 2020
 *      Author: Juan Dietz
 */
#include <stdio.h>
#include "constants.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void menuModificar(void)
{
	printf("\n\nModificar:\n\n");
	printf("1. Nombre\n");
	printf("2. Horas trabajadas\n");
	printf("3. Sueldo\n\n");
	printf("4. Guardar y salir\n");
	printf("5. Salir sin guardar\n");
}


void menuPrincipal(void)
{
	printf("\n\nMenu:\n\n");
	printf("1. Cargar modo texto\n");
	printf("2. Cargar modo binario\n\n");
	printf("3. Alta de empleado\n");
	printf("4. Modificar datos\n");
	printf("5. Baja de un empleado\n");
	printf("6. Listar empleados\n");
	printf("7. Ordenar empleados\n\n");
	printf("8. Guardar modo texto\n");
	printf("9. Guardar modo binario\n\n");
	printf("0. Salir\n");
}

void menuOrdenar(void)
{
	printf("\n\nOrdenar por:\n\n");
	printf("1. Id\n");
	printf("2. Nombre\n");
	printf("3. Horas trabajadas\n");
	printf("4. Sueldo\n\n");
	printf("5. Cancelar\n");
}
