#include "iStackNode.h"

// constructor - set the node's item, pNextNode with given i, pNxtNode
iStackNode::iStackNode(int i, iStackNode* pNxtNode)
	: item(i), pNextNode(pNxtNode)
{
}
// the above is equivalent to
//iStackNode::iStackNode(int i, iStackNode* pNxtNode)
//{
//	item = i;
//	pNextNode = pNxtNode;
//}

// destructor - no code in this example
iStackNode::~iStackNode()
{
}
