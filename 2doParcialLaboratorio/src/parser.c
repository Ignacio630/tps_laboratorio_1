#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "generico.h"
#include "parser.h"

/** \brief Parsea los datos los datos de genericos el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param gArrayGenerico LinkedList*
 * \return int
 *
 */
int parser_GenericoFromText(FILE* pFile , LinkedList* gArrayGenerico)
{
	int returnAux = -1;
	char bufferId[1000];
	char bufferNombre[500];
	char bufferPrecio[10000];
	eGenerico* auxGenerico;

	if(pFile != NULL && gArrayGenerico != NULL)
	{
		printf("adfs");
		fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferPrecio);
		while(!feof(pFile))
		{
			printf("adfs");
			fscanf(pFile,"%[^,],%[^,],%[^\n]\n",bufferId, bufferNombre, bufferPrecio);
			auxGenerico = eGenerico_newParametros(bufferId, bufferNombre, bufferPrecio);
			if(auxGenerico != NULL)
			{
				ll_add(gArrayGenerico, auxGenerico);
			}
		}
		returnAux = 0;
	}
	return returnAux;
}
