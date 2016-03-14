#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

//Estados do Semáforo
#define LIGADO
#define DESLIGADO

//Sub Estados do Semáforo
#define VERMELHO
#define AMARELO
#define VERDE

// Eventos de Semáforo
#define A
#define B
#define C

// Eventos de Controle de Simulação
#define LIGAR
#define DESLIGAR
#define CHAVEAR
#define TERMINAR

//sig1 = Pai
//sig2 = Filho

void funcaoSignalHandler(int *sig1, int *sig2, int evento){
    printf("SEMAFORO\n");
    switch(evento){
        case A:
            if(sig1 == DESLIGADO){
                sig1 = LIGADO;
                sig2 = VERMELHO;
            }
            else
                sig1 = DESLIGADO;
                break;
        case B:
            if (sig1 == LIGADO){
                switch (*sig2){
                    case VERMELHO:
                        *sig2 = VERDE;
                        sleep(3);
                    break;
                    case AMARELO:
                        *sig2 = VERMELHO;
                        sleep(2);
                    break;
                    case VERDE:
                        *sig2 = AMARELO;
                        sleep(4);
                    break;
                }
            default:
                break;
        }
        case C:
            if(*sig1 == DESLIGADO){
                *sig1 = LIGADO;
                *sig2 = VERDE;
            }
            break;
    }
}
Acao(void){
    int invalido = FALSE;

    do{
        if(invalido){
            printf("Sinal Inválido.");
        }
        else{
            printf(" 1 - Chavear o Semáforo (Ctrl + C) \n"); // Ctrl + C
            printf(" 2 - FIM (Ctrl + Z) \n Opção:"); //Ctrl + Z
        }
        invalido = FALSE;

            if(signal(SIGCHLD, funcaoSignalHandler())){
            }
            else if(signal(SIGTSTP)){
                printf("Bye!");
            }

        invalido = TRUE;
        }
    }
    while(invalido)
}

int mostrarCores(int estado1, int estado2){
    if (estado1 == DESLIGADO){
        printf("DESLIGADO\n");
    }
    else{
        printf("LIGADO\n");
        switch (estado2){
            case VERMELHO:
                printf("VERMELHO\n");
                break;
            case AMARELO:
                printf("AMARELO\n");
                break;
            case VERDE:
                printf("VERDE\n");
                break;
        }
    }
}

int main(int argc, char *argv[]){

    //Identificador do processo
    pid_t idProcesso;

    printf("INICIANDO O SEMAFORO");
    //Instalar a função para tratar o sinal do usuario
    signal(SIGUSR1, funcaoSignalHandler);
    //Criando o processo
    idProcesso = fork();

    switch(idProcesso){
        case -1:
            exit(1);
        case 0:
            while(1){
                printf("Sou o SINAL ID: %d, pai ID: %d\n", getpid(), getppid());
                sleep(1);
            }
    }
}
