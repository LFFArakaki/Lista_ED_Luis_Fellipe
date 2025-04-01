#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v1, *v2, *v3;
    
    v1 = (int *)malloc(sizeof(int)*10);
    v2 = (int *)malloc(sizeof(int)*10);
    v3 = (int *)malloc(sizeof(int)*10);
    
    for(int i=0;i<10;i++)
    {
        scanf("%d",&v1[i]);
    }
    printf("--------------------\n");
    for(int i=0;i<10;i++)
    {
        scanf("%d",&v2[i]);
    }
    printf("--------------------\n");
    printf("Vetor:\n");
    for(int i=0;i<10;i++)
    {
        v3[i] = v1[i]*v2[i];
        printf("%d ",v3[i]);
    }
    
    
    return 0;
}
