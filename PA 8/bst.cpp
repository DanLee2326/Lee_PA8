#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
}

BST::BST(const BST& copyBST)
{

}

BST::~BST()
{
	destroyTree(this->mpRoot);
}

void BST::destroyTree(Node*& pT)
{
	if (pT != nullptr)
	{
		destroyTree(pT->getLeftPtr());
		destroyTree(pT->getRightPtr());
		delete pT;
	}
}

void BST::setRootPtr(Node* newRootPtr)
{
	this->mpRoot = newRootPtr;
}

Node* BST::getRootPtr() const
{
	return this->mpRoot;
}

void BST::insert(string& newData, int& newUnits)
{
	insert(this->mpRoot, newData, newUnits);
}

void BST::insert(Node*& pT, string& newData, int& newUnits)
{
	if (pT == nullptr)
	{
		this->mpRoot = new TransactionNode(newData, newUnits);
	}
	else
	{
		if (dynamic_cast<TransactionNode*>(pT)->getUnits() > newUnits)
		{
			if (pT->getLeftPtr() == nullptr)
			{
				pT->setLeftPtr(new TransactionNode(newData, newUnits));
			}
			else
			{
				insert(pT->getLeftPtr(), newData, newUnits);
			}
		}
		else if (dynamic_cast<TransactionNode*>(pT)->getUnits() < newUnits)
		{
			if (pT->getRightPtr() == nullptr)
			{
				pT->setRightPtr(new TransactionNode(newData, newUnits));
			}
			else
			{
				insert(pT->getRightPtr(), newData, newUnits);
			}
		}
		else
		{
			cout << "Duplicate: " << newUnits << endl;
		}
	}
}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}

void BST::inOrderTraversal(Node* pT) // calls printData() from TransactionNode, each node printed on separate lines
{
	if (pT != nullptr)
	{
		inOrderTraversal(pT->getLeftPtr());
		pT->Node::printData();
		pT->printData();
		inOrderTraversal(pT->getRightPtr());
	}
}

TransactionNode& BST::findSmallest()
{
	Node* tree = mpRoot;
	while (tree->getLeftPtr() != nullptr)
	{
		tree = tree->getLeftPtr();
	}
	return dynamic_cast<TransactionNode&>(*tree);
}

TransactionNode& BST::findLargest()
{
	Node* tree = mpRoot;
	while (tree->getRightPtr() != nullptr)
	{
		tree = tree->getRightPtr();
	}
	return dynamic_cast<TransactionNode&>(*tree);
}