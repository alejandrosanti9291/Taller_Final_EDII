/*
*   Programa: Listas Circulares Dobles.
*   Fecha: 18/11/2017
*   Autor: Alejandro Santibañez Sanchez, Sebastian Urbano y Richard Ramirez
*/

//Librerias
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define reservar_memoria (nodo*)malloc(sizeof(nodo));

struct nodo
 {
   int dato;
   nodo *siguiente;
   nodo *anterior;
 };

nodo *primero, *ultimo;

int numNodos;
int contador = 0;
int pos;
//Funciones Menus
void menu_insertar();
void menu_mostrar();
void menu();
//Funciones
void inicializar();
void insertar();
void vizualizar_inicio();
void vizualizar_ultimo();
void buscar();
void modificar();
void eliminar_dato();
void eliminar();
void insertar_primero();
void insertar_intermedio();

 //Funcion Principal
int main(){
	menu();
	return 0;
}
void menu(){
   int opcion;
   do{
     	printf("\n************************");
	    printf("\n1.  Insertar           *");
	    printf("\n2.  Mostrar            *");
	    printf("\n3.  Buscar             *");
	    printf("\n4.  Modificar          *");
	    printf("\n5.  Eliminar Dato      *");
	    printf("\n0.  Salir              *");
	    printf("\n************************");
	    printf("\n Elija opcion: ");
	    scanf("%d",&opcion);
	    system("cls");
     	switch (opcion){
            case 0:exit('0');
                break;
            case 1:menu_insertar();
                break;
            case 2:menu_mostrar();
            	break;
            case 3:buscar();
            	break;
            case 4:modificar();
                break;
			case 5:eliminar_dato();
                break;
            default:printf("Numero Equivocado\n");
                break;
        }
		system("pause");
		system("cls");
     }while(opcion != 0);
}
void menu_insertar(){
   int opcion;
   do{
    	system("cls");
     	printf("\n");
     	printf("\n*********************************");
	    printf("\n1.  Insertar Ultimo             *");
	    printf("\n2.  Insertar Primero            *");
	    printf("\n3.  Insertar Intermedio         *");
	    printf("\n0.  Salir                       *");
	    printf("\n*********************************");
	    printf("\n");
	    printf("\n Elija opcion: ");
	    scanf("%d",&opcion);
	    system("cls");
     	switch (opcion){
            case 0:menu();
                break;
            case 1:insertar();
                break;
            case 2:insertar_primero();
            	break;
            case 3:insertar_intermedio();
            	break;
            default:printf("Numero Equivocado\n");
                break;
        }
		system("pause");
		system("cls");
     }while(opcion != 0);
}
void menu_mostrar(){
   int opcion;
   do{
     	printf("\n*********************************");
	    printf("\n1.  Mostrar Primero             *");
	    printf("\n2.  Mostrar Ultimo              *");
	    printf("\n0.  Salir                       *");
	    printf("\n*********************************");
	    printf("\n");
	    printf("Elija opcion: ");
	    scanf("%d",&opcion);
	    system("cls");
     	switch (opcion){
            case 0:menu();
                break;
            case 1:vizualizar_inicio();
                break;
			case 2:vizualizar_ultimo();
                break;
            default: printf("Numero Equivocado\n");
                break;
        }
		system("pause");
		system("cls");
     }while(opcion != 0);
}
void insertar(){
    nodo *nuevo = new nodo();
    if(nuevo == NULL)
        printf(" MEMORIA INSUFICIENTE\n");
    else{
        printf("\n dato:   ");
        scanf("%d",&nuevo->dato);
        if(primero == NULL){
        	primero = nuevo;
        	ultimo = nuevo;
        	primero->siguiente = primero;
        	primero->anterior = ultimo;
		}else{
			ultimo->siguiente = nuevo;
			nuevo->anterior = ultimo;
			nuevo->siguiente = primero;
			ultimo = nuevo;
			primero->anterior = ultimo;
		}
		printf("Dato Ingresado\n");
    }
	numNodos++;
	contador++;
}

void vizualizar_inicio(){
    nodo *actual;
    actual = primero;
    int i = 1;
    if(primero != NULL){
    	do{
    		printf("%d.  %d\n ",i,actual->dato);
    		actual = actual->siguiente;
    		i++;
		}while(actual != primero);
	}else{
		printf("La lista se encuentra vacia\n");
	}
}

void vizualizar_ultimo(){
    nodo *actual;
    actual = ultimo;
    int i = 1;
    if(primero != NULL){
    	do{
    		printf("%d.  %d\n ",contador,actual->dato);
    		actual = actual->anterior;
    		contador--;
		}while(actual != ultimo);
	}else{
		printf("La lista se encuentra vacia\n");
	}
}

void buscar(){
	nodo  *actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;

	printf("Ingrese el dato a buscar: ");
	scanf("%d",&nodoBuscado);
	if(primero != NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("Dato encontrado: %d\n",actual->dato);
				encontrado = true;
			}
			actual = actual->siguiente;
		}while(actual != primero && encontrado != true);
		if(!encontrado){
			printf("Dato no encontrado\n");
		}
	}else{
		printf("la lista esta vacia\n");
	}
}

void modificar(){
	nodo  *actual = new nodo();
	actual = primero;
	bool encontrado = false;
	int nodoBuscado = 0;

	printf("Ingrese el dato a buscar para modificar: ");
	scanf("%d",&nodoBuscado);
	if(primero != NULL){
		do{
			if(actual->dato == nodoBuscado){
				printf("Dato encontrado: %d\n",actual->dato);
				printf("Ingrese nuevo dato: \n");
				scanf("%d",&actual->dato);
				printf("Dato Modificado\n");
				encontrado = 1;
			}
			actual = actual->siguiente;
		}while(actual != primero && encontrado != 1);
		if(encontrado == 0){
			printf("Dato no encontrado\n");
		}
	}else{
		printf("La lista esta vacia\n");
	}
}

void eliminar_dato(){
	nodo  *actual = new nodo();
	actual = primero;
	nodo  *anterior = new nodo();
	anterior = NULL;
	bool encontrado = false;
	int nodoBuscado;

	printf("Ingrese el dato a Eliminar: ");
	scanf("%d",&nodoBuscado);
	if(actual != NULL){
		do{
			if(actual->dato == nodoBuscado){
				if(actual == primero){
					primero = primero->siguiente;
					primero->anterior = ultimo;
					ultimo->siguiente = primero;
				}else if(actual == ultimo){
					ultimo = anterior;
					ultimo->siguiente = primero;
					primero->anterior = ultimo;
				}else{
					anterior->siguiente = actual->siguiente;
					actual->siguiente->anterior = anterior;
				}
				printf("Dato Eliminado\n");
				encontrado = true;
			}
			anterior = actual;
			actual = actual->siguiente;
		}while(actual != primero && encontrado != true);
		if(!encontrado){
			printf("Dato no encontrado\n");
		}
	}else{
		printf("la lista esta vacia\n");
	}
	contador--;
}

void insertar_primero(){
    nodo *nuevo;
    nuevo = reservar_memoria;
    if(nuevo == NULL){
    	printf(" MEMORIA INSUFICIENTE\n");
	}else{
        printf("\n Ingrese Dato:   ");
        scanf("%d",&nuevo->dato);
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = primero;
        primero->anterior = nuevo;
        primero = nuevo;
        numNodos++;
    }
	contador++;
}

void insertar_intermedio(){
    nodo *actual;
    nodo *nuevo;
    nuevo = reservar_memoria;
    if(nuevo == NULL){
    	printf("\n MEMORIA INSUFICIENTE\n");
	}
    if (numNodos < 2){
    	printf("\n Número de nodos insuficiente");
	}else{
        int pos_insertar;
        printf("\n Ingrese Dato:   ");
        scanf("%d",&nuevo->dato);
        printf("\n Posición:   ");
        scanf(" %d", &pos_insertar);
        if((pos_insertar > 1) && (pos_insertar <= numNodos)){
            actual = primero;
            for (pos = 2; pos < pos_insertar; ++pos)
            actual = actual->siguiente;
            nuevo->siguiente = actual->siguiente;
            nuevo->anterior = actual;
            actual->siguiente->anterior = nuevo;
            actual->siguiente = nuevo;
            numNodos++;
        }
    }
   	printf("\n");
	contador++;
}
