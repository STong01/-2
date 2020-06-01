#include <iostream>
#include <vector>
#include <string>
using namespace std;

//Hill加密
//str1为明文，L1为加密密钥
string Hill_Encryption(string str1, vector<int> L1)
{
	string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	if (str1.length() <= 1 || L1.size() != 4 || ((L1[0] * L1[3]) - (L1[1] * L1[2]) == 0))
	{
		return 0;
	}

	//定义密文
	string str2;
	int n = str1.length();
	for (int i = 0; i < n - 1; i = i + 2)
	{
		str2 += str[((str1[i] - 'a') * L1[0] + (str1[i + 1] - 'a')* L1[2]) % str.size()];
		str2 += str[((str1[i] - 'a') * L1[1] + (str1[i + 1] - 'a')* L1[3]) % str.size()];
	}

	return str2;
}

//Hill解密
//模26倒数表
int Mod26_Reciprocal(int n)
{
	int det = 0;
	switch (n)
	{
	case 1:det = 1; break;
	case 3:det = 9; break;
	case 5:det = 21; break;
	case 7:det = 15; break;
	case 9:det = 3; break;
	case 11:det = 19; break;
	case 15:det = 7; break;
	case 17:det = 23; break;
	case 19:det = 11; break;
	case 21:det = 5; break;
	case 23:det = 17; break;
	case 25:det = 25; break;
	}
	return det;
}

//求解L1的逆矩阵
vector<int> Inverse_Matrix(vector<int>L1)
{
	vector<int>K1(4, 0);
	if (L1.size() != 4 || ((L1[0] * L1[3]) - (L1[1] * L1[2]) == 0))
	{
		return K1;
	}
	//定义ad - bc的绝对值 mod 26
	int n;
	//定义ad - bc的符号值
	int m;
	if (((L1[0] * L1[3]) - (L1[1] * L1[2])) < 0)
	{
		n = (0 - ((L1[0] * L1[3]) - (L1[1] * L1[2]))) % 26;
		m = -1;
	}
	else
	{
		n = ((L1[0] * L1[3]) - (L1[1] * L1[2])) % 26;
		m = 1;
	}
	int p = Mod26_Reciprocal(n);

	K1[0] = m * L1[3] * p;
	K1[1] = -L1[1] * m * p;
	K1[2] = -L1[2] * m * p;
	K1[3] = L1[0] * m * p;
	return K1;
}

//求解解密密钥K2
vector<int> Key(vector<int>L1)
{
	vector<int> K1 = Inverse_Matrix(L1);
	vector<int>K2(4, 0);
	for (int i = 0; i < 4; i++)
	{
		if (K1[i] < 0)
		{
			K2[i] = (26 + K1[i]) % 26;
		}
		else
		{
			K2[i] = K1[i];
		}
	}
	return K2;
}

//str2为密文，K2为解密密钥，即加密密钥L1的逆矩阵
string Hill_Decrypt(string str2, vector<int>K2)
{
	string stm = "abcdefghijklmnopqrstuvwxyz";
	if (str2.length() <= 1 || K2.size() != 4 || ((K2[0] * K2[3]) - (K2[1] * K2[2]) == 0))
	{
		return 0;
	}

	//定义明文
	string str3;
	int n = str2.length();
	for (int i = 0; i < n - 1; i = i + 2)
	{
		str3 += stm[((str2[i] - 'A') * K2[0] + (str2[i + 1] - 'A')* K2[2]) % stm.size()];
		str3 += stm[((str2[i] - 'A') * K2[1] + (str2[i + 1] - 'A')* K2[3]) % stm.size()];
	}

	return str3;
}

int main()
{
	cout << "请输入Hill明文：";
	string str1;
	cin >> str1;
	cout << "请输入加密密钥L1：";
	vector<int> L1(4, 0);
	cin >> L1[0] >> L1[1] >> L1[2] >> L1[3];

	cout << "加密后的密文为：";
	cout << Hill_Encryption(str1, L1) << endl;
	cout << "解密密钥K2为：";
	vector<int>K(4, 0);
	K = Key(L1);
	cout << K[0] << " " << K[1] << " " << K[2] << " " << K[3] << endl;

	cout << "请输入Hill密文：";
	string str2;
	cin >> str2;
	cout << "请输入解密密钥K2：";
	vector<int> K2(4, 0);
	cin >> K2[0] >> K2[1] >> K2[2] >> K2[3];

	cout << "解密后的明文为：";
	cout << Hill_Decrypt(str2, K2) << endl;

	cout << "验证Hill算法：";
	if (Hill_Decrypt(str2, K2) == str1)
	{
		cout << "true" << endl;
	}
	else
	{
		cout << "fasle" << endl;
	}

	system("pause");
	return 0;
}