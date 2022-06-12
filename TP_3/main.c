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
	int flagOpen = 0;
    int option = 0;
    LinkedList* listaPasajeros = ll_newLinkedList();

    do{
    	option = PedirOpciones("|~~~~~~~~~~~~~MENU~PRINCIPAL~~~~~~~~~~~~~~|\n|1-Cargar datos de pasajeros (Texto)\t  |\n|2-Cargar datos de pasajeros (Binario)\t  |\n|3-Alta pasajero\t\t\t  |\n|4-Modificar pasajero\t\t\t  |\n|5-Baja pasajero\t\t\t  |\n|6-Listar pasajero\t\t\t  |\n|7-Ordenar pasajero\t\t\t  |\n|8-Guardar pasajeros (Texto)\t\t  |\n|9-Guardar pasajeros (Binario)\t\t  |\n|10-Salir\t\t\t\t  |\n|_________________________________________|\n|->Elige la opcion: ", "Ups!! Opcion invalida\n");
    	switch(option)
        {
            case 1:
            	//Cargar los datos de los pasajeros en el archivo como texto
            	if(!controller_loadFromText("data.csv",listaPasajeros))
            	{
            		puts("Se cargo el archivo con exito !!!");
            		flagOpen = 1;
            	}
            	else
            	{
            		puts("Ups! Hubo un error en la carga! :(");
            	}
                break;
			case 2:
				//Cargar los datos de los pasajeros en el archivo como binario
				if(!controller_loadFromBinary("data.bin",listaPasajeros))
				{
					puts("Se cargo el archivo con exito !!!");
					flagOpen = 1;
				}
				else
				{
					puts("Ups! Hubo un error en la carga! :(");
				}
				break;
			case 3:
				//Alta pasajero
				if(flagOpen == 1)
				{
					controller_addPassenger(listaPasajeros);
				}
				else
				{
					puts("Ah ocurrido un error al intentar dar de alta!!");
				}
				break;
			case 4:
				//Modificar pasajero
				if(flagOpen == 1)
				{
					puts("|----------MODIFICAR-PASAJERO----------|");
					controller_editPassenger(listaPasajeros);
				}
				else
				{
					puts("No se pueden modificar los datos, si no hay datos! . - .");
				}
				break;
			case 5:
				//Baja pasajero
				if(flagOpen == 1)
				{
					puts("|--------BAJA-PASAJERO--------");
					controller_removePassenger(listaPasajeros);
				}
				else
				{
					puts("No se puede dar de baja pasajeros, si no hay pasajeros! . - .");
				}
				break;
			case 6:
				//listar pasajeros
				if(flagOpen == 1)
				{
					controller_ListPassenger(listaPasajeros);
				}
				else
				{
					puts("No se cargo o no se dio de alta ningun pasajero!!");
				}
				break;
			case 7:
				//Ordenar pasajeros
				if(flagOpen == 1)
				{
					controller_sortPassenger(listaPasajeros);
				}
				else
				{
					puts("No se pueden ordenar datos, si no hay datos! . - .");
				}
				break;
			case 8:
				//Guardar los datos de los pasajeros en el archivo como texto
				if(flagOpen == 1)
				{
					controller_saveAsText("data.csv",listaPasajeros);
					puts("Datos con formato de texto guardados con exito!!");
				}
				else
				{
					puts("No se modifico ni implemento nada al archivo!");
				}
				break;
			case 9:
				//Cargar los datos de los pasajeros en el archivo como binario
				if(flagOpen == 1)
				{
					controller_saveAsBinary("data.bin",listaPasajeros);
					puts("Datos con formato de binaria guardados con exito!!");
				}
				else
				{
					puts("No se modifico ni implemento nada al archivo!");
				}
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

