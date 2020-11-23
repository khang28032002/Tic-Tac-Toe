#pragma once
#include < iostream>
#include <vector>

using namespace std;

void board(vector<char> &square);
int playerInput(int player, char choice, vector<char> &square);
int checkwin(vector<char> &square);
int checkFalseInput(int* player,char *choice, vector<char> &square);