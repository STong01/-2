#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void test(int n, int m, vector<int>& p, int tmp)
{
	if (m == 0)
	{
		for (int i = 0; i < p.size(); i++)
		{
			if (i == 0)
			{
				cout << p[i];
			}
			else
			{
				cout << ' ' << p[i];
			}
		}
		cout << endl;
	}

	for (int i = tmp; i <= min(n, m); i++)
	{
		p.push_back(i);
		test(n, m - i, p, i + 1);
		p.pop_back();
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		vector<int> p;
		test(n, m, p, 1);
	}
	system("pause");
	return 0;
}