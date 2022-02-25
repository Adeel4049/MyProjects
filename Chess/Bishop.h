#pragma once
#include "PIECE.h"
class Bishop :
	public PIECE
{
	int King_Alive;
	
public:


	Bishop();
	Bishop(Position &, COLOUR);
	bool Bishop::Is_Legal(Position &P,PIECE ***B);
	void Print();
	void Draw();
	void Reset_I_Moved(){ ; }


	void save();

	 void I_Moved(){	;}
	 Position* King_Pos(){ return nullptr; }
	bool Bishop::if_Diagnol(Position P, Position O, PIECE ***B);
	bool if_killing(Position &O, PIECE ***B);
	int Find_king(){ return this->King_Alive; }


	~Bishop();
};

