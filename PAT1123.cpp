#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct node
{
	node(int nd) { d = nd; lc = NULL; rc = NULL; }
	int d;
	node *lc, *rc;
};
int geth(node* n)
{
	if (n) return 1 + max(geth(n->lc), geth(n->rc));
	else return 0;
}
node* rot(node* r, int nt)
{
	node* t = NULL;
	switch (nt)
	{
		case 1: // LL
			t = r->lc;
			r->lc = t->rc;
			t->rc = r;
			break;
		case 2: // RR
			t = r->rc;
			r->rc = t->lc;
			t->lc = r;
			break;
		case 3: // RL
			r->rc = rot(r->rc, 1);
			t = rot(r, 2);
			break;
		case 4: // LR
			r->lc = rot(r->lc, 2);
			t = rot(r, 1);
			break;
	}
	return t;
}
node* ins(node* r, int d)
{
	if (r)
	{
		if (d > r->d)
		{
			r->rc = ins(r->rc, d);
			if (geth(r->rc) - geth(r->lc) > 1) r = rot(r, r->rc->d < d ? 2 : 3);
		}
		else
		{
			r->lc = ins(r->lc, d);
			if (geth(r->lc) - geth(r->rc) > 1) r = rot(r, r->lc->d > d ? 1 : 4);
		}
	}
	else r = new node(d);
	return r;
}

int main()
{
	int N;
	cin >> N;
	node* r = NULL;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		r = ins(r, t);
	}
	int h = log(N + 1) / log(2);
	queue<node*> ans, q;
	q.push(r);
	bool f = true;
	int dep = 0;
	while (1)
	{
		queue<node*> t;
		bool con = true;
		while (!q.empty())
		{
			if (q.front()->lc)
			{
				if (!con) f = false;
				t.push(q.front()->lc);
			}
			else con = false;
			if (q.front()->rc)
			{
				if (!con) f = false;
				t.push(q.front()->rc);
			}
			else con = false;
			ans.push(q.front());
			q.pop();
		}
		if (t.empty()) break;
		dep++;
		if (dep < h && t.size() != pow(2, dep)) f = false;
		q = t;
	}
	bool flag = false;
	while (!ans.empty())
	{
		if (flag) cout << " ";
		flag = true;
		cout << ans.front()->d;
		ans.pop();
	}
	cout << endl;
	cout << (f ? "YES" : "NO");

	system("pause");
	return 0;
}