#ifndef _NODE_H__
#define _NODE_H__

class CNode{
private:
	int data;
	CNode *nextNode;
	CNode *prevNode;
public:
	CNode();
	void SetData(int iData);
	int GetData() const;
	void SetNextNode(CNode *newnextNode);
	void SetPrevNode(CNode *newprevNode);
	CNode* GetNextNode() const;
	CNode* GetPrevNode() const;
};

#endif