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
	int retorno;
		FILE* pFile;

		retorno = -1;
		pFile = fopen(path,"rb");
		if(pFile != NULL && pArrayListPassenger != NULL)
		{
			parser_PassengerFromBinary(pFile, pArrayListPassenger);
			retorno = 0;
		}
		fclose(pFile);
	    return retorno;
}



int controller_loadMaxId(char* path)
{
	int retorno;
	FILE* pFile;
	char bufferId[100];
	pFile = fopen(path, "r");

	if(pFile != NULL)
	{
		fscanf(pFile,"%[^\n]", bufferId);
		retorno = atoi(bufferId);
	}
	fclose(pFile);
	return retorno;
}
int controller_saveMaxId(char* path, int id)
{
	FILE* pFIle;
	int retorno;
	pFIle= fopen(path, "w");
	if(pFIle != NULL)
	{
		fprintf(pFIle, "%d", id);
		retorno = 0;
	}
	fclose(pFIle);
	return retorno;
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
	char id[100];
	int auxId;
	char nombre[200];
	char apellido[200];
	char precio[1000];
	char codigoVuelo[50];
	char tipoDePasajero[50];
	char estadoVuelo[50];
	retorno = -1;

	if(pArrayListPassenger != NULL)
	{
		auxId = controller_loadMaxId("maxid.csv");
		auxId++;
		itoa(auxId,id,10);
		PedirCadena(nombre, "Ingrese el nombre del pasajero:");
		PedirCadena(apellido, "Ingrese el apellido del pasajero:");
		PedirFlotante(precio, "Ingrese el precio del pasaje:","Error, lo que se ingreso no es un flotante.\n");
		TipoPasajeroMenu(tipoDePasajero);
		PedirCadenaConNumero(codigoVuelo, "Ingrese el codigo de vuelo del pasajero: ");
		EstadoVueloMenu(estadoVuelo);
	}
	unPasajero = Passenger_newParametros(id, nombre, apellido, precio, codigoVuelo, tipoDePasajero, estadoVuelo);
	if(unPasajero != NULL)
	{
		ll_add(pArrayListPassenger, unPasajero);
		controller_saveMaxId("maxid.csv",auxId);
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
	int retorno;
	int opciones;
	Passenger* pasajero;
	int id;
	char nombre[50];
	char apellido[50];
	char precio[1000];
	char tipoPasajero[20];
	char codigoVuelo[20];
	char estadoVuelo[20];
	int indice;
	retorno = -1;

	utn_GetEntero(&id, "|->Ingrese el ID del pasajero a modificar:", "\nError! El ID ingresado es invalido o no existe aun en el programa\n",0,100000,99);
	indice = findPassengerById(pArrayListPassenger, id);
	if(indice != -1)
	{
		pasajero = ll_get(pArrayListPassenger, indice);
		if(pArrayListPassenger != NULL)
		{
			do
			{
				opciones = PedirOpciones("|-----MENU-DE-MODIFICACIONES-----|\n|1-Modifcar nombre\t\t |\n|2-Modificar apellido\t\t |\n|3-Modificar precio\t\t |\n|4-Modificar codigo de vuelo\t |\n|5-Modificar tipo de pasajero    |\n|6-Modificar estado de vuelo\t |\n|7-Salir\t\t\t |\n|->Ingrese una opcion:", "Ups! Opcion invalida!!");
				switch (opciones)
				{
					case 1:
						PedirCadena(nombre, "Ingrese el nombre modificado del pasajero:");
						Passenger_setNombre(pasajero, nombre);
						break;
					case 2:
						PedirCadena(apellido, "Ingrese el apellido modificado del pasajero:");
						Passenger_setApellido(pasajero, apellido);
						break;
					case 3:
						PedirFlotante(precio, "Ingrese el precio modificado del pasaje:","Error, lo que se ingreso no es un flotante.\n");
						Passenger_setPrecio(pasajero, atof(precio));
						break;
					case 4:
						puts("|----------Menu-Modificaion----------|");
						TipoPasajeroMenu(tipoPasajero);
						Passenger_setTipoPasajero(pasajero, tipoPasajero);
						break;
					case 5:
						PedirCadenaConNumero(codigoVuelo, "Ingrese el codigo de vuelo modificado del pasajero: ");
						Passenger_setCodigoVuelo(pasajero, codigoVuelo);
						break;
					case 6:
						puts("|----------Menu-Modificaion----------|");
						EstadoVueloMenu(estadoVuelo);
						Passenger_setEstadoVuelo(pasajero, estadoVuelo);
						break;
					case 7:
						retorno = 0;
						puts("Saliendo..");
						break;
					default:
						puts("Ups! Opcion invalida!!");
						break;
				}
			}while(opciones != 7);
		}
		else
		{
			puts("No se encotro el ID del pasajero!\n");
		}

	}
    return retorno;
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
	int id;
	int index;
	int retorno;


	utn_GetEntero(&id,"|->Ingrese el ID del pasajero que quiere remover de la lista", "Error", 0, 10000, 99);
    index= findPassengerById(pArrayListPassenger, id);
    if(index != -1)
    {
    	ll_remove(pArrayListPassenger, index);
    	retorno = 0;
    }
    else
    {
    	puts("No se pudo encontrar el ID del pasajero que quiere remover\n");
    	retorno = -1;
    }

	return retorno;
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
	int retorno;
	retorno = -1;
    return retorno;
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
	FILE* pfile;
	Passenger* this;
	int len;
	int retorno;

	retorno = -1;
	pfile = fopen(path,"wb");
	if(pfile != NULL && pArrayListPassenger != NULL)
	{
		len = ll_len(pArrayListPassenger);
		for(int i = 0; i<len;i++)
		{
			this = ll_get(pArrayListPassenger, i);
			fwrite(this,sizeof(Passenger),1,pfile);
			retorno = 0;
		}
	}
	fclose(pfile);
    return retorno;
}

