#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	node() { lc = NULL; rc = NULL; }
	int d;
	node *lc, *rc;
};

void ins(node* r, node* n)
{
	if (n->d <= r->d)
		if (r->lc) ins(r->lc, n);
		else r->lc = n;
	else
		if (r->rc) ins(r->rc, n);
		else r->rc = n;
}

int main()
{
	int N;
	cin >> N;
	node* root = NULL;
	for (int i = 0; i < N; i++)
	{
		node* p = new node;
		cin >> p->d;
		if (i == 0) root = p;
		else ins(root, p);
	}
	vector<int> lvl(1, 1); // 初值为1是根
	queue<node*> q;
	q.push(root);
	while (1)
	{
		queue<node*> t;
		while (!q.empty())
		{
			if (q.front()->lc) t.push(q.front()->lc);
			if (q.front()->rc) t.push(q.front()->rc);
			q.pop();
		}
		if (t.empty()) break;
		lvl.push_back(t.size());
		q = t;
	}
	int n1 = lvl[lvl.size() - 1];
	int n2 = lvl.size() > 1 ? lvl[lvl.size() - 2] : 0;
	int s = n1 + n2;
	cout << n1 << " + " << n2 << " = " << s;

	system("pause");
	return 0;
}