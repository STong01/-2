#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n;
	vector<long> tmp = { 1, 1 };
	for (int i = 2; i <= 100001; i++)
	{
		tmp.push_back(0);
		tmp[i] = ((tmp[i - 1] % 1000000) + (tmp[i - 2] % 1000000)) % 1000000;
	}
	while (cin >> n)
	{
		if (n <= 25)  //加上判断，此时的数列值就是100000的分界处
			cout << tmp[n] << endl; //直接输出
		else
			printf("%06ld\n", tmp[n]);//输出后六位
	}

	system("pause");
	return 0;
}