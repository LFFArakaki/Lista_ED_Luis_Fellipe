#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *numeros, *posicoes;
    int x, cont;
    cont = 0;
    
    numeros = (int *)malloc(sizeof(int)*10);
    
    for(int i=0;i<10;i++)
    {
        scanf("%d",&x);
        numeros[i] = x;
        if(x%3 == 0)
        {
            cont++;
            if(cont == 1) posicoes = (int *)malloc(sizeof(int));
            else posicoes = (int *)realloc(posicoes, sizeof(int)*cont);
            posicoes[cont-1] = i;
        }
    }
    
    if(cont == 0) printf("Sem multiplos de 3");
    for(int i=0;i<cont;i++) printf("Multiplo = %d/Posicao = %d\n",numeros[posicoes[i]],posicoes[i]);
    
    return 0;
}
