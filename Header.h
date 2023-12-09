#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include<windows.h>

void bot();

void menu(int brNosac, int brKrstarica, int brRazarac, int brPodmornica);

void playerTable(char table[10][10]);

void botTable(char table[10][10]);

void printTable(char table[10][10], char tableMark[10][10],int i);

void niceprint(char tableMarkPlayer[10][10],char tableBot[10][10],char tablePlayer[10][10],char tableMarkBot[10][10]);

int botTurn(char table[10][10], char tableMark[10][10], int * velicina, int * index1, int * index2, int * broj, int * smer, int * pobeda,char tableMarkPlayer[10][10],char tableBot[10][10]);

void fill(char table[10][10]);

int playerTurn(char tableMark[10][10], char table[10][10],int *pobeda1);

void pravila();

void deCode(char polje[], int* x, int* y);

printTable1(char table[10][10]);

void pravila();

#endif // HEADER_H_INCLUDED
