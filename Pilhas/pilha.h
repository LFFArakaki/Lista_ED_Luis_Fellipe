#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int capacidade;
    int topo;
    int *dados;
} t_pilha; 

void construir_pilha(int capacidade, t_pilha *pilha);
void exibir_pilha(t_pilha *pilha);
int push(int dado, t_pilha *pilha);
int pop(int *dado, t_pilha *pilha);
int pilha_vazia(t_pilha *pilha);
int pilha_cheia(t_pilha *pilha);
int pop_n_elementos(int n, t_pilha *pilha);
void inverter_pilha(t_pilha *pilha);
void separar_pilha(t_pilha *original, t_pilha *par, t_pilha *impar);
t_pilha juntar_pilhas_decrescente(t_pilha *pilhaA, t_pilha *pilhaB);
void transferir_pilha(t_pilha *transfere, t_pilha *recebe);
int procurar_dado(int dado, t_pilha *pilha);