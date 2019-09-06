
#include <stdio.h>
#include "operations.h"

//Desarrollo

/** \brief Recibe dos valores num�ricos enteros y calcula la suma
 *
 * \param Valor correspondiente a la variable A
 * \param Valor correspondiente a la variable B
 * \return El resultado de la suma
 *
 */
int add(int a, int b)
{
    int resultado;

    resultado=a+b;
    return resultado;
}

/** \brief Recibe dos valores num�ricos enteros y calcula la resta
 *
 * \param Valor correspondiente a la variable A
 * \param Valor correspondiente a la variable B
 * \return El resultado de la resta
 *
 */
int subtract(int a, int b)
{
    int resultado;

    resultado=a-b;
    return resultado;
}

/** \brief Recibe dos valores num�ricos enteros y calcula la multiplicaci�n
 *
 * \param Valor correspondiente a la variable A
 * \param Valor correspondiente a la variable B
 * \return El resultado de la multiplicaci�n
 *
 */
int multiply(int a, int b)
{
    int resultado;

    resultado=a*b;
    return resultado;
}

/** \brief Recibe dos valores num�ricos enteros y calcula la divisi�n
 *
 * \param Valor correspondiente a la variable A
 * \param Valor correspondiente a la variable B
 * \return El resultado de la divisi�n
 *
 */
float divide(int a, int b)
{
    float resultado;

    resultado=(float)a/b;
    return resultado;
}

/** \brief Recibe dos valores num�ricos enteros y calcula el factorial
 *
 * \param Valor correspondiente a la variable n
 * \return El resultado del factorial
 *
 */
int factorial(int n)
{
    int resultado=1;
    int contador;

    for(contador=1;contador<=n;contador++)
    {
        resultado*=contador;
    }
    return resultado;
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
