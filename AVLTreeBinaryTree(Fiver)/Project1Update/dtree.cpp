/**
 * CMSC 341 - Spring 2021
 * Project 2 - Binary Trees
 * DiscriminatorTree.cpp
 * Implementation for the DTree class.
 */

#include "dtree.h"



/**
 * Destructor, deletes all dynamic memory.
 */
DTree::~DTree() {



	clear();

}

/**
 * Overloaded assignment operator, makes a deep copy of a DTree.
 * @param rhs Source DTree to copy
 * @return Deep copy of rhs
 */

void DTree::DeepCopy(const DNode *node)
{
	
	if (node)
	{
		this->insert(node->getAccount());
		DeepCopy(node->_left);
		DeepCopy(node->_right);
	}

}

DTree& DTree::operator=(const DTree& rhs) {       // the order may change as the tree is self balancing
	
	this->clear();
	DeepCopy(rhs._root);

	return (*this);

}

/**
 * Dynamically allocates a new DNode in the tree. 
 * Should also update heights and detect imbalances in the traversal path
 * an insertion.
 * @param newAcct Account object to be contained within the new DNode
 * @return true if the account was inserted, false otherwise
 */


	// DNode* temp = new DNode();
	// temp->_account = newAcct;


bool DTree::insertRec(DNode *&Current, Account newAcct, int key)
{

		if (key < Current->getAccount().getDiscriminator())
		{
			if (Current->_left == nullptr)
			{
				
				DNode* temp = new DNode();
				temp->_account = newAcct;
				Current->_left = temp;
				Current->_left->_size = 1;
				Current->_size++;
				temp = nullptr;
				if (checkImbalance(Current))
				{
					rebalance(Current);
				}

				return 1;
			}
			else if (Current->_left->getAccount().getDiscriminator() == key)
			{
				if (Current->_left->isVacant())                    // when DNode is vacant 
				{
					DNode* temp = new DNode();
					temp->_account = newAcct;
				
					Current->_left = temp;
					Current->_left->_size = 1;
					temp = nullptr;
					return true;
				}
				else
					return false;

			}
			else
			{
				if (insertRec(Current->_left, newAcct, key))
				{
					Current->_size++;
					if (checkImbalance(Current))
					{
						rebalance(Current);
					}

				}

			}
		}
		else              // key is greater ...tranverse right side
		{
			if (Current->_right == nullptr)
			{
				DNode* temp = new DNode();
				temp->_account = newAcct;
				
				Current->_right = temp;
				Current->_right->_size = 1;
				Current->_size++;
				temp = nullptr;
				if (checkImbalance(Current))
				{
					rebalance(Current);
				}
				return true;
			}
			else if (Current->_right->getAccount().getDiscriminator() == key)
			{
				if (Current->_right->isVacant())                    // when DNode is vacant 
				{
					DNode* temp = new DNode();
					temp->_account = newAcct;
				
					Current->_right = temp;
					Current->_right->_size = 1;
					temp = nullptr;
					return true;
				}
				else
					return false;

			}
			else
			{
				if (insertRec(Current->_right, newAcct, key))
				{
					Current->_size++;
					if (checkImbalance(Current))
					{
						rebalance(Current);
					}


				}
			}



		} // when key is greater else ends

}

bool DTree::insert(Account newAcct) {


	if (this->_root == nullptr)
	{
		DNode* temp = new DNode();
		temp->_account = newAcct;
				
		this->_root = temp;
		this->_root->_size = 1;
		temp = nullptr;
		return 1;
	}
	else
		return insertRec(_root,newAcct,newAcct.getDiscriminator());

}

/**
 * Removes the specified DNode from the tree.
 * @param disc discriminator to match
 * @param removed DNode object to hold removed account
 * @return true if an account was removed, false otherwise
 */




bool DTree::removeRec(int disc,DNode *&Current, DNode*& removed) {


	if (Current == nullptr)
		return 0;


	int Ckey = Current->getAccount().getDiscriminator();

	if (Ckey == disc)
	{
		if (Current->_vacant)                // if it is already vacant
			return 0;


		Current->_vacant = true;
		Current->_numVacant++;

		removed = Current;
		return 1;
	}
	else if (Ckey > disc)
	{
		if (removeRec(disc, Current->_left, removed))
		{
			Current->_numVacant++;
			return 1;
		}
		else
			return 0;
	}
	else
	{
		if (removeRec(disc, Current->_right, removed))
		{
			Current->_numVacant++;
			return 1;
		}
		else
			return 0;
	}

	return 0;
}
bool DTree::remove(int disc, DNode*& removed) {


	return removeRec(disc,_root,removed);

}

/**
 * Retrieves the specified Account within a DNode.
 * @param disc discriminator int to search for
 * @return DNode with a matching discriminator, nullptr otherwise
 */


DNode* DTree::retrieveRec(DNode *Current,int disc){

	int Ckey = Current->getAccount().getDiscriminator();

	if (Ckey == disc)
	{
		if (!Current->isVacant())
			return Current;
		else
			return nullptr;
	}
	else if (Ckey > disc)
	{
		return retrieveRec(Current->_left, disc);

	}
	else
	{
		return retrieveRec(Current->_left, disc);
	}


	return nullptr;
}
DNode* DTree::retrieve(int disc) {

	return retrieveRec(_root, disc);
	
}

/**
 * Helper for the destructor to clear dynamic memory.
 */

void DTree::clearRec(DNode *Current) {

	if (Current)
	{
		clearRec(Current->_left);
		clearRec(Current->_right);
		delete Current;
	}
}
void DTree::clear() {

	clearRec(_root);

}

/**
 * Prints all accounts' details within the DTree.
 */

void DTree::printAccountsRec(DNode *Current) const {

	if (Current == nullptr)
		return;

	printAccountsRec(Current->_left);
	
	if (!Current->isVacant())
	{

		cout << Current->_account;
		cout << "\t\tSize : " << Current->getSize() << endl;
		cout << endl;
		cout << endl;

	}

	printAccountsRec(Current->_right);

}

void DTree::printAccounts() const {

	printAccountsRec(this->_root);
}

/**
 * Dump the DTree in the '()' notation.
 */
void DTree::dump(DNode* node) const {
    if(node == nullptr) return;
    cout << "(";
    dump(node->_left);
    cout << node->getAccount().getDiscriminator() << ":" << node->getSize() << ":" << node->getNumVacant();
    dump(node->_right);
    cout << ")";
}

/**
 * Returns the number of valid users in the tree.
 * @return number of non-vacant nodes
 */
int DTree::getNumUsers() const {    // Number of NonVacant nodes

	return (this->_root->_size - this->_root->_numVacant);

}

/**
 * Updates the size of a node based on the imedaite children's sizes
 * @param node DNode object in which the size will be updated
 */
void DTree::updateSize(DNode* node) {


	if (node->_left)
	{
		if (node->_right)
		{
			node->_size = node->_left->_size + node->_right->_size + 1;
		}
		else
			node->_size = node->_left->_size  + 1;

	}
	else
	{
		if (node->_right)
			node->_size = node->_right->_size + 1;
		else
			node->_size = 1;
	}

}



/**
 * Updates the number of vacant nodes in a node's subtree based on the immediate children
 * @param node DNode object in which the number of vacant nodes in the subtree will be updated
 */
void DTree::updateNumVacant(DNode* node) {

	if (node->_left)
	{
		if (node->_right)
		{
			node->_numVacant= node->_left->_numVacant + node->_right->_numVacant;
			if (node->isVacant())
			{
				node->_numVacant++;
			}
				
		}
		else
		{
			node->_numVacant = node->_left->_numVacant;
			if (node->isVacant())
			{
				node->_numVacant++;
			}
		}
			

	}
	else
	{
		if (node->_right)
		{
			node->_numVacant = node->_right->_numVacant;
			if (node->isVacant())
			{
				node->_numVacant++;
			}
		}
		else
		{
			if (node->isVacant())
			{
				node->_numVacant = 1;
			}
		}
			
	}
	
   /// Updated as they are deleted
}

/**
 * Checks for an imbalance, defined by 'Discord' rules, at the specified node.
 * @param checkImbalance DNode object to inspect for an imbalance
 * @return (can change) returns true if an imbalance occured, false otherwise
 */



DNode *& DTree::findParent(DNode *&Current, DNode *&Parent, DNode *&Node, int &whichChild)
{

	if (Current == Node) // means Node is root node
	{
		DNode *temp = nullptr;
		return	temp;
	}
		



	if (Current->getDiscriminator() == Node->getDiscriminator())
	{
		if (Parent->_left == Current)
			whichChild = -1;
		else
			whichChild = 1;


		return Parent;
	}
	else if (Current->getDiscriminator() > Node->getDiscriminator())
	{
		return findParent(Current->_left, Current, Node, whichChild);
	}
	else
		return findParent(Current->_right, Current, Node, whichChild);


}
bool DTree::checkImbalance(DNode* node) {
	
	int ls = 0;
	int rs = 0;

	if (node->_left)
		ls = node->_left->_size;
	
	if (node->_right)
		rs = node->_right->_size;




	if (ls / 2 > rs && ls > 3 ||
					rs/ 2 > ls && rs > 3)
	{
		return 1;
	}
	else
		return 0;
	
}

//----------------
/**
 * Begins and manages the rebalancing process for a 'Discrd' tree (pass by reference).
 * @param node DNode root of the subtree to balance
 */

void DTree::TreetoArr(DNode* &Current, Account *arr,int &index,int size)
{
	if (index == size)
		return;
	if (!Current)
		return;

	TreetoArr(Current->_left,arr,index,size);

	if (!Current->isVacant())
	{
//		cout << Current->_account;
		arr[index] = Current->_account;
		index++;
	}

	TreetoArr(Current->_right,arr,index,size);

}



void DTree::AddElement(DNode *&Current, Account *arr, int st,int ed)
{
	
	int mid = (st + ed) / 2;

	if (st >= ed)
	{
		return;
	}
		

//	cout << arr[mid].getDiscriminator() << endl;

	if (Current == nullptr)
	{
		
		DNode* temp = new DNode();
		temp->_account = arr[mid];


		Current = temp;
		Current->_size = 1;
	}
	else
	{
		insertRec(Current, arr[mid], arr[mid]._disc);
	}
		

	AddElement(Current, arr, st,mid);
	AddElement(Current, arr, mid+1, ed);

}


DNode*& DTree::ArrToTree(Account *arr,int size) {
		

	DNode *Myroot =nullptr;
	int st = 1;
//	size--;

//	cout << "\n\n\n PRINTING \n\n\n";

	AddElement(Myroot, arr,st,size+1);
	
//	cout << endl << endl;

//	printAccountsRec(Myroot);

	return Myroot;

}

void DTree::rebalance(DNode*& node) {
	
	int size = node->_size+1;

	Account *arr = new Account[size];
	int index = 1;
	TreetoArr(node, arr,index,size);

	
	//cout << "Printing before changing" << endl;
	//printAccountsRec(_root);


	//for (int i = 1; i < size; i++)
	//{
	//	cout << arr[i]._disc << " ";
	//}
	//cout << endl;
	//cout << endl;
	DNode *temp = 	ArrToTree(arr, size-1);

	


	if (_root == node)
	{
		this->clearRec(_root);
		_root = temp;

	}
	else
	{

		int whichchild = 0;
		DNode *Parent = findParent(_root, _root, node, whichchild);

		this->clearRec(node);
	
		if (whichchild == -1)
		{
			Parent->_left = temp;
		}
		else
			Parent->_right = temp;
	
	}

}



// -- OR --

/**
 * Begins and manages the rebalancing process for a 'Discrd' tree (returns a pointer).
 * @param node DNode root of the subtree to balance
 * @return DNode root of the balanced subtree
 */
//DNode* DTree::rebalance(DNode*& node) {
    
//}
//----------------

/**
 * Overloaded << operator for an Account to print out the account details
 * @param sout ostream object
 * @param acct Account objec to print
 * @return ostream object containing stream of account details
 */
ostream& operator<<(ostream& sout, const Account& acct) {
	sout << "Account name: " << acct.getUsername() <<
		"\n\tDiscriminator: " << acct.getDiscriminator() <<
		"\n\tNitro: " << acct.hasNitro() <<
		"\n\tBadge: " << acct.getBadge() <<
		"\n\tStatus: " << acct.getStatus() << endl;
    return sout;
}