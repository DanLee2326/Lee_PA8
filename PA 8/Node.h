#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

class Node
{
public:
	Node(const string& newData = "");
	Node(const Node& copyNode);
	virtual ~Node();

	void setData(string newData);
	void setLeftPtr(Node* newLeftPtr);
	void setRightPtr(Node* newRightPtr);

	string getData() const;
	Node*& getLeftPtr();
	Node*& getRightPtr();

	virtual void printData() = 0;

protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;
};