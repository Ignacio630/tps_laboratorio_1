#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this = NULL;
    this = (LinkedList*)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
    	this->size = 0;
    	this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
    	returnAux = this->size;
    }
    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pNode) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
	Node* pNode = NULL;
	int len;
	len = ll_len(this);

	if(this != NULL && nodeIndex >= 0 && nodeIndex < len)
	{
		pNode = this->pFirstNode;
		for(int i=0;i<nodeIndex;i++)
		{
			pNode = pNode->pNextNode;
		}
	}

    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    int len;
    len = ll_len(this);

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= len)
    {
    	Node* pNode = (Node*)malloc(sizeof(Node));
    	if(pNode != NULL)
    	{
    		pNode->pElement = pElement;
    		if(nodeIndex == 0)
    		{
    			pNode->pNextNode = this->pFirstNode;
    			this->pFirstNode = pNode;
    		}
    		else
    		{
    			Node* auxNode = getNode(this, nodeIndex-1);
    			pNode->pNextNode = auxNode->pNextNode;
    			auxNode->pNextNode = pNode;
    		}
    		this->size++;
    		returnAux = 0;
    	}
    }

    return returnAux;
}
/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}

/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    len = ll_len(this);

    if(this != NULL)
    {
    	addNode(this, len, pElement);
    	returnAux = 0;
    }
    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* auxNode;
    int len;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	auxNode = getNode(this, index);
    	if(auxNode != NULL)
    	{
    		returnAux = auxNode->pElement;
    	}
    }
    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* auxNode;
    int len;
    len = ll_len(this);

    if(this != NULL && index >= 0 && index < len)
    {
    	auxNode = getNode(this, index);
		if(auxNode != NULL)
		{
			auxNode->pElement = pElement;
			returnAux = 0;
		}
    }

    return returnAux;
}

/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    int len;

    len = ll_len(this);
    Node* pNode;
    Node* auxNode;


    if(this != NULL && index >= 0 && index < len)
    {
<<<<<<< HEAD
    	auxNode = getNode(this, index);
=======
    	Node* auxNode = getNode(this, index);
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    	if(auxNode != NULL)
    	{
    		if(index == 0)
    		{
<<<<<<< HEAD
    			this->pFirstNode = auxNode->pNextNode;// hago que el primer nodo se iguale al siguiente nodo
    		}
    		else
    		{
    			pNode = getNode(this, index-1);	//obtengo un nodo con en la posicion anterior al que voy a eliminar
    			pNode->pNextNode = auxNode->pNextNode; //e igualo ese nodo al siguiente del que voy a borar
=======
    			this->pFirstNode = auxNode->pNextNode;
    		}
    		else
    		{
    			Node* pNode = getNode(this, index-1);
    			pNode->pNextNode = auxNode->pNextNode;
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    		}
    	}
    	free(auxNode);
    	this->size--;
    	returnAux = 0;
    }

    return returnAux;
}
/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    int len;
    len = ll_len(this);
<<<<<<< HEAD

    if(this != NULL)
    {
    	for(int i=0;i<len;i++)
		{
			returnAux = ll_remove(this, i);
		}
    }

=======
    if(this != NULL)
    {
    	for(int i = 0;i<len;i++)
    	{
			returnAux = ll_remove(this, i);
    	}

    }
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106

    return returnAux;
}

/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
<<<<<<< HEAD
    int removeThis;

    removeThis = ll_clear(this);
    if(this != NULL)
    {
    	if(removeThis == 0)
=======
    int auxClear;
    auxClear = ll_clear(this);
    if(this != NULL)
    {
    	if(auxClear == 0)
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    	{
    		free(this);
    		returnAux = 0;
    	}
    }
<<<<<<< HEAD

=======
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    int len;
    len = ll_len(this);

<<<<<<< HEAD
    if(this != NULL)
    {
    	for(int i=0;i<len;i++)
    	{
    		if(ll_get(this, i)== pElement)
    		{
    			returnAux = i;
    			break;
    		}
    	}
=======
    if(this != NULL){
		for(int i=0;i<len;i++){
			if(pElement == ll_get(this, i)){
				returnAux = i;
				break;
			}
		}
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    int len;
<<<<<<< HEAD
    len = ll_len(this);
=======

    len = ll_len(this);
    if(this != NULL)
    {
		if(len == 0)
		{
			returnAux = 1;
		}
		else
		{
			if(len > 0)
			{
				returnAux = 0;
			}
		}
    }
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106

    if(this != NULL)
    {
    	returnAux = 0;
    	if(len == 0)
    	{
    		returnAux = 1;
    	}
    }
    return returnAux;
}

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
<<<<<<< HEAD
    return addNode(this, index, pElement);
=======
	return addNode(this, index, pElement);
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
}

/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    int len;
    len = ll_len(this);
<<<<<<< HEAD

    if(this != NULL && index >= 0 && index < len)
    {
=======
    ll_indexOf(this, returnAux);
    if(this != NULL && index < len && index >= 0){
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    	returnAux = ll_get(this, index);
    	ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;

    if(this != NULL)
    {
    	returnAux = 0;
<<<<<<< HEAD
    	if(ll_indexOf(this, pElement)!= -1)
=======
    	if(ll_indexOf(this, pElement) != -1)
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    	{
    		returnAux = 1;
    	}
    }
<<<<<<< HEAD

=======
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int len;
<<<<<<< HEAD
    void* auxElemento;
    len = ll_len(this2);
=======

    len = ll_len(this2);
    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(int i=0;i<len;i++)
    	{
    		if(ll_contains(this, ll_get(this2, i)) == 0)
			{
				returnAux = 0;
			}
    	}
    }
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106

    if(this != NULL && this2 != NULL)
    {
    	returnAux = 1;
    	for(int i=0;i<len;i++)
    	{
    		auxElemento = ll_get(this2, i);
    		if(!ll_contains(this, auxElemento))
    		{
    			returnAux = 0;
    			break;
    		}
    	}
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna    (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         	 	  (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int len;
<<<<<<< HEAD
    int i;
    len = ll_len(this);

    if(this != NULL && from >= 0 && from < to && to <= len)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for(i=from;	i < to;i++)
    		{
    			ll_add(cloneArray, ll_get(this, i));
    		}
    	}
    }
=======
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106

    len = ll_len(this);
    if(this != NULL && from < to && from >= 0 && to <= len)
    {
    	cloneArray = ll_newLinkedList();
    	if(cloneArray != NULL)
    	{
    		for(int i=from;i<to;i++)
    		{
    			ll_add(cloneArray, ll_get(this, i));
    		}
    	}
    }
    return cloneArray;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    return ll_subList(this, 0, ll_len(this));
}
/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                        ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int len;
<<<<<<< HEAD
    void* auxFunc;
    int aux;
    len = ll_len(this);

    if(this != NULL && pFunc != NULL && order <= 1 && order >= 0)
    {
    	for(int i=0;i<len-1;i++)
    	{
    		for(int j=i+1;j<len;j++)
    		{
    			aux = pFunc(ll_get(this, i),ll_get(this, j));
    			if((aux > 0 && order) || (aux < 0 && !order))
=======
    void* auxFunc = NULL;
    int resultFunc;
    len = ll_len(this);

    if(this != NULL && pFunc != NULL && order >= 0 && order <= 1)
    {
    	for(int i = 0;i<len-1;i++)
    	{
    		for(int j=i+1;j<len;j++)
    		{
    			resultFunc = pFunc(ll_get(this, i),ll_get(this, j));
    			if((resultFunc > 0 && order) || (resultFunc < 0 && !order))
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    			{
    				auxFunc = ll_get(this, i);
    				ll_set(this, i, ll_get(this, j));
    				ll_set(this, j, auxFunc);
    			}
    		}
    	}
<<<<<<< HEAD
		returnAux = 0;
=======
    	returnAux = 0;
>>>>>>> 8e6b6f7ab600ffd6131d0b3b56e472c330785106
    }

    return returnAux;

}
