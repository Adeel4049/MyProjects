/**
 * CMSC 341 - Spring 2021
 * Project 2 - Binary Trees
 * UserTree.h
 * Implementation for the UTree class.
 */

#include "utree.h"

/**
 * Destructor, deletes all dynamic memory.
 */
UTree::~UTree() {


	clear();
	this->_root = nullptr;

}

/**
 * Sources a .csv file to populate Account objects and insert them into the UTree.
 * @param infile path to .csv file containing database of accounts
 * @param append true to append to an existing tree structure or false to clear before importing
 */ 
void UTree::loadData(string infile, bool append) {
    std::ifstream instream(infile);
    string line;
    char delim = ',';
    const int numFields = 5;
    string fields[numFields];

    /* Check to make sure the file was opened */
    if(!instream.is_open()) {
        std::cerr << __FUNCTION__ << ": File " << infile << " could not be opened or located" << endl;
        exit(-1);
    }

    /* Should we append or clear? */
    if(!append) this->clear();

    /* Read in the data from the .csv file and insert into the UTree */
    while(std::getline(instream, line)) {
        std::stringstream buffer(line);

        /* Quick check to make sure each line is formatted correctly */
        int delimCount = 0;
        for(unsigned int c = 0; c < buffer.str().length(); c++) if(buffer.str()[c] == delim) delimCount++;
        if(delimCount != numFields - 1) {
            throw std::invalid_argument("Malformed input file detected - ensure each line contains 5 fields deliminated by a ','");
        }

        /* Populate the account attributes - 
         * Each line always has 5 sections of data */
        for(int i = 0; i < numFields; i++) {
            std::getline(buffer, line, delim);
            fields[i] = line;
        }
        Account newAcct = Account(fields[0], std::stoi(fields[1]), std::stoi(fields[2]), fields[3], fields[4]);
        this->insert(newAcct);
    }

}

/**
 * Dynamically allocates a new UNode in the tree and passes insertion into DTree. 
 * Should also update heights and detect imbalances in the traversal path after
 * an insertion.
 * @param newAcct Account object to be inserted into the corresponding DTree
 * @return true if the account was inserted, false otherwise
 */


	// UNode* temp = new UNode();
	// temp->_dtree->insert(newAcct);
	// temp->_height = 1;


bool UTree::insertRec(UNode *Current,Account newAcct)
{
	if (_root == nullptr)
	{
		UNode* temp = new UNode();
		temp->_dtree->insert(newAcct);
		temp->_height = 1;


		_root =temp;
		return 1;
	}
	else
	{
	
		if (Current->getUsername() > newAcct.getUsername())
		{
	
			if (Current->_left == nullptr)
			{
					UNode* temp = new UNode();
					temp->_dtree->insert(newAcct);
					temp->_height = 1;

				Current->_left = temp;
				updateHeight(Current);
				return 1;
			}
			else if (Current->_left->getUsername() == newAcct.getUsername())
			{
			
				return (Current->_left->_dtree->insert(newAcct));
		
			}
			else 
			{
				if (insertRec(Current->_left, newAcct))
				{
					updateHeight(Current);
					checkImbalance(Current);
					
				}
			}
		}
		else if (Current->getUsername() < newAcct.getUsername())
		{
			if (Current->_right == nullptr)
			{
					UNode* temp = new UNode();
				temp->_dtree->insert(newAcct);
				temp->_height = 1;

				Current->_right = temp;
				updateHeight(Current);
				return 1;
			}
			else if (Current->_right->getUsername() == newAcct.getUsername())
			{
				return (Current->_right->_dtree->insert(newAcct));
				
			}
			else
			{
				if (insertRec(Current->_right, newAcct))
				{
					updateHeight(Current);
					checkImbalance(Current);
				}
				
			}
		}
		

	}// when it is not root 

}
bool UTree::insert(Account newAcct) 
{
	
	insertRec(_root, newAcct);
	return 1;
}

int Max(int a, int b)
{
	if (a > b)
	{
		return a;
	}
	else
		return b;

}

void UTree::updateHeight(UNode* node) {

	if (node->_left)
	{
		if (node->_right)
		{
			node->_height = Max(node->_left->_height, node->_right->_height) + 1;
		}
		else
		{
			node->_height = node->_left->_height + 1;
		}
	}
	else
	{
		if (node->_right)
		{
			node->_height = node->_right->_height + 1;
		}
		else
			node->_height = 1;

	}

}


void UTree::RotateRight(UNode *&Current)
{
	UNode* temp = Current;
	int wc = 0;
	UNode *Parenttemp = nullptr;
	findParent(_root, _root, temp, wc,Parenttemp);

	Current = Current->_left;
	temp->_left = Current->_right;
	Current->_right = temp;
	

	if (Parenttemp)
	{
		if (wc == 1) // means temp is the right child of parent
		{
			Parenttemp->_right = Current;
		}
		else
			Parenttemp->_left = Current;

	}
	else   // Meaning this was parent node
	{
		_root = Current;
//		updateHeight(_root);
	}

	updateHeight(temp);
	updateHeight(Current);


}
void UTree::RotateLeft(UNode *&Current)
{
	int wc = 0;

	UNode* temp = Current;
	UNode* Parenttemp = nullptr;
	findParent(_root, _root, temp, wc, Parenttemp);

	Current = Current->_right;
	temp->_right = Current->_left;


	Current->_left = temp;



	if (Parenttemp)
	{
		if (wc == 1)
			Parenttemp->_right = Current;
		else
			Parenttemp->_left = Current;
	}
	else   // Meaning this was parent node
	{
		_root = Current;
	//	updateHeight(_root);
	}



	updateHeight(temp);
	updateHeight(Current);
	
}
void UTree::findParent(UNode *Current, UNode *Parent, UNode *Node, int &whichChild, UNode *&Parenttemp)
{

	if (_root == Node)
	{
		Parenttemp = nullptr;
		return;

	}

	if (Current->getUsername() == Node->getUsername())
	{
		if (Parent->_left == Current)
			whichChild = -1;
		else
			whichChild = 1;


		Parenttemp = Parent;

	}
	else if (Current->getUsername() > Node->getUsername())
	{
		findParent(Current->_left, Current, Node, whichChild,Parenttemp);
	}
	else
		findParent(Current->_right, Current, Node, whichChild, Parenttemp);


}


/**
 * Removes a user with a matching username and discriminator.
 * @param username username to match
 * @param disc discriminator to match
 * @param removed DNode object to hold removed account
 * @return true if an account was removed, false otherwise
 */
bool UTree::removeUser(string username, int disc, DNode*& removed) {

	
	DeleteRec(_root, _root, username,disc,removed);

	return 1;
}

/**
 * Retrieves a set of users within a UNode.
 * @param username username to match
 * @return UNode with a matching username, nullptr otherwise
 */

UNode* UTree::retrieveRec(UNode *Current, string username) {

	string Ckey = Current->_dtree->getUsername();

	if (Ckey == username)
	{
		return Current;
	}
	else if (Ckey > username)
	{
		return retrieveRec(Current->_left, username);

	}
	else
	{
		return retrieveRec(Current->_left, username);
	}


	return nullptr;
}
UNode* UTree::retrieve(string username) {

	return retrieveRec(_root, username);

}

/**
 * Retrieves the specified Account within a DNode.
 * @param username username to match
 * @param disc discriminator to match
 * @return DNode with a matching username and discriminator, nullptr otherwise
 */
DNode* UTree::retrieveUser(string username, int disc) {


	UNode  *temp = this->retrieve(username);
	if (temp)
	{
		return temp->_dtree->retrieve(disc);
	}

}



bool UTree::DeleteDisc(UNode *Node, int disc, DNode*& removed)
{
	
	int res = Node->_dtree->remove(disc, removed);
	
	if (res)
	{
		cout << "Deleted   Username : " << Node->getUsername() << "  Disc : " << disc << endl;
	}
	else
	{
		cout << disc << "Not found in " << Node->getUsername() << endl;
	}
	

	//if (Node->_dtree->)

	if (Node->_dtree->getNumUsers() == 0)   // Meaning all the nodes of this username has been deleted
	{
		return 0;          // 
	}


	return 1;
}

void UTree::DeleteRec(UNode *Current, UNode *Parent, string  username, int disc, DNode*& removed)
{

	if (Current == nullptr)
		return;


	if (Current->getUsername() == username)
	{
		if (Current == _root)
		{


			if (DeleteDisc(Current, disc, removed))                    /// if there are non vacand nodes in dtree
				return;

			UNode *temp = findLeftMax(Current, Current->_left);
			temp->_right = Current->_right;
			if (Current->_left != temp)
				temp->_left = Current->_left;

			delete Current;
			Current = nullptr;
			_root = temp;

			updateHeight(_root);
			checkImbalance(_root);

		}
		else
		{
			if (Current->_left == nullptr)
			{
				if (Current->_right == nullptr)  // Meaning it is a leaf Node;
				{

					if (DeleteDisc(Current, disc, removed))                    /// if there are non vacand nodes in dtree
						return;

					if (Parent->_left == Current)
					{
						Parent->_left = nullptr;
					}
					else
					{
						Parent->_right = nullptr;
					}
					
					delete Current;
					Current = nullptr;

				}
				else     // When left child is null and there is right child
				{
				
					if (DeleteDisc(Current, disc, removed))                    /// if there are non vacand nodes in dtree
						return;

					
					if (Parent->_left == Current)
					{
						Parent->_left = Current->_right;
					}
					else
					{
						Parent->_right =Current->_right;
					}

					delete Current;
					Current = nullptr;
				}


			}  // if(left == null) end here 
			else
			{

				if (DeleteDisc(Current, disc, removed))    // there are non vacant nodes
					return;

				UNode *temp = findLeftMax(Current, Current->_left);

				temp->_right = Current->_right;			
				if (Current->_left != temp)
					temp->_left = Current->_left;
	
				if (Parent->_left == Current)
				{
						Parent->_left =temp;
				}
				else
				{
					Parent->_right = temp;
				}

				delete Current;
				Current = nullptr;
				Current = temp;

				updateHeight(Current);
			}
		}			

	}
	else if (Current->getUsername() > username)
	{
		DeleteRec(Current->_left, Current, username,disc, removed);
		updateHeight(Current);
		checkImbalance(Current);
	}
	else
	{
		DeleteRec(Current->_right, Current, username, disc, removed);
		updateHeight(Current);
		checkImbalance(Current);
	}

}


UNode*& UTree:: findLeftMax(UNode *Parent, UNode *Current)    //   ,, Node to be deleted,Node->left
{

	if (Current == nullptr)
	{
		UNode *t = nullptr;
		return t;
	}
	else
	{
		if (Current->_right)
		{
			while (Current->_right != nullptr)
			{
				Parent = Current;
				Current = Current->_right;

			}

			Parent->_right = Current->_left;
			return Current;
		}
		else
			return Current;
	}

}


/**
 * Returns the number of users with a specific username.
 * @param username username to match
 * @return number of users with the specified username
 */
int UTree::numUsers(string username) {
	
	UNode *T = this->retrieve(username);
	return (T->_dtree->getNumUsers());

}

/**
 * Helper for the destructor to clear dynamic memory.
 */

void UTree::clearRec(UNode *Current) {

	if (Current)
	{
		clearRec(Current->_left);
		clearRec(Current->_right);
		delete Current->_dtree;
		delete Current;
	}
}
void UTree::clear() {
    
	clearRec(_root);
}

/**
 * Prints all accounts' details within every DTree.
 */


void UTree::printUsersRec(UNode *Current) const {

	if (Current == nullptr)
		return;

	printUsersRec(Current->_left);
	cout << "UserName is : ";
	cout << Current->_dtree->getUsername();
	cout << "\nheight is :  " << Current->_height << endl << endl;
	Current->_dtree->printAccounts();

	printUsersRec(Current->_right);
}

void UTree::printUsers() const {


	printUsersRec(_root);


}

/**
 * Dumps the UTree in the '()' notation.
 */
void UTree::dump(UNode* node) const {
    if(node == nullptr) return;
    cout << "(";
    dump(node->_left);
    cout << node->getUsername() << ":" << node->getHeight() << ":" << node->getDTree()->getNumUsers();
    dump(node->_right);
    cout << ")";
}

/**
 * Updates the height of the specified node.
 * @param node UNode object in which the height will be updated
 */

/**
 * Checks for an imbalance, defined by AVL rules, at the specified node.
 * @param node UNode object to inspect for an imbalance
 * @return (can change) returns true if an imbalance occured, false otherwise
 */
int UTree::checkImbalance(UNode* Current) {
	
	
	if (Current->_right)   // It has a right child
	{
		if (Current->_left)
		{
			if (Current->_right->_height - Current->_left->_height > 1)
			{
				RotateLeft(Current);   
				return 1;					////         L L 
			}
			else if (Current->_left->_height - Current->_right->_height > 1)
			{
				RotateRight(Current);
				return 1;
			}
				
		}
		else
		{
			if (Current->_right->_height > 1)
			{
				if (Current->_right->_right == nullptr)
				{
					RotateRight(Current->_right);
					RotateLeft(Current);
					return 1;
				}
				else
				{
					RotateLeft(Current);
					return 1;
				}
					

			}

		}

	}
	else if (Current->_left)
	{
		if (Current->_left->_height > 1)
		{
			if (Current->_left->_left == nullptr)    ////   L R
			{

				RotateLeft(Current->_left);
				//					cout << endl;
				//					BST::PrintInOrderRec();
				//					cout << endl;
				RotateRight(Current);
				return 1;

			}
			else
			{
				RotateRight(Current);
				return 1;
			}
				


		}

	}

	return 0;
}



//----------------
/**
 * Begins and manages the rebalance procedure for an AVL tree (pass by reference).
 * @param node UNode object where an imbalance occurred
 */
void UTree::rebalance(UNode*& node) {

	checkImbalance(node);                          // Check imabalance Rebalances

// -- OR --
}

/**
 * Begins and manages the rebalance procedure for an AVL tree (returns a pointer).
 * @param node UNode object where an imbalance occurred
 * @return UNode object replacing the unbalanced node's position in the tree
 */
//UTree* UTree::rebalance(UNode* node) {

//}
//----------------
