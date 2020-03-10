#include <iostream>
#include <algorithm>
using namespace std;

//最大连续bit数
int main()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		int M_count = 0;
		while (n)
		{
			if (n & 1)
			{
				count++;
				M_count = max(count, M_count);
			}
			else
			{
				count = 0;
			}
			n = n >> 1;
		}
		cout << M_count << endl;
	}

	system("pause");
	return 0;
}