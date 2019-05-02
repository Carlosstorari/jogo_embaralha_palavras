/**
Autor: Carlos H. Storari
 Jogo em que o jogador digita uma palavra 
e as letras são embaraladas para que um outro 
jogador adivinhe qual é a palavra
**/
#include<stdio.h>
#include<stdlib.h>  //Declara biblbiotecas necessarias
#include<string.h>
#include<time.h>
#include"conio.h"

int main(){
	char palavra[100],resposta[100]; 
	
	int tam , i ,y, x, test,jogador1 = 0,jogador2 = 0,turno = 1  ;
	
	
	while(jogador1!=3||jogador2!=3){ //Começo do laco 
		textbackground(7); //Deixa a tela cinza
		system("clear");//Limpa a tela
		textcolor(0);//Faz as letras ficarem pretas
		printf("Jogador1: %d\t\t\t\t\t\t\tJogador2: %d",jogador1,jogador2);//Mostra a pontuação dos jogadores
		gotoxy(30,5);
		printf(" Digite uma palavra: ");
		gets(palavra);//Lê a palavra 
		system("clear");//Limpa tela para não mostrar a palavra digitada
		tam = strlen(palavra);//Conta os caracteres da palavra
		int vet[tam];//Vetor para receber indices aleatorios da string Palavra
		for(y = 0;y < tam; y++){
			vet[y]=101;//Preenche o espaço do vetor
		}
		printf("Jogador1: %d\t\t\t\t\t\t\tJogador2: %d",jogador1,jogador2);
		printf("\n\n\n\n");
		for(i=0;i<tam;i++)
				{
				test=0;
				while(test==0)//Inicio do teste para evitar indices repetidos
				{
					test = 1;
					Sleep(100);//Iniciamos o tempo de contagem
					srand(time(NULL));//Gera numero aleatorio para o indice
					vet[i]=(rand())%tam;//Atribui numero aleatorio ao vetor de indices
					 
					
						for(x = 0; x < tam ; x++){
							if(vet[x] == vet[i]&&i!=x) { //Verifica valores iguais em indices diferentes
								Sleep(100);
								srand(time(NULL));
								vet[i]=(rand())%tam;
								test=0;
								x = tam;
								}
						}
						
				
					
				 
				}
			   
				printf("%c  \t",palavra[vet[i]]);//Imprime conteudo do indice
			  
				   
				}
				
				
				gotoxy(30,10);
				printf(" Qual eh a palavra? ");
				printf("Jogador %d   ",turno);//Mostra a vez do jogador jogar
				gets(resposta);//Lê resposta
			
	
			
				if(strcmp(resposta,palavra)== 0){//Testa se as strings são iguais
					printf("\nCerta resposta\n\n");
					if(turno == 1){
						jogador1++;//Adiciona ponto ao jogador 1
					}
					else if(turno == 2){
						jogador2++;//Adiciona ponto ao jogador 2
					}
				}
				else{
					printf("\n\t\t\t\t\tVoce errou");
					Sleep(2000);
				}
				
			
				if(turno == 1){
					turno = 2;//Muda para turno 2
				}
				else if(turno == 2){
					turno = 1;//Muda para turno 1
				}
				if(jogador1==3||jogador2==3)//Termina o jogo 
					break;
	}
	system("clear");

	if(jogador1==3){
		gotoxy(30,10);
		printf("Jogador 1 Venceu");
		printf("\n\n\n");
	}
	else if(jogador2==3){
		gotoxy(30,10);
		printf("Jogador 2 Venceu");
		printf("\n\n\n");
		}
	getchar();
	return 0;
}