#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct{
    int numerador;
    int denominador;
} fracao;

void exibir_fracao(fracao *fracao);
fracao ler_fracao();
fracao multiplica_fracao(fracao *fracaoA, fracao *fracaoB);
fracao *maior_fracao(fracao *fracaoA, fracao *fracaoB);

int main(){
    fracao fracaoA = ler_fracao();
    fracao fracaoB = ler_fracao();
    fracao resultado = multiplica_fracao(&fracaoA, &fracaoB);
    printf("Maior fracao: ");
    if(maior_fracao(&fracaoA, &fracaoB) != NULL)
    {
        exibir_fracao(maior_fracao(&fracaoA, &fracaoB));
    }
    printf("\n");
    exibir_fracao(&fracaoA);
    printf(" vezes ");
    exibir_fracao(&fracaoB);
    printf(" igual ");
    exibir_fracao(&resultado);

    return 0;
}

void exibir_fracao(fracao *fracao){
    printf("%d/%d",fracao->numerador,fracao->denominador);
    return;
}

fracao ler_fracao(){
    char ignora;
    int num, den;

    printf("Digite uma fracao (ex: 1/2): ");
    scanf("%d%c%d",&num,&ignora,&den);

    fracao fracao = {
        num,
        den
    };

    return fracao;
}

fracao multiplica_fracao(fracao *fracaoA, fracao *fracaoB){
    fracao resultado = {
        fracaoA->numerador*fracaoB->numerador,
        fracaoA->denominador*fracaoB->denominador
    };

    return resultado;
}

fracao *maior_fracao(fracao *fracaoA, fracao *fracaoB){
    if(((float)fracaoA->numerador/fracaoA->denominador) 
    > ((float)fracaoB->numerador/fracaoB->denominador))
    return fracaoA;
    else if (((float)fracaoA->numerador/fracaoA->denominador) 
    < ((float)fracaoB->numerador/fracaoB->denominador))
    return fracaoB;
    else printf("Fracoes sao iguais/equivalentes");
    
    return NULL;
}