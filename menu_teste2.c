#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "cadastro.h"

/*Sub-rotina que apresenta o menu de opções do cadastro*/
void menu_cadastro (){
    while(1){
        char cadastro;
        int op;
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
                    /*função que verifica se existem dados cadastrados*/
                    /*função que mostra os dados ao usuário*/
                    break;
                }
                case 2:{
                    /*função que verifica se existem dados cadastrados*/
                    /*função que mostra os dados ao usuário*/
                    break;
                }
                case 3:{
                    /*função que verifica se existem dados cadastrados*/
                    /*função que mostra os dados ao usuário*/
                    break;
                }
                case 4:{
                    /*função que verifica se existem dados cadastrados*/
                    /*função que mostra os dados ao usuário*/
                    break;
                }
                case 5:{
                    /*função que verifica se existem dados cadastrados*/
                    /*função que mostra os dados ao usuário*/
                    break;
                }
                case 6:{
                    /*função que verifica se existem dados cadastrados*/
                    /*função que mostra os dados ao usuário*/
                    break;
                }
                case 7:{
                    /*função que verifica se existem dados cadastrados*/
                    /*função que mostra os dados ao usuário*/
                    break;
                }

            }
        }
        
        if(cadastro == 'S' || cadastro == 's'){
            break;
        }
    }
    
    
}

int main (){

    /*Apresenta ao usário o menu principal*/
    while(1){
        char op;
        printf("------------------------\n");
        printf("|     Menu principal    |\n");
        printf("------------------------\n");
        printf("Digite a letra correspondente a opção desejada:");
        printf("\nC- Cadastro de Dados");
        printf("\nA- Agendamento e Controle de Serviços");
        printf("\nE- Estoque");
        printf("\nF- Financeiro");
        printf("\nR- Relatórios");
        printf("\nI- Importação/Exportação de Dados");
        printf("\nS- Sair\n");
        printf("==> ");
        scanf(" %c",&op);
        
        if(op =='C'|| op == 'c'){
            /*Sub-rotina que apresenta as opções de cadastro*/
            menu_cadastro();
        }
        
        if(op =='S' || op == 's'){
            break;
        }
    }

    return 0;
}