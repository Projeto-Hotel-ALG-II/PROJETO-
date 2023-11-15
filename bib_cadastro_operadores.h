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

int iniciaOp(str_op_sistemas *op);
/*
 * FUN��O CADASTRA OPERADOR 
*/
int cadastrarOperador(int mode, str_op_sistemas *op);

/*
 * FUN��O PESQUISA OPERADOR 
*/
int pesquisarOperadorPorUsuario(int mode, char pqusuario[20], str_op_sistemas *op);

/*
 * FUN��O EDITA OPERADOR 
*/
int editarOperador(int mode, char pqusuario[20], str_op_sistemas *op);

/*
 * FUN��O EXCLUI OPERADOR 
*/
int excluirOperador(int mode, char pqusuario[20], str_op_sistemas *op);

#endif