#include <iostream>
#include <queue>
#include <stack>
using namespace std;

template<typename T>class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void addendTail(const T& node);
	T deleteHead();

private:
	stack<T>stack1;
	stack<T>stack2;
};

//stack1����ʵ�ֲ���Ԫ��
//��ɾ��Ԫ�ص�ʱ����stack2�л�����Ԫ�أ���ֱ��ɾ��stack2ջ����Ԫ��
//��stack2�в�����Ԫ�ص�ʱ����stack1�е�Ԫ��һһpop��Ȼ��Ԫ��push��stack2�м���

//��ջʵ���ڶ���β���в���ڵ�
template<typename T>void CQueue<T>::addendTail(const T& element)
{
	stack1.push(element);
}

//��ջʵ��ɾ�������ײ���Ԫ��
template<typename T>T CQueue<T>::deleteHead()
{
	if (stack2.size() <= 0)
	{
		while (stack1.size() > 0)
		{
			T& data = stack1.top();
			stack1.pop();
			stack2.push(data);
		}
	}

	if (stack2.size() == 0)
	{
		throw new exception("queue is empty");
	}

	T head = stack2.top();
	stack2.pop();

	return head;
}

int main()
{

	system("pause");
	return 0;
}