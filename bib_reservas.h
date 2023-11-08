#ifndef BIB_RESERVAS_H
#define BIB_RESERVAS_H

#include <stdio.h>
#include <time.h>
#include "bib_cadastro_acomodacoes.h"

typedef struct
{
    int codigo;
    int dia_iniReserva;
    int mes_iniReserva;
    int dia_fimReserva;
    int mes_fimReserva;
    int tempo_Reserva; // em dias
    str_acomodacoes acomod;
} str_reservas;

/*
 * FUN€ÇO FAZ A RESERVA
 */
int reservar(int mode, str_reservas reserva);

/*
 * FUN€ÇO PESQUISA RESERVA POR DISPONIBILIDADE DE DATAS
 */
int pesquisaDisp_PorData(int mode, str_reservas reservas[], int num_reservas, struct tm check_in, struct tm check_out);

/*
 * FUN€ÇO PESQUISA RESERVA POR CATEGORIA
 */
int pesquisaDisp_PorCategoria(int codigoCateg, int dias_verifica);

/*
 * FUN€ÇO PESQUISA RESERVA PELA QUANTIDADE DE PESSOAS
 */
int pesquisaDisp_PorQtdPessoas(int mode, str_reservas reservas[], int num_reservas, int num_pessoas, int dias_verifica);

/*
 * FUN€ÇO PESQUISA RESERVA PELAS FACILIDADES
 */
int pesquisaPor_Facilidades(int mode, str_reservas reservas[], int num_reservas, const char *facilidades_desejadas, int dias_verifica);

/*
 * FUN€ÇO PESQUISA RESERVA POR UMA COMBINA€ÇO DAS DEMAIS PESQUISAS
 */
int pesquisaDisponibilidade(int mode, str_reservas reservas[], int num_reservas, struct tm check_in, struct tm check_out, int codigo_categ, int num_pessoas, const char *facilidades_desejadas, int dias_verifica);

#endif