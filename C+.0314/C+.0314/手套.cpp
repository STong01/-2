#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class gloves
{
public:
	int findnum(int n, vector<int> left, vector<int> right)
	{
		int left_num = 0;
		int left_min = INT_MAX;
		int right_num = 0;
		int right_min = INT_MAX;
		int sum = 0;
		//����ÿһ����ɫ��������������
		for (int i = 0; i < n; i++)
		{
			//������0���ڵ���ɫ���ף��ۼ�
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}
			//�����������׶��еģ�ִ���ۼ�-��Сֵ+1
			else
			{
				left_num += left[i];
				right_num += right[i];
				left_min = min(left_min, left[i]);
				right_min = min(right_min, right[i]);
			}
		}
		return sum + min(left_num - left_min + 1, right_num - right_min + 1) + 1;
	}
};

int main()
{

	system("pause");
	return 0;
}