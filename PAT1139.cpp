#include <iostream>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <set>
#include <string>
using namespace std;

bool cmp(string n1, string n2) { return abs(stoi(n1)) < abs(stoi(n2)); }
bool samegender(string s1, string s2)
{
	if ((s1[0] == '-' && s2[0] == '-') || (s1[0] != '-'&&s2[0] != '-')) return true;
	return false;
}
string getabs(string s)
{
	if (s[0] == '-') return s.substr(1);
	else return s;
}
int main()
{
	int N, M;
	cin >> N >> M;
	vector<string> ids;
	vector<vector<string>> adj(N);
	set<pair<string, string>> s;
	map<string, int> m;
	for (int i = 0; i < M; i++)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (m.find(t1) == m.end())
		{
			m[t1] = ids.size();
			ids.push_back(t1);
		}
		if (m.find(t2) == m.end())
		{
			m[t2] = ids.size();
			ids.push_back(t2);
		}
		adj[m[t1]].push_back(t2);
		adj[m[t2]].push_back(t1);
		s.insert(make_pair(t1, t2));
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		string t1, t2;
		cin >> t1 >> t2;
		if (m.find(t1) == m.end() || m.find(t2) == m.end()) cout << "0" << endl;
		else
		{
			vector<pair<string, string>> ans;
			vector<string> v1, v2;
			for (int j = 0; j < adj[m[t1]].size(); j++)
				if (samegender(t1, adj[m[t1]][j]) && adj[m[t1]][j] != t2) v1.push_back(adj[m[t1]][j]); // adj[m[t1]][j] != t2 去掉直接关系
			for (int j = 0; j < adj[m[t2]].size(); j++)
				if (samegender(t2, adj[m[t2]][j]) && adj[m[t2]][j] != t1) v2.push_back(adj[m[t2]][j]);
			sort(v1.begin(), v1.end(), cmp);
			sort(v2.begin(), v2.end(), cmp);
			for (int j = 0; j < v1.size(); j++)
				for (int k = 0; k < v2.size(); k++)
					if (s.find(make_pair(v1[j], v2[k])) != s.end() || s.find(make_pair(v2[k], v1[j])) != s.end())
						ans.push_back(make_pair(v1[j], v2[k]));
			cout << ans.size() << endl;
			for (int i = 0; i < ans.size(); i++) cout << getabs(ans[i].first) << " " << getabs(ans[i].second) << endl;
		}
	}

	system("pause");
	return 0;
}