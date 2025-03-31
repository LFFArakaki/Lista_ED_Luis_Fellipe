#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor;
    int x, cont = 0;
    
    vetor = (int *)malloc(sizeof(int)*10);
    
    printf("Digite ate 10 numeros (0 encerra a lista)\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&x);
        if(x == 0) break;
        vetor[i] = x;
        cont++;
    }
    
    printf("Vetor:\n");
    for(int i=0;i<cont;i++) printf("%d ",vetor[i]);
    printf("\nPossui %d elementos",cont);
    
    return 0;
}
