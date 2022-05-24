#include "Passenger.h"
#include "utn_funciones.h"

Passenger* Passenger_new()
{
	Passenger* auxPassenger;
	auxPassenger = NULL;
	auxPassenger = (Passenger*)malloc(sizeof(Passenger));
	return auxPassenger;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* tipoPasajeroStr)
{
	Passenger* pasajero;
	pasajero = (Passenger*)malloc(sizeof(Passenger));
	int pId;
	int pTipo;

	pId= atoi(idStr);
	pasajero->id = pId;
	strcpy(pasajero->nombre, nombreStr);
	strcpy(pasajero->apellido, nombreStr);
	pTipo = atoi(tipoPasajeroStr);
	pasajero->tipoPasajero = pTipo;

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



	return 0;
}
