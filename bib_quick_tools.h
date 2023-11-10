#ifndef BIB_QUICK_TOOLS_H
#define BIB_QUICK_TOOLS_H

#include <stdio.h>

/*
 * Fun‡Æo limpa o prompt de comando
 */
void clearPrompt();

/*
 * Fun‡Æo pausa a aplica‡Æo e mostra o texto "Pressione qualquer tecla para continuar..."
 */
void pausaSist();

/*
 * Fun‡Æo apaga o arquivo tempor rio
 */
void rmvTemp();

/*
 * Fun‡Æo para contar linhas de um arquivo, exemplo: contadorLinhas("..\\data\\dados_nomeArq.dat");
 */
int contadorLinhas(char fileName[35]);

/*
 * Fun‡Æo para tornar arquivo temporario o arquivo principal, exemplo: substituiTemp("..\\data\\dados_arq.txt","..\\data\\temp.txt");
 */
int substituiTemp(char original[35], char temporario[35]);

/*
 * Fun‡Æo copia arquivo para outro, Primeiro argumento deve ser do arquivo que sera copiado e o segundo deve ser do arquivo que recebera os dados copiados
 */
void copiarArquivo(FILE *pF_fileCopiada, FILE *pF_fileCriada);

#endif