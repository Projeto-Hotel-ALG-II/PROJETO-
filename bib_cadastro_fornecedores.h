#ifndef BIB_CADASTRO_FORNECEDORES_H
#define BIB_CADASTRO_FORNECEDORES_H

#include <stdio.h>

/*
 * Struct Fornecedores - Guarda os dados dos fornecedores do hotel
 */
typedef struct
{
    int codigo;
    char nome[50];
    char razao_social[100];
    char inscricao_estadual[20]; // Varia de estado para estado
    char cnpj[19];               // XX.XXX.XXX/YYYY-ZZ
    char end_completo[100];
    char telefone[16]; // (XX) YZZZZ-ZZZZ
    char email[50];
} str_fornecedores;

/*
 * FUN€ÇO CADASTRA FORNECEDORES
 */
int cadastrarFornecedor(int mode, str_fornecedores f);

/*
 * FUN€ÇO PESQUISA FORNECEDORES
 */
int pesquisarFornecedor(int mode, char cnpj_pesq[15], str_fornecedores *pFornec);

/*
 * FUN€ÇO ALTERA FORNECEDORES
 */
int alterarFornecedor(int mode, char cnpj_forn[15], str_fornecedores att_fornec);

/*
 * FUN€ÇO EXCLUI FORNECEDORES
 */
int excluirFornecedor(int mode, char cnpj_forn[15]);

#endif