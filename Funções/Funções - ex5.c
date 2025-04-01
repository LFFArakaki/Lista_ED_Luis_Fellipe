#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gera_aleatorio(int max);
int gera_aleatorio2(int min, int max);

int main(){
    int a = gera_aleatorio(100);
    printf("%d\n",a);
    int b = gera_aleatorio2(2,7);
    printf("%d\n",b);

    return 0;
}

int gera_aleatorio(int max){
    srand(time(0));

    return rand()%max;
}

int gera_aleatorio2(int min, int max){
    srand(time(0));

    return (rand()%(max-(min-1)))+min;
}