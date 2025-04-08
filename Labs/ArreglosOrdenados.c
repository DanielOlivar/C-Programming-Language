// Arreglos Ordenados
//AXEL DANIEL BECERRIL OLIVAR
#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define MAX_ARR 15
// declaración de las funciones
int insertar(int dato);
int busquedaLineal(int dato);
int busquedaBinaria(int dato);
int actualizar(int dato, int nuevo);
int  borrar(int dato);
void crearArreglo();
void desplegarArreglo();
// variables globales
int arreglo[MAX_ARR] ;          // tamaño máximo del arreglo
int numElems = 0;               // número de elementos en el arreglo
// inicio
int main () {

    if (setlocale(LC_ALL, "") == NULL) { // para caracteres del Español
        printf(" setLocale dió null\n");
    }

    int dato, nuevo, opcion, resultado;
    crearArreglo();			    // crear un arreglo de prueba
    desplegarArreglo();         // y desplegarlo
    printf(" 1 -  Insertar.\n");
    printf(" 2 -  Encontrar en forma lineal.\n");
    printf(" 3 -  Encontrar en forma binaria .\n");
    printf(" 4 -  Actualizar.\n");
    printf(" 5 -  Borrar.\n");
    printf(" 6 -  Desplegar el arreglo.\n");
    printf(" 7 -  Terminar\n");
    while (true) {
        printf("Teclee la opción: ");
        scanf("%d", &opcion);
        switch (opcion) {
        	
        case 1:			// Insertar un nuevo elemento en el arreglo
            printf("Teclee el  valor del elemento a insertar\n");
         	scanf("%d", &dato);
         	int resultado =  insertar(dato);
         	if(resultado  == -2) {			// insertar regresa -2 si el arreglo está lleno.
         		printf("Arreglo lleno, no se puede insertar.\n");
         		break;
         	}  
			if(resultado==-1){
         	printf("Se insertó  %d en el arreglo.\n", dato);
			}
			break;
        case 2:			// Encontrar en forma lineal
            printf("Teclee el  valor del elemento a encontrar\n");
         	scanf("%d", &dato);
         	resultado =  busquedaLineal(dato);
         	if(resultado  == -1) {			// regresa -1 si no se encuentra
         		printf("No se encontró %d en la lista.\n", dato);
			}  else  {
         	printf("Se encontró  %d en el arreglo.\n", dato);
			}
            break;
        case 3:			// Búsqueda binaria
            printf("Teclee valor del elemento a encontrar.\n");
         	scanf("%d", &dato);
         	resultado = busquedaBinaria(dato);
         	if(resultado == -1) {			// regresa -1 si no se encuentra
         		printf("No se encontró %d en la lista.\n", dato);
			}  else  {
         	printf("Se encontró la llave %d.\n", dato);
			}
            break;
        case 4:			// Actualizar
            printf("Teclee valor del elemento a actualizar.\n");
         	scanf("%d", &dato);
         	printf("Teclee el nuevo valor del elemento.\n");
         	scanf("%d", &nuevo);
         	resultado =actualizar(dato, nuevo);
         	if(resultado == -1) {			// actualizar regresa -1 si no se encuentra
         		printf("No se encontró %d en la lista.\n", dato);
			} else {
				printf("Se encontró %d en la lista y se cambio por %d.\n", dato, nuevo);
			}
            break;
        case 5:			// borrar
        	 printf("Teclee valor del elemento a borrar.\n");
         	scanf("%d", &dato);
         	resultado = borrar(dato);
         	if(resultado == -1) {			// borrar regresa -1 si no se encuentra
         		printf("No se encontró %d en el arreglo, no se puede borrar.\n", dato);
			}  else  {
         	printf("Se encontró la llave %d y fue borrado el elemento.\n", dato);
			}
            break;
        case 6:
           desplegarArreglo();
           break;
         case 7:
            printf("Gracias por participar");
            exit(0);
        default:
            printf("Opción inválida, intente de nuevo\n");
  		}
    }
   return 0;
}  // fin de main
// Funciones.
int insertar(int dato) {              //  insertar en el arreglo
  	if(numElems == MAX_ARR) {
  		return -2; // arreglo lleno
	}
	int j;
	for(j=0; j<numElems; j++) { // encuentra punto de inserción (en forma lineal)
		if(arreglo[j] > dato) { // se encontró
		break;
	}
	}
	int k;
	for(k=numElems; k > j; k--) { // recorre hacia el final del arreglo
		arreglo[k] = arreglo[k-1];
	}
	arreglo[j] = dato;
	numElems++;
	
}
int busquedaLineal(int dato) {        // búsqueda lineal
     int i;
    for(i = 0; i < numElems ; i++) {
        if(arreglo[i] == dato) {
            return dato;
        } else {
            continue;
        }
    }
    return -1;
}
int busquedaBinaria(int dato) {
	int limInferior=0;
	int limSuperior=numElems-1;
	int valorCentral;
	while(true){
		valorCentral=(limInferior+limSuperior)/2;
		if(arreglo[valorCentral]==dato){
			return valorCentral;
		}
		if(limInferior>limSuperior){
			return -1;
		}
		if(arreglo[valorCentral]<dato){
			limInferior=valorCentral+1;
		}
		else
		limSuperior=valorCentral-1;
	}		
	
}
   

int actualizar(int dato, int nuevo) {   // actualización
     int i;
     for(i=0;i<numElems; i++){
     	if(arreglo[i]==dato){
     		break;
		 }
	 }
	 if(i==numElems){
	 	return -1;
	 }
	 borrar(dato);
	 insertar(nuevo);
}
int  borrar(int dato) {                 // borrado
    int i;
    for(i=0;i<numElems;i++){
    	if(arreglo[i]==dato){
    		break;
		}
	}
	if(i==numElems){
		return -1;
	}
	int k;
	for(k=i;k<numElems;k++)
		arreglo[k]=arreglo[k+1];
	numElems--;
	return dato;
   
}
void crearArreglo() {
    numElems = 0;
    arreglo[0]  = 110;
    numElems ++;
    arreglo[1]  = 220;
    numElems ++;
    arreglo[2]  = 330;
    numElems ++;
    arreglo[3]  = 440;
    numElems ++;
    arreglo[4]  = 550;
    numElems ++;
    arreglo[5]  = 660;
    numElems ++;
    arreglo[6]  = 770;
    numElems ++;
    arreglo[7]  = 880;
    numElems ++;
    return;
}
void desplegarArreglo() {
    int i;
    printf("[");
    for(i = 0; i < numElems - 1; i++) {
        printf("%d, ", arreglo[i]);
    }
    printf("%d]\n", arreglo[i]);
    return -1;
}
