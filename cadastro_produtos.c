#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_quick_tools.h"
#include "bib_cadastro_produtos.h"

int cadastro_produto(int mode, str_produtos p)
{
    FILE *pF_Prod;
    switch (mode)
    {
    case 1:
        pF_Prod = fopen("..\\data\\dados_produtos.txt", "w");
        if (pF_Prod == NULL)
        {
            return 1;
        }
        break;
    case 2:
        pF_Prod = fopen("..\\data\\dados_produtos.dat", "wb");
        if (pF_Prod == NULL)
        {
            return 1;
        }
        break;
    case 3: // alocacao dinamica

        break;
    }

    if (mode != 3)
    {
        // escrevendo dados recebidos no arquivo
        fprintf(pF_Prod, "%d|", p.codigo);
        fprintf(pF_Prod, "%s|", p.descricao);
        fprintf(pF_Prod, "%d|", p.estoque);
        fprintf(pF_Prod, "%d|", p.estoque_min);
        fprintf(pF_Prod, "%.2f|", p.preco_custo);
        fprintf(pF_Prod, "%.2f\n", p.preco_venda);

        fclose(pF_Prod);
    }
    else
    {
    }

    return 0;
}

int pesquisaProduto(int mode, int searchCod, str_produtos *prod)
{
    str_produtos prodTmp;
    FILE *ptr;
    switch (mode)
    {
    case 1:
        ptr = fopen("..\\data\\dados_produtos.txt", "w");
        if (ptr == NULL)
        {
            return 1;
        }
        break;
    case 2:
        ptr = fopen("..\\data\\dados_produtos.dat", "wb");
        if (ptr == NULL)
        {
            return 1;
        }
        break;
    case 3: // alocacao dinamica

        break;
    }

    if (mode != 3)
    {
        while (fscanf(ptr, "%d|%[^|]|%d|%d|%f|%f\n", &prodTmp.codigo, prodTmp.descricao, &prodTmp.estoque, &prodTmp.estoque_min, &prodTmp.preco_custo, &prodTmp.preco_venda) != EOF)
        {
            if (prodTmp.codigo == searchCod)
            {
                prod->codigo = prodTmp.codigo;
                strcpy(prod->descricao, prodTmp.descricao);
                prod->estoque = prodTmp.estoque;
                prod->estoque_min = prodTmp.estoque_min;
                prod->preco_custo = prodTmp.preco_custo;
                prod->preco_venda = prodTmp.preco_venda;
                fclose(ptr);
                return 0;
            }
        }

        fclose(ptr);
    }
    else
    {
    }

    return 1;
}

int alteraProduto(int mode, str_produtos x)
{
    str_produtos temp;
    FILE *ptr, *ptrTemp;
    switch (mode)
    {
    case 1: // Usando txt
        ptr = fopen("..\\data\\dados_produtos.txt", "r");
        ptrTemp = fopen("..\\data\\temp.txt", "w");
        if (ptr == NULL || ptrTemp == NULL)
        {
            return 1;
        }
        break;
    case 2:
        ptr = fopen("..\\data\\dados_produtos.dat", "rb");
        ptrTemp = fopen("..\\data\\temp.dat", "wb");
        if (ptr == NULL || ptrTemp == NULL)
        {
            return 1;
        }
        break;
    case 3: // usadno alocacao dinamica
        // codigo
        break;
    }

    if (mode != 3)
    {
        while (fscanf(ptr, "%d|%[^|]|%d|%d|%f|%f\n", &temp.codigo, temp.descricao, &temp.estoque, &temp.estoque_min, &temp.preco_custo, &temp.preco_venda) != EOF)
        {
            if (x.codigo != temp.codigo)
            {
                fprintf(ptrTemp, "%d|", temp.codigo);
                fprintf(ptrTemp, "%s|", temp.descricao);
                fprintf(ptrTemp, "%d|", temp.estoque);
                fprintf(ptrTemp, "%d|", temp.estoque_min);
                fprintf(ptrTemp, "%.2f|", temp.preco_custo);
                fprintf(ptrTemp, "%.2f\n", temp.preco_venda);
            }
            else
            {
                fprintf(ptrTemp, "%d|", x.codigo);
                fprintf(ptrTemp, "%s|", x.descricao);
                fprintf(ptrTemp, "%d|", x.estoque);
                fprintf(ptrTemp, "%d|", x.estoque_min);
                fprintf(ptrTemp, "%.2f|", x.preco_custo);
                fprintf(ptrTemp, "%.2f\n", x.preco_venda);
            }
        }

        fclose(ptrTemp);
        fclose(ptr);
    }

    if (mode == 1)
    {
        ptr = fopen("..\\data\\dados_produtos.txt", "w");
        ptrTemp = fopen("..\\data\\dados_produtos_temp.txt", "r");
    }
    else if (mode == 2)
    {
        ptr = fopen("..\\data\\dados_produtos.txt", "wb");
        ptrTemp = fopen("..\\data\\dados_produtos_ temp.txt", "rb");
    }
    else
    {
        // alocacao
    }

    if (mode != 3)
    {
        copiarArquivo(ptrTemp, ptr);

        fclose(ptrTemp);
        fclose(ptr);
    }

    return 0;
}

int deletaProduto(int mode, int codigoDel)
{
    FILE *pF_Prod, *pF_Temp;
    switch (mode)
    {
    case 1:
        pF_Prod = fopen("..\\data\\dados_produtos.txt", "r");
        pF_Temp = fopen("..\\data\\temp.txt", "w");
        if (pF_Prod == NULL || pF_Temp == NULL)
        {
            return 1;
        }
        break;
    case 2:
        pF_Prod = fopen("..\\data\\dados_produtos.dat", "rb");
        pF_Temp = fopen("..\\data\\temp.dat", "wb");
        if (pF_Prod == NULL || pF_Temp == NULL)
        {
            return 1;
        }
        break;
    case 3: // alocacao dinamica

        break;
    }

    str_produtos p;

    if (mode != 3)
    {
        while (fscanf(pF_Prod, "%d|%[^|]|%d|%d|%f|%f\n", &p.codigo, p.descricao, &p.estoque, &p.estoque_min, &p.preco_custo, &p.preco_venda) != EOF)
        {
            if (p.codigo != codigoDel)
            {
                // reescrevendo arquivo original em arquivo tempor†rio
                fprintf(pF_Temp, "%d|", p.codigo);
                fprintf(pF_Temp, "%s|", p.descricao);
                fprintf(pF_Temp, "%d|", p.estoque);
                fprintf(pF_Temp, "%d|", p.estoque_min);
                fprintf(pF_Temp, "%.2f|", p.preco_custo);
                fprintf(pF_Temp, "%.2f\n", p.preco_venda);
            }
            else
            {
                // c¢digo 0 indica que o produto foi exclu°do
                fprintf(pF_Temp, "0|");
                fprintf(pF_Temp, "%s|", p.descricao);
                fprintf(pF_Temp, "%d|", p.estoque);
                fprintf(pF_Temp, "%d|", p.estoque_min);
                fprintf(pF_Temp, "%.2f|", p.preco_custo);
                fprintf(pF_Temp, "%.2f\n", p.preco_venda);
            }
        }

        fclose(pF_Prod);
        fclose(pF_Temp);
    }
    else
    {
    }

    // C‡DIGO ABAIXO COPIA OS DADOS DO ARQUIVO TEMPORµRIO PARA O ORIGINAL
    switch (mode)
    {
    case 1:
        pF_Prod = fopen("..\\data\\dados_produtos.txt", "w");
        pF_Temp = fopen("..\\data\\temp.txt", "r");
        if (pF_Prod == NULL || pF_Temp == NULL)
        {
            exit(1);
        }
        break;
    case 2:
        pF_Prod = fopen("..\\data\\dados_produtos.txt", "wb");
        pF_Temp = fopen("..\\data\\temp.txt", "rb");
        if (pF_Prod == NULL || pF_Temp == NULL)
        {
            exit(1);
        }
        break;
    }

    if (mode != 3)
    {
        copiarArquivo(pF_Temp, pF_Prod);

        fclose(pF_Prod);
        fclose(pF_Temp);
    }

    return 0;
}