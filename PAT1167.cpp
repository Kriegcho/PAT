#include <iostream>
#include <map>
#include <queue>
using namespace std;
// 本题搞懂建树逻辑就行了。新结点比根大就找右子树直到找到合适位置，比根小就是新根
struct node
{
	node(int nd) { d = nd; lc = rc = par = NULL; }
	int d;
	node *lc, *rc, *par;
};

node* insn(node* r, node* c, node* p)
{
	if (p->d < c->d)
	{
		if (c->par)
		{
			c->par->rc = p;
			p->par = c->par;
			p->lc = c;
			c->par = p;
			return r;
		}
		else
		{
			p->lc = r;
			r->par = p;
			return p;
		}
	}
	else if (c->rc) return insn(r, c->rc, p);
	else
	{
		c->rc = p;
		p->par = c;
		return r;
	}
}

int main()
{
	int N;
	cin >> N;
	map<int, node*> m;
	node* r = NULL;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		node* p = new node(t);
		if (r == NULL) r = p;
		else r = insn(r, r, p);
	}
	queue<node*> q;
	q.push(r);
	bool f = false;
	while (!q.empty())
	{
		if (q.front()->lc) q.push(q.front()->lc);
		if (q.front()->rc) q.push(q.front()->rc);
		if (f) cout << " ";
		cout << q.front()->d;
		f = true;
		q.pop();
	}

	system("pause");
	return 0;
}