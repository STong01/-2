#include <iostream>
#include <set>
using namespace std;

int main()
{
	int num;
	int sum;
	while (cin >> num >> sum)
	{
		int hotkey;
		int n, key, val;
		int sum1 = 0;
		set<int> tmp;
		for (int i = 0; i < num; i++)
		{
			cin >> n >> key >> val;
			if (n == 1)
			{
				hotkey = key;
				tmp.insert(key, val);
				sum1++;
				if (sum1 == sum)
				{
					tmp
				}
			}
			else if (n == 2)
			{

			}
		}

	}

	system("pause");
	return 0;
}
