#pragma once


class iStackNode
{
public:
	// parameterised constructor
	iStackNode(int i, iStackNode* pNxtNode);
	// destructor
	~iStackNode();

	// public members (data & functions)
	int item;
	iStackNode* pNextNode;

private:
	// private members (data & functions)
};


