#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MSG_LEN 300
#define KEY_LEN 50

/* A key is valid only if it has at least one character and every character is a letter. */
int is_valid_key(const char key[]) {
    if (key[0] == '\0') return 0;

    for (int i = 0; key[i] != '\0'; i++) {
        if (!isalpha((unsigned char)key[i])) return 0;
    }
    return 1;
}

/* Shifts each letter by the matching letter of the key.
   decrypt = 0 encrypts, decrypt = 1 decrypts. */
void vigenere(char text[], const char key[], int decrypt) {
    int key_len = strlen(key);
    int j = 0;

    for (int i = 0; text[i] != '\0'; i++) {
        if (isalpha((unsigned char)text[i])) {
            char base = isupper((unsigned char)text[i]) ? 'A' : 'a';
            int shift = toupper((unsigned char)key[j % key_len]) - 'A';

            if (decrypt) shift = -shift;

            text[i] = base + (text[i] - base + shift + 26) % 26;
            j++;  /* only letters move the key forward */
        }
    }
}

/* Reads a whole line with fgets and removes the trailing newline. */
void read_line(char buffer[], int size) {
    fgets(buffer, size, stdin);
    buffer[strcspn(buffer, "\n")] = '\0';
}

int main(void) {
    char message[MSG_LEN];
    char key[KEY_LEN];
    int choice = 0;

    do {
        printf("\n=== Cipher Vault (Vigenere) ===\n");
        printf("1. Encrypt a message\n");
        printf("2. Decrypt a message\n");
        printf("3. Quit\n");
        printf("Enter choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Please enter a number.\n");
            while (getchar() != '\n');  /* clear the bad input */
            continue;
        }
        while (getchar() != '\n');  /* discard the rest of the line */

        if (choice == 1 || choice == 2) {
            printf("Enter message: ");
            read_line(message, MSG_LEN);

            printf("Enter key (letters only): ");
            read_line(key, KEY_LEN);

            if (!is_valid_key(key)) {
                printf("Invalid key. Use letters only, with no spaces.\n");
                continue;
            }

            vigenere(message, key, choice == 2);
            printf("Result: %s\n", message);
        } else if (choice != 3) {
            printf("Invalid choice. Try again.\n");
        }
    } while (choice != 3);

    printf("Goodbye!\n");
    return 0;
}
