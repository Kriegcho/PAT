#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int N, M;
vector<int> c(101, 0); // 将面值存成下标+计数
stack<int> ans;
// 思路：类似于DFS的思想，从最小的开始一直尝试将最小值加入栈，若无解则找下一个最小值
// 找到的第一个解肯定是符合题目要求的最小解
void calc(int pos, int s, stack<int>& q, bool& f)
{
	if (pos > 100) return;
	if (s == M && !f)
	{
		f = true;
		while (!q.empty())
		{
			ans.push(q.top());
			q.pop();
		}
		return;
	}
	if (c[pos])
	{
		if (s < M)
		{
			for (int i = pos; i <= M - s; i++)
			{
				if (c[i])
				{
					q.push(i);
					c[i]--;
					calc(i, s + i, q, f);
					if (q.empty()) return; // 因为q倒置成了ans，若此时q空表示已经找到答案了。
					q.pop();
					c[i]++;
				}
			}
		}
	}
	else
	{
		calc(pos + 1, s, q, f);
	}
}

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if (t <= 100) c[t]++;
	}
	stack<int> q;
	bool b = false;
	calc(1, 0, q, b);
	if (b)
	{
		bool f = false;
		while (!ans.empty())
		{
			if (f) cout << " ";
			cout << ans.top();
			ans.pop();
			f = true;
		}
	}
	else cout << "No Solution";

	system("pause");
	return 0;
}