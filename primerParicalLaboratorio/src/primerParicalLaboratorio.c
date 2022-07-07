#include "consulta.h"

int main(void)
{
	setbuf(stdout,NULL);
	int opciones;
//	int opcionesInforme;

	Consulta* listaPacientes[TAM];
	Medicos* listaMedicos[TAM_M];

	do{
		puts("1.ALTA CONSULTA");
		puts("2.MODIFICAR CONSULTA");
		puts("3.CANCELAR CONSULTA");
		puts("4.DIAGNOSTICAR");
		puts("5.LISTAR");
		puts("6.SALIR");

		opciones = PedirOpciones("|->Ingresar una opcion:", "Ups! Opcion incorrecta!!");
		switch (opciones) {
			case 1:
				altaPaciente(listaPacientes,TAM,listaMedicos,TAM_M);
				break;
			case 2:

				break;
			case 3:

				break;
			case 4:

				break;
			case 5:

				break;
			case 6:
				puts("Saliendo... Gracias por usar mi app!!");
				break;
			default:
				puts("Ups! Opcion incorrecta!!");
				break;
		}
	}while(opciones != 6);


	return EXIT_SUCCESS;
}
