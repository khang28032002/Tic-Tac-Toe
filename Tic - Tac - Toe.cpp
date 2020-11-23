// Tic - Tac - Toe v1.0
//It still have many failed testcases and a lot to improve
//Graphic and sound is still in progress, AI for 1 player will be add in the near future

#include <iostream>
#include "GameFunction.h"
#include <vector>
#include<stdlib.h>

using namespace std;

int main()
{
    vector<char> square;
    char c = '1';
    int player = 1;
    char choice = '0';
    int i = -1;
    int check;
    for (int i = 0; i < 9; i++)                         //input element into the vector
    {
        square.push_back(c);
        c = (int)c + 1;
        c = (char)c;
    }
    board(square);                                      //render the board 
    do
    {
        cout << "Welcome to Tic Tac Toe game \nThis is my first Tic Tac Toe game\n\n";
        cout << "Player 1 is X-------Player 2 is O\n" ;                 //instruction
        cout << "Input the tile number to make your move \n"<<endl;
        cout << "Player " << player << " turn " << endl;
        cin >> choice;                                          //input the tile number
        check = checkFalseInput(&player, &choice, square);
        while (check != 1)
        {
            cout << "Please choose a different tile " << endl;
            cin >> choice;
            check = checkFalseInput(&player, &choice, square);
        }
        playerInput(player, choice, square);                    //check input and make the move
        system("CLS");                                          //clear screen
        board(square);                                          //update the screen
        i=checkwin(square);                                     //check winner
        if (i == 1)
        {
            cout << "Player " << player << " win ";
            return 0;
        }
        else if (i == 0)
        {
            cout << "Draw";
            return 0;
        }
        player+=1;                                              //change to next player
        cout << "Welcome to Tic Tac Toe game \nThis is my first Tic Tac Toe game\n\n";
        cout << "Player 1 is X-------Player 2 is O\n";
        cout << "Input the tile number to make your move \n"<<endl;
        cout << "Player " << player << " turn " << endl;
        cin >> choice;
        check = checkFalseInput(&player, &choice, square);
        while (check != 1)
        {
            cout << "Please choose a different tile " << endl;
            cin >> choice;
            check = checkFalseInput(&player, &choice, square);
        }
        playerInput(player, choice, square);
        system("CLS");
        board(square);
        i = checkwin(square);
        if (i == 1)
        {
            cout << "Player " << player << " win ";
            return 0;
        }
        else if (i == 0)
        {
            cout << "Draw";
            return 0;
        }
        player-=1;

    } while (i == -1);
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
