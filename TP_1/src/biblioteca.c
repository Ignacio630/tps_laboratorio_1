/*
 * biblioteca.c
 *
 *  Created on: 13 abr. 2022
 *      Author: Ignacio javier Medici
 */

#include "biblioteca.h"

int MenuPrincipal(int kmIngresado, float precioAerolineas, float precioLatam)
{
	int opcion;

	printf("1. Ingresar kilometros(km = %d)\n", kmIngresado);
	printf("2. Ingresar precio de vuelos (Aerolineas=%.2f , Latam=%.2f )\n", precioAerolineas, precioLatam);
	printf("3. Calcular todos los costos\n");
	printf("4. Informar resultados\n");
	printf("5. Carga forzada de datos\n");
	printf("6. Salir\n");
	printf("Ingrese una opcion\n");
	scanf("%d", &opcion);


	return opcion;
}
int utn_GetNumero(int* pResultado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos)
{
	setbuf(stdout, NULL);
	int retorno = -1;
	int bufferint;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%d", &bufferint);

			if(bufferint <= maximo && bufferint >= minimo)
			{
				*pResultado = bufferint;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}

	return retorno;
}
float utn_GetFloat(float* pResultado, char* mensaje, char* mensajeError, float minimo, float maximo, int reintentos)
{
	setbuf(stdout, NULL);
	int retorno = -1;
	float bufferFloat;

	if(pResultado != NULL && mensaje != NULL && mensajeError != NULL && minimo <= maximo && reintentos >= 0)
	{
		do
		{
			printf("%s", mensaje);
			scanf("%f", &bufferFloat);
			if(bufferFloat <= maximo && bufferFloat >= minimo)
			{
				*pResultado = bufferFloat;
				retorno = 0;
				break;
			}
			else
			{
				printf("%s", mensajeError);
				reintentos--;
			}
		}while(reintentos >= 0);
	}
	return retorno;
}
float DescuentoDebito(float precio, int descuento)
{
	float precioDescuento;
	int precioDescuentoAplicado;

	precioDescuento = (float)(precio * descuento)/ 100;

	precioDescuentoAplicado = precio - precioDescuento;

	return precioDescuentoAplicado;
}
float InteresCredito(float precio, int interes)
{
	float precioInteres;
	float precioInteresAplicado;

	precioInteres = (precio * interes)/ 100;

	precioInteresAplicado = precio + precioInteres;

	return precioInteresAplicado;
}


