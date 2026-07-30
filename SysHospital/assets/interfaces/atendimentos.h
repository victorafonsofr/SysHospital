//fila de pacientes
#include "pacientes.h"
//lista de medicos
#include "medicos.h"

typedef struct filaP *FilaP;

FilaP pcria_fila();
int pfila_vazia(FilaP fp);
int pop(FilaP *fp,ListaCmedicos medicos, int *id);
int push_paciente_nao_cadastrado(FilaP *fp , char nome[], char queixa[]);
int push(FilaP *fp, ListaPacientes paciente,int id);
void exibir_fila(FilaP fp);
