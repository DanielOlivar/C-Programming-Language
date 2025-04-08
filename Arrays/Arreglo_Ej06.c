// Búsqueda en un arreglo simple
#include <stdio.h>
#include <locale.h>
#define LONG_ARR 15
// declaración de la función
int buscar(int num);
// variables globales
int arreglo[LONG_ARR] = {100, 210, 320, 430, 540, 650, 760, 870};
int numElems = 8;       // número de elementos en el arreglo
// inicio
int main () {
    setlocale(LC_ALL, "");		// para caracteres del Español
    int num;
    int result;
    printf("Teclee la llave a buscar: ");
    scanf("%d", &num);
   result =  buscar(num);
   if (result == -1) {
      printf("NO se encontró la llave %d\n ", num);
   } else {
         printf("SÍ se encontró la llave %d\n ", result);
   }
}
// busca un elemento en un arreglo simple
// entrega el valor encontrado o -1 si no lo encuentra
int buscar(int num) {
        for (int  i = 0; i < numElems;  i++ )   {
            if(num == arreglo[i]) {
                return num;
            }
		}
		return -1;
}
