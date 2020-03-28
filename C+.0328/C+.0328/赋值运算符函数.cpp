#include <iostream>
#include <string>
using namespace std;

//¸³ÖµÔËËã·ûº¯Êý
class MyString
{
public:

	MyString(char*pData = nullptr);

	MyString(const MyString&str);

	~MyString(void);

private:
	char* m_pData;
};

//1
//MyString& MyString::operator=(const MyString &str)
//{
//	if (this == &str)
//	{
//		return *this;
//	}
//
//	delete[]m_pData;
//	m_pData = nullptr;
//
//	m_pData = new char[strlen(str.m_pData) + 1];
//	strcpy(m_pData, str.m_pData);
//
//	return *this;
//}

//2
MyString& MyString::operator=(const MyString &str)
{
	if (this != &str)
	{
		MyString strTemp(str);
		
		char* pTemp = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pTemp;
	}

	return *this;
}



int main()
{

	system("pause");
	return 0;
}