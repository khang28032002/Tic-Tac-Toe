// Tic - Tac - Toe v2.0
//It still have many failed testcases and a lot to improve
//Graphic and sound is still in progress, AI for 1 player will be add in the near future

#include <iostream>
#include "GameFunction.h"
#include <vector>
#include <stdlib.h>
#include <string>

using namespace std;

int main()
{
    cout << "Welcome to Tic Tac Toe game \nThis is my first Tic Tac Toe game\n\n";     //instruction
    int size, mode=0;
    cout << "Choose game mode\n";
    cout << "1: VS Computer----------2: Two Players\n";
    cin >> mode;
    int checkMode= ((mode == 1) || (mode == 2)) ? true : false;
    while (!checkMode)
    {
        cout << "Please choose again ";
        cin >> mode;
        checkMode = ((mode == 1) || (mode == 2)) ? true : false;
    }
    cout << "Input the board size ";
    cin >> size;
    while (size <= 2)
    {
        cout << "Please choose again ";
        cin >> size;
    }
    int  player = 1;
    char board[100][100],pSign='X',cSign='O';
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            board[i][j] =' ';
        }
    }
    system("CLS");
    displayBoard(board,size);
    if (mode == 2)
    {
        modePVP(player, size, board);
    }
    else
    {
        do
        {
            if (gameUpdate(board, size, player) != -1) return 0;
            system("CLS");
            if (botMove(size, board,cSign) == -1)
            {
                if (botMove(size,board,pSign) == -1)
                {
                    botRandom(size, board);
                    displayBoard(board, size);
                }
                else
                {
                    displayBoard(board, size);
                    continue;
                }
                
            }
            else 
            {
                displayBoard(board, size);
                cout << "Computer win";
                return 0;
            }
        } while (true);
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
