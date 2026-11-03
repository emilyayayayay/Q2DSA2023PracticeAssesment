#include <iostream>
#include "iStack.h"

using namespace std;

//c) 
//Create a new stack called second.
//copy first into second using your copy constructor.
//Print second.
//Compare first and second using <=
int main()
{
    //push some values onto first stack
    iStack first; 

    for (int count = 1; count <= 5; count++)
    {
        first.push(count);
    }

    cout << "First stack: ";
    first.print();
    cout << endl;

    //add the copt constructor test
    iStack second(first); 
    //iStack = create an object of the iStack class.
    //second = name of the new object.
    //(first) = copy the contents of first into second.

    //print the second stack
    cout << "Second stack: ";
    second.print();
    cout << endl; 

    //compare the both stack
    if (first <= second)
    {
        cout << "first is less than or equal to second" << endl;
    }
    else
    {
        cout << "first is NOT less than or equal to second" << endl;
    }

    //d) pop one element from first and push it back increment by 1
    int value = first.pop(); //removes the top element from first
    //then also store that returned value inside the variable value
    first.push(value + 1);
    //value + 1 increments the value by 1.
    //first.push() pushes the new value onto the stack.

    //print both stacks again
    cout << "First Stack: ";
    first.print();

    cout << "Second Stack: ";
    second.print();

    return 0;
}