#include "generico.h"
#include "utn_funciones.h"
eGenerico* eGenerico_new()
{
	eGenerico* auxGenerico;
	auxGenerico = (eGenerico*)malloc(sizeof(eGenerico));
	return auxGenerico;
}
eGenerico* eGenerico_newParametros(char* idStr,char* nombreStr, char* precioStr)
{
	eGenerico* auxGenerico;
	auxGenerico = NULL;
	auxGenerico = eGenerico_new();

	if(auxGenerico != NULL && idStr != NULL && nombreStr != NULL && precioStr != NULL)
	{
		ValidarSetters(auxGenerico, idStr, nombreStr, precioStr);
	}
	return auxGenerico;
}
//Borrar
void eGenerico_delete(eGenerico* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
//Validacion
int ValidarSetters(eGenerico* this,char* idStr,char* nombreStr, char* precioStr)
{
	int returnAux;
	returnAux = 0;

	if(!eGenerico_setId(this, atoi(idStr)) &&
	   !eGenerico_setNombre(this, nombreStr) &&
	   !eGenerico_setPrecio(this, atof(precioStr)))
	{
		eGenerico_delete(this);
		this = NULL;
		returnAux = -1;
	}
	return returnAux;
}
//Setters
//Id
int eGenerico_setId(eGenerico* this,int id)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && id > 0)
	{
		this->id = id;
		returnAux = 0;
	}

	return returnAux;
}
//Name
int eGenerico_setNombre(eGenerico* this,char* name)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && name != NULL)
	{
		strcpy(this->name, name);
		returnAux = 0;
	}

	return returnAux;
}
//price
int eGenerico_setPrecio(eGenerico* this,float price)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && price >= 0)
	{
		this->price = price;
		returnAux = 0;
	}

	return returnAux;
}
//Getters
//Id
int eGenerico_getId(eGenerico* this,int* id)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && id != NULL)
	{
		*id = this->id;
		returnAux = 0;
	}

	return returnAux;
}
//Name
int eGenerico_getNombre(eGenerico* this,char* name)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && name != NULL)
	{
		strcpy(name,this->name);
		returnAux = 0;
	}

	return returnAux;
}
//Price
int eGenerico_getPrecio(eGenerico* this,float* price)
{
	int returnAux;
	returnAux = -1;

	if(this != NULL && price != NULL)
	{
		*price = this->price;
		returnAux = 0;
	}

	return returnAux;
}
//Print
void eGenerico_printOne(eGenerico* this)
{
	int id;
	char nombre[50];
	float precio;

	eGenerico_getId(this, &id);
	eGenerico_getNombre(this, nombre);
	eGenerico_getPrecio(this, &precio);

	if(this != NULL)
	{
		printf("|%6d|%15s|%10.2f|\n", id, nombre, precio);
	}
}
//Sort
int eGenerico_CompareByName(void* aux1, void* aux2)
{
	eGenerico* auxGenerico1;
	eGenerico* auxGenerico2;

	auxGenerico1 = (eGenerico*)aux1;
	auxGenerico2 = (eGenerico*)aux2;

	return strcmp(auxGenerico1->name,auxGenerico2->name);
}
int eGenerico_CompareById(void* g1, void* g2)
{
	int cmp;
	int id1;
	int id2;
	eGenerico* auxGenerico1;
	eGenerico* auxGenerico2;
	auxGenerico1 = (eGenerico*)g1;
	auxGenerico2 = (eGenerico*)g2;

	eGenerico_getId(auxGenerico1, &id1);
	eGenerico_getId(auxGenerico2, &id2);

	cmp = 0;

	if(auxGenerico1 != NULL && auxGenerico2 != NULL)
	{
		if(id1 > id2)
		{
			cmp = 1;
		}
		else
		{
			if(id1 < id2)
			{
				cmp = -1;
			}
		}
	}
	return cmp;
}
int eGenerico_CompareByPrice(void* auxPrice1, void* auxPrice2)
{
	int cmp;
	int price1;
	int price2;
	eGenerico* auxGenerico1;
	eGenerico* auxGenerico2;
	auxGenerico1 = (eGenerico*)auxPrice1;
	auxGenerico2 = (eGenerico*)auxPrice2;

	eGenerico_getId(auxGenerico1, &price1);
	eGenerico_getId(auxGenerico2, &price2);

	cmp = 0;

	if(auxGenerico1 != NULL && auxGenerico2 != NULL)
	{
		if(price1 > price2)
		{
			cmp = 1;
		}
		else
		{
			if(price1 < price2)
			{
				cmp = -1;
			}
		}
	}
	return cmp;
}
//Find
int findGenericoById(LinkedList* gArrayGenerico,int id)
{
	int returnAux;
	int i;
	int len;
	int auxId;

	eGenerico* auxGenerico;
	returnAux = -1;
	len = ll_len(gArrayGenerico);
	if(auxGenerico !=NULL && len > 0)
	{
		for(i=0;i<len;i++)
		{
			auxGenerico = ll_get(gArrayGenerico, i);
			eGenerico_getId(auxGenerico, &auxId);
			if(auxId == id)
			{
				returnAux = i;
				break;
			}
		}
	}

	return returnAux;
}

