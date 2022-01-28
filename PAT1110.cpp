#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct node
{
	node() { lc = rc = NULL; }
	bool hasc() { return lc || rc; }
	int d;
	node *lc, *rc;
};

int main()
{
	int N;
	cin >> N;
	vector<node> ns(N);
	vector<bool> f(N, true);
	for (int i = 0; i < N; i++)
	{
		ns[i].d = i;
		string s1, s2;
		cin >> s1 >> s2;
		if (s1[0] != '-')
		{
			int t = stoi(s1);
			ns[i].lc = &ns[t];
			f[t] = false;
		}
		if (s2[0] != '-')
		{
			int t = stoi(s2);
			ns[i].rc = &ns[t];
			f[t] = false;
		}
	}
	int r;
	for (int i = 0; i < N; i++)
		if (f[i])
		{
			r = i;
			break;
		}
	queue<node*> q;
	q.push(&ns[r]);
	int dep = 0, h = log(N + 1) / log(2);
	node* last = q.front();
	bool bc = true;
	while (1)
	{
		bool con = true;
		queue<node*> t;
		while (!q.empty())
		{
			node* fr = q.front();
			if (fr->lc)
			{
				if (!con)
				{
					bc = false;
					break;
				}
				t.push(fr->lc);
			}
			else con = false;
			if (fr->rc)
			{
				if (!con)
				{
					bc = false;
					break;
				}
				t.push(fr->rc);
			}
			else con = false;
			q.pop();
		}
		if (!bc) break;
		if (t.empty()) break;
		last = t.back();
		dep++;
		if (dep < h && t.size() < pow(2, dep))
		{
			bc = false;
			break;
		}
		else if (dep > h)
		{
			bc = false;
			break;
		}
		q = t;
	}
	if (bc) cout << "YES " << last->d;
	else cout << "NO " << r;

	system("pause");
	return 0;
}