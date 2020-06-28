#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"


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
    LinkedList* nuevaLista = (LinkedList*) malloc (sizeof(LinkedList));

    if(nuevaLista != NULL){
        nuevaLista->size = 0;
        nuevaLista->pFirstNode = NULL;
    }

    return nuevaLista;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int size = -1;

    if(this != NULL){
        size = this->size;
    }

    return size;
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
    Node* puntero = NULL;
    int size = ll_len(this);

    if(this != NULL && nodeIndex > -1 && nodeIndex < size){
        puntero = this->pFirstNode;

        for(int i=0; i<nodeIndex; i++){
            puntero = puntero->pNextNode;
        }

        //Otra manera de hacerlo
        /*if(nodeIndex > 0){
            while(puntero->pNextNode != NULL){
            puntero = puntero->pNextNode;
            }
        }*/
    }

    return puntero;
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
    int size = ll_len(this);
    Node* nodo = NULL;
    Node* anterior = NULL;

    if(this != NULL && nodeIndex > -1 && nodeIndex <= size){
        nodo = (Node*) malloc(sizeof(Node));
        if(nodo != NULL){
            nodo->pElement = pElement;
            nodo->pNextNode = NULL;

            if(nodeIndex == 0){
                nodo->pNextNode = this->pFirstNode;
                this->pFirstNode= nodo;

            }else{
                anterior = getNode(this, nodeIndex - 1);
                nodo->pNextNode = anterior->pNextNode;
                anterior->pNextNode = nodo;

            }
            this->size++;
        }
        returnAux = 0;
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

    int size = ll_len(this);

    if(this != NULL){
        addNode(this,size, pElement);
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
    Node* nodo = NULL;
    int size = ll_len(this);

    if(this != NULL && index > -1 && index < size){
        nodo = getNode(this, index);
        if(nodo != NULL){
            returnAux = nodo->pElement;
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
    int size = ll_len(this);
    Node* nodo = NULL;

    if(this != NULL && index > -1 && index < size){
        nodo = getNode(this, index);
        nodo->pElement = pElement;
        returnAux = 0;
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
    int size = ll_len(this);
    Node* nodo = NULL;
    Node* nodoAnterior = NULL;

    if(this != NULL && index > -1 && index < size){

        nodo = getNode(this, index);
        if(nodo != NULL){
            if(index == 0){
                this->pFirstNode = nodo->pNextNode;
                free(nodo);
                returnAux = 0;
                this->size--;
            }else{
                nodoAnterior = getNode(this, index -1);
                if(nodoAnterior !=NULL){
                    nodoAnterior->pNextNode = nodo->pNextNode;
                    free(nodo);
                    returnAux = 0;
                    this->size--;
                }
            }
        }
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


    if(this != NULL){
        while(ll_len(this)!= 0){
        ll_remove(this, 0);
        }
        returnAux = 0;
    }

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

    if(this!=NULL){
        if(!ll_clear(this)){
            free(this);
            returnAux = 0;
        }
    }

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
    int size = ll_len(this);
    Node* nodo = NULL;

    if(this != NULL){
        for(int i=0; i<size;i++){
            nodo = getNode(this, i);
            if(nodo != NULL && nodo->pElement == pElement){
                returnAux = i;
                break;
            }
        }
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

    if(this!=NULL){
        if(ll_len(this) > 0 ){
            returnAux = 0;
        }else{
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
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    int size = ll_len(this);

    if(this != NULL && index > -1 && index <= size){
        addNode(this, index, pElement);
        returnAux = 0;
    }

    return returnAux;
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
    int size = ll_len(this);

    if(this != NULL && index > -1 && index < size){

        returnAux = ll_get(this, index);
        if(ll_remove(this, index) == 1){
            returnAux = NULL;
        }
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
    int size = ll_len(this);
    Node* nodo = NULL;

    if(this!=NULL){
        returnAux = 0;
        for(int i=0; i<size;i++){
            nodo = getNode(this, i);
            if(nodo->pElement == pElement){
                returnAux = 1;
                break;
            }
        }
    }

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
    int size1 = ll_len(this);
    int size2 = ll_len(this2);
    int contador = 0;
    Node* nodo1 = NULL;
    Node* nodo2 = NULL;

    if(this != NULL && this2 != NULL){
        returnAux = 0;
        //si el tamaño de la lista dos es mayor al tamaño de la lista 1, no hay posibilidad que esten todos los
        //elementos de la lista 2 en la lista uno
        if(size2 <= size1){
            for(int ilista2 = 0; ilista2 < size2; ilista2++){
                nodo2 = getNode(this2, ilista2);
                for(int ilista1 = 0; ilista1 < size1; ilista1++){
                    nodo1= getNode(this, ilista1);
                    if(nodo1->pElement == nodo2->pElement){
                        contador++;
                        break;
                    }
                }
            }
        }
        if(contador == size2){
            returnAux=1;
        }

    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* cloneArray = NULL;
    int size = ll_len(this);
    void* element;

    if(this != NULL && from >= 0 && to >= from && to <= size){
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL){
            for(int i = from; i<to; i++){
                element = ll_get(this, i);
                ll_add(cloneArray, element);
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
    LinkedList* cloneArray = NULL;
    int size = ll_len(this);

    if(this != NULL){
        cloneArray = ll_newLinkedList();
        if(cloneArray != NULL){
            for(int i=0;i<size;i++){
                ll_add(cloneArray, ll_get(this, i));
            }
        }
    }

    return cloneArray;
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
    int returnAux = -1;
    void* elementA;
    void* elementB;
    int size = ll_len(this);

    if(this != NULL && pFunc != NULL && (order == 0 || order == 1)){
        for(int A = 0; A < size - 1; A++){
            for(int B = A + 1; B < size; B++){
                elementA = ll_get(this, A);
                elementB = ll_get(this,B);
                if(order == 1){
                    if(pFunc(elementA, elementB) == 1){
                        ll_set(this, A, elementB);
                        ll_set(this, B, elementA);
                    }
                }else{
                    if(pFunc(elementA, elementB) == -1){
                        ll_set(this, A, elementB);
                        ll_set(this, B, elementA);
                    }
                }
            }
        }
        returnAux = 0;
    }

    return returnAux;

}

