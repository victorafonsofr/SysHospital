#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pacientes.h"

#define MAX 50

struct  paciente
{
    int id;
    char nome[MAX];
    char queixa[MAX];
    struct paciente *prox;

};

static int proximo_id = 1;

ListaPacientes pcria_lista(){
    
    return NULL;

}

int plista_vazia(ListaPacientes lp){

    if(lp == NULL) return 1;
    
    return 0;

}

int pinsere_elem(ListaPacientes *lp, char nome[50], char queixa[50]){
    
    ListaPacientes novo_paciente = (ListaPacientes) malloc(sizeof(struct paciente));

    if(novo_paciente == NULL) return 0;
    
    novo_paciente->id = proximo_id;
        proximo_id++; //auto incremento para facilitar remoção por id
    
    strncpy(novo_paciente->nome, nome, 49);
    novo_paciente->nome[49] = '\0';
    
    strncpy(novo_paciente->queixa, queixa, 49);
    novo_paciente->queixa[49] = '\0';

    //inserção no começo

    novo_paciente->prox = *lp;
    *lp = novo_paciente;

    printf("[i] Paciente inserido com sucesso!\n");

    return 1;

}

int premove_elem(ListaPacientes *lp, int id){

    if(plista_vazia) return 0;

    ListaPacientes aux = *lp; //ponteiro auxiliar para caminhar na memoria

    if(aux->id == id){ // se a primeira posição for quem eu quero remover

        *lp = (*lp)->prox->prox;
        free(aux);
        
        return 1;

    }

    while(aux->prox != NULL && aux->prox->id != id)
        aux = aux->prox; // caminhar pela lista sem perder a ref principal
    
    if(aux->prox == NULL){
        printf("[!] Não existe paciente a ser removido! [!]\n");
        return 0;
    }
    
    ListaPacientes aux2 = aux->prox;
    aux->prox = aux->prox->prox;
    free(aux2);

    return 1;

}