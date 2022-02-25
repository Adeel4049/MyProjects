#include "Board.h"


Board::Board()
{

	this->row = 8;
	this->col = 8;

	this->Grid_row = 600;
	this->Grid_col = 600;

	this->rr = this->Grid_row / this->row;
	this->rc = this->Grid_col / this->col;

	this->Turn = C_RED;
	
	MakeArray();
	Create_Board();
	initwindow(Grid_row+60, Grid_col, "First Sample");
	Make_Grid();
	
	setcolor(RED);
	Create_Player();
		

}


void Board::Make_Grid()
{
	bool flag = 1;
	bool flag1 = 0;
	int t1=0, t2=0;

	for (int i = 0; i <= this->row; i++)
	{
		t2 = 0;

		if (flag == 0)
		{
			flag1 = 1;

		}
		else if (flag == 1)
		{
			flag1 = 0;

		}


		for (int c = 0; c < this->col; c++)
		{
			t2 = c*(this->rc);

			if (flag1 == false)
			{
				Print_Square(t1, t2, BLACK);
				flag1 = !flag1;

			}
			else
			{
				Print_Square(t1, t2, WHITE);
				flag1 = !flag1;

			}
		}
		t1 = i*(this->rr);

		flag = !flag;

	}

}

void Board::Print_Square(int r,int c,colors C)
{
	int e1 = r + this->rr;
	int e2 = c + this->rc;

	setcolor(YELLOW);
	rectangle(r, c, e1, e2);

	if (C == BLACK)
	{
		setfillstyle(SOLID_FILL,DARKGRAY);
		floodfill(r + 1, c + 1, YELLOW);
	}
	else
	{

		setfillstyle(SOLID_FILL, WHITE);
		floodfill(r + 1, c + 1, YELLOW);

	}


}

void Board::MakeArray()
{
	this->B = new PIECE**[this->row];

	for (int i = 0; i < this->row; i++)
	{
		this->B[i] = new PIECE*[this->col];
	}

}
void Board::Create_Board()
{
	

	for (int i = 2; i < 6; i++)
	{
		for (int c = 0; c < this->col; c++)
		{
			B[i][c] = nullptr;
				
		}
	}
	B[0][0] = new Rook(Position(0,0),C_RED);
	B[0][1] = new Knight(Position(0, 1), C_RED);
	B[0][2] = new Bishop(Position(0, 2), C_RED);
	B[0][3] = new King(Position(0, 3), C_RED);
	B[0][4] = new Queen(Position(0, 4), C_RED);
	B[0][5] = new Bishop(Position(0, 5), C_RED);
	B[0][6] = new Knight(Position(0, 6), C_RED);
	B[0][7] = new Rook(Position(0, 7), C_RED);

	B[1][0] = new Pawn(Position(1, 0), C_RED);
	B[1][1] = new Pawn(Position(1, 1), C_RED);
	B[1][2] = new Pawn(Position(1, 2), C_RED);
	B[1][3] = new Pawn(Position(1, 3), C_RED);
	B[1][4] = new Pawn(Position(1, 4), C_RED);
	B[1][5] = new Pawn(Position(1, 5), C_RED);
	B[1][6] = new Pawn(Position(1, 6), C_RED);
	B[1][7] = new Pawn(Position(1, 7), C_RED);


	B[7][0] = new Rook(Position(7, 0), C_BLUE);
	B[7][1] = new Knight(Position(7, 1), C_BLUE);
	B[7][2] = new Bishop(Position(7, 2), C_BLUE);
	B[7][3] = new King(Position(7, 3), C_BLUE);
	B[7][4] = new Queen(Position(7, 4), C_BLUE);
	B[7][5] = new Bishop(Position(7, 5), C_BLUE);
	B[7][6] = new Knight(Position(7, 6), C_BLUE);
	B[7][7] = new Rook(Position(7, 7), C_BLUE);

	B[6][0] = new Pawn(Position(6, 0), C_BLUE);
	B[6][1] = new Pawn(Position(6, 1), C_BLUE);
	B[6][2] = new Pawn(Position(6, 2), C_BLUE);
	B[6][3] = new Pawn(Position(6, 3), C_BLUE);
	B[6][4] = new Pawn(Position(6, 4), C_BLUE);
	B[6][5] = new Pawn(Position(6, 5), C_BLUE);
	B[6][6] = new Pawn(Position(6, 6), C_BLUE);
	B[6][7] = new Pawn(Position(6, 7), C_BLUE);


//	B[3][7] = new Queen(Position(3, 7), C_RED);
//	B[4][3] = new Bishop(Position(4, 3), C_RED);


}

void Board::Create_Player()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int c = 0; c < this->col; c++)
		{
			if (this->B[i][c] != nullptr)
			{
				if (this->B[i][c]->Get_COLOUR() == C_RED)
				{
					setcolor(RED);
					this->B[i][c]->Draw();
				}
				else
				{
						setcolor(BLUE);
						this->B[i][c]->Draw();
				}

			}
		}

	}
	
}
void Board::PLAY()
{
	this->Turn = C_BLUE;
	DRAW_UNDO();

	int sx, sy, ex, ey;
	do                  // ALTERNATE TURN 
	{
		Turn_message();

		COLOUR T;
		Position P1, P2;

		do
		{
			do
			{
				Check();
				get_xy(sy, sx);
				
				if (!Check_undo(sx, sy))
				{
					// sx ,sy point on PIECE 2d array 
					if (this->B[sx][sy] != nullptr)
					{
						if (this->B[sx][sy]->Get_COLOUR() == this->Turn)
						{
							//						cout << "GOT THE FIRST  " << endl;
							Highlight(Position(sx, sy));
							break;

						}
					}
					else
					{
						cout << "Illegal Move" << endl;
						if (this->Turn == C_RED)
						{
							cout << "RED's Turn " << endl;
						}
						else
							cout << "BLUE's Turn " << endl;

					}


				}

			} while (1);

			cout << "Second move " << endl;
			get_xy(ey, ex);

			if (sx != ex || sy != ey)
			{
				P1.SetX(sx);
				P1.SetY(sy);
				P2.SetX(ex);
				P2.SetY(ey);
				T = this->B[sx][sy]->Get_COLOUR();

				if (!this->B[sx][sy]->Is_Legal(P2, this->B))
				{
					Undo_high();

					cout << "ILLEGAL MOVE" << endl;
					if (this->Turn == C_RED)
					{
						cout << "RED's Turn " << endl;
					}
					else
						cout << "BLUE's Turn " << endl;


				}
				else
				{	
					if (this->B[sx][sy]->if_killing(P2, this->B))
					{
						cout << "Legal " << endl;
						break;

					}
				}

			}
			else
			{
				Undo_high();
				cout << " SAME LOCATION ... Select another cell " << endl;

			}


		} while (1);

		Move(Position(sx, sy), Position(ex, ey));
		Print();
		Make_Grid();
		Create_Player();

		if (!Self_check())
		{
			Change_Turn();

		}
		else
		{
			Make_Grid();
			Create_Player();

		}
		
		if (!Is_king())
		{

			Change_Turn();
			cout << this->Turn << " WINS ||||||||||||||||||||||||" << endl;
			Make_Grid();
		}


		Save();

	} while (true);




}

void Board::Turn_message()
{
	if (this->Turn == C_RED)
	{
		cout << "RED's Turn " << endl;
	}
	else
	{
		cout << "BLUE's Turn " << endl;

	}

}


bool Board::Check_undo(int x,int y)
{
	if (y == 8)
	{
		if (x == 2)
		{
			UNDO();
			return 1;
		}
		else
			return 1;


	}
	else
		return 0;

}

bool Board::Is_king()
{
	COLOUR T = this->Turn;

	//if (this->Turn == C_RED)
	//{
	//	T = C_BLUE;
	//}
	//else
	//{
	//	T = C_RED;
	//}



	for (int i = 0; i < 8; i++)
	{
		for (int c = 0; c < 8; c++)
		{
			if (this->B[i][c] != nullptr)
			{
			

				COLOUR C = this->B[i][c]->Get_COLOUR();

				if (C == T)
				{

					if (this->B[i][c]->Find_king() == 1)
					{
						return 1;
					}

				}
			}
		}
	}



	return 0;

}

void Board::DRAW_UNDO()
{

	int x = 600;
	int y = 600 / 8 * 2;




	setcolor(WHITE);

	

	circle(625, y + this->rr / 4+5,20);

//	setfillstyle(SOLID_FILL, LIGHTBLUE);
//	floodfill(625, this->rr / 4 + 5, WHITE);



	line(625, y + this->rr / 4 - 5, 615, y+ this->rr / 4 + 5);
	line(625, y + this->rr / 4 +15, 615, y+ this->rr / 4 + 5);




}


void Board::UNDO()
{
	if (Destination.Is_Empty())
	{
		return;
	}


	Position P1 = this->Destination.Pop();
	Position P2 = this->Source.Pop();
	
	int x1 = P1.GetX();
	int x2 = P2.GetX();
	int y1 = P1.GetY();
	int y2 = P2.GetY();



	this->B[x1][y1]->Reset_I_Moved();
	this->B[x2][y2] = this->B[x1][y1];
	this->B[x2][y2]->Set_Pos(Position(x2, y2));
	this->B[x2][y2]->Set_COLOUR(this->B[x1][y1]->Get_COLOUR());
	this->B[x1][y1] = nullptr;



	Print();
	Make_Grid();
	Create_Player();


	Change_Turn();
	Turn_message();

	//this->PreS.Print();
	//cout << endl;
	//this->PreD.Print();
	//cout << endl;

}

bool Board::Self_check()
{

	if (Check())
	{
		cout << " MOVE NOT ALLOWD ITS PUT YOUR KING IN DANGER !!!!!!!!!" << endl;
	//	Move(this->PreD, this->PreS);
		int x1 = this->PreD.GetX();
		int x2 = this->PreS.GetX();
		int y1 = this->PreD.GetY();
		int y2 = this->PreS.GetY();


		this->B[x1][y1]->Reset_I_Moved();
		this->B[x2][y2] = this->B[x1][y1];
		this->B[x2][y2]->Set_Pos(Position(x2, y2));
		this->B[x2][y2]->Set_COLOUR(this->B[x1][y1]->Get_COLOUR());
		this->B[x1][y1] = nullptr;

		return 1;
	}


	return 0;
}

void Board::Highlight(Position P)
{
	int flag = 0;

	for (int i = 0; i < this->row; i++)
	{
		for (int c = 0; c < this->col; c++)
		{

			if (this->B[P.GetX()][P.GetY()]->Is_Legal(Position(i, c), this->B) == 1)
			{
				if (this->B[P.GetX()][P.GetY()]->if_killing(Position(i, c), this->B) == 1)
				{

					if (this->B[i][c] != nullptr)
					{
						if (this->B[P.GetX()][P.GetY()]->Get_COLOUR() != this->B[i][c]->Get_COLOUR())
						{
							flag = 1;
							Change_col(Position(i, c), LIGHTRED);
						}

					}
					else
					{

						Change_col(Position(i, c), GREEN);
					}


				}
			}

		}
		
	}
	
	if (flag == 0)
	{
		Change_col(Position(P.GetX(), P.GetY()), LIGHTRED);
	}


}


bool Board::Check()
{
	COLOUR t = this->Turn;
	for (int i = 0; i < this->row; i++)
	{
		for (int c = 0; c < this->col; c++)
		{
			if (this->B[i][c] != nullptr)
			{
				int t = this->B[i][c]->Find_king();
				if (t)
				{
					if (this->B[i][c]->Get_COLOUR() == this->Turn)
					{
						if (Is_King_Dying(Position(i, c)))
						{
							Change_col(Position(i, c), LIGHTCYAN);
							return 1;
							break;
						}
					}
				}
			}

		}
	}

	return 0;
}

bool Board::Is_King_Dying(Position P)
{
	int Px = P.GetX();
	int Py = P.GetY();

	for (int i = 0; i < this->row; i++)
	{
		for (int c = 0; c < this->col; c++)
		{
			if (this->B[i][c] != nullptr)
			{
				if (this->B[Px][Py]->Get_COLOUR() != this->B[i][c]->Get_COLOUR())
				{
					if (this->B[i][c]->Is_Legal(Position(Px, Py), this->B) == 1)
					{
						return 1;

					}
				}
			}
		}

	}

	return 0;
}
void Board::Undo_high()
{

	Make_Grid();
	Create_Player();

}

void Board::Change_col(Position &P,colors C)
{

	int r = P.GetY();
	int c= P.GetX();

	r = P.GetY()*(this->rr);
	c = P.GetX()*(this->rr);
	int e1 = r + this->rr;
	int e2 = c + this->rc;

	setcolor(YELLOW);

	rectangle(r, c, e1, e2);
	setfillstyle(SOLID_FILL, C);
	floodfill(r + 1, c + 1, YELLOW);
	
	if (this->B[P.GetX()][P.GetY()] != nullptr)
	{

		COLOUR C = this->B[P.GetX()][P.GetY()]->Get_COLOUR();
		if (C == C_RED)
		{
			setcolor(RED);
			this->B[P.GetX()][P.GetY()]->Draw();
		}
		if (C == C_BLUE)
		{
			setcolor(BLUE);
			this->B[P.GetX()][P.GetY()]->Draw();
		}
	}


}

void Board::Change_Turn()
{

	if (this->Turn == C_RED)
	{
		this->Turn = C_BLUE;

	}
	else
	{
		this->Turn = C_RED;
	}


}
void Board::Move(Position &P1, Position &P2)
{
	
	int x1 = P1.GetX();
	int x2 = P2.GetX();
	int y1 = P1.GetY();
	int y2 = P2.GetY();

	this->PreS.SetX(x1);
	this->PreS.SetY(y1);
	this->PreD.SetX(x2);
	this->PreD.SetY(y2);
	
	this->Source.Push(PreS);
	this->Destination.Push(PreD);



	this->B[x1][y1]->I_Moved();
	this->B[x2][y2] = this->B[x1][y1];
	this->B[x2][y2]->Set_Pos(Position(x2,y2));
	this->B[x2][y2]->Set_COLOUR(this->B[x1][y1]->Get_COLOUR());
	this->B[x1][y1] = nullptr;



	
}
void Board:: get_xy(int &x, int &y)
{
	while (1)
	{

		getmouseclick(WM_LBUTTONDOWN, x, y);
		if (x != -1 && y != -1)
		{
//			cout << x << " " << y << endl;
			break;
		
			
		}
	}
	x = x / this->rr;
	y = y / this->rc;

//	cout << y << " " << x << endl;

}
void Board::Print()
{

	for (int i = 0; i < this->row; i++)
	{
		for (int c = 0; c < this->col; c++)
		{
			if (B[i][c] != nullptr)
			{
				this->B[i][c]->Print();
				cout << "	";
			}
			else
			{
				cout << "	";
			}
		}

		cout << endl;
	}

}



void Board::Save()
{
	
	ofstream fout1("ROOK.txt");
	ofstream fout2("KING.txt");
	ofstream fout3("QUEEN.txt");
	ofstream fout4("BISHOP.txt");
	ofstream fout5("KNIGHT.txt");
	ofstream fout6("PAWN.txt");


	for (int i = 0; i < this->row; i++)
	{
		for (int c = 0; c < this->col; c++)
		{
			if (this->B[i][c] != nullptr)
			{
				this->B[i][c]->save();

			}

		}

	}
	
	fout1.close();
	fout2.close();
	fout3.close();
	fout4.close();
	fout5.close();
	fout6.close();

		
}

void Board::Load()
{
	for (int i = 0; i < this->row; i++)
	{
		for (int c = 0; c < this->col; c++)
		{

			this->B[i][c] = nullptr;

		}
	}
	
	ifstream fin;



	int r, c, t;
	fin.open("KING.txt");
	while (!fin.eof())
	{
		fin >> r >> c >> t;

		if (t == 1)
		{
			this->B[r][c] = new King(Position(r, c), C_RED);
		}
		else
		{


			this->B[r][c] = new King(Position(r, c), C_BLUE);

		}
	}
	fin.close();

	fin.open("QUEEN.txt");
	while (!fin.eof())
	{
		fin >> r >> c >> t;

		if (t == 1)
		{
			this->B[r][c] = new Queen(Position(r, c), C_RED);
		}
		else
		{


			this->B[r][c] = new Queen(Position(r, c), C_BLUE);

		}
	}
	fin.close();


	fin.open("Bishop.txt");
	while (!fin.eof())
	{
		fin >> r >> c >> t;

		if (t == 1)
		{
			this->B[r][c] = new Bishop(Position(r, c), C_RED);
		}
		else
		{


			this->B[r][c] = new Bishop(Position(r, c), C_BLUE);

		}
	}
	fin.close();

	fin.open("PAWN.txt");
	while (!fin.eof())
	{
		fin >> r >> c >> t;

		if (t == 1)
		{
			this->B[r][c] = new Pawn(Position(r, c), C_RED);
		}
		else
		{


			this->B[r][c] = new Pawn(Position(r, c), C_BLUE);

		}
	}
	fin.close();


	fin.open("ROOK.txt");
	while (!fin.eof())
	{
		fin >> r >> c >> t;

		if (t == 1)
		{
			this->B[r][c] = new Rook(Position(r, c), C_RED);
		}
		else
		{


			this->B[r][c] = new Rook(Position(r, c), C_BLUE);

		}
	}
	fin.close();

	fin.open("KNIGHT.txt");
	while (!fin.eof())
	{
		fin >> r >> c >> t;

		if (t == 1)
		{
			this->B[r][c] = new Knight(Position(r, c), C_RED);
		}
		else
		{


			this->B[r][c] = new Knight(Position(r, c), C_BLUE);

		}
	}
	fin.close();


	Make_Grid();
	Create_Player();


}



Board::~Board()
{
}
