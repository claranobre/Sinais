#include <csignal>
#include <cstdio>
#include <unistd.h>
#include <stdlib>

//Constantes lógicas
#define FALSE 0
#define TRUE 1

//Estados do Semáforo
#define LIGADO
#define DESLIGADO

//Sub Estados do Semáforo
#define VERMELHO
#define AMARELO_VERDE
#define VERDE
#define AMARELO_VERMELHO

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
                  		*sig2 = AMARELO_VERDE;
                  	break;
              		case AMARELO_VERDE:
                  		*sig2 = VERDE;
                  	break;
              		case VERDE:
                  		*sig2 = AMARELO_VERMELHO;
                  	break;
              		case AMARELO_VERMELHO:
                  		*sig2 = VERMELHO;
                 	break;
              	}
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
int Acao(void){
	int invalido = FALSE;
	int acao, op;

	do{
		if(invalido){
			printf("Sinal Inválido.");
		}
		else{
			printf(" 1 - Ligar o Semáforo \n");
			printf(" 2 - Desligar o Semáforo \n"); //Ctrl + Z
			printf(" 3 - Chavear o Semáforo \n"); // Ctrl + C
			printf(" 4 - FIM \n Opção:");
		}
		invalido = FALSE;
		scanf("%d", &op);
		
		switch(op){
			case 1:
				acao = LIGAR;
			break;
			case 2:	
				acao = DESLIGAR;
			break;
			case 3:
				acao = CHAVEAR;
			case 4: 
				acao = TERMINAR; //Ctrl + Z
			break;
		default:
				invalido = TRUE;
			break;		
		}
	}
	while(invalido)
	return acao;
}

int mostrarCores(int estado1, int estado2){
	if (estado1 == DESLIGADO){
		printf("DESLIGADO\n");
	}
	else{
		printf("LIGADO ");
		switch (estado2){
			case VERMELHO:
				printf("VERMELHO\n");
				break;
			case AMARELO_VERDE:
				printf("AMARELO_VERDE\n");
				break;
			case VERDE:
				printf("VERDE\n");
				break;
			case AMARELO_VERMELHO:
				printf("AMARELO_VERMELHO\n");
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