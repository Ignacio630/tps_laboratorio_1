/*
 * biblioteca.c
 *
 *  Created on: 13 abr. 2022
 *      Author: Ignacio javier Medici
 */

#include "biblioteca.h"


int utn_GetEntero(int* enteroIngresado, char*mensaje, char* mensajeError)
{
	setbuf(stdout, NULL);
	int bufferInt;

	if(enteroIngresado >= 0 && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s", mensaje);
		__fpurge(stdin);
		scanf("%d", &bufferInt);
		*enteroIngresado = bufferInt;
	}
	else
	{
		printf("%s", mensajeError);
	}

	return *enteroIngresado;
}
float utn_GetFloat(float* flotanteIngresado, char* mensaje, char* mensajeError)
{
	setbuf(stdout, NULL);
	float bufferFloat;

	if(flotanteIngresado >= 0 && mensaje != NULL && mensajeError != NULL)
	{
		printf("%s", mensaje);
		scanf("%f", &bufferFloat);
		*flotanteIngresado = bufferFloat;
	}
	else
	{
		printf("%s", mensajeError);
	}

	return *flotanteIngresado;
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



