#ifndef ATENDIMENTOS_H
#define ATENDIMENTOS_H

//fila de pacientes
#include "pacientes.h"
//lista de medicos
#include "medicos.h"

typedef struct filaP *FilaP;

struct filaP{

    struct paciente *ini;
    struct paciente *fim;

};

FilaP pcria_fila();
int pfila_vazia(FilaP fp);
int dequeue(FilaP *fp,ListaCmedicos medicos, int *id);
int queue_paciente_nao_cadastrado(FilaP *fp , char nome[], char queixa[]);
int queue(FilaP *fp, ListaPacientes paciente,int id);
void exibir_fila(FilaP fp);

#endif // ATENDIMENTOS_H