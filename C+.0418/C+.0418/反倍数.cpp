#include <iostream>
using namespace std;

int main2()
{
	long num;
	long a, b, c;
	while (cin >> num)
	{
		cin >> a >> b >> c;
		long count = 0;
		for (long i = 0; i <= num; i++)
		{
			if ((i % a != 0) && (i % b != 0) && (i % c != 0))
			{
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}
