#include<stdio.h>
//AXEL DANIEL BECERRIL OLIVAR, GRUPO 11.
int printarray(int a1[],int size);
int main(){
	int i,j;
	//Arreglo unidimencional,
	int array1[8]= {2,3,5,7,11,13,17,19};
	printarray(array1,8);
	//Arreglo bidimencional.
	int matrix [5][5];
	for(i=0;i<5;i++){
		printf("\nmatrix[%d] es: ",i);
		for(j=0;j<5;j++){
			matrix[i][j]=i*j;
			printf("%d, ",matrix[i][j]);
		}
	}
	getchar();
	return 0;
}

int printarray(int a1[],int size){
	int i;
	int j;
	printf("array1 es: ");
	for(i=0;i<size;i++){
		printf("%d, ",a1[i]);
	}
}
