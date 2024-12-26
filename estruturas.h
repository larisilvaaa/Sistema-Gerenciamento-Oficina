#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h> // Entrada e saída de dados.
#include <stdlib.h> // Funções gerais como alocação de memória.
#include <string.h> // Manipulação de strings.
#include <time.h> // Operações com tempo e data.
#include <sys/stat.h> // Informações sobre arquivos e diretórios.


// Subestrutura para armazenar os dados de endereço, já que vai ser usada em várias outras partes.
typedef struct {
    char estado[3]; // Estado, como "SP", "RJ", 2 letras + o '\0'.
    char cidade[30]; // Nome da cidade.
    int cep; // CEP para localização.
    char bairro[30]; // Bairro do local.
    char rua[50]; // Nome da rua ou avenida.
    int numero; // Número do imóvel.
} Endereco;

// Estrutura principal para armazenar os dados da oficina, incluindo o lucro.
typedef struct {
    char nome[100]; // Nome da oficina.
    long int cpf_cnpj; // CPF ou CNPJ da oficina.
    Endereco endereco; // Subestrutura para organizar o endereço.
    long int telefone; // Telefone para contato.
    char email[50]; // E-mail da oficina.
    float porcentagemLucro; // Porcentagem de lucro aplicada nos serviços.
} Dados_Oficina;

// Estrutura para os clientes, que são fundamentais no sistema.
typedef struct {
    int codigo; // Código único do cliente.
    char nome[100]; // Nome completo do cliente.
    long int cpf_cnpj; // CPF ou CNPJ do cliente.
    Endereco endereco; // Endereço completo do cliente.
    long int telefone; // Telefone para contato.
    char email[50]; // E-mail do cliente.
} Cliente;

// Estrutura para os veículos que a oficina vai atender.
typedef struct {
    char placa[10]; // Placa do veículo.
    char modelo[30]; // Modelo, como "Gol", "Civic".
    char marca[30]; // Marca, como "Volkswagen", "Honda".
    int anoFabricacao; // Ano de fabricação do veículo.
    char chassi[20]; // Número do chassi, identificação única.
    int proprietario; // Dono do veículo, do tipo Cliente.
} Veiculo;

// Estrutura para as peças usadas nos serviços da oficina.
typedef struct {
    int codigo; // Código único da peça.
    char descricao[100]; // Descrição da peça.
    char fabricante[50]; // Fabricante responsável.
    char fornecedor[50]; // Fornecedor da peça.
    float precoCusto; // Preço pago pela oficina.
    float precoVenda; // Preço de venda para o cliente.
    int quantidadeEstoque; // Quantidade disponível no estoque.
    int estoqueMinimo; // Estoque mínimo antes de repor.
} Peca;

// Estrutura para os fornecedores das peças e outros itens.
typedef struct {
    int codigo; // Código único do fornecedor.
    char nomeFantasia[100]; // Nome fantasia da empresa.
    char razaoSocial[100]; // Razão social da empresa.
    char inscricaoEstadual[20]; // Inscrição estadual.
    long int cnpj; // CNPJ do fornecedor.
    Endereco endereco; // Endereço completo do fornecedor.
    long int telefone; // Telefone para contato.
    char email[50]; // E-mail para comunicação.
} Fornecedor;

// Estrutura para os serviços que a oficina oferece.
typedef struct {
    int codigo; // Código único do serviço.
    char descricao[100]; // Descrição do serviço.
    float preco; // Preço do serviço para o cliente.
    float comissao; // Comissão paga ao funcionário que executa o serviço.
} Servico;

// Estrutura para os funcionários que trabalham na oficina.
typedef struct {
    char nome[100]; // Nome completo do funcionário.
    long int cpf; // CPF do funcionário.
    char cargo[50]; // Cargo ocupado, como "Mecânico".
    float salario; // Salário do funcionário.
} Funcionario;

//Estrutura para agendamento e controle de serviços.
typedef struct {
    int controle; // Variável de contole.
    int codigo_peca; // Código da peça.
    char placa[10]; // Placa do veículo.
    int codigo_servico; // Código do serviço.
} Agendamento;

// Estrutura para armazenar transações no caixa
typedef struct {
    char descricao[50];      // Descrição da transação
    float valor;             // Valor da transação
    char tipo;           // Tipo: "E" para entreda ou "S" para saída
    char data[11];           // Data da transação
} TransacaoCaixa;

// Estrutura para contas a pagar
typedef struct {
    int id;                 // Identificador único da conta a pagar
    int codigo_fornecedor;  // Código do fornecedor
    char forma_pagamento[20]; // Forma de pagamento
    float valor;            // Valor a ser pago
    char prazo[20];         // Prazo do pagamento
    int pago;               // Variável para saber se foi pago (1 para sim, 0 para não)
} ContaPagar;

// Estrutura para contas a receber
typedef struct {
    int id;                 // Identificador único da conta a receber
    int codigo_cliente;     // Código do cliente
    char forma_pagamento[20]; // Forma de pagamento
    float valor;            // Valor a ser recebido
    char prazo[20];         // Prazo do pagamento
    int recebido;           // Variável para saber se foi recebido (1 para sim, 0 para não)
} ContaReceber;

// Estrutura para controle do caixa
typedef struct {
    float montante;          // Montante atual no caixa
    TransacaoCaixa* transacoes; // Lista dinâmica de transações
    int num_transacoes;      // Número de transações registradas
    ContaPagar* contas_pagar; // Lista dinâmica de contas a pagar
    int num_contas_pagar;    // Número de contas a pagar
    ContaReceber* contas_receber; // Lista dinâmica de contas a receber
    int num_contas_receber;  // Número de contas a receber
} Caixa;

#endif
