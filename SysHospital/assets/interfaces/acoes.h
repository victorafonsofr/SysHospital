#ifndef ACOES.H
#define ACOES.H
#include "atendimentos.h"
#include "historico_atendimento.h"

typedef enum tipo_acao{
    cadastrar=1, remover, emprestimo, devolucao 
}tipoacao;

typedef struct acao{
    tipo_acao tipo;
    char isbn[11];
    char titulo[100];
    char autor[100];
    int quantidade;
    char cpf[12];
    char nome[25];
    int prioridade;
    struct acao* prox;
}acao;
acao* criar_pilha();
int pilha_vazia(acao* pilha);
acao* criar_acao(tipoacao tipo,char isbn[],char titulo[],char autor[],int quantidade,char cpf[],char nome[],int prioridade);
void empilhar(acao** pilha, acao* nova);
acao* desempilhar(acao** pilha);
int desfazer_acao(acao** pilha, Livro** lista, user* usuario, fila* prioridade_maxima, fila* prioridade_media, fila* prioridade_minima);


#endif