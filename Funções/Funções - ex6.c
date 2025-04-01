#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

int gera_aleatorio(int min, int max);
void lanca_dado_e_moeda();
void lanca_dado();

int main(){
    lanca_dado_e_moeda();
    
    return 0;
}

int gera_aleatorio(int min, int max){
    srand(time(0));

    return (rand()%(max-(min-1)))+min;
}

void lanca_dado(){
    for(int i=0;i<6000;i++)
    {
        int dado = gera_aleatorio(1,6);
        printf("#%-4d|%d\n",i,dado);
        
        #ifdef _WIN32
        Sleep(1000);
        #else
        usleep(1000*1000);
        #endif
    }

    return;
}

void lanca_dado_e_moeda(){
    char moeda[6];
    for(int i=1;i<6001;i++)
    {
        int dado = gera_aleatorio(1,6);
        
        if(gera_aleatorio(0,1)) strcpy(moeda,"Coroa");
        else strcpy(moeda,"Cara");
        
        printf("#%-4d|%d|%s\n",i,dado,moeda);
        
        #ifdef _WIN32
        Sleep(1000);
        #else
        usleep(1000*1000);
        #endif
    }

    return;
}