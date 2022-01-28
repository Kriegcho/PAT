#include <iostream>
#include <vector>
using namespace std;

struct st
{
	st() {}
	st(st* p, int d) { len = p->len; time = p->time; des = d; }
	int len, time, des;
};
int N, M, s, d;
vector<vector<st*>> adj;
vector<int> ansl, anst, temp;
vector<bool> v;
int minl = INT32_MAX, mint = INT32_MAX, minlt = INT32_MAX;
void DFS(int pos, int len, int time)
{
	v[pos] = true;
	temp.push_back(pos);
	if (pos == d)
	{
		if (len < minl)
		{
			minl = len;
			minlt = time;
			ansl = temp;
		}
		else if (len == minl && time < minlt)
		{
			minlt = time;
			ansl = temp;
		}
		if (time < mint)
		{
			mint = time;
			anst = temp;
		}
		else if (time == mint && temp.size() < anst.size()) anst = temp;
		v[pos] = false;
		temp.pop_back();
		return;
	}
	for (int i = 0; i < adj[pos].size(); i++)
		if (!v[adj[pos][i]->des]) DFS(adj[pos][i]->des, len + adj[pos][i]->len, time + adj[pos][i]->time);
	v[pos] = false;
	temp.pop_back();
}

int main()
{
	cin >> N >> M;
	adj.resize(N);
	v.assign(N, false);
	for (int i = 0; i < M; i++)
	{
		st* p = new st;
		int v1, ow, l, t;
		scanf("%d %d %d %d %d", &v1, &p->des, &ow, &p->len, &p->time);
		adj[v1].push_back(p);
		if (!ow)
		{
			st* q = new st(p, v1);
			adj[p->des].push_back(q);
		}
	}
	cin >> s >> d;
	DFS(s, 0, 0);
	if (ansl == anst)
	{
		cout << "Distance = " << minl << "; Time = " << mint << ": ";
		for (int i = 0; i < ansl.size(); i++)
		{
			if (i > 0) cout << " -> ";
			cout << ansl[i];
		}
	}
	else
	{
		cout << "Distance = " << minl << ": ";
		for (int i = 0; i < ansl.size(); i++)
		{
			if (i > 0) cout << " -> ";
			cout << ansl[i];
		}
		cout << endl;
		cout << "Time = " << mint << ": ";
		for (int i = 0; i < anst.size(); i++)
		{
			if (i > 0) cout << " -> ";
			cout << anst[i];
		}
	}

	system("pause");
	return 0;
}