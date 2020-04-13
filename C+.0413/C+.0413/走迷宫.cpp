#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int a[10][10] = { 0 };
char str[10][10] = { 0 };

int Findload(int x, int y)
{
	queue<pair<int, int>> w;
	int x0, y0;
	w.push(make_pair(x, y));
	while (true)
	{
		x0 = w.front().first;
		y0 = w.front().second;
		if (x0 == 9 && y0 == 8)
		{
			return a[9][8];
		}
		if ((x0 + 1 >= 0) && (x0 + 1 <= 9) && (y0 >= 0) && (y0 <= 9) && (a[x0 + 1][y0] == 0) && (str[x0 + 1][y0] != '#'))
		{
			a[x0 + 1][y0] = a[x0][y0] + 1;
			w.push(make_pair(x0 + 1, y0));
		}
		if ((x0 - 1 >= 0) && (x0 - 1 <= 9) && (y0 >= 0) && (y0 <= 9) && (a[x0 - 1][y0] == 0) && (str[x0 - 1][y0] != '#'))
		{
			a[x0 - 1][y0] = a[x0][y0] + 1;
			w.push(make_pair(x0 - 1, y0));
		}		
		if ((y0 + 1 >= 0) && (y0 + 1 <= 9) && (x0 >= 0) && (x0 <= 9) && (a[x0][y0 + 1] == 0) && (str[x0][y0 + 1] != '#'))
		{
			a[x0][y0 + 1] = a[x0][y0] + 1;
			w.push(make_pair(x0, y0 + 1));
		}		
		if ((y0 - 1 >= 0) && (y0 - 1 <= 9) && (x0 >= 0) && (x0 <= 9) && (a[x0][y0 - 1] == 0) && (str[x0][y0 - 1] != '#'))
		{
			a[x0][y0 - 1] = a[x0][y0] + 1;
			w.push(make_pair(x0, y0 - 1));
		}
		w.pop();
	}
}

int main()
{
	char s;
	while (cin >> s)
	{
		str[0][0] = s;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (i == 0 && j == 0)
				{
					continue;
				}
				cin >> str[i][j];
			}
		}

		cout << Findload(0, 1) << endl;
		memset(a, 0, sizeof(a));
	}
	return 0;
}