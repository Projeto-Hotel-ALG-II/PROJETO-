#ifndef BIB_RESERVAS_H
#define BIB_RESERVAS_H

#include <stdio.h>
#include <time.h>
#include "bib_cadastro_acomodacoes.h"

typedef struct
{
    int codigo;
    time_t dia_iniReserva;
    time_t mes_iniReserva;
    time_t dia_fimReserva;
    time_t mes_fimReserva;
    time_t tempo_Reserva; // em dias
    str_acomodacoes acomod;
} str_reservas;

/*
 * FUN��O FAZ A RESERVA
 */
int reservar(int mode, str_reservas reserva);

/*
 * FUN��O PESQUISA RESERVA POR DISPONIBILIDADE DE DATAS
 */
int pesquisaDisp_PorData(int mode, str_reservas reservas[], int num_reservas, struct tm check_in, struct tm check_out);

/*
 * FUN��O PESQUISA RESERVA POR CATEGORIA
 */
int pesquisaDisp_PorCategoria(int codigoCateg, int dias_verifica);

/*
 * FUN��O PESQUISA RESERVA PELA QUANTIDADE DE PESSOAS
 */
int pesquisaDisp_PorQtdPessoas(int mode, str_reservas reservas[], int num_reservas, int num_pessoas, int dias_verifica);

/*
 * FUN��O PESQUISA RESERVA PELAS FACILIDADES
 */
int pesquisaPor_Facilidades(int mode, str_reservas reservas[], int num_reservas, const char *facilidades_desejadas, int dias_verifica);

/*
 * FUN��O PESQUISA RESERVA POR UMA COMBINA��O DAS DEMAIS PESQUISAS
 */
int pesquisaDisponibilidade(int mode, str_reservas reservas[], int num_reservas, struct tm check_in, struct tm check_out, int codigo_categ, int num_pessoas, const char *facilidades_desejadas, int dias_verifica);

#endif