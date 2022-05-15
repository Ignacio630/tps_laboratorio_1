#ifndef UTN_FUNCIONES_H_
#define UTN_FUNCIONES_H_
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int myGets(char* , int );

int PedirEntero(char* ,char* ,char*);

int PedirOpciones(char[] ,char[]);

int PedirFlotante(char [], char [], char []);

void PedirCadena(char [],char []);

int SumarArrays();

void MostrarCadena(char []);

int utn_GetEntero(int* ,char* ,char* ,int ,int ,int );

float utn_GetFlotante(float* ,char* ,char* ,int ,int ,int );

char utn_GetString(char* , char* , char* , int );

int ValidarCadena(char []);

int ValidarParidad(int);

int ValidarNumeroMinimoMaximo(int, int, int, char[]);

int ValirdarFloatMinimo(float ,int ,char[] );

#endif /* UTN_FUNCIONES_H_ */
