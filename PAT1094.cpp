#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj(N + 1);
	for (int i = 0; i < M; i++)
	{
		int id, K;
		cin >> id >> K;
		adj[id].resize(K);
		for (int j = 0; j < K; j++) cin >> adj[id][j];
	}
	int ans = 1, ansd = 1, dep = 1;
	queue<int> q;
	q.push(1);
	vector<bool> v(N + 1, false);
	v[1] = true;
	while (1)
	{
		queue<int> t;
		while (!q.empty())
		{
			for (int i = 0; i < adj[q.front()].size(); i++)
				if (!v[adj[q.front()][i]])
				{
					t.push(adj[q.front()][i]);
					v[adj[q.front()][i]] = true;
				}
			q.pop();
		}
		if (t.empty()) break;
		dep++;
		if (t.size() > ans)
		{
			ans = t.size();
			ansd = dep;
		}
		q = t;
	}
	cout << ans << " " << ansd;

	system("pause");
	return 0;
}