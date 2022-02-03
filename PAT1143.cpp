#include <iostream>
#include <vector>
#include <map>
#include <stack>
using namespace std;

struct node
{
	node(int nd) { d = nd; lc = NULL; rc = NULL; par = NULL; }
	int d;
	node *lc, *rc, *par;
};
vector<int> pre;
map<int, node*> m;
node* gettree(node* p, int l, int h)
{
	m[pre[l]]->par = p;
	if (l == h) return m[pre[l]];
	int ind = l;
	for (int i = l + 1; i <= h; i++)
	{
		if (pre[i] > pre[l])
		{
			ind = i;
			break;
		}
	}
	if (ind == l) m[pre[l]]->lc = gettree(m[pre[l]], l + 1, h);
	else if (ind > l + 1) m[pre[l]]->lc = gettree(m[pre[l]], l + 1, ind - 1);
	if (ind > l) m[pre[l]]->rc = gettree(m[pre[l]], ind, h);
	return m[pre[l]];
}

int main()
{
	int M, N;
	cin >> M >> N;
	pre.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> pre[i];
		node* p = new node(pre[i]);
		m[pre[i]] = p;
	}
	node* r = gettree(NULL, 0, N - 1);
	for (int i = 0; i < M; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		bool f1 = m.find(t1) != m.end();
		bool f2 = m.find(t2) != m.end();
		if (f1 && f2)
		{
			node* n1 = m[t1];
			node* n2 = m[t2];
			stack<node*> s1, s2;
			while (n1)
			{
				s1.push(n1);
				n1 = n1->par;
			}
			while (n2)
			{
				s2.push(n2);
				n2 = n2->par;
			}
			int ans = -1;
			while (!s1.empty() && !s2.empty())
			{
				if (s1.top() == s2.top())
				{
					ans = s1.top()->d;
					s1.pop();
					s2.pop();
				}
				else break;
			}
			if (!s1.empty() && !s2.empty()) cout << "LCA of " << t1 << " and " << t2 << " is " << ans << "." << endl;
			else if (s1.empty()) cout << t1 << " is an ancestor of " << t2 << "." << endl;
			else if (s2.empty()) cout << t2 << " is an ancestor of " << t1 << "." << endl;
			else cout << "LCA of " << t1 << " and " << t2 << " is " << ans << "." << endl;
		}
		else if (f1) cout << "ERROR: " << t2 << " is not found." << endl;
		else if (f2) cout << "ERROR: " << t1 << " is not found." << endl;
		else cout << "ERROR: " << t1 << " and " << t2 << " are not found." << endl;
	}

	system("pause");
	return 0;
}