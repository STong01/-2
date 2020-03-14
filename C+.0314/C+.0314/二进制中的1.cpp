#include <iostream>
using namespace std;

//二进制中1的个数
int main1()
{
	int n;
	while (cin >> n)
	{
		int count = 0;
		while (n)
		{
			if ((n & 1) == 1)
			{
				count++;
			}
			n >>= 1;
		}
		cout << count << endl;
	}
	system("pause");
	return 0;
}