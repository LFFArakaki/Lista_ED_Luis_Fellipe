#include "pilha.h"

void construir_pilha(int capacidade, t_pilha *pilha){
    pilha->capacidade = capacidade;
    pilha->topo = 0;
    pilha->dados = (int *)malloc(sizeof(int)*capacidade);
}
void exibir_pilha(t_pilha *pilha){
    printf("---------------\n");
    for(int i=pilha->topo;i>0;i--) printf("%d\n",pilha->dados[i-1]);
    printf("---------------\n");
}
int push(int dado, t_pilha *pilha){
    if(pilha_cheia(pilha)) return 0;
    else pilha->dados[pilha->topo++] = dado;
    return 1;
}
int pop(int *dado, t_pilha *pilha){
    if(pilha_vazia(pilha)) return 0;
    else *dado = pilha->dados[--pilha->topo];
    return 1;
}
int pilha_vazia(t_pilha *pilha){
    return !pilha->topo;
}
int pilha_cheia(t_pilha *pilha){
    return !(pilha->capacidade - pilha->topo);
}
//Ex. 1
int pop_n_elementos(int n, t_pilha *pilha){
    int aux, i=0;
    if(pilha_vazia(pilha)) return 0;
    for(i=0;i<n;i++) if(!pop(&aux, pilha)) return i;
    return i;
}
//Ex. 2
void inverter_pilha(t_pilha *pilha){
    t_pilha pilha_aux;
    int aux;
    construir_pilha(pilha->capacidade, &pilha_aux);
    while(pop(&aux, pilha)) push(aux, &pilha_aux);
    pilha->dados = pilha_aux.dados;
    pilha->topo = pilha_aux.topo;
}
//Ex. 3
void separar_pilha(t_pilha *original, t_pilha *par, t_pilha *impar){
    construir_pilha(original->capacidade, par);
    construir_pilha(original->capacidade, impar);
    for(int i=0;i<original->topo;i++)
    {
        if(original->dados[i]%2 == 0) push(original->dados[i], par);
        else push(original->dados[i], impar);
    }
    return;
}
//Ex. 4
t_pilha juntar_pilhas_decrescente(t_pilha *pilhaA, t_pilha *pilhaB){
    t_pilha pilhaFinal;
    int aux;

    construir_pilha(pilhaA->topo+pilhaB->topo, &pilhaFinal);
    while(pop(&aux, pilhaA)) push(aux, &pilhaFinal);
    while(pop(&aux, pilhaB)) push(aux, &pilhaFinal);

    return pilhaFinal;
}