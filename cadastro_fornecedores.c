#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "bib_quick_tools.h"
#include "bib_cadastro_fornecedores.h"

int iniciaF(str_fornecedores * f){
	f = (str_fornecedores*)malloc(0*sizeof(str_fornecedores));
	if(f == NULL){
		fprintf(stderr, "Memory Allocation error\n");
		exit(EXIT_FAILURE);
	}

	return 1;
}

int cadastrarFornecedor(int mode, str_fornecedores * f)
{
    FILE *pF_fornec;
    switch (mode)
    {
    case 1: // Usando txt
        pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "w");
        if (pF_fornec == NULL)
        {
            return 1;
        }
        break;
    case 2:
        pF_fornec = fopen("..\\data\\dados_fornecedores.dat", "wb");
        if (pF_fornec == NULL)
        {
            return 1;
        }
        break;
    }

        fprintf(pF_fornec, "%d|", f->codigo);
        fprintf(pF_fornec, "%s|", f->nome);
        fprintf(pF_fornec, "%s|", f->razao_social);
        fprintf(pF_fornec, "%s|", f->inscricao_estadual);
        fprintf(pF_fornec, "%s|", f->cnpj);
        fprintf(pF_fornec, "%s|", f->end_completo);
        fprintf(pF_fornec, "%s|", f->telefone);
        fprintf(pF_fornec, "%s|", f->email);

        if (mode == 3)
        {
            f = (str_fornecedores*)realloc(f, (sizeof(str_fornecedores)+1));
        }
        

        fclose(pF_fornec);
   
    return 0;
}

/*
 * Faz a pesquisa do fornecedor
 */
int pesquisarFornecedor(int mode, char cnpj_pesq[15], str_fornecedores *pFornec, str_fornecedores * f)
{
    FILE *pF_fornec;

    switch (mode)
    {
    case 1: // Usando txt
        pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "w");
        if (pF_fornec == NULL)
        {
            return 1;
        }
        break;
    case 2:
        pF_fornec = fopen("..\\data\\dados_fornecedores.dat", "wb");
        if (pF_fornec == NULL)
        {
            return 1;
        }
        break;
    }


        while (fscanf(pF_fornec, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", &f->codigo, f->nome, f->razao_social,
                  f->inscricao_estadual, f->cnpj, f->end_completo, f->telefone, f->email) != EOF)
        {
            if (strcmp(cnpj_pesq, f->cnpj) == 0 && f->codigo != 0)
            {
                pFornec->codigo = f->codigo;
                strcpy(pFornec->nome, f->nome);
                strcpy(pFornec->razao_social, f->razao_social);
                strcpy(pFornec->inscricao_estadual, f->inscricao_estadual);
                strcpy(pFornec->cnpj, f->cnpj);
                strcpy(pFornec->end_completo, f->end_completo);
                strcpy(pFornec->telefone, f->telefone);
                strcpy(pFornec->email, f->email);
                return 0;
            }
        }   

    
    fclose(pF_fornec);
    return 1;
}

int alterarFornecedor(int mode, char cnpj_forn[15], str_fornecedores * f)
{
    FILE *pF_temp, *pF_fornec;
    str_fornecedores tmp;

    switch (mode)
    {
    case 1: // Usando txt
        pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "r");
        pF_temp = fopen("..\\data\\dados_fornecedores_temp.txt", "w");
        if (pF_fornec == NULL || pF_temp)
        {
            return 1;
        }
        break;
    case 2:
        pF_fornec = fopen("..\\data\\dados_fornecedores.dat", "rb");
        pF_temp = fopen("..\\data\\dados_fornecedores_temp.dat", "wb" );
        if (pF_fornec == NULL || pF_temp)
        {
            return 1;
        }
        break;
    }
  
    while (fscanf(pF_fornec, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", &tmp.codigo, tmp.nome, tmp.razao_social, tmp.inscricao_estadual,
                    tmp.cnpj, tmp.end_completo, tmp.telefone, tmp.email) != EOF)
    {
            // caso o fornecedor n�o seja o que se deseja alterar ser� copiado os dados diretamente do arquivo original para o tempor�rio
        if (strcmp(tmp.cnpj, cnpj_forn) != 0)
        {
            fprintf(pF_temp, "%d|", tmp.codigo);
            fprintf(pF_temp, "%s|", tmp.nome);
            fprintf(pF_temp, "%s|", tmp.razao_social);
            fprintf(pF_temp, "%s|", tmp.inscricao_estadual);
            fprintf(pF_temp, "%s|", tmp.cnpj);
            fprintf(pF_temp, "%s|", tmp.end_completo);
            fprintf(pF_temp, "%s|", tmp.telefone);
            fprintf(pF_temp, "%s\n", tmp.email);
        }
            // caso o fornecedor seja o que se deseja alterar ser� escrito no arquivo tempor�rio os novos dados
        else
        {
            fprintf(pF_temp, "%d|", f->codigo);
            fprintf(pF_temp, "%s|", f->nome);
            fprintf(pF_temp, "%s|", f->razao_social);
            fprintf(pF_temp, "%s|", f->inscricao_estadual);
            fprintf(pF_temp, "%s|", f->cnpj);
            fprintf(pF_temp, "%s|", f->cnpj);
            fprintf(pF_temp, "%s|", f->telefone);
            fprintf(pF_temp, "%s\n", f->email);
        }
    }

    fclose(pF_fornec);
    fclose(pF_temp);

    if (mode == 1)
    {
        pF_temp = fopen("..\\data\\dados_fornecedores_temp.txt", "r");
        pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "w");
        if (pF_fornec == NULL || pF_temp == NULL)
        {
            exit(2);
        }
 
    }
    else if (mode == 2)
    {
        pF_fornec = fopen("..\\data\\dados_fornecedores_temp.dat", "rb");
        pF_fornec = fopen("..\\data\\dados_fornecedores.dat", "wb" );
        if (pF_fornec == NULL || pF_temp == NULL)
        {
            exit(2);
        }

    }
  
    copiarArquivo(pF_temp, pF_fornec);

    fclose(pF_temp);
    fclose(pF_fornec);

    return 0;
}

int excluirFornecedor(int mode, char cnpj_forn[15], str_fornecedores * f)
{
    FILE *pF_temp, *pF_fornec;
    str_fornecedores tmp;
    switch (mode)
    {
    case 1: // Usando txt
        pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "r");
        pF_temp = fopen("..\\data\\dados_fornecedores_temp.txt", "w");
        if (pF_fornec == NULL || pF_temp)
        {
            return 1;
        }
        break;
    case 2:
        pF_fornec = fopen("..\\data\\dados_fornecedores.dat", "rb");
        pF_temp = fopen("..\\data\\dados_fornecedores_temp.dat", "wb" );
        if (pF_fornec == NULL || pF_temp)
        {
            return 1;
        }
        break;
    }

    while (fscanf(pF_fornec, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^\n]\n", &tmp.codigo, tmp.nome, tmp.razao_social, tmp.inscricao_estadual,
                  tmp.cnpj, tmp.end_completo, tmp.telefone, tmp.email) != EOF)
    {
        // caso o fornecedor n�o seja o que se deseja excluir, ser� copiado os dados diretamente do arquivo original para o tempor�rio
        if (strcmp(tmp.cnpj, cnpj_forn) != 0)
        {
            fprintf(pF_temp, "%d|", tmp.codigo);
            fprintf(pF_temp, "%s|", tmp.nome);
            fprintf(pF_temp, "%s|", tmp.razao_social);
            fprintf(pF_temp, "%s|", tmp.inscricao_estadual);
            fprintf(pF_temp, "%s|", tmp.cnpj);
            fprintf(pF_temp, "%s|", tmp.end_completo);
            fprintf(pF_temp, "%s|", tmp.telefone);
            fprintf(pF_temp, "%s\n", tmp.email);
        }
        // caso o fornecedor seja o que se deseja excluir, ele ser� escrito no arquivo tempor�rio s� que com c�digo igual a 0
        else
        {
            fprintf(pF_temp, "0|", f->codigo); // fornecedor excluido - codigo = 0
            fprintf(pF_temp, "%s|", tmp.nome);
            fprintf(pF_temp, "%s|", tmp.razao_social);
            fprintf(pF_temp, "%s|", tmp.inscricao_estadual);
            fprintf(pF_temp, "%s|", tmp.cnpj);
            fprintf(pF_temp, "%s|", tmp.end_completo);
            fprintf(pF_temp, "%s|", tmp.telefone);
            fprintf(pF_temp, "%s\n", tmp.email);
        }
    }

    // fechando files
    fclose(pF_fornec);
    fclose(pF_temp);

    if (mode == 1)
    {
        pF_temp = fopen("..\\data\\dados_fornecedores_temp.txt", "r");
        pF_fornec = fopen("..\\data\\dados_fornecedores.txt", "w");
        if (pF_fornec == NULL || pF_temp == NULL)
        {
            exit(2);
        }
 
    }
    else if (mode == 2)
    {
        pF_fornec = fopen("..\\data\\dados_fornecedores_temp.dat", "rb");
        pF_fornec = fopen("..\\data\\dados_fornecedores.dat", "wb" );
        if (pF_fornec == NULL || pF_temp == NULL)
        {
            exit(2);
        }

    }
    
    f = (str_fornecedores*)realloc(f, (sizeof(str_fornecedores)-1));
    // fun?�o vai copiar os dados do arquivo tempor�rio de volta para o original
    copiarArquivo(pF_temp, pF_fornec);

    fclose(pF_temp);
    fclose(pF_fornec);

    return 0;
}