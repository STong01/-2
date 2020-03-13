#include <iostream>
#include <algorithm>
using namespace std;

//从当前位置开始搜索
int getsum(int x[], int n, int pos, int sum, int mul)
{
	//x[]袋子中所有球；n球的总数；pos当前位置；sum总和；mul总积
	int count = 0;
	for (int i = pos; i < n; i++)
	{
		sum += x[i];
		mul *= x[i];
		if (sum>mul)
		{
			//条件符合，总和加1，继续向后搜索
			count += 1 + getsum(x, n, i + 1, sum, mul);
		}
		else if (x[i] == 1)
		{
			//条件不符合，继续向后搜索
			count += getsum(x, n, i + 1, sum, mul);
		}
		else
		{
			//sum < mul则后面没有符合的组合了
			break;
		}
		//搜索下一个位置时候，sum和mul恢复
		sum -= x[i];
		mul /= x[i];
		while (i < n - 1 && x[i] == x[i + 1])
		{
			i++;
		}
	}
	return count;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int x[] = { 0 };
		for (int i = 0; i < n; i++)
		{
			cin >> x[i];
		}
		sort(x, x + n);
		cout << getsum(x, n, 0, 0, 1) << endl;
	}
	system("pause");
	return 0;
}