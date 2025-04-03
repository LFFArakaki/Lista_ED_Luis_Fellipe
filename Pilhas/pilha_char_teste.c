#include "pilha_char.h"

int main()
{
    char frase[50], expressao[20];
    
    //Teste Ex.5.a
    fgets(frase, 50, stdin);
    
    if(!e_palindromo(frase)) printf("Nao e palindromo!\n");
    else printf("E palindromo!\n");
    
    //Teste Ex.5.b
    scanf("%s",expressao);
    
    if(parenteses_corretos(expressao)) printf("Expressao valida!");
    else printf("Expressao invalida!");

    return 0;
}