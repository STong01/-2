#include <iostream>
#include <algorithm>
using namespace std;

int main1()
{
	int n;
	while (cin >> n)
	{
		cout << n << " = ";
		for (int i = 2; i <= sqrt(n); i++)
		{
			while (n != i)
			{
				if (n % i == 0)
				{
					cout << i << " * ";
					n = n / i;
				}
				else
				{
					break;
				}
			}
		}
		cout << n << endl;
	}
	system("pause");
	return 0;
}