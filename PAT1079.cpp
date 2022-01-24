#include <iostream>
#include <vector>
using namespace std;

vector<int> f;
vector<bool> v;
vector<vector<int>> adj;
void DFS(int pos, double p, double r, double& ans)
{
	v[pos] = true;
	if (f[pos])
	{
		ans += p * f[pos];
		f[pos] = 0;
	}
	for (int i = 0; i < adj[pos].size(); i++) if (!v[adj[pos][i]]) DFS(adj[pos][i], p * (1 + 1.0 * r / 100), r, ans);
}

int main()
{
	int N;
	double P, r;
	cin >> N >> P >> r;
	adj.resize(N);
	f.assign(N, 0); // 零售货物量
	v.assign(N, false); // 访问标志
	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;
		if (K > 0)
		{
			for (int j = 0; j < K; j++)
			{
				int t;
				cin >> t;
				adj[i].push_back(t);
			}
		}
		else
		{
			int t;
			cin >> t;
			f[i] = t;
		}
	}
	double ans = 0;
	DFS(0, P, r, ans);
	printf("%.1f", ans);

	system("pause");
	return 0;
}