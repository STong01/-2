#include <iostream>
#include <string>
using namespace std;

int main1()
{
	char p;
	while ((p = getchar()) != EOF)
	{
		if ((p >= 'A') && (p <= 'Z'))
		{
			if (p > 'E')
			{
				p = p - 5;
			}
			else
			{
				p = p + 21;
			}
		}
		putchar(p);
	}
	system("pause");
	return 0;

}