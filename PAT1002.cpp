#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

int main()
{
	int n1, n2;
	int a;
	double b;
	stack<int> stk1, stk2, stkAns;
	stack<double> exp1, exp2, expAns;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{	
		cin >> a;
		cin >> b;
		if (b != 0)
		{
			stk1.push(a);
			exp1.push(b);
		}
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		cin >> a;
		cin >> b;
		if (b != 0)
		{
			stk2.push(a);
			exp2.push(b);
		}
	}
	while (!stk1.empty() || !stk2.empty())
	{
		if (!stk1.empty() && !stk2.empty())
		{
			if (stk1.top() < stk2.top())
			{
				stkAns.push(stk1.top());
				stk1.pop();
				expAns.push(exp1.top());
				exp1.pop();
			}
			else if (stk1.top() > stk2.top())
			{
				stkAns.push(stk2.top());
				stk2.pop();
				expAns.push(exp2.top());
				exp2.pop();
			}
			else
			{
				if ((exp1.top() + exp2.top()) != 0)
				{
					stkAns.push(stk1.top());
					expAns.push(exp1.top() + exp2.top());
				}
				stk1.pop();
				stk2.pop();
				exp1.pop();
				exp2.pop();
			}
		}
		else if (stk1.empty())
		{
			stkAns.push(stk2.top());
			stk2.pop();
			expAns.push(exp2.top());
			exp2.pop();
		}
		else
		{
			stkAns.push(stk1.top());
			stk1.pop();
			expAns.push(exp1.top());
			exp1.pop();
		}
	}
	cout << stkAns.size();
	while (!stkAns.empty())
	{
		// 使用printf便于设置小数输出
		printf(" %d %.1f", stkAns.top(), expAns.top());
		stkAns.pop();
		expAns.pop();
	}
	system("pause");
	return 0;
}