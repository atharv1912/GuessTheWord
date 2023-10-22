#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* words[] = {"algorithm", "programming", "computer", "language", "openai"};
    int numWords = sizeof(words) / sizeof(words[0]);
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    int randomIndex = rand() % numWords; // Generate a random index to select a word
    char* secretWord = words[randomIndex];
    int wordLength = strlen(secretWord);
    char guessedWord[wordLength];
    int attempts = 6; // Number of allowed attempts

    // Initialize guessedWord to underscores
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';

    printf("Welcome to the 'Guess the Word' game!\n");
    printf("You have %d attempts to guess the word.\n\n", attempts);

    while (attempts > 0) {
        printf("Word to guess: %s\n", guessedWord);
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        int found = 0;  // Flag to check if the guessed letter is found in the secret word

        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                guessedWord[i] = guess;
                found = 1;
            }
        }

        if (found) {
            printf("Good guess!\n");
        } else {
            attempts--;
            printf("Wrong guess! You have %d attempts left.\n", attempts);
        }

        if (strcmp(secretWord, guessedWord) == 0) {
            printf("Congratulations! You've guessed the word: %s\n", secretWord);
            break;
        }
    }

    if (attempts == 0) {
        printf("Sorry, you've run out of attempts. The word was: %s\n", secretWord);
    }

    return 0;
}
