// Inserción en un arreglo simple
#include <stdio.h>
#include <locale.h>
#define LONG_ARR 15
// declaración de las funciones
int insertar(int num);
void despliega();
// variables globales
int arreglo[LONG_ARR] = {100, 210, 320, 430, 540, 650, 760, 870};
int numElems = 8;                   // número de elementos en el arreglo
// inicio
int main () {
    setlocale(LC_ALL, "");		// para caracteres del Español
    int num;
    int result;
    printf("arreglo antes: ");  despliega();
    printf("Teclee la llave a insertar: ");
    scanf("%d", &num);
   result =  insertar(num);
   if (result == -1) {
      printf("NO se pudo insertar, arreglo lleno\n");
   } else {
      printf("SE insertó el elemento con la llave %d\n", result);
   }
    printf("arreglo después: ");  despliega();
}
// insertar un elemento en el arreglo
// entrega -1 si el arreglo está lleno
int insertar (int num) {
    // El punto de inserción es en el índice numElems
    if(numElems == LONG_ARR) {
        return -1;
    } else {
        arreglo[numElems++] = num;
        return num;
    }
}
void despliega() {
    for (int i = 0; i < numElems; i++ )   {
       printf("%d  ", arreglo[i]);
	}
	printf("\n");
}
