#include <iostream>
using namespace std;

//动态规划
int maxProductAfterCutting_solution1(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}

	int* products = new int[length + 1];
	products[0] = 0;
	products[1] = 1;
	products[2] = 2;
	products[3] = 3;

	int max = 0;
	for (int i = 4; i <= length; i++)
	{
		max = 0;
		for (int j = 1; j <= i / 2; ++j)
		{
			int product = products[j] * products[i - j];
			if (max < product)
			{
				max = product;
			}
			products[i] = max;
		}
	}

	max = products[length];
	delete[] products;

	return max;

}

//贪婪算法
//当n >= 5的时候，我们可以证明2(n - 2) > n并且3(n - 3) > n
//所以，当绳子剩下的长度大于或者等于5的时候，我们就把它剪成长度为3或者2的绳子段
//当n >= 5时，3(n - 3) >= 2(n - 2)
int maxProductAfterCutting_solution2(int length)
{
	if (length < 2)
	{
		return 0;
	}
	if (length == 2)
	{
		return 1;
	}
	if (length == 3)
	{
		return 2;
	}

	//尽可能多的剪去长度为3的绳子段
	int timeOf3 = length / 3;

	//当绳子最后剩下的长度为4的时候，不能再剪去长度为3的绳子段
	//此时更好的方法是把绳子段剪成长度为2的两段，因为2 * 2 > 3 * 1
	if (length - timeOf3 * 3 == 1)
	{
		timeOf3 = timeOf3 - 1;
	}

	int timeOf2 = (length - timeOf3 * 3) / 2;

	return (int)(pow(3, timeOf3))*(int)(pow(2, timeOf2));
}

int main()
{

	int n;
	while (cin >> n)
	{
		cout << "动态规划求解：" << maxProductAfterCutting_solution1(n) << endl;
		cout << "贪婪算法求解：" << maxProductAfterCutting_solution2(n) << endl;
	}

	system("pause");
	return 0;
}