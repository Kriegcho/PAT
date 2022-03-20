#include <iostream>
#include <vector>
using namespace std;

int N, M, C1, C2;
int ansc = 0, maxr = 0, minl = INT32_MAX;
void DFS(int pos, int len, int r, const vector<int>& rc, const vector<vector<int>>& adj, vector<bool>& v)
{
	v[pos] = true;
	if (pos == C2)
	{
		if (len < minl)
		{
			minl = len;
			ansc = 1;
			maxr = r;
		}
		else if (len == minl)
		{
			ansc++;
			if (maxr < r) maxr = r;
		}
	}
	else for (int i = 0; i < N; i++)
	{
		if (adj[pos][i] && !v[i]) DFS(i, len + adj[pos][i], r + rc[i], rc, adj, v);
	}
	v[pos] = false;
}

int main()
{
	cin >> N >> M >> C1 >> C2;
	vector<int> rc(N);
	vector<vector<int>> adj(N, vector<int>(N, 0));
	vector<bool> v(N, false);
	for (int i = 0; i < N; i++) cin >> rc[i];
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = adj[b][a] = c;
	}
	DFS(C1, 0, rc[C1], rc, adj, v);
	cout << ansc << " " << maxr;
	system("pause");
}