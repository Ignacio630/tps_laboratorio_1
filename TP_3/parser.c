#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger)
{
	int retorno = -1;
	char bufferId[1000];
	char bufferNombre[500];
	char bufferApellido[500];
	char bufferPrecio[10000];
	char bufferTipoPasajero[200];
	char bufferCodigoVuelo[200];
	char bufferEstadoVuelo[200];
	Passenger* pasajero;

	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferApellido, bufferPrecio,bufferCodigoVuelo, bufferTipoPasajero, bufferEstadoVuelo);
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferApellido, bufferPrecio,bufferCodigoVuelo, bufferTipoPasajero, bufferEstadoVuelo);
			pasajero = Passenger_newParametros(bufferId, bufferNombre, bufferApellido, bufferPrecio,bufferCodigoVuelo, bufferTipoPasajero, bufferEstadoVuelo);
			if(pasajero != NULL)
			{
				ll_add(pArrayListPassenger, pasajero);
			}
		}
		retorno = 0;
	}
	return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{
	Passenger* this;
	int retorno;

	retorno = -1;
	if(pArrayListPassenger != NULL && pFile != NULL)
	{
		while(!feof(pFile))
		{
			this = Passenger_new();
			fread(this, sizeof(Passenger), 1, pFile);
			if(feof(pFile))
			{
				retorno = 0;
				break;
			}
			ll_add(pArrayListPassenger, this);

		}
	}

    return retorno;
}



