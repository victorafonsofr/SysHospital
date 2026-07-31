typedef struct logHistorico *Historico_atendimento;

Historico_atendimento criar_historico();
int hlista_vazia(Historico_atendimento historico);
int insere_item_historico(Historico_atendimento *historico);
//nao é possivel remover item do historico por conta de politicas fictícias de segurança de pacientes
