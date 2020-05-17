#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

//中序遍历下，找到指定节点的下一个节点
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	//节点不存在，直接返回nullptr
	if (pNode == nullptr)
	{
		return nullptr;
	}

	BinaryTreeNode* pNext = nullptr;
	//当节点右节点存在，则下个节点是右子树下的最左侧节点
	if (pNode->m_pRight != nullptr)
	{
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
		{
			pRight = pRight->m_pLeft;
		}

		pNext = pRight;
	}
	//当节点不存在右节点的时候，下个节点则忘上寻找
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		//当找到的节点是父节点的右孩子的时候，下个节点继续往爷爷节点寻找
		while (pParent != nullptr && pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		//当找到的节点是父节点的左孩子的时候，下个节点则是父节点
		pNext = pParent;
	}
	return pNext;
}

int main()
{

	system("pause");
	return 0;
}