#include <iostream>
using namespace std;

bool test(int n)
{
	for (int i = 2; i < n; i++)
	{
		if (n%i == 0)
		{
			return false;
		}
	}
	return true;
}

int main2()
{

	int n;
	while (cin >> n)
	{
		int sum = 0;
		for (int i = 2; i <= n; i++)
		{
			if (test(i))
			{
				sum++;
			}
		}
		cout << sum << endl;
	}

	return 0;
}