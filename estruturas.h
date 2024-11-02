#include<stdio.h>

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

