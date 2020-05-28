#include <iostream>
#include <algorithm>
using namespace std;

bool test9(long long n)
{
	for (long long i = 2; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			return false;
		}
	}
	return true;
}

int main9()
{
	long long n, m;
	while (cin >> n >> m)
	{
		long long sum = 0;
		for (long long i = n; i <= m; i++)
		{
			if (test9(i))
			{
				sum++;
			}
		}
		cout << sum << endl;
	}

	return 0;
}