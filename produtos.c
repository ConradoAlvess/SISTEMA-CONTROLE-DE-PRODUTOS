#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"

void cadastrarProduto(Produto produtos[], int *totalProdutos){
					//Verifica se temos 100 ou mais produtos cadastrados, evitando estouro de buffer/memoria 
					if(*totalProdutos >= 100){
						
						printf("\nLimite maximo de produtos atingido!\n");
						printf("Nao e possivel cadastrar mais produtos.\n");
						
						}
	
					printf("\n     Produto     \n");


					// Loop que "insiste" até o usuário digitar um número
			        while (1) {
			            printf("Codigo do produto: ");
			            
			            //Identifica se o usuario digitou letra ou numero, se digitou numero entramos no for
			            if (scanf("%d", &produtos[*totalProdutos].codigo) == 1) {
			            
					
							if (codigoExiste(produtos, *totalProdutos, produtos[*totalProdutos].codigo)) {
							printf("\nErro: Codigo ja cadastrado!\n\n");
							continue;
							}
							
							break;
							
						} else {
						printf("\nErro: Digite apenas numeros!\n\n");
						while (getchar() != '\n');
						}
        			}	
					
					while (1) {
				    printf("Nome do produto: ");
				    
				    // Lê o texto. O " %49[^\n]" lê espaços e limita o tamanho para não quebrar a memória
				    scanf(" %49[^\n]", produtos[*totalProdutos].nome); 
				    
				    int nomeValido = 1; // Começa assumindo que o nome é válido
				
				    // Passa por cada letra do texto até chegar no fim da string ('\0')
				    for (int i = 0; produtos[*totalProdutos].nome[i] != '\0'; i++) {
				        
				        // Verifica manualmente se o caractere atual é um número entre '0' e '9'
				        if (produtos[*totalProdutos].nome[i] >= '0' && produtos[*totalProdutos].nome[i] <= '9') {
				            nomeValido = 0; // Se achou um número, invalida o nome
				            break;          // Sai do for, pois já sabemos que está errado
				        }
				    }


					    if (nomeValido) {
					        break; // Sucesso! O nome não tem números. Sai do while.
					    } else {
					        printf("\nErro: O nome do produto nao pode conter numeros!\n\n");
					    }
					}


	
					while (1) {  
						printf("Preco do produto: R$");
			            
			            	if (scanf("%f", &produtos[*totalProdutos].preco) == 1) {
			                // Se digitou um float com sucesso, sai do loop do código
			                	break; 
            				} else {
				                // Se digitou letra, limpa o buffer e avisa o erro
				                printf("\nErro: Digite apenas o preco do produto\n\n");
				                while (getchar() != '\n'); 
				                // O loop continua e pede o código novamente
            			}
        			}
					
					while (1) {  
						printf("Quantidade em estoque: ");
			            
			            	if (scanf("%d", &produtos[*totalProdutos].quantidade) == 1) {
			                // Se digitou um número com sucesso, sai do loop do código
			                	break; 
            				} else {
				                // Se digitou letra, limpa o buffer e avisa o erro
				                printf("\nErro: Digite apenas a quantidade em estoque!\n\n");
				                while (getchar() != '\n'); 
				                // O loop continua e pede o código novamente
            			}
        			}
        			
        			//Verifica na variavel totalProdutos se o limite de produtos já foi atingido
						
					(*totalProdutos)++; 
					
	
}

void consultarProduto(Produto produtos[], int totalProdutos){
					printf("\n===============================");
					printf("\n     Consulta de produtos     \n");
					printf("===============================\n");
					
					int consultaCod;
					int encontrado = 0;
				
					while (1) {
					printf("\nDigite o codigo do produto: ");
			            
			            if (scanf("%d", &consultaCod) == 1) {
			                // Se digitou um número com sucesso, sai do loop do código
			                break; 
            			} else {
			                // Se digitou letra, limpa o buffer e avisa o erro
			                system("cls");
			                printf("\nErro: Digite apenas numeros!\n\n");
			                while (getchar() != '\n'); 
			                // O loop continua e pede o código novamente
            			}
        			}	
					system("cls");
					
						for(int i = 0; i < totalProdutos; i++){
							if(consultaCod == produtos[i].codigo){
						
							printf("\n*******************************\n");
							printf("Nome do produto: %s\n", produtos[i].nome);


							printf("\nCodigo do produto: %d\n",  produtos[i].codigo);
							
							printf("Preco do produto: R$%.2f\n", produtos[i].preco);
						
							printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
							printf("===============================\n");
						
							
							encontrado = 1;
							break; 	
						}
					}
					if (encontrado == 0){
						printf("\nCodigo do produto nao existe\n");
					}
					
}

void verificarEstoque(Produto produtos[], int totalProdutos){
	system("cls");
					printf("\n===============================");
					printf("\n     Verificar Estoque     \n");
					printf("===============================\n");
					
					//verifica se estoque está vazio
					if (totalProdutos == 0){
						
						printf("\n     Estoque vazio!     \n");
					}
					
					
					    for(int i = 0; i < totalProdutos; i++){
						
							printf("\n*******************************\n");


							printf("Nome do produto: %s\n", produtos[i].nome);
							
							printf("\nCodigo do produto: %d\n", produtos[i].codigo);
							
							printf("Preco do produto: R$%.2f\n", produtos[i].preco);
						
							printf("Quantidade em estoque: %d\n", produtos[i].quantidade);
							
							if(produtos[i].quantidade == 0){
								printf("\n     ESTOQUE ESGOTADO     \n");
							} 
							else if(produtos[i].quantidade <= 5){
								printf("\n     ESTOQUE BAIXO     \n");
							}
							else{
								printf("\n     ESTOQUE NORMAL     \n");
							}
							printf("===============================\n");
					}
}

void calcularValorEstoque(Produto produtos[], int totalProdutos){
	system("cls");
					printf("\n=== Valor Estoque Total ===\n");
					
					float valorTotalEstoq = 0;
					
					for(int i = 0; i < totalProdutos; i++){
						valorTotalEstoq += produtos[i].preco * produtos[i].quantidade;
			      	}
					
					printf("\nO valor total do estoque e: R$%.2f\n", valorTotalEstoq);
}

int codigoExiste(Produto produtos[], int totalProdutos, int codigo){
						
													
						for(int i = 0; i < totalProdutos; i++) {
								//Se o codigo do produto digitado pelo usuario já existir exibira uma mensagem de aviso
								if (produtos[i].codigo == codigo) {
										return 1;
							}
						}
					return 0;	
						
}

void salvarProdutos(Produto produtos[], int totalProdutos){
	FILE *arquivo;
	
	arquivo = fopen ("produtos.txt", "w");
	
	if (arquivo == NULL){
		printf("\nErro ao criar arquivo!\n");
		return;
	}
	
	for(int i = 0; i < totalProdutos; i++){
		
		fprintf(
			arquivo,
			"%d;%s;%.f;%d\n",
			produtos[i].codigo,
			produtos[i].nome,
			produtos[i].preco,
			produtos[i].quantidade
		);
	}
	
	fclose(arquivo);
	
	printf("\nProdutos salvos com sucesso!\n");
}

void carregarProdutos(Produto produtos[], int *totalProdutos){
		FILE *arquivo;
		
		arquivo = fopen("produtos.txt", "r");
		
		if (arquivo == NULL){
			printf("\nArquivo nao encontrado!\n");
			return;
		}
		
		*totalProdutos = 0;
		
		while(
			fscanf(
				arquivo,
				"%d;%49[^;];%f;%d\n",
				&produtos[*totalProdutos].codigo,
				produtos[*totalProdutos].nome,
				&produtos[*totalProdutos].preco,
				&produtos[*totalProdutos].quantidade
			)  == 4
		)
		{
			(*totalProdutos)++;
		}
		
		fclose(arquivo);
		
		printf("\nProdutos carregados com sucesso!\n");
	}
