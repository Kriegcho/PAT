#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> w(100, 0);
struct node
{
	int id;
	vector<int> s;
};
vector<node> tree(100);
vector<bool> f(100, false);
vector<vector<int>> ans;
vector<int> temp;

void DFS(int pos, int W, int cw)
{
	if (tree[pos].s.empty()) // 叶子
	{
		temp.push_back(w[pos]);
		if (cw == W) ans.push_back(temp);
		temp.pop_back();
	}
	temp.push_back(w[pos]);
	for (int i = 0; i < tree[pos].s.size(); i++)
	{
		cw += w[tree[pos].s[i]];
		DFS(tree[pos].s[i], W, cw);
		cw -= w[tree[pos].s[i]];
	}
	temp.pop_back();
}

bool cmp(vector<int> v1, vector<int> v2)
{
	for (int i = 0; i < v1.size() && i < v2.size(); i++)
	{
		if (v1[i] > v2[i]) return true;
		else if (v1[i] == v2[i]) continue;
		else return false;
	}
	return v1.size() > v2.size();
}

int main()
{
	int N, M, S;
	cin >> N >> M >> S;
	for (int i = 0; i < N; i++) cin >> w[i];
	for (int i = 0; i < M; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		for (int j = 0; j < t2; j++)
		{
			int t;
			cin >> t;
			tree[t1].s.push_back(t);
		}
	}
	f[0] = true;
	DFS(0, S, w[0]);
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++)
	{
		for (int j = 0; j < ans[i].size(); j++)
		{
			cout << ans[i][j];
			if (j < ans[i].size() - 1) cout << " ";
			else cout << endl;
		}
	}

	system("pause");
	return 0;
}