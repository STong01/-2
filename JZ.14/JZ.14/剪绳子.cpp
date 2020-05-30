#include <iostream>
using namespace std;

//��̬�滮
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

//̰���㷨
//��n >= 5��ʱ�����ǿ���֤��2(n - 2) > n����3(n - 3) > n
//���ԣ�������ʣ�µĳ��ȴ��ڻ��ߵ���5��ʱ�����ǾͰ������ɳ���Ϊ3����2�����Ӷ�
//��n >= 5ʱ��3(n - 3) >= 2(n - 2)
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

	//�����ܶ�ļ�ȥ����Ϊ3�����Ӷ�
	int timeOf3 = length / 3;

	//���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�����Ӷ�
	//��ʱ���õķ����ǰ����Ӷμ��ɳ���Ϊ2�����Σ���Ϊ2 * 2 > 3 * 1
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
		cout << "��̬�滮��⣺" << maxProductAfterCutting_solution1(n) << endl;
		cout << "̰���㷨��⣺" << maxProductAfterCutting_solution2(n) << endl;
	}

	system("pause");
	return 0;
}