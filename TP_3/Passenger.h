#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "LinkedList.h"
typedef struct
{
	int id;
	char nombre[500];
	char apellido[500];
	float precio;
	char codigoVuelo[200];
	char tipoPasajero[200];
	char estadoVuelo[200];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);
void Passenger_delete(Passenger* this);
int ValidarSetters(Passenger* this,char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);

int Passenger_setId(Passenger* ,int);
int Passenger_getId(Passenger* ,int*);

int Passenger_setNombre(Passenger* ,char*);
int Passenger_getNombre(Passenger* ,char*);

int Passenger_setApellido(Passenger* ,char*);
int Passenger_getApellido(Passenger* ,char*);

int Passenger_setCodigoVuelo(Passenger* ,char*);
int Passenger_getCodigoVuelo(Passenger* ,char*);

int Passenger_setTipoPasajero(Passenger* ,char*);
int Passenger_getTipoPasajero(Passenger* ,char*);

int Passenger_setEstadoVuelo(Passenger* ,char*);
int Passenger_getEstadoVuelo(Passenger* ,char*);

int Passenger_setPrecio(Passenger* ,float);
int Passenger_getPrecio(Passenger* ,float*);

void Passenger_printOne(Passenger* );

int Passenger_CompareByName(void*, void*);
int Passenger_CompareById(void*, void*);
int Passenger_CompareByFlightStatus(void*, void*);
int findPassengerById(LinkedList*,int);

//Menu
void TipoPasajeroMenu(char*);
void EstadoVueloMenu(char*);
#endif /* PASSENGER_H_ */
