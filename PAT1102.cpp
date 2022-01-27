#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	node() { lc = rc = NULL; }
	int ind;
	node *lc, *rc;
};

void invert(node* r)
{
	if (r)
	{
		invert(r->lc);
		invert(r->rc);
		swap(r->lc, r->rc);
	}
}

void inorder(node* r, bool& f)
{
	if (r)
	{
		inorder(r->lc, f);
		if (f) cout << " ";
		cout << r->ind;
		f = true;
		inorder(r->rc, f);
	}
}

int main()
{
	int N;
	cin >> N;
	vector<node> tr(N);
	vector<bool> f(N, false);
	for (int i = 0; i < N; i++)
	{
		tr[i].ind = i;
		char c1, c2;
		cin >> c1 >> c2;
		if (c1 != '-')
		{
			tr[i].lc = &tr[c1 - '0'];
			f[c1 - '0'] = true;
		}
		if (c2 != '-')
		{
			tr[i].rc = &tr[c2 - '0'];
			f[c2 - '0'] = true;
		}
	}
	node* r = NULL;
	for (int i = 0; i < N; i++)
		if (!f[i])
		{
			r = &tr[i];
			break;
		}
	invert(r);
	queue<node*> q;
	q.push(r);
	while (!q.empty())
	{
		if (q.front() != r) cout << " ";
		cout << q.front()->ind;
		if (q.front()->lc) q.push(q.front()->lc);
		if (q.front()->rc) q.push(q.front()->rc);
		q.pop();
	}
	cout << endl;
	bool flag = false;
	inorder(r, flag);

	system("pause");
	return 0;
}