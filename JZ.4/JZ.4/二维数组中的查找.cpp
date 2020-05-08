#include <iostream>
#include <vector>
using namespace std;

bool Find1(vector<int> matrix, int rows, int cols, int number)
{
	bool found = false;

	if (rows > 0 && cols > 0)
	{
		int row = 0;
		int col = cols - 1;
		while (row < rows && col > 0)
		{
			if (matrix[row * cols + col] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row * cols + col] > number)
			{
				--col;
			}
			else
			{
				++row;
			}
		}
	}
	return found;
}

bool Find2(vector<int> matrix, int rows, int cols, int number)
{
	bool found = false;

	if (rows > 0 && cols > 0)
	{
		int row = rows - 1;
		int col = 0;
		while (row >= 0 && col < cols)
		{
			if (matrix[row * cols + col] == number)
			{
				found = true;
				break;
			}
			else if (matrix[row * cols + col] > number)
			{
				--row;
			}
			else
			{
				++col;
			}
		}
	}
	return found;
}

int main()
{
	vector<int> matrix = { 1, 2, 8, 9, 2, 4, 9, 12, 4, 7, 10, 13, 6, 8, 11, 15 };
	
	int n;
	while (cin >> n)
	{
		if (Find2(matrix, 4, 4, n))
		{
			cout << "true" << endl;
		}
		else
		{
			cout << "false" << endl;

		}
	}


	system("pause");
	return 0;
}