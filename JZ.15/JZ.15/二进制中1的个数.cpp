#include <iostream>
using namespace std;

//ֻ���ж�������������������ʱ�򣬷���λ��Ӱ��λ������ж�
int NumberOf1_Way1(int n)
{
	int count = 0;
	while (n != 0)
	{
		if (n & 1)
		{
			count++;
		}
		n = n >> 1;
	}
	return count;
}

//������1������������λ���㣬��ʱ����λҲ����ͳ�Ƴ���
int NumberOf1_Way2(int n)
{
	int count = 0;
	unsigned int num = 1;
	while (num)
	{
		if (n & num)
		{
			count++;
		}
		num = num << 1;
	}
	return count;
}

//��һ��������ȥ1���ٺ�ԭ�����������㣬�Ϳ��԰��������ұߵ�1���0
int NumberOf1_Way3(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n = (n - 1)&n;
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << NumberOf1_Way3(n) << endl;
	}

	system("pause");
	return 0;
}