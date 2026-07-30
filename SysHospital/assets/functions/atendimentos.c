#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "atendimentos.h"
#include "pacientes.h"
#include "medicos.h"

#define MAX 50

struct paciente
{
    int id;
    char nome[MAX];
    char queixa[MAX];
    struct paciente *prox;

};

static int proximo_id = 1;

struct filaP{

    struct paciente *ini;
    struct paciente *fim;

};

FilaP pcria_fila(){

    FilaP temp = (FilaP) malloc(sizeof(struct filaP));

    if(temp){
        temp->ini = NULL;
        temp->fim = NULL;
    }else
        return NULL;
    
    return temp;

}

int pfila_vazia(FilaP fp){

    if(fp->ini == NULL)
        return 1;
    
    return 0;

}

int push(FilaP *fp, ListaPacientes paciente, int id){
    //insere na fila um paciente que já está cadastrado
    if(plista_vazia(paciente)) return 0;

    //ponteiro aux para encontrar o paciente com a id do parametro
    ListaPacientes aux = paciente;

    while(aux != NULL && aux->id != id)
        aux = aux->prox;
    
    if(aux == NULL){
        printf("[!] Paciente nao foi cadastrado!\n");
        return 0;
    }
    //paciente a ser inserido foi encontrado

    //criando novo nó para a fila
    ListaPacientes novo_p_fila = (ListaPacientes) malloc(sizeof(struct paciente));

    if(novo_p_fila == NULL){
        printf("[!] Nao foi possivel cadastrar o paciente na lista!\n");
        return 0;
    }

    novo_p_fila->id = aux->id;

    //preenchendo nome
    strncpy(novo_p_fila->nome, aux->nome, 49);
    novo_p_fila->nome[49] = '\0';
    
    //preenchendo queixa
    strncpy(novo_p_fila->queixa, aux->queixa, 49);
    novo_p_fila->queixa[49] = '\0';

    //preenchendo campo prox do final da lista, que é sempre nulo
    novo_p_fila->prox = NULL;

    if(pfila_vazia(*fp)){ //lista vazia

        (*fp)->ini = novo_p_fila;
        (*fp)->fim = novo_p_fila;
        
        
    }else{

        (*fp)->fim->prox = novo_p_fila;
        (*fp)->fim = novo_p_fila;

    }

    printf("[!] Paciente inserido na fila de atendimento!\n");
    return 1;

}

int push_paciente_nao_cadastrado(FilaP *fp, char nome[MAX] ,char queixa[MAX] ){ //inserção sempre no final pois é fila, necessário verificar se a lista é vazia

    if(fp == NULL || *fp == NULL){
        printf("[i] a fila selecionada nao existe\n");
        return 0;
    }

    ListaPacientes novo_p_fila = (ListaPacientes) malloc(sizeof(struct paciente));

    if(novo_p_fila == NULL) return 0;

    //preenchendo ID
    novo_p_fila->id = proximo_id;
    proximo_id++;

    //preenchendo nome
    strncpy(novo_p_fila->nome, nome, 49);
    novo_p_fila->nome[49] = '\0';
    
    //preenchendo queixa
    strncpy(novo_p_fila->queixa, queixa, 49);
    novo_p_fila->queixa[49] = '\0';

    //preenchendo campo prox do final da lista, que é sempre nulo
    novo_p_fila->prox = NULL;

    if(pfila_vazia(*fp)){ //lista vazia

        (*fp)->ini = novo_p_fila;
        (*fp)->fim = novo_p_fila;
        
        
    }else{

        (*fp)->fim->prox = novo_p_fila;
        (*fp)->fim = novo_p_fila;

    }

    return 1;

}

int pop(FilaP *fp, ListaCmedicos medicos, int *id){ //remoção sempre no inicio

    if(pfila_vazia(*fp)){
        printf("[!] A fila de pacientes está vazia, nada a remover por aqui!\n");
        return 0;
    }

    if(mlista_vazia(medicos)){ // existem medicos para atender o paciente?
        
        printf("[!] Nao e possivel atender, nao ha medicos de plantao!\n");
        return 0;
    }

    *id = (*fp)->ini->id; // id de quem foi removido

    ListaPacientes aux = (*fp)->ini;
    (*fp)->ini = (*fp)->ini->prox;
    
    if(pfila_vazia(*fp)) (*fp)->fim = NULL; //se a lista ficar vazia depois que o elemento foi removido, automaticamente define o fim como nulo também

    printf("[i] paciente %s foi atendido!\n", aux->nome);
    printf("[i] paciente %s foi removido da fila de atendimento com sucesso!\n", aux->nome);
    

    free(aux);

    return 1;

}

void exibir_fila(FilaP fp){

    if(pfila_vazia(fp))
        printf("[!] Nao ha pacientes na fila de atendimento\n");

    else{

        ListaPacientes aux = fp->ini;
        int i = 0;
        
        while(aux!=NULL){
           
            if (aux == fp->ini) printf("[%d] ID: %d | paciente: %s\t(proximo a ser atendido)\n",i+1, aux->id, aux->nome);

            else{
                printf("[%d] ID: %d | paciente: %s\n",i+1, aux->id, aux->nome);
            }

            aux = aux->prox;
            i++;

        }

    }
}