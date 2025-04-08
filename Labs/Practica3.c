#include<stdio.h>
#include<string.h>
#include<locale.h>

int calculaLong(char *Cadena);
void tieneLetra(char *ptr2, char letra);
int main (){
	system("color B0");
	setlocale(LC_ALL, "");
	int i,j,resultado,suma=0;
	char a;
	char *UNAM[]={"Universidad","Nacional","Autónoma","De","México"};
	for(i=0;i<5;i++){
		resultado=calculaLong(UNAM[i]);
		suma+=resultado;
	}
	
	printf("\nLa longitud del string UNAM es de %d carácteres.\n\n",suma);
	
	for(j=0;j<5;j++){
		tieneLetra(UNAM[j],'a');
	}
	return 0;
}
int calculaLong(char *Cadena){
	int i;
	int tam;
	tam=strlen(Cadena);
	printf("%s tiene un tamaño de %d letras\n",Cadena,tam);	
	return tam;			 	
}
void tieneLetra(char *ptr2, char letra){
	char *longitud2;
	longitud2=strchr(ptr2,letra);
	if(longitud2 == NULL){
		printf("La palabra %s NO contiene la letra buscada %c.\n",ptr2,letra);
	}else{
		printf("La palabra %s SI contine la dirección de %c\n",ptr2,letra);
	}
}


