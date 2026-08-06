#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "acoes.h"

Acao criar_pilha(){

    return NULL;

}

int pilha_vazia(Acao pilha){

    if(pilha == NULL) return 1;
    return 0;

}

Acao criar_acao(tipo_acao tipo, int id_paciente,char nome_paciente[],char queixa[],int id_medico,char nome_medico[],char crm[],int id_historico){

    Acao nova_acao = (Acao) malloc(sizeof(struct acao));

    if(nova_acao == NULL){
        printf("[!] Nao foi possivel registrar a acao.\n");
        return 0;
    }

    nova_acao->tipo = tipo;
    nova_acao->id_paciente = id_paciente;
    
    strncpy(nova_acao->nome_paciente, nome_paciente, 49);
    nova_acao->nome_paciente[49] = '\0';

    strncpy(nova_acao->queixa, queixa, 49);
    nova_acao->queixa[49] = '\0';

    nova_acao->id_medico = id_medico;

    strncpy(nova_acao->nome_medico, nome_medico, 49);
    nova_acao->nome_medico[49] = '\0';
    
    strncpy(nova_acao->crm, crm, 49);
    nova_acao->crm[49] = '\0';

    nova_acao->id_historico = id_historico;

    nova_acao->prox = NULL;

    return nova_acao;

}

void push(Acao* pilha, Acao nova){
    
    if(pilha == NULL || nova == NULL)
    return;

    nova->prox = *pilha;
    *pilha = nova;

}

int desfazer_operacao(Acao* pilha, ListaPacientes *listaP, FilaP *filaP, ListaCmedicos *listamed, Historico_atendimento *hist ){

    if(pilha == NULL || pilha_vazia(*pilha)){
        printf("[!] Nenhuma alteracao para desfazer!\n");
        return 0;
    }

    switch ((*pilha)->tipo){
        case cadastrarP:
            return premove_elem(listaP, (*pilha)->id_paciente);

        case inserir_fila:
            return remove_ultimapos_fila(filaP);

        case insere_historico:
            return hremove_elem(hist, (*pilha)->id_historico);

        case atender_pac:
            /* Um atendimento altera a fila e o historico. */
            if(!queue_prioridade(filaP, *listaP, (*pilha)->id_paciente))
                return 0;
            return hremove_elem(hist, (*pilha)->id_historico);

        case cadastrarM:
            return mremove_elem(listamed, (*pilha)->id_medico);

        default:
            printf("[!] Operacao invalida!\n");
            return 0;
    }
}

int remove_ultimapos_fila(FilaP *fila){

    if(fila == NULL || *fila == NULL || pfila_vazia(*fila)){
        printf("[!] Fila vazia ou invalida!\n");
        return 0;
    }

    ListaPacientes aux = (*fila)->ini;

    // Caso a fila tenha apenas um elemento
    if(aux == (*fila)->fim){

        free(aux);

        (*fila)->ini = NULL;
        (*fila)->fim = NULL;

        return 1;
    }

    // Procura o penúltimo elemento
    while(aux->prox != (*fila)->fim){
        aux = aux->prox;
    }

    // aux = penúltimo
    free((*fila)->fim);

    aux->prox = NULL;
    (*fila)->fim = aux;

    return 1;

}

int queue_prioridade(FilaP *fp, ListaPacientes paciente, int id){

    if(fp == NULL || *fp == NULL || plista_vazia(paciente)) return 0;

    ListaPacientes aux = paciente;

    while(aux != NULL && aux->id != id)
        aux = aux->prox;

    if(aux == NULL){
        printf("[!] Paciente nao foi cadastrado!\n");
        return 0;
    }

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

    if(pfila_vazia(*fp)){ //fila vazia: o novo nó é ao mesmo tempo inicio e fim

        novo_p_fila->prox = NULL;
        (*fp)->ini = novo_p_fila;
        (*fp)->fim = novo_p_fila;

    }else{ //insere antes do antigo inicio, viram o novo "primeiro da fila"

        novo_p_fila->prox = (*fp)->ini;
        (*fp)->ini = novo_p_fila;

    }
    return 1;

}

int pop(Acao *pilha){

    if(pilha == NULL || pilha_vazia(*pilha)){ //nada a remover!
        printf("[!] Nao ha nenhuma acao a ser desfeita!\n");
        return 0;
    }

    Acao aux = *pilha;

    *pilha = (*pilha)->prox;
    free(aux);

    printf("[i] Ultima alteracao desfeita com sucesso!\n");

    return 1;
}

void destruir_pilha(Acao *pilha)
{
    if (pilha == NULL) {
        return;
    }

    Acao atual = *pilha;

    while (atual != NULL) {
        Acao proxima = atual->prox;

        free(atual);

        atual = proxima;
    }

    *pilha = NULL;
};