#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct node
{
	node()
	{
		lc = NULL;
		rc = NULL;
	}
	int data;
	node* lc;
	node* rc;
};

vector<int> post;
vector<int> mid;

void GetTree(node* root, int pl, int pr, int ml, int mr)
{
	root->data = post[pr];
	int index;
	for (int i = ml; i <= mr; i++)
	{
		if (mid[i] == root->data)
		{
			index = i;
			break;
		}
	}
	if (index > ml)
	{
		node* lc = new node;
		lc->data = post[index - 1];
		root->lc = lc;
		GetTree(lc, pl, pl + index - ml - 1, ml, index - 1);
	}
	if (mr > index)
	{
		node* rc = new node;
		rc->data = post[pr - 1];
		root->rc = rc;
		GetTree(rc, pl + index - ml, pr - 1, index + 1, mr);
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		post.push_back(t);
	}
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		mid.push_back(t);
	}

	if (N > 0)
	{
		node tree;
		GetTree(&tree, 0, N - 1, 0, N - 1);
		cout << tree.data;
		queue<node*> q;
		if (tree.lc) q.push(tree.lc);
		if (tree.rc) q.push(tree.rc);
		while (!q.empty())
		{
			cout << " " << q.front()->data;
			if (q.front()->lc) q.push(q.front()->lc);
			if (q.front()->rc) q.push(q.front()->rc);
			q.pop();
		}
	}

	system("pause");
	return 0;
}