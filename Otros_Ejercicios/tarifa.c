#include <stdio.h>

int main(){

	int numeroMinutos, tarifa;

	printf("Ingrese el numero de minutos de permanencia:");
	scanf("%d",&numeroMinutos);

	if (numeroMinutos <= 30){
    		tarifa = numeroMinutos * 35;
		}
	else if (numeroMinutos <= 120){
        	tarifa = (30 * 35) + (numeroMinutos - 30) * 30;
    		}
		else if (numeroMinutos <= 240){
            		tarifa = (30 * 35) + (90 * 30) + (numeroMinutos - 120) * 25;
			}
        		else{
            			tarifa = (30 * 35) + (90 * 30) + (120 * 25) + (numeroMinutos - 240) * 20;
			}


	printf("El costo total es: %d pesos",tarifa);
	return 0;
}
