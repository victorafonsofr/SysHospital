#ifndef ACOES_H
#define ACOES_H

#include "atendimentos.h"
#include "historico_atendimento.h"

typedef struct acao *Acao;

typedef enum tipo_acao{
    cadastrarP, inserir_fila, insere_historico, atender_pac, cadastrarM 
}tipo_acao;

struct acao{
    tipo_acao tipo;

    int id_paciente;
    char nome_paciente[MAX];
    char queixa[MAX];
    
    int id_medico;
    char nome_medico[MAX];
    char crm[MAX];

    int id_historico;

    struct acao* prox;
};

Acao criar_pilha();
int pilha_vazia(Acao pilha);
Acao criar_acao(tipo_acao tipo, int id_paciente,char nome_paciente[],char queixa[],int id_medico,char nome_medico[],char crm[],int id_historico);
void push(Acao* pilha, Acao nova);
int desfazer_operacao(Acao* pilha, ListaPacientes *listaP, FilaP *filaP, ListaCmedicos *listamed, Historico_atendimento *hist);
int pop(Acao *pilha);
int remove_ultimapos_fila(FilaP *fila);
int queue_prioridade(FilaP *fp, ListaPacientes paciente, int id);

#endif