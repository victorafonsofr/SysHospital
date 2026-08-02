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
int pinsere_elem(ListaPacientes *lp, char nome[], char queixa[]);
int premove_elem(ListaPacientes *lp, int id);
void listar_pacientes(ListaPacientes lp);
struct paciente get_paciente(ListaPacientes lpacientes, int id_atendido);

#endif