#include "estrutura.h"
#include <stdlib.h>
#include <string.h>

Biblioteca* inicializaBiblioteca() {
    Biblioteca *biblioteca = (Biblioteca *)malloc(sizeof(Biblioteca));
    biblioteca->head = NULL;
    return biblioteca;
}

void adicionaLivro(Biblioteca *biblioteca, Livro *novoLivro) {
    novoLivro->prox = biblioteca->head;
    biblioteca->head = novoLivro;
}

Livro* buscaLivroPorISBN(Biblioteca *biblioteca, const char *ISBN) {
    Livro *atual = biblioteca->head;
    while (atual != NULL) {
        if (strcmp(atual->ISBN, ISBN) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

Livro* buscaLivroPorTitulo (Biblioteca *biblioteca, const char *titulo) {
    Livro *atual = biblioteca->head;
    while (atual != NULL) {
        if (strcmp(atual->titulo, titulo) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

Livro* buscaLivroPorAutor  (Biblioteca *biblioteca, const char *autor) {
    Livro *atual = biblioteca->head;
    while (atual != NULL) {
        if (strcmp(atual->autor, autor) == 0) {
            return atual;
        }
        atual = atual->prox;
    }
    return NULL;
}

void liberaBiblioteca(Biblioteca *biblioteca) {
    Livro *atual = biblioteca->head;
    while (atual != NULL) {
        Livro *temp = atual;
        atual = atual->prox;
        free(temp);
    }
    free(biblioteca);
}