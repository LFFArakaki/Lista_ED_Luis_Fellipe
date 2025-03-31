#include <stdio.h>
#include <stdlib.h>

double fahrenheit_to_celsius(double original);
double celsius_to_fahrenheit(double original);

int main()
{
    double original;
    int opcao;
    
    while(1)
    {
        printf("Escolha uma opcao:\n");
        printf("1 - Converter Celsius para Fahrenheit\n");
        printf("2 - Converter Fahrenheit para Celsius\n");
        printf("-1 - Encerrar o programa\n");
        scanf("%d",&opcao);
        
        switch(opcao)
        {
            case 1:
            printf("Digite a temperatura que deseja converter:\n");
            scanf("%lf",&original);
            printf("Temperatura convertida: %.2f\n",celsius_to_fahrenheit(original));
            break;
            case 2:
            printf("Digite a temperatura que deseja converter:\n");
            scanf("%lf",&original);
            printf("Temperatura convertida: %.2f\n",fahrenheit_to_celsius(original));
            break;
            case -1:
            printf("Encerrando o programa!\n");
            return 0;
            default:
            printf("Opcao invalida!\n");
            break;
        }
    }
    
    return 0;
}
double fahrenheit_to_celsius(double original){
    return (original-32)/1.8;
}
double celsius_to_fahrenheit(double original){
    return (original*1.8)+32;
}