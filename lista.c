#include "lista.h"
#include <stdlib.h>

typedef struct nodo {
	void* valor;
	struct nodo* ref;
} nodo_t;

/* Definición del struct lista */

struct lista {
	nodo_t* inicio;
	nodo_t* fin;
	size_t largo;
}

/* Definición del struct lista_iter */

struct lista_iter {
	nodo_t* anterior;
	nodo_t* actual;
}

/* Función auxiliar para crear un nuevo nodo */

nodo_t* nodo_crear(void* valor){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (!nodo)
		return NULL;
	nodo->valor = valor;
	nodo_t* ref = NULL;
	nodo->ref = ref;
	return nodo;
}

/* *****************************************************************
 *                    PRIMITIVAS DE LA LISTA
 * *****************************************************************/

lista_t *lista_crear(void) {
	lista_t* lista;
	lista = malloc(sizeof(lista_t));
	if (!lista) return NULL;
	lista->inicio = NULL;
	lista->fin = NULL;
	lista->largo = 0;	
	return lista;
}

bool lista_esta_vacia(const lista_t *lista) {
	return (lista->largo == 0);
}

bool lista_insertar_primero(lista_t *lista, void *dato) {
	nodo = nodo_crear(dato);
	if (!nodo) return false;
	nodo->ref = lista->inicio;
	lista->inicio = nodo;
	if (lista_esta_vacia(lista)) {
		lista->fin = nodo;
	}
	lista->largo++;
	return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato) {
	nodo = nodo_crear(dato);
	if (!nodo) return false;
	if (lista_esta_vacia(lista)) {
		lista->inicio = nodo;
		lista->fin = nodo;
	}
	lista->fin->ref = nodo;
	lista->fin = nodo;
	lista->largo--;
	return true;
}

void *lista_borrar_primero(lista_t *lista) {
	if (lista_esta_vacia(lista)) return NULL;
	nodo_t* nodo_a_borrar = lista->inicio;
	void* elemento = nodo_a_borrar->valor;
	lista->inicio = lista->inicio->ref;
	free(nodo_a_borrar);
	lista->largo--;
	if (lista_esta_vacia(lista)) lista->fin = NULL;
	return elemento;
}

void *lista_ver_primero(const lista_t *lista) {
	if (!lista_esta_vacia(lista)) return lista->inicio->valor;
	return NULL;
}

size_t lista_largo(const lista_t *lista) {
	return lista->largo;
}

void lista_destruir(lista_t *lista, void destruir_dato(void *)) {
	void* elemento;
	while (!lista_esta_vacia(lista)) {
		elemento = lista_borrar_primero(lista);
		if (destruir_dato) destruir_dato(elemento);
	}
	free(lista);
}

/* ******************************************************************
 *                     PRIMITIVAS DE ITERACIÓN
 * *****************************************************************/

lista_iter_t *lista_iter_crear(const lista_t *lista) {
	
}
 
bool lista_iter_avanzar(lista_iter_t *iter) {
	
 }
 
void *lista_iter_ver_actual(const lista_iter_t *iter) {
	
}

bool lista_iter_al_final(const lista_iter_t *iter) {
	
}

void lista_iter_destruir(lista_iter_t *iter) {
	
}

/* ******************************************************************
 *              PRIMITIVAS DE LISTAS JUNTO CON ITERADOR
 * *****************************************************************/ 

bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato) {
	
}

void *lista_borrar(lista_t *lista, lista_iter_t *iter) {
	
}

/* ******************************************************************
 *                 PRIMITIVAS DE ITERADOR INTERNO
 * *****************************************************************/ 

void lista_iterar(lista_t *lista, bool (*visitar)(void *dato, void *extra), void *extra) {
	
}