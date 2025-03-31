#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v1, *v2, *v3;
    
    v1 = (int *)malloc(sizeof(int)*5);
    v2 = (int *)malloc(sizeof(int)*5);
    v3 = (int *)malloc(sizeof(int)*10);
    
    printf("Insira os numeros do primeiro vetor:\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&v1[i]);
        v3[i*2] = v1[i];
    }
    printf("Insira os numeros do segundo vetor:\n");
    for(int i=0;i<5;i++)
    {
        scanf("%d",&v2[i]);
        v3[(i*2)+1] = v2[i];
    }
    
    printf("Vetor 1:\n");
    for(int i=0;i<5;i++) printf("%d ",v1[i]);
    printf("\n");
    printf("Vetor 2:\n");
    for(int i=0;i<5;i++) printf("%d ",v2[i]);
    printf("\n");
    printf("Vetor 3:\n");
    for(int i=0;i<10;i++) printf("%d ",v3[i]);
    
    return 0;
}
