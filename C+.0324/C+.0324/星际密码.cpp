#include <iostream>
#include <vector>
using namespace std;

//星际密码
//构建密码数列
int init(int n)
{
	vector<int>a = { 1, 1 };
	for (int i = 2; i <= n; i++)
	{
		a.push_back((a[i - 1] + a[i - 2]) % 10000);
	}
	return a[n];
}

int main1()
{
	int sum, n;
	while (cin >> sum)
	{
		while (sum--)
		{
			cin >> n;
			int tmp = init(n);
			//取密码后四位，当不足四位的时候，前面补0，补满四位
			printf("%04d", tmp);
		}
		cout << endl;
	}
	system("pause");
	return 0;

}
