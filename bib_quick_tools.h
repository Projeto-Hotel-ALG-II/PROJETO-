#ifndef BIB_QUICK_TOOLS_H
#define BIB_QUICK_TOOLS_H

#include <stdio.h>

/*
 * Fun��o limpa o prompt de comando
 */
void clearPrompt();

/*
 * Fun��o pausa a aplica��o e mostra o texto "Pressione qualquer tecla para continuar..."
 */
void pausaSist();

/*
 * Fun��o apaga o arquivo tempor�rio
 */
void rmvTemp();

/*
 * Fun��o para contar linhas de um arquivo, exemplo: contadorLinhas("..\\data\\dados_nomeArq.dat");
 */
int contadorLinhas(char fileName[35]);

/*
 * Fun��o para tornar arquivo temporario o arquivo principal, exemplo: substituiTemp("..\\data\\dados_arq.txt","..\\data\\temp.txt");
 */
int substituiTemp(char original[35], char temporario[35]);

/*
 * Fun��o copia arquivo para outro, Primeiro argumento deve ser do arquivo que sera copiado e o segundo deve ser do arquivo que recebera os dados copiados
 */
void copiarArquivo(FILE *pF_fileCopiada, FILE *pF_fileCriada);

#endif