#include <iostream>
#include <vector>
using namespace std;

//����֮·
//�������������Լ��
int GCD(int n, int m)
{
	int num;
	while (num = n % m)
	{
		n = m;
		m = num;
	}
	return m;
}

int main1()
{
	//nΪ������Ŀ��powerΪÿ�����޵�����ֵ
	int n, power;
	vector<int>nums;

	while (cin >> n >> power)
	{
		nums.resize(n);
		for (int i = 0; i < n; i++)
		{
			cin >> nums[i];
		}
		
		for (int j = 0; j < n; j++)
		{
			//�����޵�����ֵС����ҵ�����ֵ������Ҵ�ܹ��ޣ���ȡ���޵�ȫ������ֵ
			if (nums[j] < power)
			{
				power += nums[j];
			}
			//�����޵�����ֵ���ڻ��ߵ�����ҵ�����ֵ������Ҵ�ܹ��ޣ���ȡ��Լ��������ֵ
			else
			{
				power += GCD(power, nums[j]);
			}
		}
		cout << power << endl;
	}
	system("pause");
	return 0;
}