#include "pilha.h"

int main()
{
    t_pilha pilhaA, pilhaB, pilhaPar, pilhaImpar;
    int removidos, i = 0;
    
    construir_pilha(10, &pilhaA);
    construir_pilha(10, &pilhaB);
    
    //Teste Ex. 1
    removidos = pop_n_elementos(3,&pilhaA);
    
    if(!removidos) printf("Pilha nao tem elementos o suficiente!\n");
    else printf("%d elemento(s) removido(s) com sucesso!\n",removidos);
    //Teste Ex.2
    while(push(i++,&pilhaA));
    exibir_pilha(&pilhaA);
    inverter_pilha(&pilhaA);
    exibir_pilha(&pilhaA);
    
    //Teste Ex. 1
    removidos = pop_n_elementos(3,&pilhaA);
    
    if(!removidos) printf("Pilha nao tem elementos o suficiente!\n");
    else printf("%d elemento(s) removido(s) com sucesso!\n",removidos);
    exibir_pilha(&pilhaA);
    
    //Teste Ex. 3
    separar_pilha(&pilhaA, &pilhaPar, &pilhaImpar);
    exibir_pilha(&pilhaPar);
    exibir_pilha(&pilhaImpar);
    exibir_pilha(&pilhaA);
    
    //Teste Ex. 4
    while(push(i++,&pilhaA));
    while(push(i++,&pilhaB));
    inverter_pilha(&pilhaA);
    inverter_pilha(&pilhaB);
    exibir_pilha(&pilhaA);
    exibir_pilha(&pilhaB);
    t_pilha pilhaC = juntar_pilhas_decrescente(&pilhaA, &pilhaB);
    exibir_pilha(&pilhaC);
    
    return 0;
}