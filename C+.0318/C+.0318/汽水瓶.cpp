#include <iostream>
#include <string>
using namespace std;

int P_num(int num)
{
	int sum = 0;
	while (num > 1)
	{
		//三个瓶子换一瓶水喝
		int cur1 = num / 3;
		//不够三个瓶子先留着
		int cur2 = num % 3;
		//可以喝的水为换回来的水以及原来喝下的水
		sum = sum + cur1;
		//现在手中所拥有的瓶子数为换水之后的瓶子以及剩余的瓶子数
		num = cur2 + cur1;
		if (num == 2)
		{
			sum++;
			break;
		}
	}
	return sum;
}

int main()
{
	int number;
	while (cin >> number)
	{
		cout << P_num(number) << endl;
	}
	system("pause");
	return 0;
}