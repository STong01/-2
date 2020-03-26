#include <iostream>
#include <string>
using namespace std;

int main()
{
	long long n;
	int tmp;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		tmp = 0;
		while (n >= 2)
		{
			if (n % 3)
			{
				n = n / 3 + 1;
			}
			else
			{
				n /= 3;
			}
			tmp++;
		}
		cout << tmp << endl;
	}
	system("pause");
	return 0;
}
