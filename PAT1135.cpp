#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct node
{
	node(int nd) { d = nd; lc = NULL; rc = NULL; }
	int d;
	node *lc, *rc;
};

node* gettree(const vector<int>& pre, int l, int h)
{
	node* p = new node(pre[l]);
	if (l == h) return p;
	int ind = l;
	for (int i = l + 1; i <= h; i++)
		if (abs(pre[i]) > abs(pre[l]))
		{
			ind = i;
			break;
		}
	if (ind == l) p->lc = gettree(pre, l + 1, h);
	else if (ind > l + 1) p->lc = gettree(pre, l + 1, ind - 1);
	if (ind > l) p->rc = gettree(pre, ind, h);
	return p;
}

int ah = 0;
bool DFS(node* r, int h)
{
	if (!r)
	{
		if (ah == 0) ah = h;
		else if (h != ah) return false;
		return true;
	}
	bool f = true;
	if (r->d > 0) h++;
	if (r->lc && r->d < 0 && r->lc->d < 0) return false;
	f &= DFS(r->lc, h);
	if (!f) return f;
	if (r->rc && r->d < 0 && r->rc->d < 0) return false;
	f &= DFS(r->rc, h);
	return f;
}

int main()
{
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int N;
		cin >> N;
		ah = 0;
		vector<int> pre(N);
		for (int j = 0; j < N; j++) cin >> pre[j];
		node* r = gettree(pre, 0, N - 1);
		if (r->d > 0 && DFS(r, 0)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	system("pause");
	return 0;
}