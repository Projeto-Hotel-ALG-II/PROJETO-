#ifndef BIB_CADASTRO_ACOMODACOES_H
#define BIB_CADASTRO_ACOMODACOES_H

#include <stdio.h>

/*
 * Sub-Struct de 'Acomodacoes' - Guarda as caracter�sticas das acomoda?�es e ? acessada atrav?s da struct Acomodacoes
 */
typedef struct
{
    int codigo;
    char descricao[300];
    float valor_diaria;
    int qtd_pessoas;
} str_categ_acomodacoes;

/*
 * Struct Acomodacoes - Guarda as informa?�es das acomoda?�es
 */
typedef struct
{
    str_categ_acomodacoes catec_acomod;
    int codigo;
    char descricao[200];
    char facilidades[200];
} str_acomodacoes;

/*
 * FUN��O LISTA TODAS AS CATEGORIAS DE ACOMODA��ES
 */
void listarCategorias(int mode);

/*
 * FUN��O CADASTRA UMA NOVA CATEGORIA DE ACOMODA��O
 */
int cadastrarCategoria(int mode, str_categ_acomodacoes categoria);

/*
 * FUN��O PESQUISA UMA CATEGORIA DE ACOMODA��O
 */
int pesquisarCategoria(int mode, int codigo, str_categ_acomodacoes *categoria);

/*
 * FUN��O EDITA CATEGORIAS DE ACOMODA��ES
 */
int editarCategoria(int mode, int codigo, str_categ_acomodacoes categoria);

/*
 * FUN��O EXCLUI CATEGORIA DE ACOMODA��O
 */
int excluirCategoria(int mode, int codigo);

/*
 * FUN��O LISTA AS ACOMODA��ES
 */
void listarAcomodacoes(int mode);

/*
 * FUN��O CADASTRAR ACOMODA��ES
 */
int cadastrarAcomodacao(int mode, str_acomodacoes acomodacao);

/*
 * FUN��O PESQUISA ACOMODA��ES
 */
int pesquisarAcomodacao(int mode, int codigo, str_acomodacoes *acomodacao);

/*
 * FUN��O EDITA ACOMODA��ES
 */
int editarAcomodacao(int mode, int codigo, str_acomodacoes acomodacao);

/*
 * FUN��O EXCLUI ACOMODA��ES
 */
int excluirAcomodacao(int mode, int codigo);

#endif