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


#endif