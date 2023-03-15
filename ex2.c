//read the description
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pile.h"

char* extract(char ch[], unsigned d, unsigned f) {
   

    char* sch = malloc(f-d+2);

    char* p = sch;
    for (unsigned i=d; i<f;i++) {
        *p = ch[i];
        p++;
    }
    *p ='\0';
    return sch;
}

int main() {
    char ch[100];
    printf("Donnez une expression : ");
    fgets(ch, sizeof(ch), stdin);
    ch[strcspn(ch, "\n")] = '\0';

    creer_pile();
    for (unsigned i=0;i<strlen(ch);i++) {
        if (ch[i]=='(') {
            empiler(i);
        } else if (ch[i]==')') {
            if (vide()) {
                printf("Erreur : Parenthese fermante sans parenthese ouvrante correspondante\n");
                exit(EXIT_FAILURE);
            }

            puts(extract(ch,dernier(),i));
            depiler();
        }
    }


    if (!vide()) {
        printf("Erreur : Parenthese ouvrante sans parenthese fermante correspondante\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
