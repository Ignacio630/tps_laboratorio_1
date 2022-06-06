#ifndef PASSENGER_H_
#define PASSENGER_H_
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

#define LIBRE 0
#define OCUPADO 1

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int estadoVuelo;

}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr);
void Passenger_delete(Passenger* this);

int Passenger_setId(Passenger* ,int);
int Passenger_getId(Passenger* ,int*);

int Passenger_setNombre(Passenger* ,char*);
int Passenger_getNombre(Passenger* ,char*);

int Passenger_setApellido(Passenger* ,char*);
int Passenger_getApellido(Passenger* ,char*);

int Passenger_setCodigoVuelo(Passenger* ,char*);
int Passenger_getCodigoVuelo(Passenger* ,char*);

int Passenger_setTipoPasajero(Passenger* ,int);
int Passenger_getTipoPasajero(Passenger* ,int*);

int Passenger_setEstadoVuelo(Passenger* ,int);
int Passenger_getEstadoVuelo(Passenger* ,int*);

int Passenger_setPrecio(Passenger* ,float);
int Passenger_getPrecio(Passenger* ,float*);

void Passenger_printOne(Passenger* );

#endif /* PASSENGER_H_ */
