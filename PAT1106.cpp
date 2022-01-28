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
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		adj[i].resize(t);
		for (int j = 0; j < t; j++) cin >> adj[i][j];
	}
	queue<int> q;
	q.push(0);
	int ans = 0;
	while (1)
	{
		queue<int> t;
		bool f = false;
		while (!q.empty())
		{
			if (adj[q.front()].empty())
			{
				f = true;
				ans = 1;
				break;
			}
			for (int i = 0; i < adj[q.front()].size(); i++)
			{
				t.push(adj[q.front()][i]);
				if (adj[adj[q.front()][i]].empty())
				{
					f = true;
					ans++;
				}
			}
			q.pop();
		}
		if (t.empty()) break;
		p *= (1 + r / 100);
		if (f) break;
		q = t;
	}
	printf("%.4f %d", p, ans);

	system("pause");
	return 0;
}