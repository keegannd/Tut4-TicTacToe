#pragma once
#include <string>
using namespace std;
class tictactoe
{
private:
	char Board[3][3];
public:
	tictactoe();
	bool move(int row, int col);
	void print();
	void reset();
	string over();
	void SetRowCol(int row, int col, char x);
	~tictactoe();
};