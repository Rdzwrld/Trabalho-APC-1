#include <stdio.h>
#include <string.h>
#include <locale.h>


typedef struct {
    char nome[50];
    char autor[50];
    int ano;
} Livro;

int main() {
    setlocale(LC_ALL, "Portuguese");

    Livro biblioteca[10];
    int quantidade = 0;
    int opcao = 0; 
    int i, Excluir;
    int validacao; 

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
                    
                    printf("Nome do livro: ");
                    scanf("%49[^\n]", biblioteca[quantidade].nome);
                    getchar();
                    
                    printf("Nome do autor: ");
                    scanf("%49[^\n]", biblioteca[quantidade].autor);
                    getchar();
                    
                    printf("Ano de lancamento: ");
                    
                    if(scanf("%d", &biblioteca[quantidade].ano) == 0) {
                        printf("Ano invalido! Cadastro cancelado.\n");
                        while(getchar() != '\n');
                    } else {
                        quantidade++;
                        printf("Livro cadastrado com sucesso!\n");
                        getchar();
                    }
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
                    printf("\nNenhuma livro cadastrado.\n");
                } else {
                    printf("\n--- LISTA DE LIVROS ---\n");
                    printf("%-30s | %-30s | %s\n", "NOME", "AUTOR", "ANO");
                    printf("--------------------------------------------------------------------------\n");
                    
                    for (i = 0; i < quantidade; i++) {
                        printf("%-30s | %-30s | %d\n", 
                               biblioteca[i].nome, 
                               biblioteca[i].autor, 
                               biblioteca[i].ano);
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
