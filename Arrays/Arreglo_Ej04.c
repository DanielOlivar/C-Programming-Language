#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/* declaraci�n de la funci�n */
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
/* funci�n para generar n�meros random */
int * getRandom( ) {
	static int  r[10];
	int i;
	srand((unsigned)time(NULL));		/* Inicializa la semilla  */
	for (i = 0; i < 10; ++i)  {
		r[i] = rand();          //genera n�mero random
		printf("r[%d] = %d\n", i, r[i]);
	}
	return r;
}
