#pragma once
#include<iostream>
#include<string>

using namespace std;

#include"Position.h"
#include"graphics.h"

#include<fstream>
enum COLOUR{C_RED=0,C_BLUE=1};

class PIECE
{

private:
	
	Position LOC;
	COLOUR Color;

protected:
	int DID_I_MOVED;
	



public:

	virtual void I_Moved() = 0;
	virtual void Reset_I_Moved() = 0;
	PIECE();
	PIECE(Position &, COLOUR C);

	Position Get_Pos();
	void Set_Pos(Position &obj);

	virtual bool Is_Legal(Position &O,PIECE ***B)=0;
	virtual void Print()=0;
	virtual void Draw() = 0;
	virtual bool if_killing(Position &O, PIECE ***B) = 0;


	virtual void save()=0;

	virtual int Find_king()=0;

	virtual Position* King_Pos() = 0;



	COLOUR Get_COLOUR();
	void Set_COLOUR(COLOUR O);


	bool PIECE::Check_90(Position &O,PIECE ***B);
	bool PIECE::Check_180(Position &O, PIECE ***B);
	bool PIECE::Check_225(Position &O, PIECE ***B);
	bool PIECE::Check_315(Position &O, PIECE ***B);
	bool PIECE::Check_45(Position &O, PIECE ***B);
	bool PIECE::Check_135(Position &O, PIECE ***B);

	bool PIECE::Check_left(Position &O, PIECE ***B);
	bool PIECE::Check_right(Position &O, PIECE ***B);
	
	

	~PIECE();


};

