#include <iostream>
using namespace std;

int L_num(int n, int m)
{
	//n, m������һ��ʱ��������������߷������»�������
	//���õݹ鵽��[n, m - 1]����[n - 1, m]���ж��������м���
	if (n > 1 && m > 1)
	{
		return L_num(n - 1, m) + L_num(n, m - 1);
	}
	//ֻ��һ�л���һ�е����
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