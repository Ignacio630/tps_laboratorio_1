#include "consulta.h"
static int idIncremental(void);
static int idIncremental(void){
	int idIncremental = 1000;
	return idIncremental++;
}


int altaPaciente(Consulta* listaConsulta,int tam, int id, char* nombre,int idMedico, int idDiag){
	int rtn;
	rtn = -1;

	if(listaConsulta != NULL && tam >= 0){
		for(int i=0;i<0;i++){
			id = idIncremental();
			PedirCadena(nombre, "Ingrese el nombre del paciente: ");
			strncpy(nombre, listaConsulta[i].nombrePaciente,50);
		}
		rtn = 0;
	}

	return rtn;
}

int printConsulta(Consulta* listaConsulta, int tam){
	int rtn;
	rtn = -1;


	if(listaConsulta != NULL && tam >= 0){
		for(int i=0;i<tam;i++){
			printf("Id consulta: %d\nNombre Paciente: %s",listaConsulta[i].idConsulta,listaConsulta[i].nombrePaciente);
		}
	}

	return rtn;
}
