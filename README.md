# SISTEMA-CONTROLE-DE-PRODUTOS
Projeto academico criado na Universidade para entendimento e aprendizado em programação e linguagem C
 
## Funcionalidades
 
- Cadastro de produtos
- Consulta de produtos por código
- Verificação de estoque
- Cálculo do valor total do estoque
- Validação de entradas do usuário
- Prevenção de códigos duplicados
- Salvamento dos dados em arquivo texto
- Carregamento automático dos produtos salvos
 
 
## Tecnologias Utilizadas
 
- Linguagem C
- Estruturas (`struct`)
- Vetores
- Funções
- Ponteiros
- Manipulação de Arquivos (`FILE`)
- Modularização com arquivos `.h` e `.c`
 
 
## Estrutura do Projeto
 
CadProd/
│
├── main.c
├── produtos.c
├── produtos.h
├── produtos.txt
└── README.md

## Como Executar

### Utilizando o GCC

1. Abra o terminal na pasta do projeto.

2. Compile o programa:

gcc main.c produtos.c -o sistema

## Adicionando os Arquivos ao Projeto no Dev-C++

Caso o projeto seja aberto sem os arquivos associados, siga os passos abaixo:

1. Abra o arquivo de projeto:
2. Projeto → Adicionar ao Projeto
3. selecione os arquivos:
   main.c
  produtos.c
  produtos.h
4.Após adicionar os arquivos, a estrutura do projeto deverá ficar semelhante a:
CadProd
│
├── main.c
├── produtos.c
└── produtos.h
5. Executar → Compilar e Executar
