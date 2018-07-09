// UNIVERSIDADE FEDERAL DA BAHIA
// MATA40 - ESTRUTURAS DE DADOS E ALGORITMOS I
// Autor: Matheus Beck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int divisao(int capitalInicial, int maxInvestimento){
	if (maxInvestimento == 1){
		return capitalInicial;
	}
	if (capitalInicial <= maxInvestimento){
		return 1;
	}
	if (capitalInicial%2 == 0){
		return 2* divisao(capitalInicial/2, maxInvestimento);
	}
	else if (capitalInicial%2 != 0){
		return divisao(capitalInicial/2,maxInvestimento) + divisao((capitalInicial /2) + 1, maxInvestimento);
	}
	//return 1;
}

int main(){
	int capitalInicial, maxInvestimento, i;
	int empresas = 1;
	do {
		scanf("%d %d", &capitalInicial, &maxInvestimento);
		if (capitalInicial == 0 && maxInvestimento == 0){
			return 0;
		}
		if (capitalInicial < 1 || capitalInicial > 1000000 || maxInvestimento < 1 || maxInvestimento > 1000000){
			return 0;
		}
		int empresas = divisao(capitalInicial, maxInvestimento);
		printf("%d\n",empresas);
	} while (capitalInicial != 0 && maxInvestimento != 0);	

	return 0;
}