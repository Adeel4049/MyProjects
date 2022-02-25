#pragma once
#include"PIECE.h"
#include"graphics.h"

#include"King.h"
#include"Position.h"
#include"Queen.h"
#include"Pawn.h"
#include"Rook.h"
#include"Knight.h"
#include"Bishop.h"
#include"Stack.h"
#include<fstream>


class Board
{
private:

	PIECE ***B;
	int row;
	int col;


	int Grid_row;       //row in grid
	int Grid_col;		// coloumn in a grid
	int rr;				// row in one rectangle
	int rc;				
	
	COLOUR Turn;


	Position PreS;
	Position PreD;

	Stack<Position>Source;
	Stack<Position>Destination;



	void MakeArray();
	void Create_Board();

	void Board::Turn_message();
public:
	

	void Print();
	void Make_Grid();
	void Print_Square(int r,int c,colors C);
	void Create_Player();
	void Move(Position &P1, Position &P2);
	void PLAY();

	void Board::Change_Turn();
	void Board::get_xy(int &x, int &y);
	int Board::Get_input(int &x, int &y);
	bool Board::Is_king();
	bool Board::Check_undo(int ,int);
	void Board::Change_col(Position &P, colors C);
	void Board::Highlight(Position P);

	void Board::Save();

	void Board::Undo_high();
	bool Board::Check();
	bool Board::Is_King_Dying(Position P);
	void Board::DRAW_UNDO();
	void Board::UNDO();
	void Board::Check_undo();
	bool Board::Self_check();

	void Board::Load();
	Board();
	~Board();
};

