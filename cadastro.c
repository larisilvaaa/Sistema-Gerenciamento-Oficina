#include <stdio.h>
#include "cadastro.h"

Dados_Oficina cadastrar_dados_oficina(){
    Dados_Oficina cliente;
   
    printf("Digite o nome do cliente: ");
    setbuf(stdin, NULL);
    fgets(cliente.nome, 100, stdin);

    printf("Digite o CPF ou CNPJ (apenas números): ");
    setbuf(stdin,NULL);
    scanf("%d", &cliente.cpf_cnpj);
    getchar();

    printf("Digite o endereço:\n");
    printf(" Rua: ");
    setbuf(stdin, NULL);
    fgets(cliente.endereco.rua, 100, stdin);

    printf(" Número: ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.endereco.numero);
    getchar();

    printf(" Bairro: ");
    setbuf(stdin, NULL);
    fgets(cliente.endereco.bairro, 50, stdin);

    printf(" Cidade: ");
    setbuf(stdin, NULL);
    fgets(cliente.endereco.cidade, 50, stdin);

    printf(" Estado (2 letras): ");
    setbuf(stdin, NULL);
    fgets(cliente.endereco.estado, 3, stdin);
    getchar(); // Limpar o buffer após a entrada de estado

    printf(" CEP (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.endereco.cep);
    getchar(); 

    printf("Digite o telefone (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.telefone);
    getchar(); 

    printf("Digite o email: ");
    setbuf(stdin, NULL);
    fgets(cliente.email, 50, stdin);

    printf("Digite a porcentagem de lucro: ");
    setbuf(stdin, NULL);
    scanf("%f", &cliente.porcentagemLucro);
    getchar(); // Limpar o buffer após o scanf

    return cliente;

}

Cliente cadastrar_dados_cliente(){
    Cliente cliente;
   
    printf("Digite o código do cliente: ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.codigo);
    getchar();

    printf("Digite o nome do cliente: ");
    setbuf(stdin, NULL);
    fgets(cliente.nome, 100, stdin);

    printf("Digite o CPF ou CNPJ (apenas números): ");
    setbuf(stdin,NULL);
    scanf("%d", &cliente.cpf_cnpj);
    getchar();

    printf("Digite o endereço:\n");
    printf(" Rua: ");
    setbuf(stdin, NULL);
    fgets(cliente.endereco.rua, 100, stdin);

    printf(" Número: ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.endereco.numero);
    getchar();

    printf(" Bairro: ");
    setbuf(stdin, NULL);
    fgets(cliente.endereco.bairro, 50, stdin);

    printf(" Cidade: ");
    setbuf(stdin, NULL);
    fgets(cliente.endereco.cidade, 50, stdin);

    printf(" Estado (2 letras): ");
    setbuf(stdin, NULL);
    fgets(cliente.endereco.estado, 3, stdin);
    getchar(); // Limpar o buffer após a entrada de estado

    printf(" CEP (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.endereco.cep);
    getchar(); 

    printf("Digite o telefone (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.telefone);
    getchar(); 

    printf("Digite o email: ");
    setbuf(stdin, NULL);
    fgets(cliente.email, 50, stdin);

    return cliente;

}

Veiculo cadastrar_dados_veiculo(){
    Veiculo veiculo;
   
    printf("Digite a placa do veículo: ");
    setbuf(stdin, NULL);
    fgets(veiculo.placa, 10, stdin);

    printf("Digite o modelo do veículo: ");
    setbuf(stdin, NULL);
    fgets(veiculo.modelo, 30, stdin);

     printf("Digite a marca do veículo: \n");
    setbuf(stdin, NULL);
    fgets(veiculo.marca, 30, stdin);

    printf("Digite o ano de fabricação do veículo: ");
    setbuf(stdin, NULL);
    scanf("%d", &veiculo.anoFabricacao);
    getchar();

    printf("Digite o chassi do veículo: ");
    setbuf(stdin, NULL);
    fgets(veiculo.chassi, 20, stdin);

    printf("Digite o código do cliente: ");
    setbuf(stdin,NULL);
    scanf("%d", &veiculo.proprietario.codigo);
    getchar();

    return veiculo;
}

Peca cadastrar_dados_peca(){
    Peca peca;

    printf("Digite o código da peça: ");
    setbuf(stdin,NULL);
    scanf("%d", &peca.codigo);
    getchar();

    printf("Descrição da peça: ");
    setbuf(stdin, NULL);
    fgets(peca.descricao, 100, stdin);

    printf("Digite o fabricante: ");
    setbuf(stdin, NULL);
    fgets(peca.fabricante, 50, stdin);

    printf("Digite o fornecedor: ");
    setbuf(stdin, NULL);
    fgets(peca.fornecedor, 50, stdin);

    printf("Digite o preço de custo: ");
    setbuf(stdin, NULL);
    scanf("%f", &peca.precoCusto);
    getchar();

    printf("Digite o preço de venda: ");
    setbuf(stdin, NULL);
    scanf("%f", &peca.precoVenda);
    getchar();
    
    printf("Digite a quantidade de estoque: ");
    setbuf(stdin,NULL);
    scanf("%d", &peca.quantidadeEstoque);
    getchar();

    printf("Digite o estoque minímo: ");
    setbuf(stdin,NULL);
    scanf("%d", &peca.estoqueMinimo);
    getchar();

    return peca;
}

int main() {
    Dados_Oficina oficina;
   
    oficina = cadastrar_dados_oficina();

    printf("Nome: %s.\n",oficina.nome);

   
    return 0;
}