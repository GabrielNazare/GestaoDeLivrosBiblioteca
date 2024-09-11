#ifndef LIVRO_H
#define LIVRO_H

#include "estrutura.h"
#include <stdio.h>

void adicionarLivro(Biblioteca *biblioteca, const char *detalhes, FILE *output);
Livro* buscarLivro(Biblioteca *biblioteca, const char *criterio);
void buscarImprimirLivro(Biblioteca *biblioteca, const char *criterio, FILE *output);
void emprestarLivro(Biblioteca *biblioteca, const char *ISBN, FILE *output);
void devolverLivro(Biblioteca *biblioteca, const char *ISBN, FILE *output);

#endif // LIVRO_H
