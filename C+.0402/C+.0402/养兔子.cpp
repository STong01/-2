#include <iostream>
#include <vector>
using namespace std;

int main1()
{
	//ֱ�Ӵ�������������㣬�����������Ϊ��0�죬����Ϊ1
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