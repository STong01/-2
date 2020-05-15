#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

typedef struct ListNode
{
	//单向链表的节点定义
	int m_nValue;
	ListNode* m_pNext;
}List;

typedef struct SList
{
	ListNode* _head;
}List1;

void ListInit(SList* plist)
{
	assert(plist);
	plist->_head = NULL;
}

//链表末尾添加一个节点
void AddToTail(ListNode** pHead, int value)
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = nullptr;

	if (*pHead == nullptr)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode* pNode = *pHead;

		while (pNode->m_pNext != nullptr)
		{
			pNode = pNode->m_pNext;
		}

		pNode->m_pNext = pNew;
	}
}

//用栈实现将链表从尾到头打印
void PrintListReversingly_Iteratively(ListNode* pHead)
{
	std::stack<ListNode*>nodes;

	ListNode* pNode = pHead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d/t", pNode->m_nValue);
		nodes.pop();
	}
}

//递归实现将链表从尾到头打印
void PrintListReversingly_Recursively(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->m_pNext != nullptr)
		{
			PrintListReversingly_Recursively(pHead->m_pNext);
		}

		printf("%d\t", pHead->m_nValue);
	}
}

int main()
{

	SList* test;
	test->_head->m_nValue = 1;
	ListInit(test);
	ListNode* pnew;
	AddToTail(&pnew, 1);
	AddToTail(&pnew, 3);
	AddToTail(&pnew, 5);
	AddToTail(&pnew, 7);
	AddToTail(&pnew, 9);
	AddToTail(&pnew, 2);
	AddToTail(&pnew, 4);
	AddToTail(&pnew, 6);
	AddToTail(&pnew, 8);
	AddToTail(&pnew, 10);

	PrintListReversingly_Iteratively(pnew);

	system("pause");
	return 0;
}