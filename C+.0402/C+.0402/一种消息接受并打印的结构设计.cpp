#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n;
	while (cin >> n)
	{
		vector<int> cur = { 0 };
		cur.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> cur[i];
		}

		int len = cur.size();
		map<int, int>tmp;

		int count = 1;
		int sum = 1;
		//int num = 0;

		for (int i = 0; i < len; i++)
		{
			if (cur[i] == sum)
			{
				count = cur[i];
				cout << cur[i] << " " << count << endl;
				sum++;
			}
			else
			{
				tmp[cur[i]] = cur[i];

				if (tmp[sum] == sum)
				{
					cout << sum << " " << count << endl;
					sum++;
					//num++;
				}
			}
			while (tmp[sum] == sum)
			{
				cout << tmp[sum] << " " << count << endl;
				sum++;
				//num++;
				if (sum == tmp.size() + 1)
				{
					break;
				}
			}
		}

	}

	system("pause");
	return 0;
}
