typedef struct paciente* ListaPacientes; //lista de pacientes

//lista encadeada simples

ListaPacientes pcria_lista();
int plista_vazia(ListaPacientes lp);
int pinsere_elem(ListaPacientes *lp, char nome[], char queixa[]);
int premove_elem(ListaPacientes *lp, int id);
void listar_pacientes(ListaPacientes lp);