#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
	unsigned int n;
	cin >> n;
	vector<string> st;
	st.resize(n);
	for (unsigned int i = 0; i < n; i++)
	{
		cin >> st[i];
	}

	for (unsigned int j = 0; j < n; j++)
	{
		long long sum = 0;
		for (unsigned int i = 0; i < st[j].size(); i++)
		{
			if (st[j][i] >= 'A' && st[j][i] <= 'Z' && i != st[j].size() - 1)
			{
				if (st[j][i] == 'C')
				{
					if (st[j][i + 1] >= 'A' && st[j][i + 1] <= 'Z')
					{
						sum += 12;
					}
					else
					{
						sum += (12 * (st[j][i + 1] - '0'));
					}
				}
				else if (st[j][i] == 'H')
				{
					if (st[j][i + 1] >= 'A' && st[j][i + 1] <= 'Z')
					{
						sum += 1;
					}
					else
					{
						sum += (1 * (st[j][i + 1] - '0'));
					}
				}
				else if (st[j][i] == 'O')
				{
					if (st[j][i + 1] >= 'A' && st[j][i + 1] <= 'Z')
					{
						sum += 16;
					}
					else
					{
						sum += (16 * (st[j][i + 1] - '0'));
					}
				}
				else if (st[j][i] == 'N')
				{
					if (st[j][i + 1] >= 'A' && st[j][i + 1] <= 'Z')
					{
						sum += 14;
					}
					else
					{
						sum += (14 * (st[j][i + 1] - '0'));
					}
				}
			}
			else if (st[j][i] >= 'A' && st[j][i] <= 'Z' && i == st[j].size() - 1)
			{
				if (st[j][i] == 'C')
				{
					sum += 12;
				}
				else if (st[j][i] == 'H')
				{
					sum += 1;
				}
				else if (st[j][i] == 'O')
				{
					sum += 16;
				}
				else if (st[j][i] == 'N')
				{
					sum += 14;
				}
			}
		}
		if (j == n - 1)
		{
			cout << sum << endl;
		}
		else
		{
			cout << sum << " ";
		}
	}
	return 0;
}