#ifndef STRUCTS_H
#define STRUCTS_H

#include "estruturas.h"

void obterDataAtual(char* data);

void registrarTransacao(Caixa* caixa, const char* descricao, float valor, char tipo);

void adicionarContaPagar(Caixa* caixa, ContaPagar conta);

void adicionarContaReceber(Caixa* caixa, ContaReceber conta, char forma_pagamento, const char* prazo);

void baixarContaPagar(Caixa* caixa, int id);

void baixarContaReceber(Caixa* caixa, int id);

void exibirRelatorio(const Caixa* caixa);

void liberarCaixa(Caixa* caixa);

void financeiro();

#endif
