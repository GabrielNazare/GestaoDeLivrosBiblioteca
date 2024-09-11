//Alunos: Gabriel Henrique de Souza Nazaré & Maria Sara Navarro
//Este arquivo implementa as operações relacionadas a livro.

#include "estrutura.h"
#include "livro.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void adicionarLivro(Biblioteca *biblioteca, const char *detalhes, FILE *output) {
    Livro *novoLivro = (Livro *)malloc(sizeof(Livro));
    sscanf(detalhes, "%[^,], %[^,], %[^,], %d", novoLivro->titulo, novoLivro->autor, novoLivro->ISBN, &novoLivro->ano);
    novoLivro->disponivel = 1;
    novoLivro->prox = NULL;
    adicionaLivro(biblioteca, novoLivro);
    fprintf(output, "Livro adicionado: %s\n", novoLivro->titulo);
    printf("Livro adicionado: %s\n", novoLivro->titulo);
}

Livro* buscarLivro(Biblioteca *biblioteca, const char *criterio) {
    Livro *atual = biblioteca->head;
    while (atual != NULL) {
        if (strstr(atual->titulo, criterio) || strstr(atual->autor, criterio) || strcmp(atual->ISBN, criterio) == 0) {
            return atual;  // Retorna o livro encontrado
        }
        atual = atual->prox;
    }
    return NULL;  // Retorna NULL se não encontrar o livro
}

void buscarImprimirLivro(Biblioteca *biblioteca, const char *criterio, FILE *output) {
    Livro *atual = biblioteca->head;
    int encontrado = 0;

    while (atual != NULL) {
        if (strstr(atual->titulo, criterio) || strstr(atual->autor, criterio) || strcmp(atual->ISBN, criterio) == 0) {
            fprintf(output, "Livro encontrado: %s, %s, %s, %d, Disponível: %d\n",
                    atual->titulo, atual->autor, atual->ISBN, atual->ano, atual->disponivel);
            printf("Livro encontrado: %s, %s, %s, %d, Disponível: %d\n",
                    atual->titulo, atual->autor, atual->ISBN, atual->ano, atual->disponivel);
            encontrado = 1;
        }
        atual = atual->prox;
    }

    if (!encontrado) {
        fprintf(output, "Livro não encontrado: %s\n", criterio);
        printf("Livro não encontrado: %s\n", criterio);
    }
}

void emprestarLivro(Biblioteca *biblioteca, const char *ISBN, FILE *output) {
    Livro *livro = buscarLivro(biblioteca, ISBN);
    if (livro != NULL && livro->disponivel) {
        livro->disponivel = 0;  // Marca o livro como emprestado
        fprintf(output, "Livro emprestado: %s\n", livro->titulo);
        printf("Livro emprestado: %s\n", livro->titulo);
    } else if (livro != NULL) {
        fprintf(output, "Livro já está emprestado: %s\n", livro->titulo);
        printf("Livro já está emprestado: %s\n", livro->titulo);
    } else {
        fprintf(output, "Livro não encontrado com ISBN: %s\n", ISBN);
        printf("Livro não encontrado com ISBN: %s\n", ISBN);
    }
}

void devolverLivro(Biblioteca *biblioteca, const char *ISBN, FILE *output) {
    Livro *livro = buscarLivro(biblioteca, ISBN);
    if (livro != NULL && !livro->disponivel) {
        livro->disponivel = 1;  // Marca o livro como disponível
        fprintf(output, "Livro devolvido: %s\n", livro->titulo);
        printf("Livro devolvido: %s\n", livro->titulo);
    } else if (livro != NULL) {
        fprintf(output, "Erro: Livro não está emprestado: %s\n", livro->titulo);
        printf("Erro: Livro não está emprestado: %s\n", livro->titulo);
    } else {
        fprintf(output, "Livro não encontrado com ISBN: %s\n", ISBN);
        printf("Livro não encontrado com ISBN: %s\n", ISBN);
    }
}
