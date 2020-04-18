#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, m;
	int r, c;
	while (cin >> n >> m)
	{
		cin >> r >> c;
		vector<vector<long>> p(n, vector<long>(m, 0));
		int i = 0;
		int j = 0;
		int num = 1;
		p[i][j] = num;
		while (num != n*m)
		{
			while (j + 1 < m && p[i][j + 1] == 0)
			{
				num = num + 1;
				p[i][j + 1] = num;
				j = j + 1;
			}
			while (i + 1 < n && p[i + 1][j] == 0)
			{
				num = num + 1;
				p[i + 1][j] = num;
				i = i + 1;
			}
			while (j - 1 >= 0 && p[i][j - 1] == 0)
			{
				num = num + 1;
				p[i][j - 1] = num;
				j = j - 1;
			}
			while (i - 1 >= 0 && p[i - 1][j] == 0)
			{
				num = num + 1;
				p[i - 1][j] = num;
				i = i - 1;
			}
		}
		cout << p[r - 1][c - 1] << endl;
	}

	return 0;
}