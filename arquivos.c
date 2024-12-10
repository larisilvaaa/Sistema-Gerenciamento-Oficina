//Inclusões e definiçoes

#include "estruturas.h" //Biblioteca com as structs criadas pelo nosso grupo para operar o programa
#define qtdvet 7 //Refere-se principalmente a quantidade de vetores de Struct presentes no programa

//Variaveis globais

/*vetor_tamanhos->Vetor int de controle de tamanhos dos vetores de Struct dinâmicos. Segue especificações de cada posição:
vetor_tamanhos[0][0]->Controla forma de salvamento do programa, sendo 0 binário e 1 texto.
vetor_tamanhos[X][Y]->X representa um vetor de structs específicos, enquanto Y representa a informação guardada ali.
Segue possíveis valores de X e qual vetor ele representa:
1-vetor_cliente
2-vetor_veiculo
3-vetor_peca
4-vetor_fornecedor
5-vetor_servico
6-vetor_funcionario
Segue possíveis valores de Y e qual informação ele representa:
0-Tamanho alocado ao vetor
1-Posição disponível adjacente a última posição preenchida no vetor*/

int vetor_tamanhos[qtdvet][2];

/*Vetores de Structs->(Com execeção da variavel Oficina, que é uma variável comum) São os vetores na qual manipulamos
a informação na memória RAM dentro do programa. Funciona como ponteiros de vetores de alocação dinâmica.*/

Dados_Oficina oficina;
Cliente *vetor_cliente;
Veiculo *vetor_veiculo;
Peca *vetor_peca;
Fornecedor *vetor_fornecedor;
Servico *vetor_servico;
Funcionario *vetor_funcionario;

//Subrotinas de iniciação de valores
/*Serve para iniciar os vetores com valores padrão*/

/*Define valores padrões para o vetor_tamanhos*/
void inicia_vetor_tamanhos(){
    srand(time(NULL));
    vetor_tamanhos[0][0]=0; //Define o modo de escrita do programa como binária por padrão
    for(int i=1;i<qtdvet;i++){ //Define o tamanho de cada vetor como 10 e a posição 0 como a próxima disponível para escrita 
        vetor_tamanhos[i][0]=10;
        vetor_tamanhos[i][1]=0;
    }
    return;
}

/*Aloca 10 posições de memória zeradas para cada vetor.*/
int inicia_vetor_estruturas(){
    vetor_cliente=(Cliente*)calloc(10, sizeof(Cliente));
    vetor_veiculo=(Veiculo*)calloc(10, sizeof(Veiculo));
    vetor_peca=(Peca*)calloc(10, sizeof(Peca));
    vetor_fornecedor=(Fornecedor*)calloc(10, sizeof(Fornecedor));
    vetor_servico=(Servico*)calloc(10, sizeof(Servico));
    vetor_funcionario=(Funcionario*)calloc(10, sizeof(Funcionario));
    if (vetor_cliente == NULL || vetor_veiculo == NULL || vetor_peca == NULL || vetor_fornecedor == NULL || vetor_servico == NULL || vetor_funcionario == NULL){
        return -1;
    }
    return 1;
}

//Subrotina de finalização

/*Libera toda a memoria alocada para cada vetor dinâmico controlado pelo vetor_tamanhos.*/
void finaliza_vetor_estruturas(){
    free(vetor_cliente);
    free(vetor_veiculo);
    free(vetor_peca);
    free(vetor_fornecedor);
    free(vetor_servico);
    free(vetor_funcionario);
    return;
}

//Subrotinas de realocação dos vetores dinâmicos

/*Realoca um vetor dinâmico especifico passado para ele e, caso seja um dos vetores controlados pelo vetor_tamanhos,
atualiza seu valor em [X][0]. Retorna o vetor não realocado em caso de erro*/
void* realoca_vetor(void *origem, size_t tamanho_novo, size_t tamanho_tipo, int tipo){
    void* backup=origem;
    origem=realloc(origem, tamanho_novo*tamanho_tipo);
    if(origem==NULL){
        fprintf(stderr, "\nErro ao realocar memória. Mantendo o ponteiro original.\n");
        printf("\nErro ao realocar memória. Mantendo o ponteiro original.\n");
        return backup;
    }
    if(tipo!=-1){
        vetor_tamanhos[tipo][0]=(int)tamanho_novo;
    }
    return origem;
}

/*Realoca todos os vetores controlados pelo vetor_tamanhos com base no valor de cada um neste*/
void realoca_vetores(){
    vetor_cliente=(Cliente*)realoca_vetor(vetor_cliente, vetor_tamanhos[1][0], sizeof(Cliente), 1);
    vetor_veiculo=(Veiculo*)realoca_vetor(vetor_veiculo, vetor_tamanhos[2][0], sizeof(Veiculo), 2);
    vetor_peca=(Peca*)realoca_vetor(vetor_peca, vetor_tamanhos[3][0], sizeof(Peca), 3);
    vetor_fornecedor=(Fornecedor*)realoca_vetor(vetor_fornecedor, vetor_tamanhos[4][0], sizeof(Fornecedor), 4);
    vetor_servico=(Servico*)realoca_vetor(vetor_servico, vetor_tamanhos[5][0], sizeof(Servico), 5);
    vetor_funcionario=(Funcionario*)realoca_vetor(vetor_funcionario, vetor_tamanhos[6][0], sizeof(Funcionario), 6);
    return;
}

//Subrotinas de manipulação do vetor_tamanhos

/*Escreve o vetor_tamanhos na memória persistente do computador em dois arquivos binários, um principal e outro de backup.
OBS:Por ser uma informação de controle do sistema, esse vetor específico só é manipulado na memória persistente em binário.*/
int escreve_vetor_tamanhos(){
    FILE *p_arquivo=NULL, *p_arquivo_backup=NULL;
    mkdir(".//save");
    p_arquivo=fopen(".//save//tamanho_vetores.bin", "wb");
    p_arquivo_backup=fopen(".//save//tamanho_vetores_backup.bin", "wb");
    if(p_arquivo==NULL || p_arquivo_backup==NULL){
        if (p_arquivo != NULL) fclose(p_arquivo);
        if (p_arquivo_backup != NULL) fclose(p_arquivo_backup);
        return -1;
    }
    fwrite(vetor_tamanhos, sizeof(int), qtdvet*2, p_arquivo);
    fwrite(vetor_tamanhos, sizeof(int), qtdvet*2, p_arquivo_backup);
    fclose(p_arquivo);
    fclose(p_arquivo_backup);
    return 1;
}

/*Lê o vetor_tamanhos da memoria persistente e as escreve no vetor_tamanhos operado pelo programa nas suas respectivas posições.
Por meio do parâmetro operações, controla se será lido o arquivo principal ou backup.
OBS:Por ser uma informação de controle do sistema, esse vetor específico só é manipulado na memória persistente em binário.*/
int le_vetor_tamanhos(int operacao){
    FILE *p_arquivo=NULL;
    switch(operacao){
        case 0:
            p_arquivo=fopen(".//save//tamanho_vetores.bin", "rb");
            if(p_arquivo==NULL){
                return -1;
            }
            break;
        case 1:
            p_arquivo=fopen(".//save//tamanho_vetores_backup.bin", "rb");
            if(p_arquivo==NULL){
                return -1;
            }
            break;
        default:
            return -1;
    }
    fread(vetor_tamanhos, sizeof(int), qtdvet*2, p_arquivo);
    if(ferror(p_arquivo)){
        fclose(p_arquivo);
        return -1;
    }
    fclose(p_arquivo);
    return 1;
}

//Subrotinas de escrita dos vetores de structs em txt

/*Escreve os vetores de struct na memória presistente por meio arqivos txt. Escrevem dois arquivos, um principal,
e outro de backup. Funcionam todos da mesma forma, tendo 7 subrotinas específicas de cada vetor, e uma generalista.
Em todos os casos, retorna 1 em caso de sucesso, -1 em caso de erro total e 0 em caso de sucesso na escrita do
arquivo principal e erro no backup.
OBS: Subrotina generalizada automaticamente roda a subrotina escreve_vetor_tamanhos()
OBS2: Explicação do funcionamento do específico localizada no primeiro do tipo, tal qual o generalista.*/

/*Específico*/
int escreve_vetor_oficina_txt(){
    FILE *p_arquivo=NULL, *p_arquivo_backup=NULL;
    int ver;
    p_arquivo=fopen(".//save//oficina.txt", "w");
    p_arquivo_backup=fopen(".//save//oficina_backup.txt", "w");
    if(p_arquivo==NULL || p_arquivo_backup==NULL){
        if (p_arquivo != NULL) fclose(p_arquivo);
        if (p_arquivo_backup != NULL) fclose(p_arquivo_backup);
        return -1;
    }
    //ver=fprintf(p_arquivo,"%s;%s;%d;%s;%s;%d\n",);
    ver=fprintf(p_arquivo,"%s;%ld;%s;%s;%d;%s;%s;%d;%ld;%s;%f\n",oficina.nome, oficina.cpf_cnpj, oficina.endereco.estado, oficina.endereco.cidade, oficina.endereco.cep, oficina.endereco.bairro, oficina.endereco.rua, oficina.endereco.numero, oficina.telefone, oficina.email, oficina.porcentagemLucro);
    if(ver<0){
        fclose(p_arquivo);
        fclose(p_arquivo_backup);
        return -1;
    }
    ver=fprintf(p_arquivo_backup,"%s;%ld;%s;%s;%d;%s;%s;%d;%ld;%s;%f\n",oficina.nome, oficina.cpf_cnpj, oficina.endereco.estado, oficina.endereco.cidade, oficina.endereco.cep, oficina.endereco.bairro, oficina.endereco.rua, oficina.endereco.numero, oficina.telefone, oficina.email, oficina.porcentagemLucro);
    if(ver<0){
        fclose(p_arquivo);
        fclose(p_arquivo_backup);
        return 0;
    }
    fclose(p_arquivo);
    fclose(p_arquivo_backup);
    return 1;
}

/*Específico*/
int escreve_vetor_cliente_txt(){
    FILE *p_arquivo=NULL, *p_arquivo_backup=NULL;
    int ver;
    p_arquivo=fopen(".//save//vetor_cliente.txt", "w");
    p_arquivo_backup=fopen(".//save//vetor_cliente_backup.txt", "w");
    if(p_arquivo==NULL || p_arquivo_backup==NULL){
        if (p_arquivo != NULL) fclose(p_arquivo);
        if (p_arquivo_backup != NULL) fclose(p_arquivo_backup);
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[1][1];i++){
        ver=fprintf(p_arquivo,"%d;%s;%ld;%s;%s;%d;%s;%s;%d;%ld;%s\n", vetor_cliente[i].codigo, vetor_cliente[i].nome,vetor_cliente[i].cpf_cnpj, vetor_cliente[i].endereco.estado, vetor_cliente[i].endereco.cidade, vetor_cliente[i].endereco.cep, vetor_cliente[i].endereco.bairro, vetor_cliente[i].endereco.rua, vetor_cliente[i].endereco.numero, vetor_cliente[i].telefone, vetor_cliente[i].email);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return -1;
        }
    }
    for(int i=0;i<vetor_tamanhos[1][1];i++){
        ver=fprintf(p_arquivo_backup,"%d;%s;%ld;%s;%s;%d;%s;%s;%d;%ld;%s\n", vetor_cliente[i].codigo, vetor_cliente[i].nome,vetor_cliente[i].cpf_cnpj, vetor_cliente[i].endereco.estado, vetor_cliente[i].endereco.cidade, vetor_cliente[i].endereco.cep, vetor_cliente[i].endereco.bairro, vetor_cliente[i].endereco.rua, vetor_cliente[i].endereco.numero, vetor_cliente[i].telefone, vetor_cliente[i].email);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return 0;
        }
    }
    fclose(p_arquivo);
    fclose(p_arquivo_backup);
    return 1;
}

/*Específico*/
int escreve_vetor_veiculo_txt(){
    FILE *p_arquivo=NULL, *p_arquivo_backup=NULL;
    int ver;
    p_arquivo=fopen(".//save//vetor_veiculo.txt", "w");
    p_arquivo_backup=fopen(".//save//vetor_veiculo_backup.txt", "w");
    if(p_arquivo==NULL || p_arquivo_backup==NULL){
        if (p_arquivo != NULL) fclose(p_arquivo);
        if (p_arquivo_backup != NULL) fclose(p_arquivo_backup);
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[2][1];i++){
        ver=fprintf(p_arquivo,"%s;%s;%s;%d;%s;%d\n",vetor_veiculo[i].placa,vetor_veiculo[i].modelo,vetor_veiculo[i].marca,vetor_veiculo[i].anoFabricacao,vetor_veiculo[i].chassi,vetor_veiculo[i].proprietario);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return -1;
        }
    }
    for(int i=0;i<vetor_tamanhos[2][1];i++){
        ver=fprintf(p_arquivo_backup,"%s;%s;%s;%d;%s;%d\n",vetor_veiculo[i].placa,vetor_veiculo[i].modelo,vetor_veiculo[i].marca,vetor_veiculo[i].anoFabricacao,vetor_veiculo[i].chassi,vetor_veiculo[i].proprietario);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return 0;
        }
    }
    fclose(p_arquivo);
    fclose(p_arquivo_backup);
    return 1;
}

/*Específico*/
int escreve_vetor_peca_txt(){
    FILE *p_arquivo=NULL, *p_arquivo_backup=NULL;
    int ver;
    p_arquivo=fopen(".//save//vetor_peca.txt", "w");
    p_arquivo_backup=fopen(".//save//vetor_peca_backup.txt", "w");
    if(p_arquivo==NULL || p_arquivo_backup==NULL){
        if (p_arquivo != NULL) fclose(p_arquivo);
        if (p_arquivo_backup != NULL) fclose(p_arquivo_backup);
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[3][1];i++){
        ver=fprintf(p_arquivo,"%d;%s;%s;%s;%f;%f;%d;%d\n",vetor_peca[i].codigo,vetor_peca[i].descricao,vetor_peca[i].fabricante,vetor_peca[i].fornecedor,vetor_peca[i].precoCusto,vetor_peca[i].precoVenda,vetor_peca[i].quantidadeEstoque,vetor_peca[i].estoqueMinimo);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return -1;
        }
    }
    for(int i=0;i<vetor_tamanhos[3][1];i++){
        ver=fprintf(p_arquivo_backup,"%d;%s;%s;%s;%f;%f;%d;%d\n",vetor_peca[i].codigo,vetor_peca[i].descricao,vetor_peca[i].fabricante,vetor_peca[i].fornecedor,vetor_peca[i].precoCusto,vetor_peca[i].precoVenda,vetor_peca[i].quantidadeEstoque,vetor_peca[i].estoqueMinimo);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return 0;
        }
    }
    fclose(p_arquivo);
    fclose(p_arquivo_backup);
    return 1;
}

/*Específico*/
int escreve_vetor_fornecedor_txt(){
    FILE *p_arquivo=NULL, *p_arquivo_backup=NULL;
    int ver;
    p_arquivo=fopen(".//save//vetor_fornecedor.txt", "w");
    p_arquivo_backup=fopen(".//save//vetor_fornecedor_backup.txt", "w");
    if(p_arquivo==NULL || p_arquivo_backup==NULL){
        if (p_arquivo != NULL) fclose(p_arquivo);
        if (p_arquivo_backup != NULL) fclose(p_arquivo_backup);
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[4][1];i++){
        ver=fprintf(p_arquivo,"%d;%s;%s;%s;%ld;%s;%s;%d;%s;%s;%d;%ld;%s\n",vetor_fornecedor[i].codigo,vetor_fornecedor[i].nomeFantasia,vetor_fornecedor[i].razaoSocial,vetor_fornecedor[i].inscricaoEstadual,vetor_fornecedor[i].cnpj,vetor_fornecedor[i].endereco.estado,vetor_fornecedor[i].endereco.cidade,vetor_fornecedor[i].endereco.cep,vetor_fornecedor[i].endereco.bairro,vetor_fornecedor[i].endereco.rua, vetor_fornecedor[i].endereco.numero,vetor_fornecedor[i].telefone, vetor_fornecedor[i].email);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return -1;
        }
    }
    for(int i=0;i<vetor_tamanhos[4][1];i++){
        ver=fprintf(p_arquivo,"%d;%s;%s;%s;%ld;%s;%s;%d;%s;%s;%d;%ld;%s\n",vetor_fornecedor[i].codigo,vetor_fornecedor[i].nomeFantasia,vetor_fornecedor[i].razaoSocial,vetor_fornecedor[i].inscricaoEstadual,vetor_fornecedor[i].cnpj,vetor_fornecedor[i].endereco.estado,vetor_fornecedor[i].endereco.cidade,vetor_fornecedor[i].endereco.cep,vetor_fornecedor[i].endereco.bairro,vetor_fornecedor[i].endereco.rua, vetor_fornecedor[i].endereco.numero,vetor_fornecedor[i].telefone, vetor_fornecedor[i].email);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return 0;
        }
    }
    fclose(p_arquivo);
    fclose(p_arquivo_backup);
    return 1;
}

/*Específico*/
int escreve_vetor_servico_txt(){
    FILE *p_arquivo=NULL, *p_arquivo_backup=NULL;
    int ver;
    p_arquivo=fopen(".//save//vetor_servico.txt", "w");
    p_arquivo_backup=fopen(".//save//vetor_servico_backup.txt", "w");
    if(p_arquivo==NULL || p_arquivo_backup==NULL){
        if (p_arquivo != NULL) fclose(p_arquivo);
        if (p_arquivo_backup != NULL) fclose(p_arquivo_backup);
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[5][1];i++){
        ver=fprintf(p_arquivo,"%d;%s;%f;%f\n",vetor_servico[i].codigo,vetor_servico[i].descricao,vetor_servico[i].preco,vetor_servico[i].comissao);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return -1;
        }
    }
    for(int i=0;i<vetor_tamanhos[5][1];i++){
        ver=fprintf(p_arquivo_backup,"%d;%s;%f;%f\n",vetor_servico[i].codigo,vetor_servico[i].descricao,vetor_servico[i].preco,vetor_servico[i].comissao);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return 0;
        }
    }
    fclose(p_arquivo);
    fclose(p_arquivo_backup);
    return 1;
}

/*Específico*/
int escreve_vetor_funcionario_txt(){
    FILE *p_arquivo=NULL, *p_arquivo_backup=NULL;
    int ver;
    p_arquivo=fopen(".//save//vetor_funcionario.txt", "w");
    p_arquivo_backup=fopen(".//save//vetor_funcionario_backup.txt", "w");
    if(p_arquivo==NULL || p_arquivo_backup==NULL){
        if (p_arquivo != NULL) fclose(p_arquivo);
        if (p_arquivo_backup != NULL) fclose(p_arquivo_backup);
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[6][1];i++){
        ver=fprintf(p_arquivo,"%s;%ld;%s;%f\n",vetor_funcionario[i].nome, vetor_funcionario[i].cpf,vetor_funcionario[i].cargo,vetor_funcionario[i].salario);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return -1;
        }
    }
    for(int i=0;i<vetor_tamanhos[6][1];i++){
        ver=fprintf(p_arquivo_backup,"%d;%s;%f;%f\n",vetor_servico[i].codigo,vetor_servico[i].descricao,vetor_servico[i].preco,vetor_servico[i].comissao);
        if(ver<0){
            fclose(p_arquivo);
            fclose(p_arquivo_backup);
            return 0;
        }
    }
    fclose(p_arquivo);
    fclose(p_arquivo_backup);
    return 1;
}

/*Generalizado*/
int escreve_vetores_txt(){
    int final=1, ver=escreve_vetor_tamanhos();
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_oficina_txt();
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_cliente_txt();
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_veiculo_txt();
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_peca_txt();
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_fornecedor_txt();
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_servico_txt();
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_funcionario_txt();
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    return final;
}

//Subrotinas de escrita dos vetores de structs em binário

/*Escreve qualquer vetor na memória persistente em forma de binário. Retorna -1 em caso de erro total, 1 em caso de
sucesso e 0 em caso de sucesso na escrita do arquivo principal e erro no backup.*/
int escreve_vetor_bin(const char* diretorio_o, const char* diretorio_b, void* vetor, size_t tamanho_struct, size_t tamanho_vetor){
    FILE *p_arquivo, *p_arquivo_backup;
    p_arquivo=fopen(diretorio_o, "wb");
    p_arquivo_backup=fopen(diretorio_b, "wb");
    if(p_arquivo==NULL || p_arquivo_backup==NULL){
        if (p_arquivo != NULL) fclose(p_arquivo);
        if (p_arquivo_backup != NULL) fclose(p_arquivo_backup);
        return -1;
    }
    fwrite(vetor,tamanho_struct,tamanho_vetor,p_arquivo);
    if(ferror(p_arquivo)!=0){
        fclose(p_arquivo);
        fclose(p_arquivo_backup);
        return -1;
    }
    fwrite(vetor,tamanho_struct,tamanho_vetor,p_arquivo_backup);
    if(ferror(p_arquivo_backup)!=0){
        fclose(p_arquivo);
        fclose(p_arquivo_backup);
        return 0;
    }
    fclose(p_arquivo);
    fclose(p_arquivo_backup);
    return 1;
}

/*Escreve todos os vetores controlados pelo vetor_tamanhos na memória presistente em forma de binário. Retorna -1 em caso de erro total, 1 em caso de
sucesso e 0 em caso de sucesso na escrita do arquivo principal e erro no backup.
OBS:Automaticamente roda a subrotina escreve_vetor_tamanhos()*/
int escreve_vetores_bin(){
    int final=1, ver=escreve_vetor_tamanhos();
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_bin(".//save//oficina.bin",".//save//oficina_backup.bin",&oficina,sizeof(Dados_Oficina),1);
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_bin(".//save//vetor_cliente.bin",".//save//vetor_cliente_backup.bin",vetor_cliente,sizeof(Cliente),vetor_tamanhos[1][1]);
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_bin(".//save//vetor_veiculo.bin",".//save//vetor_veiculo_backup.bin",vetor_veiculo,sizeof(Veiculo),vetor_tamanhos[2][1]);
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_bin(".//save//vetor_peca.bin",".//save//vetor_peca_backup.bin",vetor_peca,sizeof(Peca),vetor_tamanhos[3][1]);
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_bin(".//save//vetor_fornecedor.bin",".//save//vetor_fornecedor_backup.bin",vetor_fornecedor,sizeof(Fornecedor),vetor_tamanhos[4][1]);
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_bin(".//save//vetor_servico.bin",".//save//vetor_servico_backup.bin",vetor_servico,sizeof(Servico),vetor_tamanhos[5][1]);
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    ver=escreve_vetor_bin(".//save//vetor_funcionario.bin",".//save//vetor_funcionario_backup.bin",vetor_funcionario,sizeof(Funcionario),vetor_tamanhos[6][1]);
    if(ver==-1){
        return -1;
    }else if(ver==0){
        final=0;
    }
    return final;
}

//Subrotinas de leitura dos vetores struct em binário

int le_vetor_bin(const char* diretorio, void* vetor, size_t tamanho_struct, size_t tamanho_vetor){
    FILE *p_arquivo=NULL;
    p_arquivo=fopen(diretorio, "rb");
    if(p_arquivo==NULL){
        return -1;
    }
    fread(vetor, tamanho_struct, tamanho_vetor, p_arquivo);
    if(ferror(p_arquivo)){
        fclose(p_arquivo);
        return -1;
    }
    fclose(p_arquivo);
    return 1;
}

int le_vetores_bin(int operacao){
    switch(operacao){
        case 0:
            if(le_vetor_bin(".//save//oficina.bin", &oficina, sizeof(Dados_Oficina), 1)==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_cliente.bin", vetor_cliente, sizeof(Cliente), vetor_tamanhos[1][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_veiculo.bin", vetor_veiculo, sizeof(Veiculo), vetor_tamanhos[2][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_peca.bin", vetor_peca, sizeof(Peca), vetor_tamanhos[3][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_fornecedor.bin", vetor_fornecedor, sizeof(Fornecedor), vetor_tamanhos[4][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_servico.bin", vetor_servico, sizeof(Servico), vetor_tamanhos[5][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_funcionario.bin", vetor_funcionario, sizeof(Funcionario), vetor_tamanhos[6][1])==-1){
                return -1;
            }
            break;
        case 1:
            if(le_vetor_bin(".//save//oficina_backup.bin", &oficina, sizeof(Dados_Oficina), 1)==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_cliente_backup.bin", vetor_cliente, sizeof(Cliente), vetor_tamanhos[1][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_veiculo_backup.bin", vetor_veiculo, sizeof(Veiculo), vetor_tamanhos[2][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_peca_backup.bin", vetor_peca, sizeof(Peca), vetor_tamanhos[3][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_fornecedor_backup.bin", vetor_fornecedor, sizeof(Fornecedor), vetor_tamanhos[4][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_servico_backup.bin", vetor_servico, sizeof(Servico), vetor_tamanhos[5][1])==-1){
                return -1;
            }
            if(le_vetor_bin(".//save//vetor_funcionario_backup.bin", vetor_funcionario, sizeof(Funcionario), vetor_tamanhos[6][1])==-1){
                return -1;
            }
            break;
        default:
            return -1;
    }
    return 1;
}

//Subrotinas de leitura dos vetores struct em texto

int le_vetor_oficina_txt(int operacao){
    FILE *p_arquivo=NULL;
    char linha[1024];
    switch(operacao){
        case 0:
            p_arquivo=fopen(".//save//oficina.txt", "r");
            break;
        case 1:
            p_arquivo=fopen(".//save//oficina_backup.txt", "r");
            break;
        default:
            return -1;
    }
    if(p_arquivo==NULL){
        return -1;
    }
    fgets(linha, sizeof(linha), p_arquivo);
    linha[strcspn(linha, "\n")] = '\0';
    if(sscanf(linha, "%99[^;];%ld;%2[^;];%29[^;];%d;%29[^;];%49[^;];%d;%ld;%49[^;];%f",
    oficina.nome,
    &oficina.cpf_cnpj,
    oficina.endereco.estado,
    oficina.endereco.cidade,
    &oficina.endereco.cep,
    oficina.endereco.bairro,
    oficina.endereco.rua,
    &oficina.endereco.numero,
    &oficina.telefone,
    oficina.email,
    &oficina.porcentagemLucro)!=11){
        fclose(p_arquivo);
        return -1;
    }
    fclose(p_arquivo);
    return 1;
}

int le_vetor_cliente_txt(int operacao){
    FILE *p_arquivo=NULL;
    char linha[1024];
    switch(operacao){
        case 0:
            p_arquivo=fopen(".//save//vetor_cliente.txt", "r");
            break;
        case 1:
            p_arquivo=fopen(".//save//vetor_cliente_backup.txt", "r");
            break;
        default:
            return -1;
    }
    if(p_arquivo==NULL){
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[1][1];i++){
        fgets(linha, sizeof(linha), p_arquivo);
        linha[strcspn(linha, "\n")] = '\0';
        if(sscanf(linha, "%d;%99[^;];%ld;%2[^;];%29[^;];%d;%29[^;];%49[^;];%d;%ld;%49[^;]",
        &vetor_cliente[i].codigo,
        vetor_cliente[i].nome,
        &vetor_cliente[i].cpf_cnpj,
        vetor_cliente[i].endereco.estado,
        vetor_cliente[i].endereco.cidade,
        &vetor_cliente[i].endereco.cep,
        vetor_cliente[i].endereco.bairro,
        vetor_cliente[i].endereco.rua,
        &vetor_cliente[i].endereco.numero,
        &vetor_cliente[i].telefone,
        vetor_cliente[i].email)!=11){
            fclose(p_arquivo);
            return -1;
        }
    }
    fclose(p_arquivo);
    return 1;
}

int le_vetor_veiculo_txt(int operacao){
    FILE *p_arquivo=NULL;
    char linha[1024];
    switch(operacao){
        case 0:
            p_arquivo=fopen(".//save//vetor_veiculo.txt", "r");
            break;
        case 1:
            p_arquivo=fopen(".//save//vetor_veiculo_backup.txt", "r");
            break;
        default:
            return -1;
    }
    if(p_arquivo==NULL){
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[2][1];i++){
        fgets(linha, sizeof(linha), p_arquivo);
        linha[strcspn(linha, "\n")] = '\0';
        if(sscanf(linha, "%9[^;];%29[^;];%29[^;];%d;%19[^;];%d",
        vetor_veiculo[i].placa,
        vetor_veiculo[i].modelo,
        vetor_veiculo[i].marca,
        &vetor_veiculo[i].anoFabricacao,
        vetor_veiculo[i].chassi,
        &vetor_veiculo[i].proprietario)!=6){
            fclose(p_arquivo);
            return -1;
        }
    }
    fclose(p_arquivo);
    return 1;
}

int le_vetor_peca_txt(int operacao){
    FILE *p_arquivo=NULL;
    char linha[1024];
    switch(operacao){
        case 0:
            p_arquivo=fopen(".//save//vetor_peca.txt", "r");
            break;
        case 1:
            p_arquivo=fopen(".//save//vetor_peca_backup.txt", "r");
            break;
        default:
            return -1;
    }
    if(p_arquivo==NULL){
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[3][1];i++){
        fgets(linha, sizeof(linha), p_arquivo);
        linha[strcspn(linha, "\n")] = '\0';
        if(sscanf(linha, "%d;%99[^;];%49[^;];%49[^;];%f;%f;%d;%d",
        &vetor_peca[i].codigo,
        vetor_peca[i].descricao,
        vetor_peca[i].fabricante,
        vetor_peca[i].fornecedor,
        &vetor_peca[i].precoCusto,
        &vetor_peca[i].precoVenda,
        &vetor_peca[i].quantidadeEstoque,
        &vetor_peca[i].estoqueMinimo)!=8){
            fclose(p_arquivo);
            return -1;
        }
    }
    fclose(p_arquivo);
    return 1;
}

int le_vetor_fornecedor_txt(int operacao){
    FILE *p_arquivo=NULL;
    char linha[1024];
    switch(operacao){
        case 0:
            p_arquivo=fopen(".//save//vetor_fornecedor.txt", "r");
            break;
        case 1:
            p_arquivo=fopen(".//save//vetor_fornecedor_backup.txt", "r");
            break;
        default:
            return -1;
    }
    if(p_arquivo==NULL){
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[4][1];i++){
        fgets(linha, sizeof(linha), p_arquivo);
        linha[strcspn(linha, "\n")] = '\0';
        if(sscanf(linha, "%d;%99[^;];%99[^;];%19[^;];%ld;%2[^;];%29[^;];%d;%29[^;];%49[^;];%d;%ld;%49[^;]",
        &vetor_fornecedor[i].codigo,
        vetor_fornecedor[i].nomeFantasia,
        vetor_fornecedor[i].razaoSocial,
        vetor_fornecedor[i].inscricaoEstadual,
        &vetor_fornecedor[i].cnpj,
        vetor_fornecedor[i].endereco.estado,
        vetor_fornecedor[i].endereco.cidade,
        &vetor_fornecedor[i].endereco.cep,
        vetor_fornecedor[i].endereco.bairro,
        vetor_fornecedor[i].endereco.rua,
        &vetor_fornecedor[i].endereco.numero,
        &vetor_fornecedor[i].telefone,
        vetor_fornecedor[i].email)!=13){
            fclose(p_arquivo);
            return -1;
        }
    }
    fclose(p_arquivo);
    return 1;
}

int le_vetor_servico_txt(int operacao){
    FILE *p_arquivo=NULL;
    char linha[1024];
    switch(operacao){
        case 0:
            p_arquivo=fopen(".//save//vetor_servico.txt", "r");
            break;
        case 1:
            p_arquivo=fopen(".//save//vetor_servico_backup.txt", "r");
            break;
        default:
            return -1;
    }
    if(p_arquivo==NULL){
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[5][1];i++){
        fgets(linha, sizeof(linha), p_arquivo);
        linha[strcspn(linha, "\n")] = '\0';
        if(sscanf(linha, "%d;%99[^;];%f;%f",
        &vetor_servico[i].codigo,
        vetor_servico[i].descricao,
        &vetor_servico[i].preco,
        &vetor_servico[i].comissao)!=4){
            fclose(p_arquivo);
            return -1;
        }
    }
    fclose(p_arquivo);
    return 1;
}

int le_vetor_funcionario_txt(int operacao){
    FILE *p_arquivo=NULL;
    char linha[1024];
    switch(operacao){
        case 0:
            p_arquivo=fopen(".//save//vetor_funcionario.txt", "r");
            break;
        case 1:
            p_arquivo=fopen(".//save//vetor_funcionario_backup.txt", "r");
            break;
        default:
            return -1;
    }
    if(p_arquivo==NULL){
        return -1;
    }
    for(int i=0;i<vetor_tamanhos[6][1];i++){
        fgets(linha, sizeof(linha), p_arquivo);
        linha[strcspn(linha, "\n")] = '\0';
        if(sscanf(linha, "%99[^;];%ld;%49[^;];%f",
        vetor_funcionario[i].nome,
        &vetor_funcionario[i].cpf,
        vetor_funcionario[i].cargo,
        &vetor_funcionario[i].salario)!=4){
            fclose(p_arquivo);
            return -1;
        }
    }
    fclose(p_arquivo);
    return 1;
}

int le_vetores_txt(int operacao){
    if(le_vetor_oficina_txt(operacao)==-1){
        return -1;
    }
    if(le_vetor_cliente_txt(operacao)==-1){
        return -1;
    }
    if(le_vetor_veiculo_txt(operacao)==-1){
        return -1;
    }
    if(le_vetor_peca_txt(operacao)==-1){
        return -1;
    }
    if(le_vetor_fornecedor_txt(operacao)==-1){
        return -1;
    }
    if(le_vetor_servico_txt(operacao)==-1){
        return -1;
    }
    if(le_vetor_funcionario_txt(operacao)==-1){
        return -1;
    }
    return 1;
}

//Subrotinas de procura nos vetores por chave primária

int procura_vetor_cliente(int codigo){
    for(int i=0;i<vetor_tamanhos[1][1];i++){
        if(vetor_cliente[i].codigo==codigo){
            return i;
        }
    }
    return -1;
}

int procura_vetor_veiculo(char* placa){
    for(int i=0;i<vetor_tamanhos[2][1];i++){
        if(strcmp(vetor_veiculo[i].placa, placa)==0){
            return i;
        }
    }
    return -1;
}

int procura_vetor_peca(int codigo){
    for(int i=0;i<vetor_tamanhos[3][1];i++){
        if(vetor_peca[i].codigo==codigo){
            return i;
        }
    }
    return -1;
}

int procura_vetor_fornecedor(int codigo){
    for(int i=0;i<vetor_tamanhos[4][1];i++){
        if(vetor_fornecedor[i].codigo==codigo){
            return i;
        }
    }
    return -1;
}

int procura_vetor_servico(int codigo){
    for(int i=0;i<vetor_tamanhos[5][1];i++){
        if(vetor_servico[i].codigo==codigo){
            return i;
        }
    }
    return -1;
}

int procura_vetor_funcionario(long int cpf){
    for(int i=0;i<vetor_tamanhos[6][1];i++){
        if(vetor_funcionario[i].cpf==cpf){
            return i;
        }
    }
    return -1;
}

void define_codigo_cliente(int posicao){
    int codigo;
    do{
        codigo=rand();
    }while(procura_vetor_cliente(codigo)!=-1);
    vetor_cliente[posicao].codigo=codigo;
    return;
}

void define_codigo_peca(int posicao){
    int codigo;
    do{
        codigo=rand();
    }while(procura_vetor_peca(codigo)!=-1);
    vetor_peca[posicao].codigo=codigo;
    return;
}

void define_codigo_fornecedor(int posicao){
    int codigo;
    do{
        codigo=rand();
    }while(procura_vetor_fornecedor(codigo)!=-1);
    vetor_fornecedor[posicao].codigo=codigo;
    return;
}

void define_codigo_servico(int posicao){
    int codigo;
    do{
        codigo=rand();
    }while(procura_vetor_servico(codigo)!=-1);
    vetor_servico[posicao].codigo=codigo;
    return;
}

void exclui_em_vetor_cliente(int posicao){
    vetor_cliente[posicao]=vetor_cliente[vetor_tamanhos[1][1]-1];
    vetor_tamanhos[1][1]-=1;
    return;
}

void exclui_em_vetor_veiculo(int posicao){
    vetor_veiculo[posicao]=vetor_veiculo[vetor_tamanhos[2][1]-1];
    vetor_tamanhos[2][1]-=1;
    return;
}

void exclui_em_vetor_peca(int posicao){
    vetor_peca[posicao]=vetor_peca[vetor_tamanhos[3][1]-1];
    vetor_tamanhos[3][1]-=1;
    return;
}

void exclui_em_vetor_fornecedor(int posicao){
    vetor_fornecedor[posicao]=vetor_fornecedor[vetor_tamanhos[4][1]-1];
    vetor_tamanhos[4][1]-=1;
    return;
}

void exclui_em_vetor_servico(int posicao){
    vetor_servico[posicao]=vetor_servico[vetor_tamanhos[5][1]-1];
    vetor_tamanhos[5][1]-=1;
    return;
}

void exclui_em_vetor_funcionario(int posicao){
    vetor_funcionario[posicao]=vetor_funcionario[vetor_tamanhos[6][1]-1];
    vetor_tamanhos[6][1]-=1;
    return;
}

int troca_salvamento(int operacao){
    switch(operacao){
        case 0:
            if(escreve_vetores_txt()==-1){
                return -1;
            }
            vetor_tamanhos[0][0]=1;
            remove(".//save//oficina.bin");
            remove(".//save//oficina_backup.bin");
            remove(".//save//vetor_cliente.bin");
            remove(".//save//vetor_cliente_backup.bin");
            remove(".//save//vetor_veiculo.bin");
            remove(".//save//vetor_veiculo_backup.bin");
            remove(".//save//vetor_peca.bin");
            remove(".//save//vetor_peca_backup.bin");
            remove(".//save//vetor_fornecedor.bin");
            remove(".//save//vetor_fornecedor_backup.bin");
            remove(".//save//vetor_servico.bin");
            remove(".//save//vetor_servico_backup.bin");
            remove(".//save//vetor_funcionario.bin");
            remove(".//save//vetor_funcionario_backup.bin");
            break;
        case 1:
            if(escreve_vetores_bin()==-1){
                return -1;
            }
            vetor_tamanhos[0][0]=0;
            remove(".//save//oficina.txt");
            remove(".//save//oficina_backup.txt");
            remove(".//save//vetor_cliente.txt");
            remove(".//save//vetor_cliente_backup.txt");
            remove(".//save//vetor_veiculo.txt");
            remove(".//save//vetor_veiculo_backup.txt");
            remove(".//save//vetor_peca.txt");
            remove(".//save//vetor_peca_backup.txt");
            remove(".//save//vetor_fornecedor.txt");
            remove(".//save//vetor_fornecedor_backup.txt");
            remove(".//save//vetor_servico.txt");
            remove(".//save//vetor_servico_backup.txt");
            remove(".//save//vetor_funcionario.txt");
            remove(".//save//vetor_funcionario_backup.txt");
            break;
        default:
            return -1;
    }
    if(escreve_vetor_tamanhos()==-1){
        return -1;
    }
    return 1;
}

//TO DO:
//-Testar FEITO!
//-Pesquisar sobre variáveis globais externas FEITO!
//-Criar arquivo em formato biblioteca FEITO!
//-Verificar se já está em forma de entregar a equipe FEITO!
//-Concertar escrita em txt capenga FEITO!
//-Criar leitura de arquivos em txt FEITO!
//-Criar treco de apagar subrotinas FEITO!
//-Criar comutação de saves FEITO!
//-Terminar de comentar essa bagaça