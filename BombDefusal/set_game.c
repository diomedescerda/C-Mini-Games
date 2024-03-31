#include <stdio.h>
#include <stdlib.h>
#include "modules.h"

#define NHINTS 5

int seconds;

int setLevel(){
    int op;

    printf("Ingresa la dificultad a la que quieres jugar.\n\t1. Fácil \n\t2. Medio\n\t3. Difícil\n\t4. Extremo\n");
    do{
        printf("> ");
        op = getchar();
        getchar();
        switch (op) {
            case '1':
                seconds = 120;
                return(rand() % 25 + 1);
                break;
            case '2':
                seconds = 45;
                return(rand() % (50 - 25) + 25);
                break;
            case '3':
                seconds = 20;
                return(rand() % (75 - 50) + 50);
                break;
            case '4':
                seconds = 10;
                return(rand() % (100 - 75) + 75);
                break;
        }
    }while (op < '0' || op > '4');
    return 0;
}

int setSeconds(){
    return seconds;
};

void fillHints(int hints[]){
    int num;
    for (int i = 0; i < NHINTS; i++) {
        num = rand() % 10 + 1;
        hints[i] = num;
    }
}

