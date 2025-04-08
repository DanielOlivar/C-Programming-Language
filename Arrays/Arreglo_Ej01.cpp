#include <stdio.h>
int main () {
   int n[10]; 				/* n is un arreglo de 10 enteros*/
	int i, j;
	/* inicializa los elementos a 100 + i  */
	for ( i = 0; i < 10; i++ ) {
		n[ i ] = i + 100;  	/* set elemento en el índice 1 a  i + 100 */
	}
	/* despliega cada elemento */
	for (j = 0; j < 10; j++ )  {
		printf("Element[%d] = %d\n", j, n[j] );
	}
	return 0;
}
