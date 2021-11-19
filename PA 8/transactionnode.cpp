#include "TransactionNode.h"

TransactionNode::TransactionNode(const TransactionNode& copyTN)
{

}

TransactionNode::~TransactionNode()
{

}

void TransactionNode::setUnits(int newUnits)
{
	this->mUnits = newUnits;
}

int TransactionNode::getUnits() const
{
	return this->mUnits;
}

void TransactionNode::printData()
{
	cout << this->mUnits << endl;
}