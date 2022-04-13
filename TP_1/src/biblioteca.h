/*
 * biblioteca.h
 *
 *  Created on: 13 abr. 2022
 *      Author: Ignacio javier Medici
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio.h>
#include <stdlib.h>
#define FLOATMAX 4000000000
#define INTMAX 4000000000
#define BTC 4606954.55

int MenuPrincipal(int, float, float);
int utn_GetNumero(int*, char*, char* , int , int , int );
float utn_GetFloat(float*, char*, char*, float, float, int);
float DescuentoDebito(float, int);
float InteresCredito(float, int);
int CalcularBTC(float, int);

#endif /* BIBLIOTECA_H_ */
