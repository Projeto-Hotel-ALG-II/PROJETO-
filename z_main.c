#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include "bib_quick_tools.h"

// FUN��ES: GEST�O E CADASTROS
#include "bib_cadastro_hotel.h"

// FUN��ES: VISUAIS
#include "z_visuais.h"

int main()
{
    str_fornecedores * f;
    str_op_sistemas * op;
    // STRUCT HOTEL
    str_hotel hotel;

    // STRUCTS RESERVAS
    // str_reservas reserva;

    int choice; // variavel armazena as escolhas feitas pelo usu�rio
    int mode;

    while (1)
    {
        printf("Digite o modo que deseja armazenar dados no seu sistema!\n");
        printf("1 - Arquivos de Texto (.txt).\n");
        printf("2 - Arquivos Bin�rios (.dat).\n");
        printf("3 - Memoria.\n");
        printf("4 - Cancelar.\n");
        printf("=> ");
        scanf("%d", &mode);

        if(mode == 4){
            return 0;
        }
        else if(mode == 1 || mode == 2 || mode == 3){
            break;
        }
    }

    // La�o de repeti��o principal
    while (1)
    {
        AnsiUpper(strcpy(hotel.nome_fantasia, "Muk-Luk Lodge")); // Nome provis�rio pro hotel
        choice = 0;                                              // evitando lixo de memoria

        clearPrompt(); // Limpando prompt

        // Menu Principal
        printf("BEM VINDO AO HOTEL: %s!\n", hotel.nome_fantasia);
        printf("Selecione uma op��o:\n");
        printf("1 - Cadastro e Gest�o de Dados\n");
        printf("2 - Reservas\n");
        printf("3 - Transa��es\n");
        printf("4 - Feedback\n");
        printf("5 - Importa��o/Exporta��o de Dados\n");
        printf("6 - Sair\n");
        printf("=> ");
        scanf("%d", &choice);

        // Swich para os M�dulos
        switch (choice)
        {
        case 1: // M�dulo 1 - Cadastro e Gest�o de Dados
            while (1)
            {
                clearPrompt();
                printf("=> CADASTRO E GEST�O DE DADOS\n");
                printf("Selecione uma op��o: \n");
                printf("1 - Hotel\n");
                printf("2 - H�spedes\n");
                printf("3 - Acomoda��es\n");
                printf("4 - Fornecedores\n");
                printf("5 - Produtos\n");
                printf("6 - Operadores\n");
                printf("7 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 7)
                {
                    break;
                }
                switch (choice)
                {
                case 1: // Campo 1 - Hotel - Jo�o Vitor *
                    visualCadastroHotel(mode);
                    break;
                case 2: // Campo 2 - H�spedes - Matheus Garcia *
                    visualCadastroHospedes(mode);
                    break;
                case 3: // Campo 3 - Acomoda��es - Iasmim Garcia *
                    visualCadastroAcomodacoes(mode);
                    break;
                case 4: // Campo 5 - Fornecedores - Matheus Garcia *
                    visualCadastroFornecedor(mode, f);
                    break;
                case 5: // Campo 6 - Produtos - Jo�o Vitor *
                    visualCadastroProdutos(mode);
                    break;
                case 6: // Campo 7 - Operadores - Iasmim Garcia *
                    visualCadastroOperadores(mode, op);
                    break;
                default: // Nenhuma das op��es
                    printf("\n[X] ERRO - Insira um valor v�lido!");
                    pausaSist();
                    break;
                }
            }
            break;

        case 2: // M�dulo 2 - Reservas

            break;
        case 3: // M�dulo 3 - Transa��es
            while (1)
            {
                clearPrompt();
                printf("=> TRANSA��ES\n");
                printf("Selecione uma op��o: \n");
                printf("1 - Check-in\n");
                printf("2 - Check-out\n");
                printf("3 - Sa�da de Produtos\n");
                printf("4 - Controle de Caixa\n");
                printf("5 - Contas a Receber\n");
                printf("6 - Contas a Pagar\n");
                printf("7 - Entrada de Produtos Industrializados\n");
                printf("8 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 8)
                {
                    break;
                }
                switch (choice)
                {
                case 1: // Se��o 1 - Check-in

                    break;
                case 2: // Se��o 2 - Check-out

                    break;
                case 3: // Transa��o 1 - Sa�da de produtos(venda)

                    break;
                case 4: // Constrole de caixa

                    break;
                case 5: // Transa��o 2 - Contas a Receber

                    break;
                case 6: // Transa��o 3 - Contas a Pagar

                    break;
                case 7: // Transa��o 4 - Entrada de Produtos Industrializados

                    break;
                default: // Nenhuma das op��es
                    printf("\n[X] ERRO - Insira um valor v�lido!");
                    pausaSist();
                    break;
                }
            }
            break;
        case 4: // M�dulo 4 - Feedback
            while (1)
            {
                clearPrompt();
                printf("=> FEEDBACK\n");
                printf("Selecione uma op��o: \n");
                printf(" 1 - Listagem de H�spedes\n");
                printf(" 2 - Listagem de Acomoda��es\n");
                printf(" 3 - Listagem de Reservas\n");
                printf(" 4 - Produtos em Estoque M�nimo\n");
                printf(" 5 - Listagem de Produtos de Consumo\n");
                printf(" 6 - Listagem de Movimenta��o das Acomoda��es\n");
                printf(" 7 - Vendas\n");
                printf(" 8 - Contas a Receber\n");
                printf(" 9 - Contas a Pagar\n");
                printf("10 - Movimenta��o de Caixa\n");
                printf("11 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 11)
                {
                    break;
                }
                switch (choice)
                {
                case 1: // Relat�rio 1 - Listagem de H�spedes

                    break;
                case 2: // Relat�rio 2 - Listagem de Acomoda��es

                    break;
                case 3: // Relat�rio 3 - Listagem de Reservas

                    break;
                case 4: // Relat�rio 4 - Produtos em Estoque M�nimo

                    break;
                case 5: // Relat�rio 5 - Listagem de Produtos de Consumo

                    break;
                case 6: // Relat�rio 6 - Listagem de Movimenta��o das Acomoda��es

                    break;
                case 7: // Relat�rio 7 - Vendas

                    break;
                case 8: // Relat�rio 8 - Contas a Receber

                    break;
                case 9: // Relat�rio 9 - Contas a Pagar

                    break;
                case 10: // Relat�rio 10 - Movimenta��o de caixa

                    break;
                default: // Nenhuma das op��es
                    printf("\n[X] ERRO - Insira um valor v�lido!");
                    pausaSist();
                    break;
                }
            }
            break;
        case 5: // M�dulo 5 - Importa��o/Exporta��o de Dados
            while (1)
            {
                clearPrompt();
                printf("=> Cadastro e Gest�o - H�spedes:\n");
                printf("Selecione uma op��o: \n");
                printf("1 - Importar\n");
                printf("2 - Exportar\n");
                printf("3 - Voltar\n");
                printf("=> ");
                scanf("%d", &choice);
                if (choice == 3)
                {
                    break;
                }
                switch (choice)
                {
                case 1: // Importar

                    break;
                case 2: // Exportar

                    break;
                default:
                    printf("\n[X] ERRO - Insira um valor v�lido! Pressione qualquer tecla para voltar");
                    pausaSist();
                    break;
                }
            }
            break;
        case 6:
            clearPrompt();
            printf("Tem certeza que deseja sair do sistema?\n");
            printf("                                       \n");
            printf("       1 - Sim     |     2 - N�o       \n");
            printf("=> ");
            scanf("%d", &choice);
            if (choice == 1)
            {
                rmvTemp();
                clearPrompt();
                return 0;
            }
            break;

        default: // Nenhuma das op��es
            printf("\n[X] ERRO - Insira um valor v�lido!");
            pausaSist();
            break;
        }
    }

    return 0;
}
