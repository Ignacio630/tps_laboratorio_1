/*
============================================================================
Name        : Ignacio Javier Medici
Division 	 : C
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "generico.h"
#include "utn_funciones.h"
#include "parser.h"
int main(void)
{
	setbuf(stdout,NULL);
	int opciones = 0;
	int flagOpen = 0;
	LinkedList* listaGenerico = ll_newLinkedList();
	FILE* pFile;

	pFile = fopen("data.csv","r");
	do
	{
		system("cls");
		puts("1.CARGAR ARCHIVO");
		puts("2.ALTA");
		puts("3.BAJA");
		puts("4.MODIFICACION");
		puts("5.LISTADO");
		puts("6.ORDENAR");
		puts("7.GUARDAR ARCHIVO");
		puts("8.SALIR");
		opciones = PedirOpciones("Ingrese una opcion: ", "Ups! Opcion invalida\n");
		switch (opciones) {
			case 1:
				parser_GenericoFromText(pFile, listaGenerico);
//				if()
//				{
//					puts("Se cargo el archivo con exito !!!");
//					flagOpen = 1;
//				}
//				else
//				{
//					puts("Ups! Hubo un error en la carga! :(");
//				}
				break;
			case 2:
				if(flagOpen == 1)
				{
					controller_addGenerico(listaGenerico);
				}
				else
				{
					puts("Ah ocurrido un error al intentar dar de alta!!");
				}
				break;
			case 3:
				if(flagOpen == 1)
				{
					controller_removeGenerico(listaGenerico);
				}
				else
				{
					puts("No se puede dar de baja pasajeros, si no hay pasajeros! . - .");
				}
				break;
			case 4:
				if(flagOpen == 1)
				{
					controller_editGenerico(listaGenerico);
				}
				else
				{
					puts("No se pueden modificar los datos, si no hay datos! . - .");
				}
				break;
				break;
			case 5:
				if(flagOpen == 1)
				{
					controller_ListGenerico(listaGenerico);
				}
				else
				{
					puts("No se cargo o no se dio de alta ningun pasajero!!");
				}
				break;
			case 6:
				if(flagOpen == 1)
				{
					controller_sortGenerico(listaGenerico);
				}
				else
				{
					puts("No se pueden ordenar datos, si no hay datos! . - .");
				}
				break;
			case 7:
				if(flagOpen == 1)
				{
					controller_saveAsText("data.csv", listaGenerico);
					puts("Datos con formato de texto guardados con exito!!");
				}
				else
				{
					puts("No se modifico ni implemento nada al archivo!");
				}
				break;
			case 8:
				puts("Gracias por usa mi app :)!!");
				break;
			default:
				puts("Ups! Opcion invalida!!");
				break;
		}


	}while(opciones != 8);
	return EXIT_SUCCESS;
}
