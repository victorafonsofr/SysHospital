#ifndef PACIENTES_H
#define PACIENTES_H

#define MAX 50
typedef struct paciente* ListaPacientes; //lista de pacientes

struct paciente
{
    int id;
    char nome[MAX];
    char queixa[MAX];
    struct paciente *prox;

};

//lista encadeada simples

ListaPacientes pcria_lista();
int plista_vazia(ListaPacientes lp);
int pinsere_elem(ListaPacientes *lp, char nome[], char queixa[], int *id_atual); // retorna tambem qual o id atual para inserir na fila
int premove_elem(ListaPacientes *lp, int id);
void listar_pacientes(ListaPacientes lp);
struct paciente get_paciente(ListaPacientes lpacientes, int id_atendido);
void busca_paciente(ListaPacientes lp, int id);
void pdestroi_lista(ListaPacientes *lp);

#endif