#include "pilha.h"
#include <time.h>
#include <math.h>

t_pilha converte_binario(int decimal);

int main()
{
    srand(time(0));
    
    //Teste Ex. 1
    t_pilha pilha;
    int removidos;
    
    construir_pilha((rand()%50)+1, &pilha);
    
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
    printf("Pilha A\n");
    exibir_pilha(&transfere);
    printf("Pilha B\n");
    exibir_pilha(&recebe);
    transferir_pilha(&transfere, &recebe);
    printf("Pilha A\n");
    exibir_pilha(&transfere);
    printf("Pilha B\n");
    exibir_pilha(&recebe);
    
    //Teste Ex. 9
    int dado = rand()%101;
    
    while(push(rand()%101,&pilha));
    exibir_pilha(&pilha);
    if(procurar_dado(dado,&pilha) == -1) printf("Numero %d nao encontrado!\n",dado);
    else printf("Numero %d encontrado na posicao %d\n",dado,procurar_dado(dado,&pilha));

    //Teste Ex. 6
    int teste = rand()%256;
    
    t_pilha binario = converte_binario(teste);
    printf("%d\n",teste);
    exibir_pilha(&binario);

    //Teste Ex. 7
    t_pilha p1, p2, p3;
    int temp, aux;

    construir_pilha(6,&p1);
    construir_pilha(6,&p2);
    construir_pilha(6,&p3);
    push(1,&p1);
    push(2,&p1);
    push(3,&p1);
    push(4,&p1);

    pop(&temp, &p1);
    push(temp,&p2);
    pop(&aux, &p1); push(aux, &p3);
    pop(&aux, &p1); push(aux, &p2);
    pop(&temp, &p1);
    push(temp,&p3);
    pop(&aux, &p2); push(aux, &p1);
    pop(&aux, &p2); push(aux, &p3);
    pop(&aux, &p1); push(aux, &p3);

    printf("P1\n");
    exibir_pilha(&p1);
    printf("P2\n");
    exibir_pilha(&p2);
    printf("P3\n");
    exibir_pilha(&p3);
    
    return 0;
}

//Ex. 6
t_pilha converte_binario(int decimal){
    t_pilha binario;

    construir_pilha(log2(decimal)+1, &binario);
    for(int i=0;i<binario.capacidade;i++)
    {
        push(decimal%2,&binario);
        decimal /= 2;
    }

    return binario;
}