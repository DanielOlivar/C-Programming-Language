#include<stdio.h>
#include <stdlib.h>
int main()
{
	int bebida, edad;
	float dinero,total,cambio1,cambio2,cambio3,restante;
	do{
	printf("�Cu�ntos a�os tienes? ");
	scanf("%d",&edad);
	}while(edad<0);
	if (edad < 18){
		printf("�Ve a casa por tu leche!");
	}
	else 
	{
		printf("Bienvenido se�or.\n");
			printf("�Con cuanto dinero cuentas? ");
			scanf("%f",&dinero);
			
	if (dinero < 2000 && dinero>200){
	printf("Pase a la zona general.\n");	
	do
	{
		printf("�Que desea beber?\n");
		printf("1. Wisky $500\n2. Ron $200\n3. Tequila $400\n4. Nadddda stoy my ha-ic-py.\n");
		scanf("%d",&bebida);
		switch (bebida)
		   {
					   		
			case 1:
			
			dinero=dinero-500;
			printf("Le servi:wisky y cuesta $500 por lo que le queda: $%.2f\n",dinero);
			total = total+dinero;
			break;
		

			case 2:
			dinero =dinero-200;
			printf("Le servi:ron y cuesta $200 por lo que le queda: $%.2f\n",dinero);
			total = total+dinero;
			break;
	
			case 3:
			dinero=dinero-400;
			printf("Le servi:tequila y cuesta $400 por lo que le queda: $%.2f\n",dinero);
			total = total+dinero;
			break;
			
			case 4:
			dinero=dinero-dinero;
		 	printf("Lo siento se�or...�Saca borrachos uno aqui!");
		 	total=dinero;
		 	break;
		  
		  }
	
} while (dinero > 199);
printf("\nCuanto lo lamento se�or �uno mas desplumado!");}

	}

	if (dinero >= 2000)
	{
		printf("�Adelante se�or! Pase a la zona VIP.\n");

   do{
		
		printf("�Qu� desea beber?\n1. Co�ac $500\n");
		printf("2. Champa�a $750\n3. Wisky Dalmore 18 a�os $1500\n4. Nadddda stoy my ha-ic-py.\n");
		scanf("%d",&bebida);
		
		switch (bebida)
		   {
			case 1:
			dinero=dinero-500;
			printf("Le serv�:co�ac y cuesta $500 por lo que le queda: $%.2f\n",dinero);
			total = total+dinero;
			break;
	
			case 2:
			dinero =dinero-750;
			printf("Le serv�:champa�a y cuesta $750 por lo que le queda: $%.2f\n",dinero);
			total = total+dinero;
			break;
	
			case 3:
			dinero=dinero-1500;
			printf("Le servi:whisky Dalmore 18 a�os y cuesta $1500 por lo que le queda: $%.2f\n",dinero);
			total = total+dinero;
			break;
	
			case 4:
			dinero=dinero-dinero;
			printf("Lo siento se�or...�Saca borrachos uno aqui!");
			total=dinero;
		 	break;
		  }
					
					
					
			}while(dinero >499);
			printf("\nCuanto lo lamento se�or �uno m�s desplumado!");
	}

 
	return 0;
}
	
