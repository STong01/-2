#include <iostream>
#include <vector>
#include <algorithm>
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
		vector<int>tmp = { 0 };

		int count = 1;
		int sum = 1;
		int num = 1;
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
				tmp.push_back(cur[i]);
				sort(tmp.begin(), tmp.end());
				if (tmp[num] == sum)
				{
					cout << tmp[num] << " " << count << endl;
					sum++;
					num++;
				}
			}
			while ((tmp[num] == sum) && num < tmp.size())
			{
				cout << tmp[num] << " " << count << endl;
				sum++;
				num++;
			}
		}
	}

	system("pause");
	return 0;
}
