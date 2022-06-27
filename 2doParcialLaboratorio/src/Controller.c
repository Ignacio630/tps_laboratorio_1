#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"
#include "parser.h"
#include "utn_funciones.h"
int controller_loadFromText(char* path , LinkedList* arrayGenerico)
{
	int retorno;
	FILE* pFile;

	retorno = -1;
	pFile = fopen(path,"r");
	if(pFile != NULL && arrayGenerico != NULL)
	{
		parser_GenericoFromText(pFile, arrayGenerico);
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
int controller_addGenerico(LinkedList* arrayGenerico)
{
	int retorno;
	eGenerico* auxGenerico;
	char id[100];
	int auxId;
	char nombre[200];
	char precio[1000];
	retorno = -1;

	if(auxGenerico != NULL)
	{
		ll_add(arrayGenerico, auxGenerico);
		controller_saveMaxId("maxid.csv",auxId);
		retorno = 0;
	}
	if(arrayGenerico != NULL)
	{
		auxId = controller_loadMaxId("maxid.csv");
		auxId++;
		itoa(auxId,id,10);
		PedirCadena(nombre, "Ingrese el nombre del pasajero:");
		PedirFlotante(precio, "Ingrese el precio del pasaje:","Error, lo que se ingreso no es un flotante.\n");
	}
	auxGenerico = eGenerico_newParametros(id, nombre, precio);
    return retorno;
}
int controller_editGenerico(LinkedList* arrayGenerico)
{
	int retorno;
	int opciones;
	eGenerico* pasajero;
	int id;
	char nombre[50];
	char precio[1000];
	int indice;
	retorno = -1;

	utn_GetEntero(&id, "|->Ingrese el ID de ..... a modificar:", "\nError! El ID ingresado es invalido o no existe aun en el programa\n",0,100000,99);
	indice = findGenericoById(arrayGenerico, id);
	if(indice != -1)
	{
		pasajero = ll_get(arrayGenerico, indice);
		if(arrayGenerico!= NULL)
		{
			do
			{
				opciones = PedirOpciones("|-----MENU-DE-MODIFICACIONES-----|\n|1-Modifcar nombre\t\t |\n|2-Modificar apellido\t\t |\n|3-Modificar precio\t\t |\n|4-Modificar codigo de vuelo\t |\n|5-Modificar tipo de pasajero    |\n|6-Modificar estado de vuelo\t |\n|7-Salir\t\t\t |\n|->Ingrese una opcion:", "Ups! Opcion invalida!!");
				switch (opciones)
				{
					case 1:
						PedirCadena(nombre, "Ingrese el nombre modificado del pasajero:");
						eGenerico_setNombre(pasajero, nombre);
						break;
					case 3:
						PedirFlotante(precio, "Ingrese el precio modificado del pasaje:","Error, lo que se ingreso no es un flotante.\n");
						eGenerico_setPrecio(pasajero, atof(precio));
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
int controller_removeGenerico(LinkedList* arrayGenerico)
{
	int id;
	int index;
	int retorno;


	utn_GetEntero(&id,"|->Ingrese el ID del pasajero que quiere remover de la lista", "Error", 0, 10000, 99);
    index= findGenericoById(arrayGenerico, id);
    if(index != -1)
    {
    	ll_remove(arrayGenerico, index);
    	retorno = 0;
    }
    else
    {
    	puts("No se pudo encontrar el ID del pasajero que quiere remover\n");
    	retorno = -1;
    }

	return retorno;
}

int controller_ListGenerico(LinkedList* arrayGenerico)
{
	int returnAux;
	int len;
	int i;
	eGenerico* this;

	returnAux = -1;
	len = ll_len(arrayGenerico);

	if(arrayGenerico != NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			this = (eGenerico*)ll_get(arrayGenerico, i);
			eGenerico_printOne(this);
		}
		returnAux = 0;
	}
    return returnAux;
}

int controller_sortGenerico(LinkedList* gArrayGenerico)
{
	int retorno;
	int option;
	retorno = -1;

	if(gArrayGenerico != NULL)
	{
		do
		{
			option = PedirOpciones("|~~~~~~~~~~~~~~~~~~~~MENU~DE~ORDENAMIENTO~~~~~~~~~~~~~~~~~~~~|\n|1-Ordenar por nombre por orden alfabeticamente creciente    |\n|2-Ordenar por nombre por orden alfabeticamente decreciente  |\n|3-Ordenar por ID de menor a mayor\t\t\t     |\n|4-Ordenar por ID de mayor a menor\t\t\t     |\n|5-Salir\t\t\t\t\t\t     |\n|____________________________________________________________|\n|->Elige la opcion: ","Ups! Opcion Invalida!!\n");
			switch(option)
			{
				case 1:
						ll_sort(gArrayGenerico, eGenerico_CompareByName, 1);
					break;
				case 2:
						ll_sort(gArrayGenerico, eGenerico_CompareByName, 0);
					break;
				case 3:
						ll_sort(gArrayGenerico, eGenerico_CompareById, 1);
					break;
				case 4:
						ll_sort(gArrayGenerico, eGenerico_CompareById, 0);
					break;
				case 5:
						puts("Saliendo...");
					break;
				default:
						puts("Ups! Opcion invalida!!");
					break;
			}
		}while(option != 5);
		system("cls");
	}

    return retorno;
}

int controller_saveAsText(char* path , LinkedList* gArrayGenerico)
{
	FILE* pfile;
	eGenerico* this;
	int len;
	int returnAux;
	int bufferId;
	char bufferNombre[500];
	float bufferPrecio;

	returnAux = -1;
	pfile = fopen(path,"w");
	if(pfile != NULL && gArrayGenerico != NULL)
	{
		len = ll_len(gArrayGenerico);
		for(int i = 0; i < len;i++)
		{
			this = ll_get(gArrayGenerico, i);
			if(!eGenerico_getId(this, &bufferId) ||
			   !eGenerico_getNombre(this, bufferNombre) ||
			   !eGenerico_getPrecio(this, &bufferPrecio))
			{
			fprintf(pfile,"%d%s%f\n",bufferId,bufferNombre,bufferPrecio);
			ll_add(gArrayGenerico, this);
			returnAux = 0;
			}
		}
	}
	fclose(pfile);
	return returnAux;
}
