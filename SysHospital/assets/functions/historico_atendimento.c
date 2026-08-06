#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "historico_atendimento.h"
//LISTA DUPLAMENTE ENCADEADA

static int proximo_id = 1;

void limparTelaInterno() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

Historico_atendimento criar_historico(){
    return NULL;
}

int hlista_vazia(Historico_atendimento historico){
    if(historico == NULL) return 1;
    return 0;
}

int insere_item_historico(Historico_atendimento *historico, struct paciente pac, struct medico med, int *id_hist){

    Historico_atendimento novo_item = (Historico_atendimento) malloc(sizeof(struct logHistorico));

    if(novo_item == NULL) return 0;

    novo_item->id_historico = proximo_id;
    proximo_id++;

    novo_item->id_paciente = pac.id;
    
    //preenchendo o nome e a queixa
    strncpy(novo_item->nome_paciente, pac.nome, 49);
    novo_item->nome_paciente[49] = '\0';
    
    strncpy(novo_item->queixa, pac.queixa, 49);
    novo_item->queixa[49] = '\0';

    novo_item->id_medico = med.id_medico;

    //preenchendo o nome do medico e crm
    strncpy(novo_item->nome_medico, med.nome, 49);
    novo_item->nome_medico[49] = '\0';
    
    strncpy(novo_item->crm, med.crm, 49);
    novo_item->crm[49] = '\0';

    if(hlista_vazia(*historico)){

        *historico = novo_item;
        (*historico)->ant = NULL;
        (*historico)->prox = NULL;

    }else{

        novo_item->prox = (*historico);
        novo_item->ant = NULL;
        (*historico)->ant = novo_item;
        *historico = novo_item;

    }

    *id_hist = novo_item->id_historico;

    //sucesso ao inserir no historico, retorna o id o historico
    return 1;

}

void mostrar_historico(Historico_atendimento historico){

    if(hlista_vazia(historico)){
        printf("[!] Nao houve nenhum atendimento! Portanto, nao ha nada a mostrar por aqui.\n");
    } else {
        char comando = 'a';
        Historico_atendimento aux = historico;

        while(tolower(comando) != 's'){
            limparTelaInterno();
            printf("[< Para percorrer o historico: tecla A para a esquerda | tecla D para direita >]\n[Para sair, digite 'S']\n\n");
            
            printf("Dados do registro [%d]\n", aux->id_historico);
            printf("\tID do paciente: [%d] | nome do paciente: %s\n", aux->id_paciente, aux->nome_paciente);
            printf("\tID do medico: [%d] | CRM: %s | nome do medico: Dr. %s\n", aux->id_medico, aux->crm, aux->nome_medico);
            printf("\n\tQueixa tratada: %s\n", aux->queixa);

            printf(" >> ");
            scanf(" %c", &comando);
            printf("\n");

            if(tolower(comando) == 'a'){

                if(aux->ant != NULL){
                    aux = aux->ant;
                } else {
                    printf("[i] Voce ja esta no comeco! (pressione ENTER para continuar)\n");
                    getchar(); // Limpa o '\n' do scanf
                    getchar(); // Pausa para leitura
                }

            } else if(tolower(comando) == 'd'){

                if(aux->prox != NULL){
                    aux = aux->prox;
                } else {
                    printf("[i] Voce chegou ao fim! (pressione ENTER para continuar)\n");
                    getchar(); // Limpa o '\n' do scanf
                    getchar(); // Pausa para leitura
                }

            } else if(tolower(comando) == 's'){
                printf("[i] Saindo do historico...\n");
                
            } else {
                printf("[!] Operacao invalida! (pressione ENTER para continuar)\n");
                getchar(); // Limpa o '\n' do scanf
                getchar(); // Pausa para o usuário ler a mensagem de erro
            }
        }
    }
}

int hremove_elem(Historico_atendimento *historico, int id_historico){

    if(hlista_vazia(*historico)) return 0;

    Historico_atendimento aux = *historico;

    //procura o registro pelo id_historico
    while(aux != NULL && aux->id_historico != id_historico)
        aux = aux->prox;

    if(aux == NULL){
        printf("[!] Nao existe registro de historico com esse id!\n");
        return 0;
    }

    if(aux->ant != NULL)
        aux->ant->prox = aux->prox;
    else
        *historico = aux->prox;

    if(aux->prox != NULL)
        aux->prox->ant = aux->ant;

    free(aux);

    return 1;
}

void destroi_historico(Historico_atendimento *historico)
{
    if (historico == NULL) {
        return;
    }

    Historico_atendimento atual = *historico;

    while (atual != NULL) {
        Historico_atendimento proximo = atual->prox;

        free(atual);

        atual = proximo;
    }

    *historico = NULL;
}