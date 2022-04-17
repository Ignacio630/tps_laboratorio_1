/*
 * biblioteca.c
 *
 *  Created on: 13 abr. 2022
 *      Author: Ignacio javier Medici
 */

#include "biblioteca.h"


int PedirEntero()
{
	int enteroIngresado;
	printf("Ingrese los km del viaje: \n");
	scanf("%d", &enteroIngresado);
	enteroIngresado = ValidarEntero(enteroIngresado, 1, "Error, los km ingresados tienen que ser mayor a 0");
	return enteroIngresado;
}
int ValidarEntero(int enteroIngresado, int minimo, char* mensajeError)
{
	int resultado;
	if(enteroIngresado > minimo)
	{
		resultado = enteroIngresado;
	}
	else
	{
		printf("%s\n", mensajeError);
	}
	return resultado;
}
float PedirFlotante()
{
	float flotanteIngresado;
	printf("Ingrese precio del vuelo: \n");
	scanf("%f", &flotanteIngresado);
	flotanteIngresado = ValidarEntero(flotanteIngresado, 1, "Error el precio ingresado es menor a 0.\n Reingrese otra vez los precios :)\n");
	return flotanteIngresado;
}
float ValidarFlotante(float flotanteIngresado, int minimo, char* mensajeError)
{
	int resultado;
	if(flotanteIngresado > minimo)
	{
		resultado = flotanteIngresado;
	}
	else
	{
		printf("%s\n", mensajeError);
	}
	return resultado;
}
int SubMenu()
{
	int opcion;
	printf("-----------------SubMenu-----------------\n");
	printf("\n1-Precio de Aerolineas Argentinas: \n");
	printf("2-Precio de Latam: \n");
	printf("-----------------------------------------\n");
	printf("\nIngrese una opcion: \n");
	scanf("(%d", &opcion);

	while(opcion < 1 || opcion > 2)
	{
		printf("La opcion ingresada es invalida\n Por favor reingrese la opcion");
		scanf("(%d", &opcion);
	}
	return opcion;
}
float DescuentoDebito(float precioIngresado, int descuento)
{
	float precioDescuento;
	float precioDescuentoAplicado;

	precioDescuento = (precioIngresado * descuento)/ 100;

	precioDescuentoAplicado = precioIngresado - precioDescuento;

	return precioDescuentoAplicado;
}
float InteresCredito(float precioIngresado, int interesIngresado)
{
	float precioInteres;
	float precioInteresAplicado;

	precioInteres = (precioIngresado * interesIngresado)/ 100;

	precioInteresAplicado = precioIngresado + precioInteres;

	return precioInteresAplicado;
}
float CalcularBTC(float precioIngresado, float precioEnBTC)
{
	float resultado;

	resultado = precioIngresado / precioEnBTC;

	return resultado;
}
float CalcularPrecioUnitario(float precioIngresado, float kmIngresado, char* mensajeError)
{
	float resultado;
	if(kmIngresado > 1)
	{
		resultado = precioIngresado / kmIngresado;
	}
	else
	{
		printf("%s\n", mensajeError);
	}
	return resultado;
}
float DiferenciaPrecios(float precioAerolineas, float precioLatam)
{
	float resultado;

	resultado = precioAerolineas - precioLatam;

	return resultado;
}
void MostrarResultados(char* mensaje, float precioAerolineas, float debito, float credito, float bitcoin, float diferencia, float precioUnitario)
{
	printf("%s %.2f\n", mensaje, precioAerolineas);
	printf("A) Precio con tarjeta de debito: $ %.2f", debito);
	printf("\nB) Precio con tarjeta de credito: $ %.2f", credito);
	printf("\nC) Precio pagando con bitcoin: $ %f BTC", bitcoin);
	printf("\nD) Mostrar precio unitario: $ %.2f\n", precioUnitario);
}
void MostrarCargaForzada(int kmIngresados, float precioAerolineas, float precioLatam)
{
	printf("KMs Ingresados: %d\n", kmIngresados);
	printf("\nPrecio Aerolineas: $%.2f\n", precioAerolineas);
	printf("A) Precio con tarjeta de debito: $ %.2f", DescuentoDebito(precioAerolineas, 10));
	printf("\nB) Precio con tarjeta de credito: $ %.2f", InteresCredito(precioAerolineas, 25));
	printf("\nC) Precio pagando con bitcoin: $ %f BTC", CalcularBTC(precioAerolineas, BTC));
	printf("\nD) Mostrar precio unitario: $ %.2f\n", CalcularPrecioUnitario(precioAerolineas, kmIngresados, "Error no se puede dividir por 0"));
    /////////////////////////////////////////////////////////////////
	printf("\nPrecio Latam: $%.2f\n", precioLatam);
	printf("A) Precio con tarjeta de debito: $ %.2f", DescuentoDebito(precioLatam, 10));
	printf("\nB) Precio con tarjeta de credito: $ %.2f", InteresCredito(precioLatam, 25));
	printf("\nC) Precio pagando con bitcoin: $ %f BTC", CalcularBTC(precioLatam, BTC));
	printf("\nD) Mostrar precio unitario: $ %.2f\n", CalcularPrecioUnitario(precioLatam, kmIngresados, "Error no se puede dividir por 0"));
	printf("\nLa diferencia de precio es: $ %.2f\n", DiferenciaPrecios(precioAerolineas, precioLatam));
}



