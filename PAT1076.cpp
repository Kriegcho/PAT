#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;
// 本题应使用广搜。带层数的遍历使用广搜方便很多。
// 深搜改进：不设置访问标志，使用set保存符合要求的结点。然而最后一个测试点超时了。
int N, L;
vector<vector<int>> adj;
// DFS
//set<int> ans;
//void DFS(int pos, int d)
//{
//	if (d <= L)
//	{
//		ans.insert(pos);
//		for (int i = 0; i < adj[pos].size(); i++) DFS(adj[pos][i], d + 1);
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
		// DFS
		//ans.clear();
		//DFS(t, 0);
		//cout << ans.size() - 1 << endl;
		// BFS
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