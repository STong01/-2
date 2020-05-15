#include <iostream>
using namespace std;

struct ListNode1
{
	//单向链表的节点定义
	int m_nValue;
	ListNode1* m_pNext;
};

//链表末尾添加一个节点
void AddToTail(ListNode1** pHead, int value)
{
	ListNode1* pNew = new ListNode1();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode1* pNode = *pHead;

		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = pNew;
	}
}

//在链表中找到第一个含有某值的节点并删除该节点
void RemoveNode(ListNode1** pHead, int value)
{
	if (pHead == nullptr || *pHead == nullptr)
	{
		return;
	}

	ListNode1* pToBeDeleted = nullptr;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode1* pNode = *pHead;
		while (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
		{
			pNode = pNode->m_pNext;
		}

		if (pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
		{
			pToBeDeleted = pNode->m_pNext;
			pNode->m_pNext = pNode->m_pNext->m_pNext;
		}
	}

	if (pToBeDeleted != nullptr)
	{
		delete pToBeDeleted;
		pToBeDeleted = nullptr;
	}
}

int main0()
{

	system("pause");
	return 0;
}