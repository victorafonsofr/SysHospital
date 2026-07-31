#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "historico_atendimento.h"
#include "atendimentos.h"
#include "pacientes.h"
#include "medicos.h"

#define MAX 50

//LISTA DUPLAMENTE ENCADEADA

struct logHistorico {

    int id_atendimento;

    int id_paciente;
    char nome_paciente[MAX];
    char queixa[MAX];

    int id_medico;
    char nome_medico[MAX];
    char crm[MAX];

    struct logHistorico *ant;
    struct logHistorico *prox;
};

