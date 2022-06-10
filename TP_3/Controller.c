#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "utn_funciones.h"

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListPassenger)
{
	int retorno;
	FILE* pFile;

	retorno = -1;
	pFile = fopen(path,"r");
	if(pFile != NULL && pArrayListPassenger != NULL)
	{
		parser_PassengerFromText(pFile, pArrayListPassenger);
		retorno = 0;
	}
	fclose(pFile);
    return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Alta de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	Passenger* unPasajero;
	char id;
	char nombre[200];
	char apellido[200];
	char precio;
	char codigoVuelo[50];
	char tipoDePasajero[50];
	char estadoVuelo[50];
	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		PedirEntero(&id, "Ingrese el id del pasajero:","Error, lo que se ingreso no es un entero.\n");
		PedirCadena(nombre, "Ingrese el nombre del pasajero:");
		PedirCadena(apellido, "Ingrese el apellido del pasajero:");
		PedirFlotante(&precio, "Ingrese el precio del pasaje:","Error, lo que se ingreso no es un flotante.\n");
		TipoPasajeroMenu(tipoDePasajero);
		PedirCadena(codigoVuelo, "Ingrese el codigo de vuelo del pasajero: ");
		EstadoVueloMenu(estadoVuelo);
	}
	unPasajero = Passenger_newParametros(&id, nombre, apellido, &precio, codigoVuelo, tipoDePasajero, estadoVuelo);
	if(unPasajero != NULL)
	{
		ll_add(pArrayListPassenger, unPasajero);
		retorno = 0;
	}
    return retorno;
}
/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Baja de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Listar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int len;
	int i;
	Passenger* this;

	retorno = -1;
	len = ll_len(pArrayListPassenger);

	if(pArrayListPassenger != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			this = (Passenger*)ll_get(pArrayListPassenger, i);
			Passenger_printOne(this);
		}
		retorno = 0;
	}
    return retorno;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
	int retorno;
	int option;
	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		do
		{
			option = PedirOpciones("|~~~~~~~~~~~~~~~~~~~~MENU~DE~ORDENAMIENTO~~~~~~~~~~~~~~~~~~~~|\n|1-Ordenar por nombre por orden alfabeticamente creciente    |\n|2-Ordenar por nombre por orden alfabeticamente decreciente  |\n|3-Ordenar por ID de menor a mayor\t\t\t     |\n|4-Ordenar por ID de mayor a menor\t\t\t     |\n|5-Ordenar por estado de vuelo alfabeticamente decreciente   |\n|6-Ordenar por estado de vuelo de alfabeticamente creciente  |\n|7-Salir\t\t\t\t\t\t     |\n|____________________________________________________________|\n|->Elige la opcion: ","Ups! Opcion Invalida!!\n");
			switch(option)
			{
				case 1:
						ll_sort(pArrayListPassenger, Passenger_CompareByName, 1);
					break;
				case 2:
						ll_sort(pArrayListPassenger, Passenger_CompareByName, 0);
					break;
				case 3:
						ll_sort(pArrayListPassenger, Passenger_CompareById, 1);
					break;
				case 4:
						ll_sort(pArrayListPassenger, Passenger_CompareById, 0);
					break;
				case 5:
						ll_sort(pArrayListPassenger, Passenger_CompareByFlightStatus, 1);
					break;
				case 6:
						ll_sort(pArrayListPassenger, Passenger_CompareByFlightStatus, 0);
					break;
				case 7:
						puts("Saliendo...");
					break;
				default:
						puts("Ups! Opcion invalida!!");
					break;
			}
		}while(option != 7);
		system("cls");
	}

    return retorno;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

