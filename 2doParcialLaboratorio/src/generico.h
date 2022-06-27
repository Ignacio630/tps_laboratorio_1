#ifndef GENERICO_H_
#define GENERICO_H_
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "LinkedList.h"
#include "utn_funciones.h"

typedef struct{
	int id;
	char name[50];
	float price;
} eGenerico;

eGenerico* eGenerico_new();
eGenerico* eGenerico_newParametros(char* idStr,char* nombreStr, char* precioStr);
//Borrar
void eGenerico_delete(eGenerico* this);
//Validacion
int ValidarSetters(eGenerico* this,char* idStr,char* nombreStr, char* precioStr);
//Setters
//Id
int eGenerico_setId(eGenerico* ,int);
//Name
int eGenerico_setNombre(eGenerico* ,char*);
//price
int eGenerico_setPrecio(eGenerico* ,float);
//Getters
//Id
int eGenerico_getId(eGenerico* ,int*);
//Name
int eGenerico_getNombre(eGenerico* ,char*);
//Price
int eGenerico_getPrecio(eGenerico* ,float*);
//Print
void eGenerico_printOne(eGenerico* );
//Sort
int eGenerico_CompareByName(void*, void*);
int eGenerico_CompareById(void*, void*);
int eGenerico_CompareByPrice(void* , void* );
//Find
int findGenericoById(LinkedList*,int);



#endif /* GENERICO_H_ */
