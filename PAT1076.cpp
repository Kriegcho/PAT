#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// 本题应使用广搜。一开始用深搜做，两个测试点过不了，原因：
// 如果深搜已找到一个点且符合要求，将其访问标志置为true，若其在其他结点的深搜链中，则其子结点就不能被访问到了。
int N, L;
vector<vector<int>> adj;
//vector<bool> f;
//void DFS(int pos, int d, int& cnt)
//{
//	if (d <= L)
//	{
//		f[pos] = true;
//		if (d > 0) cnt++;
//		for (int i = 0; i < adj[pos].size(); i++)
//		{
//			if (!f[adj[pos][i]]) DFS(adj[pos][i], d + 1, cnt);
//		}
//	}
//}

int main()
{
	cin >> N >> L;
	adj.resize(N + 1);
	for (int i = 1; i <= N; i++)
	{
		int c;
		cin >> c;
		for (int j = 0; j < c; j++)
		{
			int t;
			cin >> t;
			adj[t].push_back(i);
		}
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int t;
		cin >> t;
		//f.assign(N + 1, false);
		//int ans = 0;
		//DFS(t, 0, ans);
		//cout << ans << endl;
		vector<bool> f(N + 1, false);
		vector<int> ans;
		queue<int> q;
		q.push(t);
		for (int i = 0; i < L; i++)
		{
			queue<int> t;
			while (!q.empty())
			{
				f[q.front()] = true;
				for (int j = 0; j < adj[q.front()].size(); j++) if (!f[adj[q.front()][j]])
				{
					t.push(adj[q.front()][j]);
					ans.push_back(adj[q.front()][j]);
					f[adj[q.front()][j]] = true;
				}
				q.pop();
			}
			q = t;
		}
		cout << ans.size() << endl;
	}

	system("pause");
	return 0;
}