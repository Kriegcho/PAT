#include <iostream>
#include <vector>
#include <set>
using namespace std;

void DFS(int pos, const vector<vector<int>>& adj, const set<int>& sus, vector<bool>& f, set<int>& gang)
{
	f[pos] = true;
	gang.insert(pos);
	for (int i = 1; i < adj.size(); i++)
		if (sus.find(i) != sus.end() && !f[i] && adj[pos][i] && adj[i][pos])
			DFS(i, adj, sus, f, gang);
}

int main()
{
	int K, N, M;
	cin >> K >> N >> M;
	vector<vector<int>> adj(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] += c;
	}
	set<int> sus;
	vector<bool> f(N + 1, false);
	for (int i = 1; i <= N; i++)
	{
		int c = 0, rc = 0;
		vector<int> rec;
		for (int j = 1; j <= N; j++)
		{
			if (adj[i][j] && adj[i][j] <= 5)
			{
				c++;
				rec.push_back(j);
			}
		}
		for (int j = 0; j < rec.size(); j++)
		{
			if (adj[rec[j]][i]) rc++;
		}
		if (c > K && rc * 5 <= c) sus.insert(i);
	}
	vector<set<int>> ans;
	for (set<int>::iterator it = sus.begin(); it != sus.end(); it++)
	{
		if (!f[*it])
		{
			set<int> gang;
			DFS(*it, adj, sus, f, gang);
			ans.push_back(gang);
		}
	}
	if (ans.empty()) cout << "None";
	for (int i = 0; i < ans.size(); i++)
	{
		set<int>::iterator it = ans[i].begin();
		while (it != ans[i].end())
		{
			if (it != ans[i].begin()) cout << " ";
			cout << *it;
			it++;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}