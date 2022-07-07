#ifndef MEDICO_H_
#define MEDICO_H_

typedef struct{
	int id;
	char nombreMedico[50];
	int idEspecialidad;
}Medico;

typedef struct{
	int id;
	char diagnostico[50];
}Diagnostico;

#endif /* MEDICO_H_ */
