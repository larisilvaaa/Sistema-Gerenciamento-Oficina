#include <stdio.h>
#include "arquivos.h"   //Importa o cabeçalho com as funções de memória 
#include "estruturas.h" // Importa o cabeçalho com as definições das estruturas
#include "cadastro.h"   // Importa o cabeçalho com as funções de cadastro
#include <locale.h>    // Biblioteca para configurar a exibição de caracteres especiais no console

void remove_barra_n(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

// Sub-rotina que realiza o cadastro das informações da oficina
Dados_Oficina cadastrar_dados_oficina(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Dados_Oficina cliente; // Variável para armazenar os dados do cliente
    
    // Coleta o nome do cliente
    printf("Digite o nome da oficina: ");
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
    
    remove_barra_n(cliente.nome);
    remove_barra_n(cliente.email);
    remove_barra_n(cliente.endereco.estado);
    remove_barra_n(cliente.endereco.cidade);
    remove_barra_n(cliente.endereco.bairro);
    remove_barra_n(cliente.endereco.rua);

    // Retorna os dados preenchidos
    return cliente;
}


//Sub-rotina que realiza o cadastro dos clientes
Cliente cadastrar_dados_cliente(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    int codigo, posicao;
    Cliente cliente;

    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar
    
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

    remove_barra_n(cliente.nome);
    remove_barra_n(cliente.email);
    remove_barra_n(cliente.endereco.estado);
    remove_barra_n(cliente.endereco.cidade);
    remove_barra_n(cliente.endereco.bairro);
    remove_barra_n(cliente.endereco.rua);

    return cliente;

    } else if(op=='E' || op=='e'){// Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
    printf("Digite o código do cliente: ");
    scanf("%d", &codigo);

    posicao = procura_vetor_cliente(codigo);// Verifica se o cadastro desse cliente existe
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
    cliente.codigo=codigo;

    remove_barra_n(cliente.nome);
    remove_barra_n(cliente.email);
    remove_barra_n(cliente.endereco.estado);
    remove_barra_n(cliente.endereco.cidade);
    remove_barra_n(cliente.endereco.bairro);
    remove_barra_n(cliente.endereco.rua);

    vetor_cliente[posicao]=cliente;

    return cliente;

    }
   

}

//Sub-rotina que realiza o cadastro dos veículos
Veiculo cadastrar_dados_veiculo(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Veiculo veiculo;
    int posicao;
    char placa[10];
   
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

    printf("Digite o código do cliente dono do veículo: ");
    setbuf(stdin,NULL);
    scanf("%d", &veiculo.proprietario);
    getchar();

    remove_barra_n(veiculo.placa);
    remove_barra_n(veiculo.modelo);
    remove_barra_n(veiculo.marca);
    remove_barra_n(veiculo.chassi);

    return veiculo;

    } else if(op=='E' || op=='e'){ // Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
    
    printf("Digite a placa do veículo: ");
    setbuf(stdin, NULL);
    fgets(veiculo.placa, 10, stdin);
    remove_barra_n(veiculo.placa);

    posicao = procura_vetor_veiculo(veiculo.placa);// Verifica se o cadastro desse veículo existe
    if(posicao==-1){
        printf("Cadastro não encontrado!\n");
        return;
    }

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
    scanf("%d", &veiculo.proprietario);
    getchar();
    vetor_veiculo[posicao]=veiculo;

    remove_barra_n(veiculo.placa);
    remove_barra_n(veiculo.modelo);
    remove_barra_n(veiculo.marca);
    remove_barra_n(veiculo.chassi);

    return veiculo;

    }

}

//Sub-rotina que realiza o cadastro das peças
Peca cadastrar_dados_peca(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Peca peca;
    int codigo, posicao;

    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar
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

    remove_barra_n(peca.descricao);
    remove_barra_n(peca.fabricante);
    remove_barra_n(peca.fornecedor);

    return peca;

    } else if(op=='E' || op=='e'){// Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários

    printf("Digite o código da peça: ");
    scanf("%d", &codigo);
    
    posicao = procura_vetor_peca(codigo);// Verifica se o cadastro dessa peça existe
    if(posicao==-1){
        printf("Cadastro não encontrado!\n");
        return;
    }
        
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
    peca.codigo=codigo;

    remove_barra_n(peca.descricao);
    remove_barra_n(peca.fabricante);
    remove_barra_n(peca.fornecedor);

    vetor_peca[posicao]=peca;

    return peca;

    }
    
}

//Sub-rotina que realiza o cadastro dos fornecedores
Fornecedor cadastrar_dados_fornecedor(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Fornecedor fornecedor;
    int codigo, posicao;

    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar
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

    remove_barra_n(fornecedor.nomeFantasia);
    remove_barra_n(fornecedor.razaoSocial);
    remove_barra_n(fornecedor.inscricaoEstadual);
    remove_barra_n(fornecedor.email);
    remove_barra_n(fornecedor.endereco.estado);
    remove_barra_n(fornecedor.endereco.cidade);
    remove_barra_n(fornecedor.endereco.bairro);
    remove_barra_n(fornecedor.endereco.rua);

    return fornecedor;

    } else if(op=='E'|| op=='e'){// Verifica se o usuário quer editar
     // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
    printf("Digite o código do fornecedor: ");
    scanf("%d", &codigo);
    
    posicao = procura_vetor_fornecedor(codigo);// Verifica se o cadastro desse fornecedor existe
    if(posicao==-1){
        printf("Cadastro não encontrado!\n");
        return;
    }
    
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
    fornecedor.codigo=codigo;

    remove_barra_n(fornecedor.nomeFantasia);
    remove_barra_n(fornecedor.razaoSocial);
    remove_barra_n(fornecedor.inscricaoEstadual);
    remove_barra_n(fornecedor.email);
    remove_barra_n(fornecedor.endereco.estado);
    remove_barra_n(fornecedor.endereco.cidade);
    remove_barra_n(fornecedor.endereco.bairro);
    remove_barra_n(fornecedor.endereco.rua);

    vetor_fornecedor[posicao]=fornecedor;

    return fornecedor;

    }

}

//Sub-rotina que realiza o cadastro dos serviços
Servico cadastrar_dados_servico(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Servico servico;
    int codigo, posicao;

    if(op=='C'|| op=='c'){// Verifica se o usuário quer cadastrar
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

    remove_barra_n(servico.descricao);    

    return servico;

    } else  if(op=='E'|| op=='e'){// Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
    printf("Digite o código do serviço: ");
    scanf("%d", &codigo);
    
    posicao = procura_vetor_fornecedor(codigo);// Verifica se o cadastro desse serviço existe
    if(posicao==-1){
        printf("Cadastro não encontrado!\n");
        return;
    }
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

    servico.codigo=codigo;
    remove_barra_n(servico.descricao);

    vetor_servico[posicao]=servico;

    return servico;

    }

}

//Sub-rotina que realiza o cadastro dos funcionários
Funcionario cadastrar_dados_funcionario(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Funcionario funcionario;
    long int cpf;
    int posicao;

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

    remove_barra_n(funcionario.nome);
    remove_barra_n(funcionario.cargo);

    return funcionario;

    } else if(op=='E'|| op=='e'){// Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
    printf("Digite o CPF do funcionário: ");
    scanf("%ld", &cpf);
    
    posicao = procura_vetor_funcionario(cpf);// Verifica se o cadastro desse funcionário existe
    if(posicao==-1){
        printf("Cadastro não encontrado!\n");
        return;
    }

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

    remove_barra_n(funcionario.nome);
    remove_barra_n(funcionario.cargo);

    vetor_funcionario[posicao]=funcionario;

    return funcionario;

    }
}

void visualizar_dados(int escolha, int tipo, int indice_inicial, int indice_final){
    int codigo, posicao;
    long int codigo_ld;
    char texto[1024];
    switch(escolha){
        case 1:
            printf("\n\n------------------Dados da Oficina-----------------\n\n");
            printf("Nome: %s.\n", oficina.nome);
            printf("CPF ou CNPJ: %ld.\n", oficina.cpf_cnpj);
            printf("Endereço:\n");
            printf("    Rua: %s.\n", oficina.endereco.rua);
            printf("    Número: %d.\n", oficina.endereco.numero);
            printf("    Bairro: %s.\n", oficina.endereco.bairro);
            printf("    Cidade: %s.\n", oficina.endereco.cidade);
            printf("    Estado: %s.\n", oficina.endereco.estado);
            printf("    CEP: %d.\n", oficina.endereco.cep);
            printf("Telefone: %ld.\n", oficina.telefone);
            printf("Email: %s.\n", oficina.email);
            printf("Porcentagem Lucro: %.2f%%.\n", oficina.porcentagemLucro);
            printf("\n---------------------------------------------------\n\n");
            break;
        case 2:
            if(tipo==1){
                printf("Digite o código do cliente: ");
                scanf("%d", &codigo);

                posicao = procura_vetor_cliente(codigo);// procura o cadastro do cliente para ser visualizado
                if(posicao==-1){
                    printf("\nCadastro não encontrado!\n");
                    return;
                }else{
                    printf("\n\n------------------Dados do cliente------------------\n\n");
                    printf("Código: %d.\n", vetor_cliente[posicao].codigo);
                    printf("Nome: %s.\n", vetor_cliente[posicao].nome);
                    printf("CPF ou CNPJ: %ld.\n", vetor_cliente[posicao].cpf_cnpj);
                    printf("Endereço:\n");
                    printf("    Rua: %s.\n", vetor_cliente[posicao].endereco.rua);
                    printf("    Número: %d.\n", vetor_cliente[posicao].endereco.numero);
                    printf("    Bairro: %s.\n", vetor_cliente[posicao].endereco.bairro);
                    printf("    Cidade: %s.\n", vetor_cliente[posicao].endereco.cidade);
                    printf("    Estado: %s.\n", vetor_cliente[posicao].endereco.estado);
                    printf("    CEP: %d.\n", vetor_cliente[posicao].endereco.cep);
                    printf("Telefone: %ld.\n", vetor_cliente[posicao].telefone);
                    printf("Email: %s.\n", vetor_cliente[posicao].email);
                    printf("\n----------------------------------------------------\n\n");
  
                }
            }else{
                if(indice_inicial<0){
                    indice_inicial=0;
                }
                if(indice_final>vetor_tamanhos[1][1]-1){
                    indice_final=vetor_tamanhos[1][1]-1;
                }
                printf("\n\n------------------Dados do cliente------------------\n\n");
                for(int i=indice_inicial;i<indice_final+1;i++){
                    printf("Código: %d.\n", vetor_cliente[i].codigo);
                    printf("Nome: %s.\n", vetor_cliente[i].nome);
                    printf("CPF ou CNPJ: %ld.\n", vetor_cliente[i].cpf_cnpj);
                    printf("Endereço:\n");
                    printf("    Rua: %s.\n", vetor_cliente[i].endereco.rua);
                    printf("    Número: %d.\n", vetor_cliente[i].endereco.numero);
                    printf("    Bairro: %s.\n", vetor_cliente[i].endereco.bairro);
                    printf("    Cidade: %s.\n", vetor_cliente[i].endereco.cidade);
                    printf("    Estado: %s.\n", vetor_cliente[i].endereco.estado);
                    printf("    CEP: %d.\n", vetor_cliente[i].endereco.cep);
                    printf("Telefone: %ld.\n", vetor_cliente[i].telefone);
                    printf("Email: %s.\n", vetor_cliente[i].email);
                    printf("\n----------------------------------------------------\n\n");
                }
            }
            break;
        case 3:
            if(tipo==1){
                printf("\nDigite a placa do carro: ");
                setbuf(stdin, NULL);
                fgets(texto, 1024, stdin);
                remove_barra_n(texto);
                posicao=procura_vetor_veiculo(texto);
                if(posicao==-1){
                    printf("\nCadastro não encontrado!");
                }else{
                    printf("\n\n------------------Dados do veículo------------------\n\n");
                    printf("Placa: %s.\n", vetor_veiculo[posicao].placa);
                    printf("Modelo: %s.\n", vetor_veiculo[posicao].modelo);
                    printf("Marca: %s.\n", vetor_veiculo[posicao].marca);
                    printf("Ano: %d\n", vetor_veiculo[posicao].anoFabricacao);
                    printf("Chassi: %s.\n", vetor_veiculo[posicao].chassi);
                    printf("Código do proprietário: %d.\n", vetor_veiculo[posicao].proprietario);
                }
            }else{
                if(indice_inicial<0){
                    indice_inicial=0;
                }
                if(indice_final>vetor_tamanhos[2][1]-1){
                    indice_final=vetor_tamanhos[2][1]-1;
                }
                printf("\n\n------------------Dados do veículo------------------\n\n");
                for(int i=indice_inicial;i<indice_final+1;i++){
                    printf("Placa: %s.\n", vetor_veiculo[i].placa);
                    printf("Modelo: %s.\n", vetor_veiculo[i].modelo);
                    printf("Marca: %s.\n", vetor_veiculo[i].marca);
                    printf("Ano: %d\n", vetor_veiculo[i].anoFabricacao);
                    printf("Chassi: %s.\n", vetor_veiculo[i].chassi);
                    printf("Código do proprietário: %d.\n\n", vetor_veiculo[i].proprietario);
                }
            }
            break;
        case 4:
            if(tipo==1){
                printf("Digite o código da peça: ");
                scanf("%d", &codigo);

                posicao = procura_vetor_peca(codigo);// procura o cadastro do cliente para ser visualizado
                if(posicao==-1){
                    printf("\nCadastro não encontrado!\n");
                    return;
                }else{
                    printf("\n------------------Dados da peça------------------\n\n");
                    printf("Código: %d.\n", vetor_peca[posicao].codigo);
                    printf("Descrição: %s.\n", vetor_peca[posicao].descricao);
                    printf("Fabricante: %s.\n", vetor_peca[posicao].fabricante);
                    printf("Fornecedor: %s\n", vetor_peca[posicao].fornecedor);
                    printf("Preço de custo: %f.\n", vetor_peca[posicao].precoCusto);
                    printf("Preço de venda: %f.\n", vetor_peca[posicao].precoVenda);
                    printf("Quantidade de estoque: %d.\n", vetor_peca[posicao].quantidadeEstoque);
                    printf("Estoque mínimo: %d.\n", vetor_peca[posicao].estoqueMinimo);
                    printf("\n--------------------------------------------------\n\n");
  
                }
            }else{
                if(indice_inicial<0){
                    indice_inicial=0;
                }
                if(indice_final>vetor_tamanhos[3][1]-1){
                    indice_final=vetor_tamanhos[3][1]-1;
                }
                printf("\n\n------------------Dados da peça------------------\n\n");
                for(int i=indice_inicial;i<indice_final+1;i++){
                    printf("Código: %d.\n", vetor_peca[i].codigo);
                    printf("Descrição: %s.\n", vetor_peca[i].descricao);
                    printf("Fabricante: %s.\n", vetor_peca[i].fabricante);
                    printf("Fornecedor: %s\n", vetor_peca[i].fornecedor);
                    printf("Preço de custo: %f.\n", vetor_peca[i].precoCusto);
                    printf("Preço de venda: %f.\n", vetor_peca[i].precoVenda);
                    printf("Quantidade de estoque: %d.\n", vetor_peca[i].quantidadeEstoque);
                    printf("Estoque mínimo: %d.\n", vetor_peca[i].estoqueMinimo);
                    printf("\n--------------------------------------------------\n\n");
                }
            }
            break;
        case 5:
            if(tipo==1){
                printf("Digite o código do fornecedor: ");
                scanf("%d", &codigo);

                posicao = procura_vetor_fornecedor(codigo);// procura o cadastro do cliente para ser visualizado
                if(posicao==-1){
                    printf("\nCadastro não encontrado!\n");
                    return;
                }else{
                    printf("\n------------------Dados do fornecedor------------------\n\n");
                    printf("Código: %d.\n", vetor_fornecedor[posicao].codigo);
                    printf("Nome fantasia: %s.\n", vetor_fornecedor[posicao].nomeFantasia);
                    printf("Razão social: %s.\n", vetor_fornecedor[posicao].razaoSocial);
                    printf("Inscrição estadual: %s\n", vetor_fornecedor[posicao].inscricaoEstadual);
                    printf("CNPJ: %ld.\n", vetor_fornecedor[posicao].cnpj);
                    printf("Endereço:\n");
                    printf("    Rua: %s.\n", vetor_fornecedor[posicao].endereco.rua);
                    printf("    Número: %d.\n", vetor_fornecedor[posicao].endereco.numero);
                    printf("    Bairro: %s.\n", vetor_fornecedor[posicao].endereco.bairro);
                    printf("    Cidade: %s.\n", vetor_fornecedor[posicao].endereco.cidade);
                    printf("    Estado: %s.\n", vetor_fornecedor[posicao].endereco.estado);
                    printf("    CEP: %d.\n", vetor_fornecedor[posicao].endereco.cep);
                    printf("Telefone: %ld.\n", vetor_fornecedor[posicao].telefone);
                    printf("Email: %s.\n", vetor_fornecedor[posicao].email);
                }
            }else{
                if(indice_inicial<0){
                    indice_inicial=0;
                }
                if(indice_final>vetor_tamanhos[4][1]-1){
                    indice_final=vetor_tamanhos[4][1]-1;
                }
                printf("\n\n------------------Dados do fornecedor------------------\n\n");
                for(int i=indice_inicial;i<indice_final+1;i++){
                    printf("Código: %d.\n", vetor_fornecedor[i].codigo);
                    printf("Nome fantasia: %s.\n", vetor_fornecedor[i].nomeFantasia);
                    printf("Razão social: %s.\n", vetor_fornecedor[i].razaoSocial);
                    printf("Inscrição estadual: %s\n", vetor_fornecedor[i].inscricaoEstadual);
                    printf("CNPJ: %ld.\n", vetor_fornecedor[i].cnpj);
                    printf("Endereço:\n");
                    printf("    Rua: %s.\n", vetor_fornecedor[i].endereco.rua);
                    printf("    Número: %d.\n", vetor_fornecedor[i].endereco.numero);
                    printf("    Bairro: %s.\n", vetor_fornecedor[i].endereco.bairro);
                    printf("    Cidade: %s.\n", vetor_fornecedor[i].endereco.cidade);
                    printf("    Estado: %s.\n", vetor_fornecedor[i].endereco.estado);
                    printf("    CEP: %d.\n", vetor_fornecedor[i].endereco.cep);
                    printf("Telefone: %ld.\n", vetor_fornecedor[i].telefone);
                    printf("Email: %s.\n\n", vetor_fornecedor[i].email);
                }
            }
            break;
        case 6:
            if(tipo==1){
                printf("Digite o código do serviço: ");
                scanf("%d", &codigo);

                posicao = procura_vetor_servico(codigo);// procura o cadastro do cliente para ser visualizado
                if(posicao==-1){
                    printf("\nCadastro não encontrado!\n");
                    return;
                }else{
                    printf("\n------------------Dados do serviço------------------\n\n");
                    printf("Código: %d.\n", vetor_servico[posicao].codigo);
                    printf("Descrição: %s.\n", vetor_servico[posicao].descricao);
                    printf("Preço: %f.\n", vetor_servico[posicao].preco);
                    printf("Comissão: %f.\n\n", vetor_servico[posicao].comissao);
                }
            }else{
                if(indice_inicial<0){
                    indice_inicial=0;
                }
                if(indice_final>vetor_tamanhos[5][1]-1){
                    indice_final=vetor_tamanhos[5][1]-1;
                }
                printf("\n------------------Dados do serviço------------------\n\n");
                for(int i=indice_inicial;i<indice_final+1;i++){
                    printf("\n------------------Dados do serviço------------------\n\n");
                    printf("Código: %d.\n", vetor_servico[i].codigo);
                    printf("Descrição: %s.\n", vetor_servico[i].descricao);
                    printf("Preço: %f.\n", vetor_servico[i].preco);
                    printf("Comissão: %f.\n\n", vetor_servico[i].comissao);
                }
            }
            break;
        case 7:
            if(tipo==1){
                printf("Digite o cpf do funcionario: ");
                scanf("%ld", &codigo_ld);

                posicao = procura_vetor_funcionario(codigo_ld);// procura o cadastro do cliente para ser visualizado
                if(posicao==-1){
                    printf("\nCadastro não encontrado!\n");
                    return;
                }else{
                    printf("\n------------------Dados do funcionário------------------\n\n");
                    printf("Nome: %s.\n", vetor_funcionario[posicao].nome);
                    printf("CPF: %ld.\n", vetor_funcionario[posicao].cpf);
                    printf("Cargo: %s.\n", vetor_funcionario[posicao].cargo);
                    printf("Salário: %f.\n\n", vetor_funcionario[posicao].salario);
                }
            }else{
                if(indice_inicial<0){
                    indice_inicial=0;
                }
                if(indice_final>vetor_tamanhos[6][1]-1){
                    indice_final=vetor_tamanhos[6][1]-1;
                }
                printf("\n\n------------------Dados do funcionario------------------\n\n");
                for(int i=indice_inicial;i<indice_final+1;i++){
                    printf("Nome: %s.\n", vetor_funcionario[i].nome);
                    printf("CPF: %ld.\n", vetor_funcionario[i].cpf);
                    printf("Cargo: %s.\n", vetor_funcionario[i].cargo);
                    printf("Salário: %f.\n\n", vetor_funcionario[i].salario);
                }
            }
            break;
    }
    return;
}
