#include <iostream>
#include <string>
#include <stack>
using namespace std;

struct node
{
	node() { lc = rc = NULL; }
	int data;
	node *lc, *rc;
};

void PostO(node* r, node* root)
{
	if (r->lc) PostO(r->lc, root);
	if (r->rc) PostO(r->rc, root);
	cout << r->data;
	if (r != root) cout << " ";
}

int main()
{
	int N;
	cin >> N;
	stack<node*> s;
	node* cur = NULL;
	node* r = NULL;
	for (int i = 0; i < 2 * N; i++)
	{
		string t;
		cin >> t;
		if (t == "Push")
		{
			int n;
			cin >> n;
			node* p = new node;
			p->data = n;
			if (cur)
			{
				cur->rc = p;
				cur = NULL;
			}
			else if (!s.empty()) s.top()->lc = p;
			s.push(p);
		}
		else if (t == "Pop")
		{
			cur = s.top();
			s.pop();
			if (s.empty() && r == NULL) r = cur;
		}
	}
	PostO(r, r);

	system("pause");
	return 0;
}