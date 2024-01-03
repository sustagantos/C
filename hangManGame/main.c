#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "main.h"

char secretWord[WORDSIZE];
char guesses[26];
int guessesAmount = 0;


int isLetterIn(char letter) {   //checks if letter is in secret word

    for(int j = 0; j < strlen(secretWord); j++) {
        if(letter == secretWord[j]) {
            return 1;
        }
    }

    return 0;
}

int wrongGuesses() {    //returns the amount of wrong guesses
    int mistakes = 0;

    for(int i = 0; i < guessesAmount; i++) {

        if(!isLetterIn(guesses[i])) {
            mistakes++;
        }
    }

    return mistakes;
}

int lost() {    //checks if the user has lost
    return wrongGuesses() >= 5;
}

int won() {     //checks if the user won
    for(int i = 0; i < strlen(secretWord); i++) {
        if(!hasTried(secretWord[i])) {
            return 0;
        }
    }

    return 1;
}

void beginning() {      //beginning of the game

    printf("/****************/\n");
    printf("/ HANGMANGAME */\n");
    printf("/****************/\n\n");
}

void guess() {  //checks if the letter is in secret word and prints the result
    char guess;
    printf("Guess a letter: ");
    scanf(" %c", &guess);

    if(isLetterIn(guess)) {
        printf("\nThe letter '%c' is in the secret word!\n\n", guess);
    } else {
        printf("\nThe letter '%c' is NOT in the secret word!\n\n", guess);
    }

    guesses[guessesAmount] = guess;
    guessesAmount++;
}

int hasTried(char letter) {     //returns 1 if the letter has already been tried
    int found = 0;
    for(int j = 0; j < guessesAmount; j++) {
        if(guesses[j] == letter) {
            found = 1;
            break;
        }
    }

    return found;
}

void draw() {       //draws the hangman game

    int mistakes = wrongGuesses();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (mistakes>=1?'(':' '), (mistakes>=1?'_':' '), (mistakes>=1?')':' '));
    printf(" |      %c%c%c  \n", (mistakes>=3?'\\':' '), (mistakes>=2?'|':' '), (mistakes>=3?'/': ' '));
    printf(" |       %c     \n", (mistakes>=2?'|':' '));
    printf(" |      %c %c   \n", (mistakes>=4?'/':' '), (mistakes>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(secretWord); i++) {

        if(hasTried(secretWord[i])) {
            printf("%c ", secretWord[i]);
        } else {
            printf("_ ");
        }

    }
    printf("\n");

}

void pickWord() {   //picks the word from a txt file
    FILE* f;

    f = fopen("words.txt", "r");
    if(f == 0) {
        printf("Couldn't open file! \n\n");
        exit(1);
    }

    int words;
    fscanf(f, "%d", &words);

    srand(time(0));
    int randomOrder = rand() % words;

    for(int i = 0; i <= randomOrder; i++) {
        fscanf(f, "%s", secretWord);
    }

    fclose(f);
}


void addWord() {
    char choice;

    printf("Do you want to add a word to the game (Y/N)? ");
    scanf(" %c", &choice);

    if(choice == 'Y') {
        char newWord[WORDSIZE];

        printf("Type new word, all caps: ");
        scanf("%s", newWord);

        FILE* f;

        f = fopen("words.txt", "r+");
        if(f == 0) {
            printf("Couldn't open file!\n\n");
            exit(1);
        }

        int quantity;
        fscanf(f, "%d", &quantity);
        quantity++;
        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantity);

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", newWord);

        fclose(f);

    }

}

int main() {

    beginning();
        //beginning of the game
    pickWord();

    do {
        guess();
        draw();

    } while (!won() && !lost());

    if(won()) {
        printf("\nCongrats! You won!\n\n");


    } else {
        printf("\nOh no! You lost!\n");
        printf("The word was -> **%s**\n\n", secretWord);
    }

    addWord();
}