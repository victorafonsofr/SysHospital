#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "medicos.h"
#define MAX 50

struct medico{

    int id_medico;
    char nome[MAX];
    char crm[MAX];
    struct medico *prox;

};

static int proximo_id = 1;

ListaCmedicos mcria_lista(){

    return NULL;

}

int mlista_vazia(ListaCmedicos lst){
    if(lst == NULL) return 1;

    return 0;
}

int minsere_elem(ListaCmedicos *lst, char nome[MAX], char crm[MAX]){

    ListaCmedicos novo_medico = (ListaCmedicos) malloc(sizeof(struct medico));

    if(novo_medico == NULL) return 0;

    novo_medico->id_medico = proximo_id;
        proximo_id++; //auto incremento para facilitar remoção por id
    
    strncpy(novo_medico->nome, nome, 49);
    novo_medico->nome[49] = '\0';
    
    strncpy(novo_medico->crm, crm, 49);
    novo_medico->crm[49] = '\0';

    //inserção no final circular
    //*lst é o ultimo

    if (mlista_vazia(*lst)) {
        novo_medico->prox = novo_medico;
        *lst = novo_medico;
    }else{

        novo_medico->prox = (*lst)->prox; //aponta para o primeiro no
        (*lst)->prox = novo_medico;
        (*lst) = novo_medico;
    
    }

    return 1;

}

int mremove_elem(ListaCmedicos *lst, int id_medico){

    if(mlista_vazia(*lst)) return 0;

    ListaCmedicos aux = (*lst)->prox;
    ListaCmedicos primeiro = aux;
    
    if(primeiro == *lst){ //se a lista so tem um no

        if(primeiro->id_medico!= id_medico){    
            printf("[!] Nenhum medico registrado!\n");
            return 0; // o elemento nao esta na lista
        }

        free(primeiro);
        *lst = NULL;

    printf("[i] Medico inserido com sucesso!\n");

        return 1;
    }

    while(aux->prox!=primeiro && aux->prox->id_medico != id_medico)
        aux = aux->prox;

    if(aux->prox == primeiro){   //elem nao encontrado
            printf("[!] Nenhum medico registrado!\n");
            return 0; // o elemento nao esta na lista
        } 

        ListaCmedicos temp = aux->prox;

        if (temp == *lst) *lst = aux;

        aux->prox = temp->prox;
        free(temp);


    return 1;

}

void mimprime_lista(ListaCmedicos lst){
    
    if(mlista_vazia(lst)){
        printf("[!] Nenhum medico registrado!\n");
    }
    else{

        ListaCmedicos aux = lst->prox;
        int i = 0;
        do{
            printf("\t[%d] ID do medico: %d | medico: Dr. %s | CRM: %s\n",i+1, aux->id_medico, aux->nome, aux->crm);
            aux = aux->prox;
            i++;
        }while(aux != lst->prox);
            
        printf("\n");

    }
}

int troca_plantao(ListaCmedicos *plantao, int *cont){

    if(mlista_vazia(*plantao)){

        printf("[!] Nenhum medico registrado!\n");
        return 0;

    }

    (*cont)++;
    
    if(*cont >= 2){

        *plantao = (*plantao)->prox;
        *cont = 0;

        printf("[i] Plantao alterado!\n");
        printf("[i] Medico atual: Dr. %s\n", (*plantao)->nome);

    }

    return 1;

}

void medico_plantao(ListaCmedicos plantao){

    if(mlista_vazia(plantao)){

        printf(" [!] Nenhum medico registrado!\n");
    }else{

        printf("\n -> Medico atual em plantao: Dr. %s\n", plantao->nome);

    }

}

ListaCmedicos atualiza_plantao(ListaCmedicos medicos){

    ListaCmedicos plantao  = medicos->prox;

    return plantao;
}

struct medico get_medico(ListaCmedicos plantao){

    return *plantao;

}