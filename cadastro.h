#ifndef CADASTROS_H
#define CADASTROS_H

#include "estruturas.h" //inclusão da biblioteca estruturas para a implementação das structs

//função que cadastra os dados da oficina
Dados_Oficina cadastrar_dados_oficina();

//função que cadastra os dados dos clientes
Cliente cadastrar_dados_cliente();

//função que cadastra os dados dos veículos
Veiculo cadastrar_dados_veiculo();

//função que cadastra os dados das peças
Peca cadastrar_dados_peca();

//função que cadastra os dados dos fornecedores
Fornecedor cadastrar_dados_fornecedor();

//função que cadastra os dados dos serviços
Servico cadastrar_dados_servico();

//função que cadastra os dados dos funcionários
Funcionario cadastrar_dados_funcionario();

#endif