#include <iostream>
using namespace std;

int L_num(int n, int m)
{
	//n, m都大于一此时这个格子有两种走法，向下或者向右
	//利用递归到达[n, m - 1]或者[n - 1, m]在判断条件进行计算
	if (n > 1 && m > 1)
	{
		return L_num(n - 1, m) + L_num(n, m - 1);
	}
	//只有一行或者一列的情况
	//sum = n + m
	else if (((n >= 1) && (m == 1)) || ((n == 1) && (m >= 1)))
	{
		return n + m;
	}
	else
	{
		return 0;
	}
}

int main()
{
	int n, m;
	while (cin >> n >> m)
	{
		cout << L_num(n, m) << endl;
	}
	system("psuse");
	return 0;
}