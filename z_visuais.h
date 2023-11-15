#ifndef Z_VISUAIS_H
#define Z_VISUAIS_H
#include "bib_cadastro_fornecedores.h"
#include "bib_cadastro_operadores.h"

/*
 * FUN��O CONTEM OS VISUAIS DA SE��O CADASTRO E GEST�O: HOTEL
 */
void visualCadastroHotel(int mode);

/*
 * FUN��O CONTEM OS VISUAIS DA SE��O CADASTRO E GEST�O: H�SPEDES
 */
void visualCadastroHospedes(int mode);

/*
 * FUN��O CONTEM OS VISUAIS DA SE��O CADASTRO E GEST�O: ACOMODA��ES
 */
void visualCadastroAcomodacoes(int mode);

/*
 * FUN��O CONTEM OS VISUAIS DA SE��O CADASTRO E GEST�O: FORNECEDOR
 */
void visualCadastroFornecedor(int mode, str_fornecedores * f);

/*
 * FUN��O CONTEM OS VISUAIS DA SE��O CADASTRO E GEST�O: PRODUTOS
 */
void visualCadastroProdutos(int mode);

/*
 * FUN��O CONTEM OS VISUAIS DA SE��O CADASTRO E GEST�O: OPERADORES
 */
void visualCadastroOperadores(int mode, str_op_sistemas * op);

#endif