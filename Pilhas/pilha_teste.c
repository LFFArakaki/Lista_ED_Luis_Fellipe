#include "pilha.h"
#include <time.h>

int main()
{
    srand(time(0));
    
    //Teste Ex. 1
    t_pilha pilha;
    int removidos;
    
    construir_pilha((rand()%100)+1, &pilha);
    
    removidos = pop_n_elementos(rand()%pilha.capacidade,&pilha);
    
    if(!removidos) printf("Pilha nao tem elementos o suficiente!\n");
    else printf("%d elemento(s) removido(s) com sucesso!\n",removidos);
    while(push(rand()%101,&pilha));
    exibir_pilha(&pilha);
    
    removidos = pop_n_elementos(rand()%pilha.topo,&pilha);
    
    if(!removidos) printf("Pilha nao tem elementos o suficiente!\n");
    else printf("%d elemento(s) removido(s) com sucesso!\n",removidos);
    exibir_pilha(&pilha);
    
    //Teste Ex. 3
    t_pilha pilhaPar, pilhaImpar;
    
    separar_pilha(&pilha, &pilhaPar, &pilhaImpar);
    exibir_pilha(&pilhaPar);
    exibir_pilha(&pilhaImpar);
    exibir_pilha(&pilha);
    
    //Teste Ex. 2/Ex. 4
    t_pilha pilhaA, pilhaB;
    int i = 0;
    
    construir_pilha(10, &pilhaA);
    construir_pilha(10, &pilhaB);
    
    while(push(i++,&pilhaA));
    while(push(i++,&pilhaB));
    inverter_pilha(&pilhaA);
    inverter_pilha(&pilhaB);
    exibir_pilha(&pilhaA);
    exibir_pilha(&pilhaB);
    t_pilha pilhaC = juntar_pilhas_decrescente(&pilhaA, &pilhaB);
    exibir_pilha(&pilhaC);
    
    //Teste Ex. 8
    t_pilha transfere, recebe;
    
    construir_pilha((rand()%20)+1, &transfere);
    construir_pilha(transfere.capacidade, &recebe);
    while(push(rand()%101,&transfere));
    exibir_pilha(&transfere);
    exibir_pilha(&recebe);
    transferir_pilha(&transfere, &recebe);
    exibir_pilha(&transfere);
    exibir_pilha(&recebe);
    
    //Teste Ex. 9
    int dado = rand()%101;
    
    while(push(rand()%101,&pilha));
    exibir_pilha(&pilha);
    if(procurar_dado(dado,&pilha) == -1) printf("Numero %d nao encontrado!",dado);
    else printf("Numero %d encontrado na posicao %d",dado,procurar_dado(dado,&pilha));
    
    return 0;
}