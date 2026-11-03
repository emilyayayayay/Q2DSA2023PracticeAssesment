#pragma once

#include "iStackNode.h"

class iStack
{
public:
	iStack();		 // parameter-less constructor
	~iStack();		 // destructor

	int push(int i); // push item i onto stack
	int pop();		 // pop off top item 
	int size();		 // return number of items in stack
	void print();	 // prints stack contents form top to bottom in a single line

	//a)defiine and implement a copy constructor for the iStack class
	//the function prototype is as follows
	//implement it in iStack.cpp
	iStack(const iStack& stk);

	//b) perform the <= logical comparison of two stack objects using operator overloading
	//implement it in iStack.cpp
	bool operator <= (const iStack& stk) const;

private:
	iStackNode* pTos;
	int stackSize;
};


