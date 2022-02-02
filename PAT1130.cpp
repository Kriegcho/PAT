#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct node
{
	node() { lc = NULL; rc = NULL; }
	string sd;
	node *lc, *rc;
};

string InOrder(node* root, node* r)
{
	string t;
	if (r != root && (r->lc || r->rc)) t += "(";
	if (r->lc) t += InOrder(root, r->lc);
	t += r->sd;
	if (r->rc) t += InOrder(root, r->rc);
	if (r != root && (r->lc || r->rc)) t += ")";
	return t;
}

int main()
{
	int N;
	cin >> N;
	vector<node> ns(N);
	vector<bool> f(N, false);
	for (int i = 0; i < N; i++)
	{
		string s;
		int c1, c2;
		cin >> s >> c1 >> c2;
		ns[i].sd = s;
		if (c1 != -1)
		{
			ns[i].lc = &ns[c1 - 1];
			f[c1 - 1] = true;
		}
		if (c2 != -1)
		{
			ns[i].rc = &ns[c2 - 1];
			f[c2 - 1] = true;
		}
	}
	int ri;
	for (int i = 0; i < N; i++)
		if (!f[i])
		{
			ri = i;
			break;
		}
	string ans = InOrder(&ns[ri], &ns[ri]);
	cout << ans;

	system("pause");
	return 0;
}