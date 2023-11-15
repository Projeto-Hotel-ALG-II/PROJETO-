#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <string.h>
#include "bib_reservas.h"

// Fun��o ir� realizar a reserva
int reservar(int mode, str_reservas reserva)
{

    FILE *pF_reservas;

    switch (mode)
    {
    case 1:
        pF_reservas = fopen("..\\data\\reservas_feitas.txt", "r");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo de texto");
            return -1;
        }
        break;

    case 2:
        pF_reservas = fopen("..\\data\\reservas_feitas.dat", "rb");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo binário");
            return -1;
        }
        break;

    case 3:

    default:
        break;
    }

    if (pF_reservas != NULL)
    {
    }
}

// Fun��o pesquisa se h� disponibilidade por data
int pesquisaDisp_PorData(int mode, str_reservas reservas[], int num_reservas, struct tm check_in, struct tm check_out)
{
    FILE *pF_reservas = NULL;
    int ret = 0;

    switch (mode)
    {
    case 1:
        pF_reservas = fopen("..\\data\\reservas_feitas.txt", "r");
        if (pF_reservas == NULL)
        {
            printf("Erro na abertura do arquivo de texto");
            return 0;
        }
        break;

    case 2:
        pF_reservas = fopen("..\\data\\reservas_feitas.dat", "rb");
        if (pF_reservas == NULL)
        {
            printf("Erro na abertura do arquivo binário");
            return 0;
        }
        break;

    case 3:
        for (int i = 0; i < num_reservas; i++)
        {
            time_t reserva_inicio = mktime((&reservas[i].dia_iniReserva) && (&reservas[i].mes_iniReserva));
            time_t reserva_fim = mktime((&reservas[i].dia_fimReserva) && (&reservas[i].mes_fimReserva));

            time_t check_in_time = mktime(&check_in);
            time_t check_out_time = mktime(&check_out);

            if (check_in_time >= reserva_inicio && check_in_time < reserva_fim)
            {
                ret = 1;
                break;
            }

            if (check_out_time >= reserva_inicio && check_out_time < reserva_fim)
            {
                ret = 1;
                break;
            }

            if (check_in_time >= reserva_inicio && check_out_time <= reserva_fim)
            {
                ret = 1;
                break;
            }
        }
        break;

    default:
        return -1;
    }

    if (pF_reservas != NULL)
    {
        int disponibilidade = 1;
        char linha[100];

        while (fgets(linha, sizeof(linha), pF_reservas) != NULL)
        {
            struct tm reserva_inicio, reserva_fim;
            int dia_ini, mes_ini, dia_fim, mes_fim;
            int campos_lidos = sscanf(linha, "%d/%d %d/%d", &dia_ini, &mes_ini, &dia_fim, &mes_fim);
            if (campos_lidos != 4)
            {
                printf("Formato inválido no arquivo de reservas.\n");
                continue;
            }

            struct tm reserva_inicio = {0};
            reserva_inicio.tm_mday = dia_ini;
            reserva_inicio.tm_mon = mes_ini - 1;
            reserva_inicio.tm_year = check_in.tm_year;
            reserva_inicio.tm_hour = 0;
            reserva_inicio.tm_min = 0;
            reserva_inicio.tm_sec = 0;

            struct tm reserva_fim = {0};
            reserva_fim.tm_mday = dia_fim;
            reserva_fim.tm_mon = mes_fim - 1;
            reserva_fim.tm_year = check_in.tm_year;
            reserva_fim.tm_hour = 23;
            reserva_fim.tm_min = 59;
            reserva_fim.tm_sec = 59;

            time_t reserva_inicio_time = mktime(&reserva_inicio);
            time_t reserva_fim_time = mktime(&reserva_fim);

            time_t check_in_time = mktime(&check_in);
            time_t check_out_time = mktime(&check_out);

            if ((check_in_time >= reserva_inicio_time && check_in_time <= reserva_fim_time) ||
                (check_out_time >= reserva_inicio_time && check_out_time <= reserva_fim_time))
            {
                disponibilidade = 0;
                break;
            }
        }

        fclose(pF_reservas);
        return disponibilidade;
    }

    return ret;
}

// Fun��o pesquisa disponibilidade por categoria
int pesquisaDisp_PorCategoria(int mode, int codigoCateg, int dias_verifica)
{
    FILE *pF_reservas = NULL;
    str_reservas reservas;

    time_t agora = time(NULL);
    struct tm data_atual = *localtime(&agora);

    int disponibilidade = 1;
    time_t dia_verif = agora + dias_verifica * 24 * 60 * 60;

    switch (mode)
    {
    case 1:
        pF_reservas = fopen("..\\data\\reservas_feitas.txt", "r");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo de texto");
            return -1;
        }
        break;

    case 2:
        pF_reservas = fopen("..\\data\\reservas_feitas.dat", "rb");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo binário");
            return -1;
        }
        break;

    case 3:
        int num_reservas[5];

        for (int i = 0; i < num_reservas[5]; i++)
        {
            if (reservas.acomod.catec_acomod.codigo == codigoCateg)
            {
                struct tm inicio_reserva = {0};
                inicio_reserva.tm_year = data_atual.tm_year;
                inicio_reserva.tm_mon = reservas.mes_iniReserva - 1;
                inicio_reserva.tm_mday = reservas.dia_iniReserva;

                struct tm fim_reserva = {0};
                fim_reserva.tm_year = data_atual.tm_year;
                fim_reserva.tm_mon = reservas.mes_fimReserva - 1;
                fim_reserva.tm_mday = reservas.dia_fimReserva;

                time_t ireserva = mktime(&inicio_reserva);
                time_t freserva = mktime(&fim_reserva);

                if (freserva >= agora && ireserva <= dia_verif)
                {
                    disponibilidade = 0;
                }
            }
        }
        return disponibilidade;
        break;

    default:
        return -1;
    }

    if (pF_reservas != NULL)
    {

        char linha[100];
        while (fgets(linha, sizeof(linha), pF_reservas) != NULL)
            ;
        {

            if (sscanf(linha, "%d/%d %d/%d %d", &reservas.dia_iniReserva, &reservas.mes_iniReserva, &reservas.dia_fimReserva, &reservas.mes_fimReserva, &reservas.acomod.catec_acomod.codigo) == 5)
            {
                if (reservas.acomod.catec_acomod.codigo == codigoCateg)
                {
                    struct tm inicio_reserva = {0};
                    inicio_reserva.tm_year = data_atual.tm_year;
                    inicio_reserva.tm_mon = reservas.mes_iniReserva - 1;
                    inicio_reserva.tm_mday = reservas.dia_iniReserva;

                    struct tm fim_reserva = {0};
                    fim_reserva.tm_year = data_atual.tm_year;
                    fim_reserva.tm_mon = reservas.mes_fimReserva - 1;
                    fim_reserva.tm_mday = reservas.dia_fimReserva;

                    time_t ireserva = mktime(&inicio_reserva);
                    time_t freserva = mktime(&fim_reserva);

                    if (freserva >= agora && ireserva <= dia_verif)
                    {
                        disponibilidade = 0;
                    }
                }
            }
        }
        fclose(pF_reservas);
        return disponibilidade;
    }
}

// Fun��o pesquisa disponibilidade por quantidade de pessoas
int pesquisaDisp_PorQtdPessoas(int mode, str_reservas reservas[], int num_reservas, int num_pessoas, int dias_verifica)
{
    FILE *pF_reservas = NULL;
    str_reservas reserva;

    time_t agora = time(NULL);
    struct tm data_atual = *localtime(&agora);

    int disponibilidade = 1;
    time_t dia_verif = agora + dias_verifica * 24 * 60 * 60;

    switch (mode)
    {
    case 1:
        pF_reservas = fopen("..\\data\\reservas_feitas.txt", "r");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo de texto");
            return -1;
        }
        break;

    case 2:
        pF_reservas = fopen("..\\data\\reservas_feitas.dat", "rb");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo binário");
            return -1;
        }
        break;

    case 3:
        for (int i = 0; i < num_reservas; i++)
        {
            if (reservas[i].acomod.catec_acomod.qtd_pessoas >= num_pessoas)
            {
                struct tm inicio_reserva = {0};
                inicio_reserva.tm_year = data_atual.tm_year;
                inicio_reserva.tm_mon = reservas[i].mes_iniReserva - 1;
                inicio_reserva.tm_mday = reservas[i].dia_iniReserva;

                struct tm fim_reserva = {0};
                fim_reserva.tm_year = data_atual.tm_year;
                fim_reserva.tm_mon = reservas[i].mes_fimReserva - 1;
                fim_reserva.tm_mday = reservas[i].dia_fimReserva;

                time_t ireserva = mktime(&inicio_reserva);
                time_t freserva = mktime(&fim_reserva);

                if (freserva >= agora && ireserva <= dia_verif)
                {
                    disponibilidade = 0;
                }
            }
        }
        return disponibilidade;

    default:
        return -1;
    }

    if (pF_reservas != NULL)
    {
        char linha[100];
        while (fgets(linha, sizeof(linha), pF_reservas) != NULL)
        {
            if (sscanf(linha, "%d/%d %d/%d %d %d", &reserva.dia_iniReserva, &reserva.mes_iniReserva, &reserva.dia_fimReserva, &reserva.mes_fimReserva, &reserva.acomod.codigo, &reserva.acomod.catec_acomod.qtd_pessoas) == 6)
            {
                if (reserva.acomod.catec_acomod.qtd_pessoas >= num_pessoas)
                {
                    struct tm inicio_reserva = {0};
                    inicio_reserva.tm_year = data_atual.tm_year;
                    inicio_reserva.tm_mon = reserva.mes_iniReserva - 1;
                    inicio_reserva.tm_mday = reserva.dia_iniReserva;

                    struct tm fim_reserva = {0};
                    fim_reserva.tm_year = data_atual.tm_year;
                    fim_reserva.tm_mon = reserva.mes_fimReserva - 1;
                    fim_reserva.tm_mday = reserva.dia_fimReserva;

                    time_t ireserva = mktime(&inicio_reserva);
                    time_t freserva = mktime(&fim_reserva);

                    if (freserva >= agora && ireserva <= dia_verif)
                    {
                        disponibilidade = 0;
                    }
                }
            }
        }
        fclose(pF_reservas);
        return disponibilidade;
    }
}

// Fun��o pesquisa disponibilidade pelas facilidades
int pesquisaPor_Facilidades(int mode, str_reservas reservas[], int num_reservas, const char *facilidades_desejadas, int dias_verifica)
{
    FILE *pF_reservas = NULL;
    str_reservas reserva;

    time_t agora = time(NULL);
    struct tm data_atual = *localtime(&agora);

    int disponibilidade = 1;
    time_t dia_verif = agora + dias_verifica * 24 * 60 * 60;

    switch (mode)
    {
    case 1:
        pF_reservas = fopen("..\\data\\reservas_feitas.txt", "r");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo de texto");
            return -1;
        }
        break;

    case 2:
        pF_reservas = fopen("..\\data\\reservas_feitas.dat", "rb");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo binário");
            return -1;
        }
        break;

    case 3:
        for (int i = 0; i < num_reservas; i++)
        {
            const char *facilidades_acomodacao = reservas[i].acomod.facilidades;
            time_t inicio_reserva = mktime(&reservas[i].dia_iniReserva);
            time_t fim_reserva = mktime(&reservas[i].dia_fimReserva);

            if (strstr(facilidades_acomodacao, facilidades_desejadas) != NULL)
            {
                if (inicio_reserva <= agora && fim_reserva >= agora)
                {
                    disponibilidade = 0;
                    break;
                }
                for (int dia = 0; dia <= dias_verifica; dia++)
                {
                    time_t dia_verifica = agora + dia * 24 * 60 * 60;
                    if (inicio_reserva <= dia_verifica && fim_reserva >= dia_verifica)
                    {
                        disponibilidade = 0;
                        break;
                    }
                }
            }
        }
        return disponibilidade;

    default:
        return -1;
    }

    if (pF_reservas != NULL)
    {
        char linha[100];
        while (fgets(linha, sizeof(linha), pF_reservas) != NULL)
        {
            if (sscanf(linha, "%d/%d %d/%d %d %d", &reserva.dia_iniReserva, &reserva.mes_iniReserva, &reserva.dia_fimReserva, &reserva.mes_fimReserva, &reserva.acomod.codigo, &reserva.acomod.catec_acomod.qtd_pessoas) == 6)
            {
                const char *facilidades_acomodacao = reserva.acomod.facilidades;
                time_t inicio_reserva = mktime(&reserva.dia_iniReserva);
                time_t fim_reserva = mktime(&reserva.dia_fimReserva);

                if (strstr(facilidades_acomodacao, facilidades_desejadas) != NULL)
                {
                    if (inicio_reserva <= agora && fim_reserva >= agora)
                    {
                        disponibilidade = 0;
                        break;
                    }
                    for (int dia = 0; dia <= dias_verifica; dia++)
                    {
                        time_t dia_verifica = agora + dia * 24 * 60 * 60;
                        if (inicio_reserva <= dia_verifica && fim_reserva >= dia_verifica)
                        {
                            disponibilidade = 0;
                            break;
                        }
                    }
                }
            }
        }
        fclose(pF_reservas);
        return disponibilidade;
    }
}

// Fun��o pesquisa disponibilidade por uma combina��o das demais pesquisas
int pesquisaDisponibilidade(int mode, str_reservas reservas[], int num_reservas, struct tm check_in, struct tm check_out, int codigo_categ, int num_pessoas, const char *facilidades_desejadas, int dias_verifica)
{
    FILE *pF_reservas = NULL;
    str_reservas reserva;

    time_t agora = time(NULL);
    struct tm data_atual = *localtime(&agora);
    time_t dia_verif = agora + dias_verifica * 24 * 60 * 60;

    int disponibilidade = 1;

    switch (mode)
    {
    case 1:
        pF_reservas = fopen("..\\data\\reservas_feitas.txt", "r");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo de texto");
            return -1;
        }
        break;

    case 2:
        pF_reservas = fopen("..\\data\\reservas_feitas.dat", "rb");
        if (pF_reservas == NULL)
        {
            perror("Erro na abertura do arquivo binário");
            return -1;
        }
        break;

    case 3:
        for (int i = 0; i < num_reservas; i++)
        {
            if (codigo_categ != -1 && reservas[i].acomod.catec_acomod.codigo != codigo_categ)
            {
                continue;
            }

            if (num_pessoas != -1 && reservas[i].acomod.catec_acomod.qtd_pessoas < num_pessoas)
            {
                continue;
            }

            if (facilidades_desejadas[0] != '\0' && strstr(reservas[i].acomod.facilidades, facilidades_desejadas) == NULL)
            {
                continue;
            }

            struct tm inicio_reserva = {0};
            inicio_reserva.tm_year = data_atual.tm_year;
            inicio_reserva.tm_mon = reservas[i].mes_iniReserva - 1;
            inicio_reserva.tm_mday = reservas[i].dia_iniReserva;

            struct tm fim_reserva = {0};
            fim_reserva.tm_year = data_atual.tm_year;
            fim_reserva.tm_mon = reservas[i].mes_fimReserva - 1;
            fim_reserva.tm_mday = reservas[i].dia_fimReserva;

            time_t ireserva = mktime(&inicio_reserva);
            time_t freserva = mktime(&fim_reserva);

            if (freserva >= agora && ireserva <= dia_verif)
            {
                disponibilidade = 0;
                break;
            }
        }
        return disponibilidade;

    default:
        return -1;
    }

    if (pF_reservas != NULL)
    {
        char linha[100];
        while (fgets(linha, sizeof(linha), pF_reservas) != NULL)
        {
            if (sscanf(linha, "%d/%d %d/%d %d %d %s", &reserva.dia_iniReserva, &reserva.mes_iniReserva, &reserva.dia_fimReserva, &reserva.mes_fimReserva, &reserva.acomod.catec_acomod.codigo, &reserva.acomod.catec_acomod.qtd_pessoas, reserva.acomod.facilidades) == 7)
            {
                if (codigo_categ != -1 && reserva.acomod.catec_acomod.codigo != codigo_categ)
                {
                    continue;
                }

                if (num_pessoas != -1 && reserva.acomod.catec_acomod.qtd_pessoas < num_pessoas)
                {
                    continue;
                }

                if (facilidades_desejadas[0] != '\0' && strstr(reserva.acomod.facilidades, facilidades_desejadas) == NULL)
                {
                    continue;
                }

                struct tm inicio_reserva = {0};
                inicio_reserva.tm_year = data_atual.tm_year;
                inicio_reserva.tm_mon = reserva.mes_iniReserva - 1;
                inicio_reserva.tm_mday = reserva.dia_iniReserva;

                struct tm fim_reserva = {0};
                fim_reserva.tm_year = data_atual.tm_year;
                fim_reserva.tm_mon = reserva.mes_fimReserva - 1;
                fim_reserva.tm_mday = reserva.dia_fimReserva;

                time_t ireserva = mktime(&inicio_reserva);
                time_t freserva = mktime(&fim_reserva);

                if (freserva >= agora && ireserva <= dia_verif)
                {
                    disponibilidade = 0;
                    break;
                }
            }
        }

        fclose(pF_reservas);
        return disponibilidade;
    }
}
