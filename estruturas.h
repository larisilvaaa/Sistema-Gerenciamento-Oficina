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