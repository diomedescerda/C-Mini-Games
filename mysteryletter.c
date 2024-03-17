#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>


main(){
    int jug1, maq, n, dif, low, upp;
    jug1 = maq = dif, low, upp = 0;
    
    srand(time(NULL));
    n = rand() % (122 + 1 - 97) + 97;
    printf("%c\n",n);
    printf(" ----------------------- \n|     MysteryLetter     |\n ----------------------- \n");
    printf("¡Bienvenido al juego de adivinar la letra! En este juego por turnos, \ntu objetivo es adivinar una letra al azar antes que tu oponente, la inteligencia artificial (AI).\n");
    printf("Cada turno, tendrás la oportunidad de adivinar la letra misteriosa. \nSi adivinas correctamente la letra, ¡ganarás el juego! ¡Buena suerte y que comience la diversión!\n\n");
    printf("Elige la dificultad del juego\n1.Facil\n2.Medio\n3.Dificil\n");
    do{
        printf(">");
        dif = getchar();
    }while (dif != 49 && dif != 50 && dif != 51);

    printf("\n");

    while (1)
    {
        printf("Turno jugador 1 \n");
        
        do{
            printf(">");
            jug1 = getchar();
            
            if (jug1 >= 'A' && jug1 <= 'Z') 
                jug1 = tolower(jug1);

        } while (jug1 == '\n'  || (jug1<97 || jug1>122));

        if (jug1==n){
            printf("\n ------------------------------- \n|\t\tYOU WIN!\t|\n|\tCONGRATULATIONS!\t|\n ------------------------------- \nTHE GAME HAS ENDED!\n\n");
            break;
        }
        if (dif == 49)
            maq = rand() % (122 + 1 - 97) + 97;
        else if (dif == 50){
            low = n-6;
            upp = n+6;
            
            if (upp<122 && low>97)
                maq = rand() % ((upp) + 1 - (low)) + (low);
            else if (upp<122)
                maq = rand() % ((upp) + 1 - (97)) + (97);
            else if (low>97)
                maq = rand() % ((122) + 1 - (low)) + (low);
            else
                maq = rand() % (122 + 1 - 97) + 97;
        }
        else {
            low = n-2;
            upp = n+2;
            
            if (upp<122 && low>97)
                maq = rand() % ((upp) + 1 - (low)) + (low);
            else if (upp<122)
                maq = rand() % ((upp) + 1 - (97)) + (97);
            else if (low>97)
                maq = rand() % ((122) + 1 - (low)) + (low);
            else
                maq = rand() % (122 + 1 - 97) + 97;
        }
             
        printf("Turno de la maquina \n>> %c\n",maq);
       if (maq==n){
            printf("\n -----------------------\n|\tAI WIN\t\t|\n|\tGAME OVER\t|\n -----------------------\nTHE GAME HAS ENDED!\n\n");
            break;
        } 
        
    }
        
}