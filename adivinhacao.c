#include <stdio.h>
//for abs()
#include <stdlib.h>
//we need the time for srand
#include <time.h>

//Definir constantes que não vão mudar
//#define TENTATIVAS 10

int main() {

    printf("\n*******************************************\n");
    printf("* Bem vindo ao nosso jogo de adivinhacao! *\n");
    printf("*******************************************\n");

    //EPOCH = 01/01/1970, usado mt pelas linguagens de programação
    int segundos = time(0);
    srand(segundos); // s de seed

    int numeroSecreto = rand() % 100;
    //printf("numero secreto: %d\n", numeroSecreto);
    
    int chute;
    double pontos = 1000;
    int igual = 0;

    int nivel = 0;
    while(nivel < 1 || nivel > 3) {
        printf("\nQual o nivel de dificuladade?\n");
        printf("(1) Facil (2) Medio (3) Dificil\nEscolha: ");
        scanf("%d", &nivel);
    }

    int tentativas;
    switch(nivel) {
        case 1:
            tentativas = 20;
            break;
        case 2:
            tentativas = 15;
            break;
        default:
            tentativas = 6;
            break;
    }

    printf("\nChute um numero entre 1 e 100, voce tem %d tentativas.\n\n", tentativas);
        
    for(int i = 1; i <= tentativas; i++) {
      
        printf("Tentativa %d de %d\n\n", i, tentativas);

        printf("Qual o seu chute? ");
        scanf("%d", &chute);

        if(chute < 0 || chute > 100) {
            printf("\nVoce deve chutar um numero entre 0 e 100.\n\n");
            i--; //faz a pessoa não perder a chance
            continue;
        }

        igual = chute == numeroSecreto;
        int maior = chute > numeroSecreto;
        int menor = chute < numeroSecreto;
        pontos -= abs(chute - numeroSecreto)
/ 2.0;

        //essa condição retorna um int, 1 se estiver certo e 0 se estiver errado (c tem boolean? não)
        //0 is interpreted as false and anything non-zero is interpreted as true
        //por isso quando programamos arduino usamos 1 pra ligado e 0 para desligado
        if(igual) {
            printf("\nParabens! Voce ganhou em %d tentativas!\nTotal de pontos: %.1f\n\n", i, pontos);
            break;
        } else if(maior) {
            printf("\nVoce errou, seu chute foi maior que o numero secreto.\n\n");
        } else if(menor) {
            printf("\nVoce errou, seu chute foi menor que o numero secreto.\n\n");
        }
    }

    if(!igual) {
        printf("Voce perdeu, tente novamente!\n\n");
        }
     
}
