#include "estruturas.h"
#include "cadastro.h"
#include "arquivos.h"
#include "menu.h"
#include <locale.h>

typedef struct{
    char nome_peca[100];
    float frete;
    float imposto;
    int unidades;
    int quant_minima;
} estoque;

estoque pecas[100];

//funçao registra a entrada de uma nota fiscal
void registrar_peca(){
    int codigo_quantidade[100][2];//primeira coluna ocupada pelo codigo da peça e a segunda coluna ocupada pela quantidade da mesma
    int op; 
    float frete_produto,imposto_produto,preco_venda_atualizado;
    estoque a;
    while(1){
        Dados_Oficina;
        Peca peca;
        printf("\n----------------------------\n");
        printf("|        Menu de opções       |");
        printf("\n----------------------------\n");
        printf("\nGostaria de realizar a entrada de uma nota fiscal?\n");
        printf("1- Sim\n");
        printf("2- Não\n");
        printf("==> ");
        scanf("%d",&op);
        if(op==1){
            int quant=0;
            int tipos_pecas = 0;
            int  i=0,pecas_cadastradas=0;
            estoque nova_peca;
            //estoque *p = &pecas[pecas_cadastradas];

            printf("\nValor do frete: ");
            scanf("%f",&nova_peca.frete);

            printf("\nValor do imposto: ");
            scanf("%f",&nova_peca.imposto);


            while (1) {
                int tipos_pecas = 0;

                printf("\n=== Registro de Peça ===\n");

                printf("\nCódigo da peça (ou -1 para finalizar): ");
                scanf("%d", &codigo_quantidade[tipos_pecas][0]);
                if (codigo_quantidade[tipos_pecas][0] == -1){
                    break;
                } 
                printf("Unidades por peça: ");
                scanf("%d", &codigo_quantidade[tipos_pecas][1]);

                //encontra a quantidade total de pecas
                quant += codigo_quantidade[tipos_pecas][1];

                //encontra quantos tipos de pecas foram cadastradas
                tipos_pecas++;
            }

            nova_peca.unidades = quant;

            frete_produto = nova_peca.frete/(quant);
            imposto_produto = nova_peca.imposto/(quant);

            //calcula o novo preço de venda
            preco_venda_atualizado = (float)peca.precoCusto+frete_produto+imposto_produto+oficina.porcentagemLucro;
            printf("\nPreço de venda atualizado: %5.2f\n", preco_venda_atualizado);
            peca.precoVenda = preco_venda_atualizado;

            //calcula e atualiza o preço de venda
            for(i=0;i<100;i++){
                int posicao=procura_vetor_peca(codigo_quantidade[i][0]);
                vetor_peca[posicao].precoVenda=preco_venda_atualizado;
            }

            // Salvar peça no vetor de estoque
            pecas[pecas_cadastradas] = nova_peca;
            pecas_cadastradas++;

        }
        if(op==2){
            break;
        }
    
    }
}

// Função que alerta estoque baixo
/*void verificar_estoque() {
    Peca peca;
    printf("\n=== Verificação de Estoque ===\n");
    for (int i = 0; i < pecas_cadastradas; i++) {
        for (int j = 0; j < pecas[i].num_codigos; j++) {
            if (pecas[i].codigo_quantidade[j][1] <= (int)peca.estoqueMinimo) {
                printf("ALERTA: Estoque baixo para a peça '%s'",pecas[i].nome_peca);
            }
        }
    }
}*/


int main (){ 
    registrar_peca();
    return 0;
}