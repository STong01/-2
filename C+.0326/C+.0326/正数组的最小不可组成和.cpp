#include <iostream>
#include <vector>
using namespace std;

class solution
{
public:
	int getminsum(vector<int>& arr, int length)
	{
		int max = 0;
		int min = arr[0];
		//ȷ������жϷ�Χֵ
		for (int i = 0; i < length; i++)
		{
			max += arr[i];
			min = arr[i] < min ? arr[i] : min;
		}

		vector<int> p(max + 1, 0);
		for (int i = 0; i < length; i++)
		{
			for (int j = max; j >= arr[i]; j--)
			{
				//dp[j-arr[i]]��˼�Ǳ�������Ϊjʱ������Ѿ�������arr[i]���������ܷ��õ��������
				//��ÿ�����ؼ��㵱ǰ����ܷ�������
				if (p[j] < p[j - arr[i]] + arr[i])
				{
					//���±������ܹ���������ֵ
					p[j] = p[j - arr[i]] + arr[i];
				}
				else
				{
					p[j] = p[j];
				}
			}
		}
		for (int i = min; i <= max; i++)
		{
			if (i != p[i])
			{
				return i;
			}
		}
		return max + 1;
	}
};

int main1()
{
	int n;
	while (cin >> n)
	{
		vector<int> a(n);
		for (int i = 0; i < n; ++i)
		{
			cin >> a[i];
		}
		solution s;
		cout << s.getminsum(a, n) << endl;
	}
	system("pause");
	return 0;
}