#include "Header.h"
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<windows.h>


void bot() {
  printf("\n\n\n\n\n\n\n\n\n\n\n\n                                    ####     ####   #######           #######    #    #     ####    #     #\n");
  printf("                                    #   #   #    #     #                 #       #    #     #   #   ##    #\n");
  printf("                                    #   #   #    #     #                 #       #    #     #   #   # #   #\n");
  printf("                                    ####    #    #     #                 #       #    #     ####    #  #  #\n");
  printf("                                    #   #   #    #     #                 #       #    #     # #     #   # #\n");
  printf("                                    #   #   #    #     #                 #       #    #     #  #    #    ##\n");
  printf("                                    ####     ####      #                 #        ####      #   #   #     #\n");
}
void menu(int brNosac, int brKrstarica, int brRazarac, int brPodmornica)
{
    printf("----Postavljanje brodova----\n");
    printf("1. Nosac aviona (Preostalo %d)\n", brNosac);
    printf("2. Krstarica (Preostalo %d)\n", brKrstarica);
    printf("3. Razarac (Preostalo %d)\n", brRazarac);
    printf("4. Podmornica (Preostalo %d)\n", brPodmornica);
    printf("5. Ukloni brod sa mape\n");
    printf("0. Zavrsi postavku\n");
}
void playerTable(char table[10][10])
{
    int x1, x2, y1, y2, counter = 0, counter1 = 0, counter2 = 0;
    int option;
    int brNosac = 1, brKrstarica = 2, brRazarac = 3, brPodmornica = 4;
    char turn1[2+1], turn2[2+1], c;


    while(option != 0 || brNosac != 0 || brKrstarica != 0 || brRazarac != 0 || brPodmornica != 0)
    {
        menu(brNosac, brKrstarica, brRazarac, brPodmornica);
        printf("Unesite izbor:\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                if(brNosac == 0)
                    printf("Maksimalan broj brodova ovog tipa je postavljen!\n");
                else
                {
                    while (counter == 0)
                    {
                        while(counter1 != 2)
                        {
                            counter1 = 0;
                            printf("Unesite koordinate za nosac aviona:\n");
                            scanf("%s", turn1);
                            scanf("%s", turn2);
                            deCode(turn1, &x1, &y1);
                            deCode(turn2, &x2, &y2);
                            if(x2 - x1 == 3 || y2 - y1 == 3)
                                counter1++;
                            if(x2 - x1 >= 4 || y2 - y1 >= 4 || x2 - x1 <3 || y2 - y1 < 3)
                                printf("Nosac aviona je dimenzije 4 x 1!\n");
                            if(turn1[0] == turn2[0])
                            {
                                for(int i = y1; i <= y2 ; i++)
                                {
                                    if(table[i][x1] != 'O')
                                        counter2++;
                                    if((table[i+1][x1] != 'O' && i<9) || (table[i-1][x1] != 'O' && i > 0) || (table[i][x1+1] != 'O' && x1<9) || (table[i][x1-1] != 'O' && x1>0) || ((table[i-1][x1-1] != 'O') && i >0 && x1 >0) || ((table[i+1][x1-1] != 'O') && i<9 && x1 >0) || ((table[i-1][x1+1] != 'O') && i >0 && x1 <9) || ((table[i+1][x1+1] != 'O') && i <9 && x1 <9))
                                    {
                                        printf("Nije moguce postaviti brod jedan pored drugog!\n");
                                        counter2++;
                                    }
                                }
                                if(counter2 == 0)
                                    counter1++;
                                counter2 = 0;
                            }
                            else if(turn1[1] == turn2[1])
                                {
                                    for(int i = x1; i <= x2 ; i++)
                                    {
                                        if(table[y1][i] != 'O')
                                            counter2++;
                                        if((table[y1+1][i] != 'O' && y1<9) || (table[y1-1][i] != 'O' && y1>0) || (table[y1][i+1] != 'O' && i<9) || (table[y1][i-1] != 'O' && i>0) || ((table[y1+1][i+1] != 'O' && y1<9 && i<9)) || ((table[y1-1][i+1] != 'O' && y1>0 && i<9)) || ((table[y1+1][i-1] != 'O' && y1<9 && i>0)) || ((table[y1-1][i-1] != 'O' && y1>0 && i>0)))
                                        {
                                            printf("Nije moguce postaviti brod jedan pored drugog!\n");
                                            counter2++;
                                        }
                                    }
                                    if(counter2 == 0)
                                        counter1++;
                                    counter2 = 0;
                                }

                        }
                        counter1 = 0;
                        if(turn1[0] == turn2[0])
                        {
                            for(int i = y1; i <= y2 ; i++)
                                table[i][x1] = '4';
                            counter ++;
                            system("cls");
                            printf("Nova tabla:\n");
                            printTable1(table);
                        }
                        else if(turn1[1] == turn2[1])
                        {
                            for(int i = x1; i <= x2 ; i++)
                                table[y1][i] = '4';
                            counter ++;
                            system("cls");
                            printf("Nova tabla:\n");
                            printTable1(table);
                        }
                        else
                        {
                            printf("Brod ne moze biti postavljan dijagonalno!\n");
                        }
                    }
                    brNosac--;
                    counter = 0;
                    counter1 = 0;
                }
                break;
            case 2:
                if(brKrstarica == 0)
                    printf("Maksimalan broj brodova ovog tipa je postavljen!\n");
                else
                {
                    while (counter == 0)
                    {
                        while (counter1 != 2)
                        {
                            counter1 = 0;
                            printf("Unesite koordinate za krstaricu:\n");
                            scanf("%s", turn1);
                            scanf("%s", turn2);
                            deCode(turn1, &x1, &y1);
                            deCode(turn2, &x2, &y2);
                            if(x2 - x1 == 2 || y2 - y1 == 2)
                                counter1++;
                            if(x2 - x1 >= 3 || y2 - y1 >= 3 || x2 - x1 <2 || y2 - y1 < 2)
                                printf("Krstarica je dimenzije 3 x 1!\n");
                            if(turn1[0] == turn2[0])
                            {
                                for(int i = y1; i <= y2 ; i++)
                                {
                                    if(table[i][x1] != 'O')
                                        counter2++;
                                    if((table[i+1][x1] != 'O' && i<9) || (table[i-1][x1] != 'O' && i > 0) || (table[i][x1+1] != 'O' && x1<9) || (table[i][x1-1] != 'O' && x1>0) || ((table[i-1][x1-1] != 'O') && i >0 && x1 >0) || ((table[i+1][x1-1] != 'O') && i<9 && x1 >0) || ((table[i-1][x1+1] != 'O') && i >0 && x1 <9) || ((table[i+1][x1+1] != 'O') && i <9 && x1 <9))
                                    {
                                        printf("Nije moguce postaviti brod jedan pored drugog!\n");
                                        counter2++;
                                    }
                                }
                                if(counter2 == 0)
                                    counter1++;
                                counter2 = 0;
                            }
                            else if(turn1[1] == turn2[1])
                                {
                                    for(int i = x1; i <= x2 ; i++)
                                    {
                                        if(table[y1][i] != 'O')
                                            counter2++;
                                        if((table[y1+1][i] != 'O' && y1<9) || (table[y1-1][i] != 'O' && y1>0) || (table[y1][i+1] != 'O' && i<9) || (table[y1][i-1] != 'O' && i>0) || ((table[y1+1][i+1] != 'O' && y1<9 && i<9)) || ((table[y1-1][i+1] != 'O' && y1>0 && i<9)) || ((table[y1+1][i-1] != 'O' && y1<9 && i>0)) || ((table[y1-1][i-1] != 'O' && y1>0 && i>0)))
                                        {
                                            printf("Nije moguce postaviti brod jedan pored drugog!\n");
                                            counter2++;
                                        }
                                    }
                                    if(counter2 == 0)
                                        counter1++;
                                    counter2 = 0;
                                }
                        }
                        counter1 = 0;
                        if(turn1[0] == turn2[0])
                        {
                            for(int i = y1; i <= y2 ; i++)
                                table[i][x1] = '3';
                            counter ++;
                            system("cls");
                            printf("Nova tabla:\n");
                            printTable1(table);
                        }
                        else if(turn1[1] == turn2[1])
                            {
                                for(int i = x1; i <= x2 ; i++)
                                    table[y1][i] = '3';
                                    counter ++;
                                    system("cls");
                                    printf("Nova tabla:\n");
                                    printTable1(table);
                            }
                            else
                            {
                                printf("Brod ne moze biti postavljan dijagonalno!\n");
                            }
                    }
                    brKrstarica--;
                    counter = 0;
                    counter1 = 0;
                }
                break;
            case 3:
                if(brRazarac == 0)
                    printf("Maksimalan broj brodova ovog tipa je postavljen!\n");
                else
                {
                    while (counter == 0)
                    {
                        while (counter1 != 2)
                        {
                            counter1 = 0;
                            printf("Unesite koordinate za razarac:\n");
                            scanf("%s", turn1);
                            fflush(stdin);
                            scanf("%s", turn2);
                            deCode(turn1, &x1, &y1);
                            deCode(turn2, &x2, &y2);
                            if(x2 - x1 == 1 || y2 - y1 == 1)
                            {
                                counter1++;
                                //printf("Usao\n");
                            }
                            if(x2 - x1 >= 2 || y2 - y1 >= 2 || x2 - x1 <1 || y2 - y1 < 1)
                                printf("Razarac je dimenzije 2 x 1!\n");
                            if(turn1[0] == turn2[0])
                            {
                                for(int i = y1; i <= y2 ; i++)
                                {
                                    if(table[i][x1] != 'O')
                                        counter2++;
                                    if((table[i+1][x1] != 'O' && i<9) || (table[i-1][x1] != 'O' && i > 0) || (table[i][x1+1] != 'O' && x1<9) || (table[i][x1-1] != 'O' && x1>0) || ((table[i-1][x1-1] != 'O') && i >0 && x1 >0) || ((table[i+1][x1-1] != 'O') && i<9 && x1 >0) || ((table[i-1][x1+1] != 'O') && i >0 && x1 <9) || ((table[i+1][x1+1] != 'O') && i <9 && x1 <9))
                                    {
                                        printf("Nije moguce postaviti brod jedan pored drugog!\n");
                                        counter2++;
                                    }
                                }
                                if(counter2 == 0)
                                    counter1++;
                                counter2 = 0;
                            }
                            else if(turn1[1] == turn2[1])
                                {
                                    for(int i = x1; i <= x2 ; i++)
                                    {
                                        if(table[y1][i] != 'O')
                                            counter2++;
                                        if((table[y1+1][i] != 'O' && y1<9) || (table[y1-1][i] != 'O' && y1>0) || (table[y1][i+1] != 'O' && i<9) || (table[y1][i-1] != 'O' && i>0) || ((table[y1+1][i+1] != 'O' && y1<9 && i<9)) || ((table[y1-1][i+1] != 'O' && y1>0 && i<9)) || ((table[y1+1][i-1] != 'O' && y1<9 && i>0)) || ((table[y1-1][i-1] != 'O' && y1>0 && i>0)))
                                        {
                                            printf("Nije moguce postaviti brod jedan pored drugog!\n");
                                            counter2++;
                                        }
                                    }
                                    if(counter2 == 0)
                                    {
                                        counter1++;
                                        //printf("Usao2\n");
                                    }
                                    counter2 = 0;
                                }
                        }
                        counter1 = 0;
                        //printf("Dosao\n");
                        if(turn1[0] == turn2[0])
                        {
                            for(int i = y1; i <= y2 ; i++)
                                table[i][x1] = '2';
                            counter ++;
                            system("cls");
                            printf("Nova tabla:\n");
                            printTable1(table);
                        }
                        else if(turn1[1] == turn2[1])
                            {
                                for(int i = x1; i <= x2 ; i++)
                                    table[y1][i] = '2';
                                counter ++;
                                system("cls");
                                printf("Nova tabla:\n");
                                printTable1(table);
                            }
                        else
                        {
                            printf("Brod ne moze biti postavljan dijagonalno!\n");
                        }

                    }
                    brRazarac--;
                    counter = 0;
                    counter1 = 0;
                }
                break;
            case 4:
                if(brPodmornica == 0)
                    printf("Maksimalan broj brodova ovog tipa je postavljen!\n");
                else
                {
                    while (counter == 0)
                    {
                        while(counter1 != 1)
                        {
                            counter1 = 0;
                            printf("Unesite koordinatu za podmornicu:\n");
                            scanf("%s", turn1);
                            deCode(turn1, &x1, &y1);
                            if(table[y1][x1] == 'O')
                                counter1++;
                            if((table[y1+1][x1] != 'O' && y1<9) || (table[y1-1][x1] != 'O' && y1>0) || (table[y1][x1+1] != 'O' && x1<9) || (table[y1][x1-1] != 'O' && x1>0) || ((table[y1+1][x1+1] != 'O') && y1<9 && x1<9) || ((table[y1+1][x1-1] != 'O') && y1<9 && x1>0) || (table[y1-1][x1+1] != 'O' && y1>0 && x1<9) || (table[y1-1][x1-1] != 'O' && y1>0 && x1>0))
                            {
                                printf("Nije moguce postaviti brod jedan pored drugog!\n");
                                counter1++;
                            }
                        }
                        counter1 = 0;
                        table[y1][x1] = '1';
                        counter ++;
                        system("cls");
                        printf("Nova tabla:\n");
                        printTable1(table);
                    }
                    brPodmornica--;
                    counter = 0;
                }
                break;
            case 5:
                printf("Unesite koordinate broda za uklanjanje sa table:\n");
                scanf("%s", turn1);
                scanf("%s", turn2);
                deCode(turn1, &x1, &y1);
                deCode(turn2, &x2, &y2);
                if(turn1[0] == turn2[0])
                    {
                        counter = 0;
                        c = table[y1][x1];
                        if(c == 'O')
                        {
                            printf("Nije pronadjen nijedan brod sa ovim koordinatama!\n");
                            break;
                        }
                        for(int i = y1; i <= y2 ; i++)
                            if(table[i][x1] == c)
                                counter++;
                        if(counter == c - '0')
                        {
                            if(c == '1')
                                brPodmornica++;
                            if(c == '2')
                                brRazarac++;
                            if(c == '3')
                                brKrstarica++;
                            if(c == '4')
                                brNosac++;
                            for(int i = y1; i <= y2 ; i++)
                                table[i][x1] = 'O';
                            system("cls");
                            printf("Nova tabla:\n");
                            printTable1(table);
                        }
                        else
                        {
                            system("cls");
                            printTable1(table);
                            printf("Nije pronadjen nijedan brod sa ovim koordinatima!\n");
                        }
                    }
                    else if(turn1[1] == turn2[1])
                        {
                            counter = 0;
                            c = table[y1][x1];
                            if(c == 'O')
                            {
                                printf("Nije pronadjen nijedan brod sa ovim koordinatama!\n");
                                break;
                            }
                            for(int i = x1; i <= x2 ; i++)
                                if(table[y1][i] == c)
                                    counter ++;
                            if(counter == c - '0')
                            {
                                if(c == '1')
                                    brPodmornica++;
                                if(c == '2')
                                    brRazarac++;
                                if(c == '3')
                                    brKrstarica++;
                                if(c == '4')
                                    brNosac++;
                                for(int i = x1; i <= x2 ; i++)
                                    table[y1][i] = 'O';
                                system("cls");
                                printf("Nova tabla:\n");
                                printTable1(table);
                            }
                            else
                            {
                                system("cls");
                                printTable1(table);
                                printf("Nije pronadjen nijedan brod sa ovim koordinatima!\n");
                            }
                        }
                        counter = 0;
                    break;
            case 0:
                if(brNosac > 0 || brRazarac >0 || brKrstarica >0 || brPodmornica >0)
                    printf("Morate postaviti sve brodove da biste zavrsili postavku!\n");
                break;
        }

    }
}
void botTable(char table[10][10]) {
  int i, c, velicina, poz1, poz2, j, smer;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      table[i][j] = 'O';
    }
  }
  for (i = 1; i < 11; i++) {
    if (i == 1) {
      velicina = 4;
    }
    if (i >= 2 && i <= 3) {
      velicina = 3;
    }
    if (i >= 4 && i <= 6) {
      velicina = 2;
    }
    if (i >= 7 && i <= 10) {
      velicina = 1;
    }
    c = 0;
    while (c == 0) {
      poz1 = rand() % 10;
      poz2 = rand() % 10;
      smer = rand() % 4 + 1;
      if (smer == 1) {
        c = 1;
        for (j = poz1; j > poz1 - velicina; j--) {
          if (table[j][poz2] != 'O' || j < 0 || (table[j - 1][poz2] != 'O' && j - 1 >= 0) || (table[j - 1][poz2 + 1] != 'O' && j - 1 >= 0 && poz2 + 1 <= 9) || (table[j][poz2 + 1] != 'O' && poz2 + 1 <= 9) || (table[j + 1][poz2 + 1] != 'O' && j + 1 <= 9 && poz2 + 1 <= 9) || (table[j + 1][poz2] != 'O' && j + 1 <= 9) || (table[j + 1][poz2 - 1] != 'O' && j + 1 <= 9 && poz2 - 1 >= 0) || (table[j][poz2 - 1] != 'O' && poz2 - 1 >= 0) || (table[j - 1][poz2 - 1] != 'O' && j - 1 >= 0 && poz2 - 1 >= 0)) {
            c = 0;
            break;
          }
        }
        if (c == 1) {
          for (j = poz1; j > poz1 - velicina; j--) {
            table[j][poz2] = velicina + '0';
          }
        }
      }
      if (smer == 2) {
        c = 1;
        for (j = poz2; j < poz2 + velicina; j++) {
          if (table[poz1][j] != 'O' || j > 9 || (table[poz1 - 1][j] != 'O' && poz1 - 1 >= 0) || (table[poz1 - 1][j + 1] != 'O' && poz1 - 1 >= 0 && j + 1 <= 9) || (table[poz1][j + 1] != 'O' && j + 1 <= 9) || (table[poz1 + 1][j + 1] != 'O' && poz1 + 1 <= 9 && j + 1 <= 9) || (table[poz1 + 1][j] != 'O' && poz1 + 1 <= 9) || (table[poz1 + 1][j - 1] != 'O' && poz1 + 1 <= 9 && j - 1 >= 0) || (table[poz1][j - 1] != 'O' && j - 1 >= 0) || (table[poz1 - 1][j - 1] != 'O' && poz1 - 1 >= 0 && j - 1 >= 0)) {
            c = 0;
            break;
          }
        }
        if (c == 1) {
          for (j = poz2; j < poz2 + velicina; j++) {
            table[poz1][j] = velicina + '0';
          }
        }
      }
      if (smer == 3) {
        c = 1;
        for (j = poz1; j < poz1 + velicina; j++) {
          if (table[j][poz2] != 'O' || j > 9 || (table[j - 1][poz2] != 'O' && j - 1 >= 0) || (table[j - 1][poz2 + 1] != 'O' && j - 1 >= 0 && poz2 + 1 <= 9) || (table[j][poz2 + 1] != 'O' && poz2 + 1 <= 9) || (table[j + 1][poz2 + 1] != 'O' && j + 1 <= 9 && poz2 + 1 <= 9) || (table[j + 1][poz2] != 'O' && j + 1 <= 9) || (table[j + 1][poz2 - 1] != 'O' && j + 1 <= 9 && poz2 - 1 >= 0) || (table[j][poz2 - 1] != 'O' && poz2 - 1 >= 0) || (table[j - 1][poz2 - 1] != 'O' && j - 1 >= 0 && poz2 - 1 >= 0)) {
            c = 0;
            break;
          }
        }
        if (c == 1) {
          for (j = poz1; j < poz1 + velicina; j++) {
            table[j][poz2] = velicina + '0';
          }
        }
      }
      if (smer == 4) {
        c = 1;
        for (j = poz2; j > poz2 - velicina; j--) {
          if (table[poz1][j] != 'O' || j < 0 || (table[poz1 - 1][j] != 'O' && poz1 - 1 >= 0) || (table[poz1 - 1][j + 1] != 'O' && poz1 - 1 >= 0 && j + 1 <= 9) || (table[poz1][j + 1] != 'O' && j + 1 <= 9) || (table[poz1 + 1][j + 1] != 'O' && poz1 + 1 <= 9 && j + 1 <= 9) || (table[poz1 + 1][j] != 'O' && poz1 + 1 <= 9) || (table[poz1 + 1][j - 1] != 'O' && poz1 + 1 <= 9 && j - 1 >= 0) || (table[poz1][j - 1] != 'O' && j - 1 >= 0) || (table[poz1 - 1][j - 1] != 'O' && poz1 - 1 >= 0 && j - 1 >= 0)) {
            c = 0;
            break;
          }
        }
        if (c == 1) {
          for (j = poz2; j > poz2 - velicina; j--) {
            table[poz1][j] = velicina + '0';
          }
        }
      }

    }
  }

}
void printTable(char table[10][10], char tableMark[10][10],int i) {
     HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    if(i != 1){
            printf("     A    B    C    D    E    F    G    H    I    J\n");
    printf("  ");
  for (int i = 0; i < 52; i++)
    printf("-");
  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("%d |  ",i);
    for (int j = 0; j < 10; j++) {
      if (table[i][j] == 'X' && tableMark[i][j] != 'O') {
        SetConsoleTextAttribute(hConsole, 12);
        if (j == 9) {
          printf("%c  ", table[i][j]);
          SetConsoleTextAttribute(hConsole, 7);
          printf("|");
        } else printf("%c    ", table[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
      } else if(tableMark[i][j] == 'O' && table[i][j] == 'X'){
          if(j == 9){
                        SetConsoleTextAttribute(hConsole, 9);
          printf("X  ",table[i][j]);
                  SetConsoleTextAttribute(hConsole, 7);
                  printf("|");

          }
          else{
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("X    ");
                                     SetConsoleTextAttribute(hConsole, 7);
          }
      }
      else {
        if (j == 9) printf("%c  |", table[i][j]);
        else printf("%c    ", table[i][j]);
      }

    }
    if (i < 9)
      printf("\n  |                                                  |\n");
    else printf("\n");
  }
      printf("  ");
  for (int i = 0; i < 52; i++)
    printf("-");
  printf("\n");}
  else {
                        printf("     A    B    C    D    E    F    G    H    I    J\n");
              printf("  ");
      for (int i = 0; i < 52; i++)
    printf("-");
  printf("\n");
  for (int i = 0; i < 10; i++) {
    printf("%d |  ",i);
    for (int j = 0; j < 10; j++) {
      if (tableMark[i][j] == 'X' && table[i][j] != 'O') {
        SetConsoleTextAttribute(hConsole, 12);
        if (j == 9) {
          printf("X  ", table[i][j]);
          SetConsoleTextAttribute(hConsole, 7);
          printf("|");
        } else printf("X    ", table[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
      }
        else if(tableMark[i][j] == 'X' && table[i][j] == 'O') {
            SetConsoleTextAttribute(hConsole, 9);
        if (j == 9){ printf("X  ", table[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
        printf("|");
        }
        else {printf("X    ", table[i][j]);
        SetConsoleTextAttribute(hConsole, 7);
        }
      }
      else {
        SetConsoleTextAttribute(hConsole, 7);
        if (j == 9) printf("%c  |", table[i][j]);
        else printf("%c    ", table[i][j]);

      }

    }
    if (i < 9)
      printf("\n  |                                                  |\n");
    else printf("\n");
  }
        printf("  ");
  for (int i = 0; i < 52; i++)
    printf("-");
  printf("\n");


  }
}
void niceprint(char tableMarkPlayer[10][10],char tableBot[10][10],char tablePlayer[10][10],char tableMarkBot[10][10]){
      printf("                         BOT\n");
      printTable(tableMarkPlayer, tableBot,0);
      printf("                       PLAYER\n");
      printTable(tablePlayer,tableMarkBot,1);

}
int botTurn(char table[10][10], char tableMark[10][10], int * velicina, int * index1, int * index2, int * broj, int * smer, int * pobeda,char tableMarkPlayer[10][10],char tableBot[10][10]) {
         HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int poz1, poz2, c = 0, k, potez = 0;
  while (potez == 0) {
    if ( * pobeda == 10)
      return 0;
    if ( * velicina > -1 && * broj < * velicina && * broj > 0) {
      if ( * smer == 1) {
        * index1 = * index1 + 1;
        if ( * index1 > 9 || tableMark[ * index1][ * index2] == 'X') {
          * index1 = * index1 - 1;
          * smer = * smer + 1;
        } else {
          while (potez == 0) {
            if ( * pobeda == 10)
              return 0;
            if ( * index1 > 9) {
              * index1 = * index1 - * broj;
              * smer = 3;
              break;

            }
            if (tableMark[ * index1][ * index2] == 'X' && * broj > 1) {
              * smer = 3;
              * index1 = * index1 - * broj;
              break;

            }
            if (tableMark[ * index1][ * index2] == 'X' && * broj == 1) {
              * smer = * smer + 1;
              * index1 = * index1 - 1;
              break;
            }
            tableMark[ * index1][ * index2] = 'X';
            if (table[ * index1][ * index2] != 'O') {
              * broj = * broj + 1;
                SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je pogodio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
                sleep(2);
                system("cls");
                bot();
                sleep(2);
            }
            if (table[ * index1][ * index2] == 'O' && * broj == 1) {
                                SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je promasio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
              * smer = * smer + 1;
              * index1 = * index1 - 1;
              potez = 1;
              break;

            }
            if (table[ * index1][ * index2] == 'O' && * broj > 1) {
                                    SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je promasio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
               niceprint(tableMarkPlayer,tableBot,table,tableMark);
              * smer = 3;
              * index1 = * index1 - * broj;
              potez = 1;
              break;

            }
            * index1 = * index1 + 1;
            if ( * broj == * velicina) {

              * index1 = * index1 - 1;
              for ( * broj = * index1;* broj > * index1 - * velicina;* broj = * broj - 1) {

                if ( * index2 + 1 <= 9)
                  tableMark[ * broj][ * index2 + 1] = 'X';
                if ( * index2 - 1 >= 9)
                  tableMark[ * broj][ * index2 - 1] = 'X';
                tableMark[ * broj][ * index2] = 'X';
                if ( * broj + 1 <= 9) {
                  tableMark[ * broj + 1][ * index2] = 'X';
                  if ( * index2 - 1 >= 0)
                    tableMark[ * broj + 1][ * index2 - 1] = 'X';
                  if ( * index2 + 1 <= 9)
                    tableMark[ * broj + 1][ * index2 + 1] = 'X';
                }
                if ( * broj - 1 >= 0) {
                  tableMark[ * broj - 1][ * index2] = 'X';
                  if ( * index2 - 1 >= 0)
                    tableMark[ * broj - 1][ * index2 - 1] = 'X';
                  if ( * index2 + 1 <= 9)
                    tableMark[ * broj - 1][ * index2 + 1] = 'X';
                }
              }
                SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je unistio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
            system("cls");
                            niceprint(tableMarkPlayer,tableBot,table,tableMark);
                            sleep(2);
                            system("cls");
                bot();
                sleep(2);

              * broj = 0;
              * index1 = -1;
              * index2 = -1;
              * smer = 1;
              * velicina = -1;
              * pobeda = * pobeda + 1;
              potez = 1;
              c = 0;
              break;
            }
          }
        }
      } else if ( * smer == 2) {
        * index2 = * index2 + 1;
        while (potez == 0) {
          if ( * pobeda == 10)
            return 0;
          if (( * index2 > 9 || tableMark[ * index1][ * index2] == 'X') && * broj == 1) {
            * index2 = * index2 - 1;
            * smer = * smer + 1;
            break;
          } else if (( * index2 > 9 || tableMark[ * index1][ * index2] == 'X') && * broj > 1) {
            * index2 = * index2 - * broj;
            * smer = 4;
            break;
          }
          tableMark[ * index1][ * index2] = 'X';
          if (table[ * index1][ * index2] != 'O') {
            * broj = * broj + 1;
                            SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je pogodio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
                sleep(2);
                system("cls");
                bot();
                sleep(2);
          }
          if (table[ * index1][ * index2] == 'O' && * broj == 1) {
                                SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je promasio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
            * smer = * smer + 1;
            * index2 = * index2 - 1;
            potez = 1;
            break;

          }
          if (table[ * index1][ * index2] == 'O' && * broj > 1) {
                                SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je promasio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
            * smer = 4;
            * index2 = * index2 - * broj;
            potez = 1;
            break;

          }
          * index2 = * index2 + 1;
          if ( * broj == * velicina) {

            * index2 = * index2 - 1;
            for ( * broj = * index2;* broj > * index2 - * velicina;* broj = * broj - 1) {
              if ( * broj + 1 <= 9)
                tableMark[ * index1][ * broj + 1] = 'X';
              if ( * broj - 1 >= 0)
                tableMark[ * index1][ * broj - 1] = 'X';
              tableMark[ * index1][ * broj] = 'X';
              if ( * index1 + 1 <= 9) {
                tableMark[ * index1 + 1][ * broj] = 'X';
                if ( * broj - 1 >= 0)
                  tableMark[ * index1 + 1][ * broj - 1] = 'X';
                if ( * broj + 1 <= 9)
                  tableMark[ * index1 + 1][ * broj + 1] = 'X';
              }
              if ( * index1 - 1 >= 0) {
                tableMark[ * index1 - 1][ * broj] = 'X';
                if ( * broj - 1 >= 0)
                  tableMark[ * index1 - 1][ * broj - 1] = 'X';
                if ( * broj + 1 <= 9)
                  tableMark[ * index1 - 1][ * broj + 1] = 'X';
              }
            }
            SetConsoleTextAttribute(hConsole, 2);
            printf("Bot je unistio brod!\n");
            SetConsoleTextAttribute(hConsole, 7);
                        sleep(2);
            system("cls");
                    niceprint(tableMarkPlayer,tableBot,table,tableMark);
                    sleep(2);
                    system("cls");
                bot();
                sleep(2);
            * broj = 0;
            * index1 = -1;
            * index2 = -1;
            * smer = 1;
            * velicina = -1;
            * pobeda = * pobeda + 1;
            potez = 1;
            c = 0;
            break;
          }
        }
      } else if ( * smer == 3) {
        * index1 = * index1 - 1;
        if ( * index1 < 0 || tableMark[ * index1][ * index2] == 'X') {
          * index1 = * index1 + 1;
          * smer = * smer + 1;
        } else {
          while (tableMark[ * index1][ * index2] == 'O' && potez == 0) {
            if ( * pobeda == 10)
              return 0;
            tableMark[ * index1][ * index2] = 'X';
            if (table[ * index1][ * index2] != 'O') {
              * broj = * broj + 1;
                              SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je pogodio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
                sleep(2);
                system("cls");
                bot();
                sleep(2);
            }
            if ( * index1 > 9) {
              * index1 = * index1 - * broj - 1;
              * smer = 3;
            }
            if (table[ * index1][ * index2] == 'O' && * broj == 1) {
                                    SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je promasio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
              * smer = * smer + 1;
              * index1 = * index1 + 1;
              potez = 1;
              break;

            }
            if (table[ * index1][ * index2] == 'O' && * broj > 1) {
                                    SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je promasio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
              * smer = 3;
              * index1 = * index1 - * broj;
              potez = 1;
              break;

            }
            * index1 = * index1 - 1;
            if ( * broj == * velicina) {
              * index1 = * index1 + 1;
              for ( * broj = * index1;* broj < * index1 + * velicina;* broj = * broj + 1) {

                if ( * index2 + 1 <= 9)
                  tableMark[ * broj][ * index2 + 1] = 'X';
                if ( * index2 - 1 >= 0)
                  tableMark[ * broj][ * index2 - 1] = 'X';
                tableMark[ * broj][ * index2] = 'X';
                if ( * broj + 1 <= 9) {
                  tableMark[ * broj + 1][ * index2] = 'X';
                  if ( * index2 - 1 >= 0)
                    tableMark[ * broj + 1][ * index2 - 1] = 'X';
                  if ( * index2 + 1 <= 9)
                    tableMark[ * broj + 1][ * index2 + 1] = 'X';
                }
                if ( * broj - 1 >= 0) {
                  tableMark[ * broj - 1][ * index2] = 'X';
                  if ( * index2 - 1 >= 0)
                    tableMark[ * broj - 1][ * index2 - 1] = 'X';
                  if ( * index2 + 1 <= 9)
                    tableMark[ * broj - 1][ * index2 + 1] = 'X';
                }

              }
                SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je unistio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
            system("cls");
                            niceprint(tableMarkPlayer,tableBot,table,tableMark);
                            sleep(2);
                            system("cls");
                bot();
                sleep(2);
              * broj = 0;
              * index1 = -1;
              * index2 = -1;
              * smer = 1;
              * velicina = -1;
              * pobeda = * pobeda + 1;
              c = 0;
              potez = 1;
              break;
            }
          }
        }

      } else if ( * smer == 4) {
        * index2 = * index2 - 1;
        if ( * index2 < 0 || tableMark[ * index1][ * index2] == 'X') {

          * smer = * smer + 1;
          * index2 = * index2 + 1;
        } else {
          while (tableMark[ * index1][ * index2] == 'O' && potez == 0) {
            if ( * pobeda == 10)
              return 0;
            tableMark[ * index1][ * index2] = 'X';
            if (table[ * index1][ * index2] != 'O') {
              * broj = * broj + 1;
                              SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je pogodio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
                sleep(2);
                system("cls");
                bot();
                sleep(2);
            }
            if ( * index2 < 0) {
              * index2 = * index2 + * broj;
              * smer = 2;
            }
            if (table[ * index1][ * index2] == 'O' && * broj == 1) {
                                    SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je promasio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
              * smer = * smer + 1;
              potez = 1;
              break;

            }
            if (table[ * index1][ * index2] == 'O' && * broj > 1) {
                                    SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je promasio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
              * smer = 3;
              * index2 = * index2 - * broj;
              potez = 1;
              break;

            }
            * index2 = * index2 - 1;
            if ( * broj == * velicina) {

              * index2 = * index2 + 1;
              for ( * broj = * index2;* broj < * index2 + * velicina;* broj = * broj + 1) {
                if ( * broj + 1 <= 9)
                  tableMark[ * index1][ * broj + 1] = 'X';
                if ( * broj - 1 >= 0)
                  tableMark[ * index1][ * broj - 1] = 'X';
                tableMark[ * index1][ * broj] = 'X';
                if ( * index1 + 1 <= 9) {
                  tableMark[ * index1 + 1][ * broj] = 'X';
                  if ( * broj - 1 >= 0)
                    tableMark[ * index1 + 1][ * broj - 1] = 'X';
                  if ( * broj + 1 <= 9)
                    tableMark[ * index1 + 1][ * broj + 1] = 'X';
                }
                if ( * index1 - 1 >= 0) {
                  tableMark[ * index1 - 1][ * broj] = 'X';
                  if ( * broj - 1 >= 0)
                    tableMark[ * index1 - 1][ * broj - 1] = 'X';
                  if ( * broj + 1 <= 9)
                    tableMark[ * index1 - 1][ * broj + 1] = 'X';
                }
              }
                SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je unistio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
            system("cls");
                            niceprint(tableMarkPlayer,tableBot,table,tableMark);
                            sleep(2);
                            system("cls");
                bot();
                sleep(2);
              * broj = 0;
              * index1 = -1;
              * index2 = -1;
              * smer = 1;
              * velicina = -1;
              * pobeda = * pobeda + 1;
              potez = 1;
              c = 0;
              break;
            }
          }
        }

      }

    } else {
      while (c == 0) {
        if ( * pobeda == 10)
          return 0;
        poz1 = rand() % 10;
        poz2 = rand() % 10;
        if (table[poz1][poz2] == 'O' && tableMark[poz1][poz2] == 'O') {
          c = 1;
          * index1 = -1;
          * index2 = -1;
          * velicina = -1;
          * broj = 0;
          potez = 1;
          tableMark[poz1][poz2] = 'X';
            SetConsoleTextAttribute(hConsole, 3);
            printf("Bot je promasio!\n");
            SetConsoleTextAttribute(hConsole, 7);
                        sleep(2);
            system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
        } else if (table[poz1][poz2] != 'O' && tableMark[poz1][poz2] == 'O') {
          c = 1;
          * velicina = table[poz1][poz2] - '0';
          if ( * velicina > 1) {
                tableMark[poz1][poz2] = 'X';
                SetConsoleTextAttribute(hConsole, 2);
                printf("Bot je pogodio brod!\n");
                SetConsoleTextAttribute(hConsole, 7);
                            sleep(2);
                system("cls");
                niceprint(tableMarkPlayer,tableBot,table,tableMark);
                sleep(2);
                system("cls");
                bot();
                sleep(2);
            * index1 = poz1;
            * index2 = poz2;
            * broj = 1;
            potez = 0;
            c = 1;

          } else {
              SetConsoleTextAttribute(hConsole, 2);
            printf("Bot je unistio brod!\n");
            SetConsoleTextAttribute(hConsole, 7);
            sleep(2);
            system("cls");
            niceprint(tableMarkPlayer,tableBot,table,tableMark);
            sleep(2);
            system("cls");
                bot();
                sleep(2);
            * pobeda = * pobeda + 1;
            if (poz1 + 1 <= 9) {
              tableMark[poz1 + 1][poz2] = 'X';
              if (poz2 - 1 >= 0)
                tableMark[poz1 + 1][poz2 - 1] = 'X';
              if (poz2 + 1 <= 9)
                tableMark[poz1 + 1][poz2 + 1] = 'X';
            }
            if (poz1 - 1 >= 0) {
              if (poz2 - 1 >= 0)
                tableMark[poz1 - 1][poz2 - 1] = 'X';
              tableMark[poz1 - 1][poz2] = 'X';
              if (poz2 + 1 <= 9)
                tableMark[poz1 - 1][poz2 + 1] = 'X';
            }
            if (poz2 + 1 <= 9)
              tableMark[poz1][poz2 + 1] = 'X';
            if (poz2 - 1 >= 0)
              tableMark[poz1][poz2 - 1] = 'X';
            potez = 1;
          }
          tableMark[poz1][poz2] = 'X';

        }
      }
    }
  }
}
void fill(char table[10][10]) {
  int i, j;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      table[i][j] = 'O';
    }
  }
}
int playerTurn(char tableMark[10][10], char table[10][10],int *pobeda1) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  int x, y, counter = 1,velicina,smer,broj = 0,broj1 = 1;;
  char turn[3 + 1];
  while (counter != 0) {
    counter = 0;
    printf("Unesite koordinatu napada:\n");
    scanf("%s", turn);
    deCode(turn, & y, & x);
    printf("%d ", *pobeda1);
    if (x > 9 || y > 9 || x < 0 || y < 0 || tableMark[x][y] == 'X') {
      counter++;
      printf("Greska, pokusajte ponovo!\n");
    }
  }
  tableMark[x][y] = 'X';
  if (table[x][y] != 'O') {
        broj = 1;
    velicina = table[x][y] - '0';
  if(velicina == 1)
  {
      *pobeda1 = *pobeda1 + 1;
       SetConsoleTextAttribute(hConsole, 2);
      printf("\nBrod je unisten!");
     SetConsoleTextAttribute(hConsole, 7);
      return 1;
  }
  else {                SetConsoleTextAttribute(hConsole, 3);
        printf("Brod je pogodjen!");
                    SetConsoleTextAttribute(hConsole, 7);
    for(smer = 1;smer < 5;smer++){
        broj1 = 1;
        if(smer == 1){
            x = x + 1;
                while(tableMark[x][y] == 'X' && table[x][y]  == (velicina + '0') && x < 10){
                        x = x + 1;
                        broj++;
                        broj1++;
                        if(broj == velicina){
                            *pobeda1 = *pobeda1 + 1;
                                            SetConsoleTextAttribute(hConsole, 2);
                            printf("\nBrod je unisten!");
                                            SetConsoleTextAttribute(hConsole, 7);
                            return 1;
                        }


                }
                x = x - broj1;


        }
        if(smer == 2){
            y = y + 1;
                while(tableMark[x][y] == 'X' && table[x][y]  == (velicina + '0') && y < 10){
                        y = y + 1;
                        broj++;
                        broj1++;
                        if(broj == velicina){
                                                SetConsoleTextAttribute(hConsole, 2);
                            printf("\nBrod je unisten!");
                                        SetConsoleTextAttribute(hConsole, 7);
                            *pobeda1 = *pobeda1 + 1;
                           return 1;
                        }


                }
                y = y - broj1;


        }
                if(smer == 3){
            x = x - 1;
                while(tableMark[x][y] == 'X' && table[x][y]  == (velicina + '0') && x > -1){
                        broj++;
                        x = x - 1;
                        broj1++;
                        if(broj == velicina){
                                                SetConsoleTextAttribute(hConsole, 2);
                                  printf("\nBrod je unisten!");
                                        SetConsoleTextAttribute(hConsole, 7);
                            *pobeda1 = *pobeda1 + 1;
                            return 1;
                        }


                }
                x = x + broj1;


        }
                if(smer == 4){
            y = y - 1;
                while(tableMark[x][y] == 'X' && table[x][y]  == (velicina + '0') && y > -1){
                        y = y - 1;
                        broj++;
                        broj1++;
                        if(broj == velicina){
                                                SetConsoleTextAttribute(hConsole, 2);
                                  printf("\nBrod je unisten!");
                                        SetConsoleTextAttribute(hConsole, 7);
                            *pobeda1 = *pobeda1 + 1;
                            return 1;
                        }


                }
                y = y + broj1;


        }


    }
    return 1;
  }
  }
}
void pravila()
{
    printf("----------------------Pravila igre------------------------\n");
    printf("1. Prilikom unosenja brodova brodovi se unose preko koordinata(A0 - A3)\n   koordinate su u opsegu od 0 - 9 i A - J, potrebno je pisati prvo manju pa vecu koordinatu (C5 - C3 -> C3 - C5)\n");
    printf("2. Brodovi ne smeju imati zajednicke tacke, i ne smeju se dodirivati\n");
    printf("3. Brodovi su obelezeni brojevema(Podmornica - 1, Razarac - 2, Krstarica - 3, Nosac aviona - 4\n");
    printf("4. Postavljanje brodova traje dok ne unesete sve brodove i unesete opciju 0 za zavrsetak postavke\n");
    printf("5. Borite se brotiv bota, svaki napad unosite koordinatu za napad, ukoliko ste pogodili brod igrate opet\n");
    printf("6. Pogodjene mete ce na tabli biti obelezena crvenim slovom X, dok one promasene plavim\n");
    printf("7. Pobednik je onaj koji prvi potopi protivniku sve brodove\n\n\n");
}
void deCode(char polje[], int* x, int* y)
{
    if(polje[0] == 'A' || polje[0] == 'a')
        {
            *x = 0;
            *y = polje[1] - '0';
        }
    else if(polje[0] == 'B' || polje[0] == 'b')
            {
                *x = 1;
                *y = polje[1] - '0';
            }
    else if(polje[0] == 'C' || polje[0] == 'c')
            {
                *x = 2;
                *y = polje[1] - '0';
            }
    else if(polje[0] == 'D' || polje[0] == 'd')
           {
                *x = 3;
                *y = polje[1] - '0';
           }
    else if(polje[0] == 'E' || polje[0] == 'e')
            {
                *x = 4;
                *y = polje[1] - '0';
            }
    else if(polje[0] == 'F' || polje[0] == 'f')
            {
                *x = 5;
                *y = polje[1] - '0';
            }
    else if(polje[0] == 'G' || polje[0] == 'g')
            {
                *x = 6;
                *y = polje[1] - '0';
            }
    else if(polje[0] == 'H' || polje[0] == 'h')
            {
                *x = 7;
                *y = polje[1] - '0';
            }
    else if(polje[0] == 'I' || polje[0] == 'i')
            {
                *x = 8;
                *y = polje[1] - '0';
            }
    else if(polje[0] == 'J' || polje[0] == 'j')
            {
                *x = 9;
                *y = polje[1] - '0';
            }
}
printTable1(char table[10][10]){
int i,j;
            printf("     A    B    C    D    E    F    G    H    I    J\n");
                printf("  ");
                  for (int i = 0; i < 52; i++)
    printf("-");
      printf("\n");
      for (int i = 0; i < 10; i++){
        printf("%d |  ",i);
        {for (int j = 0; j < 10; j++){

            if (j == 9) printf("%c  |", table[i][j]);
            else printf("%c    ", table[i][j]);

        }
        if(i != 9)
              printf("\n  |                                                  |\n");

        }
        if(i == 9){
                  printf("  \n");
                  printf("  ");
  for (int i = 0; i < 52; i++)
    printf("-");
  printf("\n");
        }

      }
}


