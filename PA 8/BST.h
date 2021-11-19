#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Node.h"
#include "TransactionNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

class BST
{
public:
	BST();
	BST(const BST& copyBST);
	~BST();

	void setRootPtr(Node* newRootPtr);

	Node* getRootPtr() const;

	void insert(string& newData, int& newUnits);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();

private:
	Node* mpRoot;

	void destroyTree(Node*& pT);
	void insert(Node*& pT, string& newData, int& newUnits);
	void inOrderTraversal(Node* pT); // calls printData() from TransactionNode, each node printed on separate lines
};