typedef struct medico *ListaCmedicos;

ListaCmedicos mcria_lista();
ListaCmedicos atualiza_plantao(ListaCmedicos medicos);
int mlista_vazia(ListaCmedicos lst);
int minsere_elem(ListaCmedicos *lst, char nome[], char crm[]);
int mremove_elem(ListaCmedicos *lst, int id);
void mimprime_lista(ListaCmedicos lst);
int troca_plantao(ListaCmedicos *plantao, int *cont);
void medico_plantao(ListaCmedicos plantao);