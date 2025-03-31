#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int gera_aleatorio(int a);

int main(){

}

int gera_aleatorio(int a){
    unsigned int seed = time(0);

    return rand_r(&seed)%a;
}