#include "Pawn.h"


Pawn::Pawn()
{
	move = 0;

	King_Alive = 0;

}

Pawn::Pawn(Position &P, COLOUR C) :PIECE(P,C)
{
	this->move = 0;
}


bool Pawn::Check_killing(Position  &O, PIECE ***B)
{
	Position P = this->Get_Pos();
	COLOUR C = this->Get_COLOUR();


	if (C == C_RED)
	{
		if (O.GetX() - P.GetX() == 1)
		{

			if (O.GetY() - P.GetY() == 1)
			{
				if (B[O.GetX()][O.GetY()] != nullptr)
				{
					if (B[O.GetX()][O.GetY()]->Get_COLOUR() != B[P.GetX()][P.GetY()]->Get_COLOUR())
					{
						return 1;
					}
					else
						return 0;
				}
				else
					return 0;

			}
			else if (P.GetY() - O.GetY() == 1)
			{
				if (B[O.GetX()][O.GetY()] != nullptr)
				{
					if (B[O.GetX()][O.GetY()]->Get_COLOUR() != B[P.GetX()][P.GetY()]->Get_COLOUR())
					{
						return 1;
					}
					else
						return 0;

				}
				else
					return 0;

			}
		}
	}

	if (C == C_BLUE)
		{
			if (P.GetX() - O.GetX() == 1)
			{

				if (O.GetY() - P.GetY() == 1)
				{
					if (B[O.GetX()][O.GetY()] != nullptr)
					{
						if (B[O.GetX()][O.GetY()]->Get_COLOUR() != B[P.GetX()][P.GetY()]->Get_COLOUR())
						{
							return 1;
						}
						else
							return 0;
					}
					else
						return 0;

				}
				else if (P.GetY() - O.GetY() == 1)
				{
					if (B[O.GetX()][O.GetY()] != nullptr)
					{
						if (B[O.GetX()][O.GetY()]->Get_COLOUR() != B[P.GetX()][P.GetY()]->Get_COLOUR())
						{
							return 1;
						}
						else
							return 0;

					}
					else
						return 0;

				}
			}

		}


		return 0;
}

void Pawn::Draw()
{
	
	Position t = PIECE::Get_Pos();

//	int Bx = getmaxx()/8;
//	int By = getmaxy()/8;

	int Bx = 600 / 8;
	int By = 600 / 8;


	int row = t.GetY();
	int col = t.GetX();
	if (row != 0)
	{

		row = row*Bx;
	}
	
	if (col != 0)
	{

		col = col*By;
	}
	circle( row+(By/2)  , col + (By / 2)-5,10);
	line(row + (By / 2), col + (By / 2) + 2, row + (By / 2) + 5, col +(By / 2) + 15);
	line(row + (By / 2), col + (By / 2) + 2, row + (By / 2) - 5, col + (By / 2) + 15);

	line(row + (By / 2) + 5, col + (By / 2) + 15, row + (By / 2) - 5, col + (By / 2) + 15);

}

bool Pawn::Is_Legal(Position &O, PIECE ***B)
{
	Position P = this->Get_Pos();
	int Px = P.GetX();
	int Py = P.GetY();
	int Ox = O.GetX();
	int Oy = O.GetY();
	if (Px == Ox && Oy == Py) //CHECKS SAME 
	{
		return 0;
	}
	COLOUR C = B[Px][Py]->Get_COLOUR();
	if (C == C_BLUE)
	{
		if (Px <= Ox)
		{
			return 0;
		}
		if (this->DID_I_MOVED >= 1)
		{
			if (P.GetX() - O.GetX() != 1)
			{
				return 0;

			}

		}
		if (this->DID_I_MOVED == 0)
		{
			if (P.GetX() - O.GetX() > 2)
			{
				return 0;

			}


		}

		if (Check_killing(O, B))  // CHECKS IF KILLING 
		{
			return 1;
		}


		if (P.GetY() != O.GetY())
		{
			return 0;
		}

		while (Px-1 >= Ox)
		{

			if (!this->Check_90(Position(Px,Py), B))
			{
				return 0;
			}
			Px--;
		}

		return 1;
	}

	if (C == C_RED)
	{
		if (Ox <= Px)
		{
			return 0;
		}


		if (this->DID_I_MOVED >= 1)
		{
			if (O.GetX() - P.GetX() != 1)
			{
				return 0;

			}

		}

		if (this->DID_I_MOVED == 0)
		{
			if (O.GetX() - P.GetX() > 2)
			{
				return 0;

			}

			

		}
		if (Check_killing(O, B))  // CHECKS IF KILLING 
		{
			return 1;
		}

		if (P.GetY() != O.GetY())
		{
			return 0;
		}


		while (Px+1 <= Ox)
		{
 			if (!this->Check_180(Position(Px, Py), B))
			{
				return 0;
			}
			Px++;
		}
		return 1;
	}


	return 1;
}

void Pawn::Print()
{
	cout << "Pawn ";

}

void Pawn::save()
{


	ofstream fout;
	fout.open("PAWN.txt", ios:: app);


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



Pawn::~Pawn()
{
}
