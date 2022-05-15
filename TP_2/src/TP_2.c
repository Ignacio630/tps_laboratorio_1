#include "ArrayPassenger.h"
#include "utn_funciones.h"
int main(void)
{
	setbuf(stdout,NULL);

	int opciones;
	int banderaAlta = 0;
	int contadorPasajeros=0;
	Passenger pasajero[TAM];
	Passenger listaForzada[TAM_F]={{0,"Abril","Danelón",100000,2,"oFsdD", ACTIVO},
								   {1,"Emmanuel","Maciel",32000,0,"esFSD", DEMORADO},
								   {2,"Federico","De Almeida",56000,1,"NsdFT", CANCELADO},
								   {3,"Anger","Gonzales",19000,0,"oFsdD", ACTIVO},
								   {4,"Luciano","Giangaspro",38000.43,1,"esFSD", DEMORADO}};
	initPassengers(pasajero, TAM);

	do{
		opciones = PedirOpciones("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.ALTA FORZADA\n6.SALIR\nElija una opcion: ", "Ups! Opcion invalida!!\n");
		switch (opciones)
		{
			case 1:
				system("cls");
				if(pasajero[TAM].isEmpty==LIBRE)
				{
					addPassenger(pasajero, TAM, pasajero[TAM].id, pasajero[TAM].name, pasajero[TAM].lastName, pasajero[TAM].price, pasajero[TAM].typePassenger, pasajero[TAM].flycode, pasajero[TAM].statusFlight);
					puts("Se dio de alta satisfacctoriamente!!");
					contadorPasajeros++;
				}
				else
				{
					puts("No hay mas espacio");
				}
				break;
			case 2:
				if(contadorPasajeros)
				{
					modifyPassenger(pasajero, TAM, pasajero->id);
				}
				else
				{
					puts("No existe pasajero a modificar!");
				}
				system("cls");
				break;
			case 3:
				if(contadorPasajeros>0)
				{
					removePassenger(pasajero, TAM, pasajero->id);
					puts("Se dio de baja exitosamente");
					contadorPasajeros--;
				}
				else
				{
					puts("Error no existe pasajero para eliminar");
				}
				system("cls");
				break;
			case 4:
				if(contadorPasajeros >0)
				{
					sortPassenger(pasajero, TAM, 0);
					printPassengers(pasajero, TAM);
				}
				else
				{
					puts("Haga al menos un alta para mostrar el informe");
				}
				system("cls");
				break;
			case 5:
				if(banderaAlta==0)
				{
					AltaForzada(pasajero, listaForzada, TAM);
					puts("Carga forzada realizada con exito");
					contadorPasajeros += TAM_F;
					banderaAlta=1;
				}
				else
				{
					puts("Ya se dio el alta!");
				}
				system("cls");
				break;

			case 6:
				printf("Gracias por usar mi app :)\n");
				break;

			default:
				printf("Ups! Opcion invalida!!\n");
			break;
		}
	}while(opciones !=6);

	return EXIT_SUCCESS;
}
