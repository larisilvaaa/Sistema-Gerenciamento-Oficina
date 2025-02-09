#include <stdio.h>
#include <stdlib.h>
#include "estruturas.h"
#include "cadastro.h"

/*Sub-rotina que apresenta o menu de opções do cadastro
  Essa função recebe se o usuário gostaria de cadastrar os 
  dados e retorna uma opção de cadastro*/
void menu_cadastro (){
    while(1){
        char cadastro;
        int op;
        printf("\nO usuário gostaria de realizar o cadastro de dados?\n");
        printf("S- Sim\n");
        printf("N- Não\n");
        scanf(" %c",&cadastro);

        if(cadastro == 'S' || cadastro == 's'){
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
            scanf("%d",&op);

            switch(op){

                case 1:
                     Dados_Oficina oficina; 

                    oficina = cadastrar_dados_oficina();
                    break;
                case 2:
                    /*função de cadastro de dados do cliente*/
                    break;
                case 3:
                    /*função de cadastro de dados de veículos*/
                    break;
                case 4:
                    /*função de cadastro de dados de peças*/
                    break;
                case 5:
                    /*função de cadastro de dados do fornecedor*/
                    break;
                case 6:
                    /*função de cadastro de dados de serviços*/
                    break;
                case 7:
                    /*função de cadastro de dados do funcionário*/
                    break;

            }
        }
        
        if(cadastro == 'N' || cadastro == 'n'){
            break;
        }
    }
    
    
}

int main (int argc, char** argv){

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
        printf("==>");
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
