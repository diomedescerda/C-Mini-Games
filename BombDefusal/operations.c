#include <stdio.h>
#include "modules.h"

#define NHINTS 5

int operation(char s[], int hints[]){
    int val, currNum, auxNum, auxOp, error;
    char currOp = '+';
    val = currNum = auxNum = 0;
    error = 1;
    
    for (int i = 0; s[i] != '\0'; i++) {
        if(s[i] >= '0' && s[i] <='9'){
            currNum = currNum * 10 + (s[i] - '0');
        }
        else if(s[i] == '+' || s[i] == '-' || s[i] == '*'){
            switch (currOp) {
                case '+':
                    val += currNum;
                    auxOp = currOp;
                    break;
                case '-':
                    val -= currNum;
                    auxOp = currOp;
                    break;
                case '*':
                    if (auxOp == '+')
                        val = val - auxNum + (currNum * auxNum);
                    else if(auxOp == '-')
                        val = val + auxNum - (currNum * auxNum);
                    else
                        val *= currNum;
                    auxOp = '*';
                    break;
            }
            auxNum = currNum;
            currNum = 0;
            currOp = s[i];
            }
    }
   
    for (int j = 0; j < NHINTS; j++)
        if (hints[j] == currNum)
            error = 0;
    if (error > 0) {
        printf("!#%d no pertenece a la lista de números.\n",currNum);
        return -1;
    }

    switch (currOp) {
        case '+':
            val += currNum;
            break;
        case '-':
            val -= currNum;
            break;
        case '*':
            if (auxOp == '+')
                val = val - auxNum + (currNum * auxNum);
            else if (auxOp == '-')
                val = val + auxNum - (currNum * auxNum);
            else
                val *= currNum;
            auxOp = '*';
            break;
    }

    return val;
}
