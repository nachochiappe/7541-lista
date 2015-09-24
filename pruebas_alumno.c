#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void imprimir_iter_externo(lista_t *lista) {
	lista_iter_t *iter = lista_iter_crear(lista);
	int num_items = 0;

	while (!lista_iter_al_final(iter)) {
		char *elemento = lista_iter_ver_actual(iter);
		printf("%d. %s\n", ++num_items, elemento);
		lista_iter_avanzar(iter);
	}
	printf("Tengo que comprar %d ítems\n", num_items);
	lista_iter_destruir(iter);
}

bool imprimir_un_item(void *elemento, void *extra) {
	// Sabemos que ‘extra’ es un entero, por tanto le podemos hacer un cast.
	int *contador = extra;
	char *item = elemento;
	printf("%d. %s\n", ++(*contador), item);

	return true; // seguir iterando
}

void imprimir_iter_interno(lista_t *lista) {
	int num_items = 0;
	lista_iterar(lista, imprimir_un_item, &num_items);
	printf("Tengo que comprar %d ítems\n", num_items);
}

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_lista_primitivas() {
	printf("\nINICIO DE PRUEBAS PRIMITIVAS DE LISTA\n");
	
	// Declaro variables a utilizar
	int a = 1;
		
	// Crear lista
	lista_t *lista = lista_crear();
	print_test("Prueba crear lista", lista != NULL);
	
	// Verificar que esté vacía
	print_test("Prueba lista está vacía", lista_esta_vacia(lista));
	
	// Insertar un nodo al principio
	print_test("Prueba insertar primero", lista_insertar_primero(lista, &a));
	
	// Verificar que no esté vacía
	print_test("Prueba lista NO está vacía", !lista_esta_vacia(lista));
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 1", lista_largo(lista) == 1);
	
	// Ver primero
	print_test("Prueba ver primero de lista = &a", lista_ver_primero(lista) == &a);
	
	// Borrar el nodo
	print_test("Prueba borrar primero de lista = &a", lista_borrar_primero(lista) == &a);
	
	// Verificar que esté vacía luego de borrar el nodo
	print_test("Prueba lista está vacía luego de borrar nodo", lista_esta_vacia(lista));
	
	// Obtener largo de la lista luego de borrar el nodo
	print_test("Prueba largo de lista = 0", lista_largo(lista) == 0);
	
	// Insertar un nodo al final
	print_test("Prueba insertar ultimo", lista_insertar_ultimo(lista, &a));
	
	// Verificar que no esté vacía
	print_test("Prueba lista NO está vacía", !lista_esta_vacia(lista));
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 1", lista_largo(lista) == 1);
	
	// Ver primero
	print_test("Prueba ver primero de lista = &a", lista_ver_primero(lista) == &a);
	
	// Borrar el nodo
	print_test("Prueba borrar primero de lista = &a", lista_borrar_primero(lista) == &a);
	
	// Verificar que esté vacía luego de borrar el nodo
	print_test("Prueba lista está vacía luego de borrar nodo", lista_esta_vacia(lista));
	
	// Obtener largo de la lista luego de borrar el nodo
	print_test("Prueba largo de lista = 0", lista_largo(lista) == 0);
	
	// Insertar nodo NULL
	print_test("Prueba insertar NULL", lista_insertar_primero(lista, NULL));
	
	// Verificar que no esté vacía
	print_test("Prueba lista NO está vacía", !lista_esta_vacia(lista));
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 1", lista_largo(lista) == 1);
	
	// Ver primero
	print_test("Prueba ver primero de lista = NULL", lista_ver_primero(lista) == NULL);
	
	// Borrar el nodo
	print_test("Prueba borrar primero de lista = NULL", lista_borrar_primero(lista) == NULL);
	
	// Verificar que esté vacía luego de borrar el nodo
	print_test("Prueba lista está vacía luego de borrar nodo", lista_esta_vacia(lista));
	
	// Obtener largo de la lista luego de borrar el nodo
	print_test("Prueba largo de lista = 0", lista_largo(lista) == 0);
	
	// Destruir lista
	lista_destruir(lista, NULL);
}

void pruebas_lista_de_listas() {
	printf("\nINICIO DE PRUEBAS LISTA DE LISTAS\n");
	
	// Crear listas
	lista_t* lista = lista_crear();
	lista_t* lista1 = lista_crear();
	lista_t* lista2 = lista_crear();
	lista_t* lista3 = lista_crear();
	lista_t* lista4 = lista_crear();
	lista_t* lista5 = lista_crear();
	
	// Insertar un nodo al principio
	print_test("Prueba insertar lista1 ultimo", lista_insertar_ultimo(lista, lista1));
	print_test("Prueba insertar lista2 ultimo", lista_insertar_ultimo(lista, lista2));
	print_test("Prueba insertar lista3 ultimo", lista_insertar_ultimo(lista, lista3));
	print_test("Prueba insertar lista4 ultimo", lista_insertar_ultimo(lista, lista4));
	print_test("Prueba insertar lista5 ultimo", lista_insertar_ultimo(lista, lista5));
	
	// Verificar que no esté vacía
	print_test("Prueba lista NO está vacía", !lista_esta_vacia(lista));
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 5", lista_largo(lista) == 5);
	
	// Ver primero
	print_test("Prueba ver primero de lista = lista1", lista_ver_primero(lista) == lista1);
	
	// Destruir lista
	lista_destruir(lista, free);
}


void pruebas_lista_primitivas_volumen() {	
	printf("\nINICIO DE PRUEBAS DE VOLUMEN\n");
	
	// Declaro variables a utilizar
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	
	// Crear lista
	lista_t *lista = lista_crear();
	print_test("Prueba crear lista", lista != NULL);
	
	// Insertar 2500 nodos al principio (5 nodos 500 veces = 2500)
	for (int i = 1; i <= 500; i++) {
		lista_insertar_primero(lista, &a);
		lista_insertar_primero(lista, &b);
		lista_insertar_primero(lista, &c);
		lista_insertar_primero(lista, &d);
		lista_insertar_primero(lista, &e);
	}
	
	// Verificar que no esté vacía
	print_test("Prueba lista NO está vacía", !lista_esta_vacia(lista));
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 2500", lista_largo(lista) == 2500);
	
	// Ver primero
	print_test("Prueba ver primero de lista = &e", lista_ver_primero(lista) == &e);
	
	// Insertar 2500 nodos al final (5 nodos 500 veces = 2500)
	for (int i = 1; i <= 500; i++) {
		lista_insertar_ultimo(lista, &a);
		lista_insertar_ultimo(lista, &b);
		lista_insertar_ultimo(lista, &c);
		lista_insertar_ultimo(lista, &d);
		lista_insertar_ultimo(lista, &e);
	}
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 5000", lista_largo(lista) == 5000);
	
	// Ver primero
	print_test("Prueba ver primero de lista = &e", lista_ver_primero(lista) == &e);
	
	// Destruir lista
	lista_destruir(lista, NULL);
}

void pruebas_lista_primitivas_con_iter() {
	printf("\nINICIO DE PRUEBAS PRIMITIVAS DE LISTAS JUNTO CON ITERADOR\n");
	
	// Declaro variables a utilizar
	int a = 1;
	
	lista_t *lista = lista_crear();
	print_test("Prueba crear lista", lista != NULL);
	
	lista_iter_t *iter = lista_iter_crear(lista);
	print_test("Prueba crear iterador", iter != NULL);
	
	// Borrar lista vacía
	print_test("Prueba borrar lista vacía", !lista_borrar(lista, iter));
	
	// Insertar en lista vacía
	print_test("Prueba insertar elemento", lista_insertar(lista, iter, &a));
	print_test("Prueba lista NO está vacía", !lista_esta_vacia(lista));
	print_test("Prueba borrar igual a &a", lista_borrar(lista, iter) == &a);
	print_test("Prueba lista está vacía", lista_esta_vacia(lista));
	
	// Destruir iterador y lista
	lista_iter_destruir(iter);
	lista_destruir(lista, NULL);
}

void pruebas_lista_iter_externo() {
	printf("\nINICIO DE PRUEBAS ITERADOR EXTERNO\n");
	
	// Pruebas del alumno
	
	int a = 1, b = 2, c = 3;
	
	lista_t *lista = lista_crear();
	lista_iter_t *iter = lista_iter_crear(lista);
	print_test("Prueba avanzar iterador en lista vacía", !lista_iter_avanzar(iter));
	print_test("Prueba ver actual iterador en lista vacía", !lista_iter_ver_actual(iter));
	print_test("Prueba iterador al final en lista vacía", lista_iter_al_final(iter));
	lista_insertar(lista, iter, &a);
	lista_insertar(lista, iter, &b);
	print_test("Prueba ver primero luego de insertar con iterador en la primera posicion", lista_ver_primero(lista) == &b);
	print_test("Prueba ver actual iterador", lista_iter_ver_actual(iter) == &b);
	print_test("Prueba avanzar iterador", lista_iter_avanzar(iter));
	lista_insertar(lista, iter, &c);
	print_test("Prueba insertar en el medio en lista con elementos", lista_ver_primero(lista) == &b);
	print_test("Prueba ver actual iterador", lista_iter_ver_actual(iter) == &c);
	print_test("Prueba avanzar iterador", lista_iter_avanzar(iter));
	print_test("Prueba avanzar iterador", lista_iter_avanzar(iter));
	print_test("Prueba iterador al final luego de avanzar iterador", lista_iter_al_final(iter));
	print_test("Prueba insertar al final en lista con elementos", lista_insertar(lista, iter, &a));
	
	
	lista_iter_destruir(iter);
	lista_destruir(lista, NULL);
	
	// Ejemplo de la cátedra
	
	printf("\nPrueba de ejemplo de la catedra:\n");
	lista_t *super = lista_crear();
	
	lista_insertar_ultimo(super, "Leche");
	lista_insertar_ultimo(super, "Huevos");
	lista_insertar_ultimo(super, "Pan");
	lista_insertar_ultimo(super, "Mermelada");
	
	imprimir_iter_externo(super);
	
	lista_destruir(super, NULL);
}

void pruebas_lista_iter_interno() {
	printf("\nINICIO DE PRUEBAS ITERADOR INTERNO\n");
	
	// Pruebas del alumno
	
	lista_t *lista = lista_crear();
	
	lista_insertar_ultimo(lista, "Enero");
	lista_insertar_ultimo(lista, "Febrero");
	lista_insertar_ultimo(lista, "Marzo");
	lista_insertar_ultimo(lista, "Abril");
	lista_insertar_ultimo(lista, "Mayo");
	lista_insertar_ultimo(lista, "Junio");
	lista_insertar_ultimo(lista, "Julio");
	lista_insertar_ultimo(lista, "Agosto");
	lista_insertar_ultimo(lista, "Septiembre");
	lista_insertar_ultimo(lista, "Octubre");
	lista_insertar_ultimo(lista, "Noviembre");
	lista_insertar_ultimo(lista, "Diciembre");
	
	int num_mes = 0;
	lista_iterar(lista, imprimir_un_item, &num_mes);
	
	lista_destruir(lista, NULL);
	
	// Ejemplo de la cátedra
	
	printf("\nPrueba de ejemplo de la catedra:\n");
	lista_t *super = lista_crear();

	lista_insertar_ultimo(super, "Leche");
	lista_insertar_ultimo(super, "Huevos");
	lista_insertar_ultimo(super, "Pan");
	lista_insertar_ultimo(super, "Mermelada");

	imprimir_iter_interno(super);

	lista_destruir(super, NULL);
}

void pruebas_lista_alumno() {
	pruebas_lista_primitivas();
	pruebas_lista_de_listas();
	pruebas_lista_primitivas_volumen();
	pruebas_lista_primitivas_con_iter();
	pruebas_lista_iter_externo();
	pruebas_lista_iter_interno();
}
