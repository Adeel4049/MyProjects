#include "Knight.h"


Knight::Knight()
{
}
Knight::Knight(Position &Obj, COLOUR C) :PIECE(Obj, C)
{
	this->King_Alive = 0;
}
bool Knight::Is_Legal(Position &O,PIECE ***B)
{

	Position P = this->Get_Pos();
	int Px = P.GetX();
	int Py = P.GetY();
	int Ox = O.GetX();
	int Oy = O.GetY();
	
	if (Px - Ox == 1)             // 1
	{
		if (Py - Oy == 2)
		{
			if (B[Px-1][Py-2] == nullptr)
			{
				return 1;
			}
			else if (B[P.GetX()][P.GetY()]->Get_COLOUR() != B[O.GetX()][O.GetY()]->Get_COLOUR())
			{
				return 1;
			}
			else
			{
				return 0;
			}

		}
		else if (Oy - Py==2)
		{
			if (B[Px-1][Py+2] == nullptr)
			{
				return 1;
			}
			else if (B[P.GetX()][P.GetY()]->Get_COLOUR() != B[O.GetX()][O.GetY()]->Get_COLOUR())
			{
				return 1;
			}

			else
			{
				return 0;
			}

		}
	}
	else if (Ox - Px == 1)           //        2nd
	{
		if (Py - Oy == 2)
		{
			if (B[Px+1][Py-2] == nullptr)
			{
				return 1;
			}
			else if (B[P.GetX()][P.GetY()]->Get_COLOUR() != B[O.GetX()][O.GetY()]->Get_COLOUR())
			{
				return 1;
			}

			else
			{
				return 0;
			}

		}
		else if (Oy - Py== 2)
		{
			if (B[Px+1][Py+2] == nullptr)
			{
				return 1;
			}
			else if (B[P.GetX()][P.GetY()]->Get_COLOUR() !=B[O.GetX()][O.GetY()]->Get_COLOUR())
			{
				return 1;
			}

			else
			{
				return 0;
			}

		}

	}
	else if (Px - Ox == 2)
	{
		if (Py - Oy == 1)
		{
			if (B[Px-2][Py-1] == nullptr)
			{
				return 1;
			}
			else if (B[P.GetX()][P.GetY()]->Get_COLOUR() != B[O.GetX()][O.GetY()]->Get_COLOUR())
			{
				return 1;
			}

			else
			{
				return 0;
			}
		}
		else if (Oy - Py == 1)
		{
			if (B[Px-2][Py+1] == nullptr)
			{
				return 1;
			}
			else if (B[P.GetX()][P.GetY()]->Get_COLOUR() != B[O.GetX()][O.GetY()]->Get_COLOUR())
			{
				return 1;
			}

			else
			{
				return 0;
			}
		}
	}
	else if (Ox - Px == 2)
	{
		if (Py - Oy == 1)
		{
			if (B[Px+2][Py-1] == nullptr)
			{
				return 1;
			}
			else if (B[P.GetX()][P.GetY()]->Get_COLOUR() != B[O.GetX()][O.GetY()]->Get_COLOUR())
			{
				return 1;
			}

			else
			{
				return 0;
			}
		}
		else if (Oy - Py == 1)
		{
			if (B[Px+2][Py+1] == nullptr)
			{
				return 1;
			}
			else if (B[P.GetX()][P.GetY()]->Get_COLOUR() != B[O.GetX()][O.GetY()]->Get_COLOUR())
			{
				return 1;
			}

			else
			{
				return 0;
			}
		}
	}

	return 0;
}
void Knight::Print()
{

	cout << "Knight ";

}
void Knight::Draw()
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

	rectangle(row + (Bx / 4) + 8, col + (By / 4) - 5, row + (Bx / 2) + 5, col + By - 20);
	rectangle(row + (Bx / 4), col + (By / 4), row + Bx - (Bx / 4), col + (By / 2));





}

void Knight::save()
{
	ofstream fout;
	fout.open("KNIGHT.txt", ios::app);

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

Knight::~Knight()
{
}
