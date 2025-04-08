//Becerril Olivar Axel Daniel

#include<stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <string.h>
#include <stdlib.h>
#define MAX 5 // Capacidad m�xima de la pila y la cola

//Definici�n de funciones para Stack

int stack[MAX]; // stack implementado como arreglo
int top = -1; // tope del stack

int peekP(); // Peek
void pop(); // Pop
void push(int data); // Push
int isemptyP(); // Revisa si est� vac�o
int isfullP(); // Revisa si est� lleno

// Definici�n de funciones para Queues
int myQueue[MAX]; // Cola implementada como arreglo
int front = 0; // Inicio de la cola
int rear = -1; // Fin de la cola
int itemCount = 0; // N�mero de elementos en la cola

int peekQ(); // Muestra el primer elemento de la cola
void insert(int data); // Inserta un elemento al final de la cola
int removeElem(); // Remueve el primer elemento de la cola
bool isemptyQ(); // Funci�n auxiliar, entrega true si la cola est� vac�a
bool isfullQ(); // Funci�n auxiliar, entrega true si la cola est� llena


int main(){
	setlocale(LC_ALL, "");
	int i,cast;
	float numero;
	for(i=0;i<MAX;i++){
		printf("%d.- Ingrese cualquier  n�mero: ",i+1);
		scanf("%f",&numero);
		cast=(int)(numero);
		push(cast);
		insert(cast);
	}
	if(isemptyP()) {
            	printf("Stack vac�o.\n");
			}
			printf("\n\nAnalizando el contenido del Stack y Queue...\n\n");
            printf("Contenido de la pila = [");
            while(top > 0) {			//vac�a el stack
				printf("%d, ",stack[top--]);
   			}
   			printf("%d]\n", stack[top--]);
   			
	   		if(isemptyQ()) {
            	printf("Cola vac�a.\n");
			}
            printf("\nContenido de la cola = [");
            while(front < rear) {			//vac�a la cola
				printf("%d, ",myQueue[front++]);
   			}
   			printf("%d]\n", myQueue[front++]);
   			front = 0;
   			rear = -1;
			itemCount = 0;
	return 0;
}
//Funciones para Satcks
//La funci�n peek muestra el tope del stack.
int peekP(){
	if (!isemptyP()){
	return stack[top];
    }
	else{
	printf("ERROR, el stack est� vac�o, no se puede hacer peek.\n");
	return -1;
	}
}
//Pop remueve  el elemento tope del stack.
void pop(){
	if(!isemptyP()) {
	top--;
	}
	else {
	printf("ERROR, el stack est� vac�o, no se puede hacer pop.\n");
	}
}
//Introduce un nuevo elemtno al tope del stack.
void push(int data){ 
    if(!isfullP()){
	stack[++top] = data;
	}
	else {
	printf("ERROR stack est� lleno, no se puede hacer push.\n");
	}
}
//Verifica si el stack est� vacio 
int isemptyP() {
	if(top == -1) {
	return true;
	} 
	else {
	return false;
	}
}
//Verifica si el stack est� lleno
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
	printf("La cola est� vac�a, no se puede hacer peek.\n");
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
	printf("no se puede remover, cola vac�a\n");
	rear = -1;
	return -1;
	} 
	else {
	int data = myQueue[front++];
	itemCount--;
	return data;
	}
}

//Revisa si la cola est� vacia
bool isemptyQ() {
	 return itemCount == 0;
}

//Revisa si la cola est� llena
bool isfullQ() {
return itemCount == MAX;
}

