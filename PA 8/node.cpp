#include "Node.h"

Node::Node(const string& newData)
{
	this->mData = newData;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}

Node::Node(const Node& copyNode)
{

}

Node::~Node()
{

}

void Node::setData(string newData)
{
	this->mData = newData;
}

void Node::setLeftPtr(Node* newLeftPtr)
{
	this->mpLeft = newLeftPtr;
}

void Node::setRightPtr(Node* newRightPtr)
{
	this->mpRight = newRightPtr;
}

string Node::getData() const
{
	return this->mData;
}

Node*& Node::getLeftPtr()
{
	return this->mpLeft;
}

Node*& Node::getRightPtr()
{
	return this->mpRight;
}

void Node::printData()
{
	cout << this->mData << ": ";
}