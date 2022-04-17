/*
 ============================================================================
 Name        : Ignacio Javier Medici
 Division    : C
 1 Enunciado
 Una agencia de viaje necesita calcular costos para sus vuelos de Latam y Aerol�neas Argentinas
 para ofrecerlos a sus clientes.
 Se deber� ingresar por cada vuelo los km totales y el precio total del mismo.
 El objetivo de la aplicaci�n es mostrar las diferentes opciones de pagos a sus clientes.
 Para ello el programa iniciar� y contar� con un men� de opciones:
 1. Ingresar Kil�metros: ( km=x)
 2. Ingresar Precio de Vuelos: (Aerol�neas=y, Latam=z)
  - Precio vuelo Aerol�neas:
  - Precio vuelo Latam:
 3. Calcular todos los costos:
  a) Tarjeta de d�bito (descuento 10%)
  b) Tarjeta de cr�dito (inter�s 25%)
  c) Bitcoin (1BTC -> 4606954.55 Pesos Argentinos)
  d) Mostrar precio por km (precio unitario)
  e) Mostrar diferencia de precio ingresada (Latam - Aerol�neas)
 4. Informar Resultados
 Latam:
  a) Precio con tarjeta de d�bito: r
  b) Precio con tarjeta de cr�dito: r
  c) Precio pagando con bitcoin : r
  d) Precio unitario: r
 Aerol�neas:
  a) Precio con tarjeta de d�bito: r
  b) Precio con tarjeta de cr�dito: r
  c) Precio pagando con bitcoin : r
  d) Precio unitario: r
 La diferencia de precio es : r �
  5. Carga forzada de datos
  6. Salir
 ============================================================================
 */
#include "biblioteca.h"

int main()
{
	setbuf(stdout, NULL);
	char seguir = 's';
	int kmIngresados = 0;
	float precioAerolineas = 0;
	float precioLatam = 0;
	int opcion;

	float credito = 0;
	float debito = 0;
	float precioUnitario = 0;
	float bitcoin = 0;
	float diferenciaDePrecio = 0;

	do
	{
		system("clear");
		printf("1. Ingresar kilometros(km = %d)\n", kmIngresados);
		printf("2. Ingresar precio de vuelos (Aerolineas=%.2f , Latam=%.2f )\n", precioAerolineas, precioLatam);
		printf("3. Calcular todos los costos\n");
		printf("4. Informar resultados\n");
		printf("5. Carga forzada de datos\n");
		printf("6. Salir\n");
		printf("Ingrese una opcion\n");
		scanf("%d", &opcion);

		switch(opcion)
		{
			case 1:
				kmIngresados = PedirEntero();
			break;

			case 2:
				switch(SubMenu())
					{
					case 1: //pide el precio de el vuelo de Aerolineas
						precioAerolineas = PedirFlotante(precioAerolineas);
						printf("Precio de aerolineas ingresado con exito! :)");
					break;
					case 2: //pide el precio de el vuelo de Latam
						precioLatam = PedirFlotante(precioLatam);
						printf("Precio de Latam ingresado con exito! :)");
					break;
					}
			break;
			case 3:
				if(precioAerolineas > 0 && precioLatam > 0 && kmIngresados > 1)
				{
					debito = DescuentoDebito(precioAerolineas, 10);
					credito = InteresCredito(precioAerolineas, 25);
					bitcoin = CalcularBTC(precioAerolineas, BTC);
					precioUnitario = CalcularPrecioUnitario(precioAerolineas, kmIngresados, "Error no se puede dividir por 0");
					diferenciaDePrecio = DiferenciaPrecios(precioAerolineas, precioLatam);
					printf("Calculo terminado :)\n");
				}
				else
				{
					printf("Error!! El calculo no pudo hacer por falta de datos :(\nPor favor ingrese los datos necesarios (km, precio vuelos), gracias :) \n");
				}
			break;
			case 4:
				printf("KMs Ingresados: %d\n", kmIngresados);
				MostrarResultados("\nPrecio Aerolineas: ", precioAerolineas, debito, credito, bitcoin, diferenciaDePrecio, precioUnitario);
				MostrarResultados("\nPrecio Latam: ", precioLatam, debito, credito, bitcoin, diferenciaDePrecio, precioUnitario);
				printf("\nLa diferencia de precio es: %.2f \n", diferenciaDePrecio);
			break;

			case 5:
				MostrarCargaForzada(7090, 162965, 159339);
			break;

			case 6:
				seguir = 'n';
				printf("Gracias por usar mi app :) \nVuelva pronto!\n");
			break;
			default:
				printf("Opcion Incorrecta\n");
			break;
		}


	}while(seguir == 's');


	return 0;
}

