#ifndef BIB_CADASTRO_HOSPEDES_H
#define BIB_CADASTRO_HOSPEDES_H

#include <stdio.h>

/*
 * Struct H½spedes - Guarda os dados dos H½spedes do hotel
 */
typedef struct
{
    int codigo;
    char nome[50];
    char end_completo[100];
    char cpf[15];      // XXX.XXX.XXX-YY
    char telefone[16]; // (ZZ) YXXXX-XXXX
    char email[50];
    char sexo; // F, M ou N
    char estado_civil[15];
    char data_nasc[11]; // DD/MM/AAAA
} str_hospedes;

/*
 * Cadastra o H¢spede (Parƒmetro: struct com todos os dados)
 */
int cadastrarHospede(int mode, str_hospedes hospedes);

/*
 * Pesquisa o H¢spede (precisa ser chamado com os endere‡os de mem¢ria de todos as vari veis)
 */
int pesquisarHospede(int mode, char pesQ_cpf[15], str_hospedes *pHosped);

/*
 * Faz a altera‡Æo do h¢spede (selecionado pelo CPF)
 */
int alterarHospede(int mode, char cpf[15], str_hospedes att_hosped);

/*
 * Exclui o h¢spede selecionado
 */
int excluirHospede(int mode, char cpf[15]);

#endif