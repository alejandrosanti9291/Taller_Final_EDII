/*
*   Programa: Listas
*   Fecha: 18/11/2017
*   Autor: Alejandro Santibañez Sanchez, Sebastian Urbano y Richard Ramirez
*/

//Librerias
#include<stdio.h>
#include<stdlib.h>
#define reservar_memoria (Nodo *)malloc(sizeof(Nodo))

//Estructura
struct Nodo{
    int dato;
    Nodo *siguiente;
    Nodo *anterior;
};

//Funciones menus
void menu();
void menuListaSimple();
void menuListaDoble();
//Prototipo Funciones listas simples
void insertarLista(Nodo *&, int);
void editarLista(Nodo *, int);
void eliminarElementoLista(Nodo *&, int);
void buscarLista(Nodo *, int);
void mostrarLista(Nodo *);
void vaciarLista(Nodo *&, int &);
bool listaVacia(Nodo *);
//Prototipo Funciones listas dobles
void insertarListaDoble(Nodo *&, Nodo *&, int );
void editarListaDoble(Nodo *&, Nodo *&, int);
void eliminarElementoListaDoble(Nodo *&, Nodo *&, int);
void buscarListaDoble(Nodo *, Nodo *, int);
void mostrarListaDobleDirecta(Nodo *, int );
void mostrarListaDobleInversa(Nodo *, Nodo *, int );
void vaciarListaDoble();

//Funcion Principal
int main(){
    menu();

    return 0;
}

void menu(){
    int opcion;

    do{
        printf("\t\t|-----------------------------------|\n");
		printf("\t\t|           MENU PRINCIPAL          |\n");
		printf("\t\t|-----------------------------------|\n");
		printf("\t\t|           1. Listas Simples       |\n");
		printf("\t\t|           2. Listas Dobles        |\n");
		printf("\t\t|           0. Salir                |\n");
		printf("\t\t|-----------------------------------|\n\n");
		printf("\t\tIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");

		switch(opcion){
        case 1: menuListaSimple();
            break;
        case 2: menuListaDoble();
            break;
        case 0: exit(0);
            break;
        default: printf("No es una opcion valida\n");
		}
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void menuListaSimple(){
    Nodo *lista = NULL;
    int opcion, dato;

    do{
        printf("\t\t|-------------------------------|\n");
		printf("\t\t|        MENU LISTAS SIMPLES    |\n");
		printf("\t\t|-------------------------------|\n");
		printf("\t\t|                               |\n");
		printf("\t\t| 1. Insertar     |  6. vaciar  |\n");
		printf("\t\t| 2. Editar       |  0. Salir   |\n");
		printf("\t\t| 3. Eliminar     |             |\n");
		printf("\t\t| 4. Buscar       |             |\n");
		printf("\t\t| 5. Mostrar      |             |\n");
		printf("\t\t|-------------------------------|\n\n");
		printf("\t\tIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");

		switch(opcion){
            case 1: printf("Ingrese un elemento: \n");
                    scanf("%d", &dato);
                    fflush(stdin);
                    insertarLista(lista, dato);
                break;
            case 2: mostrarLista(lista);
                    printf("Ingrese elemento a editar: \n");
                    scanf("%d", &dato);
                    editarLista(lista, dato);
                break;
            case 3: mostrarLista(lista);
                    printf("Ingrese elemento a eliminar: \n");
                    scanf("%d", &dato);
                    eliminarElementoLista(lista, dato);
                break;
            case 4: printf("Ingrese elemento a buscar: \n");
                    scanf("%d", &dato);
                    buscarLista(lista, dato);
                break;
            case 5: mostrarLista(lista);
                break;
            case 6: while(lista != NULL){
                    vaciarLista(lista, dato);
                    printf(" -> %d", dato);
                    }
            printf("\n");
                break;
            case 0: menu();
                break;
            default: printf("No es una opcion valida\n");
		}
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void insertarLista(Nodo *&lista, int n){
    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo -> dato = n;
    nuevo_nodo -> siguiente = NULL;
    Nodo *aux1 = lista;
    Nodo *aux2 = NULL;

    while(aux1 != NULL && aux1 -> dato < n){
        aux2 = aux1;
        aux1 = aux1 -> siguiente;
    }
    if(aux1 == lista){
        lista = nuevo_nodo;
    }else{
        aux2 -> siguiente = nuevo_nodo;
    }
    nuevo_nodo -> siguiente = aux1;
}

void editarLista(Nodo *lista, int n){
    Nodo* nuevo = reservar_memoria;
	nuevo = lista;
	int buscar = 0, encontrado = 0;
	printf("\nIngrese el elemento a buscar para modificar: ");
	scanf("%d", & buscar);
	if(lista != NULL){
		while(nuevo != NULL && encontrado != 1){

			if(nuevo -> dato == buscar){
				printf("\nEl elemento %d encontrado \n", buscar);
				printf("\nIngrese el nuevo dato: ");
				scanf("%d", &nuevo -> dato);
				printf("\nElemento modificado con exito");
				encontrado = 1;
			}

			printf("\n %d ", nuevo -> dato);
			nuevo = nuevo -> siguiente;
		}
		if(encontrado == 0){
			printf("\nElemento no encontrado\n");
		}
	}else{
		printf("\nLa lista se encuentra vacia\n");
	}
}

void eliminarElementoLista(Nodo *&lista, int n){
    if(lista != NULL){
        Nodo *aux1 = lista;
        Nodo *aux2 = NULL;

        while((aux1 != NULL) && (aux1 -> dato != n)){
            aux2 = aux1;
            aux1 = aux1 -> siguiente;
        }
        if(aux1 == NULL){
            printf("El elemento no encontrado\n");
        }else if(aux2 == NULL){
            lista = lista -> siguiente;
            free(aux1);
        }else{
            aux2 -> siguiente = aux1 -> siguiente;
            free(aux1);
        }
        printf("Eliminado con exito\n");
    }
}

void buscarLista(Nodo *lista, int n){
    bool band = false;

    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo = lista;

    while((nuevo_nodo != NULL)&&(nuevo_nodo -> dato <= n)){
        if(nuevo_nodo -> dato == n){
            band = true;
        }
        nuevo_nodo = nuevo_nodo -> siguiente;
    }
    if(band == true){
        printf("El elemento %d ha sido encontrado\n", n);
    }else{
        printf("El elemento %d no ha sido encontrado\n", n);
    }
}

void mostrarLista(Nodo *lista){
    Nodo *actual = reservar_memoria;
    actual = lista;

    if(listaVacia(lista)){
        printf("La lista esta vacia\n");
    }else{
        while(actual != NULL){
        printf("%d \n", actual -> dato);
        actual = actual -> siguiente;
        }
    }
}

void vaciarLista(Nodo *&lista, int &n){
    Nodo *aux = lista;
    n = aux -> dato;
    lista = aux -> siguiente;
    free(aux);
}
//Menu listas dobles
void menuListaDoble(){
    Nodo *inicio = NULL;
    Nodo *fin = NULL;
    int opcion, dato;

    do{
        printf("\t\t|-------------------------------|\n");
		printf("\t\t|        MENU LISTAS DOBLES     |\n");
		printf("\t\t|-------------------------------|\n");
		printf("\t\t|                               |\n");
		printf("\t\t| 1. Insertar     |  6. vaciar  |\n");
		printf("\t\t| 2. Editar       |  0. Salir   |\n");
		printf("\t\t| 3. Eliminar     |             |\n");
		printf("\t\t| 4. Buscar       |             |\n");
		printf("\t\t| 5. Mostrar      |             |\n");
		printf("\t\t|-------------------------------|\n\n");
		printf("\t\tIngrese una opcion: ");
		scanf("%d", &opcion);
		system("cls");

		switch(opcion){
            case 1: printf("Ingrese un elemento: \n");
                    scanf("%d", &dato);
                    insertarListaDoble(inicio, fin, dato);
                break;
            case 2: editarListaDoble(inicio, fin, dato);
                break;
            case 3: mostrarListaDobleDirecta(inicio, dato);
                    eliminarElementoListaDoble(inicio, fin, dato);
            break;
            case 4: buscarListaDoble(inicio, fin, dato);
                break;
            case 5: printf("1. De derecha a izquierda");
                    printf("\t2. De izquierda a derecha");
                    printf("\t0. salir\n\n");
                    printf("\t\tIngrese una opcion: ");
                    scanf("%d", &opcion);
                    system("cls");

                    switch(opcion){
                    case 1: mostrarListaDobleDirecta(inicio, dato);
                        break;
                    case 2: mostrarListaDobleInversa(inicio, fin, dato);
                        break;
                    case 0: menuListaSimple();
                        break;
                    default: printf("No es una opcion valida\n");
                    }
                break;
            case 6:
                break;
            case 0: menu();
                break;
            default: printf("No es una opcion valida\n");
		}
        system("pause");
        system("cls");
    }while(opcion != 0);
}

void insertarListaDoble(Nodo *&inicio, Nodo *&fin, int n){
    Nodo *nuevo = reservar_memoria;
	nuevo->dato = n;

	if(inicio == NULL){
		inicio = nuevo;
		nuevo->siguiente = NULL;
		nuevo->anterior = NULL;
		fin = nuevo;
	}else{
		nuevo->siguiente = NULL;
		nuevo->anterior = fin;
		fin->siguiente = nuevo;
		fin = nuevo;
	}
}

void editarListaDoble(Nodo *&inicio, Nodo *&fin, int dato){
    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo = inicio;
    int num;
    int encontrado = 0;

    printf("Ingrese el numero a buscar para modificar: ");
    scanf("%d", &num);

    if(inicio != NULL){
        while(nuevo_nodo != NULL && encontrado != 1){
           if(nuevo_nodo -> dato == num){
                printf("Dato %d encontrado\n", num);
                printf("Ingrese el nuevo dato\n");
                scanf("%d", &nuevo_nodo -> dato);
                printf("El nodo ha sido modificado\n");
                encontrado = 1;
           }
            nuevo_nodo = nuevo_nodo -> siguiente;
        }
        if(encontrado == 0){
            printf("Dato no encontrado\n");
        }
    }else{
        printf("La lista esta vacia\n");
    }
}

void eliminarElementoListaDoble(Nodo *&inicio, Nodo *&fin, int n){
    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo = inicio;
    Nodo *atras = reservar_memoria;
    atras = NULL;
    int encontrado = 0, nodoBuscado = 0;

    printf("Ingrese el elemento a eliminar: ");
    scanf("%d", &nodoBuscado);

    if(inicio != NULL){
        while(nuevo_nodo != NULL && encontrado != 1){
           if(nuevo_nodo -> dato == nodoBuscado){
                if(nuevo_nodo == inicio){
                    inicio = inicio -> siguiente;
                    inicio -> anterior = NULL;
                }else if(nuevo_nodo == fin){
                    atras -> siguiente = NULL;
                    fin = atras;
                }else{
                    atras -> siguiente = nuevo_nodo -> siguiente;
                    nuevo_nodo -> siguiente -> anterior = atras;
                }
                printf("Eliminado con exito\n");
                encontrado = 1;
           }
            atras = nuevo_nodo;
            nuevo_nodo = nuevo_nodo -> siguiente;
        }
        if(encontrado == 0){
            printf("Dato no encontrado\n");
        }else{
            free(atras);
        }
    }else{
         printf("La lista esta vacia\n");
    }
}

void buscarListaDoble(Nodo *inicio, Nodo *fin, int n){
    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo = inicio;
    int encontrado = 0, nodoBuscado = 0;

    printf("Ingrese elemento a buscar: ");
    scanf("%d", &nodoBuscado);

    if(inicio != NULL){
        while(nuevo_nodo != NULL && encontrado != 1){
           if(nuevo_nodo -> dato == nodoBuscado){
                printf("Elemento %d encontrado\n", nodoBuscado);
                encontrado = 1;
           }
            nuevo_nodo = nuevo_nodo -> siguiente;
        }
        if(encontrado == 0){
            printf("Elemento no encontrado\n");
        }
    }else{
        printf("La lista esta vacia\n");
    }
}

void mostrarListaDobleDirecta(Nodo *inicio, int n){
    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo = inicio;

    if(inicio != NULL){
        while(nuevo_nodo != NULL){
            printf("\n %d\n", nuevo_nodo -> dato);
            nuevo_nodo = nuevo_nodo -> siguiente;
        }
    }else{
        printf("La lista esta vacia\n");
    }
}

void mostrarListaDobleInversa(Nodo *inicio, Nodo *fin, int n){
    Nodo *nuevo_nodo = reservar_memoria;
    nuevo_nodo = fin;

    if(inicio != NULL){
        while(nuevo_nodo != NULL){
            printf("\n %d", nuevo_nodo -> dato);
            nuevo_nodo = nuevo_nodo -> anterior;
        }
    }else{
        printf("La lista esta vacia\n");
    }
}

bool listaVacia(Nodo *lista){
    return (lista == NULL)? true:false;
}
