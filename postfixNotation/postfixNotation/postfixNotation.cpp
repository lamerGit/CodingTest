#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>

using namespace std;

//후위 표기식

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	string s;
	stack<char> op;
	cin >> s;

	for (auto i : s)
	{
		if (i >= 'A' && i <= 'Z')
		{
			cout << i;
		}
		else
		{
			if (i == '(')
			{
				op.push(i);
			}
			else if (i == '*' || i == '/')
			{
				while (!op.empty() && (op.top() == '*' || op.top() == '/'))
				{
					cout << op.top();
					op.pop();
				}
				op.push(i);
			}
			else if (i == '+' || i == '-')
			{
				while (!op.empty() && op.top() != '(')
				{
					cout << op.top();
					op.pop();
				}
				op.push(i);
			}
			else if (i == ')')
			{
				while (!op.empty() && op.top() != '(')
				{
					cout << op.top();
					op.pop();
				}
				op.pop();
			}
		}

	}
	while (!op.empty())
	{
		cout << op.top();
		op.pop();
	}


}