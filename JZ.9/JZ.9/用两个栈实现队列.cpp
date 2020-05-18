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

//stack1用来实现插入元素
//当删除元素的时候，若stack2中还存在元素，则直接删除stack2栈顶的元素
//若stack2中不存在元素的时候，则将stack1中的元素一一pop，然后将元素push到stack2中即可

//用栈实现在队列尾部中插入节点
template<typename T>void CQueue<T>::addendTail(const T& element)
{
	stack1.push(element);
}

//用栈实现删除队列首部的元素
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