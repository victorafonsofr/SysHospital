# SysHospital

Sistema hospitalar desenvolvido em linguagem C para aplicar, de forma integrada, estruturas de dados estudadas na disciplina de **Estrutura de Dados I**.

O projeto simula operações básicas do atendimento hospitalar em uma interface de terminal, permitindo organizar pacientes, médicos, filas de atendimento, histórico de consultas e ações que podem ser desfeitas.

> **Status:** projeto acadêmico em desenvolvimento.

## Funcionalidades

- Cadastro e listagem de pacientes;
- cadastro e gerenciamento de médicos;
- organização de pacientes em uma fila de atendimento;
- rotação de médicos disponíveis no plantão;
- registro do histórico de atendimentos;
- navegação pelos registros do histórico;
- armazenamento e reversão de ações realizadas no sistema;
- liberação da memória utilizada pelas estruturas dinâmicas.

## Estruturas de dados

Cada módulo utiliza uma estrutura de dados de acordo com a operação que representa no sistema:

| Estrutura | Aplicação no sistema | Módulo |
|---|---|---|
| Lista simplesmente encadeada | Cadastro e gerenciamento de pacientes | `pacientes.c` |
| Lista duplamente encadeada | Histórico de atendimentos, permitindo percorrer os registros nos dois sentidos | `historico_atendimento.c` |
| Lista circular | Rotação dos médicos durante o plantão | `medicos.c` |
| Fila dinâmica | Organização dos pacientes por ordem de chegada | `atendimentos.c` |
| Pilha dinâmica | Armazenamento das ações que podem ser desfeitas | `acoes.c` |

## Tecnologias utilizadas

- Linguagem C;
- biblioteca padrão da linguagem C;
- GCC para compilação;
- Git e GitHub para controle de versão.

## Organização do projeto

```text
SysHospital/
├── assets/
│   ├── main.c
│   ├── interfaces/          # Arquivos de cabeçalho (.h)
│   └── functions/           # Implementações dos módulos (.c)
└── README.md
```

## Pré-requisitos

Para compilar o projeto, é necessário ter o **GCC** instalado.

Verifique a instalação executando:

```bash
gcc --version
```

## Como baixar o projeto

Clone o repositório e acesse a pasta que contém o código-fonte:

```bash
git clone https://github.com/victorafonsofr/SysHospital.git
cd SysHospital/assets
```

## Compilação

### Windows — PowerShell

```powershell
gcc -I interfaces main.c functions/*.c -o SysHospital.exe
```

Execute o programa com:

```powershell
.\SysHospital.exe
```

### Linux

```bash
gcc -I interfaces main.c functions/*.c -o SysHospital
```

Execute o programa com:

```bash
./SysHospital
```

### Compilação com avisos habilitados

Durante o desenvolvimento, recomenda-se habilitar os avisos do compilador:

```bash
gcc -Wall -Wextra -pedantic -I interfaces main.c functions/*.c -o SysHospital
```

Esses avisos ajudam a identificar possíveis problemas no código, como variáveis não utilizadas, conversões inseguras e declarações inconsistentes.

## Observações

- Os comandos devem ser executados dentro da pasta `assets`;
- a opção `-I interfaces` informa ao GCC onde encontrar os arquivos de cabeçalho;
- `functions/*.c` inclui na compilação todos os arquivos `.c` da pasta `functions`;
- `-o SysHospital` define o nome do arquivo executável gerado.

## Objetivo acadêmico

O SysHospital tem como objetivo demonstrar a aplicação prática de estruturas de dados em um problema realista. Cada estrutura foi escolhida conforme o comportamento necessário para a funcionalidade correspondente, como ordem de chegada, navegação bidirecional, rotação cíclica e reversão da última ação.

## Autor

Desenvolvido por [Victor Afonso](https://github.com/victorafonsofr).

## Licença

Este projeto foi desenvolvido para fins acadêmicos. Caso queira reutilizá-lo, consulte o autor.
