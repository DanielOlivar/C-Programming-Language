// Actualización en arreglo simple
#include <stdio.h>
#include <locale.h>
#define LONG_ARR 15
// declaración de las funciones
int actualizar(int num, int nuevo);
void despliega();
int buscar(int num);
// variables globales
int arreglo[LONG_ARR] = {100, 210, 320, 430, 540, 650, 760, 870};
int numElems = 8;       // número de elementos en el arreglo
// inicio
int main () {
    setlocale(LC_ALL, "");		// para caracteres del Español
    int num;
    int nuevo;
    int result;
    printf("arreglo antes: ");
    despliega();
    printf("Teclee la llave del elemento a modificar: ");
    scanf("%d", &num);
    printf("Teclee la nueva llave: ");
    scanf("%d", &nuevo);
   result =  buscar(num);
   if (result == -1) {                      //result es el índice del elemento encontrado
      printf("NO se puede actualizar, no existe la llave %d\n", num);
   } else {
       arreglo[result] = nuevo;
       printf("Se actualizó el elemento con la llave %d, la nueva llave es %d\n", num, nuevo);
   }
    printf("arreglo después: ");
    despliega();
}

void despliega() {
    for (int i = 0; i < numElems; i++ )   {
       printf("%d  ", arreglo[i]);
	}
	printf("\n");
}
// Función buscar, entrega -1 si no lo encuentra, entrega el INDICE cuando lo encuentra.
int buscar(int num) {
    for (int  i = 0; i <numElems; i++ )   {
            if(num == arreglo[i]) {
                return i;           // entrega el índice NO la llave
            }
		}
		return -1;
}

