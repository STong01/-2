#include <iostream>
using namespace std;

//只能判断正数，当遇到负数的时候，符号位会影响位运算的判断
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

//将数与1的左移数进行位运算，此时符号位也可以统计出来
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

//把一个整数减去1，再和原整数做与运算，就可以把整数最右边的1变成0
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