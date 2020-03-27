#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		int k = 0;
		for (int i = 2; i <= sqrt(n); i++)
		{
			if ((n % i) == 0)
			{
				while ((n % i) == 0)
				{
					n = n / i;
				}
				//cout << i << ' ';
				k++;
			}
		}

		if (n != 1)
		{
			//cout << n << endl;
			k++;
		}
		cout << k << endl;
	}
	system("pause");
	return 0;
}