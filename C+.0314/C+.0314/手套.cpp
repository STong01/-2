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
		//遍历每一种颜色的左右手套序列
		for (int i = 0; i < n; i++)
		{
			//对于有0存在的颜色手套，累加
			if (left[i] * right[i] == 0)
			{
				sum += left[i] + right[i];
			}
			//对于左右手套都有的，执行累加-最小值+1
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