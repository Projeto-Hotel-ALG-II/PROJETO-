#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sys/stat.h>

#include "bib_quick_tools.h"
#include "bib_reservas.h"

void clearPrompt()
{
    system("cls");
}

void pausaSist()
{
    printf("\nPressione qualquer tecla para continuar . . .");
    getch();
}

void rmvTemp()
{
    remove("..\\data\\temp.txt");
    remove("..\\data\\temp.dat");
}

int contadorLinhas(char fileName[35])
{
    FILE *pF;
    char linha[1000];
    int qtdLinhas = 1;
    pF = fopen(fileName, "r");

    //  somada uma unidade ao contador de linhas cada vez que o arquivo lˆ uma linha
    while (fgets(linha, sizeof(linha), pF) != NULL)
    {
        qtdLinhas++;
    }
    fclose(pF);
    return qtdLinhas;
}

int substituiTemp(char original[35], char temporario[35])
{

    if (chmod(original, S_IWUSR) == 0 && chmod(temporario, S_IWUSR) == 0)
    {
        remove(original);
        rename(temporario, original);
    }

    return 0;
}

void copiarArquivo(FILE *pF_fileCopiada, FILE *pF_fileCriada)
{
    char linha[1000]; // leitor tempor rio para cada linha lida do arquivo

    // A cada linha lida no arquivo tempor rio a mesma ‚ escrita no arquivo original
    while (fgets(linha, sizeof(linha), pF_fileCopiada) != NULL)
    {
        fputs(linha, pF_fileCriada);
    }
}

int incrementaData(str_reservas *r)
{
    int rest;
    if (r->mes_iniReserva == 1 || r->mes_iniReserva == 3 || r->mes_iniReserva == 5 || r->mes_iniReserva == 7 || r->mes_iniReserva == 8 || r->mes_iniReserva == 10 || r->mes_iniReserva == 12)
    {
        if (r->dia_iniReserva < 31)
        {
            r->dia_iniReserva++;
            return 0;
        }
        else
        {
            if (r->mes_iniReserva < 12)
            {
                r->mes_iniReserva++;
                r->dia_iniReserva = 1;
                return 0;
            }
            else
            {
                r->ano_iniReserva++;
                r->mes_iniReserva = 1;
                r->dia_iniReserva = 1;
                return 0;
            }
        }
    }
    else if (r->mes_iniReserva == 4 || r->mes_iniReserva == 6 || r->mes_iniReserva == 9 || r->mes_iniReserva == 11)
    {
        if (r->dia_iniReserva < 30)
        {
            r->dia_iniReserva++;
            return 0;
        }
        else
        {
            r->mes_iniReserva++;
            r->dia_iniReserva = 1;
            return 0;
        }
    }
    else if (r->mes_iniReserva == 2)
    {
        rest = r->ano_iniReserva % 4;
        if (rest != 0)
        {
            if (r->dia_iniReserva < 28)
            {
                r->dia_iniReserva++;
                return 0;
            }
            else
            {
                r->mes_iniReserva++;
                r->dia_iniReserva = 1; 
                return 0;
            }
        }
        else
        {
            if (r->dia_iniReserva < 29)
            {
                r->dia_iniReserva++;
                return 0;
            }
            else
            {
                r->mes_iniReserva++;
                r->dia_iniReserva = 1; 
                return 0;
            } 
        }
    }

    return 1;
}
