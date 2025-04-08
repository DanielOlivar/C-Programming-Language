// B�squeda en un arreglo simple
#include <stdio.h>
#include <locale.h>
#define LONG_ARR 15
// declaraci�n de la funci�n
int buscar(int num);
// variables globales
int arreglo[LONG_ARR] = {100, 210, 320, 430, 540, 650, 760, 870};
int numElems = 8;       // n�mero de elementos en el arreglo
// inicio
int main () {
    setlocale(LC_ALL, "");		// para caracteres del Espa�ol
    int num;
    int result;
    printf("Teclee la llave a buscar: ");
    scanf("%d", &num);
   result =  buscar(num);
   if (result == -1) {
      printf("NO se encontr� la llave %d\n ", num);
   } else {
         printf("S� se encontr� la llave %d\n ", result);
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
