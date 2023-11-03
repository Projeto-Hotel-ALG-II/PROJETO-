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


#endif