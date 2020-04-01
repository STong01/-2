#include <iostream>
#include <string>
using namespace std;

int son(string str1, string str2)
{
	int len1 = str1.size();
	int len2 = str2.size();
	int count = 0;

	for (int i = 0; i < len1; i++)
	{
		for (int j = 0; j < len2; j++)
		{
			if (str1[i] == str2[j])
			{
				i++;
			}
			else
			{
				break;
			}

			if (j == len2 - 1)
			{
				if (len2 == 1)
				{
					i--;
				}
				count++;
				i = i - j;
			}
		}
	}
	return count;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << son(s1,s2)<<endl;
	}

	system("pause");
	return 0;
}