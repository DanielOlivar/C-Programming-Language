#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

// Definición de funciones
void insert(int item);		// insert en base a prioridad
int removeFirst();			// remove el primer elemento de la cola
int removePrio(int prio);	// remove el primer elemento de la cola de cierta prioridad
void display();				// desplegar la cola
int peek(); 					// peek el primer elemento de la cola
void create();				// crea una cola priorizada con algunos elementos.

// Definición de variables globales
#define max 10 				// capacidad de la cola
int queArray[max];			// cola priorizada implementada como arreglo
int front;						// inicio de la cola
int rear;						// fin de la cola
int itemCount =0;

int main() {
    int n, opcion;
    setlocale(LC_ALL, "");		// para caracteres del Español
    // Crear la cola priorizada
    front = -1;
    rear = 0;
    create();				// remover el comentario cuando se implementen las 
    							// funciones faltantes.

    printf("  1 - Insertar un elemento en la cola por prioridad\n");
    printf("  2 - Remover el primer elemento de la cola\n");
    printf("  3 - Remover el primer elemento de la cola por prioridad\n");
    printf("  4 - Desplegar la cola\n");
    printf("  5 - Peek\n");
    printf("  6 - Terminar\n");


    while (true)     {
        printf("Teclee la opción: ");
        scanf("%d", &opcion);
        int elemento;
        switch (opcion) {
        case 1:
            printf("Teclee el valor a insertar: ");
            scanf("%d",&n);
            insert(n);
            printf("Se insertó correctamente el valor: %d.\n",n);
            break;
        case 2:
            elemento = removeFirst();
            if(elemento != -1) {
                printf("Se removió el elemento %d\n", elemento);
            }
            break;
        case 3:
        	printf("Teclee prioridad: " );
        	scanf("%d",&n);
            elemento = removePrio(n);
            if (elemento == -1) {
            	printf("No se encontró ningún elemento con prioridad %d\n", n);
			} else {
				printf("Se removió el primer elemento con prioridad %d\n", n);	
			}
            break;
        case 4:
            display();
            break;
        case 5:
            elemento = peek();
            if(elemento != -1) {
                printf("Primer elemento de la cola: %d\n", elemento);
            }
            break;
        case 6:
            printf("Gracias por participar");
            exit(0);
        default:
            printf("Opción inválida, intente de nuevo\n");
        }
    }
    return 0;
}
// remover el elemento al inicio de la cola
int removeFirst() {
    if(front == -1 & rear == 0) {
        printf("La cola está vacía, no se puede remover\n");
        return -1;
    } else {
        return queArray[front--];
    }
    
}
// remove el primer elemento de la cola de cierta prioridad
int removePrio(int prio) {
	printf("Entrando a remPrio, n=%d\n",prio);
	int encontrado = -1;		// elemento encontrado, -1 = no encontrado
	int iEncontrado,i;			// índice del elemento encontrado
    if(front == -1 & rear == 0) {
        printf("La cola está vacía, no se puede remover\n");
        return -1;
    } 
    
    for(i = rear; i <= front; i++) {
        if(queArray[i] != prio) {
        	;  // nop, seguir buscando		
		} else {
			encontrado = prio;		// guarda elemento encontrado
			iEncontrado = i;		// guarda el índice del elemento encontrado
		}
	}
	if(encontrado == -1) {			// NO se econtró
		return encontrado;
	} 
	if(iEncontrado == front) {		// Se encontró en el front de la cola
		front--;
		return encontrado;				
	} else {
		int j;
		for(j = iEncontrado; j<=front; j++) {
				queArray[j] = queArray[j+1];						
		}
		front--;
		return encontrado;
	}
}
// insert en base a prioridad
void insert(int item){
	 if(rear == max-1) { // da la vuelta.
	 rear = -1;
} 	
else {
queArray[++rear] = item;
front++;
}
}


// peek el primer elemento de la cola
int peek() {
    if(front == -1 & rear == 0) {
        printf("La cola está vacía, no se puede hacer peek\n");
        return -1;
    }
    return queArray[front];
}

/* Despliega la cola */
void display() {
    int i;
    printf("arreglo: [");
    for(i = 0; i < max - 1; i++) {
      printf("%d, ", queArray[i]);
    }
    printf("%d]\n", queArray[i]);
   
}


void create() {
    front = -1;
    rear = 0;
    insert(6);
    insert(11);
    insert(18);
    insert(9);
    insert(5);
}
