#pragma once
#include "PIECE.h"
class Rook :
	public PIECE
{
	int King_Alive;


public:
	Rook();
	Rook(Position &, COLOUR);
	bool Is_Legal(Position &O, PIECE ***B);
	void Print();
	void Draw();
	int Find_king(){ return this->King_Alive; }
	bool if_killing(Position &O, PIECE ***B);
	void I_Moved(){ ; }
	void Reset_I_Moved(){ ; }
	Position* King_Pos(){  return nullptr; }

	void Rook::save();


	~Rook();
};

