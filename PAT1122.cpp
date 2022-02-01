#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1][v2] = adj[v2][v1] = 1;
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int n;
		cin >> n;
		bool f = true;
		vector<bool> v(N + 1, false);
		if (n != N + 1) f = false;
		int cur, b;
		cin >> b;
		cur = b;
		for (int i = 1; i < n; i++)
		{
			int t;
			cin >> t;
			if (v[t]) f = false;
			else
			{
				v[t] = true;
				if (!adj[cur][t]) f = false;
			}
			cur = t;
		}
		if (f) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	system("pause");
	return 0;
}