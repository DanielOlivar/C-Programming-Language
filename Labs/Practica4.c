/*PRÁCTICA 3
BECERRIL OLIVAR AXEL DANIEL*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "");
	char final[]="00";
	char buffer[250];
	char *memoria;
	memoria=malloc(1);
	printf("Ingrese n líneas de texto (para terminar teclee 00)\n");
	gets(buffer);
	while(strcmp(buffer, "00")!=0){ //Para que sea diferente de 0 el strcmp y diferente de 00
		strcat(buffer," "); //Concatena el texto
		memoria=realloc(memoria, sizeof(buffer));
		if(memoria==NULL){ //Para marcar error de memoria
			fprintf(stderr,"Ya no hay memoria\n"); // fprintf y stdeer imprime errores
		}
		else{
			strcat(memoria,buffer);
		}
		gets(buffer);
	}
	printf("Resultado: %s\n",memoria);
	free(memoria);
	
	return 0;
}

