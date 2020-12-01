#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
#include <time.h>

using namespace std;

typedef struct pairNum
{
	int first;
	int second;
}pairN;

void displayBoard(char (&board)[100][100],int size)		//This function is used for drawing and updating the screen
{
	cout << "\n";
	for (int i = 0; i < size; i++)
	{
		cout << "\t";
		for (int j = 0; j < size; j++)
		{
			cout << " | ";
            cout << board[i][j];
		}
		cout << " | ";
		cout << "\n";
	}
}

// This function is to check player input and make change to the vector

int playerInput( int player ,int x, int y, char(&board)[100][100])
{
	if (player == 1)
	{
		board[x][y] = 'X';
	}
	else
	{
		board[x][y] = 'O';
	}
	return 0;
}

int checkDraw(char(&board)[100][100], int size)
{
	int check = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == 'X' || board[i][j]=='O') check++;
		}
	}
	if (check == size*size)
	{
		return 0;
	}
	else return -1;
}


//This function is for checking the winner.
//Return 1 if there is a winner
//Return 0 if there if a draw
//Return -1 to continue the game

int checkwin(int x, int y, char (&board)[100][100],int size)
{
	int check;
	check = checkDraw(board, size);
	if (board[x][y] == board[x][y + 1] && board[x][y] == board[x][y - 1]) return 1;
	else if (board[x][y] == board[x][y + 1] && board[x][y] == board[x][y + 2]) return 1;
	else if (board[x][y] == board[x][y - 1] && board[x][y] == board[x][y - 2]) return 1;
	else if (board[x][y] == board[x + 1][y] && board[x][y] == board[x - 1][y]) return 1;
	else if (board[x][y] == board[x + 1][y] && board[x][y] == board[x + 2][y]) return 1;
	else if (board[x][y] == board[x - 1][y] && board[x][y] == board[x - 2][y]) return 1;
	else if (board[x][y] == board[x + 1][y + 1] && board[x][y] == board[x - 1][y - 1]) return 1;
	else if (board[x][y] == board[x + 1][y + 1] && board[x][y] == board[x + 2][y + 2]) return 1;
	else if (board[x][y] == board[x - 1][y - 1] && board[x][y] == board[x - 2][y - 2]) return 1;
	else if (board[x][y] == board[x - 1][y + 1] && board[x][y] == board[x + 1][y - 1]) return 1;
	else if (board[x][y] == board[x + 1][y - 1] && board[x][y] == board[x + 2][y - 2]) return 1;
	else if (board[x][y] == board[x - 1][y + 1] && board[x][y] == board[x - 2][y + 2]) return 1;
	else if (check == 0) return 0;
	else return -1;
}

int checkFalseInput(int x,int y, char(&board)[100][100],int size)
{
	if (board[x][y] == 'X' || board[x][y] == 'O') return 0;
	else if (x > (size - 1) || y > (size - 1)) return 0;
	else return 1;
}


/*if (board[x][y] == board[x][y + 1] && board[x][y] == board[x][y - 1]) return 1;
else if (board[x][y] == board[x][y + 1] && board[x][y] == board[x][y + 2]) return 1;
else if (board[x][y] == board[x][y - 1] && board[x][y] == board[x][y - 2]) return 1;
else if (board[x][y] == board[x + 1][y] && board[x][y] == board[x - 1][y]) return 1;
else if (board[x][y] == board[x + 1][y] && board[x][y] == board[x + 2][y]) return 1;
else if (board[x][y] == board[x - 1][y] && board[x][y] == board[x - 2][y]) return 1;
else if (board[x][y] == board[x + 1][y + 1] && board[x][y] == board[x - 1][y - 1]) return 1;
else if (board[x][y] == board[x + 1][y + 1] && board[x][y] == board[x + 2][y + 2]) return 1;
else if (board[x][y] == board[x - 1][y - 1] && board[x][y] == board[x - 2][y - 2]) return 1;
else if (board[x][y] == board[x - 1][y + 1] && board[x][y] == board[x + 1][y - 1]) return 1;
else if (board[x][y] == board[x + 1][y - 1] && board[x][y] == board[x + 2][y - 2]) return 1;
else if (board[x][y] == board[x - 1][y + 1] && board[x][y] == board[x - 2][y + 2]) return 1;
else return 0; */

int gameUpdate(char(&board)[100][100], int size,int player)
{
	int check,x,y;
	cout << "\nPlayer 1 is X-------Player 2 is O\n";                                  //instruction
	cout << "Input the coordinate to make your move \n" << endl;
	cout << "Player " << player << " turn ";
	cin >> x >> y;
	check = checkFalseInput(x, y, board, size);
	while (check == 0)
	{
		cout << "Please choose a different tile ";
		cin >> x >> y;
		check = checkFalseInput(x, y, board, size);
	}
	playerInput(player, x, y, board);
	system("CLS");
	displayBoard(board, size);
	
	if (checkwin(x, y, board, size) == 1)
	{
		cout << "Player " << player << " win";
		return 1;
	}
	else if (checkwin(x, y, board, size) == 0)
	{
		cout << "Draw";
		return 0;
	}
	else return -1;
}

int modePVP(int player, int size, char(&board)[100][100])
{
	do
	{
		if(gameUpdate(board, size, player)!=-1) return 0;
		++player;
		if(gameUpdate(board, size, player)!=-1)return 0;
		--player;
	} while (true);
}

int rand(int r)
{
	srand(time(NULL));
	return rand() % r;
}

int botMove(int size, char(&board)[100][100],char sign)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0;j < size; j++)
		{
			if (board[i][j] == ' ' && board[i][j + 1] == sign && board[i][j + 2] == sign)
			{
				board[i][j] = 'O';
				return 1;
			}
			else if (board[i][j] == ' ' && board[i + 1][j] == sign && board[i + 2][j] ==sign)
			{
				board[i][j] = 'O';
				return 1;
			}
			else if (board[i][j] == ' ' && board[i + 1][j + 1] == sign && board[i + 2][j + 2] == sign)
			{
				board[i][j] = 'O';
				return 1;
			}
			else if (board[i][j] == ' ' && board[i - 1][j - 1] == sign && board[i - 2][j - 2] == sign)
			{
				board[i][j] = 'O';
				return 1;
			}
			else if (board[i][j] == sign && board[i][j + 2] == sign && board[i][j + 1] == ' ')
			{
				board[i][j + 1] = 'O';
				return 1;
			}
			else if (board[i][j] == sign && board[i+2][j] == sign && board[i+1][j] == ' ')
			{
				board[i+1][j] = 'O';
				return 1;
			}
			else if (board[i][j] ==sign && board[i+2][j + 2] == sign && board[i+1][j + 1] == ' ')
			{
				board[i+1][j + 1] = 'O';
				return 1;
			}
			else if (board[i][j] == sign && board[i-2][j - 2] == sign && board[i-1][j - 1] == ' ')
			{
				board[i-1][j - 1] = 'O';
				return 1;
			}
		}
	}
	return -1;
}



int botRandom(int size, char(&board)[100][100])
{
	pairN aRnd[100];
	int k = 0;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (board[i][j] == ' ')
			{
				aRnd[k].first = i;
				aRnd[k].second = j;
				k++;
			}
		}
	}
	int r = rand(k);
	board[aRnd[r].first][aRnd[r].second] = 'O';
	return 0;
}