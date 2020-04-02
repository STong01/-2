#include <iostream>
#include <vector>
using namespace std;

int main1()
{
	//直接从收养的那天计算，收养的那天记为第0天，个数为1
	vector<long long> p = { 1, 1 };
	int day;
	while (cin >> day)
	{
		for (int i = 2; i <= day; i++)
		{
			p.push_back(0);
			p[i] = p[i - 1] + p[i - 2];
		}
		cout << p[day] << endl;
	}

	system("pause");
	return 0;
}