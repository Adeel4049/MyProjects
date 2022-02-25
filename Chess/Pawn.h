#pragma once
#include "PIECE.h"
class Pawn :
	public PIECE
{
	int move;
	int King_Alive;

public:
	Pawn();
	Pawn(Position &obj, COLOUR C);
	bool  Is_Legal(Position &O, PIECE ***B);
	bool if_killing(Position &O, PIECE ***B){ return 1; }
	bool Check_killing(Position  &O, PIECE ***B);
	int Find_king(){ return 0; }
	void Draw();
	void Print();
	Position* King_Pos(){ return nullptr; }

	void save();


	void I_Moved(){ this->DID_I_MOVED = 1; }
	void Reset_I_Moved(){ this->DID_I_MOVED = 0;}

	~Pawn();
};

