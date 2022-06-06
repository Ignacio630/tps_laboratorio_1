#include "Passenger.h"
#include "utn_funciones.h"
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
Passenger* Passenger_newParametros(char* idStr,char* nombreStr, char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr, char* estadoVueloStr)
{
	Passenger* pasajero;
	pasajero = Passenger_new();

	if(pasajero != NULL)
	{
		if(!Passenger_setId(pasajero, atoi(idStr)) &&
		   !Passenger_setNombre(pasajero, nombreStr) &&
		   !Passenger_setApellido(pasajero, apellidoStr) &&
		   !Passenger_setPrecio(pasajero, atof(precioStr)) &&
		   !Passenger_setTipoPasajero(pasajero, atoi(tipoPasajeroStr)) &&
		   !Passenger_setCodigoVuelo(pasajero, codigoVueloStr) &&
		   !Passenger_setEstadoVuelo(pasajero, atoi(estadoVueloStr)))
		{
			Passenger_setId(pasajero, atoi(idStr));
			Passenger_setNombre(pasajero, nombreStr);
			Passenger_setApellido(pasajero, apellidoStr);
			Passenger_setPrecio(pasajero, atof(precioStr));
			Passenger_setTipoPasajero(pasajero, atoi(tipoPasajeroStr));
			Passenger_setCodigoVuelo(pasajero, codigoVueloStr);
			Passenger_setEstadoVuelo(pasajero, atoi(estadoVueloStr));
		}
	}
	return pasajero;
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
	if(this != NULL && id > 1000)
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
		strncpy(this->nombre,nombre,sizeof(this->nombre));
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
		strncpy(this->apellido,apellido,sizeof(this->apellido));
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

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero)
	{
		retorno = 0;
		this->tipoPasajero = tipoPasajero;
	}
	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno = -1;
	if(this != NULL && tipoPasajero)
	{
		retorno = 0;
		*tipoPasajero = this->tipoPasajero;
	}
	return retorno;
}
int Passenger_setEstadoVuelo(Passenger* this,int estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo)
	{
		retorno = 0;
		this->estadoVuelo = estadoVuelo;
	}
	return retorno;
}
int Passenger_getEstadoVuelo(Passenger* this,int* estadoVuelo)
{
	int retorno = -1;
	if(this != NULL && estadoVuelo)
	{
		retorno = 0;
		*estadoVuelo = this->estadoVuelo;
	}
	return retorno;
}
int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno = -1;
	if(this != NULL && precio)
	{
		retorno = 0;
		this->precio = precio;
	}
	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno = -1;
	if(this != NULL && precio)
	{
		retorno = 0;
		*precio = this->precio;
	}
	return retorno;
}

void Passenger_printOne(Passenger* pasajero)
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	int tipoPasajero;
	char codigoVuelo[4];
	int estadoVuelo;
	Passenger_getId(pasajero, &id);
	Passenger_getNombre(pasajero, nombre);
	Passenger_getApellido(pasajero, apellido);
	Passenger_getPrecio(pasajero, &precio);
	Passenger_getTipoPasajero(pasajero, &tipoPasajero);
	Passenger_getCodigoVuelo(pasajero, codigoVuelo);
	Passenger_getEstadoVuelo(pasajero, &estadoVuelo);

	if(pasajero != NULL)
	{
		printf("|%8d|%15s|%15s|%10.2f|%8d|%8s|%8d|\n", id, nombre, apellido, precio,tipoPasajero, codigoVuelo, estadoVuelo);
	}
}

int ValidarGetters(Passenger* this)
{
	int retorno;

	retorno = -1;

	return retorno;
}
