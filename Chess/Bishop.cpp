#include "Bishop.h"


Bishop::Bishop()
{
}
Bishop::Bishop(Position &Obj, COLOUR C) :PIECE(Obj, C)
{
	this->King_Alive = 0;
}


bool Bishop::if_killing(Position &O, PIECE ***B)
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


void Bishop:: save()
{
	ofstream fout;
	fout.open("BISHOP.txt", ios::app);


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


	fout << P.GetX() << "  " << P.GetY() << "  " << t <<  endl;



}

bool Bishop::Is_Legal(Position &O, PIECE ***B)
{

	Position P = this->Get_Pos();
	int Px = P.GetX();
	int Py = P.GetY();


	int Ox = O.GetX();
	int Oy = O.GetY();


	if (Px == Ox)
	{
		return 0;
	}
	else
	{
		if (Py == Oy)
		{
			return 0;
		}

	}

	
	if (! (if_Diagnol(Position(Px, Py), Position(Ox, Oy), B)))
	{
		return 0;
	}



	if (Px > Ox && Py < Oy)
	{
		
		while (Px - 1 > Ox && Py + 1 < Oy)
		{

			if (!Check_45(Position(Px, Py), B))
			{
				return 0;

			}
			else
			{
				Px--;
				Py++;

			}
		}
		return 1;
	}

	if (Px > Ox && Py > Oy)
	{
		while ((Px - 1) > Ox && (Py - 1) > Oy)
		{
			if (Px == Ox && Py == Oy)
			{
				return 1;
			}

			Position T(Px, Py);

			if (!Check_135(T, B))
			{
				return 0;

			}
			else
			{
				Px--;
				Py--;

			}
		}
		return 1;
	}



	if (Px < Ox && Py < Oy)
	{

		while (Px + 1 < Ox && Py + 1 < Oy)
		{

			if (!Check_315(Position(Px, Py), B))
			{
				return 0;

			}
			else
			{
				Px++;
				Py++;

			}
		}
		return 1;
	}

	if (Px < Ox && Py > Oy)
	{
		while (Px + 1 < Ox && Py - 1 > Oy)
		{
			if (!Check_225(Position(Px, Py), B))
			{
				return 0;

			}
			else
			{
				Px++;
				Py--;

			}
		}
		return 1;
	}

}

void Bishop::Print()
{

	cout << "Bishop ";

}
void Bishop::Draw()
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
	line(row + (Bx / 2), col + (By / 4), row + (Bx / 4), col + (By /2)+15);
	line(row + (Bx / 2), col + (By / 4), row + (Bx / 2)+15, col + (By / 2) + 15);
	line(row + (Bx / 4), col + (By / 2) + 15, row + (Bx / 2) + 15, col + (By / 2) + 15);

}



bool Bishop::if_Diagnol(Position P, Position O, PIECE ***B)
{
	
	int Px = P.GetX();
	int Py = P.GetY();


	int Ox = O.GetX();
	int Oy = O.GetY();





	if (Px < Ox && Py < Oy)
	{
		for (int i = P.GetX(), c = P.GetY();  i < 8 && c < 8; c++, i++)
			{
				if (i == O.GetX() && c == O.GetY())
				{
					return 1;
				}

			}


	}


	if (Px > Ox && Py < Oy)
	{
			for (int c = P.GetY(), i = P.GetX(); c < 8 && i>=0; c++,i--)
			{
				if (i == O.GetX() && c == O.GetY())
				{
					return 1;
				}

			}


	}


	if (Px > Ox && Py > Oy)
	{

		
		for (int i = P.GetX(),  c = P.GetY(); i >= 0 && c >= 0; c--, i--)
			{
				if (i == O.GetX() && c == O.GetY())
				{
					return 1;
				}

			}


	}

	if (Px < Ox && Py > Oy)
	{


		for (int i = P.GetX(),c = P.GetY(); c >= 0 && i < 8; c--,i++)
			{
				if (i == O.GetX() && c == O.GetY())
				{
					return 1;
				}

			}



	}
	return 0;


}

Bishop::~Bishop()
{
}
