#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>

// Definición de variables globales
#define max 14 				// capacidad de la cola
#define maxpriori 10
int priori;
char res;
void datos();
int Q[max],Pr[maxpriori];
int NQ[max], NPr[maxpriori];
int r = -1,f = -1;
int rear=-1, front=-1;
//DESARROLLO funciones

int removeFirst() {
    if(f == -1 & r == 0) {
        printf("Cola vacía, no se puede remover\n");
        return -1;
    } else {
        return Q[r--];
    }

}

// peek el primer elemento de la cola
int peek() {
    if(f == -1 & r == 0) {
        printf("Cola vacía, no se puede hacer peek\n");
        return -1;
    }
    return Q[r];
}

int peekprio() {
    if(f == -1 & r == 0) {
        printf("Cola vacía, no se puede hacer peek\n");
        return -1;
    }
    return Pr[r];
}

void create() {
	enqueue(3000,1);
	enqueue(8000,2);
	enqueue(5000,2);
	enqueue(6000,3);
	enqueue(4000,3);
	enqueue(1000,5);
	enqueue(2000,6);
	enqueue(7000,8);
	enqueue(8000,1);
	enqueue(1500,4);
	enqueue(2300,4);
	enqueue(7643,7);
	enqueue(2345,7);
	enqueue(9000,9);
}

void enqueue(int data,int p)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((f==0)&&(r==max-1)) //Check if Queue is full
		printf("Queue is full");
	else
	{
		if(f==-1)//if Queue is empty
		{
			f = r = 0;
			Q[r] = data;
			Pr[r] = p;

		}
		else if(r == max-1)//if there there is some elemets in Queue
		{
			for(i=f;i<=r;i++) { Q[i-f] = Q[i]; Pr[i-f] = Pr[i]; r = r-f; f = 0; for(i = r;i>f;i--)
				{
					if(p>Pr[i])
					{
						Q[i+1] = Q[i];
						Pr[i+1] = Pr[i];
					}
					else
						break;
					Q[i+1] = data;
					Pr[i+1] = p;
					r++;
				}
			}
		}
		else
		{
			for(i = r;i>=f;i--)
			{
				if(p>Pr[i])
				{
					Q[i+1] = Q[i];
					Pr[i+1] = Pr[i];	
				}
				else
					break;
			}
			Q[i+1] = data;
			Pr[i+1] = p;
			r++;
		}	
	}

}
void print() //print the data of Queue
{
int i;
	for(i=f;i<=r;i++)
	{
		printf("\nElement = %d\tPriority = %d",Q[i],Pr[i]);
	}
}
int dequeue() //remove the data from front
{
	if(f == -1)
	{
		printf("Queue is Empty");
	}	
	else
	{
		printf("deleted Element = %d\t Its Priority = %d",Q[f],Pr[f]);
		if(f==r)
			f = r = -1;
		else
			f++;
	}
}
////////////////////////////////////// NEW QUENUE///////////////////////////////////////////////////////////////
void Nenquenue(int ndata,int np)//Enqueue function to insert data and its priority in queue
{
	int i;
	if((front==0)&&(rear==max-1)) //Check if Queue is full
		printf("Queue is full");
	else
	{
		if(front==-1)//if Queue is empty
		{
			front = rear = 0;
			NQ[rear] = ndata;
			NPr[rear] = np;

		}
		else if(rear == max-1)//if there there is some elemets in Queue
		{
			for(i=front;i<=rear;i++) { NQ[i-front] = NQ[i]; NPr[i-front] = NPr[i]; rear = rear-front; front = 0; for(i =rear ;i>front ;i--)
				{
					if(np>NPr[i])
					{
						NQ[i+1] = NQ[i];
						NPr[i+1] = NPr[i];
					}
					else
						break;
					NQ[i+1] = ndata;
					NPr[i+1] = np;
					rear++;
				}
			}
		}
		else
		{
			for(i = rear;i>=front;i--)
			{
				if(np>NPr[i])
				{
					NQ[i+1] = NQ[i];
					NPr[i+1] = NPr[i];	
				}
				else
					break;
			}
			NQ[i+1] = ndata;
			NPr[i+1] = np;
			rear++;
		}	
	}

}

void Nprint() //print the data of NEW Queue
{
int i;
	for(i=front;i<=rear;i++)
	{
		printf("\nElement = %d\tPriority = %d",NQ[i],NPr[i]);
	}
}

//Desarrolo main
int main()
{
	int opt,n,i,data,p;
	setlocale(LC_ALL, ""); //CARÁCTERES EN ESPAÑOL
	system("color B0");
	datos();
	
	

	do{
		printf("\n\t\t\tMenu inicial.\n\n1. Mostrar procesos en cola.\n2. Insertar más elementos\n3. Iniciar Simulador\n4. Generar nueva cola\n0. Salir\n");
		printf("\nIngrese una opción: ");
		scanf("%d",&opt);
		switch(opt){
			int elemento, prio, n, x, v;
			case 1:
				system("cls");
				datos();
				printf("Procesos en cola:");
				create();
				print();
				printf("\nNo hay más procesos que mostrar.\n");
				break;
			case 2:
				system("cls");
				datos();
				printf("\nIntroduce la cantidad de elementos a ingresar:\n");
				scanf("%d",&n);
				printf("\nIntroduce tus elementos y su prioridad separados por un espacio.\n");
				i=0;
				while(i<n){
					scanf("%d %d",&data,&p);
					enqueue(data,p);
					i++;
				}
				break;
			case 3:
				system("cls");
				datos();
				for(v=0; v<14; v++){
				elemento = removeFirst();
				prio = peekprio();
				n=rand()%11;
				n=rand()%n+1;
				x=rand()%11;
				x=rand()%x+1;
            	if(elemento != -1) {
                printf("\nProceso %d está ejecutando con prioridad %d\n", elemento, prio);
          		}
          		printf("Procesando %d segundos\n", n);
          		printf("Proceso %d perdió control del CPU.\n", elemento);
          		printf("Nueva prioridad: %d\n", x);
          		printf("Se regresará a la cola con prioridad %d\n\n", x);
				Nenquenue(elemento, x);
				}
				break;
			case 4:
				system("cls");
				datos();
				printf("Procesos en cola:");
				Nprint();
				break;
			case 0:
				system("cls");
				printf("\nGracias por utilizar el programa.");
				break;
			default:
				printf("\nElija una opción válida:\n");

		}
	}while(opt!=0);
        return 0;
}

void datos(){
	printf("Facultad de Ingeniería\n");
	printf("Materia: Estructura de Datos y Algorítmos 1.\n\n");
	printf("\t\t\tProyecto Final 2021-1.\n");
	printf("Integrantes:\n");
	printf("Becerril Olivar Axel Daniel.\n");
	printf("Matrícula: 31711388-8\n");
	printf("Martínez Acuña Ruth Amalinalli\n");
	printf("Matrícula: 31701085-9\n\n");
}
