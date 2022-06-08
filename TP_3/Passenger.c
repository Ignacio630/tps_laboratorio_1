//Includes
#include "Passenger.h"
#include "utn_funciones.h"
//Defines
#define FIRSTCLASS 0
#define EXECUTIVECLASS 1
#define ECONOMYCLASS 2
/*
 *
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int isEmpty;
 * */
Passenger* Passenger_new()
{
	Passenger* auxPassenger;
	auxPassenger = (Passenger*)malloc(sizeof(Passenger));
	return auxPassenger;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	Passenger* pasajero;
	pasajero = NULL;
	pasajero = Passenger_new();

	if(pasajero != NULL && idStr != NULL && nombreStr != NULL && apellidoStr != NULL && precioStr != NULL && tipoPasajeroStr != NULL && codigoVueloStr != NULL && estadoVueloStr != NULL)
	{
		ValidarSetters(pasajero, idStr, nombreStr, apellidoStr, precioStr, tipoPasajeroStr, codigoVueloStr, estadoVueloStr);
	}
	return pasajero;
}
int ValidarSetters(Passenger* pasajero,char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr)
{
	int retorno;
//	int tipoPasajero;

	retorno = 0;

//
//	if(strcmp(tipoPasajeroStr,"FirstClass") == 0)
//	{
//		tipoPasajero = FIRSTCLASS;
//	}
//	else
//	{
//		if(strcmp(tipoPasajeroStr,"ExecutiveClass") == 0)
//		{
//			tipoPasajero = EXECUTIVECLASS;
//		}
//		else
//		{
//			if(strcmp(tipoPasajeroStr, "EconomyClass") == 0)
//			{
//				tipoPasajero = ECONOMYCLASS;
//			}
//		}
//	}
	if(Passenger_setId(pasajero, atoi(idStr)) == -1 ||
	   Passenger_setNombre(pasajero, nombreStr) == -1 ||
	   Passenger_setApellido(pasajero, apellidoStr) == -1 ||
	   Passenger_setPrecio(pasajero, atof(precioStr)) == -1 ||
	   Passenger_setTipoPasajero(pasajero, tipoPasajeroStr) == -1 ||
	   Passenger_setCodigoVuelo(pasajero, codigoVueloStr) == -1 ||
	   Passenger_setEstadoVuelo(pasajero, estadoVueloStr) == -1)
	{
		Passenger_delete(pasajero);
		pasajero = NULL;
		retorno = -1;
	}

	return retorno;
}

void Passenger_delete(Passenger* this){
	if(this != NULL)
	{
		free(this);
	}
}

int Passenger_setId(Passenger* this,int id)
{
	int retorno = -1;
	if(this != NULL && id > 0)
	{
		retorno = 0;
		this->id = id;
	}
	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = 0;
	}
	return retorno;
}
int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(this->nombre,nombre);
	}
	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno = -1;
	if(this != NULL && nombre != NULL)
	{
		retorno = 0;
		strcpy(nombre,this->nombre);
	}
	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strcpy(this->apellido,apellido);
	}
	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno = -1;
	if(this != NULL && apellido != NULL)
	{
		retorno = 0;
		strcpy(apellido,this->apellido);
	}
	return retorno;
}
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio > 0)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio != NULL)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strcpy(this->codigoVuelo,codigoVuelo);
	}
	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno = -1;
	if(this != NULL && codigoVuelo != NULL)
	{
		retorno = 0;
		strcpy(codigoVuelo,this->codigoVuelo);
	}
	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		strcpy(this->tipoPasajero,tipoPasajero);
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero != NULL)
	{
		retorno = 0;
		strcpy(tipoPasajero,this->tipoPasajero);
	}
	return retorno;
}
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		retorno = 0;
		strcpy(this->estadoVuelo, estadoVuelo);
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo != NULL)
	{
		retorno = 0;
		strcpy(estadoVuelo,this->estadoVuelo);
	}
	return retorno;
}

void Passenger_printOne(Passenger* pasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[20];

	Passenger_getId(pasajero, &id);
	Passenger_getNombre(pasajero, nombre);
	Passenger_getApellido(pasajero, apellido);
	Passenger_getPrecio(pasajero, &precio);
	Passenger_getCodigoVuelo(pasajero, codigoVuelo);
	Passenger_getTipoPasajero(pasajero, tipoPasajero);
	Passenger_getEstadoVuelo(pasajero, estadoVuelo);

	if(pasajero != NULL)
	{
		printf("|%8d|%15s|%15s|%10.2f|%15s|%15s|%15s|\n", id, nombre, apellido, precio, codigoVuelo, tipoPasajero, estadoVuelo);
	}
}
int Passenger_CompareByName(void* p1, void* p2)
{
	Passenger* pasajero1;
	Passenger* pasajero2;

	pasajero1 = (Passenger*)p1;
	pasajero2 = (Passenger*)p2;

	return strcmp(pasajero1->nombre,pasajero2->nombre);
}
int Passenger_CompareById(void* p1, void* p2)
{
	int compara;
	int idP1;
	int idP2;
	Passenger* pasajero1;
	Passenger* pasajero2;
	pasajero1 = (Passenger*)p1;
	pasajero2 = (Passenger*)p2;

	Passenger_getId(pasajero1, &idP1);
	Passenger_getId(pasajero2, &idP2);
	compara = 0;
	if(pasajero1 != NULL && pasajero2 != NULL)
	{
		if(idP1 > idP2)
		{
			compara = 1;
		}
		else
		{
			if(idP1 < idP2)
			{
				compara = -1;
			}
		}
	}
	return compara;
}
int Passenger_CompareByFlightStatus(void* p1, void* p2)
{
	char EstadoVueloP1[200];
	char EstadoVueloP2[200];
	Passenger* pasajero1;
	Passenger* pasajero2;

	pasajero1 = (Passenger*)p1;
	pasajero2 = (Passenger*)p2;

	Passenger_getEstadoVuelo(pasajero1, EstadoVueloP1);
	Passenger_getEstadoVuelo(pasajero2, EstadoVueloP2);

	return strcmp(EstadoVueloP1,EstadoVueloP2);
}















