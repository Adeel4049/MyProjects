#include "Rook.h"


Rook::Rook()
{
}
Rook ::Rook(Position &Obj, COLOUR C) :PIECE(Obj, C)
{
	this->King_Alive = 0;
}
bool Rook:: Is_Legal(Position &O, PIECE ***B)
{

	Position P = this->Get_Pos();
	int Px = P.GetX();
	int Py = P.GetY();


	int Ox = O.GetX();
	int Oy = O.GetY();
	

	if (Ox == Px)  // CHECK IF SAME 
	{
		if (Oy == Py)
		{
			return 0;

		}

	}
	if (Px == Ox)
	{
		if (Py < Oy)
		{	
			while (Py+1 <  Oy)
				{
					if (!Check_right(Position(Px, Py), B))
					{
						return 0;
					}
					else
					{
						Py++;
					}
				}


			}
			else
			{
				while (Py-1 < Oy)
				{
					if (!Check_left(Position(Px, Py), B))
					{
						return 0;
					}
					else
					{
						Py--;
					}
				}
			}
		return 1;
	}
	if (Py == Oy)
	{
		if (Px < Ox)
		{

			while (Px+1 < Ox)
			{
				if (!Check_180(Position(Px, Py), B))
				{
					return 0;
				}
				else
				{
					Px++;
				}
			}


		}
		else
		{
			while (Px-1 > Ox)
			{
				if (!Check_90(Position(Px, Py), B))
				{
					return 0;
				}
				else
				{
					Px--;
				}
			}
			
		}

		return 1;
	}

	return 0;

}
void Rook::Print()
{
	cout << "Rook ";

}
void Rook::Draw()
{
	Position t = PIECE::Get_Pos();

	int row = t.GetY();
	int col = t.GetX();


	int Bx = 600 / 8;
	int By = 600 / 8;



	if (row != 0)
	{

		row = row*Bx;
	}

	if (col != 0)
	{

		col = col*By;
	}


	rectangle(row + (Bx / 4), col + (By / 4) - 2, row + (Bx / 2) + 10, col + (By / 2) - 5);
	rectangle(row + (Bx / 4) + 5, col + (By / 2) - 5, row + (Bx / 2) + 5, col + (By / 2) + 15);


}


bool Rook::if_killing(Position &O, PIECE ***B)
{
	Position P = this->Get_Pos();
	COLOUR C = B[P.GetX()][P.GetY()]->Get_COLOUR();

	int Px = P.GetX();
	int Py = P.GetY();


	int Ox = O.GetX();
	int Oy = O.GetY();


	if (B[Ox][Oy] != nullptr)
	{
		if (B[Ox][Oy]->Get_COLOUR() != B[Px][Py]->Get_COLOUR())
		{
			return 1;
		}

	}
	else if (B[Ox][Oy] == nullptr)
	{
		return 1;
	}
	else
	{

		return 0;

	}

	return 0;
}


void Rook::save()
{
	ofstream fout;
	fout.open("ROOK.txt", ios::app);

	Position P = PIECE::Get_Pos();

	int t;
	if (PIECE::Get_COLOUR() == C_RED)
	{
		t = 1;
	}
	else
	{
		t = 0;
	}


	fout << P.GetX() << "  " << P.GetY() << "  " << t << endl;

}





Rook::~Rook()
{
}
