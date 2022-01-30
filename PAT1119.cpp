#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct node
{
	node() { lc = NULL; rc = NULL; }
	int d;
	node *lc, *rc;
};
vector<int> pre, post;
map<int, node*> m;
node* fill(int prl, int prh, int pol, int poh, bool& f)
{
	node* p = m[pre[prl]];
	if (prl == prh) return p;
	int t = pol + 1;
	for (int i = pol; i <= poh; i++)
		if (post[i] == pre[prl + 1])
		{
			t = i;
			break;
		}
	p->lc = fill(prl + 1, prl + 1 + t - pol, pol, t, f);
	if (t == poh - 1) f = false; // 只有一棵子树，肯定不止一个解。放到左子树
	else p->rc = fill(prl + 1 + t - pol + 1, prh, t + 1, poh - 1, f);
	return p;
}

void Inorder(node* r, bool& f)
{
	if (r->lc) Inorder(r->lc, f);
	if (f) cout << " ";
	cout << r->d;
	f = true;
	if (r->rc) Inorder(r->rc, f);
}

int main()
{
	int N;
	cin >> N;
	pre.resize(N);
	post.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> pre[i];
		node* p = new node;
		p->d = pre[i];
		m[p->d] = p;
	}
	for (int i = 0; i < N; i++) cin >> post[i];
	bool f = true;
	node* r = fill(0, N - 1, 0, N - 1, f);
	cout << (f ? "Yes" : "No") << endl;
	bool flag = false;
	Inorder(r, flag);
	cout << endl; // 不加这个格式错误。。

	system("pause");
	return 0;
}