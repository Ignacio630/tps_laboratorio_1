#include "ArrayPassenger.h"
#include "utn_funciones.h"
int main(void)
{
	setbuf(stdout,NULL);

	int opciones;
	int opcionesInforme;
	int banderaAlta = 0;
	int contadorlistaPasajeros=0;
	Passenger listaPasajeros[TAM];
	Passenger listaForzada[TAM]={{0,"Abril","Danelón",100000,"EJECUTIVO","oFsdD876", "ACTIVO", OCUPADO},
								   {1,"Emmanuel","Maciel",32000,"TURISTA","esFSD354", "DEMORADO", OCUPADO},
								   {2,"Federico","De Almeida",56000,"PREMIUN","esFSD543", "CANCELADO", OCUPADO},
								   {3,"Anger","Gonzales",19000,"TURISTA","esFSD354", "ACTIVO", OCUPADO},
								   {4,"Luciano","Giangaspro",38000.43,"PREMIUN","esFSD543", "DEMORADO", OCUPADO}};
	initPassengers(listaPasajeros, TAM);
	do{
		opciones = PedirOpciones("1.ALTA\n2.MODIFICAR\n3.BAJA\n4.INFORMAR\n5.ALTA FORZADA\n6.SALIR\nElija una opcion: ", "Ups! Opcion invalida!!\n");
		switch (opciones)
		{
			case 1:
				system("cls");
				if(listaPasajeros[TAM].isEmpty == LIBRE)
				{
					addPassenger(listaPasajeros, TAM, listaPasajeros[TAM].id, listaPasajeros[TAM].name, listaPasajeros[TAM].lastName, listaPasajeros[TAM].price, listaPasajeros[TAM].typePassenger, listaPasajeros[TAM].flycode, listaPasajeros[TAM].statusFlight);
					puts("Se dio de alta satisfacctoriamente!!");
					contadorlistaPasajeros++;
				}
				else
				{
					puts("No hay mas espacio");
				}
				break;
			case 2:
				if(contadorlistaPasajeros)
				{
					modifyPassenger(listaPasajeros, TAM, listaPasajeros->id);
				}
				else
				{
					puts("No existe listaPasajeros a modificar!");
				}
				system("cls");
				break;
			case 3:
				if(contadorlistaPasajeros>0)
				{
					if(removePassenger(listaPasajeros, TAM, listaPasajeros->id)){
						puts("Se dio de baja exitosamente");
						contadorlistaPasajeros--;
					}
					else{
						puts("No existe el id que desea elminar");
					}
				}
				else
				{
					puts("Error no existe listaPasajeros para eliminar");
				}
				system("cls");
				break;
			case 4:
				if(contadorlistaPasajeros > 0)
				{
					do{
						puts("|----------------------------------------MENU-DE-INFORMES----------------------------------------|");
						puts("|1. Lista de pasajeros ordenados alfabéticamente por Apellido y Tipo de pasajero.");
						puts("|2. Total y promedio de los precios de los pasajes, y cuántos pasajeros superan el precio promedio.");
						puts("|3. Listado de los pasajeros por Código de vuelo y estados de vuelos ‘ACTIVO’");
						puts("|4.Salir");
						opcionesInforme = PedirOpciones("|->Ingrese una opcion: ", "Ups! Opcion invalida!!\n");
						switch (opcionesInforme) {
							case 1:
									sortPassengerByNameAndType(listaPasajeros, TAM, 0);
									printPassengers(listaPasajeros, TAM);
								break;
							case 2:
									SortPromedioYTotalPasajeros(listaPasajeros, TAM);
								break;
							case 3:
									sorPassengerByFlyCodeAndFlightStatus(listaPasajeros,TAM,0);
									printPassengers(listaPasajeros, TAM);
								break;
							case 4:
									puts("Saliendo...");
								break;
							default:
									puts("Ups! Opcion invalida");
								break;
						}
					}while(opcionesInforme != 4);
				}
				else
				{
					puts("Haga al menos un alta para mostrar el menu de informe");
				}
				system("cls");
				break;
			case 5:
				if(banderaAlta==0)
				{
					AltaForzada(listaPasajeros, listaForzada, TAM);
					puts("Carga forzada realizada con exito");
					contadorlistaPasajeros += TAM;
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
