#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "modules.h"

#define NHINTS 5

void CLI(){
    int key, sec, op, hints[NHINTS];
    double elapsed = 0;
    char input[100];

    srand(time(NULL));

    key = setLevel();
    sec = setSeconds();

    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
    printf("▓▓▓▓ WELCOME to BombDefusal ▓▓▓▓\n");
    printf("▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓\n");
    printf("\n\tNo tenemos mucho tiempo, ¡Un matemático loco ha activado una bomba!\n");
    printf("\tPara desactivarla, debes llegar al número que desactiva la bomba.\n");
    printf("\n\tEl número objetivo es  ¤ %d ¤\n", key);
    printf("\tSolo puedes utilizar los operadores matemáticos  [ + | - | * ]\n");
    printf("\tEstos son los números con los que puedes operar ");
    printf("━ ");
    fillHints(hints);


    for (int i = 0; i < NHINTS; i++) {
        if (i == NHINTS-1)
            printf("%d \n", hints[i]);
        else
            printf("%d, ", hints[i]);
    }


    printf("\n Tienes %d segundos para desactivar la bomba! \n\n", sec);
    printf("> ");
   
    time_t start = time(NULL);


    mygetline(input, 99);
    op = operation(input, hints);
    elapsed = difftime(time(NULL), start);
    
    if (op == key)
        if (elapsed <= sec) 
            printf("\n %d\t=\t%d\n\n¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n¤¤¤¤ YOU WIN! ¤¤¤¤\n¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n", op, key);
        else{
            printf("\nEL TIEMPO SE TE HA ACABADO\n");
            printf("\n %d\t=\t%d\n\n¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n¤¤¤¤ GAME OVER ¤¤¤¤\n¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n", op, key);
        }
    else
        printf("\n %d\t!=\t%d\n\n¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n¤¤¤¤ GAME OVER ¤¤¤¤\n¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤¤\n", op, key); 
}
