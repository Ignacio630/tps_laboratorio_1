#include "ArrayPassenger.h"

static int idIncremental=1000;
static int incrementalID(void);
static int incrementalID(void){
	return idIncremental++;
}
int FindFree(Passenger list[],int len)
{
	int retorno;
	int i;
	retorno = -1;
	if(list !=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].isEmpty == LIBRE)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int initPassengers(Passenger* list, int tam)
{
	int retorno;
	int i;
	retorno= -1;

	if(list!=NULL && tam>0)
	{
		for(i=0;i<tam;i++)
		{
			list[i].isEmpty=LIBRE;
			retorno = 0;
		}
	}
	return retorno;
}
int addPassenger(Passenger* list, int len, int id, char name[], char lastName[], float price, int typePassenger, char flycode[], int statusFlight)
{
	int retorno;
	retorno = -1;
	int banderaLibre;
	int i;
	banderaLibre = FindFree(list, len);
	if(list != NULL && len >= 0)
	{
		for(i=0;i<len;i++)
		{
			if(banderaLibre >= 0)
			{
				list[banderaLibre].id= incrementalID();
				PedirCadena(name, "Ingrese el nombre del pasajero:");
				strcpy(list[banderaLibre].name,name);
				PedirCadena(lastName, "Ingrese el apellido del pasajero:");
				strcpy(list[banderaLibre].lastName,lastName);
				utn_GetFlotante(&price, "Ingrese el precio del pasaje: ", "Error, el numero ingresado no es un flotante\n", 0, 4000000, 99);
				list[banderaLibre].price = price;
				utn_GetEntero(&typePassenger, "Ingrese el tipo de vuelo\n1.TURISTA\n2.PREMIUN\n3.EJECUTIVO\nIngrese el tipo de pasajero:", "Error, tipo de pasajero invalido", 1, 3, 99);
				list[banderaLibre].typePassenger = typePassenger;
				PedirCadena(flycode, "Ingrese el codigo de vuelo: ");
				strcpy(list[banderaLibre].flycode, flycode);
				utn_GetEntero(&statusFlight, "Ingrese el estado de vuelo\n1.ACTIVO\n2.DEMORADO\n3.CANCELADO\nElija la opcion:", "Error, estado de vuelo invalido", 1, 3, 99);
				list[banderaLibre].isEmpty = OCUPADO;
				retorno = 0;
				break;
			}
		}
	}
	return retorno;
}
int findPassengerById(Passenger* list ,int len,int id)
{
	int retorno;
	int i;

	retorno = -1;
	if(list !=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}
int modifyPassenger(Passenger* list, int len, int id)
{
	int bandera = 0;
	int i;
	int opciones;
	utn_GetEntero(&id, "Ingrese el id del pasajero que queire modificar: ", "Error, pasajero no encontrado!\n", 0, 2000, 99);
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty == OCUPADO && list[i].id == id)
		{
			do
			{
				opciones = PedirOpciones("1.Modificar nombre\n2.Modificar apellido\n3.Modificar precio\n4.Modificar tipo de vuelo\n5.Modificar codigo de vuelo\n6.Salir\n", "Error, opcion invalida");
				switch (opciones)
				{
					case 1:
						PedirCadena(list[i].name, "Ingrese la modificacion del nombre:");
						bandera=1;
						break;
					case 2:
						PedirCadena(list[i].lastName, "Ingrese la modificacion del apellido: ");
						bandera=1;
						break;
					case 3:
						utn_GetFlotante(&list->price, "Ingrese la modificacion del precio:$", "Error", 0, 40000000, 99);
						bandera=1;
						break;
					case 4:
						utn_GetEntero(&list->typePassenger, "Ingrese la modificacion del tipo de pasajero:", "Error", 0, 3, 99);
						bandera=1;
						break;
					case 5:
						PedirCadena(list[i].flycode, "Ingrese la modificacion del codigo de vuelo:");
						bandera=1;
						break;
					case 6:
						puts("Modificacion exitosa!");
						break;
					default:
						printf("Ups! Opcion invalida!!\n");
					break;
				}

			}while(opciones != 6);

		}
	}
	return bandera;
}
int removePassenger(Passenger* list, int len, int id)
{
	int i;
	char opcion;
	int flag=0;
	utn_GetEntero(&id, "Ingrese el id del pasajero que quiere remover :", "Error", 0, 2000, 99);
	if(list!=NULL && len>0)
	{
		for(i=0;i<len;i++)
		{
			if(list[i].id == id && list[i].isEmpty == OCUPADO)
			{
				printf("Esta seguro que desea eliminar este pasajero?? s/n: ");
				fflush(stdin);
				scanf("%c", &opcion);
				while(opcion != 's' && opcion != 'n')
				{
					printf("Ingrese s si queire eliminar o n si no quiere: ");
					fflush(stdin);
					scanf("%c", &opcion);
				}
				if(opcion == 's')
				{
					list[i].isEmpty = LIBRE;
					flag=1;
				}
			}
		}
	}
	return flag;
}
int printPassengers(Passenger* list,int len)
{
	int i;
	puts("<-----------------------------!INFORME PASAJEROS!------------------------------->");
	puts("|Id:\t|Nombre\t\t|Apellido\t|Precio\t\t|Clase \t|Codigo de vuelo| Estado del vuelo|");
	for(i=0;i<len;i++)
	{
		if(list[i].isEmpty == OCUPADO)
		{
			printf("|%-7d|%-15s|%-15s|%-15.2f|%-7d|%15s|%17d|\n",list[i].id ,list[i].name, list[i].lastName,list[i].price, list[i].typePassenger, list[i].flycode, list[i].statusFlight);
		}
	}
	return 0;
}
/** \brief Sort the elements in the array of passengers, the argument order indicate UP or DOWN order
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*/
int sortPassenger(Passenger* list, int len, int order) {
	int retorno = -1;
	int i;
	int j;
	Passenger aux;

	if (list != NULL && TAM > 0)
	{
		switch (order)
		{
		case 0:
			for (i=0; i < TAM - 1; i++)
			{
				for (j=i + 1; j<TAM;j++)
				{
					if (list[i].isEmpty == OCUPADO && list[j].isEmpty == OCUPADO)
					{
						if (list[i].id > list[j].id) {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			retorno = 0;
			break;
		case 1:
			for (i = 0; i < TAM - 1; i++)
			{
				for (j=i + 1; j<TAM;j++)
				{
					if (list[i].isEmpty == OCUPADO&& list[j].isEmpty == OCUPADO)
					{
						if (list[i].id < list[j].id) {
							aux = list[i];
							list[i] = list[j];
							list[j] = aux;
						}
					}
				}
			}
			retorno = 0;
			break;
		default:
			puts("Tiene que ingresar un criterio valido!");
			retorno = -1;
			break;
		}
	}
	return retorno;
}
void AltaForzada(Passenger* pasajero, Passenger* list, int len)
{
	int espacioLibre;

	if(pasajero != NULL && list != NULL && len >0)
	{
		for(int j=0;j<TAM_F;j++)
		{
			espacioLibre=FindFree(list, len);
			if(espacioLibre != -1)
			{
				pasajero[espacioLibre]=list[j];
			}
		}
	}

}
