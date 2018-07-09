// UNIVERSIDADE FEDERAL DA BAHIA
// MATA40 - ESTRUTURAS DE DADOS E ALGORITMOS I
// Autor: Matheus Beck

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int linhas, colunas, instrucoes;
	int i,j;

	while(scanf("%d %d %d", &linhas, &colunas, &instrucoes)){
		if (linhas == 0 && colunas == 0 && instrucoes == 0){
			return 0;
		}
		if (linhas < 1 || colunas > 100 || instrucoes < 1 || instrucoes > 50000){
			return 0;
		}
		char arena[linhas][colunas];
		char instr[instrucoes];
		for (i = 0; i < linhas; i++){
			for (j = 0; j < colunas; j++){
				scanf(" %c", &arena[i][j]);
			}
		}
		for (i = 0; i< instrucoes; i++){
			scanf(" %c", &instr[i]);
		}
		/*
		for (i = 0; i < linhas; i++){
			for (j = 0; j < colunas; j++){
				printf(" %c", arenana[i][j]);
			}
			printf("\n");
		}
		for (i = 0; i< instrucoes; i++){
			printf(" %c\n", instr[i]);
		} */
		//int qtdFigurinhas = executaRali(arenana, instr, linhas, colunas, instrucoes);
		int posX, posY = 0; //i e j
		int proximoX, proximoY = 0;
		int i,j,z;
		int figurinhas = 0;
		//Encontra a posicao inicial
		for (i = 0; i<linhas; i++){
			for (j = 0; j<colunas; j++){
				if (arena[i][j] == 'N'){
					posX = i;
					posY = j;
					proximoX = posX - 1;
					proximoY = posY;
				} 
				if (arena[i][j] == 'S'){
					posX = i;
					posY = j;
					proximoX = posX + 1;
					proximoY = posY;
				}
				if (arena[i][j] == 'L'){
					posX = i;
					posY = j;
					proximoX = posX;
					proximoY = posY + 1;
				}
				if (arena[i][j] == 'O'){
					posX = i;
					posY = j;
					proximoX = posX;
					proximoY = posY - 1;
				}
			}
		}
		/*
		printf("Pos X: %d\n", posX);
		printf("Pos Y: %d\n", posY);
		printf("Prox X: %d\n", proximoX);
		printf("Prox Y: %d\n", proximoY);
		*/
		//Executa as instruçoes
		for (z = 0; z< instrucoes; z++){
			//printf("Proxima instrução: %c\n", instr[z]);
			switch (instr[z]){
				case 'D':
					if (arena[posX][posY] == 'N'){
						proximoX +=1;
						proximoY +=1;
						arena[posX][posY] = 'L';
					}
						
					else if (arena[posX][posY] == 'S'){
						proximoX -=1;
						proximoY -=1;
						arena[posX][posY] = 'O';
					}
						
					else if (arena[posX][posY] == 'L'){
						proximoX +=1;
						proximoY -=1;
						arena[posX][posY] = 'S';
					}
						
					else if (arena[posX][posY] == 'O'){
						proximoX -=1;
						proximoY +=1;
						arena[posX][posY] = 'N';
					}
					break;
				case 'F':
					if (arena[proximoX][proximoY] == '.'){
						if (proximoX < 0 || proximoX >= linhas || proximoY < 0 || proximoY >= colunas){
							break; // limite da arenana
						}
						arena[proximoX][proximoY] = arena[posX][posY];
						int auxX = posX;
						int auxY = posY;
						posX = proximoX;
						posY = proximoY;
						if (proximoX<auxX && proximoY == auxY){
							proximoX -=1; 	
						}
							
						else if (proximoX>auxX && proximoY == auxY){
							proximoX +=1;
						}
							
						else if (proximoX == auxX && proximoY > auxY){
							proximoY +=1;
						}
							
						else if (proximoX == auxX && proximoY < auxY){
							proximoY -=1;
						}
						arena[auxX][auxY] = '.';
					}
					else if (arena[proximoX][proximoY] == '*'){
						if (proximoX < 0 || proximoX >= linhas || proximoY < 0 || proximoY >= colunas){
							break; // limite da arenana
						}
						arena[proximoX][proximoY] = arena[posX][posY];
						figurinhas++;
						int auxX = posX;
						int auxY = posY;
						posX = proximoX;
						posY = proximoY;
						if (proximoX<auxX && proximoY == auxY){
							proximoX -=1; 	
						}
							
						else if (proximoX>auxX && proximoY == auxY){
							proximoX +=1;
						}
							
						else if (proximoX == auxX && proximoY > auxY){
							proximoY +=1;
						}
							
						else if (proximoX == auxX && proximoY < auxY){
							proximoY -=1;
						}
						arena[auxX][auxY] = '.';
					}
					else if (arena[proximoX][proximoY] == '#'){
						//Não faça nada
					}
					break;
				case 'E':
					if (arena[posX][posY] == 'N'){
						proximoX +=1;
						proximoY -=1;
						arena[posX][posY] = 'O';
					}
					else if (arena[posX][posY] == 'S'){
						proximoX -=1;
						proximoY +=1;
						arena[posX][posY] = 'L';
					}
					else if (arena[posX][posY] == 'L'){
						proximoX -=1;
						proximoY -=1;
						arena[posX][posY] = 'N';
					}
						
					else if (arena[posX][posY] == 'O'){
						proximoX +=1;
						proximoY +=1;
						arena[posX][posY] = 'S';
					}
						
					break;
				default:
					//printf("Não reconheci a instrução\n");
					break;
			}
			/*
			printf("Após a instrução %d:\n", z);
			for (i = 0; i<linhas; i++){
				for (j = 0; j<colunas;j++){
					printf("%c",arena[i][j]);
				}
				printf("\n");
			}
			printf("Pos X: %d\n", posX);
			printf("Pos Y: %d\n", posY);
			printf("Prox X: %d\n", proximoX);
			printf("Prox Y: %d\n", proximoY);
			*/
		}/*
		for (i = 0; i < linhas; i++){
			for (j = 0; j < colunas; j++){
				printf("%c", arena[i][j]);
			}
			printf("\n");
		}*/
		printf("%d\n", figurinhas);
		
	}
	return 0;
}