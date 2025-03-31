#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *pares, *impares;
    int par, impar, x;
    par = impar = 0;
    
    for(int i=0;i<10;i++)
    {
        scanf("%d",&x);
        if(x%2 == 0)
        {
            par++;
            if(par == 1) pares = (int *)malloc(sizeof(int));
            else pares = (int *)realloc(pares, sizeof(int)*par);
            pares[par-1] = x;
        }
        else
        {
            impar++;
            if(impar == 1) impares = (int *)malloc(sizeof(int));
            else impares = (int *)realloc(impares, sizeof(int)*impar);
            impares[impar-1] = x;
        }
    }
    
    for(int i=0;i<par;i++)
    {
        printf("%d ",pares[i]);
    }
    printf("\n");
    for(int i=0;i<impar;i++)
    {
        printf("%d ",impares[i]);
    }

    return 0;
}
