#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node
{
	node() { lc = NULL; rc = NULL; }
	int d;
	node *lc, *rc;
};

int getcnt(node* r)
{
	if (r == NULL) return 0;
	int t = 1;
	t += getcnt(r->lc);
	t += getcnt(r->rc);
	return t;
}

vector<int> ds;
void fill(node* r, int l, int h)
{
	int lc = getcnt(r->lc);
	int rc = getcnt(r->rc);
	r->d = ds[l + lc];
	if (lc) fill(r->lc, l, l + lc - 1);
	if (rc) fill(r->rc, l + lc + 1, h);
}


int main()
{
	int N;
	cin >> N;
	vector<node> tr(N);
	for (int i = 0; i < N; i++)
	{
		int l, r;
		cin >> l >> r;
		if (l > -1) tr[i].lc = &tr[l];
		if (r > -1) tr[i].rc = &tr[r];
		tr[i].d = i;
	}
	ds.resize(N);
	for (int i = 0; i < N; i++) cin >> ds[i];
	sort(ds.begin(), ds.end());
	node* r = &tr[0];
	fill(r, 0, N - 1);
	queue<node*> q;
	q.push(r);
	while (!q.empty())
	{
		if (q.front() != r) cout << " ";
		cout << q.front()->d;
		if (q.front()->lc) q.push(q.front()->lc);
		if (q.front()->rc) q.push(q.front()->rc);
		q.pop();
	}
 
	system("pause");
	return 0;
}