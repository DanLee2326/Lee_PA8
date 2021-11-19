#include "DataAnalysis.h"

void DataAnalysis::runAnalysis()
{
	openFile();
	readLines();
	printTrends();
}

void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv", std::ios::in);
}

void DataAnalysis::splitLine(int& newUnits, string& newType, string& newField)
{
	char line[100] = "";

	mCsvStream.getline(line, 100, ',');
	newUnits = atoi(line);
	mCsvStream.getline(line, 100, ',');
	newType = line;
	mCsvStream.getline(line, 100);
	newField = line;
}

void DataAnalysis::readLines() // calls compare(), use inOrderTraversal() for display
{
	int Units = 0;
	string Type = "";
	string Field = "";
	char removeL[100] = "";

	mCsvStream.getline(removeL, 100);

	while (!mCsvStream.eof())
	{
		splitLine(Units, Type, Field);
		compareInsert(Units, Type, Field);
	}
	mCsvStream.close();
	
	cout << "Sold Tree" << endl;
	cout << "------------------------------------------------" << endl;
	mTreeSold.inOrderTraversal();

	cout << endl;

	cout << "Purchased Tree" << endl;
	cout << "------------------------------------------------" << endl;
	mTreePurchased.inOrderTraversal();
}

void DataAnalysis::compareInsert(int& newUnits, string& newType, string& newField)
{
	if (newField == "Purchased")
	{
		mTreePurchased.insert(newType, newUnits);
	}
	else if (newField == "Sold")
	{
		mTreeSold.insert(newType, newUnits);
	}
}

void DataAnalysis::printTrends()
{
	TransactionNode tn;

	cout << endl;
	cout << "Most Sold - ";
	tn = mTreeSold.findLargest();
	tn.Node::printData();
	tn.printData();
	
	cout << "Least Sold - ";
	tn = mTreeSold.findSmallest();
	tn.Node::printData();
	tn.printData();
	
	cout << "Most Purchased - " ;
	tn = mTreePurchased.findLargest();
	tn.Node::printData();
	tn.printData();
	
	cout << "Least Purchased - ";
	tn = mTreePurchased.findSmallest();
	tn.Node::printData();
	tn.printData();
}