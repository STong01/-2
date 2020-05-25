#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

inline int read()
{
	int x = 0, f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}

int main()
{
	int sum = read();
	while (sum > 0)
	{
		int num = read();
		int k = read();
		vector<int> p;
		p.resize(num);
		for (int i = 0; i < num; i++)
		{
			p[i] = read();
		}

		sort(p.begin(), p.end());

		cout << p[k - 1] << endl;

		sum--;
	}

	return 0;
}