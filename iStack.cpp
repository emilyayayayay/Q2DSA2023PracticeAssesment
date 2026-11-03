#include "iStack.h"
#include <iostream>
using namespace std;

iStack::iStack()
{
	pTos = NULL;
	stackSize = 0;
}

iStack::~iStack()
{
	while (stackSize != 0)
		pop();
}

int iStack::push(int i)
{
	iStackNode* pNewTos = new iStackNode(i, pTos);
	pTos = pNewTos;
	stackSize++;
	return i;
}

int iStack::pop()
{
	if (pTos) {
		int item = pTos->item;
		iStackNode* pNewTos = pTos->pNextNode;
		delete pTos;
		pTos = pNewTos;
		stackSize--;
		return item;
	}
	exit(0);
}

int iStack::size()
{
	return stackSize;
}

void iStack::print() {
	iStackNode* ptr = pTos; // a pointer to the top of the stack
	while (ptr != NULL) {
		cout << ptr->item << " "; // output item
		ptr = ptr->pNextNode;	  // move ptr to next iStackNode
	}
	cout << endl;
}

//a) implementing the function
//stk = size of the other stack
iStack :: iStack(const iStack& stk) //copying constructor declaration
{
	pTos = NULL; //initialise the new stack
	//pTos : pointer to the top of the stack, NULL : doesnt point to anything
	//why? the new stack must start empty before we add any nodes
	stackSize = 0; //stores the number of nodes in the stack
	//why? cz we hvnt copied any items yet

	iStack temp; //create another stack called temp
	//why? We need a temporary stack to help us preserve the original order.
	//Remember: when we push something onto a stack, it becomes the new top.
	//We'll use temp to reverse the order once, then reverse it again when copying into our new stack.

	iStackNode* ptr = stk.pTos; //create a pointer to the og stack
	//iStackNode* means ptr is a pointer to a stack node.
	//stk.pTos accesses the top node of the original stack.
	//ptr starts at that top node.
	//why? We need a pointer to traverse through the original stack and access every node.

	while (ptr != nullptr) //keep repeating while ptr is not pointing to anythign empty
	//why? we want to visit every node in the og stack
	{
		temp.push(ptr -> item); //copy the current item's value into temp
		//ptr->item accesses the value stored in the current node.
		//temp.push() pushes that value onto the temporary stack.
		//why? we want to copy every value from the og stack into temp
		ptr = ptr -> pNextNode; //move to the next node
		//ptr->pNextNode accesses the pointer to the next node.
		//We update ptr to point to that next node.
		//why? So we can move through the original stack instead of repeatedly looking at the same node.
	}

	while (temp.size() != 0) //We want to keep transferring items until the temporary stack is empty.
	//temp.size() returns the number of items in the temporary stack.
	//!= 0 means the size is NOT zero.
	//while temp size not yet empty, we will keep popping
	{
		push(temp.pop());
		//temp.pop() removes and returns the top item from the temporary stack.
		//push() pushes that returned value onto our new stack.
	}

	//A stack is LIFO (Last In, First Out). We use a temporary stack because copying directly using push() 
	//would reverse the original order. Using two reversals preserves the order.
}

//b) implementing the bool operator <= (const iStack& stk);
//both stacks must hv the same size
//Every corresponding item in the first stack must be less than or equal to the corresponding item in the second stack.
bool iStack::operator<=(const iStack& stk) const
//operator<=: overloads the <= operator.
//const iStack& stk: receives the second stack without copying it.
//Final const: promises not to modify the current stack.
{
    if (stackSize != stk.stackSize) //if current stack not equal to the other stack
    {
		return false; //then return false
	}    

    const iStackNode* ptr1 = pTos; //ptr1 points to the top of the first stack.
    const iStackNode* ptr2 = stk.pTos; //ptr2 points to the top of the second stack.
	//We need two pointers because we want to compare corresponding nodes in both stacks.

    while (ptr1 != nullptr && ptr2 != nullptr) //while the stack is not empty yet
    {
        if (ptr1->item > ptr2->item) //check if it violates the <= condition
        {
			return false;
		}

		//move to the next nodes
        ptr1 = ptr1->pNextNode;
        ptr2 = ptr2->pNextNode;
    }

    return true;
}
