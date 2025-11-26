#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <ctype.h>

typedef struct {
    char nome[50];
    char autor[50];
    int ano;
} Livro;

int validarString(char *str) {
    int i;
    int apenasEspacos = 1;
    
    if (strlen(str) == 0) return 0; 

    for (i = 0; str[i] != '\0'; i++) {
        if (!isspace((unsigned char)str[i])) {
            apenasEspacos = 0; 
            break;
        }
    }

    if (apenasEspacos) return 0; 
    return 1; 
}

int main() {
    setlocale(LC_ALL, "Portuguese");

    Livro biblioteca[10];
    int quantidade = 0;
    int opcao = 0; 
    int i, Excluir;
    int validacao;
    char bufferAno[50];
    int anoValido;
    
    char matrizExibicao[10][3][50]; 

    do {
        printf("\n--- SISTEMA DE BIBLIOTECA ---\n");
        printf("1. Cadastrar livros\n");
        printf("2. Excluir livros cadastrados\n");
        printf("3. Ver livros (Procurar)\n");
        printf("4. Sair\n");
        printf("Escolha uma opcao: ");

        validacao = scanf("%d", &opcao);

        if (validacao == 0) {
            printf("\nOpcao invalida! Tente novamente.\n");
            while(getchar() != '\n'); 
            continue; 
        }

        getchar(); 

        switch (opcao) {
            case 1: 
                if (quantidade >= 10) {
                    printf("\nERRO: Nao ha mais espaco para livros, exclua um e tente novamente.\n");
                } else {
                    printf("\n--- CADASTRO DE LIVRO ---\n");
                    
                    do {
                        printf("Nome do livro: ");
                        fgets(biblioteca[quantidade].nome, 50, stdin);
                        
                        biblioteca[quantidade].nome[strcspn(biblioteca[quantidade].nome, "\n")] = 0;

                        if (!validarString(biblioteca[quantidade].nome)) {
                            printf("ERRO: O nome nao pode ser vazio ou conter apenas espacos.\n");
                        }
                    } while (!validarString(biblioteca[quantidade].nome));
                    
                    do {
                        printf("Nome do autor: ");
                        fgets(biblioteca[quantidade].autor, 50, stdin);
                        
                        biblioteca[quantidade].autor[strcspn(biblioteca[quantidade].autor, "\n")] = 0;

                        if (!validarString(biblioteca[quantidade].autor)) {
                            printf("ERRO: O autor nao pode ser vazio ou conter apenas espacos.\n");
                        }
                    } while (!validarString(biblioteca[quantidade].autor));
                    
                    do {
                        anoValido = 0;
                        printf("Ano de lancamento: ");
                        fgets(bufferAno, 50, stdin);
                        bufferAno[strcspn(bufferAno, "\n")] = 0;

                        if (!validarString(bufferAno)) {
                            printf("ERRO: O ano nao pode ser vazio ou conter apenas espacos.\n");
                        } else {
                            if (sscanf(bufferAno, "%d", &biblioteca[quantidade].ano) == 1) {
                                anoValido = 1;
                            } else {
                                printf("ERRO: Digite um numero valido para o ano.\n");
                            }
                        }
                    } while (!anoValido);

                    quantidade++;
                    printf("Livro cadastrado com sucesso!\n");
                }
                break;

            case 2: 
                if (quantidade == 0) {
                    printf("\nNao ha livros cadastrados para excluir.\n");
                } else {
                    printf("\n--- EXCLUIR LIVRO ---\n");
                    printf("Escolha um livro para excluir:\n");
                    
                    for (i = 0; i < quantidade; i++) {
                        printf("%d. %s\n", i + 1, biblioteca[i].nome);
                    }
                    
                    printf("Digite o numero do livro: ");
                    if(scanf("%d", &Excluir) == 1) {
                         getchar();
                         if (Excluir > 0 && Excluir <= quantidade) {
                            int posReal = Excluir - 1;
                            for (i = posReal; i < quantidade - 1; i++) {
                                biblioteca[i] = biblioteca[i + 1];
                            }
                            quantidade--;
                            printf("Livro excluido com sucesso!\n");
                        } else {
                            printf("Numero invalido!\n");
                        }
                    } else {
                        printf("Entrada invalida! Digite apenas numeros.\n");
                        while(getchar() != '\n'); 
                    }
                }
                break;

            case 3: 
                if (quantidade == 0) {
                    printf("\nNenhum livro cadastrado.\n");
                } else {
                    printf("\n--- LISTA DE LIVROS (Matriz) ---\n");
                    printf("%-30s | %-30s | %s\n", "NOME", "AUTOR", "ANO");
                    printf("--------------------------------------------------------------------------\n");
                    
                    for (i = 0; i < quantidade; i++) {
                        strcpy(matrizExibicao[i][0], biblioteca[i].nome);
                        strcpy(matrizExibicao[i][1], biblioteca[i].autor);
                        sprintf(matrizExibicao[i][2], "%d", biblioteca[i].ano);
                    }

                    for (i = 0; i < quantidade; i++) {
                        printf("%-30s | %-30s | %s\n", 
                               matrizExibicao[i][0], 
                               matrizExibicao[i][1], 
                               matrizExibicao[i][2]);
                    }
                }
                break;

            case 4:
                printf("\nSaindo do sistema...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }

    } while (opcao != 4);

    return 0;
}

