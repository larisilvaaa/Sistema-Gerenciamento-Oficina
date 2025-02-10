#include "estruturas.h"
#include "arquivos.h"   //Importa o cabeçalho com as funções de memória 
// Importa o cabeçalho com as definições das estruturas
#include "cadastro.h"
#include "financeiro.h"

int verifica_colisao_funcionario(OrdemServico *p){
    for(int i=0;i<vetor_tamanhos[7][1];i++){
        if(vetor_ordemservico[i].cpf_funcionario==(*p).cpf_funcionario){
            if(vetor_ordemservico[i].data_hora.tm_mday==(*p).data_hora.tm_mday &&
            vetor_ordemservico[i].data_hora.tm_mon==(*p).data_hora.tm_mon &&
            vetor_ordemservico[i].data_hora.tm_year==(*p).data_hora.tm_year){
                if((*p).data_hora.tm_hour == vetor_ordemservico[i].data_hora.tm_hour){
                   return -1; 
                }
            }
        }
    }
    return 1;
}

float calcula_comissao(OrdemServico *p){
    int contador=0, pos;
    double comissao=0;
    while((*p).codigo_servicos[contador]!=-1 || contador<100){
        pos=procura_vetor_servico((*p).codigo_servicos[contador]);
        comissao+=(double)vetor_servico[pos].comissao;
        contador++;
    }
    return comissao;
}

double calcula_diferenca_datas(struct tm data1, struct tm data2){
    double dife;
    time_t tempo1, tempo2;
    tempo1=mktime(&data1);
    tempo2=mktime(&data2);
    if(tempo1==-1 || tempo2 ==-1){
        return -1;
    }
    dife=difftime(tempo2, tempo1);
    dife/=(60*60*24);
    return dife;
}

void verifica_produtividade(){
    int cod, pos;
    double dife;
    system(CLEAR);
    printf("Digite o código da ordem de serviço finalizada: ");
    setbuf(stdin, NULL);
    scanf("%d", &cod);
    pos=procura_vetor_ordemservico(cod);
    if(pos==-1){
        printf("A ordem de serviço não foi encontrada!");
        PAUSE();
        system(CLEAR);
        return;
    }else if(vetor_ordemservico[pos].finalizado==0){
        printf("A ordem de serviço não foi finalizada!");
        PAUSE();
        system(CLEAR);
        return;
    }
    dife=calcula_diferenca_datas(vetor_ordemservico[pos].data_hora, vetor_ordemservico[pos].data_hora_final);
    system(CLEAR);
    printf("O funcionario de cpf %ld finalizou tal serviço em %.1f dias!\n", vetor_ordemservico[pos].cpf_funcionario, dife);
    PAUSE();
    system(CLEAR);
    return;
}

void novo_agendamento_servico(){
    OrdemServico servico_temp;
    int contador=0,dia, mes, ano, hora, minuto, pos;
    servico_temp.preco=0;
    printf("Digite a placa do veiculo a receber o serviço: ");
    setbuf(stdin, NULL); // Limpa o buffer para evitar problemas de entrada
    fgets(servico_temp.placa, 10, stdin); // lê todos os caracteres incluindo os espaços
    remove_barra_n(servico_temp.placa);
    if(procura_vetor_veiculo(servico_temp.placa)==-1){
        printf("Veículo não encontrado! Favor cadastrar!\n");
        PAUSE();
        system(CLEAR);
        return;
    }
    while(contador<100){
        printf("Digite '-1' na entrada abaixo caso tenha finalizado!\n");
        printf("Digite o código do %d servico: ", contador);
        setbuf(stdin, NULL);
        scanf("%d", servico_temp.codigo_servicos[contador]);
        pos=procura_vetor_servico(servico_temp.codigo_servicos[contador]);
        if(servico_temp.codigo_servicos[contador]==-1){
            break;
        }else if(pos==-1){
            printf("Este servico nao consta em nosso sistema!\n");
        }else{
            servico_temp.preco+=vetor_servico[pos].preco+vetor_servico[pos].comissao;
            contador++;
        }
        if(contador==100){
            printf("Limite de serviços possíveis de se cadastrar atingido! Prosseguindo cadastro!\n");
        }
    }
    contador=0;
    while(contador<100){
        printf("Digite '-1' na entrada abaixo caso tenha finalizado!\n");
        printf("Digite o código da %d peça: ", contador);
        setbuf(stdin, NULL);
        scanf("%d", servico_temp.pecas[contador][0]);
        printf("Digite a quantidade da %d peça: ", contador);
        setbuf(stdin, NULL);
        scanf("%d", servico_temp.pecas[contador][1]);
        pos=procura_vetor_peca(servico_temp.pecas[contador][0]);
        if(servico_temp.pecas[contador][0]==-1){
            break;
        }else if(pos==-1){
            printf("Esta peça nao consta em nosso sistema!\n");
        }else{
            servico_temp.preco+=(float)vetor_peca[pos].precoVenda * servico_temp.pecas[contador][1];
            contador++;
        }
        if(contador==100){
            printf("Limite de peças possíveis de se cadastrar atingido! Prosseguindo cadastro!\n");
        }
    }
    while(1){
        printf("Digite a data nesse formato, ignorando os parenteses! (DD/MM/AAAA HH:MM)\n");
        printf("Digite a data e hora do início da execução dessa ordem de serviço: ");
        setbuf(stdin, NULL);
        scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);
        servico_temp.data_hora.tm_mday = dia;
        servico_temp.data_hora.tm_mon  = mes - 1;
        servico_temp.data_hora.tm_year = ano - 1900;
        servico_temp.data_hora.tm_hour = hora;
        servico_temp.data_hora.tm_min  = minuto;
        servico_temp.data_hora.tm_sec  = 0;
        servico_temp.data_hora.tm_isdst = -1;
        if(verifica_colisao_funcionario(&servico_temp)==-1){
            printf("O funcionário esta ocupado nesta data!\n");
        }else{
            break;
        }
    }
    printf("Escreva o valor da comissão do funcionário por serviço: R$");
    setbuf(stdin, NULL);
    scanf("%f", &servico_temp.comissao);
    servico_temp.codigo=define_codigo_ordem_servico(vetor_tamanhos[7][1]);
    servico_temp.existe=1;
    servico_temp.finalizado=0;
    vetor_ordemservico[vetor_tamanhos[7][1]]=servico_temp;
    vetor_tamanhos[7][1]++;
    system(CLEAR);
    printf("Ordem de serviço cadastrada com sucesso!\n");
    printf("Código da ordem: %d", servico_temp.codigo);
    PAUSE();
    system(CLEAR);
    return;
}

void finaliza_servico(){
    int cod_ord, pos, dia, mes, ano, hora, minuto;
    struct tm data_horaf;
    double dife, comissao;
    system(CLEAR);
    printf("Digite o código da ordem de serviço: ");
    setbuf(stdin, NULL);
    scanf("%d", &cod_ord);
    pos=procura_vetor_ordemservico(cod_ord);
    if(pos==-1){
        printf("Essa ordem de serviço não foi encontrada!\n");
        PAUSE();
        system(CLEAR);
        return;
    }
    printf("Digite a data nesse formato, ignorando os parenteses! (DD/MM/AAAA HH:MM)\n");
    printf("Digite a data e hora do final da execução dessa ordem de serviço: ");
    setbuf(stdin, NULL);
    scanf("%d/%d/%d %d:%d", &dia, &mes, &ano, &hora, &minuto);
    data_horaf.tm_mday = dia;
    data_horaf.tm_mon  = mes - 1;
    data_horaf.tm_year = ano - 1900;
    data_horaf.tm_hour = hora;
    data_horaf.tm_min  = minuto;
    data_horaf.tm_sec  = 0;
    data_horaf.tm_isdst = -1;
    vetor_ordemservico[pos].data_hora_final=data_horaf;
    atualizar_estoque(pos);
    dife=calcula_diferenca_datas(vetor_ordemservico[pos].data_hora, vetor_ordemservico[pos].data_hora_final);
    comissao=calcula_comissao(&vetor_ordemservico[pos]);
    adicionarContaPagar(6,vetor_ordemservico[pos].cpf_funcionario,(float)comissao);
    system(CLEAR);
    printf("O funcionario de cpf %ld finalizou tal serviço em %.1f dias, recebendo R$%.2f de comissão!\n", vetor_ordemservico[pos].cpf_funcionario, dife, comissao);
    PAUSE();
    system(CLEAR);
    vetor_ordemservico[pos].finalizado=1;
    return;
}