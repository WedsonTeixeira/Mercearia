typedef struct{
    int CodigoProduto;
    char Nome[30];
    float Valor;
}Produto;

typedef struct{
    int CodigoVenda;
    int CodigoProduto;
    int Quantidade;
    float ValorVenda;
}Venda;

void MensagemErroArquivo()
{
    system("cls");
    printf("ERRO DE ARQUIVO!\n");
    system("pause");
}

void CadastrarProduto()
{
    FILE *Gravar = fopen("Produtos.dat","ab");
    if(Gravar == NULL)
    {
        MensagemErroArquivo();
    }
    else
    {
        Produto Novo;
        system("cls");
        printf("\t\tCADASTRO DE PRODUTOS\n\n");

        printf("CÓDIGO DO PRODUTO.: ");
        scanf("%d", &Novo.CodigoProduto);
        fflush(stdin);

        printf("NOME DO PRODUTO...: ");
        gets(Novo.Nome);
        fflush(stdin);

        printf("VALOR DO PRODUTO..: ");
        scanf("%f", &Novo.Valor);
        fflush(stdin);

        fwrite(&Novo, sizeof(Produto), 1, Gravar);
        fclose(Gravar);

        printf("\nProduto Cadastrado Com Sucesso.\n\n");
        system("pause");
    }
}

bool VerificarProduto(int Codigo, Produto *Existente)
{
    FILE *Ler = fopen("Produtos.dat","rb");
    if(Ler == NULL)
    {
        MensagemErroArquivo();
    }
    else
    {
        while(fread(Existente, sizeof(Produto), 1, Ler) == 1)
        {
            if(Existente->CodigoProduto == Codigo)
            {
                return true;
            }
        }
        fclose(Ler);
    }
    return false;
}


void CadastrarVenda()
{
    FILE *Gravar = fopen("Vendas.dat","ab");
    if(Gravar == NULL)
    {
        MensagemErroArquivo();
    }
    else
    {
        Venda Nova;
        Produto Existente;

        system("cls");
        printf("\t\tCADASTRO DE VENDAS\n\n");

        printf("CÓDIGO DO PRODUTO.....: ");
        scanf("%d", &Nova.CodigoProduto);
        fflush(stdin);

        if(VerificarProduto(Nova.CodigoProduto, &Existente))
        {
            printf("CÓDIGO DA VENDA.......: ");
            scanf("%d", &Nova.CodigoVenda);
            fflush(stdin);

            printf("QUANTIDADE DO PRODUTO.: ");
            scanf("%d", &Nova.Quantidade);
            fflush(stdin);

            Nova.ValorVenda = Nova.Quantidade * Existente.Valor;

            fwrite(&Nova, sizeof(Venda), 1, Gravar);
            fclose(Gravar);

            printf("\nVenda Cadastrada Com Sucesso.\n\n");
            system("pause");
        }
        else
        {
            fclose(Gravar);
            printf("\nNão foi possivel cadastrar essa venda.\n\n");
            system("pause");
        }
    }
}

void MostrarProdutos()
{
    FILE *Ler = fopen("Produtos.dat","rb");
    if(Ler == NULL)
    {
        MensagemErroArquivo();
    }
    else
    {
        system("cls");
        printf("\t\tTABELA DE PRODUTOS\n\n");

        Produto Existente;
        while(fread(&Existente, sizeof(Produto), 1, Ler) == 1)
        {
            printf("CÓDIGO DO PRODUTO.: %d\n", Existente.CodigoProduto);
            printf("NOME DO PRODUTO...: %s\n", Existente.Nome);
            printf("VALOR DO PRODUTO..: %.2f\n\n", Existente.Valor);
        }
        fclose(Ler);
        system("pause");
    }
}

void MostrarVendas()
{
    FILE *Ler = fopen("Vendas.dat","rb");
    if(Ler == NULL)
    {
        MensagemErroArquivo();
    }
    else
    {
        system("cls");
        printf("\t\tTABELA DE VENDAS\n\n");

        Venda Existente;
        while(fread(&Existente, sizeof(Venda), 1, Ler) == 1)
        {
            printf("CÓDIGO DA VENDA.......: %d\n", Existente.CodigoVenda);
            printf("CÓDIGO DO PRODUTO.....: %d\n", Existente.CodigoProduto);
            printf("QUANTIDADE DO PRODUTO.: %d\n", Existente.Quantidade);
            printf("VALOR DA VENDA........: %.2f\n\n", Existente.ValorVenda);
        }
        fclose(Ler);
        system("pause");
    }
}
