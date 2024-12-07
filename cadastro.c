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
    vetor_cliente[posicao]=cliente;

    return cliente;

    } else if(op=='V' || op=='v'){
        //opção para visualização do arquivo
        printf("Digite o código do cliente: ");
        scanf("%d", &codigo);

        int posicao = procura_vetor_cliente(codigo);// procura o cadastro do cliente para ser visualizado
        if(posicao==-1){
            printf("Cadastro não encontrado!\n");
            return;
        }else{
            printf("\n------------------Dados do cliente------------------\n\n");
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
  
        }
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

    printf("Digite o código do cliente: ");
    setbuf(stdin,NULL);
    scanf("%d", &veiculo.proprietario);
    getchar();

     inicia_vetor_tamanhos();
    if(vetor_tamanhos[2][1]==vetor_tamanhos[2][0]-1){
        vetor_veiculo=(Veiculo*)realoca_vetor(vetor_veiculo,vetor_tamanhos[2][0]+10, sizeof(Veiculo),1);
    }
    vetor_veiculo[vetor_tamanhos[2][1]]=veiculo;
    vetor_tamanhos[2][1]++;

    return veiculo;

    } else if(op=='E' || op=='e'){ // Verifica se o usuário quer editar
        // A lógica para editar repete o preenchimento, mas ajustando para apenas os dados necessários
    
    printf("Digite a placa do veículo: ");
    setbuf(stdin, NULL);
    fgets(veiculo.placa, 10, stdin);

    posicao = procura_vetor_veiculo(placa);// Verifica se o cadastro desse veículo existe
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

    return veiculo;

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
        printf("Digite a placa do veículo: ");
        setbuf(stdin, NULL);
        fgets(veiculo.placa, 10, stdin);

        int posicao = procura_vetor_veiculo(placa);// procura o cadastro do veículo para ser visualizado
        if(posicao==-1){
            printf("Cadastro não encontrado!\n");
            return;
        }else{
            printf("\n------------------Dados do veículo------------------\n\n");
            printf("Placa: %s.\n", vetor_veiculo[posicao].placa);
            printf("Modelo: %s.\n", vetor_veiculo[posicao].modelo);
            printf("Marca: %s.\n", vetor_veiculo[posicao].marca);
            printf("Ano: %d\n", vetor_veiculo[posicao].anoFabricacao);
            printf("Chassi: %s.\n", vetor_veiculo[posicao].chassi);
            printf("Código do proprietário: %d.\n", vetor_veiculo[posicao].proprietario);
  
        }
    }

}

//Sub-rotina que realiza o cadastro das peças
Peca cadastrar_dados_peca(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Peca peca;
    int codigo, posicao;

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

    inicia_vetor_tamanhos();
    if(vetor_tamanhos[3][1]==vetor_tamanhos[3][0]-1){
        vetor_peca=(Peca*)realoca_vetor(vetor_peca,vetor_tamanhos[3][0]+10, sizeof(Peca),1);
    }
    vetor_peca[vetor_tamanhos[3][1]]=peca;
    vetor_tamanhos[3][1]++;

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

    vetor_peca[posicao]=peca;

    return peca;

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
        printf("Digite o código da peça: ");
        scanf("%d", &codigo);

        int posicao = procura_vetor_peca(codigo);// procura o cadastro da peça para ser visualizado
        if(posicao==-1){
            printf("Cadastro não encontrado!\n");
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
  
        }
    }
    
}

//Sub-rotina que realiza o cadastro dos fornecedores
Fornecedor cadastrar_dados_fornecedor(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Fornecedor fornecedor;
    int codigo, posicao;

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

    inicia_vetor_tamanhos();
    if(vetor_tamanhos[4][1]==vetor_tamanhos[4][0]-1){
        vetor_fornecedor=(Fornecedor*)realoca_vetor(vetor_fornecedor,vetor_tamanhos[4][0]+10, sizeof(Fornecedor),1);
    }
    vetor_fornecedor[vetor_tamanhos[4][1]]=fornecedor;
    vetor_tamanhos[4][1]++;

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

    vetor_fornecedor[posicao]=fornecedor;

    return fornecedor;

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
        printf("Digite o código do fornecedor: ");
        scanf("%d", &codigo);

        int posicao = procura_vetor_fornecedor(codigo);// procura o cadastro do fornecedor para ser visualizado
        if(posicao==-1){
            printf("Cadastro não encontrado!\n");
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
            printf("Telefone: %d.\n", vetor_fornecedor[posicao].telefone);
            printf("Email: %d.\n", vetor_fornecedor[posicao].email);
  
        }
    }

}

//Sub-rotina que realiza o cadastro dos serviços
Servico cadastrar_dados_servico(char op){
    setlocale(LC_ALL, "pt_BR.UTF-8"); // Configura o programa para suportar caracteres especiais do português
    Servico servico;
    int codigo, posicao;

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

    inicia_vetor_tamanhos();
    if(vetor_tamanhos[5][1]==vetor_tamanhos[5][0]-1){
        vetor_servico=(Servico*)realoca_vetor(vetor_servico,vetor_tamanhos[5][0]+10, sizeof(Servico),1);
    }
    vetor_servico[vetor_tamanhos[5][1]]=servico;
    vetor_tamanhos[5][1]++;

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

    vetor_servico[posicao]=servico;

    return servico;

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
        printf("Digite o código do serviço: ");
        scanf("%d", &codigo);

        int posicao = procura_vetor_servico(codigo);// procura o cadastro do serviço para ser visualizado
        if(posicao==-1){
            printf("Cadastro não encontrado!\n");
            return;
        }else{
            printf("\n------------------Dados do serviço------------------\n\n");
            printf("Código: %d.\n", vetor_servico[posicao].codigo);
            printf("Descrição: %s.\n", vetor_servico[posicao].descricao);
            printf("Preço: %f.\n", vetor_servico[posicao].preco);
            printf("Comissão: %f.\n", vetor_servico[posicao].comissao);
            
        }
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

    inicia_vetor_tamanhos();
    if(vetor_tamanhos[6][1]==vetor_tamanhos[6][0]-1){
        vetor_funcionario=(Funcionario*)realoca_vetor(vetor_funcionario,vetor_tamanhos[6][0]+10, sizeof(Funcionario),1);
    }
    vetor_funcionario[vetor_tamanhos[6][1]]=funcionario;
    vetor_tamanhos[6][1]++;

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

    vetor_funcionario[posicao]=funcionario;

    return funcionario;

    } else if(op=='V' || op=='v'){
        //opção para a visualização do arquivo
        printf("Digite o CPF do funcionário: ");
        scanf("%ld", &cpf);

        int posicao = procura_vetor_funcionario(cpf);// procura o cadastro do funcionário para ser visualizado
        if(posicao==-1){
            printf("Cadastro não encontrado!\n");
            return;
        }else{
            printf("\n------------------Dados do funcionário------------------\n\n");
            printf("Nome: %s.\n", vetor_funcionario[posicao].nome);
            printf("CPF: %ld.\n", vetor_funcionario[posicao].cpf);
            printf("Cargo: %s.\n", vetor_funcionario[posicao].cargo);
            printf("Salário: %f.\n", vetor_funcionario[posicao].salario);
            
        }
    }

}
