#include <iostream>
using namespace std;

class Solution
{
public:
	int Add(int num1, int num2)
	{
		int sum = 0;
		int carry = 0;
		while (num2 != 0)
		{
			//���㲻�����λ��ʱ���ֵ
			sum = num1^num2;
			//��������еĽ�λ
			carry = (num1 & num2) << 1;
			num1 = sum;
			num2 = carry;
		}
		return num1;
	}
};

int main1()
{
	int num1, num2;
	Solution a;
	while (cin >> num1 >> num2)
	{
		cout << a.Add(num1, num2) << endl;
	}
	system("pause");
	return 0;
}