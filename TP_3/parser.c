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
	char bufferId[100];
	char bufferNombre[50];
	char bufferApellido[50];
	char bufferPrecio[1000];
	char bufferTipoPasajero[10];
	char bufferCodigoVuelo[20];
	char bufferEstadoVuelo[10];
	char falsaLectura[1000];
	Passenger* pasajero;

	fscanf(pFile,"%s",falsaLectura);
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		while(!feof(pFile))
		{
			fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferApellido, bufferPrecio,bufferCodigoVuelo, bufferTipoPasajero, bufferEstadoVuelo);
			pasajero = Passenger_newParametros(bufferId, bufferNombre, bufferApellido, bufferPrecio,bufferCodigoVuelo, bufferTipoPasajero, bufferEstadoVuelo);
			ll_add(pArrayListPassenger, pasajero);
			break;

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

    return 1;
}



