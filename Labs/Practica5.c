//Becerril Olivar Axel Daniel

#include<stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5 // Capacidad máxima de la pila y la cola

//Definición de funciones para Stack

int stack[MAX]; // stack implementado como arreglo
int top = -1; // tope del stack

int peekP(); // Peek
void pop(); // Pop
void push(int data); // Push
int isemptyP(); // Revisa si está vacío
int isfullP(); // Revisa si está lleno

// Definición de funciones para Queues
int myQueue[MAX]; // Cola implementada como arreglo
int front = 0; // Inicio de la cola
int rear = -1; // Fin de la cola
int itemCount = 0; // Número de elementos en la cola

int peekQ(); // Muestra el primer elemento de la cola
void insert(int data); // Inserta un elemento al final de la cola
int removeElem(); // Remueve el primer elemento de la cola
bool isemptyQ(); // Función auxiliar, entrega true si la cola está vacía
bool isfullQ(); // Función auxiliar, entrega true si la cola está llena


int main(){
	setlocale(LC_ALL, "");
	int i,cast;
	float numero;
	for(i=0;i<MAX;i++){
		printf("%d.- Ingrese cualquier  número: ",i+1);
		scanf("%f",&numero);
		cast=(int)(numero);
		push(cast);
		insert(cast);
	}
	if(isemptyP()) {
            	printf("Stack vacío.\n");
			}
			printf("\n\nAnalizando el contenido del Stack y Queue...\n\n");
            printf("Contenido de la pila = [");
            while(top > 0) {			//vacía el stack
				printf("%d, ",stack[top--]);
   			}
   			printf("%d]\n", stack[top--]);
   			
	   		if(isemptyQ()) {
            	printf("Cola vacía.\n");
			}
            printf("\nContenido de la cola = [");
            while(front < rear) {			//vacía la cola
				printf("%d, ",myQueue[front++]);
   			}
   			printf("%d]\n", myQueue[front++]);
   			front = 0;
   			rear = -1;
			itemCount = 0;
	return 0;
}
//Funciones para Satcks
//La función peek muestra el tope del stack.
int peekP(){
	if (!isemptyP()){
	return stack[top];
    }
	else{
	printf("ERROR, el stack está vacío, no se puede hacer peek.\n");
	return -1;
	}
}
//Pop remueve  el elemento tope del stack.
void pop(){
	if(!isemptyP()) {
	top--;
	}
	else {
	printf("ERROR, el stack está vacío, no se puede hacer pop.\n");
	}
}
//Introduce un nuevo elemtno al tope del stack.
void push(int data){ 
    if(!isfullP()){
	stack[++top] = data;
	}
	else {
	printf("ERROR stack está lleno, no se puede hacer push.\n");
	}
}
//Verifica si el stack está vacio 
int isemptyP() {
	if(top == -1) {
	return true;
	} 
	else {
	return false;
	}
}
//Verifica si el stack está lleno
int isfullP(){
	if(top == MAX - 1) {
	return true;
	}
	else {
	return false;
	}
}

//Funciones para Queues
//PeekQ sirve para mostrar el elemtno en el front de la cola.
int peekQ() {
	if (isemptyQ()) {
	printf("La cola está vacía, no se puede hacer peek.\n");
	return -1;
	}
	return myQueue[front];
}

//Para inster un elemento al final de la cola
void insert(int data) {
	 if(rear == MAX-1) { // da la vuelta.
	 	 rear = -1;
	 }
	 if(isfullQ()) {
	 printf("No se puede insertar, cola llena\n");
	 rear = -1;
	 } 
	 else {
	 myQueue[++rear] = data;
	 itemCount++;
	 }
}

//Remueve el primer elemento de la cola
int removeElem() {
	if(isemptyQ()) {
	printf("no se puede remover, cola vacía\n");
	rear = -1;
	return -1;
	} 
	else {
	int data = myQueue[front++];
	itemCount--;
	return data;
	}
}

//Revisa si la cola está vacia
bool isemptyQ() {
	 return itemCount == 0;
}

//Revisa si la cola está llena
bool isfullQ() {
return itemCount == MAX;
}

