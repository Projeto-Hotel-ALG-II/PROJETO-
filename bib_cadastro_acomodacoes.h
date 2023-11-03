#ifndef BIB_CADASTRO_ACOMODACOES_H
#define BIB_CADASTRO_ACOMODACOES_H

#include <stdio.h>

/*
 * Sub-Struct de 'Acomodacoes' - Guarda as caracter­sticas das acomoda?„es e ? acessada atrav?s da struct Acomodacoes
 */
typedef struct
{
    int codigo;
    char descricao[300];
    float valor_diaria;
    int qtd_pessoas;
} str_categ_acomodacoes;

/*
 * Struct Acomodacoes - Guarda as informa?„es das acomoda?„es
 */
typedef struct
{
    str_categ_acomodacoes catec_acomod;
    int codigo;
    char descricao[200];
    char facilidades[200];
} str_acomodacoes;

#endif