#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
	int M, N, K;
	cin >> M >> N >> K;
	for (int i = 0; i < K; i++)
	{
		vector<bool> f(N + 1, false); // 入栈过的标志
		stack<int> s; // 栈。栈中元素一定是递增的
		s.push(0);
		bool b = false;
		int cur = 0; // 已入栈的最大数
		for (int j = 0; j < N; j++)
		{
			int t;
			cin >> t;
			if (f[t])
			{
				if (t == s.top())
				{
					s.pop();
				}
				else b = true; // 不能break，要把输入走完
			}
			else
			{
				for (int k = cur + 1; k <= t; k++)
				{
					if (!f[k])
					{
						s.push(k);
						f[k] = true;
						if (s.size() > M + 1) b = true;
					}
				}
				s.pop();
			}
			f[t] = true;
			if (cur < t) cur = t;
		}
		if (b) cout << "NO" << endl;
		else cout << "YES" << endl;
	}

	system("pause");
	return 0;
}