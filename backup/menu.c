#include "estruturas.h"
#include "cadastro.h"
#include "arquivos.h"
#include "menu.h"
int execucao=1;
/*Sub-rotina que apresenta o menu de opções do cadastro*/
void menu_cadastro (){
    while(1){
        system(CLEAR);
        char cadastro;
        int op,vizualizacao,codigo;
        int indice_inicial,indice_final;
        printf("\nDigite a letra correspondente a opção desejada:\n");
        printf("C- Cadastrar\n");
        printf("E- Editar\n");
        printf("V- Vizualizar\n");
        printf("A - Apagar\n");
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
            system(CLEAR);
            switch(op){

                case 1:{
                    /*função de cadastro de dados da oficina*/
                    oficina = cadastrar_dados_oficina(cadastro);
                    break;
                }
                case 2:{
                    /*função de cadastro de dados da oficina*/
                    if(vetor_tamanhos[1][1]==vetor_tamanhos[1][0]-1){
                        vetor_cliente=(Cliente*)realoca_vetor(vetor_cliente,vetor_tamanhos[1][0]+10, sizeof(Cliente),1);
                    }
                    vetor_cliente[vetor_tamanhos[1][1]]=cadastrar_dados_cliente(cadastro);
                    define_codigo_cliente(vetor_tamanhos[1][1]);
                    vetor_tamanhos[1][1]++;
                    break;
                }
                case 3:{
                    /*função de cadastro de dados de veículos*/
                    if(vetor_tamanhos[2][1]==vetor_tamanhos[2][0]-1){
                        vetor_veiculo=(Veiculo*)realoca_vetor(vetor_veiculo,vetor_tamanhos[2][0]+10, sizeof(Veiculo),2);
                    }
                    vetor_veiculo[vetor_tamanhos[2][1]]=cadastrar_dados_veiculo(cadastro);
                    vetor_tamanhos[2][1]++;
                    break;
                }
                case 4:{
                    /*função de cadastro de dados de peças*/
                    if(vetor_tamanhos[3][1]==vetor_tamanhos[3][0]-1){
                        vetor_peca=(Peca*)realoca_vetor(vetor_peca,vetor_tamanhos[3][0]+10, sizeof(Peca),3);
                    }
                    vetor_peca[vetor_tamanhos[3][1]]=cadastrar_dados_peca(cadastro);
                    define_codigo_peca(vetor_tamanhos[3][1]);
                    vetor_tamanhos[3][1]++;
                    break;
                }
                case 5:{
                    /*função de cadastro de dados do fornecedor*/
                    if(vetor_tamanhos[4][1]==vetor_tamanhos[4][0]-1){
                        vetor_fornecedor=(Fornecedor*)realoca_vetor(vetor_fornecedor,vetor_tamanhos[4][0]+10, sizeof(Fornecedor),4);
                    }
                    vetor_fornecedor[vetor_tamanhos[4][1]]=cadastrar_dados_fornecedor(cadastro);
                    define_codigo_fornecedor(vetor_tamanhos[4][1]);
                    vetor_tamanhos[4][1]++;
                    break;
                }
                case 6:{
                    /*função de cadastro de dados de serviços*/
                    if(vetor_tamanhos[5][1]==vetor_tamanhos[5][0]-1){
                        vetor_servico=(Servico*)realoca_vetor(vetor_servico,vetor_tamanhos[5][0]+10, sizeof(Servico),5);
                    }
                    vetor_servico[vetor_tamanhos[5][1]]=cadastrar_dados_servico(cadastro);
                    define_codigo_servico(vetor_tamanhos[5][1]);
                    vetor_tamanhos[5][1]++;
                    break;
                }
                case 7:{
                    /*função de cadastro de dados do funcionário*/
                    if(vetor_tamanhos[6][1]==vetor_tamanhos[6][0]-1){
                        vetor_funcionario=(Funcionario*)realoca_vetor(vetor_funcionario,vetor_tamanhos[6][0]+10, sizeof(Funcionario),6);
                    }
                    vetor_funcionario[vetor_tamanhos[6][1]]=cadastrar_dados_funcionario(cadastro);
                    vetor_tamanhos[6][1]++;
                    break;
                }

            }
        }else

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
                    oficina = cadastrar_dados_oficina(cadastro);
                    break;
                }
                case 2:{
                    /*função de edição de dados do cliente*/
                    cadastrar_dados_cliente(cadastro);
                    break;
                }
                case 3:{
                    /*função de edição de dados de veículos*/
                    cadastrar_dados_veiculo(cadastro);
                    break;
                }
                case 4:{
                    /*função de edição de dados de peças*/
                    cadastrar_dados_peca(cadastro);
                    break;
                }
                case 5:{
                    /*função de edição de dados do fornecedor*/
                    cadastrar_dados_fornecedor(cadastro);
                    break;
                }
                case 6:{
                    /*função de edição de dados de serviços*/
                    cadastrar_dados_servico(cadastro);
                    break;
                }
                case 7:{
                    /*função de ediçao de dados do funcionário*/
                    cadastrar_dados_funcionario(cadastro);
                    break;
                }

            }
        }else

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
            if(op==1){
                visualizar_dados(op, 0, 0, 0);
            }else if(op>=1 || op<=7){
                printf("\n\n------------------------\n");
                printf("|     Menu de opções    |\n");
                printf("|    de vizualização    |\n");
                printf("------------------------\n");
                printf("Selecione o que você gostaria de vizualizar:");
                printf("\n1- Vizualizar um cadastro pelo código");
                printf("\n2- Vizualizar um conjunto de cadastros\n");
                printf("==> ");
                scanf("%d",&vizualizacao);
                system(CLEAR);
                if(vizualizacao==1){
                    visualizar_dados(op,vizualizacao,0,0);
                        /*função que verifica se existem dados cadastrados*/
                        /*função que vizualiza um cliente*/
                        /*função que mostra os dados ao usuário*/
                }else if(vizualizacao==2){
                    printf("\nDigite o indicie do primeiro cadastro");
                    printf("\n==> ");
                    scanf("%d",&indice_inicial);
                    printf("\nDigite o indie do último cadastro");
                    printf("\n==> ");
                    scanf("%d",&indice_final);
                    visualizar_dados(op,vizualizacao,indice_inicial,indice_final);
                }
            }
        }else
        if(cadastro == 'S' || cadastro == 's'){
            break;
        }else if(cadastro=='A' || cadastro=='a'){
            int posicao;
            long int codigo_ld;
            char texto[1024];
            printf("------------------------\n");
            printf("|     Menu de opções    |\n");
            printf("------------------------\n");
            printf("Selecione de qual cadastro você gostaria de apagar:");
            printf("\n1- Clientes");
            printf("\n2- Veículos");
            printf("\n3- Peças");
            printf("\n4- Fornecedores");
            printf("\n5- Serviços");
            printf("\n6- Funcionários\n");
            printf("==> ");
            scanf("%d",&op);

            if(op==1){
                printf("Digite o código do cliente: ");
                scanf("%d", &codigo);

                posicao = procura_vetor_cliente(codigo);// Verifica se o cadastro desse cliente existe
                if(posicao==-1){
                    printf("Cadastro não encontrado!\n");
                }else{
                    exclui_em_vetor_cliente(posicao);
                }
            }else if(op==2){
                printf("Digite a placa do veículo: ");
                setbuf(stdin, NULL);
                fgets(texto, 1024, stdin);
                remove_barra_n(texto);
                posicao = procura_vetor_veiculo(texto);// Verifica se o cadastro desse cliente existe
                if(posicao==-1){
                    printf("Cadastro não encontrado!\n");
                }else{
                    exclui_em_vetor_veiculo(posicao);
                }
            }else if(op==3){
                printf("Digite o código da peça: ");
                scanf("%d", &codigo);

                posicao = procura_vetor_peca(codigo);// Verifica se o cadastro desse cliente existe
                if(posicao==-1){
                    printf("Cadastro não encontrado!\n");
                }else{
                    exclui_em_vetor_peca(posicao);
                }
            }else if(op==4){
                printf("Digite o código do fornecedor: ");
                scanf("%d", &codigo);

                posicao = procura_vetor_fornecedor(codigo);// Verifica se o cadastro desse cliente existe
                if(posicao==-1){
                    printf("Cadastro não encontrado!\n");
                }else{
                    exclui_em_vetor_fornecedor(posicao);
                }
            }else if(op==5){
                printf("Digite o código do servico: ");
                scanf("%d", &codigo);

                posicao = procura_vetor_servico(codigo);// Verifica se o cadastro desse cliente existe
                if(posicao==-1){
                    printf("Cadastro não encontrado!\n");
                }else{
                    exclui_em_vetor_servico(posicao);
                }
            }else if(op==6){
                printf("Digite o cpf do funcionario: ");
                scanf("%ld", &codigo_ld);

                posicao = procura_vetor_funcionario(codigo_ld);// Verifica se o cadastro desse cliente existe
                if(posicao==-1){
                    printf("Cadastro não encontrado!\n");
                }else{
                    exclui_em_vetor_funcionario(posicao);
                }
            }
        }
        PAUSE();
    }
}

void menu_relatorio(){
    int cur, filtro;
    char linha_filtro[1024];
    while(1){
        system(CLEAR);
        printf("Digite o numero correspondente a qual relatorio gostaria de gerar: \n");
        printf("1-Cadastros basicos\n");
        printf("2-Estoque\n");
        printf("3-Produtividade\n");
        printf("4-Funcionario\n");
        printf("9-Sair\n");
        printf("==> ");
        scanf("%d", cur);
        switch(cur){
            case 1:
                printf("\nDigite o numero correspondente a qual cadastro gostaria de gerar relatorio:\n");
                printf("1-Clientes\n");
                printf("2-Veiculo\n");
                printf("3-Peca\n");
                printf("3-Fornecedor\n");
                printf("4-Servico\n");
                printf("5-Funcionario\n");
                printf("==> ");
                scanf("%d", cur);
                if(cur<1||cur>5){
                    printf("Opcao Invalida! Retornando ao menu anterior!\n");
                    PAUSE();
                }else{
                    printf("\nDigite o numero correspondente ao filtro desejado:\n");
                    printf("1-Sem filtro\n");
                    printf("2-Nome\n");
                    printf("3-Codigo\n");
                    printf("==> ");
                    scanf("%d", filtro);
                    if(filtro==1||filtro<1||filtro>3){
                        filtro=1;
                    }else{
                        printf("\nDigite seu filtro: ");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]", linha_filtro);
                    }
                    relatorio_cadastro_basico(cur,filtro,linha_filtro);
                }
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 9:
                return;
                break;
            default:
                printf("Opcao Invalida! Digite Novamente!\n");
                PAUSE();
        }
    }
    PAUSE();
    return;
}