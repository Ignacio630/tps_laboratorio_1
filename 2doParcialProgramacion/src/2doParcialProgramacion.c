/*
 ============================================================================
 Name        : Ignacio javier Medici
 Division	 : C


 1. (4 puntos) Crear un array de enteros en memoria dinámica y una función que reciba dicho array.
 La función deberá ajustar el tamaño del array a la cantidad de números pares que haya en el mismo quedándose únicamente con los elementos que cumplan con dicha característica.
 2. (4 Puntos) Elija 4 de los siguientes conceptos (mas el obligatorio) y
 realice un párrafo en donde se pueda observar la relación de los conceptos (No realizar definiciones del estilo copy-paste)
 3.  (2 Puntos) Crear una función que guarde en un archivo binario el contenido del array generado en el punto 1. Leerlo en otra función y mostrarlo.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define T 4
int* arrayEnteroPares(int*);

int main(void)
{
	setbuf(stdout,NULL);
	//PUNTO 1°

	int* aEnteros;

	arrayEnteroPares(aEnteros);

	//Punto 2°
	/* Elegi Puntero, Direccion de memoria, puntero a funcion, segmento de codigo, memoria dinamica
	 *
	 *	Elegi estas porque su relacion se basa en que los punteros a funcion es una variable que guarda la direccion de memoria de una funcion, y esta misma llamarla mediante
	 *	punteros para asi poder reutilizar dicha funcion ya que gracias a estos permiten realizar varias funciones con los mismos parametros que se pasan por punteros en la misma funcion,
	 *	estos mismos tienen su propia direccion de memoria que toma el control haciendo esta el primer segmento de codigo para poder comenzar el codigo de dicha funcion
	 *
	 * */
	//Punto 3°


	free(aEnteros);
	return EXIT_SUCCESS;
}
int* arrayEnteroPares(int* aEnteros)
{
	int* auxArray;
	auxArray = realloc(aEnteros, sizeof(int)*sizeof(aEnteros)%2);

	return auxArray;
}
