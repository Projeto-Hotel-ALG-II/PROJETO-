#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_cadastro_operadores.h"
#include "bib_quick_tools.h"

// Fun?’o para cadastrar um operador no sistema
int cadastrarOperador(int mode, str_op_sistemas operador)
{
    FILE *foperador;
    switch (mode)
    {
    case 1:
        foperador = fopen("..\\data\\dados_operadores.txt", "a");
        if (foperador == NULL)
        {
            return 1;
        }
        operador.codigo = contadorLinhas("..\\data\\dados_operadores.txt") + 1;
        break;
    case 2:
        foperador = fopen("..\\data\\dados_operadores.dat", "ab");
        if (foperador == NULL)
        {
            return 1;
        }
        operador.codigo = contadorLinhas("..\\data\\dados_operadores.dat") + 1;
        break;
    case 3: // alocacao dinamica

        break;
    }

    fprintf(foperador, "%d|", operador.codigo);
    fprintf(foperador, "%s|", operador.nome);
    fprintf(foperador, "%s|", operador.usuario);
    fprintf(foperador, "%s|", operador.senha);
    fprintf(foperador, "%s\n", operador.permissoes);

    fclose(foperador);
    return 0; // Operador cadastrado com sucesso
}

// Fun?’o para pesquisar um operador pelo usuÇ­rio
int pesquisarOperadorPorUsuario(int mode, char pqusuario[20], str_op_sistemas *operador)
{
    FILE *foperador;
    switch (mode)
    {
    case 1:
        foperador = fopen("..\\data\\dados_operadores.txt", "r");
        if (foperador == NULL)
        {
            return 1;
        }
        break;
    case 2:
        foperador = fopen("..\\data\\dados_operadores.dat", "rb");
        if (foperador == NULL)
        {
            return 1;
        }
        break;
    case 3: // alocacao dinamica

        break;
    }

    str_op_sistemas dados;

    while (fscanf(foperador, "%d|%[^|]|%[^|]|%[^|]|%[^\n]\n", &dados.codigo, dados.nome, dados.usuario, dados.senha, dados.permissoes) != EOF)
    {
        if (strcmp(pqusuario, dados.usuario) == 0)
        {
            operador->codigo = dados.codigo;
            strcpy(operador->nome, dados.nome);
            strcpy(operador->usuario, dados.usuario);
            strcpy(operador->senha, dados.senha);
            strcpy(operador->permissoes, dados.permissoes);
            fclose(foperador);
            return 0; // Operador encontrado
        }
    }

    fclose(foperador);
    return 1; // Operador n’o encontrado
}

// Fun?’o para editar um operador
int editarOperador(int mode, char pqusuario[20], str_op_sistemas operador)
{
    FILE *ftemp, *foperador;
    str_op_sistemas temp;
    switch (mode)
    {
    case 1:
        foperador = fopen("..\\data\\dados_operadores.txt", "r");
        ftemp = fopen("..\\data\\dados_operadores_temp.txt", "w");
        if (foperador == NULL || ftemp == NULL)
        {
            return 1;
        }
        break;
    case 2:
        foperador = fopen("..\\data\\dados_operadores.dat", "rb");
        ftemp = fopen("..\\data\\dados_operadores_temp.dat", "wb");
        if (foperador == NULL || ftemp == NULL)
        {
            return 1;
        }
        break;
    case 3: // alocacao dinamica

        break;
    }

    while (fscanf(foperador, "%d|%[^|]|%[^|]|%[^|]|%[^\n]\n", &temp.codigo, temp.nome, temp.usuario, temp.senha, temp.permissoes) != EOF)
    {
        if (strcmp(temp.usuario, pqusuario) != 0)
        {
            fprintf(ftemp, "%d|", temp.codigo);
            fprintf(ftemp, "%s|", temp.nome);
            fprintf(ftemp, "%s|", temp.usuario);
            fprintf(ftemp, "%s|", temp.senha);
            fprintf(ftemp, "%s\n", temp.permissoes);
        }
        else
        {
            fprintf(ftemp, "%d|", temp.codigo);
            fprintf(ftemp, "%s|", operador.nome);
            fprintf(ftemp, "%s|", operador.usuario);
            fprintf(ftemp, "%s|", operador.senha);
            fprintf(ftemp, "%s\n", operador.permissoes);
        }
    }

    fclose(foperador);
    fclose(ftemp);

    if (mode == 1)
    {
        if (substituiTemp("..\\data\\dados_operadores.txt", "..\\data\\dados_operadores_temp.txt") == 0)
        {
            return 0; // Operador editado com sucesso
        }
        else
        {
            return 1;
        }
    }
    else if (mode == 2)
    {
        if (substituiTemp("..\\data\\dados_operadores.dat", "..\\data\\dados_operadores_temp.dat") == 0)
        {
            return 0; // Operador editado com sucesso
        }
        else
        {
            return 1;
        }
    }
    return 0;
}

// Fun?’o para excluir um operador
int excluirOperador(int mode, char pqusuario[20])
{
    FILE *ftemp, *foperador;
    str_op_sistemas temp;
    switch (mode)
    {
    case 1:
        foperador = fopen("..\\data\\dados_operadores.txt", "r");
        ftemp = fopen("..\\data\\dados_operadores_temp.txt", "w");
        if (foperador == NULL || ftemp == NULL)
        {
            return 1;
        }
        break;
    case 2:
        foperador = fopen("..\\data\\dados_operadores.dat", "rb");
        ftemp = fopen("..\\data\\dados_operadores_temp.dat", "wb");
        if (foperador == NULL || ftemp == NULL)
        {
            return 1;
        }
        break;
    case 3: // alocacao dinamica

        break;
    }

    while (fscanf(foperador, "%d|%[^|]|%[^|]|%[^|]|%[^\n]\n", &temp.codigo, temp.nome, temp.usuario, temp.senha, temp.permissoes) != EOF)
    {
        if (strcmp(temp.usuario, pqusuario) != 0)
        {
            fprintf(ftemp, "%d|", temp.codigo);
            fprintf(ftemp, "%s|", temp.nome);
            fprintf(ftemp, "%s|", temp.usuario);
            fprintf(ftemp, "%s|", temp.senha);
            fprintf(ftemp, "%s\n", temp.permissoes);
        }
        else
        {
            fprintf(ftemp, "0|"); // Marca o operador como exclu­do
            fprintf(ftemp, "%s|", temp.nome);
            fprintf(ftemp, "%s|", temp.usuario);
            fprintf(ftemp, "%s|", temp.senha);
            fprintf(ftemp, "%s\n", temp.permissoes);
        }
    }

    fclose(foperador);
    fclose(ftemp);

    if (mode == 1)
    {
        if (substituiTemp("..\\data\\dados_operadores.txt", "..\\data\\dados_operadores_temp.txt") == 0)
        {
            return 0; // Operador editado com sucesso
        }
        else
        {
            return 1;
        }
    }
    else if (mode == 2)
    {
        if (substituiTemp("..\\data\\dados_operadores.dat", "..\\data\\dados_operadores_temp.dat") == 0)
        {
            return 0; // Operador editado com sucesso
        }
        else
        {
            return 1;
        }
    }
    return 0;
}