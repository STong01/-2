#include <iostream>
#include <vector>
using namespace std;

int main2()
{
	vector<long> p = { 0, 1, 1 };
	long from, to;
	while (cin >> from >> to)
	{
		for (long i = 2; i <= to; i++)
		{
			p.push_back(0);
			p[i] = p[i - 1] + p[i - 2];
		}
		long sum = 0;
		for (long i = from; i <= to; i++)
		{
			sum += p[i];
		}
		cout << sum << endl;
	}

	system("pause");
	return 0;
}