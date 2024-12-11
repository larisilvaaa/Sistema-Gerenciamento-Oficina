#include "estruturas.h"
#include "cadastro.h"

/*Sub-rotina que apresenta o menu de opções do cadastro*/
void menu_cadastro (){
    while(1){
        char cadastro;
        int op,vizualizacao,codigo;
        int indicie_inicial,indicie_final;
        printf("\nDigite a letra correspondente a opção desejada:\n");
        printf("C- Cadastrar\n");
        printf("E- Editar\n");
        printf("V- Vizualizar\n");
        printf("S- Sair\n");
        printf("==> ");
        scanf(" %c",&cadastro);

        if(cadastro == 'C' || cadastro == 'c'){
            printf("------------------------\n");
            printf("|     Menu de opções    |\n");
            printf("------------------------\n");
            printf("Selecione o tipo de cadastro a ser realizado:");
            printf("\n1- Oficina");
            printf("\n2- Clientes");
            printf("\n3- Veículos");
            printf("\n4- Peças");
            printf("\n5- Fornecedores");
            printf("\n6- Serviços");
            printf("\n7- Funcionários\n");
            printf("==> ");
            scanf("%d",&op);

            switch(op){

                case 1:{
                    /*função de cadastro de dados da oficina*/
                    Dados_Oficina oficina; 

                    oficina = cadastrar_dados_oficina();

                    break;
                }
                case 2:{
                    /*função de cadastro de dados do cliente*/
                    break;
                }
                case 3:{
                    /*função de cadastro de dados de veículos*/
                    break;
                }
                case 4:{
                    /*função de cadastro de dados de peças*/
                    break;
                }
                case 5:{
                    /*função de cadastro de dados do fornecedor*/
                    break;
                }
                case 6:{
                    /*função de cadastro de dados de serviços*/
                    break;
                }
                case 7:{
                    /*função de cadastro de dados do funcionário*/
                    break;
                }

            }
        }

        if(cadastro == 'E' || cadastro == 'e'){
            printf("------------------------\n");
            printf("|     Menu de opções    |\n");
            printf("------------------------\n");
            printf("Selecione qual cadastro você gostaria de editar:");
            printf("\n1- Oficina");
            printf("\n2- Clientes");
            printf("\n3- Veículos");
            printf("\n4- Peças");
            printf("\n5- Fornecedores");
            printf("\n6- Serviços");
            printf("\n7- Funcionários\n");
            printf("==> ");
            scanf("%d",&op);

            switch(op){

                case 1:{
                    /*função de edição de dados da oficina*/
                    Dados_Oficina oficina; 

                    oficina = cadastrar_dados_oficina();
                    break;
                }
                case 2:{
                    /*função de edição de dados do cliente*/
                    break;
                }
                case 3:{
                    /*função de edição de dados de veículos*/
                    break;
                }
                case 4:{
                    /*função de edição de dados de peças*/
                    break;
                }
                case 5:{
                    /*função de edição de dados do fornecedor*/
                    break;
                }
                case 6:{
                    /*função de edição de dados de serviços*/
                    break;
                }
                case 7:{
                    /*função de ediçao de dados do funcionário*/
                    break;
                }

            }
        }

        if(cadastro == 'V' || cadastro == 'v'){
            printf("------------------------\n");
            printf("|     Menu de opções    |\n");
            printf("------------------------\n");
            printf("Selecione qual cadastro você gostaria de vizualizar:");
            printf("\n1- Oficina");
            printf("\n2- Clientes");
            printf("\n3- Veículos");
            printf("\n4- Peças");
            printf("\n5- Fornecedores");
            printf("\n6- Serviços");
            printf("\n7- Funcionários\n");
            printf("==> ");
            scanf("%d",&op);
            switch(op){

                case 1:{
                    printf("------------------------\n");
                    printf("|     Menu de opções    |\n");
                    printf("|    de vizualização    |");
                    printf("------------------------\n");
                    printf("Selecione o que você gostaria de vizualizar:");
                    printf("\n1- Vizualizar um cliente pelo código");
                    printf("\n2- Vizualizar um conjunto de clientes");
                    printf("==> ");
                    scanf("%d",&vizualizacao);
                    if(vizualizacao==1){
                        printf("\nDigite o código do cliente que você gostaria de vizualizar: ");
                        printf("==> ");
                        scanf("%d",&codigo)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um cliente*/
                        /*função que mostra os dados ao usuário*/
                    }
                    if(vizualizacao==2){
                        printf("\nDigite o indicie do primeiro cadastro");
                        printf("==> ");
                        scanf("%d",&indicie_inicial);
                        printf("\nDigite o indie do último cadastro");
                        printf("==> ");
                        scanf("%d",&indice_final)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um grupo de clientes*/
                        /*função que mostra os dados ao usuário*/
                    }
                    break;
                }
                case 2:{
                    printf("------------------------\n");
                    printf("|     Menu de opções    |\n");
                    printf("|    de vizualização    |");
                    printf("------------------------\n");
                    printf("Selecione o que você gostaria de vizualizar:");
                    printf("\n1- Vizualizar um cliente pelo código");
                    printf("\n2- Vizualizar um conjunto de clientes");
                    printf("==> ");
                    scanf("%d",&vizualizacao);
                    if(vizualizacao==1){
                        printf("\nDigite o código do cliente que você gostaria de vizualizar: ");
                        printf("==> ");
                        scanf("%d",&codigo)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um cliente*/
                        /*função que mostra os dados ao usuário*/
                    }
                    if(vizualizacao==2){
                        printf("\nDigite o indicie do primeiro cadastro");
                        printf("==> ");
                        scanf("%d",&indicie_inicial);
                        printf("\nDigite o indie do último cadastro");
                        printf("==> ");
                        scanf("%d",&indice_final)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um grupo de clientes*/
                        /*função que mostra os dados ao usuário*/
                    }
                    break;
                }
                case 3:{
                    printf("------------------------\n");
                    printf("|     Menu de opções    |\n");
                    printf("|    de vizualização    |");
                    printf("------------------------\n");
                    printf("Selecione o que você gostaria de vizualizar:");
                    printf("\n1- Vizualizar um veículo pela placa");
                    printf("\n2- Vizualizar um conjunto de veículos");
                    printf("==> ");
                    scanf("%d",&vizualizacao);
                    if(vizualizacao==1){
                        printf("\nDigite a placa do veículo que você gostaria de vizualizar: ");
                        printf("==> ");
                        scanf("%d",&codigo)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um cliente*/
                        /*função que mostra os dados ao usuário*/
                    }
                    if(vizualizacao==2){
                        printf("\nDigite o indicie do primeiro veículo");
                        printf("==> ");
                        scanf("%d",&indicie_inicial);
                        printf("\nDigite o indie do último veículo");
                        printf("==> ");
                        scanf("%d",&indice_final)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um grupo de clientes*/
                        /*função que mostra os dados ao usuário*/
                    }
                    break;
                }
                case 4:{
                    printf("------------------------\n");
                    printf("|     Menu de opções    |\n");
                    printf("|    de vizualização    |");
                    printf("------------------------\n");
                    printf("Selecione o que você gostaria de vizualizar:");
                    printf("\n1- Vizualizar uma peça pelo código");
                    printf("\n2- Vizualizar um conjunto de peças");
                    printf("==> ");
                    scanf("%d",&vizualizacao);
                    if(vizualizacao==1){
                        printf("\nDigite o código da peça que você gostaria de vizualizar: ");
                        printf("==> ");
                        scanf("%d",&codigo)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um cliente*/
                        /*função que mostra os dados ao usuário*/
                    }
                    if(vizualizacao==2){
                        printf("\nDigite o indicie da primeira peça ");
                        printf("==> ");
                        scanf("%d",&indicie_inicial);
                        printf("\nDigite o indie da última peça");
                        printf("==> ");
                        scanf("%d",&indice_final)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um grupo de clientes*/
                        /*função que mostra os dados ao usuário*/
                    }
                    break;
                }
                case 5:{
                    printf("------------------------\n");
                    printf("|     Menu de opções    |\n");
                    printf("|    de vizualização    |");
                    printf("------------------------\n");
                    printf("Selecione o que você gostaria de vizualizar:");
                    printf("\n1- Vizualizar um fornecedor pelo código");
                    printf("\n2- Vizualizar um conjunto de fornecedores");
                    printf("==> ");
                    scanf("%d",&vizualizacao);
                    if(vizualizacao==1){
                        printf("\nDigite o código do fornecedor que você gostaria de vizualizar: ");
                        printf("==> ");
                        scanf("%d",&codigo)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um cliente*/
                        /*função que mostra os dados ao usuário*/
                    }
                    if(vizualizacao==2){
                        printf("\nDigite o indicie do primeiro fornecedor");
                        printf("==> ");
                        scanf("%d",&indicie_inicial);
                        printf("\nDigite o indie do último fornecedor");
                        printf("==> ");
                        scanf("%d",&indice_final)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um grupo de clientes*/
                        /*função que mostra os dados ao usuário*/
                    }
                    break;
                }
                case 6:{
                    printf("------------------------\n");
                    printf("|     Menu de opções    |\n");
                    printf("|    de vizualização    |");
                    printf("------------------------\n");
                    printf("Selecione o que você gostaria de vizualizar:");
                    printf("\n1- Vizualizar um serviço pelo código");
                    printf("\n2- Vizualizar um conjunto de serviços oferecidos pela oficina");
                    printf("==> ");
                    scanf("%d",&vizualizacao);
                    if(vizualizacao==1){
                        printf("\nDigite o código do serviço que você gostaria de vizualizar: ");
                        printf("==> ");
                        scanf("%d",&codigo)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um cliente*/
                        /*função que mostra os dados ao usuário*/
                    }
                    if(vizualizacao==2){
                        printf("\nDigite o indicie do primeiro serviço");
                        printf("==> ");
                        scanf("%d",&indicie_inicial);
                        printf("\nDigite o indie do último serviço");
                        printf("==> ");
                        scanf("%d",&indice_final)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um grupo de clientes*/
                        /*função que mostra os dados ao usuário*/
                    }
                    break;
                }
                case 7:{
                    printf("------------------------\n");
                    printf("|     Menu de opções    |\n");
                    printf("|    de vizualização    |");
                    printf("------------------------\n");
                    printf("Selecione o que você gostaria de vizualizar:");
                    printf("\n1- Vizualizar um funcionário pelo CPF");
                    printf("\n2- Vizualizar um conjunto de funcionários");
                    printf("==> ");
                    scanf("%d",&vizualizacao);
                    if(vizualizacao==1){
                        printf("\nDigite o CPF do funcionário que você gostaria de vizualizar: ");
                        printf("==> ");
                        scanf("%d",&codigo)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um cliente*/
                        /*função que mostra os dados ao usuário*/
                    }
                    if(vizualizacao==2){
                        printf("\nDigite o indicie do primeiro funcionário");
                        printf("==> ");
                        scanf("%d",&indicie_inicial);
                        printf("\nDigite o indie do último funcionário");
                        printf("==> ");
                        scanf("%d",&indice_final)
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um grupo de clientes*/
                        /*função que mostra os dados ao usuário*/
                    }
                    break;
                }

            }
        }
        
        if(cadastro == 'S' || cadastro == 's'){
            break;
        }
    }
    
    
}