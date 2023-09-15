
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define SIZE 5

void preprocessKey(char *key) {
    int len = strlen(key);
    int index = 0;
    int used[26] = {0};
    char result[26] = {0};

    for (int i = 0; i < len; i++) {
        if (!used[tolower(key[i]) - 'a'] && isalpha(key[i])) {
            result[index++] = tolower(key[i]);
            used[tolower(key[i]) - 'a'] = 1;
        }
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (!used[c - 'a']) {
            result[index++] = c;
        }
    }

    strcpy(key, result);
}

void generatePlayfairMatrix(char key[SIZE][SIZE]) {
    char keyString[26];
    printf("Enter the key: ");
    scanf("%s", keyString);
    
    preprocessKey(keyString);

    int k = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            key[i][j] = keyString[k++];
        }
    }
}

void findCharPosition(char key[SIZE][SIZE], char ch, int *row, int *col) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (key[i][j] == ch) {
                *row = i;
                *col = j;
                return;
            }
        }
    }
}

void encrypt(char key[SIZE][SIZE], char *message) {
    // Implementation of encryption goes here
}

int main() {
    char key[SIZE][SIZE];
    generatePlayfairMatrix(key);

    char message[100];
    printf("Enter the message to encrypt: ");
    scanf("%s", message);

    encrypt(key, message);

    return 0;
}
```

Please note that this code still provides the basic structure for implementing the Playfair cipher encryption, and you'll need to fill in the encryption logic in the `encrypt` function.
