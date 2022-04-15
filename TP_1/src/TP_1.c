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

	do
	{
		switch(MenuPrincipal(kmIngresados, precioAerolineas, precioLatam))
		{
			case 1:
				utn_GetNumero(&kmIngresados, "Ingrese los km de su viaje: \n", "ERROR ingrese kilometros validos\n", 1, INTMAX, 999);
			break;

			case 2:
				utn_GetFloat(&precioAerolineas, "Ingrese precio del vuelo Aerolineas Argentinas\n", "ERROR el precio ingresado es invalido\n", 1, FLOATMAX, 999);
				utn_GetFloat(&precioLatam, "Ingrese precio del vuelo Latam\n", "ERROR el precio ingresado es invalido\n", 1, FLOATMAX, 999);
			break;

			case 3:
				printf("%.2f\n", DescuentoDebito(precioAerolineas, 10));
				printf("%.2f\n", InteresCredito(precioAerolineas, 25));
				printf("%f\n", CalcularBTC(precioLatam, BTC));
			break;
			case 4:
			break;

			case 5:
			break;

			case 6:
				seguir = 'n';
			break;
			default:
				printf("Opcion Incorrecta\n");
			break;
		}


	}while(seguir == 's');


	return 0;
}

