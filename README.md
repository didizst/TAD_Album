# Trabalho de Estrutura de Dados: Implementação de um TAD Cofo Genérico (gCofo) de Álbuns

Este projeto consiste na implementação de um **Tipo Abstrato de Dados (TAD) Cofo Genérico** (`gCofo`) na linguagem C. O objetivo é permitir o armazenamento e a manipulação de coleções de elementos de qualquer tipo definido pelo usuário, utilizando uma API genérica e modularizada.

Como exemplo de aplicação, o TAD foi utilizado para gerenciar uma coleção de objetos do tipo `Album`.

## 1. Estrutura de Dados de Exemplo: `Album`

Para demonstrar a funcionalidade genérica do `gCofo`, a estrutura `Album` foi definida com os seguintes campos:

| Campo | Tipo | Descrição |
| :--- | :--- | :--- |
| `nome` | `char[30]` | Nome do álbum. |
| `id` | `int` | Identificador único do álbum. |
| `valor` | `float` | Preço do álbum. |

## 2. Ambiente de Desenvolvimento

| Item | Especificação |
| :--- | :--- |
| **Sistema Operacional** | Windows 10/11 |
| **Compilador** | MinGW (GCC para Windows) |
| **Bibliotecas Externas** | Nenhuma |

## 3. Estrutura dos Arquivos

O pacote do projeto está organizado com os seguintes arquivos:

| Arquivo | Descrição |
| :--- | :--- |
| `README.md` | Este documento. |
| `gCofo.h` | Declaração da API do cofo genérico. |
| `gCofo.c` | Implementação do TAD genérico (sem código de entrada/saída). |
| `album.h` | Declaração da `struct Album` e protótipos das funções de comparação. |
| `album.c` | Implementação das funções de comparação específicas para `Album`. |
| `main.c` | Programa principal contendo a interface com o usuário (menu interativo) e testes. |
| `main.exe` (ou `executavel.exe`) | Arquivo compilado gerado. |

## 4. Compilação e Execução

O arquivo `main.c` inclui diretamente `gCofo.c` e `album.c`. Desta forma, basta compilar o `main.c`.

### 4.1. No Linux/macOS

```bash
cd TAD_Album
gcc -o main.exe main.c
./main.exe
```

### 4.2. No Windows (usando MinGW)

```bash
cd TAD_Album
gcc -o main.exe main.c
./main.exe
```

> **Nota:** Uma prática mais convencional seria compilar os arquivos `.c` separadamente e linká-los, mas o comando acima funciona para a estrutura de `#include` utilizada neste projeto.

## 5. Funcionalidades Implementadas e Testadas

O programa `main.c` oferece uma interface de menu interativa para testar todas as funcionalidades do TAD. O usuário pode escolher entre as seguintes opções:

| Funcionalidade | Descrição |
| :--- | :--- |
| **Criar Cofo** | Aloca memória para um novo cofo com um tamanho máximo especificado. |
| **Inserir Album no Cofo** | Adiciona um novo álbum (`nome`, `id`, `valor`) ao cofo. |
| **Remover Album por Nome** | Busca e remove um álbum usando seu nome como chave. |
| **Remover Album por ID** | Busca e remove um álbum usando seu ID como chave. |
| **Remover Album por Valor** | Busca e remove um álbum usando seu valor como chave. |
| **Consultar Album por Nome** | Busca e exibe um álbum usando seu nome. |
| **Consultar Album por ID** | Busca e exibe um álbum usando seu ID. |
| **Consultar Album por Valor** | Busca e exibe um álbum usando seu valor. |
| **Listar todos os Albuns no Cofo** | Exibe todos os elementos atualmente no cofo. |
| **Destruir Cofo** | Libera a memória do cofo (somente se estiver vazio). |
| **Esvaziar Cofo** | Libera a memória de todos os álbuns dentro do cofo, esvaziando-o. |
| **Sair** | Esvazia, destrói o cofo e encerra o programa. |

## 6. Restrições Atendidas

O projeto cumpriu as seguintes restrições:

1.  O arquivo `gCofo.c` (implementação do TAD) **não utiliza** `printf`, `scanf` ou qualquer função de entrada/saída.
2.  A estrutura `Album` contém os campos exigidos (`char[30]`, `int` e `float`).
3.  O código segue uma **arquitetura modular**, separando a lógica do TAD genérico (`gCofo.c`), a lógica do tipo de dado (`album.c`) e a interface do programa principal (`main.c`).
4.  A API utilizada é única e respeita o padrão definido (e.g., `gcofCreate`, `gcofInsert`, `gcofRemove`, `gcofQuery`).

## 7. Considerações Finais

Este trabalho demonstra com sucesso a implementação de **TADs genéricos em C**, evidenciando organização, flexibilidade e reutilização de código. A separação clara entre a lógica do TAD (`gCofo`) e a implementação do tipo de dado (`Album`) permite que o cofo seja facilmente adaptado para armazenar qualquer outro tipo de dado.

## 8. Identificação

| Disciplina | Aluno | Professor |
| :--- | :--- | :--- |
| Estrutura de Dados 1 | Diego Miqueias Andrade Oliveira | Ancelmo Cardoso de Paiva |
