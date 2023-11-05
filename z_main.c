#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bib_cadastro_fornecedores.h"
#include "bib_cadastro_produtos.h"
#include "bib_cadastro_operadores.h"

void visualFornecedor()
{
    char nomeTemp[35], nomeOrg[35];
    int choice, ret;
    str_fornecedores f;

    while (1)
    {
        clearPrompt();
        // menu principal da se‡Æo funcionarios
        printf("Cadastro e GestÆo de Fornecedores:\n");
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
            printf("Indique a razÆo social       : ");
            scanf(" %[^\n]", f.razao_social);

            fflush(stdin);
            printf("Indique a inscri‡Æo estadual : ");
            scanf(" %[^\n]", f.inscricao_estadual);

            fflush(stdin);
            printf("Indique o cnpj               : ");
            scanf(" %[^\n]", f.cnpj);

            fflush(stdin);
            printf("Indique o endere‡o completo  : ");
            scanf(" %[^\n]", f.end_completo);

            fflush(stdin);
            printf("Indique o telefone           : ");
            scanf(" %[^\n]", f.telefone);

            fflush(stdin);
            printf("Indique o email              : ");
            scanf(" %[^\n]", f.email);

            // fun‡Æo cadastra o fornecedor
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

            ret = pesquisarFornecedor(f.cnpj, &f.codigo, f.nome, f.razao_social, f.inscricao_estadual,
                                      f.cnpj, f.end_completo, f.telefone, f.email);

            if (ret == 0)
            {
                printf("=> Fornecedor encontrado!\n");
                printf("=========================================\n");
                printf("C¢digo             : %d\n", f.codigo);
                printf("Nome Fornecedor    : %s\n", f.nome);
                printf("RazÆo Social       : %s\n", f.razao_social);
                printf("Inscri‡Æo Estadual : %s\n", f.inscricao_estadual);
                printf("CNPJ               : %s\n", f.cnpj);
                printf("Endere‡o Completo  : %s\n", f.end_completo);
                printf("Telefone           : %s\n", f.telefone);
                printf("Email              : %s\n", f.email);
                pausaSist();
            }
            else
            {
                printf("=> Fornecedor nÆo encontrado!\n");
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

            ret = pesquisarFornecedor(f.cnpj, &f.codigo, f.nome, f.razao_social, f.inscricao_estadual,
                                      f.cnpj, f.end_completo, f.telefone, f.email);

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
                printf("0 - NÆo\n");
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
                    printf("Indique a nova razÆo social       : ");
                    scanf(" %[^\n]", f.razao_social);

                    fflush(stdin);
                    printf("Indique a nova inscri‡Æo estadual : ");
                    scanf(" %[^\n]", f.inscricao_estadual);

                    fflush(stdin);
                    printf("Indique o novo cnpj               : ");
                    scanf(" %[^\n]", f.cnpj);

                    fflush(stdin);
                    printf("Indique o novo endere‡o completo  : ");
                    scanf(" %[^\n]", f.end_completo);

                    fflush(stdin);
                    printf("Indique o novo telefone           : ");
                    scanf(" %[^\n]", f.telefone);

                    fflush(stdin);
                    printf("Indique o novo email              : ");
                    scanf(" %[^\n]", f.email);

                    ret = alterarFornecedor(f.cnpj, f);

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
                printf("=> Fornecedor nÆo encontrado!\n");
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

            ret = pesquisarFornecedor(f.cnpj, &f.codigo, f.nome, f.razao_social, f.inscricao_estadual,
                                      f.cnpj, f.end_completo, f.telefone, f.email);

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
                printf("Deseja excluir este fornecedor?\n");
                printf("1 - Sim\n");
                printf("0 - NÆo\n");
                printf("=> ");
                scanf("%d", &choice);

                if (choice == 1)
                {
                    ret = excluirFornecedor(f.cnpj);

                    if (ret == 0)
                    {
                        printf("Fornecedor exclu¡do com sucesso!");
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
                printf("Fornecedor nÆo encontrado.");
                pausaSist();
            }

            break;
        default: // ===== EM CASO DE OUTRA OP€ÇO =====
            printf("\n[X] ERRO - Insira um valor valido!");
            pausaSist();
            break;
        }
    }

    return 0;
}

int visualProdutos(void)
{
  int x;
  int ret;
  str_produtos cliente;

  while (1)
  {

    clearPrompt();
    printf("\n");
    printf("-------- CADASTRO - PRODUTOS --------\n");
    printf("1 - CADASTRAR PRODUTO\n");
    printf("2 - VER DADOS DO PRODUTO\n");
    printf("3 - ALTERAR DADOS DO PRODUTO\n");
    printf("4 - DELETAR PRODUTO\n");
    printf("5 - ENCERRAR\n");
    printf("\n");
    printf("INSIRA: ");
    fflush(stdin);
    scanf("%d", &x);

    if (x == 5)
    {
      break;
    }

    switch (x)
    {
    case 1:

      printf("DIGITE O C�DIGO DO PRODUTO: ");
      fflush(stdin);
      scanf("%d", &cliente.codigo);

      printf("DIGITE A DESCRI��O DO PRODUTO: ");
      fflush(stdin);
      scanf("%[^\n]", cliente.descricao);

      printf("DIGITE O ESTOQUE DO PRODUTO: ");
      fflush(stdin);
      scanf("%d", &cliente.estoque);

      printf("DIGITE O ESTOQUE M�NIMO DO PRODUTO: ");
      fflush(stdin);
      scanf("%d", &cliente.estoque_min);

      printf("DIGITE O PRE�O DE CUSTO DO PRODUTO: ");
      fflush(stdin);
      scanf("%f", &cliente.preco_custo);

      printf("DIGITE O PRE�O DE VENDA DO PRODUTO: ");
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
      printf("DIGITE O C�DIGO DO PRODUTO: \n");
      fflush(stdin);
      scanf("%d", &cliente.codigo);
      ret = pesquisaProduto(cliente.codigo, cliente.descricao, &cliente.estoque, &cliente.estoque_min, &cliente.preco_custo, &cliente.preco_venda);
      if (ret == 0)
      {
        printf("----DADOS DO PRODUTO---- \n");
        printf("C�DIGO DO PRODUTO: %d\n", cliente.codigo);
        printf("DESCRI��O DO PRODUTO: %s\n", cliente.descricao);
        printf("ESTOQUE DO PRODUTO: %d\n", cliente.estoque);
        printf("ESTOQUE M�NIMO DO PRODUTO: %d\n", cliente.estoque_min);
        printf("CUSTO DO PRODUTO: R$%.2f\n", cliente.preco_custo);
        printf("PRE�O DE VENDA: R$%.2f\n", cliente.preco_venda);
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
      printf("DIGITE O C�DIGO DO PRODUTO: \n");
      fflush(stdin);
      scanf("%d", &cliente.codigo);
      ret = pesquisaProduto(cliente.codigo, cliente.descricao, &cliente.estoque, &cliente.estoque_min, &cliente.preco_custo, &cliente.preco_venda);
      if (ret == 0)
      {
        printf("----DADOS DO PRODUTO---- \n");
        printf("C�DIGO DO PRODUTO: %d\n", cliente.codigo);
        printf("DESCRI��O DO PRODUTO: %s\n", cliente.descricao);
        printf("ESTOQUE DO PRODUTO: %d\n", cliente.estoque);
        printf("ESTOQUE M�NIMO DO PRODUTO: %d\n", cliente.estoque_min);
        printf("CUSTO DO PRODUTO: R$%.2f\n", cliente.preco_custo);
        printf("PRE�O DE VENDA: R$%.2f\n", cliente.preco_venda);

        printf("\n");
        printf("TEM CERTEZA QUE DESEJA ALTERAR ESTE PRODUTO?\n");
        printf("1 - SIM\n");
        printf("2 - N�O\n");
        printf("\n");
        printf("INSIRA: ");
        scanf("%d", &x);
        clearPrompt();

        if (x == 1)
        {
          printf("---- DADOS DO PRODUTO ----\n");
          printf("1 - C�DIGO DO PRODUTO: %d\n", cliente.codigo);
          printf("2 - DESCRI��O DO PRODUTO: %s\n", cliente.descricao);
          printf("3 - ESTOQUE: %d\n", cliente.estoque);
          printf("4 - ESTOQUE M�NIMO: %d\n", cliente.estoque_min);
          printf("5 - PRE�O DE CUSTO: %.2f\n", cliente.preco_custo);
          printf("6 - PRE�O DE VENDA: %.2f\n", cliente.preco_venda);
          printf("\n");
          printf("INSIRA: ");
          scanf("%d", &x);
          if (x == 1)
          {
            printf("DIGITE O C�DIGO DO PRODUTO: ");
            fflush(stdin);
            scanf("%d", &cliente.codigo);
            printf("\n");
          }

          if (x == 2)
          {
            printf("DIGITE A DESCRI��O DO PRODUTO: ");
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
            printf("DIGITE O ESTOQUE M�NIMO DO PRODUTO: ");
            fflush(stdin);
            scanf("%d", &cliente.estoque_min);
          }

          if (x == 5)
          {
            printf("DIGITE O PRE�O DE CUSTO DO PRODUTO: ");
            fflush(stdin);
            scanf("%f", &cliente.preco_custo);
          }

          if (x == 6)
          {
            printf("DIGITE O PRE�O DE VENDA DO PRODUTO: ");
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
      printf("TEM CERTEZA QUE DESJA DELETAR OS DADOS DOS PRODUTOS?\n");
      printf("1 - SIM\n");
      printf("2 - N�O\n");
      printf("\n");
      printf("INSIRA: ");
      scanf("%d", &x);

      if (x == 1)
      {
        ret = deletaProduto();
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
}


void visualOperadores() {
    char ntemp[35], noriginal[35];
    int choice, ret;
    str_op_sistemas operador;
    
    while (1) {
        printf("Cadastro e Gestão de Operadores do Sistema:\n");
        printf("1 - Cadastrar\n");
        printf("2 - Pesquisar\n");
        printf("3 - Alterar\n");
        printf("4 - Excluir\n");
        printf("5 - Voltar\n");
        printf("=> ");
        scanf("%d", &choice);

        if (choice == 5) {
            break;  // Sai do loop quando a escolha for 5
        }

        switch (choice) {
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
                printf("Indique as permissões (separadas por vírgulas) : ");
                scanf(" %[^\n]", operador.permissoes);

                // Função cadastra o operador
                ret = cadastrarOperador(operador);

                if (ret == 0) {
                    printf("\nOperador cadastrado com sucesso!");
                    pausaSist();
                } else {
                    printf("Erro ao acessar o arquivo operadores.txt\n");
                    pausaSist();
                }
                break;

            case 2: // PESQUISAR OPERADOR
                printf("Pesquisar Operador: \n");
                printf("Login do operador: ");
                fflush(stdin);
                scanf("%s", operador.usuario);

                ret = pesquisarOperadorPorUsuario(operador.usuario, &operador);

                if (ret == 0) {
                    printf("=> Operador encontrado!\n");
                    printf("=========================================\n");
                    printf("Código      : %d\n", operador.codigo);
                    printf("Nome        : %s\n", operador.nome);
                    printf("Login       : %s\n", operador.usuario);
                    printf("Permissões  : %s\n", operador.permissoes);
                    pausaSist();
                } else {
                    printf("=> Operador não encontrado!\n");
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
                ret = pesquisarOperadorPorUsuario(operador.usuario, &operador);

                if (ret == 0) {
                    printf("=> Operador encontrado!\n");
                    printf("=========================================\n");
                    printf("Código      : %d\n", operador.codigo);
                    printf("Nome        : %s\n", operador.nome);
                    printf("Login       : %s\n", operador.usuario);
                    printf("Permissões  : %s\n", operador.permissoes);
                    printf("=========================================\n");
                    printf("Deseja alterar este operador?\n");
                    printf("1 - Sim\n");
                    printf("0 - Não\n");
                    printf("=> ");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        clearPrompt();
                        fflush(stdin);
                        printf("Indique o novo nome        : ");
                        scanf(" %[^\n]", operador.nome);

                        fflush(stdin);
                        printf("Indique a nova senha       : ");
                        scanf(" %[^\n]", operador.senha);

                        fflush(stdin);
                        printf("Indique as novas permissões (separadas por vírgulas) : ");
                        scanf(" %[^\n]", operador.permissoes);

                        ret = editarOperador(operador.usuario, operador);

                        if (ret == 0) {
                            printf("Operador alterado com sucesso!");
                            pausaSist();
                        } else {
                            printf("=> Falha ao alterar operador.");
                            pausaSist();
                        }
                    }
                } else {
                    printf("=> Operador não encontrado!\n");
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

                ret = pesquisarOperadorPorUsuario(operador.usuario, &operador);

                if (ret == 0) {
                    printf("=> Operador encontrado!\n");
                    printf("=========================================\n");
                    printf("Código      : %d\n", operador.codigo);
                    printf("Nome        : %s\n", operador.nome);
                    printf("Login       : %s\n", operador.usuario);
                    printf("Permissões  : %s\n", operador.permissoes);
                    printf("=========================================\n");
                    printf("Deseja excluir este operador?\n");
                    printf("1 - Sim\n");
                    printf("0 - Não\n");
                    printf("=> ");
                    scanf("%d", &choice);

                    if (choice == 1) {
                        ret = excluirOperador(operador.usuario);

                        if (ret == 0) {
                            printf("Operador excluído com sucesso!");
                            pausaSist();
                        } else {
                            printf("=> Falha ao excluir operador.");
                            pausaSist();
                        }
                    }
                } else {
                    printf("Operador não encontrado.");
                    pausaSist();
                }
                break;

            default: // EM CASO DE OUTRA OPÇÃO
                printf("\n[X] ERRO - Insira um valor válido!");
                pausaSist();
                break;
        }
    }

    return 0;
}