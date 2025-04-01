#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float distancia_entre_pontos(ponto *pontoA, ponto *pontoB);
int pertence_ao_circulo(circulo *circulo, ponto *ponto);

typedef struct{
    float x;
    float y;
} ponto;

typedef struct{
    ponto ponto_central;
    float raio;
} circulo;

int main(){
    circulo c = {
        {0, 0},
        4
    };
    ponto pontoA = {
        4,
        0
    };
    ponto pontoB = {
        7.1,
        2.8
    };

    printf("Distancia entre A e B = %f\n",distancia_entre_pontos(pontoA, pontoB));
    if(pertence_ao_circulo(c, pontoA)) printf("A pertence ao circulo!\n");
    if(pertence_ao_circulo(c, pontoB)) printf("B pertence ao circulo!\n");
}

float distancia_entre_pontos(ponto *pontoA, ponto *pontoB){
    return sqrt(((pontoA->x - pontoB->x)*(pontoA->x - pontoB->x))
    + ((pontoA->y - pontoB->y)*(pontoA->y - pontoB->y)));
}

int pertence_ao_circulo(circulo *circulo, ponto *ponto){
    if(distancia_entre_pontos(ponto, circulo->ponto_central) == circulo->raio) return 1;
    else return 0;
}