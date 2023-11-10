#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <sys/stat.h>

#include "bib_quick_tools.h"

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

    // ê somada uma unidade ao contador de linhas cada vez que o arquivo là uma linha
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
    char linha[1000]; // leitor tempor†rio para cada linha lida do arquivo

    // A cada linha lida no arquivo tempor†rio a mesma Ç escrita no arquivo original
    while (fgets(linha, sizeof(linha), pF_fileCopiada) != NULL)
    {
        fputs(linha, pF_fileCriada);
    }
}