#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor;
    
    vetor = (int *)malloc(sizeof(int)*10);
    
    for(int i=0;i<10;i++)
    {
        scanf("%d",&vetor[i]);
        vetor[i] = vetor[i]%2;
    }
    
    for(int i=0;i<10;i++) printf("%d ",vetor[i]);
    
    return 0;
}