#ifndef BIB_CADASTRO_PRODUTOS_H
#define BIB_CADASTRO_PRODUTOS_H

#include <stdio.h>

/*
 * Struct Produtos - Guarda as informa?„es dos produtos
 */
typedef struct
{
    int codigo;
    char descricao[40];
    int estoque;
    int estoque_min;
    float preco_custo;
    float preco_venda;
} str_produtos;

/*
 * FUN€ÇO CADASTRA PRODUTO
 */
int cadastro_produto(int mode, str_produtos h);

/*
 * FUN€ÇO ALTERA PRODUTO
 */
int alteraProduto(int mode, str_produtos x);

/*
 * FUN€ÇO PESQUISA PRODUTO
 */
int pesquisaProduto(int mode, int searchCod, str_produtos *prod);

/*
 * FUN€ÇO DELETA PRODUTO
 */
int deletaProduto(int mode, int codigo);

#endif