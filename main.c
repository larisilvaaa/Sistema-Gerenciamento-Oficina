#include "estruturas.h"
#include "cadastro.h"
#include "arquivos.h"
#include "menu.h"
#include <locale.h>

int main(){
    setlocale(LC_ALL, "pt_BR.UTF-8"); 
    int cur;
    inicia_vetor_tamanhos();
    if(inicia_vetor_estruturas()==-1){
        printf("Erro na alocação de memória! Fechando o programa!\n");
        exit(1);
    }
    inicializa_sistema();
    while(execucao==1){
        char op;
        system(CLEAR);
        printf("------------------------\n");
        printf("|     Menu principal    |\n");
        printf("------------------------\n");
        printf("Digite a letra correspondente a opção desejada:");
        printf("\nG- Gerenciamento de Dados");
        printf("\nA- Agendamento e Controle de Serviços");
        printf("\nE- Estoque");
        printf("\nF- Financeiro");
        printf("\nR- Relatórios");
        printf("\nI- Importação/Exportação de Dados");
        printf("\nO- Opções de armazenamento");
        printf("\nS- Salvar arquivos");
        printf("\nF- Finalizar programa");
        printf("\n==> ");
        scanf(" %c",&op);
        
        switch(op){
            case 'g':
            case 'G':
                menu_cadastro();
                break;
            case 'o':
            case 'O':
                system(CLEAR);
                printf("\n\nMETODO DE SALVAMENTO:");
                printf("\n\nMetodo atual: ");
                switch(vetor_tamanhos[0][0]){
                    case 0:
                        printf("Binário");
                        break;
                    case 1:
                        printf("Texto");
                        break;
                }
                printf("\n\nVocê tem certeza que quer trocar o metodo? (1 para SIM/ 0 para NÃO)\n==> ");
                scanf("%d", &cur);
                if(cur==1){
                    if(troca_salvamento(vetor_tamanhos[0][0])==-1){
                        printf("\nErro na hora da troca, mantendo metodo de armazenamento atual!");
                    }else{
                        printf("\nTroca bem sucedida!\n\n");
                    }
                }
                PAUSE();
                break;
            case 's':
            case 'S':
                system(CLEAR);
                printf("\n\nSalvando...");
                if(salvar_arquivos()==-1){
                    printf("\nErro ao salvar arquivos, voltando ao menu!\n\n");
                }else{
                    printf("\nSalvo com sucesso!\n\n");
                }
                PAUSE();
                break;
            case 'f':
            case 'F':
                system(CLEAR);
                printf("\nMuito obrigado por utilizar o programa! :D\n");
                finaliza_vetor_estruturas();
                execucao=0;
                PAUSE();
                break;
        }
    }

    return 0;
}

//To Do: Menu
//Implementar Opções de armazenamento FEITO!
//Salvar arquivos FEITO!

//To Do: Gerenciamento de dados
//Implementar p/Larissa na p/Marcela FEITO!
//Migrar controle de alocação de Larissa para Marcela FEITO!
//Polir visuais

//To Do: Controle
//Colocar limpa_barra_n() FEITO!
//Reprogramar visualização
//Remover codigos
//Adaptar

//To Do: Arquivos
//Corrigir leitura txt
