#ifndef PRODUTOS_H
#define PRODUTOS_H
typedef struct {
	int codigo;
	char nome[50];
	float preco;
	int quantidade;
} Produto;

void cadastrarProduto(Produto produtos[], int *totalProdutos);

void consultarProduto(Produto produtos[], int totalProdutos);

void verificarEstoque(Produto produtos[], int totalProdutos);

void calcularValorEstoque(Produto produtos[], int totalProdutos);

void salvarProdutos(Produto produtos[], int totalProdutos);

void carregarProdutos(Produto produtos[], int *totalProdutos);

int codigoExiste(Produto produtos[], int totalProdutos, int codigo);

#endif