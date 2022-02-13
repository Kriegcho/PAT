#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int Nv, Ne, K;
	cin >> Nv >> Ne;
	vector<vector<int>> adj(Nv + 1, vector<int>(Nv + 1, 0));
	for (int i = 0; i < Ne; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		adj[a][b] = adj[b][a] = c;
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int s, t;
		cin >> s;
		bool f = true;
		vector<int> dis(Nv + 1, 0), temp(Nv + 1, 0);
		int mind = INT32_MAX, ind = 1;
		for (int j = 1; j <= Nv; j++)
			if (adj[s][j])
			{
				temp[j] = adj[s][j];
				if (adj[s][j] < mind)
				{
					mind = adj[s][j];
					ind = j;
				}
			}
		for (int j = 1; j < Nv; j++)
		{
			cin >> t;
			if (f)
			{
				if (temp[t] && temp[t] == mind)
				{
					dis[t] = mind;
					mind = INT32_MAX;
					for (int k = 1; k <= Nv; k++)
					{
						if (!dis[k] && k != s)
						{
							if (adj[t][k])
							{
								if (!temp[k]) temp[k] = dis[t] + adj[t][k];
								else if (dis[t] + adj[t][k] < temp[k]) temp[k] = dis[t] + adj[t][k];
							}
							if (temp[k] && temp[k] < mind) mind = temp[k];
						}
					}
				}
				else f = false;
			}
		}
		cout << (f ? "Yes" : "No") << endl;
	}

	system("pause");
	return 0;
}