#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

vector<int> hap;
vector<string> name;
vector<vector<int>> adj;
vector<bool> v;
map<string, int> m;
int maxh = 0, minc = INT32_MAX, mind = INT32_MAX, N, K, e, cnt = 0;
vector<int> temp, ans;

void DFS(int pos, int h, int c, int dep)
{
	temp.push_back(pos);
	if (pos == e)
	{
		h += hap[e];
		if (c < minc)
		{
			ans = temp;
			minc = c;
			maxh = h;
			mind = dep;
			cnt = 1;
		}
		else if (c == minc)
		{
			cnt++;
			if (h > maxh)
			{
				ans = temp;
				maxh = h;
				mind = dep;
			}
			else if (h == maxh && dep < mind)
			{
				ans = temp;
				mind = dep;
			}
		}
	}
	else
	{
		v[pos] = true;
		for (int i = 0; i < N; i++) if (adj[pos][i] && !v[i]) DFS(i, h + hap[pos], c + adj[pos][i], dep + 1);
		v[pos] = false;
	}
	temp.pop_back();
}

int main()
{
	string beg;
	cin >> N >> K >> beg;
	name.push_back(beg);
	m.insert(make_pair(beg, 0));
	hap.assign(N, 0);
	v.assign(N, false);
	for (int i = 1; i < N; i++)
	{
		string n;
		cin >> n >> hap[i];
		if (n == "ROM") e = i;
		name.push_back(n);
		m.insert(make_pair(n, i));
	}
	adj.assign(N, vector<int>(N, 0));
	for (int i = 0; i < K; i++)
	{
		string s1, s2;
		int c;
		cin >> s1 >> s2 >> c;
		adj[m[s1]][m[s2]] = adj[m[s2]][m[s1]] = c;
	}
	DFS(0, 0, 0, 0);
	int avgh = maxh / mind;
	cout << cnt << " " << minc << " " << maxh << " " << avgh << endl;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i > 0) cout << "->";
		cout << name[ans[i]];
	}

	system("pause");
	return 0;
}