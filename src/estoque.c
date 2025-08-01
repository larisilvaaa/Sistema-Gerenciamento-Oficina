#include "estruturas.h"
#include "cadastro.h"
#include "arquivos.h"
#include "menu.h"
#include "financeiro.h"
#include <locale.h>

//funçao registra a entrada de uma nota fiscal
void registrar_peca(){
    int codigo_quantidade[100][3];//primeira coluna ocupada pelo codigo da peça e a segunda coluna ocupada pela quantidade da mesma
    int op; 
    float frete_produto,imposto_produto,preco_venda_atualizado;
    while(1){
        printf("\n----------------------------\n");
        printf("|        Menu de opções       |");
        printf("\n----------------------------\n");
        printf("\nGostaria de realizar a entrada de uma nota fiscal?\n");
        printf("1- Sim\n");
        printf("2- Não\n");
        printf("==> ");
        scanf("%d",&op);
        if(op==1){
            long int cnpj_fornecedor;
            int quant=0, pos;
            int tipos_pecas = 0;
            int pecas_cadastradas=0;
            Estoque nova_peca;
            float preco_total=0;

            printf("\nDigite o CNPJ do fornecedor: ");
            scanf("%ld", &cnpj_fornecedor);
            op=procura_vetor_fornecedor(cnpj_fornecedor);
            if(op==-1){
                printf("\nO fornecedor não consta em nossos sistemas!");
                PAUSE();
                system(CLEAR);
                return;
            }

            printf("\nValor do frete: ");
            scanf("%f",&nova_peca.frete);

            printf("\nValor do imposto: ");
            scanf("%f",&nova_peca.imposto);


            while (tipos_pecas<100) {
                printf("\n=== Registro de Peça ===\n");

                printf("\nCódigo da peça (ou -1 para finalizar): ");
                scanf("%d", &codigo_quantidade[tipos_pecas][0]);
                if (codigo_quantidade[tipos_pecas][0] == -1){
                    break;
                }
                pos=procura_vetor_peca(codigo_quantidade[tipos_pecas][0]);
                if(pos==-1){
                    printf("\nEssa peça não foi encontrada! Digite novamente!\n");
                }else{
                    printf("Unidades por peça: ");
                    scanf("%d", &codigo_quantidade[tipos_pecas][1]);
                    codigo_quantidade[tipos_pecas][2]=pos;

                    //encontra a quantidade total de pecas
                    quant += codigo_quantidade[tipos_pecas][1];

                    //encontra quantos tipos de pecas foram cadastradas
                    tipos_pecas++;
                    preco_total+=vetor_peca[pos].precoCusto*codigo_quantidade[tipos_pecas][1];
                }
                if(tipos_pecas==100){
                    printf("\nNão é possível cadastrar mais peças! Prosseguindo cadastro!\n");
                }
            }

            nova_peca.unidades = quant;

            frete_produto = nova_peca.frete/(quant);
            imposto_produto = nova_peca.imposto/(quant);

            tipos_pecas=0;
            while(codigo_quantidade[tipos_pecas][0] != -1 && tipos_pecas < 100){
                vetor_peca[codigo_quantidade[tipos_pecas][2]].precoVenda=vetor_peca[codigo_quantidade[tipos_pecas][2]].precoCusto+frete_produto+imposto_produto+(oficina.porcentagemLucro*vetor_peca[codigo_quantidade[tipos_pecas][2]].precoCusto);
                vetor_peca[codigo_quantidade[tipos_pecas][2]].quantidadeEstoque+=codigo_quantidade[tipos_pecas][1];
                tipos_pecas++;
            }
            //adicionarContaPagar(4, pos, preco_total);
        }
        if(op==2){
            break;
        }
    }
    return;
}

void alerta_estoque(){
    int qtd=0;
    system(CLEAR);
    for(int i=0;i<vetor_tamanhos[4][1];i++){
        if(vetor_peca[i].quantidadeEstoque<=vetor_peca[i].estoqueMinimo){
            qtd++;
            printf("Peça: %s com estoque baixo!\n", vetor_peca[i].nome);
        }
    }
    if(qtd>0){
        PAUSE();
        system(CLEAR);
        return;
    }
    return;
}

void atualizar_estoque(int pos){
    int contador, pos1;
    while(contador!=100 || vetor_ordemservico[pos].pecas[contador][0]==-1){
        pos1=procura_vetor_peca(vetor_ordemservico[pos].pecas[contador][0]);
        vetor_peca[pos1].quantidadeEstoque-=vetor_ordemservico[pos].pecas[contador][1];
    }
    return;
}