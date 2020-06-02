#include <iostream>
#include <vector>
#include <string>
using namespace std;

string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string stm = "abcdefghijklmnopqrstuvwxyz";

//Hill����
//str1Ϊ���ģ�L1Ϊ������Կ
string Hill_Encryption(string str1, vector<int> L1)
{
	if (str1.length() <= 1 || ((L1[0] * L1[3]) - (L1[1] * L1[2]) == 0) || L1.size() != 4)
	{
		return 0;
	}

	//��������
	string str2;
	int n = str1.length();
	for (int i = 0; i < n - 1; i = i + 2)
	{
		str2 += str[((str1[i] - 'a') * L1[0] + (str1[i + 1] - 'a')* L1[2]) % 26];
		str2 += str[((str1[i] - 'a') * L1[1] + (str1[i + 1] - 'a')* L1[3]) % 26];
	}

	return str2;
}

//Hill����

//���L1�������
vector<int> Inverse_Matrix(vector<int>L1)
{
	vector<int>K2(4, 0);
	if (L1.size() != 4 || ((L1[0] * L1[3]) - (L1[1] * L1[2]) == 0))
	{
		return K2;
	}

	K2[0] = (L1[3] / ((L1[0] * L1[3]) - (L1[1] * L1[2])));
	K2[1] = 0 - (L1[1] / ((L1[0] * L1[3]) - (L1[1] * L1[2])));
	K2[2] = 0 - (L1[2] / ((L1[0] * L1[3]) - (L1[1] * L1[2])));
	K2[3] = (L1[0] / ((L1[0] * L1[3]) - (L1[1] * L1[2])));
	return K2;
}

//str2Ϊ���ģ�K2Ϊ������Կ����������ԿL1�������

string Hill_Decrypt(string str2, vector<int>K2)
{
	if (str2.length() <= 1 || ((K2[0] * K2[3]) - (K2[1] * K2[2]) == 0) || K2.size() != 4)
	{
		return 0;
	}

	//��������
	string str3;
	int n = str2.length();
	for (int i = 0; i < n - 1; i = i + 2)
	{
		str3 += stm[((str2[i] - 'A') * K2[0] + (str2[i + 1] - 'A')* K2[2]) % 26];
		str3 += stm[((str2[i] - 'A') * K2[1] + (str2[i + 1] - 'A')* K2[3]) % 26];
	}

	return str3;
}

int main()
{
	//cout << "������Hill���ģ�";
	//string str1;
	//cin >> str1;
	//cout << "�����������ԿL1��";
	//vector<int> L1(4, 0);
	//cin >> L1[0] >> L1[1] >> L1[2] >> L1[3];

	//cout << "���ܺ������Ϊ��";
	//cout << Hill_Encryption(str1, L1) << endl;
	//cout << "������ԿK2Ϊ��";
	//vector<int>K(4, 0);
	//K = Inverse_Matrix(L1);
	//cout << K[0] << " " << K[1] << " " << K[2] << " " << K[3] << endl;

	cout << "������Hill���ģ�";
	string str2;
	cin >> str2;
	cout << "�����������ԿK2��";
	vector<int> K2(4, 0);
	cin >> K2[0] >> K2[1] >> K2[2] >> K2[3];

	cout << "���ܺ������Ϊ��";
	cout << Hill_Decrypt(str2, K2) << endl;

	//cout << "��֤Hill�㷨��";
	//if (Hill_Decrypt(str2, K2) == str1)
	//{
	//	cout << "true" << endl;
	//}
	//else
	//{
	//	cout << "fasle" << endl;
	//}



	system("pause");
	return 0;
}