#include "tictactoe.h"
#include <string>
#include <string.h>
#include <iostream>

using namespace std;
tictactoe::tictactoe()
{
	reset();
}

// This function checks if the desired move of player is legal.
//It checks if that entry of the matrix is empty
bool tictactoe::move(int row, int col){
	if (Board[row][col] == NULL){
		if (row <= 2 && row >= 0 && col <= 2 && col >= 0){
			return true;
		}
	}
	return false;
}
// this function prints out the board 
void tictactoe::print(){
	int i, j;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (Board[i][j] == NULL)
				cout << "-  ";
			else
				cout << Board[i][j] << "  ";
		}
		cout << endl;
	}
}
//This function sets all the entries of the matrix back to null
void tictactoe::reset(){
	int i, j;
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			Board[i][j] = NULL;
		}
	}
}
string tictactoe::over(){
	int i;
	int j;
	char winner = NULL;
	for (i = 0; i < 3; i++){
		if (Board[i][0] == Board[i][1] && Board[i][0] == Board[i][2]){	//Checks if one of the players has fulled up a row
			if (Board[i][0] != NULL)
				winner = Board[i][0];
		}

		if (Board[0][i] == Board[1][i] && Board[0][i] == Board[2][i]){	//Checks if one of the players has fulled up a column
			if (Board[0][i] != NULL)
				winner = Board[0][i];
		}
	}

	if (Board[0][0] == Board[1][1] && Board[2][2]){		//Checks if player fulled up the diagonal from top left to bottom right 
		if (Board[0][0] != NULL)
			winner = Board[0][0];
	}

	if (Board[0][2] == Board[1][1] && Board[2][0]){		//Checks if player fulled up the diagonal from top right to bottom left 
		if (Board[0][2] != NULL)
			winner = Board[0][2];
	}
	if (winner == 'X')
		return "Player 1 wins";
	else if (winner == 'O')
		return "Player 2 wins";

	// If there is no winner yet

	// This will check if there is an empty entry in the matrix. if not then the game is a draw
	for (i = 0; i < 3; i++){
		for (j = 0; j < 3; j++){
			if (move(i, j))
				return "Game is still in progress";
		}
	}

	return "Game is a draw";
}
void tictactoe::SetRowCol(int row, int col, char x) {
	Board[row][col] = x;
}
tictactoe::~tictactoe()
{
}


int main(){
	tictactoe game;
	bool StillPlaying = true;
	string status; //
	char NewGame;
	int row, col;
	int Player = 1; //This stores who's turn it is
	while (StillPlaying) {
		cout << "Current Board" << endl << endl;
		game.print(); //Prints out board
		cout << endl << "Player " << Player << " please enter the row and column of your move (row:col)" << endl;
		cin >> row;
		cin.ignore(1, ':') >> col;
		row -= 1; //The user will enter a 1 for the first row or column but in the array this corresponds to position 0
		col -= 1;
		if (game.move(row, col)) {	//If it's a legal move, then set it
			if (Player == 1) {
				game.SetRowCol(row, col, 'X');
				Player = 2;		//Once move Done then next Player's turn
			}
			else {
				game.SetRowCol(row, col, 'O');
				Player = 1;
			}
		}
		else {	//If not legal move then Player must re-enter a move. This is done by restarting loop.
			cout << "That is not a legal move" << endl << endl;
		}
		status = game.over();
		if (status != "Game is still in progress") {
			game.print();
			cout << status << endl << endl; //Prints out who won or if it was a draw
			cout << "Would you like to play again? (Y/N)";
			cin >> NewGame;
			if (NewGame == 'Y' || NewGame == 'y') { // If do want to play again then resets board and it makes it Player 1's turn
				game.reset();
				Player = 1;
			}
			else
				return 0;
		}
	}
}