#ifndef ESTOQUE_H
#define ESTOQUE_H

typedef struct {
    int codigo;
    char nome[50];
    char descricao[100];
    int quantidade;
    float preco;
} Produto;

void cadastrarProduto();
void exibirProduto(Produto p);

#endif
