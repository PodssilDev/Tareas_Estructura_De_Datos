#include <stdio.h>
float num1, num2, resultado;
int numero;
int main()
{
	printf("Ingrese el primer numero\n");
	scanf("%f",&num1);
	printf("Ingrese el segundo numero\n");
	scanf("%f",&num2);
	printf("Ingrese un numero que represente la operacion\n");
	printf("El numero 1 representa a la SUMA\n");
	printf("El numero 2 representa a la RESTA\n");
	printf("El numero 3 representa a la MULTIPLICACION\n");
	printf("El numero 4 representa a la DIVISION\n");
	scanf("%d",&numero);
	if (numero == 1){
		resultado = num1 + num2;
		printf("El resultado de la suma es %f\n", resultado);
	}
	else if (numero == 2){
		resultado = num1 - num2;
		printf("El resultado de la resta es %f\n", resultado);
	}
	else if (numero == 3){
		resultado = num1 * num2;
		printf("El resultado de la multiplicacion es %f\n", resultado);
	}
	else if (numero == 4){
		resultado = num1 / num2;
		printf("El resultado de la division es %f\n", resultado);
	}
	else{
		printf("Ingreso un numero invalido, ejecute el programa denuevo.\n");
	}
	return 0;
}