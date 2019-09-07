#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>
#include "Biblioteca.h"

int main()
{
    setlocale(LC_ALL,"Portuguese");
    int Opcao;

    do
    {
        system("cls");
        printf("\t\tVENDE TUDO MAIS BARATO\n\n");
        printf("1 - Novo Produto\n");
        printf("2 - Nova Venda\n");
        printf("3 - Mostrar Produtos\n");
        printf("4 - Mostrar Vendas\n");
        printf("5 - Sair\n\n");
        printf("Informe a Opção: ");
        scanf("%d", &Opcao);

        switch(Opcao)
        {
            case 1:
                CadastrarProduto();
                break;
            case 2:
                CadastrarVenda();
                break;
            case 3:
                MostrarProdutos();
                break;
            case 4:
                MostrarVendas();
                break;
        }

    }while(Opcao != 5);
}
