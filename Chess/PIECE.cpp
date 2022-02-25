#include "PIECE.h"


PIECE::PIECE()
{
	this->LOC.SetX(0);
	this->LOC.SetY(0);

}
PIECE::PIECE(Position &Obj,COLOUR C)
{
	this->LOC.SetX(Obj.GetX());
	this->LOC.SetY(Obj.GetY());
	this->Color = C;


	this->DID_I_MOVED = 0;
}



Position PIECE::Get_Pos()
{
	

	return this->LOC;

}
void PIECE::Set_Pos(Position &Obj)
{
	this->LOC.SetX(Obj.GetX());
	this->LOC.SetY(Obj.GetY());
	
}
void PIECE::Set_COLOUR(COLOUR O)
{

	this->Color = O;

}


COLOUR PIECE::Get_COLOUR()
{

	return this->Color;

}



bool PIECE::Check_45(Position &O, PIECE ***B)
{
	if (O.GetX() - 1 < 0)
	{
		return 0;

	}
	if (O.GetY() + 1 > 7)
	{
		return 0;

	}


	if (B[O.GetX() - 1][O.GetY() + 1] == nullptr)
	{
		return 1;

	}
	return 0;
}
bool PIECE::Check_135(Position &O, PIECE ***B)
{
	if (O.GetX()-1 < 0)
	{
		return 0;

	}
	if (O.GetY() - 1 < 0)
	{
		return 0;

	}


	if (B[O.GetX() - 1][O.GetY() - 1] == nullptr)
	{
		return 1;

	}
	return 0;
}
bool PIECE::Check_225(Position &O, PIECE ***B)
{
	if (O.GetX()+1 > 7)
	{
		return 0;

	}
	if (O.GetY()-1 < 0)
	{
		return 0;
	}



	if (B[O.GetX() + 1][O.GetY() - 1] == nullptr)
	{
		return 1;

	}
	return 0;
}
bool PIECE::Check_315(Position &O, PIECE ***B)
{
	if (O.GetX()+1 > 7)
	{
		return 0;

	}
	if (O.GetY()+1 > 7)
	{
		return 0;
	}


	if (B[O.GetX() + 1][O.GetY() + 1] == nullptr)
	{
		return 1;

	}
	return 0;
}
bool PIECE::Check_90(Position &O, PIECE ***B)
{
	if (O.GetX()-1 == 0)
	{
		return 0;

	}
	if (B[O.GetX()-1][O.GetY()] == nullptr)
	{
		return 1;
	}

	return 0;
}
bool PIECE::Check_180(Position &O, PIECE ***B)
{
	if ((O.GetX()+1) == 0)
	{
		return 0;

	}


	if (B[O.GetX()+1][O.GetY()] == nullptr)
	{

		return 1;
	}

	return 0;

}

bool PIECE::Check_right(Position &O, PIECE ***B)
{
	if (O.GetY() + 1 >7)
	{
		return 0;

	}
	if (B[O.GetX()][O.GetY()+1] == nullptr)
	{
		return 1;
	}

	return 0;
}
bool PIECE::Check_left(Position &O, PIECE ***B)
{
	if (O.GetY() - 1 <0)
	{
		return 0;

	}
	if (B[O.GetX()][O.GetY() - 1] == nullptr)
	{
		return 1;
	}

	return 0;
}



PIECE::~PIECE()
{
}
