#include <iostream>
#include <algorithm>
using namespace std;

//完全数计算
int count(int n)
{
	int cur = 0;
	if ((n < 0) | (n > 500000))
	{
		return -1;
	}
	else
	{
		for (int i = 2; i <= n; i++)
		{
			int sum = 0;
			double q = sqrt(i);
			for (int j = 2; j <= q; j++)
			{
				//计算数的约数
				if (i % j == 0)
				{
					if (i / j == j)
					{
						sum += j;
					}
					else
					{
						sum += j + (i / j);
					}
				}
			}

			if (sum + 1 == i)
			{
				cur++;
			}
		}
		return cur;
	}
}

int main1()
{
	int input;
	while (cin >> input)
	{
		cout << count(input) << endl;
	}
	system("pause");
	return 0;
}