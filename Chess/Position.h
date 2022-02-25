#pragma once
class Position
{

private:
	int x;
	int y;

public:
	Position(){ this->x = 0; this->y = 0; }
	Position(int a, int b){ this->x = a; this->y = b; }
	void SetX(int a){ this->x = a; }
	void SetY(int a){ this->y = a; }

	int GetX(){ return this->x; }
	int GetY(){ return this->y; }

	void Print(){ cout << "(" << this->x << "," << this->y << ")"; cout << endl; }
	
	friend ostream& operator<<(ostream &cout, Position &P)
	{
		cout << "( " << P.x << " " << P.y << ")";
		return cout;
	}


	~Position(){}
};

