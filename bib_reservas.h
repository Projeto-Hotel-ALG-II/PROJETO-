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

#endif