#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

class TransactionNode : public Node
{
public:
	TransactionNode(const string& newData = "", const int& newUnits = 0) : Node(newData), mUnits(newUnits) {}
	TransactionNode(const TransactionNode& copyTN);
	~TransactionNode();

	void setUnits(int newUnits);

	int getUnits() const;

	void printData();

private:
	int mUnits;
};