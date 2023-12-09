#include <stdio.h>
#include <stdlib.h>
#include "Header.h"
#include <conio.h>
#include <time.h>
#include<windows.h>

int main() {
  system("COLOR 0");
  srand(time(NULL));
  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int index1 = -1, index2 = -1, velicina = -1, broj = 0, smer = 1, pobeda = 0, i = 0, x = 1,pobeda1 = 0;
  char tableBot[10][10], tableMarkBot[10][10], tablePlayer[10][10], tableMarkPlayer[10][10];
  botTable(tableBot);
  fill(tablePlayer);
  pravila();
  playerTable(tablePlayer);
  fill(tableMarkBot);
  fill(tableMarkPlayer);
  while (pobeda < 10 && pobeda1 < 10) {
    x = 1;
    while (x == 1) {
    niceprint(tableMarkPlayer,tableBot,tablePlayer,tableMarkBot);
    printf("%d %d\n",pobeda,pobeda1);
      x = playerTurn(tableMarkPlayer, tableBot,&pobeda1);
    if(pobeda1 == 10) break;
      if(x == 1)
       sleep(2);
    system("cls");

    }
    if(pobeda1 == 10) {
        system("cls");
    niceprint(tableMarkPlayer,tableBot,tablePlayer,tableMarkBot);
            break;}
    SetConsoleTextAttribute(hConsole, 2);
    printf("Promasaj!\n");
    SetConsoleTextAttribute(hConsole, 7);
    bot();
    sleep(2);
    system("cls");
    botTurn(tablePlayer, tableMarkBot, & velicina, & index1, & index2, & broj, & smer, & pobeda,tableMarkPlayer,tableBot);
    if(pobeda == 10) break;
    system("cls");
  }
  if(pobeda1 == 10){
        printf("\nPobedio je covek!");
  }
if(pobeda == 10){
    printf("\nPobedio je bot!");
}
  return 0;
}
