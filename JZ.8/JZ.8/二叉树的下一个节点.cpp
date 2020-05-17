#include <iostream>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
	BinaryTreeNode* m_pParent;
};

//��������£��ҵ�ָ���ڵ����һ���ڵ�
BinaryTreeNode* GetNext(BinaryTreeNode* pNode)
{
	//�ڵ㲻���ڣ�ֱ�ӷ���nullptr
	if (pNode == nullptr)
	{
		return nullptr;
	}

	BinaryTreeNode* pNext = nullptr;
	//���ڵ��ҽڵ���ڣ����¸��ڵ����������µ������ڵ�
	if (pNode->m_pRight != nullptr)
	{
		BinaryTreeNode* pRight = pNode->m_pRight;
		while (pRight->m_pLeft != nullptr)
		{
			pRight = pRight->m_pLeft;
		}

		pNext = pRight;
	}
	//���ڵ㲻�����ҽڵ��ʱ���¸��ڵ�������Ѱ��
	else if (pNode->m_pParent != nullptr)
	{
		BinaryTreeNode* pCurrent = pNode;
		BinaryTreeNode* pParent = pNode->m_pParent;
		//���ҵ��Ľڵ��Ǹ��ڵ���Һ��ӵ�ʱ���¸��ڵ������үү�ڵ�Ѱ��
		while (pParent != nullptr && pCurrent == pParent->m_pRight)
		{
			pCurrent = pParent;
			pParent = pParent->m_pParent;
		}
		//���ҵ��Ľڵ��Ǹ��ڵ�����ӵ�ʱ���¸��ڵ����Ǹ��ڵ�
		pNext = pParent;
	}
	return pNext;
}

int main()
{

	system("pause");
	return 0;
}