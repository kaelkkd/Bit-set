#include <stdio.h>
#include <stdlib.h>

int main() {
    unsigned int vetor[200];    //vetor responsavel por armazenar os valores
    int entrada;                //variavel utilizada para receber os valores do usuario
    int pos;                    //posicao que o elemento ocupara no vetor      
    int desloc;                 //valor de deslocamento necessario para ativar o bit correspondente
    int w;
    int j;
    int i;
    
    for (i = 0; i < 200; i++) { //loop para inicializar o vetor, definindo 0 como elemento padrão
        vetor[i] = 0;
    }
    
    while (1) {
        printf("Digite um inteiro entre 0 e 5000: \n");
        scanf("%d", &entrada);

        if (entrada == -1) {     //caso o valor digitado for -1, o programa ira imprimir os valores armazenados no vetor
            printf("Inteiros digitados: \n");
            break;
        }
        
        else if (entrada < 0 || entrada > 5000) {     //caso o valor digitado esteja fora do intervalo, o programa ira encerrar e retornar 1
            printf("O valor digitado está fora do intervalo.\n");
            return 1;
        } 
        
        else {  //caso o valor esteja no intervalo
            desloc = entrada / 32; //quantidade de bits que serao utilizados no deslocamento
            vetor[desloc] = vetor[desloc] | 1 << (entrada - (desloc * 32)); 
            //posicao do numero no vetor
        }
    }

    for (i = 0; i < 200; i++) {  //loop para imprimir o vetor, primeiro percorre o vetor
        for (j = 0; j < 32; j++) {  //em seguida percorre os bits do inteiro
            if (vetor[i] & (1 << j)) {  //caso o bit correspondente esteja ativado o valor sera printado
                printf("%d\n", (i << 5) + j);   
            }
        }
    }

    return 0;
}
