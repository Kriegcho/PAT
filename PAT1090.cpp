#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N;
	double p, r;
	cin >> N >> p >> r;
	vector<vector<int>> adj(N);
	int root;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if (t == -1) root = i;
		else adj[t].push_back(i);
	}
	queue<int> q;
	q.push(root);
	int ans = 0;
	while (1) // BFS
	{
		queue<int> t;
		while (!q.empty())
		{
			for (int j = 0; j < adj[q.front()].size(); j++)
			{
				t.push(adj[q.front()][j]);
			}
			q.pop();
		}
		if (t.empty()) break;
		q = t;
		ans = q.size();
		p *= (1 + 1.0 * r / 100);
	}
	if (N == 1) ans = 1; // 测试点3。。。
	printf("%.2f %d", p, ans);

	system("pause");
	return 0;
}