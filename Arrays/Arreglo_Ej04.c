#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* declaración de la función */
int * getRandom( );
int main ()  {
   int *p;                  // pointer a int
   int i;
   p = getRandom();
   for ( i = 0; i < 10; i++ )    {
       printf( "*(p + %d) : %d\n", i, *(p + i));
   }
   return 0;
}
/* función para generar números random */
int * getRandom( ) {
	static int  r[10];
	int i;
	srand((unsigned)time(NULL));		/* Inicializa la semilla  */
	for (i = 0; i < 10; ++i)  {
		r[i] = rand();          //genera número random
		printf("r[%d] = %d\n", i, r[i]);
	}
	return r;
}
