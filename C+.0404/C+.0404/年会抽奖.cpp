#include <iostream>
#include <vector>
using namespace std;

int main()
{
	vector<long long> tmp = { 0, 0, 1 };
	vector<long long> fun = { 0, 1, 2 };

	int n;
	//无人获奖情况递减
	//fun表示n人时候，总的抽取的情况，为n!
	//tmp为无人获奖的情况，假设B拿了A名字，则1、A恰好拿了B的名字，则情况变为tmp[n - 2];
	//2、A没有拿B的名字，则情况变为tmp[n - 1]
	for (int i = 3; i < 21; i++)
	{
		tmp.push_back(0);
		tmp[i] = (i - 1) * (tmp[i - 2] + tmp[i - 1]);
		fun.push_back(0);
		fun[i] = i * fun[i - 1];
	}
	while (cin>>n)
	{
		printf("%.2f%c\n", 1.0*tmp[n] / fun[n] * 100, '%');
	}

	system("pause");
	return 0;
}
