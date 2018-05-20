#include "CNode.h"

CNode::CNode()
{

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

CNode * CNode::GetNextNode() const
{
	return nextNode;
}
