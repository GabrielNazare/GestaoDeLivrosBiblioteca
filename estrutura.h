#ifndef ESTRUTURA_H
#define ESTRUTURA_H

// Estrutura do livro
typedef struct Livro {
    char titulo[100];
    char autor[100];
    char ISBN[20];
    int ano;
    int disponivel; // 1 se disponível, 0 se emprestado
    struct Livro *prox;
} Livro;

// Estrutura da biblioteca
typedef struct Biblioteca {
    Livro *head;
} Biblioteca;

// Funções relacionadas à estrutura da biblioteca
Biblioteca* inicializaBiblioteca();
void adicionaLivro(Biblioteca *biblioteca, Livro *novoLivro);
Livro* buscaLivroPorISBN(Biblioteca *biblioteca, const char *ISBN);
void liberaBiblioteca(Biblioteca *biblioteca);

#endif // ESTRUTURA_H
