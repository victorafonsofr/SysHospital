#include "pacientes.h"
#include "medicos.h"

typedef struct logHistorico *Historico_atendimento;

struct logHistorico {

    struct logHistorico *ant;

    int id_historico;

    int id_paciente;
    char nome_paciente[MAX];
    char queixa[MAX];

    int id_medico;
    char nome_medico[MAX];
    char crm[MAX];

    
    struct logHistorico *prox;
};

Historico_atendimento criar_historico();
int hlista_vazia(Historico_atendimento historico);
int insere_item_historico(Historico_atendimento *historico, struct paciente pac, struct medico med);
//nao é possivel remover item do historico por conta de politicas fictícias de segurança de pacientes
void mostrar_historico(Historico_atendimento historico);
int hremove_elem(Historico_atendimento *historico, int id_historico);