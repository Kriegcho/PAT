#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <stack>
using namespace std;

struct node
{
	string add, nadd;
	int d;
};

int main()
{
	string h1, h2, t;
	int N;
	cin >> h1 >> h2 >> N;
	map<string, node*> m;
	vector<node*> ans;
	for (int i = 0; i < N; i++)
	{
		node* p = new node;
		cin >> p->add >> p->d >> p->nadd;
		m[p->add] = p;
	}
	int l1 = 0;
	t = h1;
	while (t != "-1")
	{
		t = m[t]->nadd;
		l1++;
	}
	stack<node*> l;
	if (l1 * 3 <= N)
	{
		while (h1 != "-1")
		{
			l.push(m[h1]);
			h1 = m[h1]->nadd;
		}
		while (h2 != "-1")
		{
			if (h2 != "-1")
			{
				ans.push_back(m[h2]);
				h2 = m[h2]->nadd;
			}
			if (h2 != "-1")
			{
				ans.push_back(m[h2]);
				h2 = m[h2]->nadd;
			}
			if (!l.empty())
			{
				ans.push_back(l.top());
				l.pop();
			}
		}
	}
	else
	{
		while (h2 != "-1")
		{
			l.push(m[h2]);
			h2 = m[h2]->nadd;
		}
		while (h1 != "-1")
		{
			if (h1 != "-1")
			{
				ans.push_back(m[h1]);
				h1 = m[h1]->nadd;
			}
			if (h1 != "-1")
			{
				ans.push_back(m[h1]);
				h1 = m[h1]->nadd;
			}
			if (!l.empty())
			{
				ans.push_back(l.top());
				l.pop();
			}
		}
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i]->add << " " << ans[i]->d << " " << (i < ans.size() - 1 ? ans[i + 1]->add : "-1") << endl;

	system("pause");
	return 0;
}