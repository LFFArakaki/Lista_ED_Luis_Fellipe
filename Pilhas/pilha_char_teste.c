#include "pilha_char.h"

int main()
{
    char string[50];
    
    fgets(string, 50, stdin);
    
    if(!e_palindromo(string)) printf("Nao e palindromo!\n");
    else printf("E palindromo!\n");

    return 0;
}