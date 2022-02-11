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
vector<int> pre, ino;
map<int, node*> m;
node* gettree(node* p, int pl, int ph, int ol, int oh) // 跟1143题目基本一样。。改一下gettree函数即可。根据先序和中序建树。
{
	m[pre[pl]]->par = p;
	if (pl == ph) return m[pre[pl]];
	int ind = ol;
	for (int i = ol; i <= oh; i++)
	{
		if (ino[i] == pre[pl])
		{
			ind = i;
			break;
		}
	}
	if (ind > ol) m[pre[pl]]->lc = gettree(m[pre[pl]], pl + 1, pl + ind - ol, ol, ind - 1);
	if (ind < oh) m[pre[pl]]->rc = gettree(m[pre[pl]], pl + ind - ol + 1, ph, ind + 1, oh);
	return m[pre[pl]];
}

int main()
{
	int M, N;
	cin >> M >> N;
	pre.resize(N);
	ino.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> ino[i];
		node* p = new node(ino[i]);
		m[ino[i]] = p;
	}
	for (int i = 0; i < N; i++) cin >> pre[i];
	node* r = gettree(NULL, 0, N - 1, 0, N - 1);
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