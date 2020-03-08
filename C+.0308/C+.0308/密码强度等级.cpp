#include <iostream>
#include <string>
using namespace std;

//ÃÜÂëÇ¿¶ÈµÈ¼¶
//×ÖÄ¸ÅĞ¶Ï
int numChar(string str, int k)
{
	int small = 0;
	int big = 0;
	for (int i = 0; i < k; i++)
	{
		//´óĞ´×ÖÄ¸ÅĞ¶Ï
		if (str[i] >= 65 && str[i] <= 90)
		{
			big++;
		}
		//Ğ¡Ğ´×ÖÄ¸ÅĞ¶Ï
		else if (str[i] >= 97 && str[i] <= 122)
		{
			small++;
		}
	}

	if ((small + big) == 0)
	{
		return 0;
	}
	else if (small == k || big == k)
	{
		return 10;
	}
	else if (small > 0 && big > 0)
	{
		return 20;
	}
	return 0;
}

//Êı×ÖÅĞ¶Ï
int numNumber(string str, int k)
{
	int num = 0;
	for (int i = 0; i < k; i++)
	{
		if (str[i] - '0' >= 0 && str[i] - '0' <= 9)
		{
			num++;
		}
	}
	if (num == 0)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 10;
	}
	else
	{
		return 20;
	}
}

//·ûºÅÅĞ¶Ï
int numSymbal(string str, int k)
{
	int num = 0;
	for (int i = 0; i < k; i++)
	{
		if (!(str[i] >= 65 && str[i] <= 90) &&
			!(str[i] >= 97 && str[i] <= 122) &&
			!(str[i] - '0' >= 0 && str[i] - '0' <= 9))
		{
			num++;
		}
	}

	if (num == 0)
	{
		return 0;
	}
	else if (num == 1)
	{
		return 10;
	}
	else
	{
		return 25;
	}
}

int main()
{
	string str;
	while (cin >> str)
	{
		int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
		int k = str.size();
		if (k <= 4)
		{
			sum1 = 5;
		}
		else if (k >= 8)
		{
			sum1 = 25;
		}
		else
		{
			sum1 = 10;
		}

		sum2 = numChar(str, k);//×ÖÄ¸ÅĞ¶Ï
		sum3 = numNumber(str, k);//Êı×ÖÅĞ¶Ï
		sum4 = numSymbal(str, k);//·ûºÅÅĞ¶Ï

		if ((sum2 > 0) && (sum3 > 0) && (sum4 > 4))
		{
			if (sum2 == 10)
			{
				sum5 = 3;
			}
			else
			{
				sum5 = 5;
			}
		}
		else if (sum2 > 0 && sum3 > 0 && sum4 == 0)
		{
			sum5 = 2;
		}
		if (sum1 + sum2 + sum3 + sum4 + sum5 >= 90)
		{
			cout << "VERY_SECURE" << endl;
		}
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 80)
		{
			cout << "SECURE" << endl;
		}
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 70)
		{
			cout << "VERY_STRONG" << endl;
		}
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 60)
		{
			cout << "STRONG" << endl;
		}
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 50)
		{
			cout << "AVERAGE" << endl;
		}
		else if (sum1 + sum2 + sum3 + sum4 + sum5 >= 25)
		{
			cout << "WEAK" << endl;
		}
		else
		{
			cout << "VERY_WEAK" << endl;
		}
	}
	system("pause");
	return 0;
}