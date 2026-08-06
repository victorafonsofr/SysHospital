#ifndef MEDICOS_H
#define MEDICOS_H

#define MAX 50

typedef struct medico *ListaCmedicos;

struct medico{

    int id_medico;
    char nome[MAX];
    char crm[MAX];
    struct medico *prox;

};

ListaCmedicos mcria_lista();
ListaCmedicos atualiza_plantao(ListaCmedicos medicos);
int mlista_vazia(ListaCmedicos lst);
int minsere_elem(ListaCmedicos *lst, char nome[], char crm[]);
int mremove_elem(ListaCmedicos *lst, int id);
void mimprime_lista(ListaCmedicos lst);
int troca_plantao(ListaCmedicos *plantao, int *cont);
void medico_plantao(ListaCmedicos plantao);
struct medico get_medico(ListaCmedicos plantao);
void mdestroi_lista(ListaCmedicos *lista);

#endif // MEDICOS_H