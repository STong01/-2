#include <iostream>
using namespace std;

//求两个数的最大公约数
int gcd(int a, int b)
{
	int r;
	while (r = a%b)
	{
		a = b;
		b = r;
	}
	return b;
}

int main1()
{
	int a, b;
	while (cin >> a >> b)
	{
		//输出两个数的最大公倍数
		cout << a * b / gcd(a, b) << endl;
	}
	system("pause");
	return 0;
}