#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bib_quick_tools.h"
#include "bib_cadastro_acomodacoes.h"

// FUN€ÇO MOSTRA TODAS AS CATEGORIAS
void listarCategorias(int mode)
{
    FILE *arquivo;

    switch (mode)
    {
    case 1: // USANDO ARQUIVO DE TEXTO
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.txt", "r");

        // CONDI€ÇO DE ERRO
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo de categorias de acomoda‡Æes.\n");
            return;
        }
        break;

    case 2: // USANDO ARQUIVO BINµRIO
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.dat", "rb");

        // CONDI€ÇO DE ERRO
        if (arquivo == NULL)
        {
            printf("Erro ao abrir o arquivo de categorias de acomoda‡Æes.\n");
            return;
        }
        break;

    case 3: // USANDO MEMàRIA
        /* code */
        break;
    }

    if (mode != 3)
    {
        str_categ_acomodacoes categoria;

        printf("Categorias de Acomoda‡Æes Cadastradas:\n");
        printf("-------------------------------\n");
        // o fscanf lˆ os dados e armazena na variavel categorias ate chegar no fim do arquivo (EOF)
        while (fscanf(arquivo, "%d|%[^|]|%f|%d", &categoria.codigo, categoria.descricao, &categoria.valor_diaria, &categoria.qtd_pessoas) != EOF)
        {
            if (categoria.codigo != 0)
            {
                printf("C¢digo                : %d\n", categoria.codigo);
                printf("Descri‡Æo             : %s\n", categoria.descricao);
                printf("Valor da Di ria       : R$%.2f\n", categoria.valor_diaria);
                printf("Quantidade de Pessoas : %d\n", categoria.qtd_pessoas);
                printf("-------------------------------\n");
            }
        }

        // assim q terminar a leitura, fecha o arquivo
        fclose(arquivo);
    }
    else
    {
    }
}

// FUN€ÇO CADASTRA UMA CATEGORIA
int cadastrarCategoria(int mode, str_categ_acomodacoes categoria)
{
    FILE *arquivo;

    switch (mode)
    {
    case 1: // USANDO ARQUIVO DE TEXTO
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.txt", "a");

        // CONDI€ÇO DE ERRO
        if (arquivo == NULL)
        {
            return 1;
        }
        categoria.codigo = contadorLinhas("..\\data\\dados_categ_acomodacoes.txt");
        break;

    case 2: // USANDO ARQUIVO BINµRIO
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.dat", "ab");

        // CONDI€ÇO DE ERRO
        if (arquivo == NULL)
        {
            return 1;
        }
        categoria.codigo = contadorLinhas("..\\data\\dados_categ_acomodacoes.dat");
        break;

    case 3: // USANDO MEMàRIA
        /* code */
        break;
    }

    if (mode != 3)
    {
        fprintf(arquivo, "%d|", categoria.codigo);
        fprintf(arquivo, "%s|", categoria.descricao);
        fprintf(arquivo, "%.2f|", categoria.valor_diaria);
        fprintf(arquivo, "%d\n", categoria.qtd_pessoas);

        fclose(arquivo);
    }
    else
    {
    }
    return 0;
}

// FUN€ÇO PESQUISA CATEGORIA
int pesquisarCategoria(int mode, int codigo, str_categ_acomodacoes *pCategoria)
{
    FILE *arquivo;

    switch (mode)
    {
    case 1: // USANDO ARQUIVO DE TEXTO
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.txt", "r");

        // CONDI€ÇO DE ERRO
        if (arquivo == NULL)
        {
            return 1;
        }
        break;
    case 2: // USANDO ARQUIVO BINµRIO
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.dat", "rb");

        // CONDI€ÇO DE ERRO
        if (arquivo == NULL)
        {
            return 1;
        }
        break;
    case 3: // USANDO MEMàRIA
        /* code */
        break;
    }

    str_categ_acomodacoes categoriaTemp;
    // variavel que vai armazenar temporariamente os dados das categorias

    if (mode != 3)
    {
        // loop vai ler os dados com a categoriaTemp ate chegar no fim do arquvio
        while (fscanf(arquivo, "%d|%[^|]|%f|%d\n", &categoriaTemp.codigo, categoriaTemp.descricao, &categoriaTemp.valor_diaria, &categoriaTemp.qtd_pessoas) != EOF)
        {
            if (categoriaTemp.codigo == codigo)
            {
                // mandando valores encontrados para os respectivos endere‡os fornecido para a fun‡Æo
                pCategoria->codigo = categoriaTemp.codigo;
                strcpy(pCategoria->descricao, categoriaTemp.descricao);
                pCategoria->qtd_pessoas = categoriaTemp.qtd_pessoas;
                pCategoria->valor_diaria = categoriaTemp.valor_diaria;
                return 0;
            }
        }
        fclose(arquivo);
    }
    else
    {
    }

    return 1;
}

// FUN€ÇO EDITA CATEGORIA
int editarCategoria(int mode, int codigo, str_categ_acomodacoes categoria)
{
    FILE *arquivo, *arquivoTemp;

    switch (mode)
    {
    case 1: // USANDO ARQUIVO DE TEXTO
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.txt", "r");
        arquivoTemp = fopen("..\\data\\temp.txt", "w");

        // CONDI€ÇO DE ERRO
        if (arquivo == NULL)
        {
            return 1;
        }
        break;
    case 2: // USANDO ARQUIVO BINµRIO
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.dat", "rb");
        arquivoTemp = fopen("..\\data\\temp.dat", "wb");

        // CONDI€ÇO DE ERRO
        if (arquivo == NULL)
        {
            return 1;
        }
        break;
    case 3: // USANDO MEMàRIA
        /* code */
        break;
    }

    str_categ_acomodacoes categoriaTemp;

    if (mode != 3)
    {
        while (fscanf(arquivo, "%d|%[^|]|%f|%d", &categoriaTemp.codigo, categoriaTemp.descricao, &categoriaTemp.valor_diaria, &categoriaTemp.qtd_pessoas) != EOF)
        {
            if (categoriaTemp.codigo == codigo)
            {
                fprintf(arquivoTemp, "%d|", categoria.codigo);
                fprintf(arquivoTemp, "%s|", categoria.descricao);
                fprintf(arquivoTemp, "%.2f|", categoria.valor_diaria);
                fprintf(arquivoTemp, "%d\n", categoria.qtd_pessoas);
            }
            else
            {
                fprintf(arquivoTemp, "%d|", categoriaTemp.codigo);
                fprintf(arquivoTemp, "%s|", categoriaTemp.descricao);
                fprintf(arquivoTemp, "%.2f|", categoriaTemp.valor_diaria);
                fprintf(arquivoTemp, "%d\n", categoriaTemp.qtd_pessoas);
            }
        }

        fclose(arquivo);
        fclose(arquivoTemp);
    }
    else
    {
    }

    // passando dados do arquivo tempor rio para arquivo original
    if (mode == 1)
    {
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.txt", "w");
        arquivoTemp = fopen("..\\data\\temp.txt", "r");
        if (arquivo == NULL && arquivoTemp == NULL)
        {
            return 1;
        }
    }
    else if (mode == 2)
    {
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.dat", "wb");
        arquivoTemp = fopen("..\\data\\temp.dat", "rb");
        if (arquivo == NULL && arquivoTemp == NULL)
        {
            return 1;
        }
    }

    if (mode != 3)
    {
        // fun‡Æo copia dados do tempor rio para o original
        copiarArquivo(arquivoTemp, arquivo);

        fclose(arquivo);
        fclose(arquivoTemp);
    }

    return 0;
}

// FUN€ÇO EXCLUI CATEGORIA
int excluirCategoria(int mode, int codigo)
{
    FILE *arquivo, *arquivoTemp;

    switch (mode)
    {
    case 1:
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.txt", "r");
        arquivoTemp = fopen("..\\data\\temp.txt", "w");

        if (arquivo == NULL || arquivoTemp == NULL)
        {
            exit(1);
        }
        break;

    case 2:
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.dat", "rb");
        arquivoTemp = fopen("..\\data\\temp.dat", "wb");

        if (arquivo == NULL || arquivoTemp == NULL)
        {
            exit(1);
        }
        break;

    case 3:
        /* code */
        break;
    }

    str_categ_acomodacoes categoriaTemp;

    if (mode != 3)
    {
        while (fscanf(arquivo, "%d|%[^|]|%f|%d", &categoriaTemp.codigo, categoriaTemp.descricao, &categoriaTemp.valor_diaria, &categoriaTemp.qtd_pessoas) != EOF)
        {
            if (categoriaTemp.codigo != codigo)
            {
                fprintf(arquivoTemp, "%d|", categoriaTemp.codigo);
                fprintf(arquivoTemp, "%s|", categoriaTemp.descricao);
                fprintf(arquivoTemp, "%.2f|", categoriaTemp.valor_diaria);
                fprintf(arquivoTemp, "%d\n", categoriaTemp.qtd_pessoas);
            }
            else
            {
                fprintf(arquivoTemp, "0|");
                fprintf(arquivoTemp, "%s|", categoriaTemp.descricao);
                fprintf(arquivoTemp, "%.2f|", categoriaTemp.valor_diaria);
                fprintf(arquivoTemp, "%d\n", categoriaTemp.qtd_pessoas);
            }
        }

        fclose(arquivo);
        fclose(arquivoTemp);
    }
    else
    {
    }

    if (mode == 1)
    {
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.txt", "w");
        arquivoTemp = fopen("..\\data\\temp.txt", "r");
        if (arquivo == NULL && arquivoTemp == NULL)
        {
            return 1;
        }
    }
    else if (mode == 2)
    {
        arquivo = fopen("..\\data\\dados_categ_acomodacoes.dat", "wb");
        arquivoTemp = fopen("..\\data\\temp.dat", "rb");
        if (arquivo == NULL && arquivoTemp == NULL)
        {
            return 1;
        }
    }

    if (mode != 3)
    {
        copiarArquivo(arquivoTemp, arquivo);

        fclose(arquivo);
        fclose(arquivoTemp);
    }

    return 0;
}

// FUN€ÇO LISTA ACOMODA€åES
void listarAcomodacoes(int mode)
{
    FILE *pF_Acomod, *pF_Categ;
    int op;

    switch (mode)
    {
    case 1:
        // Abre o arquivo "dados_acomodacoes.txt" no modo de leitura
        pF_Acomod = fopen("..\\data\\dados_acomodacoes.txt", "r");
        pF_Categ = fopen("..\\data\\dados_categ_acomodacoes.txt", "r");

        if (pF_Acomod == NULL || pF_Categ == NULL)
        { // mensagemd de erro
            return;
        }
        break;

    case 2:
        // Abre o arquivo "dados_acomodacoes.txt" no modo de leitura
        pF_Acomod = fopen("..\\data\\dados_acomodacoes.dat", "rb");
        pF_Categ = fopen("..\\data\\dados_categ_acomodacoes.dat", "rb");

        if (pF_Acomod == NULL || pF_Categ == NULL)
        { // mensagemd de erro
            return;
        }
        break;

    case 3:

        break;
    }

    str_acomodacoes acomodacao;

    if (mode != 3)
    {
        // Lˆ os dados das acomoda‡Æes do arquivo enquanto nÆo atingir o final do arquivo EOF
        printf("Acomoda‡Æes Cadastradas:\n");
        printf("-------------------------------\n");
        while (fscanf(pF_Acomod, "%d|%[^|]|%[^|]|%d", &acomodacao.codigo, acomodacao.descricao, acomodacao.facilidades, &acomodacao.catec_acomod.codigo) != EOF)
        {
            if (acomodacao.codigo != 0)
            {
                printf("C¢digo      : %d\n", acomodacao.codigo);
                printf("Descri‡Æo   : %s\n", acomodacao.descricao);
                printf("Facilidades : %s\n", acomodacao.facilidades);
                printf("=> Categoria de Acomoda‡Æo\n");

                op = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod);
                
                if (op == 0)
                {
                    printf("= C¢digo                : %d\n", acomodacao.catec_acomod.codigo);
                    printf("= Descri‡Æo             : %s\n", acomodacao.catec_acomod.descricao);
                    printf("= Valor da Di ria       : R$%.2f\n", acomodacao.catec_acomod.valor_diaria);
                    printf("= Quantidade de Pessoas : %d\n", acomodacao.catec_acomod.qtd_pessoas);
                    printf("-------------------------------\n");
                }
                else
                {
                    printf("A categoria desta acomoda‡Æo foi apagada, por favor, edite ela e selecione uma nova categoria.\n");
                    printf("-------------------------------\n");
                }
            }
        }

        // fechamento do arquivo
        fclose(pF_Acomod);
    }
    else
    {
    }
}

// FUN€ÇO CADASTRA UMA ACOMODA€ÇO
int cadastrarAcomodacao(int mode, str_acomodacoes acomodacao)
{
    FILE *arquivo;

    switch (mode)
    {
    case 1:
        // Abre o arquivo "dados_acomodacoes.txt" no modo de apˆndice (para adicionar novos dados ao final)
        arquivo = fopen("..\\data\\dados_acomodacoes.txt", "a");

        if (arquivo == NULL)
        { // mensagem erro
            exit(1);
        }
        acomodacao.codigo = contadorLinhas("..\\data\\dados_acomodacoes.txt");
        break;

    case 2:
        // Abre o arquivo "dados_acomodacoes.dat" no modo de apˆndice (para adicionar novos dados ao final)
        arquivo = fopen("..\\data\\dados_acomodacoes.dat", "ab");

        if (arquivo == NULL)
        { // mensagem erro
            exit(1);
        }
        acomodacao.codigo = contadorLinhas("..\\data\\dados_acomodacoes.dat");
        break;

    case 3:

        break;
    }

    if (mode != 3)
    {
        fprintf(arquivo, "%d|", acomodacao.codigo);
        fprintf(arquivo, "%s|", acomodacao.descricao);
        fprintf(arquivo, "%s|", acomodacao.facilidades);
        fprintf(arquivo, "%d\n", acomodacao.catec_acomod.codigo);

        fclose(arquivo);
    }
    else
    {
    }

    return 0;
}

// FUN€ÇO PESQUISA UMA ACOMODA€ÇO
int pesquisarAcomodacao(int mode, int codigo, str_acomodacoes *pAcomodacao)
{
    FILE *arquivo;

    switch (mode)
    {
    case 1:
        arquivo = fopen("..\\data\\dados_acomodacoes.txt", "r");

        if (arquivo == NULL)
        { // mensagem de erro

            exit(1);
        }
        break;
    case 2:
        arquivo = fopen("..\\data\\dados_acomodacoes.dat", "rb");

        if (arquivo == NULL)
        { // mensagem de erro

            exit(1);
        }
        break;
    case 3:
        /* code */
        break;
    }

    str_acomodacoes acomodacaoTemp;

    if (mode != 3)
    {
        while (fscanf(arquivo, "%d|%[^|]|%[^|]|%d\n", &acomodacaoTemp.codigo, acomodacaoTemp.descricao,
                      acomodacaoTemp.facilidades, &acomodacaoTemp.catec_acomod.codigo) != EOF)
        {
            if (acomodacaoTemp.codigo == codigo)
            {
                // mandando valores encontrados para os respectivos endere‡os fornecido para a fun‡Æo
                pAcomodacao->codigo = acomodacaoTemp.codigo;
                strcpy(pAcomodacao->descricao, acomodacaoTemp.descricao);
                strcpy(pAcomodacao->facilidades, acomodacaoTemp.facilidades);
                pAcomodacao->catec_acomod.codigo = acomodacaoTemp.catec_acomod.codigo;

                return 0;
            }
        }

        fclose(arquivo);
    }
    else
    {
    }

    return 1;
}

// FUN€ÇO EDITA UMA ACOMODA€ÇO
int editarAcomodacao(int mode, int codigo, str_acomodacoes acomodacao)
{
    FILE *arquivo, *arquivoTemp;

    switch (mode)
    {
    case 1:
        arquivo = fopen("..\\data\\dados_acomodacoes.txt", "r");
        arquivoTemp = fopen("..\\data\\temp.txt", "w");

        if (arquivo == NULL || arquivoTemp == NULL)
        {
            exit(1);
        }
        break;

    case 2:
        arquivo = fopen("..\\data\\dados_acomodacoes.dat", "rb");
        arquivoTemp = fopen("..\\data\\temp.dat", "wb");

        if (arquivo == NULL || arquivoTemp == NULL)
        {
            exit(1);
        }
        break;
    case 3:
        /* code */
        break;
    }

    str_acomodacoes acomodacaoTemp;

    if (mode != 3)
    {
        while (fscanf(arquivo, "%d|%[^|]|%[^|]|%d|%[^|]|%f|%d", &acomodacaoTemp.codigo, acomodacaoTemp.descricao,
                      acomodacaoTemp.facilidades, &acomodacaoTemp.catec_acomod.codigo,
                      acomodacaoTemp.catec_acomod.descricao, &acomodacaoTemp.catec_acomod.valor_diaria,
                      &acomodacaoTemp.catec_acomod.qtd_pessoas) != EOF)
        {
            if (acomodacaoTemp.codigo == codigo)
            {
                fprintf(arquivoTemp, "%d|", acomodacao.codigo);
                fprintf(arquivoTemp, "%s|", acomodacao.descricao);
                fprintf(arquivoTemp, "%s|", acomodacao.facilidades);
                fprintf(arquivoTemp, "%d\n", acomodacao.catec_acomod.codigo);
            }
            else
            {
                fprintf(arquivoTemp, "%d|", acomodacaoTemp.codigo);
                fprintf(arquivoTemp, "%s|", acomodacaoTemp.descricao);
                fprintf(arquivoTemp, "%s|", acomodacaoTemp.facilidades);
                fprintf(arquivoTemp, "%d\n", acomodacaoTemp.catec_acomod.codigo);
            }
        }

        fclose(arquivo);
        fclose(arquivoTemp);
    }

    // passando dados do arquivo tempor rio para arquivo original
    if (mode == 1)
    {
        arquivo = fopen("..\\data\\dados_acomodacoes.txt", "w");
        arquivoTemp = fopen("..\\data\\temp.txt", "r");
        if (arquivo == NULL && arquivoTemp == NULL)
        {
            return 1;
        }
    }
    else if (mode == 2)
    {
        arquivo = fopen("..\\data\\dados_acomodacoes.dat", "wb");
        arquivoTemp = fopen("..\\data\\temp.dat", "rb");
        if (arquivo == NULL && arquivoTemp == NULL)
        {
            return 1;
        }
    }

    if (mode != 3)
    {
        // fun‡Æo copia dados do tempor rio para o original
        copiarArquivo(arquivoTemp, arquivo);

        fclose(arquivo);
        fclose(arquivoTemp);
    }

    return 0;
}

// FUN€ÇO EXCLUI UMA ACOMODA€ÇO
int excluirAcomodacao(int mode, int codigo)
{
    FILE *arquivo, *arquivoTemp;

    switch (mode)
    {
    case 1:
        arquivo = fopen("..\\data\\dados_acomodacoes.txt", "r");
        arquivoTemp = fopen("..\\data\\temp.txt", "w");

        if (arquivo == NULL || arquivoTemp == NULL)
        {
            exit(1);
        }
        break;
    case 2:
        arquivo = fopen("..\\data\\dados_acomodacoes.dat", "rb");
        arquivoTemp = fopen("..\\data\\temp.dat", "wb");

        if (arquivo == NULL || arquivoTemp == NULL)
        {
            exit(1);
        }
        break;
    case 3:

        break;
    }

    str_acomodacoes acomodacaoTemp;
    int encontrado = 0;

    if (mode != 3)
    {
        while (fscanf(arquivo, "%d|%[^|]|%[^|]|%d|%[^|]|%f|%d", &acomodacaoTemp.codigo, acomodacaoTemp.descricao,
                      acomodacaoTemp.facilidades, &acomodacaoTemp.catec_acomod.codigo,
                      acomodacaoTemp.catec_acomod.descricao, &acomodacaoTemp.catec_acomod.valor_diaria,
                      &acomodacaoTemp.catec_acomod.qtd_pessoas) != EOF)
        {
            if (acomodacaoTemp.codigo == codigo)
            {
                fprintf(arquivoTemp, "0|");
                fprintf(arquivoTemp, "%s|", acomodacaoTemp.descricao);
                fprintf(arquivoTemp, "%s|", acomodacaoTemp.facilidades);
                fprintf(arquivoTemp, "%d|", acomodacaoTemp.catec_acomod.codigo);
                fprintf(arquivoTemp, "%s|", acomodacaoTemp.catec_acomod.descricao);
                fprintf(arquivoTemp, "%.2f|", acomodacaoTemp.catec_acomod.valor_diaria);
                fprintf(arquivoTemp, "%d\n", acomodacaoTemp.catec_acomod.qtd_pessoas);
            }
            else
            {
                fprintf(arquivoTemp, "%d|", acomodacaoTemp.codigo);
                fprintf(arquivoTemp, "%s|", acomodacaoTemp.descricao);
                fprintf(arquivoTemp, "%s|", acomodacaoTemp.facilidades);
                fprintf(arquivoTemp, "%d|", acomodacaoTemp.catec_acomod.codigo);
                fprintf(arquivoTemp, "%s|", acomodacaoTemp.catec_acomod.descricao);
                fprintf(arquivoTemp, "%.2f|", acomodacaoTemp.catec_acomod.valor_diaria);
                fprintf(arquivoTemp, "%d\n", acomodacaoTemp.catec_acomod.qtd_pessoas);
            }
        }

        fclose(arquivo);
        fclose(arquivoTemp);
    }

    // passando dados do arquivo tempor rio para arquivo original
    if (mode == 1)
    {
        arquivo = fopen("..\\data\\dados_acomodacoes.txt", "w");
        arquivoTemp = fopen("..\\data\\temp.txt", "r");
        if (arquivo == NULL && arquivoTemp == NULL)
        {
            return 1;
        }
    }
    else if (mode == 2)
    {
        arquivo = fopen("..\\data\\dados_acomodacoes.dat", "wb");
        arquivoTemp = fopen("..\\data\\temp.dat", "rb");
        if (arquivo == NULL && arquivoTemp == NULL)
        {
            return 1;
        }
    }

    if (mode != 3)
    {
        // fun‡Æo copia dados do tempor rio para o original
        copiarArquivo(arquivoTemp, arquivo);

        fclose(arquivo);
        fclose(arquivoTemp);
    }

    return 0;
}