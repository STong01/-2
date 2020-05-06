#include <iostream>
using namespace std;

//斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项.
int Fibonacci1(int n)//斐波那契数列
{
	//定义数组，保存状态值
	int* fi = new int[n + 1];
	//初始化数据
	fi[0] = 0;
	fi[1] = fi[2] = 1;
	//循环构建数组
	for (int i = 2; i <= n; i++)
	{
		fi[i] = fi[i - 1] + fi[i - 2];
	}

	return fi[n];
}

int Fibonacci2(int n)//斐波那契数列
{
	if (n == 0)
		return 0;
	if (n == 1 || n == 2)
		return 1;

	int fn = 0;
	int fn1 = 0, fn2 = 1;

	for (int i = 2; i <= n; i++)
	{
		fn = fn1 + fn2;
		fn1 = fn2;
		fn2 = fn;
	}

	return fn;
}

//一只青蛙一次可以跳上1级台阶，也可以跳上2级……它也可以跳上n级。求该青蛙跳上一个n级的台阶总共有多少种跳法
//分析除了最后一块台阶，其他台阶是否跳上去，只有两中可能，跳上去或者不跳上去（2），所以最终选择为2^n
int jumpFloorII1(int number)
{
	return 1 << (number - 1);
}

int jumpFloorII2(int number)
{
	int sum = 1;
	for (int i = 1; i < number; i++)
	{
		sum *= 2;
	}
	return sum;
}

int main()
{
	int n;
	while (cin >> n)
	{
		int cur = jumpFloorII2(n);
		cout << cur << endl;

	}
	

	system("pause");
	return 0;
}