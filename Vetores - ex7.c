#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *vetor;
    int temp;
    
    vetor = (int *)malloc(sizeof(int)*8);
    
    for(int i=0;i<8;i++)
    {
        int j = i;
        scanf("%d",&vetor[i]);
        while(j > 0 && vetor[j] < vetor[j-1])
        {
            temp = vetor[j];
            vetor[j] = vetor[j-1];
            vetor[j-1] = temp;
            j--;
        }
    }
    
    for(int i=0;i<8;i++) printf("%d ",vetor[i]);
    
    return 0;
}