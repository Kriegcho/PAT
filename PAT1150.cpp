#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = adj[b][a] = c;
	}
	set<int> ns;
	for (int i = 1; i <= N; i++) ns.insert(i);
	vector<bool> v(N + 1, false);
	int K, mind = INT32_MAX, ind = 1;
	cin >> K;
	for (int i = 1; i <= K; i++)
	{
		int n;
		cin >> n;
		int nt = (n >= N + 1 ? (n == N + 1 ? 1 : 0) : 2); // 0 TS cycle 1 TS simple cycle 2 Not a TS cycle
		vector<int> q(n);
		set<int> s;
		for (int j = 0; j < n; j++)
		{
			cin >> q[j];
			s.insert(q[j]);
		}
		if (s != ns) nt = 2;
		if (q[0] != q[n - 1]) nt = 2;
		int td = 0;
		for (int j = 1; j < n; j++)
		{
			if (adj[q[j]][q[j - 1]]) td += adj[q[j]][q[j - 1]];
			else
			{
				td = 0;
				nt = 2;
				break;
			}
		}
		if (nt < 2 && td > 0 && td < mind)
		{
			mind = td;
			ind = i;
		}
		if (nt == 2) cout << "Path " << i << ": " << (td == 0 ? "NA" : to_string(td)) << " (Not a TS cycle)" << endl;
		else if (nt == 1) cout << "Path " << i << ": " << td << " (TS simple cycle)" << endl;
		else if (nt == 0) cout << "Path " << i << ": " << td << " (TS cycle)" << endl;
	}
	cout << "Shortest Dist(" << ind << ") = " << mind << endl;

	system("pause");
	return 0;
}