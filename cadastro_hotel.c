#include <stdio.h>
#include <string.h>
#include "bib_quick_tools.h"
#include "bib_cadastro_hotel.h"

int escreveHotel(int mode, str_hotel h);
int alteraHotel(int mode, str_hotel h);
int lerHotel(int mode, str_hotel *h);
int deletaHotel(int mode);

int escreveHotel(int mode, str_hotel h)
{
    FILE *ptr;
    switch (mode)
    {
    case 1: // USANDO ARQUIVO DE TEXTO
        ptr = fopen("..\\data\\dados_hotel.txt", "w");

        // CONDI€ÇO DE ERRO
        if (ptr == NULL)
        {
            return 1;
        }
        break;
    case 2: // USANDO ARQUIVO BINµRIO
        ptr = fopen("..\\data\\dados_hotel.dat", "wb");

        // CONDI€ÇO DE ERRO
        if (ptr == NULL)
        {
            return 1;
        }
        break;
    case 3: // USANDO MEMàRIA
        /* code */
        break;
    }

    if (mode != 3)
    {
        fprintf(ptr, "%s|", h.nome_fantasia);
        fprintf(ptr, "%s|", h.razao_soc);
        fprintf(ptr, "%s|", h.inscricao_estadual);
        fprintf(ptr, "%s|", h.cnpj);
        fprintf(ptr, "%s|", h.end_completo);
        fprintf(ptr, "%s|", h.telefone);
        fprintf(ptr, "%s|", h.email);
        fprintf(ptr, "%s|", h.nome_responsavel);
        fprintf(ptr, "%s|", h.tel_responsavel);
        fprintf(ptr, "%s|", h.horario_checkin);
        fprintf(ptr, "%s|", h.horario_checkout);
        fprintf(ptr, "%f|", h.margem_lucro);

        fclose(ptr);
    }
    else
    {
    }

    return 0;
}

int alteraHotel(int mode, str_hotel h)
{
    FILE *ptr;
    switch (mode)
    {
    case 1: // USANDO ARQUIVO DE TEXTO
        ptr = fopen("..\\data\\dados_hotel.txt", "w");

        // CONDI€ÇO DE ERRO
        if (ptr == NULL)
        {
            return 1;
        }
        break;

    case 2: // USANDO ARQUIVO BINµRIO
        ptr = fopen("..\\data\\dados_hotel.dat", "wb");

        // CONDI€ÇO DE ERRO
        if (ptr == NULL)
        {
            return 1;
        }
        break;

    case 3: // USANDO MEMàRIA
        /* code */
        break;
    }

    // CONDI€ÇO DE ERRO
    if (ptr == NULL)
    {
        return 1;
    }

    if (mode != 3)
    {
        fprintf(ptr, "%s|", h.nome_fantasia);
        fprintf(ptr, "%s|", h.razao_soc);
        fprintf(ptr, "%s|", h.inscricao_estadual);
        fprintf(ptr, "%s|", h.cnpj);
        fprintf(ptr, "%s|", h.end_completo);
        fprintf(ptr, "%s|", h.telefone);
        fprintf(ptr, "%s|", h.email);
        fprintf(ptr, "%s|", h.nome_responsavel);
        fprintf(ptr, "%s|", h.tel_responsavel);
        fprintf(ptr, "%s|", h.horario_checkin);
        fprintf(ptr, "%s|", h.horario_checkout);
        fprintf(ptr, "%f|", h.margem_lucro);

        fclose(ptr);
    }
    else
    {
    }

    return 0;
}

int lerHotel(int mode, str_hotel *h)
{
    str_hotel hotel;
    FILE *ptr;

    switch (mode)
    {
    case 1: // USANDO ARQUIVO DE TEXTO
        ptr = fopen("..\\data\\dados_hotel.txt", "r");

        // CONDI€ÇO DE ERRO
        if (ptr == NULL)
        {
            return 1;
        }
        break;

    case 2: // USANDO ARQUIVO BINµRIO
        ptr = fopen("..\\data\\dados_hotel.dat", "rb");

        // CONDI€ÇO DE ERRO
        if (ptr == NULL)
        {
            return 1;
        }
        break;

    case 3: // USANDO MEMàRIA
        /* code */
        break;
    }

    if (mode != 3)
    {
        fscanf(ptr, "%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%[^|]|%f|", hotel.nome_fantasia, hotel.razao_soc, hotel.inscricao_estadual, hotel.cnpj, hotel.end_completo, hotel.telefone, hotel.email, hotel.nome_responsavel, hotel.tel_responsavel, hotel.horario_checkin, hotel.horario_checkout, &hotel.margem_lucro);
    }
    else
    {
    }

    if (strcmp(hotel.nome_fantasia, "0") == 0)
    {
        return 1;
    }

    strcpy(h->nome_fantasia, hotel.nome_fantasia);
    strcpy(h->razao_soc, hotel.razao_soc);
    strcpy(h->inscricao_estadual, hotel.inscricao_estadual);
    strcpy(h->cnpj, hotel.cnpj);
    strcpy(h->end_completo, hotel.end_completo);
    strcpy(h->telefone, hotel.telefone);
    strcpy(h->email, hotel.email);
    strcpy(h->nome_responsavel, hotel.nome_responsavel);
    strcpy(h->tel_responsavel, hotel.tel_responsavel);
    strcpy(h->horario_checkin, hotel.horario_checkin);
    strcpy(h->horario_checkout, hotel.horario_checkout);
    h->margem_lucro = hotel.margem_lucro;

    fclose(ptr);

    return 0;
}

int deletaHotel(int mode)
{
    FILE *ptr;
    switch (mode)
    {
    case 1: // USANDO ARQUIVO DE TEXTO
        ptr = fopen("..\\data\\dados_hotel.txt", "w");

        // CONDI€ÇO DE ERRO
        if (ptr == NULL)
        {
            return 1;
        }
        break;

    case 2: // USANDO ARQUIVO BINµRIO
        ptr = fopen("..\\data\\dados_hotel.dat", "wb");

        // CONDI€ÇO DE ERRO
        if (ptr == NULL)
        {
            return 1;
        }
        break;

    case 3: // USANDO MEMàRIA
        /* code */
        break;
    }

    if (mode != 3)
    {
        fprintf(ptr, "0");
        fclose(ptr);
    }
    else
    {
    }
    
    return 0;
}
