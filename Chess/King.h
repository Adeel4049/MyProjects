#pragma once

#include "PIECE.h"

class King : public PIECE
{

	int King_Alive;

public:
	King();
	King(Position &,COLOUR);
	
	bool Is_Legal(Position &P, PIECE ***B);
	void Print();
	void Draw();
	void King::save();

	bool if_killing(Position &O, PIECE ***B){ return 1; }
	int Find_king(){ return this->King_Alive; }

	void I_Moved(){ this->DID_I_MOVED = 1; }
	void Reset_I_Moved(){ this->DID_I_MOVED = 0; }

	Position* King_Pos(){ Position P = PIECE::Get_Pos(); return &P; };


	~King();
};

