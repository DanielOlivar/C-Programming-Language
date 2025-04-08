// Borrado en un arreglo simple
#include <stdio.h>
#include <locale.h>
#include <stdio.h>
#define LONG_ARR 15
// declaración de las funciones
int buscar(int num);
int borrar(int num);
void despliega();
// variables globales
int arreglo[15] = {100, 210, 320, 430, 540, 650, 760, 870};
int numElems = 8;               // número de elementos en el arreglo
// inicio
int main () {
    setlocale(LC_ALL, "");		// para caracteres del Español
    int num;
    int result;
    printf("Arreglo antes: ");    despliega();
    printf("Teclee la llave a borrar: ");
    scanf("%d", &num);
   result =  buscar(num);
   if (result == -1) {
      printf("NO se encontró la llave %d, no se puede borrar\n", num);
   } else {
         int borrado = borrar(result);
         printf("Se borró la llave %d\n", borrado);
   }
   printf("Arreglo despúes: ");    despliega();
}
// busca un elemento en un arreglo simple
// entrega el INDICE del valor encontrado o -1 si no lo encuentra
int buscar(int num) {
        for (int  i = 0; i < numElems;  i++ )   {
            if(num == arreglo[i]) {
                return i;
            }
		}
		return -1;
}
// "borra" el elemento num haciendo un recorrimiento
int borrar(int n) {                             // n es el índice del valor encontrado.
    int borrado = arreglo[n];
       for (int i = n ; i < numElems;  i++) {
            arreglo[i] = arreglo[i + 1];
        }
        numElems--;
        return borrado;
}
void despliega() {
    for (int i = 0; i < numElems; i++ )   {
       printf("%d  ", arreglo[i]);
	}
	printf("\n");
}
