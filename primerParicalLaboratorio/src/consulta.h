#ifndef CONSULTA_H_
#define CONSULTA_H_
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "utn_funciones.h"

//Defines
#define TAM 10
typedef struct{
	int idConsulta;
	char nombrePaciente[50];
	int idFecha;
	int idDiagnostico;
	int idMedico;
} Consulta;


int altaPaciente(Consulta* ,int,int,char*,int,int);
int printConsulta(Consulta* , int );
#endif /* CONSULTA_H_ */
