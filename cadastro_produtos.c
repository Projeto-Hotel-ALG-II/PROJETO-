#include <stdio.h>
#include <string.h>
#include "bib_quick_tools.h"
#include "bib_cadastro_produtos.h"

int cadastro_produto(int mode, str_produtos h)
{
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
        fprintf(ptr, "%d|", h.codigo);
        fprintf(ptr, "%s|", h.descricao);
        fprintf(ptr, "%d|", h.estoque);
        fprintf(ptr, "%d|", h.estoque_min);
        fprintf(ptr, "%.2f|", h.preco_custo);
        fprintf(ptr, "%.2f\n", h.preco_venda);

        fclose(ptr);
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
        ptrTemp = fopen("..\\data\\dados_produtos_temp.txt", "w");
        if (ptr == NULL || ptrTemp == NULL)
        {
            return 1;
        }
        break;
    case 2:
        ptr = fopen("..\\data\\dados_produtos.dat", "rb");
        ptrTemp = fopen("..\\data\\dados_produtos_temp.dat", "wb");
        if (ptr == NULL || ptrTemp == NULL)
        {
            return 1;
        }
        break;
    case 3: // usadno alocacao dinamica
        // codigo
        break;
    }

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

    copiarArquivo(ptrTemp, ptr);
    fclose(ptrTemp);
    fclose(ptr);

    return 0;
}

int deletaProduto(int mode, int codigo)
{
    FILE *pF_Prod, *pF_Temp;
    switch (mode)
    {
    case 1:
        pF_Prod = fopen("..\\data\\dados_produtos.txt", "r");
        pF_Temp = fopen("temp.txt", "w");
        if (pF_Prod == NULL || pF_Temp == NULL)
        {
            return 1;
        }
        break;
    case 2:
        pF_Prod = fopen("..\\data\\dados_produtos.dat", "rb");
        pF_Temp = fopen("temp.dat", "wb");
        if (pF_Prod == NULL || pF_Temp == NULL)
        {
            return 1;
        }
        break;
    case 3: // alocacao dinamica

        break;
    }

    if(mode != 3){
        while(fscanf(pF_Prod, "%d|%[^|]|%d|%d|%f|%f\n") != EOF){
            if() /////////   <<<<================================================== MUDA AQUI VIU!
        }
    }

    fclose(pF_Prod);
    fclose(pF_Temp);
    return 0;
}