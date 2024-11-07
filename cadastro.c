#include <stdio.h>
#include "cadastro.h"

Dados_Oficina cadastrar_dados_oficina(){
    Dados_Oficina cliente;
   
    printf("Digite o nome do cliente: ");
    fgets(cliente.nome, 100, stdin);

    printf("Digite o CPF ou CNPJ: ");
    fgets(cliente.cpf_cnpj, 20, stdin);

    printf("Digite o endereço:\n");
    printf(" Rua: ");
    fgets(cliente.endereco.rua, 100, stdin);

    printf(" Númeroe: ");
    scanf("%d", &cliente.endereco.numero);
    getchar();

    printf(" Bairro: ");
    fgets(cliente.endereco.bairro, 50, stdin);

    printf(" Cidade: ");
    fgets(cliente.endereco.cidade, 50, stdin);

    printf(" Estado (2 letras): ");
    fgets(cliente.endereco.estado, 3, stdin);
    getchar(); // Limpar o buffer após a entrada de estado

    printf(" CEP: ");
    fgets(cliente.endereco.cep, 10, stdin);

    printf("Digite o telefone: ");
    fgets(cliente.telefone, 15, stdin);

    printf("Digite o email: ");
    fgets(cliente.email, 50, stdin);

    printf("Digite a porcentagem de lucro: ");
    scanf("%f", &cliente.porcentagemLucro);
    getchar(); // Limpar o buffer após o scanf

    return cliente;

}

int main() {
    Dados_Oficina oficina;

    oficina = cadastrar_dados_oficina();
   
    return 0;
}