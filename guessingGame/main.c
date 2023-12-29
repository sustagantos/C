#include <stdio.h>
#include <stdlib.h>
#include <time.h>



void main() {

    printf("GUESSING GAME!");

    int guess;
    int gotIt;
    int dificulty;
    int maxTries;
    double score = 1000;

    //generating the secret number
    srand(time(0));
    int number = rand() % 100;

    //choosing dificulty
    printf("choosing the dificulty!\n");
    printf("(1)Easy (2)Medium (3)Hard\n\n");
    printf("choose: ");

    scanf("%d", &dificulty);

    switch(dificulty) {
        case 1: 
            maxTries = 20;
            break;
        case 2:
            maxTries = 15;
            break;
        default:
            maxTries = 6;
            break;
    }

    //game loop
    for(int i = 1; i <= maxTries; i++) {

        printf("%d out of %d tries\n", i, maxTries);

        printf("guess a number: ");
        scanf("%d", &guess);

        //negative numbers
        if(guess < 0) {
            printf("choose a positive number!\n");
            i--;
            continue;
        }

        //checks if guess is right
        gotIt = guess == number;

        if(gotIt) {
            break;
        } else if(guess > number) {
            printf("\nGuess was bigger than secret number!\n\n");
        } else {
            printf("\nGuess was smaller than secret number\n\n");
        }


        double scoreLost = abs(guess - number) / 2.0;
        score = score - scoreLost;
    }

    //printing last message
    printf("\n");
    if(gotIt) {
        printf("\nCongratulations! You guessed the secret number!\n");
        printf("SCORE: %.2f\n\n", score);
    } else {
        printf("\nYou couldn't guess the number! Try again!\n\n");
    }


}