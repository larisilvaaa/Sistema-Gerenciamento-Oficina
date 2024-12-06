#include <stdio.h>
#include "arquivos.h"
#include "estruturas.h" // Importa o cabeçalho com as definições das estruturas
#include "cadastro.h"   // Importa o cabeçalho com as funções de cadastro
#include <locale.h>    // Biblioteca para configurar a exibição de caracteres especiais no console

// Sub-rotina que realiza o cadastro das informações da oficina
Dados_Oficina cadastrar_dados_oficina(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Dados_Oficina cliente; // Variável para armazenar os dados do cliente
    
    // Coleta o nome do cliente
    printf("Digite o nome do cliente: ");
    setbuf(stdin, NULL); // Limpa o buffer para evitar problemas de entrada
    fgets(cliente.nome, 100, stdin); // lê todos os caracteres incluindo os espaços

    // Coleta o CPF ou CNPJ do cliente
    printf("Digite o CPF ou CNPJ (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%ld", &cliente.cpf_cnpj); // long int para armazenar até 19 dígitos  
    getchar(); // Limpa o buffer após a entrada de números

    // Coleta o endereço do cliente
    printf("Digite o endereço:\n");
    printf(" Rua: ");
    setbuf(stdin, NULL);
    fgets(cliente.endereco.rua, 100, stdin);

    printf(" Número: ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.endereco.numero); // armazena até 10 dígitos
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
    getchar(); // Limpa o buffer para evitar problemas

    // Coleta o CEP do cliente
    printf(" CEP (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%d", &cliente.endereco.cep);
    getchar();

    // Coleta o telefone do cliente
    printf("Digite o telefone +DDD (apenas números): ");
    setbuf(stdin, NULL);
    scanf("%ld", &cliente.telefone);
    getchar();

    // Coleta o e-mail do cliente
    printf("Digite o email: ");
    setbuf(stdin, NULL);
    fgets(cliente.email, 50, stdin);

    // Coleta a porcentagem de lucro
    printf("Digite a porcentagem de lucro: ");
    setbuf(stdin, NULL);
    scanf("%f", &cliente.porcentagemLucro);
    getchar();

    // Retorna os dados preenchidos
    return cliente;
}


//Sub-rotina que realiza o cadastro dos clientes
Cliente cadastrar_dados_cliente(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Cliente cliente;
    int codigo, posicao;

    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar
        
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

    inicia_vetor_tamanhos();
    if(vetor_tamanhos[1][1]==vetor_tamanhos[1][0]-1){
        vetor_cliente=(Cliente*)realoca_vetor(vetor_cliente,vetor_tamanhos[1][0]+10, sizeof(Cliente),1);
    }
    vetor_cliente[vetor_tamanhos[1][1]]=cliente;
    vetor_tamanhos[1][1]++;

    return cliente;

    } else if(op=='E' || op=='e'){// Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
        printf("Digite o código do cliente: ");
        scanf("%d", &codigo);

        posicao = procura_vetor_cliente(codigo);
        if(posicao==-1){
            printf("Cadastro não encontrado!\n");
            return;
        }
    
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
    vetor_cliente[posicao]=cliente;

    return cliente;

    } else if(op=='V' || op=='v'){
        //opção para visualização do arquivo
        printf("Digite o código do cliente: ");
        scanf("%d", &codigo);

        int posicao = procura_vetor_cliente(codigo);
        if(posicao==-1){
            printf("Cadastro não encontrado!\n");
        }else{
            //printar todos 
            vetor_cliente[posicao].codigo;
            vetor_cliente[posicao].cpf_cnpj;
            vetor_cliente[posicao].email;
            vetor_cliente[posicao].endereco;
            vetor_cliente[posicao].nome;
            vetor_cliente[posicao].telefone;

        }
    }
   

}

//Sub-rotina que realiza o cadastro dos veículos
Veiculo cadastrar_dados_veiculo(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Veiculo veiculo;
   
    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar
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

    } else if(op=='E' || op=='e'){ // Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
        
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
Peca cadastrar_dados_peca(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Peca peca;

    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar
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

    } else if(op=='E' || op=='e'){// Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
        
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
Fornecedor cadastrar_dados_fornecedor(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Fornecedor fornecedor;

    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar

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

    } else if(op=='E'|| op=='e'){// Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
    
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
Servico cadastrar_dados_servico(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Servico servico;

    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar

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

    } else  if(op=='E'|| op=='e'){// Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
        
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
Funcionario cadastrar_dados_funcionario(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Funcionario funcionario;

    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar

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

    } else if(op=='E'|| op=='e'){// Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários

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
