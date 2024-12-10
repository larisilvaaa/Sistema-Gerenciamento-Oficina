#ifndef CADASTROS_H
#define CADASTROS_H

#include "estruturas.h" //inclusão da biblioteca estruturas para a implementação das structs

//função que cadastra os dados da oficina
Dados_Oficina cadastrar_dados_oficina(char op);

//função que cadastra os dados dos clientes
Cliente cadastrar_dados_cliente(char op);

//função que cadastra os dados dos veículos
Veiculo cadastrar_dados_veiculo(char op);

//função que cadastra os dados das peças
Peca cadastrar_dados_peca(char op);

//função que cadastra os dados dos fornecedores
Fornecedor cadastrar_dados_fornecedor(char op);

//função que cadastra os dados dos serviços
Servico cadastrar_dados_servico(char op);

//função que cadastra os dados dos funcionários
Funcionario cadastrar_dados_funcionario(char op);

#endif