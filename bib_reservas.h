#ifndef BIB_RESERVAS_H 
#define BIB_RESERVAS_H

#include <stdio.h>
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

#endif