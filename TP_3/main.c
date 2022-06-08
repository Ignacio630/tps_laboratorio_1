#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "utn_funciones.h"
/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
	setbuf(stdout, NULL);
    int option = 0;

    LinkedList* listaPasajeros = ll_newLinkedList();

	printf("/*******************************************\n");
	printf("/*******************************************\n");
    do{
    	option = PedirOpciones("1-Cargar datos de pasajeros (Texto)\n2-Cargar datos de pasajeros (Binario)\n3-Alta pasajero\n4-Modificar pasajero\n5-Baja pasajero\n6-Listar pasajero\n7-Ordenar pasajero\n8-Guardar pasajeros (Texto)\n9-Guardar pasajeros (Binario)\n10-Salir\nElige la opcion:", "Ups!! Opcion invalida\n");
    	switch(option)
        {
            case 1:
            	//Cargar los datos de los pasajeros en el archivo como texto
            	if(!controller_loadFromText("data.csv",listaPasajeros))
            	{
            		puts("Se cargo el archivo con exito !!!");
            	}
            	else
            	{
            		puts("Ups! Hubo un error en la carga! :(");
            	}
                break;
			case 2:
				//Cargar los datos de los pasajeros en el archivo como binario
				controller_loadFromBinary("data.csv",listaPasajeros);
				break;
			case 3:
				//Alta pasajero
				controller_addPassenger(listaPasajeros);
				break;
			case 4:
				//Modificar pasajero
				controller_editPassenger(listaPasajeros);
				break;
			case 5:
				//Baja pasajero
				controller_removePassenger(listaPasajeros);
				break;
			case 6:
				//listar pasajeros
				controller_ListPassenger(listaPasajeros);
				break;
			case 7:
				//Ordenar pasajeros
				controller_sortPassenger(listaPasajeros);
				break;
			case 8:
				//Guardar los datos de los pasajeros en el archivo como texto
				controller_saveAsText("data.csv",listaPasajeros);
				break;
			case 9:
				//Cargar los datos de los pasajeros en el archivo como binario
				controller_saveAsBinary("data.csv",listaPasajeros);
				break;
			case 10:
				//Salir
				puts("Gracias por usar mi app!! :)");
				break;
            default:
            	//Ingreso erroneo de opciones
            	printf("Ups!! Opcion invalida\n");
            	break;
        }
    }while(option != 10);
    system("cls");

    return 0;
}

