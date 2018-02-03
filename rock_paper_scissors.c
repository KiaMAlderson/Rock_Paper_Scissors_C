#import <stdio.h>
#import <stdlib.h>
#import <time.h>

int main(){
  //Encode RPS as 123
  //Player inputs a value, computer generates a random number (1, 2, 3)
  //Employ "win-stay lose-shift" strategy
  //Set empty location for player value
  unsigned int player = 0;
  //Changeable number of rounds
  unsigned int rounds = 5;
  //Track last made move by computer
  unsigned int previous = 0;
  //Track if computer won last round
  unsigned int win = 0;
  //Holds computer choice
  unsigned int choice = 0;
  //Number of computer wins
  unsigned int comp_win = 0;
  //Number of player wins
  unsigned int player_win = 0;

  printf("Welcome to Rock-Paper-Scissors\n");
  printf("Rock = 1, Paper = 2, Scissors = 3\n");
  printf("The computer will try to beat you!\n");
  for(int i = 0; i < rounds; i++){
    //if ((player < 1) | (player > 3)){
    printf("Enter your move:  ");
    scanf("%d\n", player);
    //  printf("%d\n", player);
  //  }
    if (win == 1){
      choice = previous;
    } else {
    choice = rand() % 3 + 1;
    }

    //1 beats 2, 2 beats 3, 3 beats 1
    //Move draws against itself
    if (player == 1){
      if (choice == 1){
        printf("DRAW\n");
        win = 0;
      } else if (choice == 2){
        printf("Player wins\n");
        player_win += 1;
        win = 0;
      } else if (choice == 3){
        printf("Computer wins\n");
        comp_win += 1;
        win = 1;
        previous = choice;
      } else {
        printf("ERROR\n");
        exit(1);
      }
    } else if (player == 2){
      if (choice == 1){
        printf("Computer wins\n");
        comp_win += 1;
        win = 1;
        previous = choice;
      } else if (choice == 2){
        printf("DRAW\n");
        win = 0;
      } else if (choice == 3){
        printf("Player wins\n");
        player_win += 1;
        win = 0;
      } else {
        printf("ERROR\n");
        exit(1);
      }
    } else if (player == 3){
      if (choice == 1){
        printf("Player wins\n");
        player_win += 1;
        win = 0;
      } else if (choice == 2){
        printf("Computer wins\n");
        comp_win += 1;
        win = 1;
        previous = choice;
      } else if (choice == 3){
        printf("DRAW\n");
        win = 0;
      } else {
        printf("ERROR\n");
        exit(1);
      }
    } else {
      printf("ERROR\n");
      exit(1);
    }
    choice = 0;
    player = 0;
  }

  if (comp_win > player_win){
    printf("Computer wins! Score: %d vs %d\n", comp_win, player_win);
  } else if (comp_win < player_win){
    printf("Player wins! Score: %d vs %d\n", comp_win, player_win);
  } else {
    printf("Nobody wins! Score: %d vs %d\n", comp_win, player_win);
  }
  return 1;
}
