#ifndef BIB_CADASTRO_OPERADORES_H
#define BIB_CADASTRO_OPERADORES_H

#include <stdio.h>

/*
 * Struct Operadores do Sistema - Guarda os logins dos operadores do sistema
 */
typedef struct
{
    int codigo;
    char nome[50];
    char usuario[20];
    char senha[9]; // 8 caracteres
    char permissoes[200];
} str_op_sistemas;



#endif