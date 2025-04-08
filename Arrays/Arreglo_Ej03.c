#include <stdio.h>
// declaración de funciones
double getAverage(int *arr, int size);
int main () {
	/* arreglo de  int con 5 elementos */
	int balance[5] = {1000, 2, 3, 17, 50};
	double avg;
	/* pasa el nombre del arreglo (pointer) al arreglo como argumento */
	avg = getAverage(balance, 5) ;
	/* despliega el valor entregado por la función*/
	printf( "Average value is: %0.2f ", avg );
	return 0;
}
double getAverage(int *arr, int size) {
	int    i;
	double avg;
	double sum;
	double a;
	for (i = 0; i < size; ++i) {
		sum += arr[i];
	}
	avg = sum / size;
	return avg;
}
