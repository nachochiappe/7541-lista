#include "lista.h"
#include <stdlib.h>

typedef struct nodo {
	void* valor;
	struct nodo* ref;
} nodo_t;

/* Definición del struct lista. */

struct lista {
	nodo_t* primero;
	nodo_t* ultimo;
	int tamano;
};

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
	
}

bool lista_esta_vacia(const lista_t *lista) {
	
}

bool lista_insertar_primero(lista_t *lista, void *dato) {
	
}

bool lista_insertar_ultimo(lista_t *lista, void *dato) {
	
}

void *lista_borrar_primero(lista_t *lista) {
	
}

void *lista_ver_primero(const lista_t *lista) {
	
}

size_t lista_largo(const lista_t *lista) {
	
}

void lista_destruir(lista_t *lista, void destruir_dato(void *)) {
	
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