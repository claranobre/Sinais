#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

//Estados do Semáforo
#define LIGADO 1
#define DESLIGADO 0

//Sub Estados do Semáforo
#define VERMELHO 1
#define AMARELO 2
#define VERDE 3

// Eventos de Controle de Simulação
#define LIGAR 0
#define DESLIGAR 1 
#define CHAVEAR 2
#define TERMINAR 3

//sig1 = Pai
//sig2 = Filho

void funcaoSignalHandler(int *sig1, int *sig2, int evento){
	printf("SEMAFORO\n");
	switch(evento){
		case 1:
			if(sig1 == DESLIGADO){
				sig1 = LIGADO;
				sig2 = VERMELHO;
			}
			else
				sig1 = DESLIGADO;
				break;
		case 2:
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
    		}
    	case 3:
    		if(*sig1 == DESLIGADO){
    			*sig1 = LIGADO;
    			*sig2 = VERDE;
    		}
    		default;
    		break;			
	}
}
Acao(void){
	int invalido = 0;
	int pid;
	int myalarm();

	do{
		if(invalido){
			printf("Sinal Inválido.");
		}
		else{
			printf(" 1 - Chavear o Semáforo (Ctrl + C) \n"); // Ctrl + C
			printf(" 2 - FIM (Ctrl + Z) \n Opção:"); //Ctrl + Z
		}
		invalido = 0;

			if(signal(SIGCHLD, funcaoSignalHandler){}
			else if(kill(pid, SIGKILL)){
				printf("Bye!");
			}

		invalido = 1;		
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
	union wait status;
	
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
	signal(SIGALARM, myalarm);
 	alarm(5);
 	wait(&status);
}