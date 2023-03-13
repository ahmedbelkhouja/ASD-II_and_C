#include <stdio.h>
#include <string.h>

void main() {
    char* words[100];
    int num_words, i, j;
    char temp[50];

    printf("Enter the number of words to sort (maximum %d): ", 100);
    scanf("%d", &num_words);

    if (num_words > 100) {
        printf("Error: too many words.\n");
        return 1;
    }

    printf("Enter %d words:\n", num_words);
    for (i = 0; i < num_words; i++) {
        words[i] = (char*) malloc(50 * sizeof(char));
        scanf("%s", words[i]);
    }
    //tri a bulles
    for (i = 0; i < num_words - 1; i++) {
        for (j = 0; j < num_words - i - 1; j++) {
            if (strcmp(words[j], words[j+1]) > 0) {
                strcpy(temp, words[j]);
                strcpy(words[j], words[j+1]);
                strcpy(words[j+1], temp);
            }
        }
    }
    printf("Sorted words:\n");
    for (i = 0; i < num_words; i++) {
        printf("%s\n", words[i]);
    }
    for (i = 0; i < num_words; i++) {
        free(words[i]);
    }
}