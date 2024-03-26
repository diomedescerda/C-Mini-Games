#include <stdio.h>
#define NLETTERS 27
#define MAXLINE 1000

void arrayOG(char a[], int l);
void arrayModified(char a[], int s);
void get_line(char a[], int l);
void encrypt(char a[], char b[], char c[]);
void decrypt (char a[], char b[], char c[]);

main() {
    int s, l, op, aux;
    char line[MAXLINE], abc[NLETTERS], cba[NLETTERS];
    
    s = 0;
    l = 97;

    printf(">>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
    printf("<< WELCOME TO ENCRYPTOR TOOL >>\n");
    printf("<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n");
    printf("\n¡Prepárate para adentrarte en el emocionante mundo de la encriptación a tráves del cifrado César!\n");
    printf("Con esta herramienta, podrás proteger tus mensajes más importantes o intrigantes \n");
    printf("mediante un ancestral método de encriptación.\n");
    printf("\nAntes de empezar ingrese el número de desplazamientos que tendrá el encriptamiento (1-9)");
    
    arrayOG(abc, l);
    do{
        printf("\n~>");
        s = getchar();
        getchar();
        arrayModified(cba, s - 48);
    }while(s<48 || s>57);

    do{
        
        printf("\n>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>\n");
        printf("\t1. Encriptar\n\t2. Desencriptar\n\t3. Salir");
        printf("\n<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<\n~>");
        op = getchar();
        getchar();
        if (op == 49) {
            printf("Ingrese el texto a encriptar\n~> ");
            get_line(line, MAXLINE);
            encrypt(abc, cba, line);
            printf("\nTexto encriptado\n~> %s\n",line);
            printf("\nDesea seguir en el software? Presione y para seguir\n>");
            aux = getchar();
            getchar();
            if (aux != 121) {
                break;
            }
        } else if (op == 50) {
            printf("Ingrese el texto a desencriptar \n~> ");
            get_line(line, MAXLINE);
            decrypt(abc, cba, line);
            printf("\nTexto desencriptado\n~> %s\n",line);
            printf("\nDesea seguir en el software? Presione y para seguir\n>");
            aux = getchar();
            getchar();
            if (aux != 121) {
                break;
            }
        }
    }while (op != 51);
    
    printf("\n");
}

void arrayOG(char a[], int l){
    for (int i = 0; i < (NLETTERS-1); i++) {
        a[i] = l;
        l++;
    }

    a[NLETTERS-1] = '\0'; 
}
void arrayModified(char a[], int s){
    int l = 97 + s;
    
    for (int i = 0; i < (NLETTERS-1); i++) {
        a[i] = l;
        l++;
   }

    l = 97;
    s++;
    
    for (int i = NLETTERS-s; i < (NLETTERS-1); i++) {
        a[i] = l;
        l++;
    }
    
    a[NLETTERS] = '\0';
}


void get_line(char l[], int lim){
    int c, i;

    for (i = 0; (i < lim -1) && ((c = getchar()) != '\n'); ++i)
            l[i] = c;
    l[i] = '\0';
}

void encrypt(char a[], char b[], char line[]){
    int i, lo, hi, v, m;
   
    for (i = 0; line[i]!='\0'; i++){
        lo = 0;
        hi = NLETTERS;
        do {
            m = (lo + (hi - lo) / 2);
            v = a[m];
                if (v == line[i]){
                    line[i] = b[m];
                    break;
                }
                else if (v > line[i])
                    hi = m;
                else
                    lo = m + 1;
        } while (lo < hi);
    }
}


void decrypt(char a[], char b[], char line[]){
    int i;
   
    for (i = 0; line[i]!='\0'; i++)
        for (int j = 0; j < (NLETTERS - 1); j++)
            if (line[i] == b[j]) {
                line[i] = a[j];
                break;
            }
}
