// UNIVERSIDADE FEDERAL DA BAHIA
// MATA40 - ESTRUTURAS DE DADOS E ALGORITMOS I
// Autor: Matheus Beck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (){
	/*Programa que recebe o ano atual e determina 
	o próximo ano em que o cometa ficará visível*/
	int anoAtual;
	scanf("%d", &anoAtual);
	int anosVisiveis[107];
	anosVisiveis[0] = 1986;
	int j = 0;
	for (int i = 1; i <= 106; i++){
		/*Calcula e guarda em um vetor todos os anos em
		que o Cometa ficará visível entre 1986 e 1042*/
		anosVisiveis[i] = anosVisiveis[j++] + 76;
	}
	for (int i = 0; i <= 106; i++){
		if (anoAtual < anosVisiveis[i]){
			printf("%d\n", anosVisiveis[i]);
			return 0;
		}
	}
	return 1;
}