#include <iostream>
#include <algorithm>
using namespace std;

bool test11(long long n)
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

int main11()
{
	long long x, y;
	long long n;
	cin >> n;
	while (n > 0)
	{
		cin >> x >> y;
		long long cur = y - x;
		if (cur == 1 || cur == 0)
		{
			cout << "No" << endl;
		}
		else if (cur % 2 == 0)
		{
			cout << "Yes" << endl;
		}
		else if (test11(cur))
		{
			cout << "Yes" << endl;
		}

		n--;
	}
	return 0;
}