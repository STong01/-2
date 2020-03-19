#include <iostream>
#include <string>
using namespace std;

//×Ö·û´®·´×ª
string rever(string str)
{
	if (str.empty())
	{
		return str;
	}

	size_t start = 0;
	size_t end = str.size() - 1;
	while (start < end)
	{
		swap(str[start], str[end]);
		start++;
		end--;
	}
	return str;
}

int main1()
{
	string s;
	while (cin >> s)
	{
		cout << rever(s) << endl;
	}
	system("pause");
	return 0;
}