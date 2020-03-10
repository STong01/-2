#include <iostream>
using namespace std;

//最近公共祖先
class LCA
{
public:
	int getMax(int a, int b)
	{
		while (a != b)
		{
			if (a > b)
			{
				a = a >> 1;
			}
			else
			{
				b = b >> 1;
			}
		}
		return a;
	}
};

int main1()
{

	system("pause");
	return 0;
}