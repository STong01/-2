#include <iostream>
#include <vector>
using namespace std;

//ʵ��Ҫô����λ�϶���������Ҫôż��λ�϶���ż��
class Solution
{
	void test(vector<int> & arr, int len)
	{
		int i = 0;
		int j = 1;
		while (i < len && j < len)
		{
			if ((arr[j] % 2 != 0))
			{
				j += 2;
				continue;
			}
			if ((arr[i] % 2 == 0))
			{
				i += 2;
				continue;
			}
			swap(arr[i], arr[j]);
		}

	}
};

int main3()
{

	system("pause");
	return 0;
}