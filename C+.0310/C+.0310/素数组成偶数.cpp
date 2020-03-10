#include <iostream>
#include <algorithm>
using namespace std;

//判断是不是素数
bool isPrime(int num)
{
	int tmp = sqrt(num);

	for (int i = 2; i <= tmp; i++)
	{
		if (num%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int n;
	int half;
	int i;
	while (cin >> n)
	{
		half = n / 2;

		for (i = half; i > 0; i--)
		{
			if (isPrime(i) && isPrime(n - i))
			{
				break;
			}
		}
		cout << i << endl;
		cout << n - i << endl;
	}

	system("pause");
	return 0;
}