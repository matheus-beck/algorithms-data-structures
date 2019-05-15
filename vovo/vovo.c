// UNIVERSIDADE FEDERAL DA BAHIA
// MATA40 - ESTRUTURAS DE DADOS E ALGORITMOS I
// Autor: Matheus Beck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int numDepositos;
	int depJ, depZ, i;
	int diferenca = 0;
	int j = 0;
	while (scanf("%i", &numDepositos) == 1){
		if (numDepositos == 0){
			return 0;
		}
		int cofrinho[numDepositos];
		for (i = 0; i < numDepositos; i++){
			scanf("%d %d", &depJ, &depZ);
			diferenca = depJ - depZ;
			if (i >= 1){
				cofrinho[i] = cofrinho[i-1] + diferenca; 
			}
			else {
				cofrinho [i] = diferenca;
			}
		}
		j++;
		printf("Teste %d\n", j);
		for (i = 0; i < numDepositos; i++){
			printf("%d\n", cofrinho[i]);
		}
		printf("\n");			
	}
	return 0;
}