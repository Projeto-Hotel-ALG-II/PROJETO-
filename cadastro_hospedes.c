#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#include "bib_quick_tools.h"
#include "bib_cadastro_hospedes.h"

int cadastrarHospede(int mode, str_hospedes hospedes)
{
    FILE *pF_hosped;
    switch (mode)
    {
    case 1: // TRABALHANDO COM ARQUIVOS TXT
        pF_hosped = fopen("..\\data\\dados_hospedes.txt", "a");
        if (pF_hosped == NULL)
        {
            exit(1);
        }
        hospedes.codigo = contadorLinhas("..\\data\\dados_hospedes.txt");
        break;

    case 2: // TRABALHANDO COM ARQUIVOS BIN�RIOS
        pF_hosped = fopen("..\\data\\dados_hospedes.bin", "ab");
        if (pF_hosped == NULL)
        {
            exit(1);
        }
        hospedes.codigo = contadorLinhas("..\\data\\dados_hospedes.bin");
        break;

    case 3: // TRABALHANDO COM ALOCA��O DIN�MICA DE MEM�RIA

        break;
    }

    if (mode != 3)
    {
        fprintf(pF_hosped, "%d|", hospedes.codigo);
        fprintf(pF_hosped, "%s|", hospedes.nome);
        fprintf(pF_hosped, "%s|", hospedes.end_completo);
        fprintf(pF_hosped, "%s|", hospedes.cpf);
        fprintf(pF_hosped, "%s|", hospedes.telefone);
        fprintf(pF_hosped, "%s|", hospedes.email);
        fprintf(pF_hosped, "%c|", hospedes.sexo);
        fprintf(pF_hosped, "%s|", hospedes.estado_civil);
        fprintf(pF_hosped, "%s\n", hospedes.data_nasc);

        fclose(pF_hosped);
    }
    return 0;
}

int pesquisarHospede(int mode, char pesQ_cpf[15], str_hospedes *pHosped)
{
    FILE *pF_hosped;
    str_hospedes h; // struct hospedes

    switch (mode)
    {
    case 1:
        pF_hosped = fopen("..\\data\\dados_hospedes.txt", "r");
        if (pF_hosped == NULL)
        {
            exit(1);
        }
        break;

    case 2:
        pF_hosped = fopen("..\\data\\dados_hospedes.dat", "rb");
        if (pF_hosped == NULL)
        {
            exit(1);
        }
        break;

    case 3:
        /* code */
        break;

    default:
        break;
    }

    if (mode != 3)
    {
        while (fscanf(pF_hosped, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^\n]\n", &h.codigo, h.nome, h.end_completo, h.cpf, h.telefone,
                      h.email, &h.sexo, h.estado_civil, h.data_nasc) != EOF)
        {
            if (strcmp(h.cpf, pesQ_cpf) == 0 && h.codigo != 0)
            {
                pHosped->codigo = h.codigo;
                strcpy(pHosped->nome, h.nome);
                strcpy(pHosped->end_completo, h.end_completo);
                strcpy(pHosped->cpf, h.cpf);
                strcpy(pHosped->telefone, h.telefone);
                strcpy(pHosped->email, h.email);
                pHosped->sexo = h.sexo;
                strcpy(pHosped->estado_civil, h.estado_civil);
                strcpy(pHosped->data_nasc, h.data_nasc);
                return 0;
            }
        }

        fclose(pF_hosped);
    }
    else
    {
    }
    return 1;
}

int alterarHospede(int mode, char cpf[15], str_hospedes att_hosped)
{
    FILE *pF_hospedes;
    FILE *pF_temp;
    str_hospedes tmp;

    switch (mode)
    {
    case 1:
        pF_hospedes = fopen("..\\data\\dados_hospedes.txt", "r");
        pF_temp = fopen("..\\data\\temp.txt", "w");

        if (pF_hospedes == NULL || pF_temp == NULL)
        {
            exit(1);
        }
        break;
    case 2:
        pF_hospedes = fopen("..\\data\\dados_hospedes.dat", "rb");
        pF_temp = fopen("..\\data\\temp.dat", "wb");

        if (pF_hospedes == NULL || pF_temp == NULL)
        {
            exit(1);
        }
        break;
    case 3:
        /* code */
        break;
    }

    if (mode != 3)
    {
        while (fscanf(pF_hospedes, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^\n]\n", &tmp.codigo, tmp.nome, tmp.end_completo, tmp.cpf, tmp.telefone,
                      tmp.email, &tmp.sexo, tmp.estado_civil, tmp.data_nasc) != EOF)
        {
            // caso h�spede n�o seja o pesquisado, ser� escrito diretamente o conteudo do arquivo original no tempor�rio
            if (strcmp(tmp.cpf, cpf) != 0)
            {
                fprintf(pF_temp, "%d|", tmp.codigo);
                fprintf(pF_temp, "%s|", tmp.nome);
                fprintf(pF_temp, "%s|", tmp.end_completo);
                fprintf(pF_temp, "%s|", tmp.cpf);
                fprintf(pF_temp, "%s|", tmp.telefone);
                fprintf(pF_temp, "%s|", tmp.email);
                fprintf(pF_temp, "%c|", tmp.sexo);
                fprintf(pF_temp, "%s|", tmp.estado_civil);
                fprintf(pF_temp, "%s\n", tmp.data_nasc);
            }
            // caso o h�spede seja o pesquisado, ele ser� escrito no arquivo tempor�rio s� que com os novos dados
            else
            {
                att_hosped.codigo = tmp.codigo;
                fprintf(pF_temp, "%d|", att_hosped.codigo);
                fprintf(pF_temp, "%s|", att_hosped.nome);
                fprintf(pF_temp, "%s|", att_hosped.end_completo);
                fprintf(pF_temp, "%s|", att_hosped.cpf);
                fprintf(pF_temp, "%s|", att_hosped.telefone);
                fprintf(pF_temp, "%s|", att_hosped.email);
                fprintf(pF_temp, "%c|", att_hosped.sexo);
                fprintf(pF_temp, "%s|", att_hosped.estado_civil);
                fprintf(pF_temp, "%s\n", att_hosped.data_nasc);
            }
        }

        // fechando arquivos
        fclose(pF_hospedes);
        fclose(pF_temp);
    }

    switch (mode)
    {
    case 1:
        // Reescrevendo os dados do arquivo tempor�rio no arquivo principal
        pF_temp = fopen("..\\data\\temp.txt", "r");
        pF_hospedes = fopen("..\\data\\dados_hospedes.txt", "w");
        if (pF_hospedes == NULL || pF_temp == NULL)
        {
            exit(1);
        }
        break;
    case 2:
        // Reescrevendo os dados do arquivo tempor�rio no arquivo principal
        pF_temp = fopen("..\\data\\temp.dat", "rb");
        pF_hospedes = fopen("..\\data\\dados_hospedes.dat", "wb");
        if (pF_hospedes == NULL || pF_temp == NULL)
        {
            exit(1);
        }
        break;
    }

    if (mode != 3)
    {
        // fun��o vai copiar os dados do arquivo tempor�rio de volta para o original
        copiarArquivo(pF_temp, pF_hospedes);

        fclose(pF_temp);
        fclose(pF_hospedes);
    }

    return 0;
}

int excluirHospede(int mode, char cpf[15])
{
    // declarando ponteiros de arquivos
    FILE *pF_hospedes;
    FILE *pF_temp;

    switch (mode)
    {
    case 1:
        // abrindo arquivos
        pF_hospedes = fopen("..\\data\\dados_hospedes.txt", "r");
        pF_temp = fopen("..\\data\\temp.txt", "w"); // arquivo tempor�rio

        // caso n�o seja poss�vel abrir o arquivo
        if (pF_hospedes == NULL || pF_temp == NULL)
        {
            exit(1);
        }
        break;

    case 2:
        // abrindo arquivos
        pF_hospedes = fopen("..\\data\\dados_hospedes.dat", "rb");
        pF_temp = fopen("..\\data\\temp.dat", "wb"); // arquivo tempor�rio

        // caso n�o seja poss�vel abrir o arquivo
        if (pF_hospedes == NULL || pF_temp == NULL)
        {
            exit(1);
        }
        break;

    case 3:
        /* code */
        break;
    }

    str_hospedes tmp;

    if (mode != 3)
    {
        // lendo arquivo original linha por linha
        while (fscanf(pF_hospedes, "%d|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%c|%[^|]|%[^\n]\n", &tmp.codigo, tmp.nome, tmp.end_completo, tmp.cpf, tmp.telefone,
                      tmp.email, &tmp.sexo, tmp.estado_civil, tmp.data_nasc) != EOF)
        {
            // caso h�spede n�o seja o pesquisado, ser� escrito diretamente o conteudo do arquivo original no tempor�rio
            if (strcmp(tmp.cpf, cpf) != 0)
            {
                fprintf(pF_temp, "%d|", tmp.codigo);
                fprintf(pF_temp, "%s|", tmp.nome);
                fprintf(pF_temp, "%s|", tmp.end_completo);
                fprintf(pF_temp, "%s|", tmp.cpf);
                fprintf(pF_temp, "%s|", tmp.telefone);
                fprintf(pF_temp, "%s|", tmp.email);
                fprintf(pF_temp, "%c|", tmp.sexo);
                fprintf(pF_temp, "%s|", tmp.estado_civil);
                fprintf(pF_temp, "%s\n", tmp.data_nasc);
            }
            // caso o h�spede seja o pesquisado, ele ser� escrito no arquivo tempor�rio s� que com o c�digo igual a 0
            else
            {
                fprintf(pF_temp, "0|");
                fprintf(pF_temp, "%s|", tmp.nome);
                fprintf(pF_temp, "%s|", tmp.end_completo);
                fprintf(pF_temp, "%s|", tmp.cpf);
                fprintf(pF_temp, "%s|", tmp.telefone);
                fprintf(pF_temp, "%s|", tmp.email);
                fprintf(pF_temp, "%c|", tmp.sexo);
                fprintf(pF_temp, "%s|", tmp.estado_civil);
                fprintf(pF_temp, "%s\n", tmp.data_nasc);
            }
        }

        // fechando arquivos
        fclose(pF_hospedes);
        fclose(pF_temp);
    }

    switch (mode)
    {
    case 1:
        // Reescrevendo os dados do arquivo tempor�rio no arquivo principal
        pF_temp = fopen("..\\data\\temp.txt", "r");
        pF_hospedes = fopen("..\\data\\dados_hospedes.txt", "w");
        if (pF_hospedes == NULL || pF_temp == NULL)
        {
            exit(2);
        }
        break;
    case 2:
        // Reescrevendo os dados do arquivo tempor�rio no arquivo principal
        pF_temp = fopen("..\\data\\temp.dat", "rb");
        pF_hospedes = fopen("..\\data\\dados_hospedes.dat", "wb");
        if (pF_hospedes == NULL || pF_temp == NULL)
        {
            exit(2);
        }
        break;
    }

    if (mode != 3)
    {
        // fun��o vai copiar os dados do arquivo tempor�rio de volta para o original
        copiarArquivo(pF_temp, pF_hospedes);

        fclose(pF_temp);
        fclose(pF_hospedes);
    }

    return 0;
}