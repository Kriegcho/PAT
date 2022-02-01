#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> deg(N + 1, 0);
	vector<vector<int>> adj(N + 1, vector<int>(N + 1));
	for (int i = 0; i < M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		deg[v1]++;
		deg[v2]++;
		adj[v1][v2] = adj[v2][v1] = 1;
	}
	bool f = true;
	int gc = 0, ec = 0;
	vector<bool> v(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		if (!v[i])
		{
			gc++;
			if (gc > 1) break;
			queue<int> q;
			q.push(i);
			v[i] = true;
			while (!q.empty())
			{
				for (int j = 1; j <= N; j++)
					if (adj[q.front()][j] && !v[j])
					{
						v[j] = true;
						q.push(j);
					}
				q.pop();
			}
		}
	}
	if (gc != 1) f = false;
	for (int i = 1; i <= N; i++)
	{
		if (i > 1) cout << " ";
		cout << deg[i];
		if (deg[i] % 2) ec++;
	}
	cout << endl;
	if (f)
	{
		if (ec == 0) cout << "Eulerian";
		else if (ec == 2) cout << "Semi-Eulerian";
		else cout << "Non-Eulerian";
	}
	else cout << "Non-Eulerian";

	system("pause");
	return 0;
}