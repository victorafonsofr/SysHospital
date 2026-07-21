#include <stdio.h>
#include <stdlib.h>

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

void time_sleep(int segundos){

    #ifdef _WIN32
        #include <windows.h>
        Sleep(segundos*1000);

    #else
        #include <unistd.h>
        sleep(segundos);
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
    printf(" "BG_WHITE BLACK "[06]" RESET GREEN " Exibir fila de prioridade\n" RESET);
    printf(" "BG_WHITE BLACK "[07]" RESET GREEN " Histórico de antedimentos\n" RESET);
    printf(" "BG_WHITE BLACK "[08]" RESET GREEN " Desfazer ultima acao\n" RESET);
    printf(" "BG_WHITE BLACK "[09]" RESET GREEN " Exibir medicos de plantao\n" RESET);
    printf(" "BG_WHITE BLACK "[10]" RESET GREEN " Buscar paciente\n" RESET);
    printf("\n");
    printf(" "BG_WHITE BLACK "[0]" RESET RED " Sair do Sistema\n" RESET);

    printf(BOLD CYAN "\n  ------------------------------------------\n" RESET);
    printf("  >> ");
}

int main() {
    int opcao;

    do {
        exibirMenu();

        if (scanf("%d", &opcao) != 1) { //scanf retorna o tanto de inteiros lidos, nesse caso ou 1 ou 0
            while (getchar() != '\n'); //remove o buffer incorreto digitado (se houver)
            opcao = -1;
        }

        switch (opcao) {
            case 1:
                printf(YELLOW "\n [i] Redirecionando para Cadastro...\n" RESET);
                time_sleep(2);
                break;

            case 2:
                printf(YELLOW "\n [i] Carregando pacientes...\n" RESET);
                time_sleep(2);
                break;

            case 3:
                printf(YELLOW "\n [i] Carregando menu de insercao...\n" RESET);
                time_sleep(2);
                break;

            case 4:
                printf(YELLOW "\n [i] Chamando proximo paciente...\n" RESET);
                time_sleep(2);
                break;

            case 5:
                printf(YELLOW "\n [i] Exibindo fila de pacientes...\n" RESET);
                time_sleep(2);
                break;

            case 6:
                printf(YELLOW "\n [i] Exibindo lista de prioridade...\n" RESET);
                time_sleep(2);
                break;
            case 7:
                printf(YELLOW "\n [i] Carregando historico de atendimentos...\n" RESET);
                time_sleep(2);
                break;

            case 8:
                printf(YELLOW "\n [i] Desfazendo ultima acao...\n" RESET);
                time_sleep(1);
                limparTela();
                break;

            case 9:
                printf(YELLOW "\n [i] Exibindo medicos de plantao...\n" RESET);
                time_sleep(2);
                break;

            case 10:
                printf(YELLOW "\n [i] Buscando paciente...\n" RESET);
                time_sleep(2);
                break;

            case 0: //fazer sistema que verifica horas
                printf(BOLD "\n Encerrando SysHospital. Tenha um bom dia!\n" RESET);
                time_sleep(2);
                break;
            default:
                printf(RED "\n [!] Opcao invalida. Tente novamente.\n" RESET);
                time_sleep(2);
        }

        if (opcao != 0) {
            printf("\n Pressione Enter para continuar...");
            getchar(); // Limpa o buffer do scanf
            getchar(); // Aguarda o usuário
        }

    } while (opcao != 0);

    return 0;
}