#ifndef STRUCTS_H
#define STRUCTS_H

// Subestrutura para armazenar o endereço
typedef struct {
    char estado[30];
    char cidade[30];
    char cep[12];
    char bairro[30];
    char rua[50];
    int numero;
} Endereco;

// Estrutura principal para armazenar os dados do cliente da oficina
typedef struct {
    char nome[100];
    char cpf_cnpj[20];
    Endereco endereco; // Usando a subestrutura Endereco
    char telefone[15];
    char email[50];
    float porcentagemLucro; // Usando float para representar a porcentagem
} dados_Oficina;

// Estrutura para armazenar os dados dos clientes
typedef struct {
    int codigo;               // Código do cliente
    char nome[100];           // Nome do cliente
    char cpf_cnpj[20];        // CPF ou CNPJ
    Endereco endereco;        // Endereço do cliente (usando a subestrutura)
    char telefone[15];        // Telefone
    char email[50];           // E-mail
} Cliente;

// Estrutura para armazenar os dados dos veículos
typedef struct {
    char placa[10];           // Placa do veículo
    char modelo[30];          // Modelo do veículo
    char marca[30];           // Marca do veículo
    int anoFabricacao;        // Ano de fabricação do veículo
    char chassi[20];          // Chassi do veículo
    Cliente *proprietario;    // Ponteiro para o proprietário do veículo (tipo Cliente)
} Veiculo;


// Estrutura para armazenar os dados das peças
typedef struct {
    int codigo;               // Código da peça
    char descricao[100];      // Descrição da peça
    char fabricante[50];      // Fabricante
    char fornecedor[50];      // Nome do fornecedor
    float precoCusto;         // Preço de custo
    float precoVenda;         // Preço de venda
    int quantidadeEstoque;    // Quantidade em estoque
    int estoqueMinimo;        // Estoque mínimo
} Peca;

// Estrutura para armazenar os dados dos fornecedores
typedef struct {
    int codigo;               // Código do fornecedor (único)
    char nomeFantasia[100];   // Nome fantasia
    char razaoSocial[100];    // Razão social
    char inscricaoEstadual[20]; // Inscrição estadual
    char cnpj[20];            // CNPJ
    Endereco endereco;        // Endereço completo
    char telefone[15];        // Telefone
    char email[50];           // E-mail
} Fornecedor;

// Estrutura para armazenar os dados dos serviços oferecidos
typedef struct {
    int codigo;               // Código do serviço
    char descricao[100];      // Descrição do serviço
    float preco;              // Preço do serviço
    float comissao;           // Comissão paga ao funcionário
} Servico;

// Estrutura para armazenar os dados dos funcionários
typedef struct {
    char nome[100];           // Nome do funcionário
    char cpf[15];             // CPF
    char cargo[50];           // Cargo
    float salario;            // Salário
} Funcionario;

#endif