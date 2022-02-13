#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct node
{
	node() { lc = NULL; rc = NULL; }
	string s;
	node *lc, *rc;
};

string PostO(node* r)
{
	string s;
	if (!r->lc || !r->rc)
	{
		s = "(" + r->s;
		if (r->lc) s += PostO(r->lc);
		if (r->rc) s += PostO(r->rc);
		s += ")";
	}
	else
	{
		s = "(";
		if (r->lc) s += PostO(r->lc);
		if (r->rc) s += PostO(r->rc);
		s += r->s;
		s += ")";
	}
	return s;
}

int main()
{
	int N, ri;
	cin >> N;
	vector<node> tree(N);
	vector<bool> f(N, false);
	for (int i = 0; i < N; i++)
	{
		int l, r;
		cin >> tree[i].s >> l >> r;
		if (l != -1)
		{
			tree[i].lc = &tree[l - 1];
			f[l - 1] = true;
		}
		if (r != -1)
		{
			tree[i].rc = &tree[r - 1];
			f[r - 1] = true;
		}
	}
	for (int i = 0; i < N; i++) if (!f[i]) ri = i;
	string ans = PostO(&tree[ri]);
	cout << ans;

	system("pause");
	return 0;
}