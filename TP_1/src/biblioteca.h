/*
 * biblioteca.h
 *
 *  Created on: 13 abr. 2022
 *      Author: Ignacio javier Medici
 */

#ifndef BIBLIOTECA_H_
#define BIBLIOTECA_H_
#include <stdio_ext.h>
#include <stdlib.h>
#define BTC 4606954.55

int utn_GetEntero(int*, char*, char*);
float utn_GetFloat(float*, char*, char*);
float DescuentoDebito(float, int);
float InteresCredito(float, int);
float CalcularBTC(float, float);
float CalcularPrecioUnitario(float, float, char*);
float DiferenciaPrecios(float , float);
void MostrarEntero(char*, int);
void MostrarFlotante(char*, float);
void MostrarBTC(char* , float );
void MostrarResultados(char*, float, float, float, float, float, float);
void MostrarCargaForzada();

#endif /* BIBLIOTECA_H_ */
