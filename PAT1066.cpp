#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	node() { lc = rc = NULL; }
	int d;
	node *lc, *rc;
};

int geth(node* r)
{
	if (r) return 1 + max(geth(r->lc), geth(r->rc));
	else return 0;
}

node* rot(node* r, int type)
{
	node* t = NULL;
	switch (type)
	{
	case 1: // LL
		t = r->lc;
		r->lc = t->rc;
		t->rc = r;
		break;
	case 2: // LR
		r->lc = rot(r->lc, 3);
		return rot(r, 1);
		break;
	case 3: // RR
		t = r->rc;
		r->rc = t->lc;
		t->lc = r;
		break;
	case 4: // RL
		r->rc = rot(r->rc, 1);
		return rot(r, 3);
		break;
	}
	return t;
}

node* insn(node* r, int n)
{
	if (r)
	{
		if (r->d > n)
		{
			r->lc = insn(r->lc, n);
			if (geth(r->lc) - geth(r->rc) > 1) r = rot(r, r->lc->d > n ? 1 : 2);
		}
		else
		{
			r->rc = insn(r->rc, n);
			if (geth(r->rc) - geth(r->lc) > 1) r = rot(r, r->rc->d < n ? 3 : 4);
		}
	}
	else
	{
		r = new node();
		r->d = n;
	}
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
		r = insn(r, t);
	}
	cout << r->d;

	system("pause");
	return 0;
}