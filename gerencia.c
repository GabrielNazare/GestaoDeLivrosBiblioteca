//Alunos: Gabriel Henrique de Souza Nazaré & Maria Sara Navarro
//Este arquivo possui a lógica principal do sistema, inclui a leitura dos comandos, chamadas de funções de gerenciamente e a interação com o usuário

#include "estrutura.h"
#include "livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    char comando[100];
    FILE *input, *output;
    if (argc < 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    input = fopen(argv[1], "r");
    output = fopen(argv[2], "w");
    if (input == NULL || output == NULL) {
        printf("Erro ao abrir os arquivos.\n");
        return 1;
    }

    Biblioteca *biblioteca = inicializaBiblioteca();

    while (fgets(comando, sizeof(comando), input) != NULL) {
        // Remove o caractere de nova linha do comando lido
        comando[strcspn(comando, "\n")] = 0;

        if (strncmp(comando, "ADD", 3) == 0) {
            adicionarLivro(biblioteca, comando + 4, output);
        } else if (strncmp(comando, "SEARCH", 6) == 0) {
            buscarImprimirLivro(biblioteca, comando + 7, output);
        } else if (strncmp(comando, "CHECK_OUT", 9) == 0) {
            emprestarLivro(biblioteca, comando + 10, output);
        } else if (strncmp(comando, "CHECK_IN", 8) == 0) {
            devolverLivro(biblioteca, comando + 9, output);
        } else if (strncmp(comando, "END", 3) == 0) {
            break;
        }
    }

    liberaBiblioteca(biblioteca);
    fclose(input);
    fclose(output);

    return 0;
}
