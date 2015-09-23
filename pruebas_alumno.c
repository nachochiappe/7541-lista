#include "lista.h"
#include "testing.h"
#include <stddef.h>
#include <stdio.h>
#include <stdbool.h>

/* ******************************************************************
 *                      EJEMPLOS ITERADORES
 * *****************************************************************/
/*
//
// Imprimir una lista con iterador externo
//
void imprimir_iter_externo(lista_t *lista)
{
    lista_iter_t *iter = lista_iter_crear(lista);
    int num_items = 0;

    while (!lista_iter_al_final(iter))
    {
        char *elemento = lista_iter_ver_actual(iter);
        printf("%d. %s\n", ++num_items, elemento);

        lista_iter_avanzar(iter);
    }
	printf("Tengo que comprar %d ítems\n", num_items);
    lista_iter_destruir(iter);
}


//
// Imprimir una lista con iterador interno
//

bool imprimir_un_item(void *elemento, void *extra)
{
	// Sabemos que ‘extra’ es un entero, por tanto le podemos hacer un cast.
	int *contador = extra;
	char *item = elemento;
	printf("%d. %s\n", ++(*contador), item);

	return true; // seguir iterando
}

void imprimir_iter_interno(lista_t *lista)
{
	int num_items = 0;
	lista_iterar(lista, imprimir_un_item, &num_items);
	printf("Tengo que comprar %d ítems\n", num_items);
}

//
// Ejemplo de uso
//


void ejemplo_iteradores() {
    lista_t *super = lista_crear();

    lista_insertar_ultimo(super, "leche");
    lista_insertar_ultimo(super, "huevos");
    lista_insertar_ultimo(super, "pan");
    lista_insertar_ultimo(super, "mermelada");

    imprimir_iter_externo(super);
    imprimir_iter_interno(super);

    lista_destruir(super, NULL);
}
*/

/* ******************************************************************
 *                   PRUEBAS UNITARIAS ALUMNO
 * *****************************************************************/

void pruebas_lista_primitivas() {
	// Declaro variables a utilizar
	int a = 1;
	int* p_a = &a;
		
	// Crear lista
	lista_t *lista = lista_crear();
	print_test("Prueba crear lista", lista != NULL);
	
	// Verificar que esté vacía
	print_test("Prueba lista está vacía", lista_esta_vacia(lista));
	
	// Insertar un nodo al principio
	print_test("Prueba insertar primero", lista_insertar_primero(lista, p_a));
	
	// Verificar que no esté vacía
	print_test("Prueba lista NO está vacía", !lista_esta_vacia(lista));
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 1", lista_largo(lista) == 1);
	
	// Ver primero
	print_test("Prueba ver primero de lista = p_a", lista_ver_primero(lista) == p_a);
	
	// Borrar el nodo
	print_test("Prueba borrar primero de lista = p_a", lista_borrar_primero(lista) == p_a);
	
	// Verificar que esté vacía luego de borrar el nodo
	print_test("Prueba lista está vacía luego de borrar nodo", lista_esta_vacia(lista));
	
	// Obtener largo de la lista luego de borrar el nodo
	print_test("Prueba largo de lista = 0", lista_largo(lista) == 0);
	
	// Insertar un nodo al final
	print_test("Prueba insertar ultimo", lista_insertar_ultimo(lista, p_a));
	
	// Verificar que no esté vacía
	print_test("Prueba lista NO está vacía", !lista_esta_vacia(lista));
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 1", lista_largo(lista) == 1);
	
	// Ver primero
	print_test("Prueba ver primero de lista = p_a", lista_ver_primero(lista) == p_a);
	
	// Borrar el nodo
	print_test("Prueba borrar primero de lista = p_a", lista_borrar_primero(lista) == p_a);
	
	// Verificar que esté vacía luego de borrar el nodo
	print_test("Prueba lista está vacía luego de borrar nodo", lista_esta_vacia(lista));
	
	// Obtener largo de la lista luego de borrar el nodo
	print_test("Prueba largo de lista = 0", lista_largo(lista) == 0);
	
	// Destruir lista
	lista_destruir(lista, NULL);
}

void pruebas_lista_primitivas_volumen() {	
	// Declaro variables a utilizar
	int a = 1, b = 2, c = 3, d = 4, e = 5;
	int* p_a = &a;
	int* p_b = &b;
	int* p_c = &c;
	int* p_d = &d;
	int* p_e = &e;
	
	// Crear lista
	lista_t *lista = lista_crear();
	print_test("Prueba crear lista", lista != NULL);
	
	// Insertar 2500 nodos al principio (5 nodos 500 veces = 2500)
	for (int i = 1; i <= 500; i++) {
		lista_insertar_primero(lista, p_a);
		lista_insertar_primero(lista, p_b);
		lista_insertar_primero(lista, p_c);
		lista_insertar_primero(lista, p_d);
		lista_insertar_primero(lista, p_e);
	}
	
	// Verificar que no esté vacía
	print_test("Prueba lista NO está vacía", !lista_esta_vacia(lista));
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 2500", lista_largo(lista) == 2500);
	
	// Ver primero
	print_test("Prueba ver primero de lista = p_e", lista_ver_primero(lista) == p_e);
	
	// Insertar 2500 nodos al final (5 nodos 500 veces = 2500)
	for (int i = 1; i <= 500; i++) {
		lista_insertar_ultimo(lista, p_a);
		lista_insertar_ultimo(lista, p_b);
		lista_insertar_ultimo(lista, p_c);
		lista_insertar_ultimo(lista, p_d);
		lista_insertar_ultimo(lista, p_e);
	}
	
	// Obtener largo de la lista
	print_test("Prueba largo de lista = 5000", lista_largo(lista) == 5000);
	
	// Ver primero
	print_test("Prueba ver primero de lista = p_e", lista_ver_primero(lista) == p_e);
	
	// Destruir lista
	lista_destruir(lista, NULL);
}

void pruebas_lista_primitivas_con_iter() {
	
}

void pruebas_lista_iter_externo() {
	
}

void pruebas_lista_iter_interno() {
	
}

void pruebas_lista_alumno() {
	pruebas_lista_primitivas();
	pruebas_lista_primitivas_volumen();
	pruebas_lista_primitivas_con_iter();
	pruebas_lista_iter_externo();
	pruebas_lista_iter_interno();
}
