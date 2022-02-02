#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <set>
using namespace std;

struct road
{
	road(int nb, int ne, int nl) { b = nb; e = ne; l = nl; }
	int b, e, l;
};
map<string, int> ms;
vector<string> sn; // 站名
vector<vector<road*>> adj(10001);
vector<road*> ans, temp;
vector<bool> v(10001, false), trans(10001, false);
int mind = INT32_MAX, minc = INT32_MAX;
void DFS(int pos, int e, int dep, int l, int tc)
{
	if (pos == e)
	{
		if (dep < mind)
		{
			ans = temp;
			mind = dep;
			minc = tc;
			return;
		}
		else if (dep == mind && tc < minc)
		{
			ans = temp;
			minc = tc;
			return;
		}
	}
	else
	{
		v[pos] = true;
		for (int i = 0; i < adj[pos].size(); i++)
		{
			if (!v[adj[pos][i]->e])
			{
				temp.push_back(adj[pos][i]);
				DFS(adj[pos][i]->e, e, dep + 1, adj[pos][i]->l, l == 0 || l == adj[pos][i]->l ? tc : tc + 1);
				temp.pop_back();
			}
		}
		v[pos] = false;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		int M;
		cin >> M;
		string cur;
		for (int j = 0; j < M; j++)
		{
			string t;
			cin >> t;
			if (ms.find(t) == ms.end())
			{
				ms[t] = sn.size();
				sn.push_back(t);
			}
			else trans[ms[t]] = true;
			if (j > 0)
			{
				road* p = new road(ms[cur], ms[t], i);
				road* q = new road(ms[t], ms[cur], i);
				adj[ms[t]].push_back(q);
				adj[ms[cur]].push_back(p);
			}
			cur = t;
		}
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		mind = INT32_MAX, minc = INT32_MAX;
		string b, e;
		cin >> b >> e;
		DFS(ms[b], ms[e], 0, 0, 0);
		cout << ans.size() << endl;
		string curs = sn[ms[b]];
		int curl = ans[0]->l;
		for (int i = 1; i < ans.size(); i++)
		{
			if (ans[i]->l != curl)
			{
				cout << "Take Line#" << curl << " from " << curs << " to " << sn[ans[i]->b] << "." << endl; // 换乘线路
				curs = sn[ans[i]->b];
				curl = ans[i]->l;
			}
		}
		cout << "Take Line#" << curl << " from " << curs << " to " << sn[ans[ans.size() - 1]->e] << "." << endl; // 最后一条线路
	}

	system("pause");
	return 0;
}