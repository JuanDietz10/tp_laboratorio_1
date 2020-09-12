
#include <stdio.h>
#include <stdlib.h>
#include "operations.h"



/** \brief Recibe dos valores numéricos enteros, calcula la suma y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable A
 * \param Valor correspondiente a la variable B
 * \param Valor correspondiente a la variable pResult
 * \return Devuelve si hubo error o no
 *
 */
int add(int a, int b, int* pResult)
{
	int ret = -1;
	int sum;

	if(pResult!=NULL)
	{
		sum=a+b;
		*pResult=sum;
		ret=0;
	}
	return ret;
}

/** \brief Recibe dos valores numéricos enteros, calcula la resta y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable A
 * \param Valor correspondiente a la variable B
 * \param Valor correspondiente a pResult, se guarda el resultado en el contenido de la direccion de memoria que guarda la variable
 * \return Devuelve si hubo error o no
 *
 */
int subtract(int a, int b, int* pResult)
{
	int ret = -1;
	int subtraction;

	if(pResult!=NULL)
	{
		subtraction=a-b;
		*pResult=subtraction;
		ret=0;
	}
	return ret;
}

/** \brief Recibe dos valores numéricos enteros, calcula la multiplicacion y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable A
 * \param Valor correspondiente a la variable B
 * \param Valor correspondiente a pResult, se guarda el resultado en el contenido de la direccion de memoria que guarda la variable
 * \return Devuelve si hubo error o no
 *
 */
int multiply(int a, int b, int* pResult)
{
	int ret = -1;
	int mult;

	if(pResult!=NULL)
	{
		if(a==0 || b==0)
		{
			mult=a*b;
			*pResult=mult;
			ret=0;
		}else
		{
			if(a!=0 && abs(b)<=2147483647/abs(a)) //evitar overflow en una variable tipo int.
			{
				mult=a*b;
				*pResult=mult;
				ret=0;
			}else
			{
				ret=-2; //overflow
			}
		}



	}
	return ret;
}

/** \brief Recibe dos valores numéricos enteros, calcula la division y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable A
 * \param Valor correspondiente a la variable B
 * \param Valor correspondiente a pResult, se guarda el resultado en el contenido de la direccion de memoria que guarda la variable
 * \return Devuelve si hubo error o no
 *
 */
int divide(int a, int b, float* pResult)
{
	int   ret=-1;
	float division;

	if(b!=0 && pResult!=NULL)
	{
		division=(float)a/b;
		*pResult=division;
		ret=0;
	}
	return ret;
}

/** \brief Recibe un valor numérico entero, calcula el factorial y devuelve el valor del resultado por referencia
 *
 * \param Valor correspondiente a la variable n
 * \param Valor correspondiente a ña variable pResult
 * \return Devuelve si hubo error y el tipo de error
 *
 */
int factorial(int n, int* pResult)
{
	int ret=-1;
	int result=1;
	int count;

	if(n>=0 && pResult!=NULL) //Dominio: numeros mayores o iguales a cero
	{
		if(n<=12) //Evitar overflow, si se modifica el tipo de variable y/o sistema operativo el valor puede aumentar para usar numeros mayores
		{
			for(count=1;count<=n;count++)
			{
				result*=count;
			}
			*pResult=result;
			ret=0;
		}else
		{
			ret=-2; // Codigo para indicar overflow
			}
	}
	return ret;
}

/*int factorial(int n)
{
	int respuesta;
	if(n==1)
	{
		return 1;
	}else
	{
		respuesta=n*factorial(n-1);
	}
	return respuesta;
}*/
