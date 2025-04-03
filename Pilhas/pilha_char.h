#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct{
    int capacidade;
    int topo;
    char *dados;
} t_pilha_char; 

void construir_pilha(int capacidade, t_pilha_char *pilha);
void exibir_pilha(t_pilha_char *pilha);
int push(char dado, t_pilha_char *pilha);
int pop(char *dado, t_pilha_char *pilha);
int pilha_vazia(t_pilha_char *pilha);
int pilha_cheia(t_pilha_char *pilha);
int pop_n_elementos(int n, t_pilha_char *pilha);
void inverter_pilha(t_pilha_char *pilha);
int parenteses_corretos(char *expressao);
int e_palindromo(char *frase);
void transferir_pilha(t_pilha_char *transfere, t_pilha_char *recebe);
int procurar_dado(int dado, t_pilha_char *pilha);