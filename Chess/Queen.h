#pragma once
#include "PIECE.h"
class Queen :
	public PIECE
{
	int King_Alive;
public:
	Queen();
	
	Queen(Position &Obj,COLOUR C);
	bool Is_Legal(Position &P, PIECE ***B);

	bool if_killing(Position &O, PIECE ***B);
	int Find_king(){ return this->King_Alive; }
	void Print();
	void Draw();
	void I_Moved(){ ; }
	Position* King_Pos(){ return nullptr; }
	bool Queen::if_Diagnol(Position P, Position O, PIECE ***B);


	void save();
	void Reset_I_Moved(){ ; }

	~Queen();
};

