#include <stdio.h>
#include <stdlib.h>
#include "produtos.h"


int main() {
	Produto produtos[100];
	
	// Variaveis do programa
	int continuar = 1;
	int totalProdutos = 0;
//	carregarProdutos(produtos, &totalProdutos);

	


	
	
	//Titulo de apresentação
	printf("\n===============================\n");
	printf("SISTEMA DE CONTROLE DE PRODUTOS");
	printf("\n===============================\n");


	while (continuar == 1){
	
		int opc;
		
		printf("\n1 - Cadastrar produtos\n");
		printf("2 - Consultar produtos\n");
		printf("3 - Verificar estoque\n");
		printf("4 - Calcular valor total do estoque\n");
		printf("5 - Salvar Produtos\n");
		printf("6 - Carregar Produtos\n");
		printf("7 - Sair\n");
		printf("\nDigite uma opcao: ");
		
		if (scanf("%d", &opc) != 1) {
            printf("\nErro: Digite apenas numeros!\n");
            
            // 2. Limpa o caractere inválido que ficou preso no buffer
            while (getchar() != '\n'); 
            continue; // Volta para o início do loop
        }


        // 3. Validação dos números (se é maior que 5 ou menor que 0)
        if (opc < 1 || opc > 7) {
            printf("\nOpcao invalida! Escolha entre 1 e 5.\n");
            continue;
        }
		
			switch(opc){
				case 1:
					cadastrarProduto(produtos, &totalProdutos);
					break;
				
				case 2:
					consultarProduto(produtos, totalProdutos);
					break;
					
				case 3:
					verificarEstoque(produtos, totalProdutos);
					break; 	
						
				case 4:
					calcularValorEstoque(produtos, totalProdutos);
					break;
					
				case 5:
					salvarProdutos(produtos, totalProdutos);
			
					break;
					
				case 6:
					carregarProdutos(produtos, &totalProdutos);
					
					break;
					
				case 7:
					printf("Saindo...");
					continuar = 0;
					break;	
					
				default:
					printf("\nOpcao invalida\n");
				}
		}
	
return 0;
}