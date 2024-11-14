#include <stdio.h>
#include "estruturas.h" //estruturas definidas 
#include "cadastro.h"   //função de cadastro 
#include <locale.h>    //biblioteca que permite o reconhecimento de caracteres especias 



//Sub-rotina que realiza o cadastro da oficina
Dados_Oficina cadastrar_dados_oficina(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); //define a locale para português do Brasil
    Dados_Oficina cliente;
   
    printf("Digite o nome do cliente: ");
    setbuf(stdin, NULL);//limpa buffer de teclado
    fgets(cliente.nome, 100, stdin);

    printf("Digite o CPF ou CNPJ (apenas números): ");
    setbuf(stdin,NULL);
    scanf("%ld", &cliente.cpf_cnpj);
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

    printf("Digite o telefone +DDD (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%ld", &cliente.telefone);
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

//Sub-rotina que realiza o cadastro dos clientes
Cliente cadastrar_dados_cliente(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); //define a locale para português do Brasil
    Cliente cliente;

    if(op=='C'|| op=='c'){// opção para cadastrar
        
    printf("Digite o código do cliente: ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.codigo);
    getchar();

    printf("Digite o nome do cliente: ");
    setbuf(stdin, NULL);
    fgets(cliente.nome, 100, stdin);

    printf("Digite o CPF ou CNPJ (apenas números): ");
    setbuf(stdin,NULL);
    scanf("%ld", &cliente.cpf_cnpj);
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

    printf("Digite o telefone +DDD (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%ld", &cliente.telefone);
    getchar(); 

    printf("Digite o email: ");
    setbuf(stdin, NULL);
    fgets(cliente.email, 50, stdin);

    } else if(op=='E' || op=='e'){// opção para editar
    
    printf("Digite o nome do cliente: ");
    setbuf(stdin, NULL);
    fgets(cliente.nome, 100, stdin);

    printf("Digite o CPF ou CNPJ (apenas números): ");
    setbuf(stdin,NULL);
    scanf("%ld", &cliente.cpf_cnpj);
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

    printf("Digite o telefone +DDD (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%ld", &cliente.telefone);
    getchar(); 

    printf("Digite o email: ");
    setbuf(stdin, NULL);
    fgets(cliente.email, 50, stdin);

    } else if(op=='V' || op=='v'){
        //opção para visualização do arquivo
    }
   
    return cliente;

}

//Sub-rotina que realiza o cadastro dos veículos
Veiculo cadastrar_dados_veiculo(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); //define a locale para português do Brasil
    Veiculo veiculo;
   
    if(op=='C'|| op=='c'){// opção para cadastrar
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

    } else if(op=='E' || op=='e'){ //opção para editar
        
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

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
    }

    return veiculo;
}

//Sub-rotina que realiza o cadastro das peças
Peca cadastrar_dados_peca(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); //define a locale para português do Brasil
    Peca peca;

    if(op=='C'|| op=='c'){// opção para cadastrar
    
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

    } else if(op=='E' || op=='e'){//opção para editar
        
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

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
    }
    
    return peca;
}

//Sub-rotina que realiza o cadastro dos fornecedores
Fornecedor cadastrar_dados_fornecedor(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); //define a locale para português do Brasil
    Fornecedor fornecedor;

    if(op=='C'|| op=='c'){// opção para cadastrar

    printf("Digite o código do fornecedor: ");
    setbuf(stdin, NULL);
    scanf("%d", &fornecedor.codigo);
    getchar();

    printf("Digite o nome fantasia: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.nomeFantasia, 100, stdin);

    printf("Digite a razão social: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.razaoSocial, 100, stdin);

    printf("Digite a inscrição Estadual: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.inscricaoEstadual, 20, stdin);

    printf("Digite o CNPJ (apenas números): ");
    setbuf(stdin,NULL);
    scanf("%ld", &fornecedor.cnpj);
    getchar();

    printf("Digite o endereço:\n");
    printf(" Rua: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.endereco.rua, 100, stdin);

    printf(" Número: ");
    setbuf(stdin, NULL);
    scanf("%d", &fornecedor.endereco.numero);
    getchar();

    printf(" Bairro: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.endereco.bairro, 50, stdin);

    printf(" Cidade: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.endereco.cidade, 50, stdin);

    printf(" Estado (2 letras): ");
    setbuf(stdin, NULL);
    fgets(fornecedor.endereco.estado, 3, stdin);
    getchar(); // Limpar o buffer após a entrada de estado

    printf(" CEP (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%d", &fornecedor.endereco.cep);
    getchar(); 

    printf("Digite o telefone +DDD (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%ld", &fornecedor.telefone);
    getchar(); 

    printf("Digite o email: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.email, 50, stdin);

    } else if(op=='E'|| op=='e'){// opção para editar
    
    printf("Digite o nome fantasia: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.nomeFantasia, 100, stdin);

    printf("Digite a razão social: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.razaoSocial, 100, stdin);

    printf("Digite a inscrição Estadual: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.inscricaoEstadual, 20, stdin);

    printf("Digite o CNPJ (apenas números): ");
    setbuf(stdin,NULL);
    scanf("%ld", &fornecedor.cnpj);
    getchar();

    printf("Digite o endereço:\n");
    printf(" Rua: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.endereco.rua, 100, stdin);

    printf(" Número: ");
    setbuf(stdin, NULL);
    scanf("%d", &fornecedor.endereco.numero);
    getchar();

    printf(" Bairro: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.endereco.bairro, 50, stdin);

    printf(" Cidade: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.endereco.cidade, 50, stdin);

    printf(" Estado (2 letras): ");
    setbuf(stdin, NULL);
    fgets(fornecedor.endereco.estado, 3, stdin);
    getchar(); // Limpar o buffer após a entrada de estado

    printf(" CEP (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%d", &fornecedor.endereco.cep);
    getchar(); 

    printf("Digite o telefone +DDD (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%ld", &fornecedor.telefone);
    getchar(); 

    printf("Digite o email: ");
    setbuf(stdin, NULL);
    fgets(fornecedor.email, 50, stdin);

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
    }

    return fornecedor;    

}

//Sub-rotina que realiza o cadastro dos serviços
Servico cadastrar_dados_servico(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); //define a locale para português do Brasil
    Servico servico;

    if(op=='C'|| op=='c'){// opção para cadastrar

    printf("Digite o código do serviço: ");
    setbuf(stdin, NULL);
    scanf("%d", &servico.codigo);
    getchar();

    printf("Digite a descrição do serviço: ");
    setbuf(stdin, NULL);
    fgets(servico.descricao, 100, stdin);

    printf("Digite o preço do serviço: ");
    setbuf(stdin, NULL);
    scanf("%f", &servico.preco);
    getchar();

    printf("Digite a comissão paga ao funcionário: ");
    setbuf(stdin, NULL);
    scanf("%f", &servico.comissao);
    getchar();

    } else  if(op=='E'|| op=='e'){// opção para editar
        
    printf("Digite a descrição do serviço: ");
    setbuf(stdin, NULL);
    fgets(servico.descricao, 100, stdin);

    printf("Digite o preço do serviço: ");
    setbuf(stdin, NULL);
    scanf("%f", &servico.preco);
    getchar();

    printf("Digite a comissão paga ao funcionário: ");
    setbuf(stdin, NULL);
    scanf("%f", &servico.comissao);
    getchar();

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
    }

    return servico; 
}

//Sub-rotina que realiza o cadastro dos funcionários
Funcionario cadastrar_dados_funcionario(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); //define a locale para português do Brasil
    Funcionario funcionario;

    if(op=='C'|| op=='c'){// opção para cadastrar

    printf("Digite o nome do funcionário: ");
    setbuf(stdin, NULL);
    fgets(funcionario.nome, 100, stdin);

    printf("Digite o CPF: ");
    setbuf(stdin,NULL);
    scanf("%ld", &funcionario.cpf);
    getchar();

    printf("Digite o cargo: ");
    setbuf(stdin, NULL);
    fgets(funcionario.cargo, 50, stdin);

    printf("Digite o salário do funcionário: ");
    setbuf(stdin,NULL);
    scanf("%f", &funcionario.salario);
    getchar();

    } else if(op=='E'|| op=='e'){// opção para editar

    printf("Digite o CPF: ");
    setbuf(stdin,NULL);
    scanf("%ld", &funcionario.cpf);
    getchar();

    printf("Digite o cargo: ");
    setbuf(stdin, NULL);
    fgets(funcionario.cargo, 50, stdin);

    printf("Digite o salário do funcionário: ");
    setbuf(stdin,NULL);
    scanf("%f", &funcionario.salario);
    getchar();

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
    }

    return funcionario;
}
