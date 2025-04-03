#include "pilha_char.h"

void construir_pilha(int capacidade, t_pilha_char *pilha){
    pilha->capacidade = capacidade;
    pilha->topo = 0;
    pilha->dados = (char *)malloc(sizeof(char)*capacidade);
}
void exibir_pilha(t_pilha_char *pilha){
    printf("---------------\n");
    for(int i=pilha->topo;i>0;i--) printf("%c\n",pilha->dados[i-1]);
    printf("---------------\n");
}
int push(char dado, t_pilha_char *pilha){
    if(pilha_cheia(pilha)) return 0;
    else pilha->dados[pilha->topo++] = dado;
    return 1;
}
int pop(char *dado, t_pilha_char *pilha){
    if(pilha_vazia(pilha)) return 0;
    else *dado = pilha->dados[--pilha->topo];
    return 1;
}
int pilha_vazia(t_pilha_char *pilha){
    return !pilha->topo;
}
int pilha_cheia(t_pilha_char *pilha){
    return !(pilha->capacidade - pilha->topo);
}
int pop_n_elementos(int n, t_pilha_char *pilha){
    char aux; 
    int i=0;
    if(pilha_vazia(pilha)) return 0;
    for(i=0;i<n;i++) if(!pop(&aux, pilha)) return i;
    return i;
}
void inverter_pilha(t_pilha_char *pilha){
    t_pilha_char pilha_aux;
    char aux;
    construir_pilha(pilha->capacidade, &pilha_aux);
    while(pop(&aux, pilha)) push(aux, &pilha_aux);
    pilha->dados = pilha_aux.dados;
    pilha->topo = pilha_aux.topo;
}
void transferir_pilha(t_pilha_char *transfere, t_pilha_char *recebe){
    t_pilha_char pilha_aux;
    char aux;
    construir_pilha(transfere->topo, &pilha_aux);
    while(pop(&aux, transfere)) push(aux, &pilha_aux);
    while(pop(&aux, &pilha_aux)) push(aux, recebe);
    return;
}
int procurar_dado(int dado, t_pilha_char *pilha){
    t_pilha_char pilha_aux;
    int posicao = -1, i = 1;
    char aux;

    construir_pilha(pilha->topo, &pilha_aux);
    while(pop(&aux, pilha))
    {
        push(aux, &pilha_aux);
        if(aux == dado)
        {
            posicao = i;
            break;
        } 
        i++;
    }
    while(pop(&aux, &pilha_aux)) push(aux, pilha);
    return posicao;
}
//Ex. 5.a
int parenteses_corretos(char *expressao){
    t_pilha_char checa;
    char aux, temp, comp = ' ';
    int i = 0;

    construir_pilha(strlen(expressao),&checa);
    while(push(expressao[i++], &checa));
    while(pop(&aux,&checa))
    {
        temp = aux;
        if(temp == '(' || temp == '{' || temp == '[')
        {
            if(comp == ' ') return 0;
            else if((comp - temp) > 2) return 0;
            else comp = ' ';
        } 
        if(temp == ')' || temp == '}' || temp == ']') comp = temp;
    }
    if(comp != ' ') return 0;
    return 1;
}
//Ex. 5.b
int e_palindromo(char *frase){
    t_pilha_char checa;
    char *sem_espaco, aux;
    int i = 0, cont = 0, tamanho = strlen(frase);

    for(i=0;i<tamanho;i++)
    {
        if(frase[i] != ' ' && frase[i] != '\n')
        {
            cont++;
            if(cont == 1) sem_espaco = (char *)malloc(sizeof(char));
            else sem_espaco = (char *)realloc(sem_espaco, sizeof(char)*cont);
            sem_espaco[cont-1] = frase[i];
        }
    }
    i = 0;
    construir_pilha(cont, &checa);
    while(push(sem_espaco[i++], &checa));
    i = 0;
    for(i=0;i<cont/2;i++)
    {
        pop(&aux, &checa);
        if(sem_espaco[i] != aux) return 0;
    }
    return 1;
}