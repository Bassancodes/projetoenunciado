#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/estoque.h"

void cadastrarProduto() {
    Produto p;
    FILE *arquivo = fopen("data/produtos.dat", "ab");

    if (!arquivo) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    printf("Código do produto: ");
    scanf("%d", &p.codigo);
    getchar();  

    printf("Nome do produto: ");
    fgets(p.nome, sizeof(p.nome), stdin);
    p.nome[strcspn(p.nome, "\n")] = 0; 

    printf("Descrição do produto: ");
    fgets(p.descricao, sizeof(p.descricao), stdin);
    p.descricao[strcspn(p.descricao, "\n")] = 0;

    printf("Quantidade em estoque: ");
    scanf("%d", &p.quantidade);

    printf("Preço unitário: ");
    scanf("%f", &p.preco);

    fwrite(&p, sizeof(Produto), 1, arquivo);
    fclose(arquivo);

    printf("\nProduto cadastrado com sucesso!\n");
}

void exibirProduto(Produto p) {
    printf("\n[Código: %d] %s\n", p.codigo, p.nome);
    printf("Descrição: %s\n", p.descricao);
    printf("Quantidade: %d | Preço: R$ %.2f\n", p.quantidade, p.preco);
}

int main() {
    int opcao;

    do {
        printf("\n1 - Cadastrar Produto\n0 - Sair\nOpção: ");
        scanf("%d", &opcao);
        getchar(); // Limpa buffer

        switch (opcao) {
            case 1:
                cadastrarProduto();
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }

    } while (opcao != 0);

    return 0;
}
