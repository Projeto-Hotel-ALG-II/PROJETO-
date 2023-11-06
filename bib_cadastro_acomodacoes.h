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

/*
 * FUN€ÇO LISTA TODAS AS CATEGORIAS DE ACOMODA€åES
 */
void listarCategorias(int mode);

/*
 * FUN€ÇO CADASTRA UMA NOVA CATEGORIA DE ACOMODA€ÇO
 */
int cadastrarCategoria(int mode, str_categ_acomodacoes categoria);

/*
 * FUN€ÇO PESQUISA UMA CATEGORIA DE ACOMODA€ÇO
 */
int pesquisarCategoria(int mode, int codigo, str_categ_acomodacoes *categoria);

/*
 * FUN€ÇO EDITA CATEGORIAS DE ACOMODA€åES
 */
int editarCategoria(int mode, int codigo, str_categ_acomodacoes categoria);

/*
 * FUN€ÇO EXCLUI CATEGORIA DE ACOMODA€ÇO
 */
int excluirCategoria(int mode, int codigo);

/*
 * FUN€ÇO LISTA AS ACOMODA€åES
 */
void listarAcomodacoes(int mode);

/*
 * FUN€ÇO CADASTRAR ACOMODA€åES
 */
int cadastrarAcomodacao(int mode, str_acomodacoes acomodacao);

/*
 * FUN€ÇO PESQUISA ACOMODA€åES
 */
int pesquisarAcomodacao(int mode, int codigo, str_acomodacoes *acomodacao);

/*
 * FUN€ÇO EDITA ACOMODA€åES
 */
int editarAcomodacao(int mode, int codigo, str_acomodacoes acomodacao);

/*
 * FUN€ÇO EXCLUI ACOMODA€åES
 */
int excluirAcomodacao(int mode, int codigo);

#endif