#pragma once
#include <iostream>
#include <vector>

using namespace std;

void displayBoard(char (&board)[100][100],int size);
int playerInput(int player,int x, int y, char(&board)[100][100]);
int checkDraw(char(&board)[100][100], int size);
int checkwin(int x,int y, char(&board)[100][100],int size);
int checkFalseInput(int x, int y, char(&board)[100][100],int size);
int gameUpdate(char(&board)[100][100], int size,int player);
int modePVP(int player, int size, char(&board)[100][100]);
int rand(int r);
int botMove(int size, char(&board)[100][100],char sign);
int botRandom(int size, char(&board)[100][100]);
