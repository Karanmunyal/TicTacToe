#include<iostream>
using namespace std;
class TICTACTOE
{
private:
	int getXcoord();
	int getYcoord();
	bool placemarker(int x, int y, char current);
	bool checkvictory(char current);
	char board[3][3];
	int n;

public:
	TICTACTOE();
	void playgame();
	void clearboard();
	void printboard();
};
void TICTACTOE::playgame()
{
	cout << "Enter the size :";
	cin >> n;
	char player1 = 'x';
	char player2 = 'o';
	char current = 'x';
	bool isdone = false;
	int x, y;
	int turn = 0;
	while (isdone == false)
	{
		printboard();
		x = getXcoord();
		y = getYcoord();
		if (placemarker(x, y, current) == false)
		{
			cout << "the spot is occupied \n";
		}

		else {
			turn++;
			if (checkvictory (current) == true)
			{
				cout << "The game is over player " << current << " has won \n";
				isdone = true;
			}
			else if (turn == 9)
			{
				cout << "Its a tie game";
				isdone = true;
			}


			if (current == player1)
			{
				current = player2;
			}
			else
			{
				current = player1;
			}
		}
	}
}
int TICTACTOE::getXcoord()
{
	bool isinputbad = true;

	int x;
	while (isinputbad == true){
		
		cout << "Enter the x coordinate \n";
		cin >> x;
		if (x < 1 || x > 3) {
			cout << "invalid Coordinate";
		}
		else {
			isinputbad = false;
		}
			}
	return x - 1;
}


int TICTACTOE::getYcoord()
{
	bool isinputbad = true;

	int y;
	while (isinputbad == true){

		cout << "Enter the y  coordinate \n";
		cin >> y;
		if (y < 1 || y>3){
			cout << "invalid Coordinate";
		}
		else{
			isinputbad = false;

		}
	}
	return y - 1;
}

bool TICTACTOE::placemarker(int x, int y,char current)
{
	if (board[y][x] != ' ')
	{
		return false;
	}
	board[y][x]=current;
}

bool TICTACTOE::checkvictory(char current)
{
	int i,j;
	//horizontal
	for (i = 0; i < n; i++) {
		for (j = 0; j < n;j++)
		{ 
			if (board[i][j] == board[i][j + 1])//(board[i][0] == current) && (board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
			{
			}
		//vertical
		else if ()//(board[i][j] == current) && (board[0][i] == board[1][i]) && (board[1][i] == board[2][i]))
		
		}
		
	}

	if ((board[0][0] == current) && (board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
	{
		return true; 
	}

	if ((board[2][0] == current) && (board[2][0] == board[1][1]) && (board[1][1] == board[0][2]))
	{
		return true;
	}

	return false;
}
TICTACTOE::TICTACTOE()
{
	clearboard();

}
void TICTACTOE::clearboard()
{


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			board[i][j] = ' ';
		}
	}
}
void TICTACTOE:: printboard(){
	
	for (int a = 0; a <= n; a++)

	{
		for (int b = 0; b <= n; b++) {
			cout << char(218) << char(196) << char(191) << " ";	
		} 
		cout << '\n';

		for (int b = 0; b <= n; b++) cout << char(179) <<board[a][b] << char(179) << " ";

		cout << '\n';

		for (int b = 0; b <= n; b++) cout << char(192) << char(196) << char(217) << " ";

		cout << '\n';

	}

}

int main()
{
	char input;
	bool isdone = false;
	TICTACTOE game;
	while (isdone == false) {
		game.playgame();
		cout << "Want to play again (Y/N) ? \n";
		cin >> input;
		if (input == 'N' || input == 'n') //Use toLower()
			isdone = true;
		game.clearboard();
	}
	system("PAUSE");
	return 0;
}


