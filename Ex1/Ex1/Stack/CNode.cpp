#include "CNode.h"

CNode::CNode()
{
	prevNode = nullptr;
	nextNode = nullptr;
}

void CNode::SetData(int iData)
{
	data = iData;
}

int CNode::GetData() const
{
	return data;
}

void CNode::SetNextNode(CNode *newnextNode)
{
	nextNode = newnextNode;
}

void CNode::SetPrevNode(CNode * newprevNode)
{
	prevNode = newprevNode;
}

CNode * CNode::GetNextNode() const
{
	return nextNode;
}

CNode * CNode::GetPrevNode() const
{
	return prevNode;
}
