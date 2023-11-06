#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// BIBLIOTECA DE FERRAMENTAS
#include "bib_quick_tools.h"

// BIBLIOTECAS - CADASTRO E GEST∂O DE DADOS
#include "bib_cadastro_hotel.h"
#include "bib_cadastro_hospedes.h"
#include "bib_cadastro_acomodacoes.h"
#include "bib_cadastro_fornecedores.h"
#include "bib_cadastro_produtos.h"
#include "bib_cadastro_operadores.h"

// BIBLIOTECA - RESERVAS
#include "bib_reservas.h"

void visualCadastroHotel(int mode)
{
    str_hotel hot;
    int ret;
    int choice;

    while (1)
    {
        clearPrompt();
        printf("Gest∆o dos dados do Hotel:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Visualizar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n");
        printf("=> ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            break;
        }

        switch (choice)
        {
        case 1: // CADASTRANDO
            printf("DIGITE O NOME FANTASIA DO HOTEL: ");
            fflush(stdin);
            scanf("%[^\n]", hot.nome_fantasia);

            printf("DIGITE A RAZ«O SOCIAL: ");
            fflush(stdin);
            scanf("%[^\n]", hot.razao_soc);

            printf("DIGITE A INSCRIÄ«O ESTADUAL: ");
            fflush(stdin);
            scanf("%[^\n]", hot.inscricao_estadual);

            printf("DIGITE O CNPJ: ");
            fflush(stdin);
            scanf("%[^\n]", hot.cnpj);

            printf("DIGITE O ENDEREÄO COMPLETO: ");
            fflush(stdin);
            scanf("%[^\n]", hot.end_completo);

            printf("DIGITE O TELEFONE: ");
            fflush(stdin);
            scanf("%[^\n]", hot.telefone);

            printf("DIGITE O E-MAIL: ");
            fflush(stdin);
            scanf("%[^\n]", hot.email);

            printf("DIGITE O NOME DO RESPONSµVEL: ");
            fflush(stdin);
            scanf("%[^\n]", hot.nome_responsavel);

            printf("DIGITE O TELEFONE DO RESPONSµVEL: ");
            fflush(stdin);
            scanf("%[^\n]", hot.tel_responsavel);

            printf("DIGITE O HORµRIO DE CHECK-IN: ");
            fflush(stdin);
            scanf("%[^\n]", hot.horario_checkin);

            printf("DIGITE O HORµRIO DE CHECK-OUT: ");
            fflush(stdin);
            scanf("%[^\n]", hot.horario_checkout);

            printf("DIGITE A MARGEM DE LUCRO DE PRODUTOS VENDIDOS: ");
            fflush(stdin);
            scanf("%f", &hot.margem_lucro);

            ret = escreveHotel(mode, hot);
            if (ret == 0)
            {
                printf("HOTEL REGISTRADO COM SUCESSO!");
                pausaSist();
            }
            else
            {
                printf("PROBLEMA NO REGISTRO.");
                pausaSist();
            }
            break;

        case 2: // LENDO DADOS
            ret = lerHotel(mode, &hot);
            if (ret == 0)
            {
                printf("=> Dados do hotel carregados!\n");
                printf("=========================================\n");
                printf("NOME FANTASIA           : %s\n", hot.nome_fantasia);
                printf("RAZ«O SOCIAL            : %s\n", hot.razao_soc);
                printf("INSCRI««O ESTADUAL      : %s\n", hot.inscricao_estadual);
                printf("CNPJ                    : %s\n", hot.cnpj);
                printf("ENDERE«O COMPLETO       : %s\n", hot.end_completo);
                printf("TELEFONE                : %s\n", hot.telefone);
                printf("E-MAIL                  : %s\n", hot.email);
                printf("NOME DO RESPONSAVEL     : %s\n", hot.nome_responsavel);
                printf("TELEFONE DO RESPONSµVEL : %s\n", hot.tel_responsavel);
                printf("HORARIO DE CHECK-IN     : %sh\n", hot.horario_checkin);
                printf("HORARIO DE CHECK-OUT    : %sh\n", hot.horario_checkout);
                printf("MARGEM DE LUCRO         : %.1f%%\n", hot.margem_lucro);
                pausaSist();
            }

            else
            {
                printf("ERRO AO CARREGAR DADOS\n");
                pausaSist();
            }

            break;

        case 3: //
            // MENU DE CAMPOS DO REGISTRO_HOTEL
            ret = lerHotel(mode, &hot);
            if (ret == 1)
            {
                printf("N«O EXISTEM DADOS NO ARQUIVO.\n");
                pausaSist();
            }
            else
            {
                while (1)
                {
                    clearPrompt();
                    printf("Qual campo deseja alterar?\n");
                    printf("1   - NOME FANTASIA           - %s\n", hot.nome_fantasia);
                    printf("2   - RAZ«O SOCIAL            - %s\n", hot.razao_soc);
                    printf("3   - INSCRI««O ESTADUAL      - %s\n", hot.inscricao_estadual);
                    printf("4   - CNPJ                    - %s\n", hot.cnpj);
                    printf("5   - ENDEREÄO COMPLETO       - %s\n", hot.end_completo);
                    printf("6   - TELEFONE                - %s\n", hot.telefone);
                    printf("7   - E-MAIL                  - %s\n", hot.email);
                    printf("8   - NOME DO RESPONSAVEL     - %s\n", hot.nome_responsavel);
                    printf("9   - TELEFONE DO RESPONSµVEL - %s\n", hot.tel_responsavel);
                    printf("10 - HORARIO DE CHECK-IN      - %s\n", hot.horario_checkin);
                    printf("11 - HORARIO DE CHECK-OUT     - %s\n", hot.horario_checkout);
                    printf("12 - MARGEM DE LUCRO          - %.1f%%\n\n", hot.margem_lucro);

                    printf("13 - Cancelar\n");
                    printf("14 - Confirmar Mudanáas\n");
                    printf("=> ");
                    scanf("%d", &choice);

                    if (choice == 13 || choice == 14)
                    {
                        break;
                    }

                    if (choice == 1)
                    {
                        printf("DIGITE O NOME FANTASIA: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.nome_fantasia);
                    }
                    else if (choice == 2)
                    {
                        printf("DIGITE A RAZ«O SOCIAL: ");
                        fflush(stdin);

                        scanf("%[^\n]s", hot.razao_soc);
                    }
                    else if (choice == 3)
                    {
                        printf("DIGITE A INSCRIÄ«O SOCIAL: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.inscricao_estadual);
                    }
                    else if (choice == 4)
                    {
                        printf("DIGITE O CNPJ: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.cnpj);
                    }
                    else if (choice == 5)
                    {
                        printf("DIGITE O ENDEREÄO COMPLETO: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.end_completo);
                    }
                    else if (choice == 6)
                    {
                        printf("DIGITE O TELEFONE: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.telefone);
                    }
                    else if (choice == 7)
                    {
                        printf("DIGITE O E-MAIL: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.email);
                    }
                    else if (choice == 8)
                    {
                        printf("DIGITE O NOME DO RESPONSµVEL: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.nome_responsavel);
                    }

                    else if (choice == 9)
                    {
                        printf("DIGITE O TELEFONE DO RESPONSAVEL: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.tel_responsavel);
                    }
                    else if (choice == 10)
                    {
                        printf("DIGITE O HORµRIO CHECK-IN: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.horario_checkin);
                    }
                    else if (choice == 11)
                    {
                        printf("DIGITE O HORµRIO DE CHECK-OUT: ");
                        fflush(stdin);
                        scanf("%[^\n]s", hot.horario_checkout);
                    }
                    else if (choice == 12)
                    {
                        printf("DIGITE A MARGEM: ");
                        fflush(stdin);
                        scanf("%f", &hot.margem_lucro);
                    }
                }

                if (choice == 14)
                {
                    ret = alteraHotel(mode, hot);
                    if (ret == 1)
                    {
                        printf("ERRO AO ALTERAR.\n");
                        pausaSist();
                    }
                    else
                    {
                        printf("CAMPO ALTERADO COM SUCESSO.\n");
                        pausaSist();
                    }
                }
            }

            break;

        case 4:
            printf("Tem certeza que deseja apagar os dados do hotel?\n");
            printf("1 - Sim\n");
            printf("2 - N∆o\n");
            printf("=> ");
            scanf("%d", &choice);

            if (choice == 1)
            {
                ret = deletaHotel(mode);
                if (ret == 1)
                {
                    printf("ERRO AO DELETAR DADOS");
                    pausaSist();
                }
                else
                {
                    printf("DADOS DELETADOS");
                    pausaSist();
                }
            }

            break;
        }
    }
    return 0;
}

void visualCadastroHospedes(int mode)
{
    int choice; // armazena as escolhas de navegabilidade do usu†rio
    int ret;    // armazena o retorno das funá‰es
    str_hospedes hospedes;

    while (1)
    {
        clearPrompt();
        // menu principal da seá∆o cadastro de hospedes
        printf("Cadastro e Gest∆o de H¢spedes:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n");
        printf("=> ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            break;
        }

        switch (choice)
        {
        case 1: // ===== CADASTRAR H‡SPEDE =====

            // recolhendo dados do novo hospede
            fflush(stdin);
            printf("Indique o nome               : ");
            scanf(" %[^\n]", hospedes.nome);

            fflush(stdin); // Limpa o buffer
            printf("Indique o endereáo completo  : ");
            scanf(" %[^\n]", hospedes.end_completo);

            fflush(stdin);
            printf("Indique o CPF                : ");
            scanf(" %[^\n]", hospedes.cpf);

            fflush(stdin);
            printf("Indique o telefone           : ");
            scanf(" %[^\n]", hospedes.telefone);

            fflush(stdin);
            printf("Indique o e-mail             : ");
            scanf(" %[^\n]", hospedes.email);

            fflush(stdin);
            printf("Indique o sexo               : ");
            hospedes.sexo = getch();
            printf("%c\n", hospedes.sexo);

            fflush(stdin);
            printf("Indique o estado civil       : ");
            scanf("%[^\n]", hospedes.estado_civil);

            fflush(stdin);
            printf("Indique a data de nascimento : ");
            scanf("%[^\n]", hospedes.data_nasc);

            // funá∆o cadastra os h¢spedes
            ret = cadastrarHospede(mode, hospedes);

            if (ret == 0)
            {
                printf("\nH¢spede cadastrado com sucesso!");
                pausaSist();
            }
            else
            {
                printf("Erro ao acessar o arquivo dados_hospedes.txt\n");
                pausaSist();
            }

            break;

        case 2: // ===== PESQUISAR H‡SPEDE =====
            printf("Pesquisar H¢spede: \n");
            printf("CPF do h¢spede (XXX.XXX.XXX-XX): ");
            fflush(stdin);
            scanf("%s", hospedes.cpf);

            ret = pesquisarHospede(mode, hospedes.cpf, &hospedes);

            if (ret == 0)
            {
                printf("=> H¢spede encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", hospedes.codigo);
                printf("Nome               : %s\n", hospedes.nome);
                printf("Endereáo           : %s\n", hospedes.end_completo);
                printf("CPF                : %s\n", hospedes.cpf);
                printf("Telefone           : %s\n", hospedes.telefone);
                printf("E-mail             : %s\n", hospedes.email);
                printf("Sexo               : %c\n", hospedes.sexo);
                printf("Estado Civil       : %s\n", hospedes.estado_civil);
                printf("Data de Nascimento : %s\n", hospedes.data_nasc);
                pausaSist();
            }
            else
            {
                printf("=> H¢spede n∆o encontrado!\n");
                pausaSist();
            }
            break;
        case 3: // ===== ALTERAR H‡SPEDE =====
            clearPrompt();
            printf("Alterar h¢spede:\n");

            printf("Informe o CPF: \n");
            fflush(stdin);
            scanf("%s", hospedes.cpf);

            printf("\n");

            ret = pesquisarHospede(mode, hospedes.cpf, &hospedes);

            if (ret == 0)
            {
                printf("=> H¢spede encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", hospedes.codigo);
                printf("Nome               : %s\n", hospedes.nome);
                printf("Telefone           : %s\n", hospedes.telefone);
                printf("Email              : %s\n", hospedes.email);
                printf("Data de Nascimento : %s\n", hospedes.data_nasc);
                printf("=========================================\n");
                printf("Deseja alterar este h¢spede?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    while (1)
                    {
                        fflush(stdin);
                        clearPrompt();
                        printf("Qual campo deseja alterar?\n");
                        printf("1 - Nome               - %s.\n", hospedes.nome);
                        printf("2 - Endereáo Completo  - %s.\n", hospedes.end_completo);
                        printf("3 - CPF                - %s.\n", hospedes.cpf);
                        printf("4 - Telefone           - %s.\n", hospedes.telefone);
                        printf("5 - Email              - %s.\n", hospedes.email);
                        printf("6 - Sexo               - %c.\n", hospedes.sexo);
                        printf("7 - Estado Civil       - %s.\n", hospedes.estado_civil);
                        printf("8 - Data de Nascimento - %s.\n", hospedes.data_nasc);
                        printf("\n");
                        printf("9 - Cancelar\n");
                        printf("10 - Confirmar\n");
                        printf("=> ");
                        scanf("%d", &choice);

                        if (choice == 9 || choice == 10)
                        {
                            break;
                        }

                        switch (choice)
                        {
                        case 1:
                            fflush(stdin);
                            printf("Indique o nome               : ");
                            scanf(" %[^\n]", hospedes.nome);
                            break;
                        case 2:
                            fflush(stdin);
                            printf("Indique o endereáo completo  : ");
                            scanf(" %[^\n]", hospedes.end_completo);
                            break;
                        case 3:
                            fflush(stdin);
                            printf("Indique o CPF                : ");
                            scanf(" %[^\n]", hospedes.cpf);
                            break;
                        case 4:
                            fflush(stdin);
                            printf("Indique o telefone           : ");
                            scanf(" %[^\n]", hospedes.telefone);
                            break;
                        case 5:
                            fflush(stdin);
                            printf("Indique o e-mail             : ");
                            scanf(" %[^\n]", hospedes.email);
                            break;
                        case 6:
                            fflush(stdin);
                            printf("Indique o sexo               : ");
                            hospedes.sexo = getch();
                            printf("%c\n", hospedes.sexo);
                            break;
                        case 7:
                            fflush(stdin);
                            printf("Indique o estado civil       : ");
                            scanf("%[^\n]", hospedes.estado_civil);
                            break;
                        case 8:
                            fflush(stdin);
                            printf("Indique a data de nascimento : ");
                            scanf("%[^\n]", hospedes.data_nasc);
                            break;
                        default:
                            printf("Insira um valor v†lido!\n");
                            clearPrompt();
                            break;
                        }
                    }

                    if (choice != 9)
                    {
                        ret = alterarHospede(mode, hospedes.cpf, hospedes);

                        if (ret == 0)
                        {
                            printf("H¢spede alterado com sucesso");
                            pausaSist();
                        }
                        else
                        {
                            printf("=> Falha ao alterar h¢spede");
                            pausaSist();
                        }
                    }
                }
            }
            else
            {
                printf("=> H¢spede n∆o encontrado!\n");
                pausaSist();
            }

            break;
        case 4: // ===== EXCLUIR H‡SPEDE =====
            clearPrompt();
            printf("Excluir h¢spede:\n");

            printf("Informe o CPF: \n");
            fflush(stdin);
            scanf("%s", hospedes.cpf);

            printf("\n");

            ret = pesquisarHospede(mode, hospedes.cpf, &hospedes);

            if (ret == 0)
            {
                printf("=> H¢spede encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", hospedes.codigo);
                printf("Nome               : %s\n", hospedes.nome);
                printf("Telefone           : %s\n", hospedes.telefone);
                printf("Email              : %s\n", hospedes.email);
                printf("Data de Nascimento : %s\n", hospedes.data_nasc);
                printf("=========================================\n");
                printf("Deseja excluir este h¢spede?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirHospede(mode, hospedes.cpf);

                    if (ret == 0)
                    {
                        printf("H¢spede exclu°do com sucesso!");
                        pausaSist();
                    }
                    else
                    {
                        printf("=> Falha ao excluir h¢spede.");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("H¢spede n∆o encontrado.");
                pausaSist();
            }
            break;
        default: // ===== EM CASO DE OUTRA OPÄ«O =====
            printf("\n[X] ERRO - Insira um valor v†lido!");
            pausaSist();
            break;
        }
    }
    return;
}

void visualCadastroAcomodacoes(int mode)
{
    int choice, ret;
    str_categ_acomodacoes categoria;
    str_acomodacoes acomodacao;

    while (1)
    {
        clearPrompt();
        printf("Cadastro e Gest∆o de Acomodaá‰es e Categorias:\n");
        printf("1 - Cadastrar Categoria de Acomodaá∆o\n");
        printf("2 - Pesquisar Categoria de Acomodaá∆o\n");
        printf("3 - Editar Categoria de Acomodaá∆o\n");
        printf("4 - Excluir Categoria de Acomodaá∆o\n");
        printf("5 - Cadastrar Acomodaá∆o\n");
        printf("6 - Pesquisar Acomodaá∆o\n");
        printf("7 - Editar Acomodaá∆o\n");
        printf("8 - Excluir Acomodaá∆o\n");
        printf("9 - Listar Categorias\n");
        printf("10 - Listar Acomodaá‰es\n");
        printf("11 - Sair\n");
        printf("=> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            fflush(stdin);
            printf("Informe a descriá∆o da categoria: ");
            scanf(" %[^\n]", categoria.descricao);

            fflush(stdin);
            printf("Informe o valor da di†ria: ");
            scanf("%f", &categoria.valor_diaria);

            fflush(stdin);
            printf("Informe a quantidade de pessoas: ");
            scanf("%d", &categoria.qtd_pessoas);

            ret = cadastrarCategoria(mode, categoria);

            if (ret == 0)
            {
                printf("Categoria de acomodaá∆o cadastrada com sucesso!\n");
                pausaSist();
            }
            else
            {
                printf("Erro ao abrir o arquivo de categorias de acomodaá‰es.\n");
                pausaSist();
            }

            break;

        case 2:
            printf("Pesquisa de Categoria de Acomodaá∆o.\n");
            printf("Informe o c¢digo da categoria de acomodaá∆o: ");
            scanf("%d", &acomodacao.catec_acomod.codigo);

            ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &categoria);

            if (ret == 0)
            {
                printf("Categoria de Acomodaá∆o encontrada!\n");
                printf("===================================\n");
                printf("C¢digo                : %d\n", categoria.codigo);
                printf("Descriá∆o             : %s\n", categoria.descricao);
                printf("Valor da Di†ria       : R$%.2f\n", categoria.valor_diaria);
                printf("Quantidade de Pessoas : %d\n", categoria.qtd_pessoas);
                pausaSist();
            }
            else
            {
                printf("Categoria de Acomodaá∆o n∆o encontrada.\n");
                pausaSist();
            }

            break;

        case 3:
            printf("Pesquisa de Categoria de Acomodaá∆o.\n");
            printf("Informe o c¢digo da categoria de acomodaá∆o: ");
            scanf("%d", &acomodacao.catec_acomod.codigo);

            ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &categoria);

            if (ret == 0)
            {
                printf("Categoria de Acomodaá∆o encontrada!\n");
                printf("===================================\n");
                printf("C¢digo                : %d\n", categoria.codigo);
                printf("Descriá∆o             : %s\n", categoria.descricao);
                printf("Valor da Di†ria       : R$%.2f\n", categoria.valor_diaria);
                printf("Quantidade de Pessoas : %d\n", categoria.qtd_pessoas);
                printf("===================================\n");
                printf("Deseja alterar esta categoria?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    while (1)
                    {
                        clearPrompt();
                        printf("Qual campo deseja alterar?\n");
                        printf("1 - Descriá∆o             - %s\n", categoria.descricao);
                        printf("2 - Valor da Di†ria       - R$%.2f\n", categoria.valor_diaria);
                        printf("3 - Quantidade de Pessoas - %d\n\n", categoria.qtd_pessoas);
                        printf("4 - Cancelar\n");
                        printf("5 - Alterar Categoria\n");
                        printf("=> ");
                        scanf("%d", &choice);

                        if (choice == 5 || choice == 4)
                        {
                            break;
                        }

                        switch (choice)
                        {
                        case 1:
                            fflush(stdin);
                            printf("Informe a descriá∆o da categoria: ");
                            scanf(" %[^\n]", categoria.descricao);
                            break;

                        case 2:
                            fflush(stdin);
                            printf("Informe o valor da di†ria: ");
                            scanf("%f", &categoria.valor_diaria);
                            break;

                        case 3:
                            fflush(stdin);
                            printf("Informe a quantidade de pessoas: ");
                            scanf("%d", &categoria.qtd_pessoas);
                            break;

                        default:
                            printf("Insira um valor v†lido.\n");
                            pausaSist();
                            break;
                        }
                    }

                    if (choice == 5)
                    {
                        ret = editarCategoria(mode, categoria.codigo, categoria);

                        if (ret == 0)
                        {
                            printf("Categoria de Acomodaá∆o alterada com sucesso!\n");
                            pausaSist();
                        }
                        else
                        {
                            printf("Erro ao alterar categoria.\n");
                            pausaSist();
                        }
                    }
                }
            }
            else
            {
                printf("Categoria de Acomodaá∆o n∆o encontrada.\n");
                pausaSist();
            }

            break;

        case 4:
            printf("Informe o c¢digo da categoria a ser exclu°da: ");
            scanf("%d", &categoria.codigo);

            ret = pesquisarCategoria(mode, categoria.codigo, &categoria);

            if (ret == 0)
            {
                printf("Categoria de Acomodaá∆o encontrada!\n");
                printf("===================================\n");
                printf("C¢digo                : %d\n", categoria.codigo);
                printf("Descriá∆o             : %s\n", categoria.descricao);
                printf("Valor da Di†ria       : R$%.2f\n", categoria.valor_diaria);
                printf("Quantidade de Pessoas : %d\n", categoria.qtd_pessoas);
                printf("===================================\n");
                printf("Deseja excluir esta categoria?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirCategoria(mode, categoria.codigo);

                    if (ret == 0)
                    {
                        printf("Categoria de Acomodaá∆o exclu°da com sucesso!\n");
                        pausaSist();
                    }
                    else
                    {
                        printf("Erro ao excluir Categoria de Acomodaá∆o.\n");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("Categoria de Acomodaá∆o n∆o encontrada.\n");
                pausaSist();
            }

            break;

        case 5:
            printf("Cadastrando acomodaá∆o.\n");

            printf("Informe a descriá∆o da acomodaá∆o: ");
            fflush(stdin);
            scanf(" %[^\n]", acomodacao.descricao);

            printf("Informe as facilidades: ");
            fflush(stdin);
            scanf(" %[^\n]", acomodacao.facilidades);

            printf("Informe o c¢digo da categoria da acomodaá∆o: ");
            fflush(stdin);
            scanf("%d", &acomodacao.catec_acomod.codigo);

            ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod);

            if (ret == 0)
            {
                ret = cadastrarAcomodacao(mode, acomodacao);

                if (ret == 0)
                {
                    printf("Acomodaá∆o cadastrada com sucesso!\n");
                    pausaSist();
                }
                else
                {
                    printf("Erro ao abrir o arquivo de acomodaá‰es.\n");
                    pausaSist();
                }
            }
            else
            {
                printf("O c¢digo dessa categoria de acomodaá∆o n∆o existe.\n");
                pausaSist();
            }

            break;

        case 6:

            printf("Pesquisando acomodaá∆o.\n");
            printf("Informe o c¢digo da acomodaá∆o: ");
            scanf("%d", &acomodacao.codigo);

            ret = pesquisarAcomodacao(mode, acomodacao.codigo, &acomodacao);

            if (ret == 0)
            {
                printf("Acomodaá∆o encontrada!\n");
                printf("===========================\n");
                printf("C¢digo      : %d\n", acomodacao.codigo);
                printf("Descriá∆o   : %s\n", acomodacao.descricao);
                printf("Facilidades : %s\n", acomodacao.facilidades);
                printf("=> Categoria de Acomodaá∆o\n");
                printf("=  C¢digo                : %d\n", acomodacao.catec_acomod.codigo);
                printf("=  Descriá∆o             : %s\n", acomodacao.catec_acomod.descricao);
                printf("=  Valor da Di†ria       : R$%.2f\n", acomodacao.catec_acomod.valor_diaria);
                printf("=  Quantidade de Pessoas : %d\n", acomodacao.catec_acomod.qtd_pessoas);

                pausaSist();
            }
            else
            {
                printf("Acomodaá∆o n∆o encontrada!\n");
                pausaSist();
            }
            break;

        case 7:
            printf("Alterando acomodaá∆o.\n");
            printf("Informe o c¢digo da acomodaá∆o: ");
            scanf("%d", &acomodacao.codigo);

            ret = pesquisarAcomodacao(mode, acomodacao.codigo, &acomodacao);

            if (ret == 0)
            {
                printf("Categoria de Acomodaá∆o encontrada!\n");
                printf("===================================\n");
                printf("C¢digo      : %d\n", acomodacao.codigo);
                printf("Descriá∆o   : %s\n", acomodacao.descricao);
                printf("Facilidades : %s\n", acomodacao.facilidades);
                printf("=> Categoria de Acomodaá∆o\n");
                printf("=  C¢digo      : %d\n", acomodacao.catec_acomod.codigo);
                printf("=  Descriá∆o   : %s\n", acomodacao.catec_acomod.descricao);
                printf("===================================\n");
                printf("Deseja alterar esta acomodaá∆o?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    int codTemp;
                    while (1)
                    {
                        clearPrompt();
                        printf("Qual campo deseja alterar?\n");
                        printf("1 - Descriá∆o   : %s\n", acomodacao.descricao);
                        printf("2 - Facilidades : %s\n\n", acomodacao.facilidades);
                        printf("Categoria de Acomodaá∆o:\n");
                        printf("3 - C¢digo      : %d (%s)\n", acomodacao.catec_acomod.codigo, acomodacao.catec_acomod.descricao);
                        printf("4 - Cancelar\n");
                        printf("5 - Alterar Categoria\n");
                        printf("=> ");
                        scanf("%d", &choice);

                        if (choice == 4 || choice == 5)
                        {
                            break;
                        }

                        switch (choice)
                        {
                        case 1:
                            printf("Informe a nova descriá∆o da acomodaá∆o: ");
                            fflush(stdin);
                            scanf(" %[^\n]", acomodacao.descricao);
                            break;

                        case 2:
                            printf("Informe as novas facilidades: ");
                            fflush(stdin);
                            scanf(" %[^\n]", acomodacao.facilidades);
                            break;

                        case 3:
                            codTemp = acomodacao.catec_acomod.codigo;
                            printf("Informe o novo c¢digo da categoria da acomodaá∆o: ");
                            fflush(stdin);
                            scanf("%d", &acomodacao.catec_acomod.codigo);

                            ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod);

                            if (ret != 0)
                            {
                                printf("Informe um c¢digo de categoria v†lido!\n");
                                pausaSist();

                                acomodacao.catec_acomod.codigo = codTemp;
                            }
                            break;

                        default:
                            printf("Selecione uma opá∆o v†lida.\n");
                            pausaSist();
                            break;
                        }
                    }

                    if (choice == 5)
                    {
                        ret = editarAcomodacao(mode, acomodacao.codigo, acomodacao);

                        if (ret == 0)
                        {
                            printf("Acomodaá∆o alterada com sucesso!\n");
                            pausaSist();
                        }
                        else
                        {
                            printf("Erro ao alterar Acomodaá∆o.\n");
                            pausaSist();
                        }
                    }
                }
            }
            else
            {
                printf("Acomodaá∆o n∆o encontrada!\n");
                pausaSist();
            }
            break;

        case 8:
            printf("Excluindo acomodaá∆o.\n");
            printf("Informe o c¢digo da acomodaá∆o: ");
            scanf("%d", &acomodacao.codigo);

            ret = pesquisarAcomodacao(mode, acomodacao.codigo, &acomodacao);

            if (ret == 0)
            {
                printf("Categoria de Acomodaá∆o encontrada!\n");
                printf("===================================\n");
                printf("C¢digo      : %d\n", acomodacao.codigo);
                printf("Descriá∆o   : %s\n", acomodacao.descricao);
                printf("Facilidades : %s\n", acomodacao.facilidades);
                printf("=> Categoria de Acomodaá∆o\n");
                printf("=  C¢digo      : %d\n", acomodacao.catec_acomod.codigo);
                printf("=  Descriá∆o   : %s\n", acomodacao.catec_acomod.descricao);
                printf("===================================\n");
                printf("Deseja excluir esta acomodaá∆o?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirAcomodacao(mode, acomodacao.codigo);

                    if (ret == 0)
                    {
                        printf("Acomodaá∆o exclu°da com sucesso!\n");
                        pausaSist();
                    }
                    else
                    {
                        printf("Erro ao excluir Acomodaá∆o.\n");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("Acomodaá∆o n∆o encontrada!\n");
                pausaSist();
            }
            break;

        case 9:
            listarCategorias(mode);
            pausaSist();
            break;

        case 10:
            listarAcomodacoes(mode);
            pausaSist();
            break;

        case 11:
            exit(0);

        default:
            printf("Opá∆o inv†lida. Tente novamente.\n");
            pausaSist();
            break;
        }
    }

    return;
}

void visualCadastroFornecedor(int mode)
{
    int choice, ret;
    str_fornecedores f;

    while (1)
    {
        clearPrompt();
        // menu principal da se?ío funcionarios
        printf("Cadastro e Gestío de Fornecedores:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n");
        printf("=> ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            break;
        }

        switch (choice)
        {
        case 1: // ===== CADASTRAR FORNECEDOR =====

            // recolhendo dados do novo fornecedor
            fflush(stdin);
            printf("Indique o nome               : ");
            scanf(" %[^\n]", f.nome);

            fflush(stdin);
            printf("Indique a razío social       : ");
            scanf(" %[^\n]", f.razao_social);

            fflush(stdin);
            printf("Indique a inscri?ío estadual : ");
            scanf(" %[^\n]", f.inscricao_estadual);

            fflush(stdin);
            printf("Indique o cnpj               : ");
            scanf(" %[^\n]", f.cnpj);

            fflush(stdin);
            printf("Indique o endere?o completo  : ");
            scanf(" %[^\n]", f.end_completo);

            fflush(stdin);
            printf("Indique o telefone           : ");
            scanf(" %[^\n]", f.telefone);

            fflush(stdin);
            printf("Indique o email              : ");
            scanf(" %[^\n]", f.email);

            // fun?ío cadastra o fornecedor
            ret = cadastrarFornecedor(f);

            if (ret == 0)
            {
                printf("\nFornecedor cadastrado com sucesso!");
                pausaSist();
            }
            else
            {
                printf("Erro ao acessar o arquivo dados_fornecedores.txt\n");
                pausaSist();
            }
            break;
        case 2: // ===== PESQUISAR FORNECEDOR =====
            printf("Pesquisar Fornecedor: \n");
            printf("CNPJ do fornecedor: ");
            fflush(stdin);
            scanf("%s", f.cnpj);

            ret = pesquisarFornecedor(mode, f.cnpj, &f);

            if (ret == 0)
            {
                printf("=> Fornecedor encontrado!\n");
                printf("=========================================\n");
                printf("CΩdigo             : %d\n", f.codigo);
                printf("Nome Fornecedor    : %s\n", f.nome);
                printf("Razío Social       : %s\n", f.razao_social);
                printf("Inscri?ío Estadual : %s\n", f.inscricao_estadual);
                printf("CNPJ               : %s\n", f.cnpj);
                printf("Endere?o Completo  : %s\n", f.end_completo);
                printf("Telefone           : %s\n", f.telefone);
                printf("Email              : %s\n", f.email);
                pausaSist();
            }
            else
            {
                printf("=> Fornecedor nío encontrado!\n");
                pausaSist();
            }
            break;
        case 3: // ===== ALTERAR FORNECEDOR =====
            clearPrompt();
            printf("Alterar fornecedor:\n");

            printf("Informe o CNPJ: \n");
            fflush(stdin);
            scanf("%s", f.cnpj);

            printf("\n");

            ret = pesquisarFornecedor(mode, f.cnpj, &f);

            if (ret == 0)
            {
                printf("=> Fornecedor encontrado!\n");
                printf("=========================================\n");
                printf("CΩdigo             : %d\n", f.codigo);
                printf("Nome               : %s\n", f.nome);
                printf("Telefone           : %s\n", f.telefone);
                printf("Email              : %s\n", f.email);
                printf("CNPJ               : %s\n", f.cnpj);
                printf("=========================================\n");
                printf("Deseja alterar este fornecedor?\n");
                printf("1 - Sim\n");
                printf("0 - Nío\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    AnsiUpper(f.nome);
                    clearPrompt();
                    fflush(stdin);
                    printf("Indique o novo nome               : ");
                    scanf(" %[^\n]", f.nome);

                    fflush(stdin);
                    printf("Indique a nova razío social       : ");
                    scanf(" %[^\n]", f.razao_social);

                    fflush(stdin);
                    printf("Indique a nova inscri?ío estadual : ");
                    scanf(" %[^\n]", f.inscricao_estadual);

                    fflush(stdin);
                    printf("Indique o novo cnpj               : ");
                    scanf(" %[^\n]", f.cnpj);

                    fflush(stdin);
                    printf("Indique o novo endere?o completo  : ");
                    scanf(" %[^\n]", f.end_completo);

                    fflush(stdin);
                    printf("Indique o novo telefone           : ");
                    scanf(" %[^\n]", f.telefone);

                    fflush(stdin);
                    printf("Indique o novo email              : ");
                    scanf(" %[^\n]", f.email);

                    ret = alterarFornecedor(mode, f.cnpj, f);

                    if (ret == 0)
                    {
                        printf("Fornecedor alterado com sucesso!");
                        pausaSist();
                    }
                    else
                    {
                        printf("=> Falha ao alterar fornecedor.");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("=> Fornecedor nío encontrado!\n");
                pausaSist();
            }

            break;
        case 4: // ===== EXCLUIR FORNECEDOR =====
            clearPrompt();
            printf("Excluir fornecedor:\n");

            printf("Informe o CNPJ: \n");
            fflush(stdin);
            scanf("%s", f.cnpj);

            printf("\n");

            ret = pesquisarFornecedor(mode, f.cnpj, &f);

            if (ret == 0)
            {
                printf("=> Fornecedor encontrado!\n");
                printf("=========================================\n");
                printf("CΩdigo             : %d\n", f.codigo);
                printf("Nome               : %s\n", f.nome);
                printf("Telefone           : %s\n", f.telefone);
                printf("Email              : %s\n", f.email);
                printf("CNPJ               : %s\n", f.cnpj);
                printf("=========================================\n");
                printf("Deseja excluir este fornecedor?\n");
                printf("1 - Sim\n");
                printf("0 - Nío\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirFornecedor(mode, f.cnpj);

                    if (ret == 0)
                    {
                        printf("Fornecedor exclu≠do com sucesso!");
                        pausaSist();
                    }
                    else
                    {
                        printf("=> Falha ao excluir fornecedor.");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("Fornecedor nío encontrado.");
                pausaSist();
            }

            break;
        default: // ===== EM CASO DE OUTRA OP?ÄO =====
            printf("\n[X] ERRO - Insira um valor valido!");
            pausaSist();
            break;
        }
    }

    return;
}

void visualCadastroProdutos(int mode)
{
    int x;
    int ret;
    str_produtos cliente;

    while (1)
    {
        clearPrompt();
        // menu principal da se?ío funcionarios
        printf("Cadastro e Gest∆o de Produtos:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n");
        printf("=> ");
        scanf("%d", &x);

        if (x == 5)
        {
            break;
        }

        switch (x)
        {
        case 1:

            printf("DIGITE O C‡DIGO DO PRODUTO: ");
            fflush(stdin);
            scanf("%d", &cliente.codigo);

            printf("DIGITE A DESCRIÄ«O DO PRODUTO: ");
            fflush(stdin);
            scanf("%[^\n]", cliente.descricao);

            printf("DIGITE O ESTOQUE DO PRODUTO: ");
            fflush(stdin);
            scanf("%d", &cliente.estoque);

            printf("DIGITE O ESTOQUE M÷NIMO DO PRODUTO: ");
            fflush(stdin);
            scanf("%d", &cliente.estoque_min);

            printf("DIGITE O PREÄO DE CUSTO DO PRODUTO: ");
            fflush(stdin);
            scanf("%f", &cliente.preco_custo);

            printf("DIGITE O PREÄO DE VENDA DO PRODUTO: ");
            fflush(stdin);
            scanf("%f", &cliente.preco_venda);

            ret = cadastro_produto(cliente);

            if (ret == 0)
            {
                printf("CADASTRO DE PRODUTO CONCLUIDO");
                pausaSist();
            }
            else
            {
                printf("ERRO AO CADASTRAR PRODUTO");
                pausaSist();
            }

            break;

        case 2:
            clearPrompt();
            printf("DIGITE O C‡DIGO DO PRODUTO: \n");
            fflush(stdin);
            scanf("%d", &cliente.codigo);
            ret = pesquisaProduto(mode, cliente.codigo, &cliente);
            if (ret == 0)
            {
                printf("----DADOS DO PRODUTO---- \n");
                printf("C‡DIGO DO PRODUTO: %d\n", cliente.codigo);
                printf("DESCRIÄ«O DO PRODUTO: %s\n", cliente.descricao);
                printf("ESTOQUE DO PRODUTO: %d\n", cliente.estoque);
                printf("ESTOQUE M÷NIMO DO PRODUTO: %d\n", cliente.estoque_min);
                printf("CUSTO DO PRODUTO: R$%.2f\n", cliente.preco_custo);
                printf("PREÄO DE VENDA: R$%.2f\n", cliente.preco_venda);
                pausaSist();
            }
            else
            {
                printf("ERRO NA BUSCA");
                pausaSist();
            }

            break;

        case 3:

            clearPrompt();
            printf("DIGITE O C‡DIGO DO PRODUTO: \n");
            fflush(stdin);
            scanf("%d", &cliente.codigo);

            ret = pesquisaProduto(mode, cliente.codigo, &cliente);

            if (ret == 0)
            {
                printf("----DADOS DO PRODUTO---- \n");
                printf("C‡DIGO DO PRODUTO: %d\n", cliente.codigo);
                printf("DESCRIÄ«O DO PRODUTO: %s\n", cliente.descricao);
                printf("ESTOQUE DO PRODUTO: %d\n", cliente.estoque);
                printf("ESTOQUE M÷NIMO DO PRODUTO: %d\n", cliente.estoque_min);
                printf("CUSTO DO PRODUTO: R$%.2f\n", cliente.preco_custo);
                printf("PREÄO DE VENDA: R$%.2f\n", cliente.preco_venda);

                printf("\n");
                printf("TEM CERTEZA QUE DESEJA ALTERAR ESTE PRODUTO?\n");
                printf("1 - SIM\n");
                printf("2 - N«O\n");
                printf("\n");
                printf("INSIRA: ");
                scanf("%d", &x);
                clearPrompt();

                if (x == 1)
                {
                    printf("---- DADOS DO PRODUTO ----\n");
                    printf("1 - C‡DIGO DO PRODUTO: %d\n", cliente.codigo);
                    printf("2 - DESCRIÄ«O DO PRODUTO: %s\n", cliente.descricao);
                    printf("3 - ESTOQUE: %d\n", cliente.estoque);
                    printf("4 - ESTOQUE M÷NIMO: %d\n", cliente.estoque_min);
                    printf("5 - PREÄO DE CUSTO: %.2f\n", cliente.preco_custo);
                    printf("6 - PREÄO DE VENDA: %.2f\n", cliente.preco_venda);
                    printf("\n");
                    printf("INSIRA: ");
                    scanf("%d", &x);
                    if (x == 1)
                    {
                        printf("DIGITE O C‡DIGO DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%d", &cliente.codigo);
                        printf("\n");
                    }

                    if (x == 2)
                    {
                        printf("DIGITE A DESCRIÄ«O DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%[^\n]", cliente.descricao);
                    }

                    if (x == 3)
                    {
                        printf("DIGITE O ESTOQUE: ");
                        fflush(stdin);
                        scanf("%d", &cliente.estoque);
                    }

                    if (x == 4)
                    {
                        printf("DIGITE O ESTOQUE M÷NIMO DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%d", &cliente.estoque_min);
                    }

                    if (x == 5)
                    {
                        printf("DIGITE O PREÄO DE CUSTO DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%f", &cliente.preco_custo);
                    }

                    if (x == 6)
                    {
                        printf("DIGITE O PREÄO DE VENDA DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%f", &cliente.preco_venda);
                    }
                }
                ret = alteraProduto(cliente);

                if (ret == 0)
                {
                    printf("SUCESSO AO ALTERAR PRODUTO");
                    pausaSist();
                }
                else
                {
                    printf("ERRO AO ALTERAR PRODUTO");
                    pausaSist();
                }
            }
            else
            {
                printf("ERRO NA BUSCA");
                pausaSist();
            }

            break;

        case 4:
            printf("Deletando produto\n");
            printf("DIGITE O C‡DIGO DO PRODUTO: \n");
            fflush(stdin);
            scanf("%d", &cliente.codigo);

            ret = pesquisaProduto(mode, cliente.codigo, &cliente);

            if (ret == 0)
            {
                printf("PRODUTO ENCONTRADO!\n");
                printf("=========================\n");
                printf("C¢digo    : %d\n", cliente.codigo);
                printf("Descriá∆o : %s\n", cliente.descricao);
                printf("Estoque   : %d\n", cliente.estoque);
                printf("=========================\n");
                printf("Deseja apagar esse produto?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                scanf("%d", &x);

                if (x == 1)
                {
                    ret = deletaProduto(mode, cliente.codigo);

                    if (ret == 0)
                    {
                        printf("PRODUTO EXCLU÷DO COM SUCESSO");
                        pausaSist();
                    }
                    else
                    {
                        printf("ERRO AO EXCLUIR PRODUTO");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("PRODUTO N«O ENCONTRADO");
                pausaSist();
            }
            break;
        }
    }
    return;
}

void visualCadastroOperadores(int mode)
{
    int choice, ret;
    str_op_sistemas operador;

    while (1)
    {
        printf("Cadastro e Gest∆o de Operadores do Sistema:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n");
        printf("=> ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            break; // Sai do loop quando a escolha for 5
        }

        switch (choice)
        {
        case 1: // CADASTRAR OPERADOR
            // Recolhendo dados do novo operador
            fflush(stdin);
            printf("Indique o nome   : ");
            scanf(" %[^\n]", operador.nome);

            fflush(stdin);
            printf("Indique o login  : ");
            scanf(" %[^\n]", operador.usuario);

            fflush(stdin);
            printf("Indique a senha  : ");
            scanf(" %[^\n]", operador.senha);

            fflush(stdin);
            printf("Indique as permiss‰es (separadas por v°rgulas) : ");
            scanf(" %[^\n]", operador.permissoes);

            // Funá∆o cadastra o operador
            ret = cadastrarOperador(mode, operador);

            if (ret == 0)
            {
                printf("\nOperador cadastrado com sucesso!");
                pausaSist();
            }
            else
            {
                printf("Erro ao acessar o arquivo operadores.txt\n");
                pausaSist();
            }
            break;

        case 2: // PESQUISAR OPERADOR
            printf("Pesquisar Operador: \n");
            printf("Login do operador: ");
            fflush(stdin);
            scanf("%s", operador.usuario);

            ret = pesquisarOperadorPorUsuario(mode, operador.usuario, &operador);

            if (ret == 0)
            {
                printf("=> Operador encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo      : %d\n", operador.codigo);
                printf("Nome        : %s\n", operador.nome);
                printf("Login       : %s\n", operador.usuario);
                printf("Permiss‰es  : %s\n", operador.permissoes);
                pausaSist();
            }
            else
            {
                printf("=> Operador n∆o encontrado!\n");
                pausaSist();
            }
            break;

        case 3: // ALTERAR OPERADOR
            clearPrompt();
            printf("Alterar operador:\n");
            printf("Informe o login: \n");
            fflush(stdin);
            scanf("%s", operador.usuario);

            printf("\n");
            ret = pesquisarOperadorPorUsuario(mode, operador.usuario, &operador);

            if (ret == 0)
            {
                printf("=> Operador encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo      : %d\n", operador.codigo);
                printf("Nome        : %s\n", operador.nome);
                printf("Login       : %s\n", operador.usuario);
                printf("Permiss‰es  : %s\n", operador.permissoes);
                printf("=========================================\n");
                printf("Deseja alterar este operador?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    clearPrompt();
                    fflush(stdin);
                    printf("Indique o novo nome        : ");
                    scanf(" %[^\n]", operador.nome);

                    fflush(stdin);
                    printf("Indique a nova senha       : ");
                    scanf(" %[^\n]", operador.senha);

                    fflush(stdin);
                    printf("Indique as novas permiss‰es (separadas por v°rgulas) : ");
                    scanf(" %[^\n]", operador.permissoes);

                    ret = editarOperador(mode, operador.usuario, operador);

                    if (ret == 0)
                    {
                        printf("Operador alterado com sucesso!");
                        pausaSist();
                    }
                    else
                    {
                        printf("=> Falha ao alterar operador.");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("=> Operador n∆o encontrado!\n");
                pausaSist();
            }
            break;

        case 4: // EXCLUIR OPERADOR
            clearPrompt();
            printf("Excluir operador:\n");
            printf("Informe o login: \n");
            fflush(stdin);
            scanf("%s", operador.usuario);

            printf("\n");

            ret = pesquisarOperadorPorUsuario(mode, operador.usuario, &operador);

            if (ret == 0)
            {
                printf("=> Operador encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo      : %d\n", operador.codigo);
                printf("Nome        : %s\n", operador.nome);
                printf("Login       : %s\n", operador.usuario);
                printf("Permiss‰es  : %s\n", operador.permissoes);
                printf("=========================================\n");
                printf("Deseja excluir este operador?\n");
                printf("1 - Sim\n");
                printf("0 - N∆o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirOperador(mode, operador.usuario);

                    if (ret == 0)
                    {
                        printf("Operador exclu°do com sucesso!");
                        pausaSist();
                    }
                    else
                    {
                        printf("=> Falha ao excluir operador.");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("Operador n∆o encontrado.");
                pausaSist();
            }
            break;

        default: // EM CASO DE OUTRA OPÄ«O
            printf("\n[X] ERRO - Insira um valor v†lido!");
            pausaSist();
            break;
        }
    }

    return;
}
