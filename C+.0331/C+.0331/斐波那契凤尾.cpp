#include <iostream>
#include <vector>
using namespace std;

int test(int n)
{
	vector<int> tmp = { 1, 1 };
	int num = 0;
	for (int i = 2; i <= n; i++)
	{
		tmp.push_back(tmp[i - 1] + tmp[i - 2]);
	}
	num = tmp[n] % 1000000;
	return num;
}

int main()
{
	int n;
	while (cin >> n)
	{
		cout << test(n) << endl;
	}

	system("pause");
	return 0;
}