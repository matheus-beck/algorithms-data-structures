// UNIVERSIDADE FEDERAL DA BAHIA
// MATA40 - ESTRUTURAS DE DADOS E ALGORITMOS I
// Autor: Matheus Beck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int soldados, numSorteado;
	int i, j;
	scanf("%d %d", &soldados, &numSorteado);
	if (1<= numSorteado && numSorteado <= soldados && soldados <= 100){
		char listaSoldados[soldados][200];
		char aux[20];

		for (i = 0; i < soldados; i++){
			//fgets (listaSoldados[i],20,stdin);
			scanf("%s", listaSoldados[i]);
			//Condição que testa o tamanho da string
			if (strlen(listaSoldados[i]) > 20){
				return 1;
			}
			//Condição que testa a utilização exclusiva de letras minusculas usando ASCII
			for (j = 0; j<strlen(listaSoldados[i]);j++){
				if ((int) listaSoldados[i][j] < 97 || (int) listaSoldados[i][j] > 122){
					return 1 ;
				}
			}
		}
		
		// Ordena o vetor de Strings
	   	for (i = 1; i < soldados; i++){
	      	for (j = 0; j < soldados -1 ; j++){
	        	if(strcmp(listaSoldados[j],listaSoldados[j+1]) > 0){
	        	/*Verifica se o caracter diferente na primeira String 
	         	é maior que o caracter da segunda String*/
	            	strcpy(aux,listaSoldados[j]);
	            	strcpy(listaSoldados[j],listaSoldados[j+1]);
	            	strcpy(listaSoldados[j+1],aux);                              
	         	}
	       	}
	   	}

	   	printf("%s\n", listaSoldados[numSorteado-1]);
	    return 0;
	}
	else {
		return 1;
	}
}
	