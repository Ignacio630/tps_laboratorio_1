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

    do{
    	option = PedirOpciones("1-Cargar datos de pasajeros (Texto)\n2-Cargar datos de pasajeros (Binario)\n3-Alta pasajero\n4-Modificar pasajero\n5-Baja pasajero\n6-Listar pasajero\n7-Ordenar pasajero\n8-Guardar pasajeros (Texto)\n9-Guardar pasajeros (Binario)\n10-Salir\nElige la opcion:", "Ups!! Opcion invalida\n");

    	switch(option)
        {
            case 1:
                controller_loadFromText("data.csv",listaPasajeros);
                system("cls");
                break;
			case 2:
				controller_loadFromText("data.csv",listaPasajeros);
				system("cls");
				break;
			case 3:
				controller_loadFromText("data.csv",listaPasajeros);
				system("cls");
				break;
			case 4:
				controller_loadFromText("data.csv",listaPasajeros);
				system("cls");
				break;
			case 5:
				controller_loadFromText("data.csv",listaPasajeros);
				system("cls");
				break;
			case 6:
				controller_loadFromText("data.csv",listaPasajeros);
				system("cls");
				break;
			case 7:
				controller_loadFromText("data.csv",listaPasajeros);
				system("cls");
				break;
			case 8:
				controller_loadFromText("data.csv",listaPasajeros);
				system("cls");
				break;
			case 9:
				controller_loadFromText("data.csv",listaPasajeros);
				system("cls");
				break;
			case 10:
				controller_loadFromText("data.csv",listaPasajeros);
				system("cls");
				break;

            default:
            	system("cls");
            	printf("Ups!! Opcion invalida\n");
            	break;
        }
    }while(option != 10);
    return 0;
}

