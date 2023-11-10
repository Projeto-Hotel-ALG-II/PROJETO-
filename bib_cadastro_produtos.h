#ifndef BIB_CADASTRO_PRODUTOS_H
#define BIB_CADASTRO_PRODUTOS_H

#include <stdio.h>

/*
 * Struct Produtos - Guarda as informa?�es dos produtos
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
 * FUN��O CADASTRA PRODUTO
 */
int cadastro_produto(int mode, str_produtos h);

/*
 * FUN��O ALTERA PRODUTO
 */
int alteraProduto(int mode, str_produtos x);

/*
 * FUN��O PESQUISA PRODUTO
 */
int pesquisaProduto(int mode, int searchCod, str_produtos *prod);

/*
 * FUN��O DELETA PRODUTO
 */
int deletaProduto(int mode, int codigo);

#endif