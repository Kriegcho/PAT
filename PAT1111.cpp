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

vector<int> disl, templ, lt, dist, tempt, tt;
vector<vector<int>> pathl, patht;
vector<bool> vf;
void DIJL(int s)
{
	disl.assign(N, 0);
	templ.assign(N, 0);
	lt.assign(N, 0);
	pathl.assign(N, vector<int>(1, s));
	int mind = INT32_MAX, ind = 0;
	for (int i = 0; i < adj[s].size(); i++)
	{
		if (adj[s][i]->len < mind)
		{
			mind = adj[s][i]->len;
			ind = adj[s][i]->des;
		}
		templ[adj[s][i]->des] = adj[s][i]->len;
		lt[adj[s][i]->des] = adj[s][i]->time;
	}
	for (int i = 0; i < N; i++)
	{
		if (disl[ind]) break;
		else
		{
			disl[ind] = mind;
			pathl[ind].push_back(ind);
			if (ind == d) break;
		}
		mind = INT32_MAX;
		for (int j = 0; j < adj[ind].size(); j++)
			if (!disl[adj[ind][j]->des] && adj[ind][j]->des != s)
			{
				if (!templ[adj[ind][j]->des] || disl[ind] + adj[ind][j]->len < templ[adj[ind][j]->des])
				{
					templ[adj[ind][j]->des] = disl[ind] + adj[ind][j]->len;
					lt[adj[ind][j]->des] = lt[ind] + adj[ind][j]->time;
					pathl[adj[ind][j]->des] = pathl[ind];
				}
				else if (disl[ind] + adj[ind][j]->len == templ[adj[ind][j]->des])
				{
					if (lt[ind] + adj[ind][j]->time < lt[adj[ind][j]->des])
					{
						lt[adj[ind][j]->des] = lt[ind] + adj[ind][j]->time;
						pathl[adj[ind][j]->des] = pathl[ind];
					}
				}
			}
		for (int j = 0; j < N; j++)
			if (!disl[j])
			{
				if (templ[j] && templ[j] < mind)
				{
					mind = templ[j];
					ind = j;
				}
				else if (templ[j] == mind && lt[j] < lt[ind]) ind = j;
			}
	}
	ansl = pathl[d];
	minl = disl[d];
}

void DIJT(int s)
{
	dist.assign(N, 0);
	tempt.assign(N, 0);
	tt.assign(N, 0);
	patht.assign(N, vector<int>(1, s));
	int mind = INT32_MAX, ind = 0;
	for (int i = 0; i < adj[s].size(); i++)
	{
		if (adj[s][i]->time < mind)
		{
			mind = adj[s][i]->time;
			ind = adj[s][i]->des;
		}
		tempt[adj[s][i]->des] = adj[s][i]->time;
		tt[adj[s][i]->des] = 1;
	}
	for (int i = 0; i < N; i++)
	{
		if (dist[ind]) break;
		else
		{
			dist[ind] = mind;
			patht[ind].push_back(ind);
			if (ind == d) break;
		}
		mind = INT32_MAX;
		for (int j = 0; j < adj[ind].size(); j++)
			if (!dist[adj[ind][j]->des] && adj[ind][j]->des != s)
			{
				if (!tempt[adj[ind][j]->des] || dist[ind] + adj[ind][j]->time < tempt[adj[ind][j]->des])
				{
					tempt[adj[ind][j]->des] = dist[ind] + adj[ind][j]->time;
					tt[adj[ind][j]->des] = tt[ind] + 1;
					patht[adj[ind][j]->des] = patht[ind];
				}
				else if (dist[ind] + adj[ind][j]->time == tempt[adj[ind][j]->des])
				{
					if (tt[ind] + 1 < tt[adj[ind][j]->des])
					{
						tt[adj[ind][j]->des] = tt[ind] + 1;
						patht[adj[ind][j]->des] = patht[ind];
					}
				}
			}
		for (int j = 0; j < N; j++)
			if (!dist[j])
			{
				if (tempt[j] && tempt[j] < mind)
				{
					mind = tempt[j];
					ind = j;
				}
				else if (tempt[j] == mind && tt[j] < tt[ind]) ind = j;
			}
	}
	anst = patht[d];
	mint = dist[d];
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
	DIJL(s);
	DIJT(s);
	//DFS(s, 0, 0);
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