#include <iostream>
using namespace std;

void SortAges(int ages[], int length)
{
	if (ages == nullptr || length <= 0)
	{
		return;
	}
	const int oldestAge = 99;
	int timeOfAge[oldestAge + 1];

	for (int i = 0; i <= oldestAge; ++i)
	{
		timeOfAge[i] = 0;
	}

	for (int i = 0; i < length; i++)
	{
		int age = ages[i];
		if (age<0 || age>oldestAge)
		{
			throw new std::exception("age out of range");
		}

		++timeOfAge[age];
	}

	int index = 0;
	for (int i = 0; i <= oldestAge; ++i)
	{
		for (int j = 0; j < timeOfAge[i]; ++j)
		{
			ages[index] = i;
			++index;
		}
	}
}

int main()
{

	int ages[] = { 12, 13, 46, 43, 12, 23, 56, 87, 66, 55, 98, 67 };
	SortAges(ages, 12);
	for (int i = 0; i < 12; i++)
	{
		cout << ages[i] << " ";
	}
	cout << endl;

	system("pause");
	return 0;
}