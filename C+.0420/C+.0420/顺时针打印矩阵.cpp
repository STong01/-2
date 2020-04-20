#include <iostream>
#include <vector>
using namespace std;

class Printer 
{
public:
	vector<int> clockwisePrint(vector<vector<int> > mat, int n, int m) 
	{
		vector<int> tmp;
		int num = 1;
		int i = 0;
		int j = 0;
		tmp.push_back(mat[0][0]);
		mat[0][0] = NULL;
		while (num != n * m)
		{
			while (j + 1 < m && mat[i][j + 1] != NULL)
			{
				tmp.push_back(mat[i][j + 1]);
				num++;
				mat[i][j + 1] = NULL;
				j = j + 1;
			}
			while (i + 1 < n && mat[i + 1][j] != NULL)
			{
				tmp.push_back(mat[i + 1][j]);
				num++;
				mat[i + 1][j] = NULL;
				i = i + 1;
			}
			while (j - 1 >= 0 && mat[i][j - 1] != NULL)
			{
				tmp.push_back(mat[i][j - 1]);
				num++;
				mat[i][j - 1] = NULL;
				j = j - 1;
			}
			while (i - 1 < m && mat[i - 1][j] != NULL)
			{
				tmp.push_back(mat[i - 1][j]);
				num++;
				mat[i - 1][j] = NULL;
				i = i - 1;
			}
		}
		return tmp;
	}
};

int main()
{
	Printer test;
	vector<vector<int> > mat = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
	vector<int> cur = test.clockwisePrint(mat, 4, 4);
	for (int i = 0; i < 16; i++)
	{
		cout << cur[i] << ' ';
	}

	system("pause");
	return 0;
}