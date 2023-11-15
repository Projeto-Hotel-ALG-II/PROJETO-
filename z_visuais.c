#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

// BIBLIOTECA DE FERRAMENTAS
#include "bib_quick_tools.h"

// BIBLIOTECAS - CADASTRO E GEST¶O DE DADOS
#include "bib_cadastro_hotel.h"
#include "bib_cadastro_hospedes.h"
#include "bib_cadastro_acomodacoes.h"
#include "bib_cadastro_fornecedores.h"
#include "bib_cadastro_produtos.h"
#include "bib_cadastro_operadores.h"

// BIBLIOTECA - RESERVAS
#include "bib_reservas.h"

// CADASTRO E GEST¶O DE DADOS:
void visualCadastroHotel(int mode)
{
    str_hotel hot;
    int ret;
    int choice;

    while (1)
    {
        clearPrompt();
        printf("GestÆo dos dados do Hotel:\n");
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

            printf("DIGITE A RAZÇO SOCIAL: ");
            fflush(stdin);
            scanf("%[^\n]", hot.razao_soc);

            printf("DIGITE A INSCRI€ÇO ESTADUAL: ");
            fflush(stdin);
            scanf("%[^\n]", hot.inscricao_estadual);

            printf("DIGITE O CNPJ: ");
            fflush(stdin);
            scanf("%[^\n]", hot.cnpj);

            printf("DIGITE O ENDERE€O COMPLETO: ");
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
                printf("RAZÇO SOCIAL            : %s\n", hot.razao_soc);
                printf("INSCRIÇÇO ESTADUAL      : %s\n", hot.inscricao_estadual);
                printf("CNPJ                    : %s\n", hot.cnpj);
                printf("ENDEREÇO COMPLETO       : %s\n", hot.end_completo);
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
                printf("NÇO EXISTEM DADOS NO ARQUIVO.\n");
                pausaSist();
            }
            else
            {
                while (1)
                {
                    clearPrompt();
                    printf("Qual campo deseja alterar?\n");
                    printf("1   - NOME FANTASIA           - %s\n", hot.nome_fantasia);
                    printf("2   - RAZÇO SOCIAL            - %s\n", hot.razao_soc);
                    printf("3   - INSCRIÇÇO ESTADUAL      - %s\n", hot.inscricao_estadual);
                    printf("4   - CNPJ                    - %s\n", hot.cnpj);
                    printf("5   - ENDERE€O COMPLETO       - %s\n", hot.end_completo);
                    printf("6   - TELEFONE                - %s\n", hot.telefone);
                    printf("7   - E-MAIL                  - %s\n", hot.email);
                    printf("8   - NOME DO RESPONSAVEL     - %s\n", hot.nome_responsavel);
                    printf("9   - TELEFONE DO RESPONSµVEL - %s\n", hot.tel_responsavel);
                    printf("10 - HORARIO DE CHECK-IN      - %s\n", hot.horario_checkin);
                    printf("11 - HORARIO DE CHECK-OUT     - %s\n", hot.horario_checkout);
                    printf("12 - MARGEM DE LUCRO          - %.1f%%\n\n", hot.margem_lucro);

                    printf("13 - Cancelar\n");
                    printf("14 - Confirmar Mudan‡as\n");
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
                        printf("DIGITE A RAZÇO SOCIAL: ");
                        fflush(stdin);

                        scanf("%[^\n]s", hot.razao_soc);
                    }
                    else if (choice == 3)
                    {
                        printf("DIGITE A INSCRI€ÇO SOCIAL: ");
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
                        printf("DIGITE O ENDERE€O COMPLETO: ");
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
            printf("2 - NÆo\n");
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
    return;
}

void visualCadastroHospedes(int mode)
{
    int choice; // armazena as escolhas de navegabilidade do usu rio
    int ret;    // armazena o retorno das fun‡äes
    str_hospedes *hospedes;

    // Alocando mem¢ria para a gestÆo dos dados dos h¢spedes
    hospedes = (str_hospedes *)malloc(sizeof(str_hospedes));

    // caso nÆo seja poss¡vel alocar mem¢ria
    if (!hospedes)
    {
        printf("Erro ao alocar mem¢ria\n");
        pausaSist();
        exit(1);
    }

    while (1)
    {
        clearPrompt();
        // menu principal da se‡Æo cadastro de hospedes
        printf("Cadastro e GestÆo de H¢spedes:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n");
        printf("=> ");
        scanf("%d", &choice);

        if (choice == 5)
        {
            free(hospedes);
            break;
        }

        switch (choice)
        {
        case 1: // ===== CADASTRAR HàSPEDE =====

            // recolhendo dados do novo hospede
            fflush(stdin); // Limpa o buffer
            printf("Indique o CPF ( XXX.XXX.XXX-YY )          : ");
            scanf(" %[^\n]", hospedes->cpf);

            ret = pesquisarHospede(mode, hospedes->cpf, hospedes);

            if (ret == 0)
            {
                printf("Esse cpf j  foi cadastrado!\n");
                pausaSist();
            }
            else
            {
                fflush(stdin);
                printf("Indique o nome                            : ");
                scanf(" %[^\n]", hospedes->nome);

                fflush(stdin);
                printf("Indique o endere‡o completo               : ");
                scanf(" %[^\n]", hospedes->end_completo);

                fflush(stdin);
                printf("Indique o telefone (ZZ) YXXXX-XXXX        : ");
                scanf(" %[^\n]", hospedes->telefone);

                fflush(stdin);
                printf("Indique o e-mail                          : ");
                scanf(" %[^\n]", hospedes->email);

                fflush(stdin);
                printf("Indique o sexo M, F ou N                  : ");
                hospedes->sexo = getch();
                printf("%c\n", hospedes->sexo);

                fflush(stdin);
                printf("Indique o estado civil                    : ");
                scanf("%[^\n]", hospedes->estado_civil);

                fflush(stdin);
                printf("Indique a data de nascimento (DD/MM/AAAA) : ");
                scanf("%[^\n]", hospedes->data_nasc);

                // fun‡Æo cadastra os h¢spedes
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
            }

            break;

        case 2: // ===== PESQUISAR HàSPEDE =====
            
            printf("Pesquisar H¢spede: \n");
            printf("Informe o CPF do h¢spede (XXX.XXX.XXX-XX): ");
            
            fflush(stdin);
            scanf("%s", hospedes->cpf);

            ret = pesquisarHospede(mode, hospedes->cpf, hospedes);

            if (ret == 0)
            {
                printf("=> H¢spede encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", hospedes->codigo);
                printf("Nome               : %s\n", hospedes->nome);
                printf("Endere‡o           : %s\n", hospedes->end_completo);
                printf("CPF                : %s\n", hospedes->cpf);
                printf("Telefone           : %s\n", hospedes->telefone);
                printf("E-mail             : %s\n", hospedes->email);
                printf("Sexo               : %c\n", hospedes->sexo);
                printf("Estado Civil       : %s\n", hospedes->estado_civil);
                printf("Data de Nascimento : %s\n", hospedes->data_nasc);
                pausaSist();
            }
            else
            {
                printf("=> H¢spede nÆo encontrado!\n");
                pausaSist();
            }
            break;
        case 3: // ===== ALTERAR HàSPEDE =====
            
            clearPrompt();
            printf("Alterar h¢spede:\n");
            printf("Informe o CPF do h¢spede (XXX.XXX.XXX-XX): ");

            fflush(stdin);
            scanf("%s", hospedes->cpf);

            printf("\n");

            ret = pesquisarHospede(mode, hospedes->cpf, hospedes);

            if (ret == 0)
            {
                printf("=> H¢spede encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", hospedes->codigo);
                printf("Nome               : %s\n", hospedes->nome);
                printf("Telefone           : %s\n", hospedes->telefone);
                printf("Email              : %s\n", hospedes->email);
                printf("Data de Nascimento : %s\n", hospedes->data_nasc);
                printf("=========================================\n");
                printf("Deseja alterar este h¢spede?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    while (1)
                    {
                        fflush(stdin);
                        clearPrompt();
                        printf("Qual campo deseja alterar?\n");
                        printf("1 - Nome               - %s.\n", hospedes->nome);
                        printf("2 - Endere‡o Completo  - %s.\n", hospedes->end_completo);
                        printf("3 - CPF                - %s.\n", hospedes->cpf);
                        printf("4 - Telefone           - %s.\n", hospedes->telefone);
                        printf("5 - Email              - %s.\n", hospedes->email);
                        printf("6 - Sexo               - %c.\n", hospedes->sexo);
                        printf("7 - Estado Civil       - %s.\n", hospedes->estado_civil);
                        printf("8 - Data de Nascimento - %s.\n", hospedes->data_nasc);
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
                            scanf(" %[^\n]", hospedes->nome);
                            break;
                        case 2:
                            fflush(stdin);
                            printf("Indique o endere‡o completo  : ");
                            scanf(" %[^\n]", hospedes->end_completo);
                            break;
                        case 3:
                            fflush(stdin);
                            printf("Indique o CPF                : ");
                            scanf(" %[^\n]", hospedes->cpf);
                            break;
                        case 4:
                            fflush(stdin);
                            printf("Indique o telefone           : ");
                            scanf(" %[^\n]", hospedes->telefone);
                            break;
                        case 5:
                            fflush(stdin);
                            printf("Indique o e-mail             : ");
                            scanf(" %[^\n]", hospedes->email);
                            break;
                        case 6:
                            fflush(stdin);
                            printf("Indique o sexo               : ");
                            hospedes->sexo = getch();
                            printf("%c\n", hospedes->sexo);
                            break;
                        case 7:
                            fflush(stdin);
                            printf("Indique o estado civil       : ");
                            scanf("%[^\n]", hospedes->estado_civil);
                            break;
                        case 8:
                            fflush(stdin);
                            printf("Indique a data de nascimento : ");
                            scanf("%[^\n]", hospedes->data_nasc);
                            break;
                        default:
                            printf("Insira um valor v lido!\n");
                            clearPrompt();
                            break;
                        }
                    }

                    if (choice != 9)
                    {
                        ret = alterarHospede(mode, hospedes->cpf, hospedes);

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
                printf("=> H¢spede nÆo encontrado!\n");
                pausaSist();
            }

            break;
        case 4: // ===== EXCLUIR HàSPEDE =====
            clearPrompt();
            printf("Excluir h¢spede:\n");

            printf("Informe o CPF: \n");
            fflush(stdin);
            scanf("%s", hospedes->cpf);

            printf("\n");

            ret = pesquisarHospede(mode, hospedes->cpf, hospedes);

            if (ret == 0)
            {
                printf("=> H¢spede encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", hospedes->codigo);
                printf("Nome               : %s\n", hospedes->nome);
                printf("Telefone           : %s\n", hospedes->telefone);
                printf("Email              : %s\n", hospedes->email);
                printf("Data de Nascimento : %s\n", hospedes->data_nasc);
                printf("=========================================\n");
                printf("Deseja excluir este h¢spede?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirHospede(mode, hospedes->cpf);

                    if (ret == 0)
                    {
                        printf("H¢spede exclu¡do com sucesso!");
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
                printf("H¢spede nÆo encontrado.");
                pausaSist();
            }
            break;
        default: // ===== EM CASO DE OUTRA OP€ÇO =====
            printf("\n[X] ERRO - Insira um valor v lido!");
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
        printf("Cadastro e GestÆo de Acomoda‡äes e Categorias:\n");
        printf("1  - Cadastrar Categoria de Acomoda‡Æo\n");
        printf("2  - Pesquisar Categoria de Acomoda‡Æo\n");
        printf("3  - Editar Categoria de Acomoda‡Æo\n");
        printf("4  - Excluir Categoria de Acomoda‡Æo\n\n");
        printf("5  - Cadastrar Acomoda‡Æo\n");
        printf("6  - Pesquisar Acomoda‡Æo\n");
        printf("7  - Editar Acomoda‡Æo\n");
        printf("8  - Excluir Acomoda‡Æo\n\n");
        printf("9  - Listar Categorias\n");
        printf("10 - Listar Acomoda‡äes\n");
        printf("11 - Sair\n");
        printf("=> ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1: // Cadastrando Categoria
            printf("Cadastrando categoria.\n");
            fflush(stdin);
            printf("Informe a descri‡Æo da categoria: ");
            scanf(" %[^\n]", categoria.descricao);

            fflush(stdin);
            printf("Informe o valor da di ria: R$");
            scanf("%f", &categoria.valor_diaria);

            fflush(stdin);
            printf("Informe a quantidade de pessoas: ");
            scanf("%d", &categoria.qtd_pessoas);

            ret = cadastrarCategoria(mode, categoria);

            if (ret == 0)
            {
                printf("Categoria de acomoda‡Æo cadastrada com sucesso!\n");
                pausaSist();
            }
            else
            {
                printf("Erro ao abrir o arquivo de categorias de acomoda‡äes.\n");
                pausaSist();
            }

            break;

        case 2:
            printf("Pesquisa de Categoria de Acomoda‡Æo.\n");
            printf("Informe o c¢digo da categoria de acomoda‡Æo: ");
            scanf("%d", &acomodacao.catec_acomod.codigo);

            ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &categoria);

            if (ret == 0)
            {
                printf("Categoria de Acomoda‡Æo encontrada!\n");
                printf("===================================\n");
                printf("C¢digo                : %d\n", categoria.codigo);
                printf("Descri‡Æo             : %s\n", categoria.descricao);
                printf("Valor da Di ria       : R$%.2f\n", categoria.valor_diaria);
                printf("Quantidade de Pessoas : %d\n", categoria.qtd_pessoas);
                pausaSist();
            }
            else
            {
                printf("Categoria de Acomoda‡Æo nÆo encontrada.\n");
                pausaSist();
            }

            break;

        case 3:
            printf("Pesquisa de Categoria de Acomoda‡Æo.\n");
            printf("Informe o c¢digo da categoria de acomoda‡Æo: ");
            scanf("%d", &acomodacao.catec_acomod.codigo);

            ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &categoria);

            if (ret == 0)
            {
                printf("Categoria de Acomoda‡Æo encontrada!\n");
                printf("===================================\n");
                printf("C¢digo                : %d\n", categoria.codigo);
                printf("Descri‡Æo             : %s\n", categoria.descricao);
                printf("Valor da Di ria       : R$%.2f\n", categoria.valor_diaria);
                printf("Quantidade de Pessoas : %d\n", categoria.qtd_pessoas);
                printf("===================================\n");
                printf("Deseja alterar esta categoria?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    while (1)
                    {
                        clearPrompt();
                        printf("Qual campo deseja alterar?\n");
                        printf("1 - Descri‡Æo             - %s\n", categoria.descricao);
                        printf("2 - Valor da Di ria       - R$%.2f\n", categoria.valor_diaria);
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
                            printf("Informe a descri‡Æo da categoria: ");
                            scanf(" %[^\n]", categoria.descricao);
                            break;

                        case 2:
                            fflush(stdin);
                            printf("Informe o valor da di ria: R$");
                            scanf("%f", &categoria.valor_diaria);
                            break;

                        case 3:
                            fflush(stdin);
                            printf("Informe a quantidade de pessoas: ");
                            scanf("%d", &categoria.qtd_pessoas);
                            break;

                        default:
                            printf("Insira um valor v lido.\n");
                            pausaSist();
                            break;
                        }
                    }

                    if (choice == 5)
                    {
                        ret = editarCategoria(mode, categoria.codigo, categoria);

                        if (ret == 0)
                        {
                            printf("Categoria de Acomoda‡Æo alterada com sucesso!\n");
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
                printf("Categoria de Acomoda‡Æo nÆo encontrada.\n");
                pausaSist();
            }

            break;

        case 4:
            printf("Informe o c¢digo da categoria a ser exclu¡da: ");
            scanf("%d", &categoria.codigo);

            ret = pesquisarCategoria(mode, categoria.codigo, &categoria);

            if (ret == 0)
            {
                printf("Categoria de Acomoda‡Æo encontrada!\n");
                printf("===================================\n");
                printf("C¢digo                : %d\n", categoria.codigo);
                printf("Descri‡Æo             : %s\n", categoria.descricao);
                printf("Valor da Di ria       : R$%.2f\n", categoria.valor_diaria);
                printf("Quantidade de Pessoas : %d\n", categoria.qtd_pessoas);
                printf("===================================\n");
                printf("Deseja excluir esta categoria?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirCategoria(mode, categoria.codigo);

                    if (ret == 0)
                    {
                        printf("Categoria de Acomoda‡Æo exclu¡da com sucesso!\n");
                        pausaSist();
                    }
                    else
                    {
                        printf("Erro ao excluir Categoria de Acomoda‡Æo.\n");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("Categoria de Acomoda‡Æo nÆo encontrada.\n");
                pausaSist();
            }

            break;

        case 5:
            printf("Cadastrando acomoda‡Æo.\n");

            printf("Informe a descri‡Æo da acomoda‡Æo: ");
            fflush(stdin);
            scanf(" %[^\n]", acomodacao.descricao);

            printf("Informe as facilidades: ");
            fflush(stdin);
            scanf(" %[^\n]", acomodacao.facilidades);

            printf("Informe o c¢digo da categoria da acomoda‡Æo: ");
            fflush(stdin);
            scanf("%d", &acomodacao.catec_acomod.codigo);

            ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod);

            if (ret == 0)
            {
                ret = cadastrarAcomodacao(mode, acomodacao);

                if (ret == 0)
                {
                    printf("Acomoda‡Æo cadastrada com sucesso!\n");
                    pausaSist();
                }
                else
                {
                    printf("Erro ao abrir o arquivo de acomoda‡äes.\n");
                    pausaSist();
                }
            }
            else
            {
                printf("O c¢digo dessa categoria de acomoda‡Æo nÆo existe.\n");
                pausaSist();
            }

            break;

        case 6:

            printf("Pesquisando acomoda‡Æo.\n");
            printf("Informe o c¢digo da acomoda‡Æo: ");
            scanf("%d", &acomodacao.codigo);

            ret = pesquisarAcomodacao(mode, acomodacao.codigo, &acomodacao);

            if (ret == 0)
            {
                ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod);

                printf("Acomoda‡Æo encontrada!\n");
                printf("===========================\n");
                printf("C¢digo      : %d\n", acomodacao.codigo);
                printf("Descri‡Æo   : %s\n", acomodacao.descricao);
                printf("Facilidades : %s\n", acomodacao.facilidades);
                printf("=> Categoria de Acomoda‡Æo\n");
                if (ret == 0)
                {
                    printf("=  C¢digo                : %d\n", acomodacao.catec_acomod.codigo);
                    printf("=  Descri‡Æo             : %s\n", acomodacao.catec_acomod.descricao);
                    printf("=  Valor da Di ria       : R$%.2f\n", acomodacao.catec_acomod.valor_diaria);
                    printf("=  Quantidade de Pessoas : %d\n", acomodacao.catec_acomod.qtd_pessoas);
                }
                else
                {
                    printf("= A categoria desta acomoda‡Æo foi exclu¡da, por favor, altere a acomoda‡Æo para resolver o problema.\n");
                }

                pausaSist();
            }
            else
            {
                printf("Acomoda‡Æo nÆo encontrada!\n");
                pausaSist();
            }
            break;

        case 7:
            printf("Alterando acomoda‡Æo.\n");
            printf("Informe o c¢digo da acomoda‡Æo: ");
            scanf("%d", &acomodacao.codigo);

            ret = pesquisarAcomodacao(mode, acomodacao.codigo, &acomodacao);

            if (ret == 0)
            {
                ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod);

                printf("Acomoda‡Æo encontrada!\n");
                printf("===================================\n");
                printf("C¢digo      : %d\n", acomodacao.codigo);
                printf("Descri‡Æo   : %s\n", acomodacao.descricao);
                printf("Facilidades : %s\n", acomodacao.facilidades);
                printf("=> Categoria de Acomoda‡Æo\n");
                if (ret == 0)
                {
                    printf("=  C¢digo      : %d\n", acomodacao.catec_acomod.codigo);
                    printf("=  Descri‡Æo   : %s\n", acomodacao.catec_acomod.descricao);
                }
                else
                {
                    printf("Informe uma nova categoria para esta acomoda‡Æo!\n");
                }
                printf("===================================\n");
                printf("Deseja alterar esta acomoda‡Æo?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    int codTemp;
                    while (1)
                    {
                        clearPrompt();
                        printf("Qual campo deseja alterar?\n");
                        printf("1 - Descri‡Æo   : %s\n", acomodacao.descricao);
                        printf("2 - Facilidades : %s\n\n", acomodacao.facilidades);
                        printf("Categoria de Acomoda‡Æo:\n");

                        ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod);

                        if (ret == 0)
                        {
                            printf("3 - C¢digo      : %d - %s\n\n", acomodacao.catec_acomod.codigo, acomodacao.catec_acomod.descricao);
                        }
                        else
                        {
                            printf("3 - C¢digo      : %d - Indispon¡vel.\n\n", acomodacao.catec_acomod.codigo);
                        }

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
                            printf("Informe a nova descri‡Æo da acomoda‡Æo: ");
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
                            printf("Informe o novo c¢digo da categoria da acomoda‡Æo: ");
                            fflush(stdin);
                            scanf("%d", &acomodacao.catec_acomod.codigo);

                            ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod);

                            if (ret != 0)
                            {
                                printf("Informe um c¢digo de categoria v lido!\n");
                                pausaSist();

                                acomodacao.catec_acomod.codigo = codTemp;
                            }
                            break;

                        default:
                            printf("Selecione uma op‡Æo v lida.\n");
                            pausaSist();
                            break;
                        }
                    }

                    if (choice == 5)
                    {
                        ret = editarAcomodacao(mode, acomodacao.codigo, acomodacao);

                        if (ret == 0)
                        {
                            printf("Acomoda‡Æo alterada com sucesso!\n");
                            pausaSist();
                        }
                        else
                        {
                            printf("Erro ao alterar Acomoda‡Æo.\n");
                            pausaSist();
                        }
                    }
                }
            }
            else
            {
                printf("Acomoda‡Æo nÆo encontrada!\n");
                pausaSist();
            }
            break;

        case 8:
            printf("Excluindo acomoda‡Æo.\n");
            printf("Informe o c¢digo da acomoda‡Æo: ");
            scanf("%d", &acomodacao.codigo);

            ret = pesquisarAcomodacao(mode, acomodacao.codigo, &acomodacao);

            if (ret == 0)
            {
                ret = pesquisarCategoria(mode, acomodacao.catec_acomod.codigo, &acomodacao.catec_acomod);

                printf("Categoria de Acomoda‡Æo encontrada!\n");
                printf("===================================\n");
                printf("C¢digo      : %d\n", acomodacao.codigo);
                printf("Descri‡Æo   : %s\n", acomodacao.descricao);
                printf("Facilidades : %s\n", acomodacao.facilidades);
                printf("=> Categoria de Acomoda‡Æo\n");

                if (ret == 0)
                {
                    printf("=  C¢digo      : %d\n", acomodacao.catec_acomod.codigo);
                    printf("=  Descri‡Æo   : %s\n", acomodacao.catec_acomod.descricao);
                }
                else
                {
                    printf("A categoria desta acomoda‡Æo foi apagada!\n");
                }
                printf("===================================\n");
                printf("Deseja excluir esta acomoda‡Æo?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirAcomodacao(mode, acomodacao.codigo);

                    if (ret == 0)
                    {
                        printf("Acomoda‡Æo exclu¡da com sucesso!\n");
                        pausaSist();
                    }
                    else
                    {
                        printf("Erro ao excluir Acomoda‡Æo.\n");
                        pausaSist();
                    }
                }
            }
            else
            {
                printf("Acomoda‡Æo nÆo encontrada!\n");
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
            return;

        default:
            printf("Op‡Æo inv lida. Tente novamente.\n");
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
        // menu principal da se?’o funcionarios
        printf("Cadastro e Gest’o de Fornecedores:\n");
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
            printf("Indique a raz’o social       : ");
            scanf(" %[^\n]", f.razao_social);

            fflush(stdin);
            printf("Indique a inscri?’o estadual : ");
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

            // fun?’o cadastra o fornecedor
            ret = cadastrarFornecedor(mode, f);

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
                printf("C½digo             : %d\n", f.codigo);
                printf("Nome Fornecedor    : %s\n", f.nome);
                printf("Raz’o Social       : %s\n", f.razao_social);
                printf("Inscri?’o Estadual : %s\n", f.inscricao_estadual);
                printf("CNPJ               : %s\n", f.cnpj);
                printf("Endere?o Completo  : %s\n", f.end_completo);
                printf("Telefone           : %s\n", f.telefone);
                printf("Email              : %s\n", f.email);
                pausaSist();
            }
            else
            {
                printf("=> Fornecedor n’o encontrado!\n");
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
                printf("C¢digo             : %d\n", f.codigo);
                printf("Nome               : %s\n", f.nome);
                printf("Telefone           : %s\n", f.telefone);
                printf("Email              : %s\n", f.email);
                printf("CNPJ               : %s\n", f.cnpj);
                printf("=========================================\n");
                printf("Deseja alterar este fornecedor?\n");
                printf("1 - Sim\n");
                printf("0 - N’o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    clearPrompt();
                    fflush(stdin);
                    printf("Indique o novo nome               : ");
                    scanf(" %[^\n]", f.nome);

                    fflush(stdin);
                    printf("Indique a nova raz’o social       : ");
                    scanf(" %[^\n]", f.razao_social);

                    fflush(stdin);
                    printf("Indique a nova inscri?’o estadual : ");
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
                printf("=> Fornecedor n’o encontrado!\n");
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
                printf("C½digo             : %d\n", f.codigo);
                printf("Nome               : %s\n", f.nome);
                printf("Telefone           : %s\n", f.telefone);
                printf("Email              : %s\n", f.email);
                printf("CNPJ               : %s\n", f.cnpj);
                printf("=========================================\n");
                printf("Deseja excluir este fornecedor?\n");
                printf("1 - Sim\n");
                printf("0 - N’o\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirFornecedor(mode, f.cnpj);

                    if (ret == 0)
                    {
                        printf("Fornecedor exclu­do com sucesso!");
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
                printf("Fornecedor n’o encontrado.");
                pausaSist();
            }

            break;
        default: // ===== EM CASO DE OUTRA OP?€O =====
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
    str_produtos prod;

    while (1)
    {
        clearPrompt();
        // menu principal da se?’o funcionarios
        printf("Cadastro e GestÆo de Produtos:\n");
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

            printf("DIGITE O CàDIGO DO PRODUTO: ");
            fflush(stdin);
            scanf("%d", &prod.codigo);

            printf("DIGITE A DESCRI€ÇO DO PRODUTO: ");
            fflush(stdin);
            scanf("%[^\n]", prod.descricao);

            printf("DIGITE O ESTOQUE DO PRODUTO: ");
            fflush(stdin);
            scanf("%d", &prod.estoque);

            printf("DIGITE O ESTOQUE MÖNIMO DO PRODUTO: ");
            fflush(stdin);
            scanf("%d", &prod.estoque_min);

            printf("DIGITE O PRE€O DE CUSTO DO PRODUTO: ");
            fflush(stdin);
            scanf("%f", &prod.preco_custo);

            printf("DIGITE O PRE€O DE VENDA DO PRODUTO: ");
            fflush(stdin);
            scanf("%f", &prod.preco_venda);

            ret = cadastro_produto(mode, prod);

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
            printf("DIGITE O CàDIGO DO PRODUTO: \n");
            fflush(stdin);
            scanf("%d", &prod.codigo);
            ret = pesquisaProduto(mode, prod.codigo, &prod);
            if (ret == 0)
            {
                printf("----DADOS DO PRODUTO---- \n");
                printf("CàDIGO DO PRODUTO: %d\n", prod.codigo);
                printf("DESCRI€ÇO DO PRODUTO: %s\n", prod.descricao);
                printf("ESTOQUE DO PRODUTO: %d\n", prod.estoque);
                printf("ESTOQUE MÖNIMO DO PRODUTO: %d\n", prod.estoque_min);
                printf("CUSTO DO PRODUTO: R$%.2f\n", prod.preco_custo);
                printf("PRE€O DE VENDA: R$%.2f\n", prod.preco_venda);
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
            printf("DIGITE O CàDIGO DO PRODUTO: \n");
            fflush(stdin);
            scanf("%d", &prod.codigo);

            ret = pesquisaProduto(mode, prod.codigo, &prod);

            if (ret == 0)
            {
                printf("----DADOS DO PRODUTO---- \n");
                printf("CàDIGO DO PRODUTO: %d\n", prod.codigo);
                printf("DESCRI€ÇO DO PRODUTO: %s\n", prod.descricao);
                printf("ESTOQUE DO PRODUTO: %d\n", prod.estoque);
                printf("ESTOQUE MÖNIMO DO PRODUTO: %d\n", prod.estoque_min);
                printf("CUSTO DO PRODUTO: R$%.2f\n", prod.preco_custo);
                printf("PRE€O DE VENDA: R$%.2f\n", prod.preco_venda);

                printf("\n");
                printf("TEM CERTEZA QUE DESEJA ALTERAR ESTE PRODUTO?\n");
                printf("1 - SIM\n");
                printf("2 - NÇO\n");
                printf("\n");
                printf("INSIRA: ");
                scanf("%d", &x);
                clearPrompt();

                if (x == 1)
                {
                    printf("---- DADOS DO PRODUTO ----\n");
                    printf("1 - CàDIGO DO PRODUTO: %d\n", prod.codigo);
                    printf("2 - DESCRI€ÇO DO PRODUTO: %s\n", prod.descricao);
                    printf("3 - ESTOQUE: %d\n", prod.estoque);
                    printf("4 - ESTOQUE MÖNIMO: %d\n", prod.estoque_min);
                    printf("5 - PRE€O DE CUSTO: %.2f\n", prod.preco_custo);
                    printf("6 - PRE€O DE VENDA: %.2f\n", prod.preco_venda);
                    printf("\n");
                    printf("INSIRA: ");
                    scanf("%d", &x);
                    if (x == 1)
                    {
                        printf("DIGITE O CàDIGO DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%d", &prod.codigo);
                        printf("\n");
                    }

                    if (x == 2)
                    {
                        printf("DIGITE A DESCRI€ÇO DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%[^\n]", prod.descricao);
                    }

                    if (x == 3)
                    {
                        printf("DIGITE O ESTOQUE: ");
                        fflush(stdin);
                        scanf("%d", &prod.estoque);
                    }

                    if (x == 4)
                    {
                        printf("DIGITE O ESTOQUE MÖNIMO DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%d", &prod.estoque_min);
                    }

                    if (x == 5)
                    {
                        printf("DIGITE O PRE€O DE CUSTO DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%f", &prod.preco_custo);
                    }

                    if (x == 6)
                    {
                        printf("DIGITE O PRE€O DE VENDA DO PRODUTO: ");
                        fflush(stdin);
                        scanf("%f", &prod.preco_venda);
                    }
                }
                ret = alteraProduto(mode, prod);

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
            printf("DIGITE O CàDIGO DO PRODUTO: \n");
            fflush(stdin);
            scanf("%d", &prod.codigo);

            ret = pesquisaProduto(mode, prod.codigo, &prod);

            if (ret == 0)
            {
                printf("PRODUTO ENCONTRADO!\n");
                printf("=========================\n");
                printf("C¢digo    : %d\n", prod.codigo);
                printf("Descri‡Æo : %s\n", prod.descricao);
                printf("Estoque   : %d\n", prod.estoque);
                printf("=========================\n");
                printf("Deseja apagar esse produto?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                scanf("%d", &x);

                if (x == 1)
                {
                    ret = deletaProduto(mode, prod.codigo);

                    if (ret == 0)
                    {
                        printf("PRODUTO EXCLUÖDO COM SUCESSO");
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
                printf("PRODUTO NÇO ENCONTRADO");
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
        printf("Cadastro e GestÆo de Operadores do Sistema:\n");
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
            printf("Indique as permissäes (separadas por v¡rgulas) : ");
            scanf(" %[^\n]", operador.permissoes);

            // Fun‡Æo cadastra o operador
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
                printf("Permissäes  : %s\n", operador.permissoes);
                pausaSist();
            }
            else
            {
                printf("=> Operador nÆo encontrado!\n");
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
                printf("Permissäes  : %s\n", operador.permissoes);
                printf("=========================================\n");
                printf("Deseja alterar este operador?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
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
                    printf("Indique as novas permissäes (separadas por v¡rgulas) : ");
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
                printf("=> Operador nÆo encontrado!\n");
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
                printf("Permissäes  : %s\n", operador.permissoes);
                printf("=========================================\n");
                printf("Deseja excluir este operador?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirOperador(mode, operador.usuario);

                    if (ret == 0)
                    {
                        printf("Operador exclu¡do com sucesso!");
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
                printf("Operador nÆo encontrado.");
                pausaSist();
            }
            break;

        default: // EM CASO DE OUTRA OP€ÇO
            printf("\n[X] ERRO - Insira um valor v lido!");
            pausaSist();
            break;
        }
    }

    return;
}

// RESERVAS: sendo desenvolvido

/*
void visualReservas()
{
  int mode;
  str_reservas reservaDados[5], reserva;
  int ret, choice, num_reservas;
  while (1)
  {
    clearPrompt();
    printf("=> RESERVAS:\n");
    printf("Selecione uma op  o: \n");
    printf("1 - Verificar disponibilidades\n");
    printf("2 - Fazer Reserva\n");
    printf("3 - Cancelamento\n");
    printf("4 - Voltar\n");
    printf("=> ");
    scanf("%d", &choice);
    if (choice == 4)
    {
      break;
    }
    switch (choice)
    {
    case 1: // Verificar disponibilidade das acomoda  es

      printf("Como deseja verificar a disponibilidade das acomoda  es?\n");
      printf("1 - Pesquisa por Data.\n");
      printf("2 - Pesquisa por Categoria.\n");
      printf("3 - Pesquisa por Quantidade de Pessoas.\n");
      printf("4 - Tipo de Facilidade.\n");
      printf("5 - Combina  o.\n");
      printf("=> \n");
      scanf("%d", &choice);

      switch (choice)
      {
      case 1:
        printf("Indique o dia e o mes de check-in (DD/MM): ");
        scanf("%d/%d", &reserva.dia_iniReserva, &reserva.mes_iniReserva);

        printf("Indique o dia e o mes de check-out (DD/MM): ");
        scanf("%d/%d", &reserva.dia_fimReserva, &reserva.mes_fimReserva);


        ret = pesquisarDisp_porData(mode, reserva, reservaDados, num_reservas, reserva.dia_iniReserva, reserva.mes_iniReserva, reserva.dia_fimReserva, reserva.mes_fimReserva);

        if (ret == 0)
        {
          printf("Nenhuma acomoda‡Æo dispon¡vel nesta data.\n");
        }
        else
        {
          printf("RESULTADOS: ---------------\n");
          for (int i = 0; i < ret; i++)
          {
            printf("Op‡Æo: %d =================\n", i);
            printf("Codigo      : %d\n", reservaDados[i].acomod.codigo);
            printf("Descri‡Æo   : %s\n", reservaDados[i].acomod.descricao);
            printf("Facilidades : %s\n", reservaDados[i].acomod.facilidades);
            printf("Categoria desta Acomoda‡Æo --------------\n");
            printf(" - Codigo                : %d\n", reservaDados[i].acomod.catec_acomod.codigo);
            printf(" - Descri‡Æo             : %s\n", reservaDados[i].acomod.catec_acomod.descricao);
            printf(" - Valor da Di ria       : %.2f\n", reservaDados[i].acomod.catec_acomod.valor_diaria);
            printf(" - Quantidade de Pessoas : %d\n", reservaDados[i].acomod.catec_acomod.qtd_pessoas);
          }
        }

        break;
      case 2:
        int codigoCateg;
        printf("Indique o c digo da categoria que deseja reservar: ");
        scanf("%d", &codigoCateg);

        ret = pesquisaDisp_PorCateg(codigoCateg, 30);

        if (ret == 1)
        {
          printf("Categoria de acomoda‡Æo dispon¡vel para reserva nos pr¢ximos 30 dias.\n");
          printf(" ---------------\n");
          for (int i = 0; i < ret; i++) {
            printf("Categoria de Acomoda‡Æo --------------\n");
            printf(" - Codigo                : %d\n", reservaDados[i].acomod.catec_acomod.codigo);
            printf(" - Descri‡Æo             : %s\n", reservaDados[i].acomod.catec_acomod.descricao);
            printf(" - Valor da Di ria       : %.2f\n", reservaDados[i].acomod.catec_acomod.valor_diaria);
            printf(" - Quantidade de Pessoas : %d\n", reservaDados[i].acomod.catec_acomod.qtd_pessoas);
          }
        }
        else
        {
          printf("Categoria de acomoda‡Æo nÆo est  dispon¡vel para reserva nos pr¢ximos 30 dias.\n");
        }

        break;
      case 3:
        int num_pessoas;
        printf("Digite o n£mero desejado de pessoas para uma acomoda‡Æo: ");
        scanf("%d", &num_pessoas);

        int disponibilidade = pesquisaDisp_PorQtdPessoas(mode, reservaDados, num_reservas, num_pessoas, 30);
        if (disponibilidade == 0)
        {
          printf("Categorias e acomoda‡äes dispon¡veis: \n");
          for (int i = 0; i < num_reservas; i++)
          {
            printf("Op‡Æo: %d =================\n", i);
            printf("Codigo      : %d\n", reservaDados[i].acomod.codigo);
            printf("Descri‡Æo   : %s\n", reservaDados[i].acomod.descricao);
            printf("Facilidades : %s\n", reservaDados[i].acomod.facilidades);
            printf("Categoria desta Acomoda‡Æo --------------\n");
            printf(" - Codigo                : %d\n", reservaDados[i].acomod.catec_acomod.codigo);
            printf(" - Descri‡Æo             : %s\n", reservaDados[i].acomod.catec_acomod.descricao);
            printf(" - Valor da Di ria       : %.2f\n", reservaDados[i].acomod.catec_acomod.valor_diaria);
            printf(" - Quantidade de Pessoas : %d\n", reservaDados[i].acomod.catec_acomod.qtd_pessoas);
          }
        }
        else
        {
          printf("Nenhuma categoria de acomoda‡Æo dispon¡vel para a quantidade de pessoas especificada nos pr¢ximos 30 dias.\n");
        }

        break;
      case 4:
        time_t agora = time(NULL);
        struct tm data_atual = *localtime(&agora);
        char facilidades_desejadas[200];
        printf("Digite as facilidades desejadas: ");
        scanf("%s", facilidades_desejadas);

        int disponibilidade = pesquisaPor_Facilidades(mode, reserva, num_reservas, facilidades_desejadas, 30);

        if (disponibilidade == 0)
        {
          printf("Acomoda‡äes com as facilidades desejadas estÆo dispon¡veis nos pr¢ximos 30 dias: \n");
          for (int i = 0; i < num_reservas; i++)
          {
            printf("Op‡Æo: %d =================\n", i);
            printf("Codigo      : %d\n", reservaDados[i].acomod.codigo);
            printf("Descri‡Æo   : %s\n", reservaDados[i].acomod.descricao);
            printf("Facilidades : %s\n", reservaDados[i].acomod.facilidades);
            printf("Categoria desta Acomoda‡Æo --------------\n");
            printf(" - Codigo                : %d\n", reservaDados[i].acomod.catec_acomod.codigo);
            printf(" - Descri‡Æo             : %s\n", reservaDados[i].acomod.catec_acomod.descricao);
            printf(" - Valor da Di ria       : %.2f\n", reservaDados[i].acomod.catec_acomod.valor_diaria);
            printf(" - Quantidade de Pessoas : %d\n", reservaDados[i].acomod.catec_acomod.qtd_pessoas);
          }
        }
        else
        {
          printf("Nenhuma acomoda‡Æo com as facilidades desejadas est  dispon¡vel nos pr¢ximos 30 dias.\n");
        }
        break;
      case 5:

        printf("Indique o dia e o mes de check-in (DD/MM): ");
        scanf("%d/%d", &reserva.dia_iniReserva, &reserva.mes_iniReserva);

        printf("Indique o dia e o mes de check-out (DD/MM): ");
        scanf("%d/%d", &reserva.dia_fimReserva, &reserva.mes_fimReserva);

        printf("Digite o c¢digo da categoria (ou -1 para ignorar a categoria): ");
        scanf("%d", &codigoCateg);

        printf("Digite o n£mero de pessoas desejado (ou -1 para ignorar a quantidade de pessoas): ");
        scanf("%d", &num_pessoas);

        printf("Digite as facilidades desejadas (ou deixe em branco para ignorar as facilidades): ");
        scanf("%s", facilidades_desejadas);

        struct tm check_in = {0};
        check_in.tm_year = data_atual.tm_year;
        check_in.tm_mon = reserva.mes_iniReserva - 1;
        check_in.tm_mday = reserva.dia_iniReserva;

        struct tm check_out = {0};
        check_out.tm_year = data_atual.tm_year;
        check_out.tm_mon = reserva.mes_fimReserva - 1;
        check_out.tm_mday = reserva.dia_fimReserva;

        int disponibilidade = pesquisaPorDisponibilidade(mode, reservaDados, num_reservas, check_in, check_out, codigoCateg, num_pessoas, facilidades_desejadas, 30);

        if (disponibilidade > 0)
        {
          printf("Acomoda‡äes dispon¡veis com base nos crit‚rios fornecidos.\n");
          for (int i = 0; i < disponibilidade; i++)
          {
            printf("Op‡Æo: %d =================\n", i);
            printf("Codigo      : %d\n", reservaDados[i].acomod.codigo);
            printf("Descri‡Æo   : %s\n", reservaDados[i].acomod.descricao);
            printf("Facilidades : %s\n", reservaDados[i].acomod.facilidades);
            printf("Categoria desta Acomoda‡Æo --------------\n");
            printf(" - Codigo                : %d\n", reservaDados[i].acomod.catec_acomod.codigo);
            printf(" - Descri‡Æo             : %s\n", reservaDados[i].acomod.catec_acomod.descricao);
            printf(" - Valor da Di ria       : %.2f\n", reservaDados[i].acomod.catec_acomod.valor_diaria);
            printf(" - Quantidade de Pessoas : %d\n", reservaDados[i].acomod.catec_acomod.qtd_pessoas);
          }
        }
        else
        {
          printf("Nenhuma acomoda‡Æo dispon¡vel com base nos crit‚rios fornecidos.\n");
        }

      default:
        break;
      }

    case 2:
      printf("Qual ‚ o dia e mes de check-in desejado para a sua reserva? Digite em DD/MM/AA");
      scanf("%d/%d", &reserva.dia_iniReserva, &reserva.dia_fimReserva);

      int dataDisp = pesquisaDisp_PorData(mode, reserva, num_reservas, reserva.dia_iniReserva, reserva.dia_fimReserva);

      printf("Digite o c¢digo da categoria de acomoda‡Æo desejada\n");
      for (int i = 0; i < reservaDados; i++)
      {
        printf("Categoria de Acomoda‡Æo --------------\n");
        printf(" - Codigo                : %d\n", reservaDados[i].acomod.catec_acomod.codigo);
        printf(" - Descri‡Æo             : %s\n", reservaDados[i].acomod.catec_acomod.descricao);
        printf(" - Valor da Di ria       : %.2f\n", reservaDados[i].acomod.catec_acomod.valor_diaria);
        printf(" - Quantidade de Pessoas : %d\n", reservaDados[i].acomod.catec_acomod.qtd_pessoas);
      }
      scanf("%d", &reserva.acomod.catec_acomod.codigo);

      printf("Digite o c¢digo da acomoda‡Æo desejada\n");
      for (int i = 0; i < reservaDados; i++)
          {
            printf("Op‡Æo: %d =================\n", i);
            printf("Codigo      : %d\n", reservaDados[i].acomod.codigo);
            printf("Descri‡Æo   : %s\n", reservaDados[i].acomod.descricao);
            printf("Facilidades : %s\n", reservaDados[i].acomod.facilidades);
          }
      scanf("%d", &reserva.acomod.codigo);

      if (reservar() == 1)
      {
        printf("Reserva feita com sucesso!\n");
      }
      else{
        printf("A reserva nÆo foi feita.");
      }






      break;
    case 3: // Reservar

      break;
    case 4: // Cancelamento

      break;
    default:
      printf("\n[X] ERRO - Insira um valor v lido!");
      pausaSist();
      break;
    }
  }
}
*/
