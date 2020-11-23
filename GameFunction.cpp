#include <iostream>
#include <string>
#include <vector>

using namespace std;

void board(vector<char> &square)		//This function is used for drawing and updating the screen
{
	cout << "\n\t| " <<square[0]  << " | " << square[1] << " | " << square[2] <<" |" << endl;
	cout << "\t-------------" << endl;
	cout << "\t| " << square[3] << " | " << square[4] << " | " << square[5] <<" |"<< endl;
	cout << "\t-------------" << endl;
	cout << "\t| " << square[6] << " | " << square[7] << " | " << square[8] <<" |"<< endl;
}

// This function is to check player input and make change to the vector

int playerInput( int player , char choice,vector<char> &square) 
{
	if (player==1 && choice == '1' && square[0]!='X' && square[0]!='O')
	{
		square[0] = 'X';
	}
	else if (player == 2 && choice == '1' && square[0] != 'X' && square[0] != 'O')
	{
		square[0] = 'O';
	}

	if (player == 1 && choice == '2' && square[1] != 'X' && square[1] != 'O')
	{
		square[1] = 'X';
	}
	else if(player == 2 && choice == '2' && square[1] != 'X' && square[1] != 'O')
	{
		square[1] = 'O';
	}

	if (player == 1 && choice == '3' && square[2] != 'X' && square[2] != 'O')
	{
		square[2] = 'X';
	}
	else if(player == 2 && choice == '3' && square[3] != 'X' && square[3] != 'O')
	{
		square[2] = 'O';
	}

	if (player == 1 && choice == '4' && square[3] != 'X' && square[3] != 'O')
	{
		square[3] = 'X';
	}
	else if(player == 2 && choice == '4' && square[3] != 'X' && square[3] != 'O')
	{
		square[3] = 'O';
	}

	if (player == 1 && choice == '5' && square[4] != 'X' && square[4] != 'O')
	{
		square[4] = 'X';
	}
	else if(player == 2 && choice == '5' && square[4] != 'X' && square[4] != 'O')
	{
		square[4] = 'O';
	}
	
	if (player == 1 && choice == '6' && square[5] != 'X' && square[5] != 'O')
	{
		square[5] = 'X';
	}
	else if(player == 2 && choice == '6' && square[5] != 'X' && square[5] != 'O')
	{
		square[5] = 'O';
	}

	if (player == 1 && choice == '7' && square[6] != 'X' && square[6] != 'O')
	{
		square[6] = 'X';
	}
	else if(player == 2 && choice == '7' && square[6] != 'X' && square[6] != 'O')
	{
		square[6] = 'O';
	}
	
	if (player == 1 && choice == '8' && square[7] != 'X' && square[7] != 'O')
	{
		square[7] = 'X';
	}
	else if( player == 2 && choice == '8' && square[7] != 'X' && square[7] != 'O')
	{
		square[7] = 'O';
	}

	if (player == 1 && choice == '9' && square[8] != 'X' && square[8] != 'O')
	{
		square[8] = 'X';
	}
	else if(player == 2 && choice == '9' && square[8] != 'X' && square[8] != 'O')
	{
		square[8] = 'O';
	}

	return 0;

}

//This function is for checking the winner.
//Return 1 if there is a winner
//Return 0 if there if a draw 
//Return -1 to continue the game

int checkwin(vector<char>& square)
{
	if (square[0] == square[1] && square[1] == square[2])
	{
		return 1;
	}

	else if (square[0] == square[3] && square[3] == square[6])
	{
		return 1;
	}

	else if (square[0] == square[4] && square[4] == square[8])
	{
		return 1;
	}

	else if (square[3] == square[4] && square[4] == square[5])
	{
		return 1;
	}

	else if (square[6] == square[7] && square[7] == square[8])
	{
		return 1;
	}

	else if (square[1] == square[4] && square[4] == square[7])
	{
		return 1;
	}

	else if (square[2] == square[5] && square[5] == square[8])
	{
		return 1;
	}

	else if (square[2] == square[4] && square[4] == square[6])
	{
		return 1;
	}

	else if (square[0] != '1' && square[1] != '2' && square[2] != '3' && square[3] != '4' && square[4] != '5' && square[5] != '6' && square[6] != '7' && square[7] != '8' && square[8] != '9')
	{
		return 0;
	}
	else return -1;
	
}

int checkFalseInput(int* player,char *choice, vector<char>& square)
{
	int x = (int)*choice - 48;
	if (square[x - 1] == 'X' || square[x - 1] == 'O')
	{
		return 0;
	}
	else return 1;
}
