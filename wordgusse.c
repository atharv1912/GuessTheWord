#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char* words[] = {"algorithm", "programming", "computer", "language", "vesit","windows","linux","lenovo","Blockchain","Cybersecurity","Encryption","Network","Robotics","Automation","Internet","Database","Hacker"};

    int numWords = sizeof(words) / sizeof(words[0]);
    

    srand(time(NULL));
    
    int randomIndex = rand() % numWords; 
    char* secretWord = words[randomIndex];
    int wordLength = strlen(secretWord);
    char guessedWord[wordLength];
    int attempts = 6; 


    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0';

    printf("**************Welcome to the 'Guess the Word' game!**************\n");
    printf("You have %d attempts to guess the word.\n\n", attempts);

    while (attempts > 0) {
        printf("Word to guess: %s\n", guessedWord);
        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);

        int found = 0;  

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
            printf("Congratulations! You've guessed the word: %s in %d attempts \n", secretWord, attempts);
            break;
        }
    }

    if (attempts == 0) {
        printf("Sorry, you've run out of attempts. The word was: %s\n", secretWord);
    }

    return 0;
}
