// Programa feito por Diego Miqueias
// Criado e executado em CLion
// Link Github: https://github.com/didizst/TAD_Album

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#include "gCofo.h"
#include "album.h"
#include "gCofo.c"
#include "album.c"

void print_menu();
void print_album(Album *a);
void limpar_buffer_entrada();

int main() {
    gCofo *meuCofo = NULL;
    int opcao;
    int sair = FALSE;
    int tamanhoCofo;

    while (sair == FALSE) {
        print_menu();

        if (scanf("%d", &opcao) != 1) {
            printf("ERRO: Entrada invalida. Por favor, digite um numero.\n");
            limpar_buffer_entrada();
            continue;
        }
        limpar_buffer_entrada();

        if (opcao == 1) { // Criar Cofo
            if (meuCofo != NULL) {
                printf("ATENCAO: O cofo ja existe. Esvazie, destrua ou remova itens (Opcoes 11, 10 e (3,4,5).\n");
            } else {
                printf("Digite o tamanho maximo do cofo: ");
                scanf("%d", &tamanhoCofo);
                limpar_buffer_entrada();

                if (tamanhoCofo <= 0) {
                    printf("ERRO: Tamanho deve ser positivo.\n");
                } else {
                    meuCofo = gcofCreate(tamanhoCofo);
                    if (meuCofo != NULL) {
                        printf("Cofo de tamanho %d criado com sucesso!\n", tamanhoCofo);
                    } else {
                        printf("ERRO: Nao foi possivel alocar memoria para o cofo.\n");
                    }
                }
            }
        }
        else if (opcao == 2) { // Inserir Album
            if (meuCofo == NULL) {
                printf("ERRO: Crie o cofo primeiro (Opcao 1).\n");
            }
            else if (meuCofo->numItens >= meuCofo->maxItens) {
                printf("ERRO: Nao e possivel inserir. O cofo esta cheio (%d/%d).\n", meuCofo->numItens, meuCofo->maxItens);
            }
            // Se o cofo existe E NÃO está cheio:
            else {
                Album *novoAlbum = (Album*) malloc(sizeof(Album));
                if (novoAlbum == NULL) {
                    printf("ERRO: Falha ao alocar memoria para o novo album.\n");
                } else {
                    printf("Digite o nome do album (ate 29 chars): ");
                    scanf(" %29[^\n]", novoAlbum->nome);
                    limpar_buffer_entrada();

                    printf("Digite o ID do album (inteiro): ");
                    scanf("%d", &novoAlbum->id);
                    limpar_buffer_entrada();

                    printf("Digite o valor do album (float): ");
                    scanf("%f", &novoAlbum->valor);
                    limpar_buffer_entrada();

                    if (gcofInsert(meuCofo, (void*)novoAlbum) == TRUE) {
                        printf("Album '%s' inserido com sucesso!\n", novoAlbum->nome);
                    } else {
                        printf("ERRO: Nao foi possivel inserir. Cofo esta cheio?\n");
                        free(novoAlbum);
                    }
                }
            }
        }
        else if (opcao == 3 || opcao == 4 || opcao == 5) { // Remover (por Nome, ID ou Valor)
            if (meuCofo == NULL || meuCofo->numItens == 0) {
                printf("ERRO: Cofo nao existe ou esta vazio.\n");
            } else {
                void *key;
                int (*cmp_func)(void*, void*);
                Album *removido = NULL;

                // guardar as chaves de busca
                char nomeBusca[30];
                int idBusca;
                float valorBusca;

                if (opcao == 3) {
                    printf("Digite o NOME do album para remover: ");
                    scanf(" %29[^\n]", nomeBusca);
                    limpar_buffer_entrada();
                    key = (void*)nomeBusca;
                    cmp_func = cmpNameAlbum;
                } else if (opcao == 4) {
                    printf("Digite o ID do album para remover: ");
                    scanf("%d", &idBusca);
                    limpar_buffer_entrada();
                    key = (void*)&idBusca;
                    cmp_func = cmpIdAlbum;
                } else { // opcao == 5
                    printf("Digite o VALOR do album para remover: ");
                    scanf("%f", &valorBusca);
                    limpar_buffer_entrada();
                    key = (void*)&valorBusca;
                    cmp_func = cmpValueAlbum;
                }

                removido = (Album*) gcofRemove(meuCofo, key, cmp_func);

                if (removido != NULL) {
                    printf("Album removido com sucesso:\n");
                    print_album(removido);
                    free(removido);
                } else {
                    printf("Album nao encontrado para remocao.\n");
                }
            }
        }
        else if (opcao == 6 || opcao == 7 || opcao == 8) { // Consultar (por Nome, ID ou Valor)
            if (meuCofo == NULL || meuCofo->numItens == 0) {
                printf("ERRO: Cofo nao existe ou esta vazio.\n");
            } else {
                void *key;
                int (*cmp_func)(void*, void*);
                Album *encontrado = NULL;

                char nomeBusca[30];
                int idBusca;
                float valorBusca;

                if (opcao == 6) {
                    printf("Digite o NOME do album para consultar: ");
                    scanf(" %29[^\n]", nomeBusca);
                    limpar_buffer_entrada();
                    key = (void*)nomeBusca;
                    cmp_func = cmpNameAlbum;
                } else if (opcao == 7) {
                    printf("Digite o ID do album para consultar: ");
                    scanf("%d", &idBusca);
                    limpar_buffer_entrada();
                    key = (void*)&idBusca;
                    cmp_func = cmpIdAlbum;
                } else { // opcao == 8
                    printf("Digite o VALOR do album para consultar: ");
                    scanf("%f", &valorBusca);
                    limpar_buffer_entrada();
                    key = (void*)&valorBusca;
                    cmp_func = cmpValueAlbum;
                }

                encontrado = (Album*) gcofQuery(meuCofo, key, cmp_func);

                if (encontrado != NULL) {
                    printf("Album encontrado:\n");
                    print_album(encontrado);
                } else {
                    printf("Album nao encontrado.\n");
                }
            }
        }
        else if (opcao == 9) { // Listar elementos
            if (meuCofo == NULL) {
                printf("ERRO: Crie o cofo primeiro (Opcao 1).\n");
            } else if (meuCofo->numItens == 0) {
                printf("Cofo esta vazio. Nada para listar.\n");
            } else {
                printf("--- Lista de Albuns no Cofo (%d/%d) ---\n", meuCofo->numItens, meuCofo->maxItens);
                // Acesso direto. Requer que gCofo.h exponha a struct.
                int i;
                for (i = 0; i < meuCofo->numItens; i++) {
                    Album *a = (Album*) meuCofo->item[i];
                    printf("  %d: ", i + 1);
                    print_album(a);
                }
                printf("----------------------------------------\n");
            }
        }
        else if (opcao == 10) { // Destruir se vazio
            if (meuCofo == NULL) {
                printf("Cofo nem existe. Nada a fazer.\n");
            } else {
                if (gcofDestroy(meuCofo) == TRUE) {
                    printf("Cofo destruido com sucesso!\n");
                    meuCofo = NULL; // Importante para resetar o ponteiro
                } else {
                    printf("ERRO: Nao foi possivel destruir. O cofo NAO esta vazio.\n");
                }
            }
        }
        else if (opcao == 11) { // Esvaziar (Limpar)
            if (meuCofo == NULL) {
                printf("ERRO: Crie o cofo primeiro (Opcao 1).\n");
            } else if (meuCofo->numItens == 0) {
                printf("Cofo ja esta vazio.\n");
            } else {
                if (gcofClean(meuCofo) == TRUE) {
                    printf("Cofo esvaziado. Todos os albuns foram liberados da memoria.\n");
                } else {
                    // (Isso não deve acontecer pela implementação de gcofClean)
                    printf("ERRO: Falha ao esvaziar o cofo.\n");
                }
            }
        }
        else if (opcao == 0) { // Sair
            printf("Saindo... \n");
            if (meuCofo != NULL) {
                printf("Limpando e destruindo o cofo existente...\n");
                gcofClean(meuCofo);
                gcofDestroy(meuCofo);
                meuCofo = NULL;
            }
            printf("Obrigado por usar a ferramenta!\n");
            sair = TRUE;
        }
        else { // Opção padrão (inválida)
            printf("Opcao invalida. Tente novamente.\n");
        }

        // Pausa para o usuário ler a saída
        if (sair == FALSE) {
            printf("\nPressione ENTER para continuar...\n");
            getchar();
        }
    }

    return 0;
}


void print_menu() {
    printf("\n===================================================\n");
    printf("     Gerenciamento de Albuns (TAD gCofo)   \n");
    printf("===================================================\n");
    printf(" 1. Criar Cofo\n");
    printf(" 2. Inserir Album no Cofo\n");
    printf(" 3. Remover Album por Nome (char)\n");
    printf(" 4. Remover Album por ID (int)\n");
    printf(" 5. Remover Album por Valor (float)\n");
    printf(" 6. Consultar Album por Nome (char)\n");
    printf(" 7. Consultar Album por ID (int)\n");
    printf(" 8. Consultar Album por Valor (float)\n");
    printf(" 9. Listar todos os Albuns no Cofo\n");
    printf(" 10. Destruir Cofo (so se estiver vazio)\n");
    printf(" 11. Esvaziar Cofo (libera todos os albuns)\n");
    printf(" 0. Sair\n");
    printf("---------------------------------------------------\n");
    printf(" Escolha uma opcao: ");
}


void print_album(Album *a) {
    if (a != NULL) {
        printf("Album: %s (ID: %d, Valor: R$%.2f)\n", a->nome, a->id, a->valor);
    } else {
        printf("Album (NULL)\n");
    }
}

void limpar_buffer_entrada() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
