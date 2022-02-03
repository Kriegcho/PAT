#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int nv, ne;
	cin >> nv >> ne;
	vector<vector<int>> adjm(nv + 1, vector<int>(nv + 1, 0));
	vector<vector<int>> adj(nv + 1);
	for (int i = 0; i < ne; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		adjm[v1][v2] = adjm[v2][v1] = 1;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int K;
		cin >> K;
		map<int, bool> mv;
		int fv;
		cin >> fv;
		mv[fv] = true;
		for (int j = 0; j < adj[fv].size(); j++) mv.insert(make_pair(adj[fv][j], false)); // 这里的map必包括Maximal集合
		int type = 1; // 1 Yes 2 Not Maximal 3 Not a Clique
		for (int j = 1; j < K; j++)
		{
			int t;
			cin >> t;
			if (mv.find(t) == mv.end()) type = 3;
			else if (type < 3)
			{
				mv[t] = true;
				map<int, bool>::iterator it = mv.begin();
				while (it != mv.end())
				{
					if (j == 1) // 两个点可以确认Maximal
					{
						if (it->first != t && !adjm[it->first][t]) it = mv.erase(it);
						else it++;
					}
					else if (it->first != t && !adjm[it->first][t])
					{
						type = 3;
						break;
					}
					else it++;
				}
			}
		}
		if (type < 3)
		{
			map<int, bool>::iterator it = mv.begin();
			while (it != mv.end())
			{
				if (!it->second)
				{
					type = 2;
					break;
				}
				it++;
			}
		}
		if (type == 1) cout << "Yes" << endl;
		else if (type == 2) cout << "Not Maximal" << endl;
		else if (type == 3) cout << "Not a Clique" << endl;
	}

	system("pause");
	return 0;
}