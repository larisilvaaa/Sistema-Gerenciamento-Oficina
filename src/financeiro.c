#include "estruturas.h"
#include "cadastro.h"
#include "arquivos.h"
#include "menu.h"

void obterDataAtual(struct tm data) {
    time_t t;
    t = time(NULL);
    struct tm *tempo = localtime(&t);
    data=*tempo;
    return data;
}

void registrarTransacao(const char* descricao, float valor, char tipo) {
    TransacaoCaixa* p = realloc(caixa->transacoes, (caixa->num_transacoes + 1) * sizeof(TransacaoCaixa));
    if (p == NULL) {
        printf("Erro ao alocar memória!\n");
        return;
    }
    caixa->transacoes = p;
    TransacaoCaixa novaTransacao;
    strncpy(novaTransacao.descricao, descricao, sizeof(novaTransacao.descricao));
    novaTransacao.valor = valor;
    novaTransacao.tipo = tipo;
    obterDataAtual(novaTransacao.data);

    caixa->transacoes[caixa->num_transacoes++] = novaTransacao;
    if (tipo == 'E'||tipo == 'e')
        caixa->montante += valor;
    else if (tipo == 'S'||tipo == 's')
        caixa->montante -= valor;
}

/*void adicionarContaPagar(Caixa* caixa, ContaPagar conta) {
    caixa->contas_pagar = realloc(caixa->contas_pagar, (caixa->num_contas_pagar + 1) * sizeof(ContaPagar));
    conta.pago = 0;
    caixa->contas_pagar[caixa->num_contas_pagar++] = conta;
}*/

void adicionarContaPagar(int op, long int codigo, float valor){
    ContaPagar temp;
    int dia, mes, ano, hora, minuto;
    define_id_contaspagar(caixa.contas_pagar[vetor_tamanhos[8][1]]);
    temp.codigo_entidade[0]=codigo;
    temp.codigo_entidade[1]=op;
    temp.valor=valor;
    switch(op){
        case 0: //Genérico
            temp.codigo_entidade[1]=0;
            printf("Código da entidade: ");
            scanf("%d", temp.codigo_entidade[0]);
            printf("Valor: R$ ");
            scanf("%f", temp.valor);
    }
    while(1==1){
        printf("\nForma de Pagamento (D - Dinheiro ou C - cartão de crédito/debito): ");
        scanf(" %c", temp.forma_pagamento);
        if(temp.forma_pagamento!='D' || temp.forma_pagamento!='d' || temp.forma_pagamento!='C' || temp.forma_pagamento!='c'){
            printf("Valor inválido! Digite novamente!\n");
        }else{
            break;
        }
    }
    printf("\nPrazo de pagamento(dd/mm/aaaa): ");
    scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);
    temp.prazo.tm_mday = dia;
    temp.prazo.tm_mon  = mes - 1;
    temp.prazo.tm_year = ano - 1900;
    temp.prazo.tm_hour = hora;
    temp.prazo.tm_min  = minuto;
    temp.prazo.tm_sec  = 0;
    temp.prazo.tm_isdst = -1;
    temp.pago=0;
    temp.existe=1;
    caixa.contas_pagar[vetor_tamanhos[9][1]]=temp;
    vetor_tamanhos[9][1]++;
    system(CLEAR);
    printf("Conta registrada com sucesso!\n");
    PAUSE();
    system(CLEAR);
    return;
}

void adicionarContaReceber(Caixa* caixa, ContaReceber conta, char forma_pagamento, const char* prazo) {
    ContaReceber* p = realloc(caixa->contas_receber, (caixa->num_contas_receber + 1) * sizeof(ContaReceber));
    if (p == NULL) {
        printf("Erro ao alocar memória para contas a receber!\n");
        return;
    }
    caixa->contas_receber = p;
    conta.recebido = 0;
     if (forma_pagamento == 'd' || forma_pagamento == 'D') {
        // Pagamento em dinheiro: adicionar ao montante do caixa
        caixa->montante += conta.valor;
        conta.recebido = 1; // Marca como recebido
        conta.forma_pagamento = 'D';
    } else if (forma_pagamento == 'c' || forma_pagamento == 'C') {
        // Pagamento em cartão: registrar data de vencimento
        if (prazo != NULL) {
            strncpy(conta.prazo, prazo, sizeof(conta.prazo) - 1);
            conta.prazo[sizeof(conta.prazo) - 1] = '\0';
        } else {
            printf("Erro: O prazo deve ser informado para pagamentos em cartão.\n");
            return;
        }
        conta.forma_pagamento = 'C';
    } else {
        printf("Erro: Forma de pagamento inválida.\n");
        return;
    }
    caixa->contas_receber[caixa->num_contas_receber++] = conta;
}

void baixarContaPagar(Caixa* caixa, int id) {
    for (int i = 0; i < caixa->num_contas_pagar; i++) {
        if (caixa->contas_pagar[i].id == id && !caixa->contas_pagar[i].pago) { // verifica se a conta foi paga 
            registrarTransacao(caixa, "Pagamento de fornecedor", caixa->contas_pagar[i].valor, 'S');
            caixa->contas_pagar[i].pago = 1;
            printf("Conta a pagar ID %d baixada com sucesso.\n", id);
            return;
        }
    }
    printf("Conta a pagar ID %d não encontrada ou já paga.\n", id);
}

void baixarContaReceber(Caixa* caixa, int id) {
    for (int i = 0; i < caixa->num_contas_receber; i++) {
        if (caixa->contas_receber[i].id == id && !caixa->contas_receber[i].recebido) {// verifica se a conta foi recebida 
            registrarTransacao(caixa, "Recebimento de cliente", caixa->contas_receber[i].valor, 'E');
            caixa->contas_receber[i].recebido = 1;
            printf("Conta a receber ID %d baixada com sucesso.\n", id);
            return;
        }
    }
    printf("Conta a receber ID %d não encontrada ou já recebida.\n", id);
}

void exibirRelatorio(const Caixa* caixa) {
    printf("\n=== Relatório de Caixa ===\n");
    printf("Montante Atual: %.2f\n", caixa->montante);
    printf("\n=== Transações ===\n");
    for (int i = 0; i < caixa->num_transacoes; i++) {
        printf("[%s] %s: %.2f (%c)\n",
               caixa->transacoes[i].data,
               caixa->transacoes[i].descricao,
               caixa->transacoes[i].valor,
               caixa->transacoes[i].tipo);
    }
    printf("\n=== Contas a Pagar ===\n");
    for (int i = 0; i < caixa->num_contas_pagar; i++) {
        printf("ID: %d, Valor: %.2f, Pago: %s\n",
               caixa->contas_pagar[i].id,
               caixa->contas_pagar[i].valor,
               caixa->contas_pagar[i].pago ? "Sim" : "Não");
    }
    printf("\n=== Contas a Receber ===\n");
    for (int i = 0; i < caixa->num_contas_receber; i++) {
        printf("ID: %d, Valor: %.2f, Recebido: %s\n",
               caixa->contas_receber[i].id,
               caixa->contas_receber[i].valor,
               caixa->contas_receber[i].recebido ? "Sim" : "Não");
    }
}

void financeiro(){
    
    int opcao;

    // Carregar os dados ao iniciar o programa
    //carregarDados(&caixa);

    do {
        printf("\n=== Menu Financeiro ===\n");
        printf("1. Registrar transação\n");
        printf("2. Adicionar conta a pagar\n");
        printf("3. Adicionar conta a receber\n");
        printf("4. Baixar conta a pagar\n");
        printf("5. Baixar conta a receber\n");
        printf("6. Exibir relatório\n");
        printf("7. Salvar dados\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                char descricao[50], tipo;
                float valor;
                printf("Descrição: ");
                scanf(" %[^\n]s", descricao);
                printf("Valor: ");
                scanf("%f", &valor);
                printf("Tipo (E - entrada ou S - saída): ");
                scanf(" %c", &tipo);
                registrarTransacao(&caixa, descricao, valor, tipo);
                break;
            }
            case 2: {
                ContaPagar conta;
                printf("ID: ");
                scanf("%d", &conta.id);
                printf("Código do Fornecedor: ");
                scanf("%d", &conta.codigo_fornecedor);
                 printf("Forma de Pagamento (D - Dinheiro ou C - cartão de crédito/debito): ");
                scanf(" %c", &conta.forma_pagamento);
                printf("Valor: ");
                scanf("%f", &conta.valor);
                printf("Prazo (dd/mm/aaaa): ");
                scanf(" %[^\n]s", conta.prazo);
                adicionarContaPagar(&caixa, conta);
                break;
            }
            case 3: {
                ContaReceber conta;
                char forma_pagamento;
                char prazo[11];
                printf("ID: ");
                scanf("%d", &conta.id);
                printf("Código do Cliente: ");
                scanf("%d", &conta.codigo_cliente);
                printf("Forma de Pagamento (D - Dinheiro ou C - cartão de crédito/debito): ");
                scanf(" %c", &forma_pagamento);
                printf("Valor: ");
                scanf("%f", &conta.valor);
                printf("Prazo (dd/mm/aaaa): ");
                scanf(" %[^\n]s", prazo);
                adicionarContaReceber(&caixa, conta, forma_pagamento, prazo);
                break;
            }
            case 4: {
                int id;
                printf("ID da conta a pagar: ");
                scanf("%d", &id);
                baixarContaPagar(&caixa, id);
                break;
            }
            case 5: {
                int id;
                printf("ID da conta a receber: ");
                scanf("%d", &id);
                baixarContaReceber(&caixa, id);
                break;
            }
            case 6: {
                exibirRelatorio(&caixa);
                break;
            }
            case 7: {
                //salvarDados(&caixa);
                break;
            }
            case 0: {
                printf("Encerrando o programa...\n");
                //salvarDados(&caixa);
                break;
            }
            default: {
                printf("Opção inválida. Tente novamente.\n");
                break;
            }
        }
    } while (opcao != 0);

    liberarCaixa(&caixa);
}