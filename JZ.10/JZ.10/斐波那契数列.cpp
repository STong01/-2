#include <iostream>
using namespace std;

//递归求解斐波那契数列，此方法存在严重效率问题
long long Fibonacci1(unsigned int n)
{
	if (n <= 0)
	{
		return 0;
	}
	else if (n == 1)
	{
		return 1;
	}
	else
	{
		return Fibonacci1(n - 1) + Fibonacci1(n - 2);
	}
}

long long Fibonacci2(unsigned n)
{
	int result[2] = { 0, 1 };
	if (n < 2)
	{
		return result[n];
	}

	long long fibNminusOne = 1;
	long long fibNminusTwo = 0;
	long long fibN = 0;
	for (unsigned int i = 2; i <= n; i++)
	{
		fibN = fibNminusOne + fibNminusTwo;
		fibNminusTwo = fibNminusOne;
		fibNminusOne = fibN;
	}

	return fibN;
}

int main()
{
	unsigned int n = 0;
	while (cin >> n)
	{
		cout << Fibonacci1(n) << endl;
		cout << Fibonacci2(n) << endl;

	}

	system("pause");
	return 0;
}