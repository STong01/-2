//#include <iostream>
//#include <string>
//using namespace std;
//
//string FindNum(string str)
//{
//	string s;
//	for (int i = 0; i < str.size(); i++)
//	{
//		if ((str[i] >= '0') && (str[i] <= '9'))
//		{
//			s += str[i];
//		}
//	}
//	return s;
//}
//
//int main()
//{
//	string str;
//	while (getline(cin , str))
//	{
//		cout << FindNum(str) << endl;
//	}
//	system("pause");
//	return 0;
//}
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

int main()
{
	string temp;
	while (getline(cin, temp))
	{
		string res;
		int j = 0;
		for (int i = 0; i < temp.size(); i++)
		{
			if ((temp[i] >= '0') && (temp[i] <= '9'))
			{
				//res.push_back(temp[i]);
				res+= temp[i];
				//j++;
			}
		}
		//atoi(res.c_str());
		cout << res << endl;
	}
	system("pause");
	return 0;
}