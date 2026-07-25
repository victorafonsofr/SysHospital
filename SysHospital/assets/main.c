#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tratamento multiplataforma para o Sleep e Windows API
#ifdef _WIN32
    #ifndef WIN32_LEAN_AND_MEAN
        #define WIN32_LEAN_AND_MEAN
    #endif
    #include <windows.h>
#else
    #include <unistd.h>
#endif

#include "pacientes.h"
#include "atendimentos.h"

#define MAX 50

// Definições de cores ANSI
#define RED       "\x1b[31m"
#define GREEN     "\x1b[32m"
#define YELLOW    "\x1b[33m"
#define BLUE      "\x1b[34m"
#define MAGENTA   "\x1b[35m"
#define CYAN      "\x1b[36m"
#define BOLD      "\x1b[1m"
#define RESET     "\x1b[0m"

// Fundo colorido
#define BG_WHITE  "\x1b[47m"
#define BLACK     "\x1b[30m"

void limparTela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Função de tempo ajustada para funcionar em qualquer SO
void time_sleep(int segundos) {
    #ifdef _WIN32
        Sleep(segundos * 1000); // Windows recebe milissegundos
    #else
        sleep(segundos);        // Linux recebe segundos
    #endif
}

void exibirMenu() {
    limparTela();

    printf(RED BOLD);
    printf("           _ _ _ _ _\n");
    printf("          |         |\n");
    printf("          |         |\n");
    printf("     _ _ _|         |_ _ _\n");
    printf("    |                     |\n");
    printf("    |     @SysHospital    |\n");
    printf("    |_ _ _           _ _ _|\n");
    printf("          |         |\n");
    printf("          |         |\n");
    printf("          |_ _ _ _ _|\n");
    printf(RESET);
    
    time_sleep(1);

    printf("\n" BOLD CYAN "  ------------------------------------------\n" RESET);
    printf(BOLD "              MENU DE GESTAO\n" RESET);
    printf(BOLD CYAN "  ------------------------------------------\n\n" RESET);

    printf(" "BG_WHITE BLACK "[01]" RESET GREEN " Cadastro de pacientes\n" RESET);
    printf(" "BG_WHITE BLACK "[02]" RESET GREEN " Listar pacientes\n" RESET);
    printf(" "BG_WHITE BLACK "[03]" RESET GREEN " Inserir paciente na fila\n" RESET);
    printf(" "BG_WHITE BLACK "[04]" RESET GREEN " Atender proximo paciente\n" RESET);
    printf(" "BG_WHITE BLACK "[05]" RESET GREEN " Exibir fila de atendimentos\n" RESET);
    printf(" "BG_WHITE BLACK "[06]" RESET GREEN " Historico de atendimentos\n" RESET);
    printf(" "BG_WHITE BLACK "[07]" RESET GREEN " Desfazer ultima acao\n" RESET);
    printf(" "BG_WHITE BLACK "[08]" RESET GREEN " Exibir medicos de plantao\n" RESET);
    printf(" "BG_WHITE BLACK "[09]" RESET GREEN " Buscar paciente\n" RESET);
    printf("\n");
    printf(" "BG_WHITE BLACK "[0]" RESET RED " Sair do Sistema\n" RESET);

    printf(BOLD CYAN "\n  ------------------------------------------\n" RESET);
    printf("  >> ");
}

int main() {
    int opcao;

    //variáveis para manipular a inserção em listas
    char nome[MAX], queixa[MAX];

    //Listas e filas de pacientes
    ListaPacientes pacientes = pcria_lista();
    FilaP fila_pacientes = pcria_fila();

    int id_removido = 0; //variavel para indicar qual id foi atendido
    int id = 0; //variavel que seleciona um id da lista de pacientes para adicionar a fila
    int op_fila; //opcao a ser selecionada no menu de insercao na fila


    do {
        exibirMenu();

        if (scanf("%d", &opcao) != 1) { //scanf retorna o tanto de inteiros lidos, nesse caso ou 1 ou 0
            while (getchar() != '\n'); //remove o buffer incorreto digitado (se houver)
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf(YELLOW "\n [i] Redirecionando para Cadastro...\n" RESET);
                time_sleep(1);

                limparTela();

                while(getchar() != '\n'); // consome espaços com salto de linha

                printf(GREEN"[!] Entre com o nome do paciente:\n"RESET);
                printf(">> ");

                fgets(nome, sizeof(nome), stdin);
                nome[strcspn(nome, "\n")] = '\0'; //tira o /n e coloca um terminador nulo

                printf("\n");
                
                printf(GREEN"[!] Entre com a queixa do paciente:\n"RESET);
                printf(">> ");

                fgets(queixa, sizeof(queixa), stdin);
                queixa[strcspn(queixa, "\n")] = '\0'; //tira o /n e coloca um terminador nulo

                printf("\n");

                pinsere_elem(&pacientes, nome, queixa);
                
                break;

            case 2:
                printf(YELLOW "\n [i] Carregando pacientes...\n" RESET);
                time_sleep(1);

                limparTela();

                listar_pacientes(pacientes);

                break;

            case 3:
                printf(YELLOW "\n [i] Carregando menu de insercao...\n" RESET);
                time_sleep(1);

                limparTela();

                listar_pacientes(pacientes);

                printf(GREEN"[i] Selecione o id do paciente a ser inserido na fila:\n"RESET);
                printf(">> ");

                if (scanf("%d", &id) != 1) {
                        printf("[!] Entrada inválida.\n");
                        while (getchar() != '\n');
                        break;
                }

                printf("\n");

                if(push(&fila_pacientes, pacientes, id) == 0){
                    
                    printf(GREEN"[i] Deseja cadastrar um novo paciente?\n (1) sim | (2) nao\n"RESET);
                    printf(">> ");
                    
                    if (scanf("%d", &op_fila) != 1) {
                        printf("[!] Entrada inválida.\n");
                        while (getchar() != '\n');
                        break;
                    }

                    printf("\n");
                    getchar();
                    if(op_fila == 1){
                        
                        printf(GREEN"[!] Entre com o nome do paciente:\n"RESET);
                        printf(">> ");

                        fgets(nome, sizeof(nome), stdin);
                        nome[strcspn(nome, "\n")] = '\0'; //tira o /n e coloca um terminador nulo

                        printf("\n");
                        
                        printf(GREEN"[!] Entre com a queixa do paciente:\n"RESET);
                        printf(">> ");

                        fgets(queixa, sizeof(queixa), stdin);
                        queixa[strcspn(queixa, "\n")] = '\0'; //tira o /n e coloca um terminador nulo

                        printf("\n");

                        pinsere_elem(&pacientes, nome, queixa); //cadastra um novo paciente
                        push_paciente_nao_cadastrado(&fila_pacientes,nome, queixa); //cadastra o paciente na fila
                        
                    
                    }else if(op_fila!=2){
                        printf("[i] Opcao invalida! acesse esse menu novamente para tentar denovo\n");
                    }

                }


                break;

            case 4:    

                printf(YELLOW "\n [i] Chamando proximo paciente...\n" RESET);
                time_sleep(1);

                if(pop(&fila_pacientes, &id_removido)==1) printf("[i] o ID removido foi: %d\n", id_removido);

                break;

            case 5:
                printf(YELLOW "\n [i] Exibindo fila de pacientes...\n" RESET);
                time_sleep(1);

                exibir_fila(fila_pacientes);

                break;

            case 6:
                printf(YELLOW "\n [i] Exibindo lista de prioridade...\n" RESET);
                time_sleep(1);
                break;
            case 7:
                printf(YELLOW "\n [i] Carregando historico de atendimentos...\n" RESET);
                time_sleep(1);
                break;

            case 8:
                printf(YELLOW "\n [i] Desfazendo ultima acao...\n" RESET);
                time_sleep(1);
                limparTela();
                break;

            case 9:
                printf(YELLOW "\n [i] Exibindo medicos de plantao...\n" RESET);
                time_sleep(1);
                break;

            case 10:
                printf(YELLOW "\n [i] Buscando paciente...\n" RESET);
                time_sleep(1);
                break;

            case 0: //fazer sistema que verifica horas
                printf(BOLD "\n Encerrando SysHospital. Tenha um bom dia!\n" RESET);
                time_sleep(1);
                break;
            default:
                printf(RED "\n [!] Opcao invalida. Tente novamente.\n" RESET);
                time_sleep(1);
        }

        if (opcao != 0) {
            printf("\n Pressione Enter para continuar...");

            getchar();
            getchar(); // Aguarda o usuário
        }

    } while (opcao != 0);

    return 0;
}