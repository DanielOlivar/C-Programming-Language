#include<stdio.h>
#include<locale.h>
#include<stdlib.h>
#include<string.h>
//Funciones
void imprimeReporte();
struct 	Empleado{
	int numEmpleado;
	char nombre[30];
	char apellido[30];
	char departamento[20];
	float sueldo;
};
char archivo[]="Empleados.txt";
struct Empleado emp;
//Función pricnipal
int main(){
	setlocale(LC_ALL, "");
	char buff[255];
	int result;
	FILE *fp;
	fp=fopen("Empleados.txt","r");
	fgets(buff,255,fp);
	printf("Listado de Clientes.\n");
	while(result!=EOF){
		fscanf(fp,"%d",buff);
		emp.numEmpleado=atoi(buff);
		fscanf(fp,"%s",buff);
		strcpy(emp.nombre,buff);
		fscanf(fp,"%s",buff);
		strcpy(emp.apellido,buff);
		fscanf(fp,"%s",buff);
		strcpy(emp.departamento,buff);
		result=fscanf(fp,"%s",buff);
		emp.sueldo=atof(buff);
		imprimeReporte();
	}
	fclose(fp);
	return 0;
}
//Desarrollo de funciones
void imprimeReporte(){
	printf("=========================\n");
	printf("Número: %d\n",emp.numEmpleado);
	printf("Nombre: %s\n",emp.nombre);
	printf("Apellido: %s\n",emp.apellido);
	printf("Departamento: %s\n",emp.departamento);
	printf("Sueldo: $%.02f\n",emp.sueldo);
}
