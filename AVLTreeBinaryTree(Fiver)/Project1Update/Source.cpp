#include<iostream>
#include<fstream>
#include<vector>

#include"dtree.h"
#include"utree.h"



using namespace std;
int main()
{

 	UTree *Obj;

 	Obj = new UTree();
	
	Obj->loadData("accounts.csv",0);

	Obj->printUsers();


//	delete Obj;	
	system("PAUSE");
	return 0;
}
 