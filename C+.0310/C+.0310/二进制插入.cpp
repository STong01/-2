#include <iostream>
using namespace std;

//二进制插入
class insert
{
public:
	int C_insert(int n, int m, int j, int i)
	{
		m <<= j;
		return n | m;
	}
};

int main1()
{
	int m = 1024;
	int n = 19;
	int j = 2;
	int i = 6;
	insert test;
	int p = test.C_insert(m, n, j, i);
	cout << p << endl;
	system("pause");
	return 0;
}