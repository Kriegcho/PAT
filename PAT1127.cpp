#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

struct node
{
	node(int nd) { d = nd; lc = NULL; rc = NULL; }
	int d;
	node *lc, *rc;
};
vector<int> ino, poo;
map<int, node*> m;
node* filltree(int ol, int oh, int pl, int ph)
{
	node* p = m[poo[ph]];
	int ind = ol;
	for (int i = ol; i <= oh; i++)
		if (ino[i] == poo[ph])
		{
			ind = i;
			break;
		}
	if (ind > ol) p->lc = filltree(ol, ind - 1, pl, pl + ind - ol - 1);
	if (ind < oh) p->rc = filltree(ind + 1, oh, pl + ind - ol, ph - 1);
	return p;
}

int main()
{
	int N;
	cin >> N;
	ino.resize(N);
	poo.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> ino[i];
		node* p = new node(ino[i]);
		m[ino[i]] = p;
	}
	for (int i = 0; i < N; i++) cin >> poo[i];
	node* r = filltree(0, N - 1, 0, N - 1);
	bool f = true;
	queue<node*> q;
	vector<int> ans;
	q.push(r);
	ans.push_back(r->d);
	while (1)
	{
		queue<node*> qt, qs;
		stack<node*> st;
		while (!q.empty())
		{
			if (q.front()->lc) qt.push(q.front()->lc);
			if (q.front()->rc) qt.push(q.front()->rc);
			q.pop();
		}
		if (qt.empty()) break;
		q = qt;
		if (f)
		{
			while (!qt.empty())
			{
				ans.push_back(qt.front()->d);
				qt.pop();
			}
		}
		else
		{
			while (!qt.empty())
			{
				st.push(qt.front());
				qt.pop();
			}
			while (!st.empty())
			{
				ans.push_back(st.top()->d);
				st.pop();
			}
		}
		f = !f;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		if (i > 0) cout << " ";
		cout << ans[i];
	}

	system("pause");
	return 0;
}