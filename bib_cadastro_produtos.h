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



#endif