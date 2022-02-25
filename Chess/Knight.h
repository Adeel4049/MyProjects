#pragma once
#include "PIECE.h"
class Knight :
	public PIECE
{
	int King_Alive;
public:
	Knight();
	Knight(Position &, COLOUR);
	bool Is_Legal(Position &O, PIECE ***B);
	bool Knight::Check_Kill(Position &O, PIECE ***B);
	bool if_killing(Position &O, PIECE ***B){ return 1; }
	void Print();
	void Draw();
	void I_Moved(){ ; }
	Position* King_Pos(){ return nullptr; }
	int Find_king(){ return this->King_Alive; }
	void Reset_I_Moved(){ ; }
	void Knight::save();


	~Knight();
};

