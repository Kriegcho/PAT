#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
using namespace std;

vector<int> d;
struct node
{
	node() { lc = rc = NULL; }
	int d;
	node *lc, *rc;
};

node* gettree(int l, int h)
{
	node* p = new node;
	if (l == h) p->d = d[l];
	else if (l < h)
	{
		int c = h - l + 1;
		int t = log(c + 1) / log(2);
		int temp;
		if (c - pow(2, t) + 1 > pow(2, t - 1)) temp = pow(2, t - 1) - 1 + pow(2, t - 1);
		else temp = pow(2, t - 1) - 1 + c - pow(2, t) + 1;
		p->d = d[l + temp];
		p->lc = gettree(l, l + temp - 1);
		p->rc = gettree(l + temp + 1, h);
	}
	else p = NULL;
	return p;
}

int main()
{
	int N;
	cin >> N;
	d.resize(N);
	for (int i = 0; i < N; i++) cin >> d[i];
	sort(d.begin(), d.end());
	node* r = gettree(0, N - 1);
	queue<node*> q;
	cout << r->d;
	if (r->lc) q.push(r->lc);
	if (r->rc) q.push(r->rc);
	while (!q.empty())
	{
		cout << " " << q.front()->d;
		if (q.front()->lc) q.push(q.front()->lc);
		if (q.front()->rc) q.push(q.front()->rc);
		q.pop();
	}

	system("pause");
	return 0;
}