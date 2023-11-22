#ifndef BIB_CADASTRO_HOTEL_H
#define BIB_CADASTRO_HOTEL_H

#include <stdio.h>

/*
 * Struct Hotel - Guarda os dados do Hotel em quest’o
 */
typedef struct
{
    char nome_fantasia[50];
    char razao_soc[100];
    char inscricao_estadual[20]; // Varia dependendo do estado
    char cnpj[19];               // XX.XXX.XXX/YYYY-ZZ
    char end_completo[100];
    char telefone[16]; // (ZZ) YXXXX-XXXX
    char email[50];
    char nome_responsavel[50];
    char tel_responsavel[16]; // (ZZ) YXXXX-XXXX
    char horario_checkin[6];  // XX:XX
    char horario_checkout[6];
    float margem_lucro; // XX,XX%
} str_hotel;

/**
 * Escreve os dados do hotel - caso o hotel exista ele ser  reescrito, s¢ ‚ poss¡vel existir um hotel
*/
int escreveHotel(int, str_hotel *);

/*
* Altera o hotel cadastrado
*/
int alteraHotel(int, str_hotel *);

/**
 * Lˆ o hotel cadastrado caso haja um
*/
int lerHotel(int, str_hotel *);

/**
 * deleta o hotel cadastrado
*/
int deletaHotel(int);

#endif