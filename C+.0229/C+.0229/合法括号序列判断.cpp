#include <iostream>
#include <stack>
using namespace std;

class Parenthesis 
{
public:
	bool chkParenthesis(string A, int n) 
	{
		stack<char> sc;
		for (auto e : A)
		{
			switch (e)
			{
			case '(':
				sc.push(e);
				break;
			case ')':
			{
						if (sc.empty() || sc.top() != '(')
						{
							return false;
						}
						else
						{
							sc.pop();
						}
			}
				break;
			default:
				return false;
			}
		}
		return true;
	}
};

int main()
{
	string A = "(())()";
	int n = 6;
	Parenthesis STR;
	cout << STR.chkParenthesis(A, n) << endl;

	system("pause");
	return 0;
}