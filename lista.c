#include "lista.h"
#include <stdlib.h>
#include <stdbool.h>

/* *****************************************************************
 *                   DEFINICION TIPOS DE DATOS
 * *****************************************************************/

typedef struct nodo {
	void* valor;
	struct nodo* siguiente;
} nodo_t;

struct lista {
	nodo_t* inicio;
	nodo_t* fin;
	size_t largo;
};

struct lista_iter {
	nodo_t* anterior;
	nodo_t* actual;
};

/* Función auxiliar para crear un nuevo nodo */

nodo_t* nodo_crear(void* valor){
	nodo_t* nodo = malloc(sizeof(nodo_t));
	if (!nodo)
		return NULL;
	nodo->valor = valor;
	nodo_t* siguiente = NULL;
	nodo->siguiente = siguiente;
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
	nodo_t* nodo = nodo_crear(dato);
	if (!nodo) return false;
	nodo->siguiente = lista->inicio;
	lista->inicio = nodo;
	if (lista_esta_vacia(lista)) {
		lista->fin = nodo;
	}
	lista->largo++;
	return true;
}

bool lista_insertar_ultimo(lista_t *lista, void *dato) {
	nodo_t* nodo = nodo_crear(dato);
	if (!nodo) return false;
	if (lista_esta_vacia(lista)) {
		lista->inicio = nodo;
		lista->fin = nodo;
	}
	lista->fin->siguiente = nodo;
	lista->fin = nodo;
	lista->largo++;
	return true;
}

void *lista_borrar_primero(lista_t *lista) {
	if (lista_esta_vacia(lista)) return NULL;
	nodo_t* nodo_a_borrar = lista->inicio;
	void* elemento = nodo_a_borrar->valor;
	lista->inicio = lista->inicio->siguiente;
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
	while (!lista_esta_vacia(lista)) {
		void* elemento = lista_borrar_primero(lista);
		if (destruir_dato) destruir_dato(elemento);
	}
	free(lista);
}

/* ******************************************************************
 *                     PRIMITIVAS DE ITERACIÓN
 * *****************************************************************/

lista_iter_t *lista_iter_crear(const lista_t *lista) {
	if (lista_esta_vacia(lista)) return NULL;
	lista_iter_t* iter = malloc(sizeof(lista_iter_t));
	iter->anterior = NULL;
	iter->actual = lista->inicio;
	return iter;
}
 
bool lista_iter_avanzar(lista_iter_t *iter) {
	if (lista_iter_al_final(iter)) return false;
	if (!(iter->actual)) return false;
	iter->anterior = iter->actual;
	iter->actual = iter->actual->siguiente;
	return true;
}
 
void *lista_iter_ver_actual(const lista_iter_t *iter) {
	void* valor = iter->actual->valor;
	return valor;
}

bool lista_iter_al_final(const lista_iter_t *iter) {
	if (!(iter->actual)->siguiente) return true;
	return false;
}

void lista_iter_destruir(lista_iter_t *iter) {
	free(iter);
}

/* ******************************************************************
 *              PRIMITIVAS DE LISTAS JUNTO CON ITERADOR
 * *****************************************************************/ 

bool lista_insertar(lista_t *lista, lista_iter_t *iter, void *dato) {
	// Si estoy en la primera posición del iterador
	if (!(iter->anterior) && iter->actual) {
		lista_insertar_primero(lista, dato);
		iter->actual = lista->inicio;
	}
	// Si estoy en cualquier otra posición del iterador
	else {
		nodo_t* nodo = nodo_crear(dato);
		if (!nodo) return false;
		iter->anterior->siguiente = nodo;
		nodo->siguiente = iter->actual;
		iter->actual = nodo;
	}
	lista->largo++;
	return true;
}

void *lista_borrar(lista_t *lista, lista_iter_t *iter) {
	nodo_t *nodo_a_borrar = iter->actual;
	void* dato_borrado = nodo_a_borrar->valor;
    // Si la lista está vacía
	if (lista_esta_vacia(lista)) return NULL;
	// Si estoy en la primera posición del iterador
	else if (!(iter->anterior) && iter->actual) lista_borrar_primero(lista);
	// Si estoy en la última posición del iterador
	else if (lista_iter_al_final(iter)) lista->fin = iter->anterior;
	// Si estoy en cualquier otra posición del iterador
	else iter->anterior->siguiente = nodo_a_borrar->siguiente;
	free(nodo_a_borrar);
	return dato_borrado;
}

/* ******************************************************************
 *                 PRIMITIVAS DE ITERADOR INTERNO
 * *****************************************************************/ 

void lista_iterar(lista_t *lista, bool (*visitar)(void *dato, void *extra), void *extra) {
	lista_iter_t* iter = lista_iter_crear(lista);
	void* dato = lista_iter_ver_actual(iter);
	while ((lista_iter_avanzar(iter)) && (visitar(dato, extra))) dato = lista_iter_ver_actual(iter);
	lista_iter_destruir(iter);
}