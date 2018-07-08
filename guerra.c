// UNIVERSIDADE FEDERAL DA BAHIA
// MATA40 - ESTRUTURAS DE DADOS E ALGORITMOS I
// Autor: Matheus Beck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int numSecoes;
	int somaSecoes = 0;
	int aux = 0; 
	int secaoDivisao = 0;
	int i,j;
	scanf("%d", &numSecoes);
	if (numSecoes < 1 || numSecoes > 100000){
		return 1;
	}
	int listaSecoes[numSecoes];

	for (i = 0; i < numSecoes; i++){
		scanf("%d", &listaSecoes[i]);
		if (listaSecoes[i] < 1 || listaSecoes[i] > 100){
			return 1;
		}
		somaSecoes += listaSecoes[i];
	}
	int divisao = somaSecoes/2;

	for (j = 0; j < numSecoes; j++){
		if (aux < divisao){
			aux += listaSecoes[j];
			secaoDivisao +=1;
		}
	}
	printf("%d\n", secaoDivisao);
	return 0;
}