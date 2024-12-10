#ifndef _ARQUIVOS_H
#define _ARQUIVOS_H
#include "estruturas.h"
#define qtdvet 7 //Refere-se principalmente a quantidade de vetores de Struct presentes no programa

extern int vetor_tamanhos[qtdvet][2];
extern Dados_Oficina oficina;
extern Cliente *vetor_cliente;
extern Veiculo *vetor_veiculo;
extern Peca *vetor_peca;
extern Fornecedor *vetor_fornecedor;
extern Servico *vetor_servico;
extern Funcionario *vetor_funcionario;

void inicia_vetor_tamanhos();
int inicia_vetor_estruturas();
void finaliza_vetor_estruturas();
void* realoca_vetor(void*,size_t,size_t,int);
void realoca_vetores();
int escreve_vetor_tamanhos();
int le_vetor_tamanhos(int);
int escreve_vetor_oficina_txt();
int escreve_vetor_cliente_txt();
int escreve_vetor_veiculo_txt();
int escreve_vetor_peca_txt();
int escreve_vetor_fornecedor_txt();
int escreve_vetor_servico_txt();
int escreve_vetor_funcionario_txt();
int escreve_vetores_txt();
int escreve_vetor_bin(const char*,const char*,void*,size_t,size_t);
int escreve_vetores_bin();
int le_vetor_bin(const char*,void*,size_t,size_t);
int le_vetores_bin(int);
int le_vetor_oficina_txt(int);
int le_vetor_cliente_txt(int);
int le_vetor_veiculo_txt(int);
int le_vetor_peca_txt(int);
int le_vetor_fornecedor_txt(int);
int le_vetor_servico_txt(int);
int le_vetor_funcionario_txt(int);
int le_vetores_txt(int);
int procura_vetor_cliente(int);
int procura_vetor_veiculo(char*);
int procura_vetor_peca(int);
int procura_vetor_fornecedor(int);
int procura_vetor_servico(int);
int procura_vetor_funcionario(long int);
void define_codigo_cliente(int);
void define_codigo_peca(int);
void define_codigo_fornecedor(int);
void define_codigo_servico(int);
void exclui_em_vetor_cliente(int);
void exclui_em_vetor_veiculo(int);
void exclui_em_vetor_peca(int);
void exclui_em_vetor_fornecedor(int);
void exclui_em_vetor_servico(int);
void exclui_em_vetor_funcionario(int);
int troca_salvamento(int);

#endif