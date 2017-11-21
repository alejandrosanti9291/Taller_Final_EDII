/*
*   Programa: Listas Circulares Simples
*   Fecha: 18/11/2017
*   Autor: Alejandro Santibañez Sanchez, Sebastian Urbano y Richard Ramirez
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo));

struct Flavius {
	int info;
	struct Flavius *prox;
};
typedef struct Flavius Josephus;

void insertar (int, Josephus **);
void mostrar_vencedor (Josephus *);
void juego (Josephus **);
void encontrar (Josephus **p);
void eliminar (Josephus **p);

int main () {
	int cont;
	int M;//variable para la velocidad a la que mueren las personas//
 	int N;//el numero de personas//
 	   printf("Introduzca el numero de personas: ");
       scanf("%d",&N);
       printf("\nIntroduce el intervalo en que moriran las personas:  ");
       scanf("%d",&M);
	Josephus *persona = NULL;
	for (cont = 1; cont <= N; ++cont)
		insertar (cont, &persona);
	juego (&persona);
	mostrar_vencedor (persona);
	return EXIT_SUCCESS;
}

void insertar (int num, Josephus **p) {
	Josephus *nodo;
    nodo = (Josephus *) malloc (sizeof (Josephus));
	nodo->info = num;
	if (*p == NULL) {
		*p = nodo;
		(**p).prox = *p;
	}
	else {
		Josephus *temp = *p;
		while ((**p).prox != temp) {
			*p = (**p).prox;
		}
		(**p).prox = nodo;
		nodo->prox = temp;
		*p = temp;
	}
}

void juego (Josephus **p) {
	if (*p != NULL) {
		while (*p != (**p).prox) {
			encontrar (p);
			eliminar (p);
		}
	}
}

void encontrar (Josephus **p) {
	int cont;
	while (cont) {
		*p = (**p).prox;
		cont--;
	}
}

void eliminar (Josephus **p) {
	Josephus *morta = *p;
	while ((**p).prox !=	morta) {
		*p = (**p).prox;
	}
	(**p).prox = (**p).prox->prox;
	*p = (**p).prox;
	free(morta);
}

void mostrar_vencedor (Josephus *p) {
	if (p != NULL)
	printf ("\n\nEl sobreviviente es: %d\n", p->info);
}
