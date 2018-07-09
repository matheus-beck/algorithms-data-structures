// UNIVERSIDADE FEDERAL DA BAHIA
// MATA40 - ESTRUTURAS DE DADOS E ALGORITMOS I
// Autor: Matheus Beck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int qtdDoc, qtdRes;
	int i, qtdO; //Quantidade de caracteres "o" que serão exibidos
	do{
		(scanf("%d %d", &qtdDoc, &qtdRes));
		if (qtdDoc == 0 && qtdRes == 0){
			return 0;
		}
		if (qtdDoc < 1 || qtdDoc > 1000000 || qtdRes < 1 || qtdRes > 100){
			return 0;
		}
		if (qtdDoc % qtdRes == 0){
			qtdO = (qtdDoc / qtdRes) - 6;
		}
		else{
			qtdO = (qtdDoc / qtdRes) - 5;
		}
		if (qtdO > 14){
			printf("Poooooooooooooooodle\n");
		}
		else {
			printf("Poo");
			for (i = 0; i<qtdO; i++){
				printf("o");
			}
			printf("dle\n");
		}
	} while (qtdDoc != 0 && qtdRes != 0);
	return 0;
}