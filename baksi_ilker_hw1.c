#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void checkGuess(int luckyNum,int guess_1, int guess_2, int *_prox_1, int *_prox_2, int *_flag, int *_score_1, int *_score_2){

    // CALCULATION OF THE PROXIMITIES
    if(luckyNum > guess_1){
        *_prox_1 = luckyNum - guess_1;
    }
    else{
        *_prox_1 = guess_1 - luckyNum;
    }
    if(luckyNum > guess_2){
        *_prox_2 = luckyNum - guess_2;
    }
    else{
        *_prox_2 = guess_2 - luckyNum;
    }

    // END OF THE CALCULATION OF THE PROXIMITIES

    // PRINTING PROXIMITIES

    printf(" Proximity of the Player 1's guess to the lucky number is: %d\n",*_prox_1);
    printf(" Proximity of the Player 2's guess to the lucky number is: %d\n\n",*_prox_2);

    // END OF THE PRINTING PROXIMITIES

    // CHECK THE GUESSES SECTION

    if(*_prox_1 == 0 || *_prox_2 == 0){
        *_flag=1;
    }

    // END OF THE CHECK THE GUESSES SECTION

    // DISPLAY THE "IT IS CORRECT" MESSAGES SECTION

    if(*_prox_1 == 0 && *_prox_2 !=0 ){

        printf(" Player 1 has guessed the number correctly.\n");
    }

    if(*_prox_2 == 0 && *_prox_1 !=0 ){

        printf(" Player 2 has guessed the number correctly.\n");
    }
    if(*_prox_2 == 0 && *_prox_1 ==0 ){
        printf(" Player 1 and Player 2 have guessed the number correctly.\n");

    }

    // END OF THE DISPLAY THE "IT IS CORRECT" MESSAGES SECTION

    // UPTADE THE SCORES SECTION

    if(*_prox_2 > *_prox_1){
        printf(" Player 1's guess is the closest to the lucky number.\n");
        *_score_1 = *_score_1 + 1 ;
    }
    if(*_prox_1 > *_prox_2){
        printf(" Player 2's guess is the closest to the lucky number.\n");
        *_score_2 = *_score_2 + 1 ;
    }
    if(*_prox_1 == *_prox_2){
        printf(" Player 1's guess and Player 2's guess are the same.\n");
        *_score_1 = *_score_1 + 1 ;
        *_score_2 = *_score_2 + 1 ;
    }
    if (*_prox_1==0){
        *_score_1 = *_score_1 + 1;
    }
    if (*_prox_2==0){
        *_score_2 = *_score_2 + 1;
    }

    // END OF THE UPTADE THE SCORES SECTION


}



//.
//.
//.
//.
//.
//.
//.



int main(){

int luckyNum,flag=0,guess_1,guess_2,prox_1,prox_2,score_1=0,score_2=0;

// GENERATING A RANDOM NUMBER
srand(time(0));
luckyNum=(rand()%1000)+1;
printf("\n A lucky number has been generated randomly.\n");
printf(" The lucky number is: %d\n\n",luckyNum);

// END OF GENERATING A RANDOM NUMBER

// MAIN LOOP SECTION

do
{
    printf(" ********************************************************\n");
    printf("  Player 1 enter your guess: ");
    scanf("%d",&guess_1);
    printf("  Player 2 enter your guess: ");
    scanf("%d",&guess_2);
    printf("\n");

    // CHECK GUESSES NEGATIVE OR NOT

    while(guess_1<0 || guess_2<0){
        printf("There is an invalid guess! Try again.\n");
        printf(" ********************************************************\n");
        printf("  Player 1 enter your guess: ");
        scanf("%d",&guess_1);
        printf("  Player 2 enter your guess: ");
        scanf("%d",&guess_2);
        printf("\n");
    }

    // END OF THE CHECK GUESSES NEGATIVE OR NOT SECTION

    checkGuess(luckyNum,guess_1,guess_2,&prox_1,&prox_2,&flag,&score_1,&score_2);
    printf("\n");

}
while(flag==0);

// END OF MAIN LOOP SECTION

// DISPLAY THE SCORES SECTION

    printf(" The scores are\n Player 1: %d\n Player 2: %d",score_1,score_2);
    printf(" \n --------------------------------------------------------\n");

// END OF THE DISPLAY THE SCORES SECTION
return 0;
}
