#include "King.h"


King::King() :PIECE()
{
}
King::King(Position &Obj, COLOUR C) :PIECE(Obj, C)
{
	King_Alive = 1;
		
}
bool King::Is_Legal(Position &O, PIECE ***B)
{
	Position P = this->Get_Pos();
	int Px = P.GetX();
	int Py = P.GetY();
	int Ox = O.GetX();
	int Oy = O.GetY();


	if (Px == Ox)
	{
		if (Py - Oy > 1 || Oy - Py > 1)
		{
			return 0;
		}
		
	}
	if (Py == Oy)
	{
		if (Px - Ox > 1 || Ox - Px > 1)
		{
			return 0;
		}

	}



	if (Px == Ox)
	{
		if (Py - Oy == 1)
		{
			if (B[Px][Py - 1] == nullptr)
			{
				return 1;
			}
			else if (B[Px][Py]->Get_COLOUR() != B[Ox][Oy]->Get_COLOUR())
			{
				return 1;
			}
			else
			return 0;
		}
		else if (Oy - Py ==1)
		{
			if (B[Px][Py + 1] == nullptr)
			{
				return 1;
			}
			else if (B[Px][Py]->Get_COLOUR() != B[Ox][Oy]->Get_COLOUR())
			{
				return 1;
			}
			else
			return 0;
		}


	}
	else 	if (Py == Oy)
	{
		if (Px - Ox == 1)
		{
			if (B[Px-1][Py] == nullptr)
			{
				return 1;
			}
			else if (B[Px][Py]->Get_COLOUR() != B[Ox][Oy]->Get_COLOUR())
			{
				return 1;
			}
			else
			return 0;
		}
		else if (Ox - Px == 1)
		{
			if (B[Px+1][Py] == nullptr)
			{
				return 1;
			}
			else if (B[Px][Py]->Get_COLOUR() != B[Ox][Oy]->Get_COLOUR())
			{
				return 1;
			}

			else
			return 0;
		}

	}



//	Diagnol


	if (Px > Ox && Py < Oy)
	{
		if (Px - Ox != 1 || Oy - Py != 1)
		{
			return 0;
		}

			if (!Check_45(Position(Px, Py), B))
			{
				if (B[Px][Py]->Get_COLOUR() != B[Ox][Oy]->Get_COLOUR())
				{
					return 1;
				}
				else
				{


					return 0;
				}
			}
			
			else
			{
				return 1;
			}

			return 0;
	}
	


	if (Px > Ox && Py > Oy)
	{
		if (Px - Ox != 1 || Py - Oy != 1)
		{
			return 0;
		}


			Position T(Px, Py);

			if (!Check_135(T, B))
			{
				if (B[Px][Py]->Get_COLOUR() != B[Ox][Oy]->Get_COLOUR())
				{
					return 1;
				}
				else
				return 0;

			}
			else
			{
				return 1;
			}
			return 0;
	}
	
	



	if (Px < Ox && Py < Oy)
	{
	
		if (Ox - Px != 1 || Oy - Py != 1)
		{
			return 0;
		}	
			if (!Check_315(Position(Px, Py), B))
			{
				if (B[Px][Py]->Get_COLOUR() != B[Ox][Oy]->Get_COLOUR())
				{
					return 1;
				}
				else
				return 0;

			}
			else
			{
				return 1;
			}
		return 0;
	}

	if (Px < Ox && Py > Oy)
	{
	
		if (Ox - Px != 1 || Py - Oy != 1)
		{
			return 0;
		}

	
			if (!Check_225(Position(Px, Py), B))
			{
				if (B[Px][Py]->Get_COLOUR() != B[Ox][Oy]->Get_COLOUR())
				{
					return 1;
				}
				else
				return 0;

			}
			else
			{
				return 1;
			}
		
		return 0;
	}


}
void King::Print()
{
	
	cout << "KING ";

}
void King::Draw()
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


	rectangle(row + (Bx / 4) + 5, col + (By / 2) - 10, row + 12 + (Bx / 2), col + (By / 2) + 10);
	line(row + (Bx / 4) + 5, col + (By / 2) - 10, row + (Bx / 4) - 5, col + (By / 4) - 5);
	line(row + 12 + (Bx / 2), col + (By / 2) - 10, row + Bx-10, col + (By / 4) - 5);

	line(row + (Bx / 4) - 5, col + (By / 4) - 5, row + Bx - 10, col + (By / 4) - 5);


}

void King::save()
{
	ofstream fout;
	fout.open("KING.txt", ios::app);

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

King::~King()
{
}
