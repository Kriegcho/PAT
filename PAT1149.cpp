#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> ids;
	map<string, int> m;
	vector<vector<bool>> adj(N * 2, vector<bool>(N * 2, false));
	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if (m.find(s1) == m.end())
		{
			m[s1] = ids.size();
			ids.push_back(s1);
		}
		if (m.find(s2) == m.end())
		{
			m[s2] = ids.size();
			ids.push_back(s2);
		}
		adj[m[s1]][m[s2]] = adj[m[s2]][m[s1]] = true;
	}
	for (int i = 0; i < M; i++)
	{
		int K;
		cin >> K;
		vector<string> ck;
		bool f = true;
		for (int j = 0; j < K; j++)
		{
			string s;
			cin >> s;
			if (f && m.find(s) != m.end())
			{
				for (int k = 0; k < ck.size(); k++)
					if (adj[m[s]][m[ck[k]]])
					{
						f = false;
						break;
					}
				ck.push_back(s);
			}
		}
		cout << (f ? "Yes" : "No") << endl;
	}

	system("pause");
	return 0;
}