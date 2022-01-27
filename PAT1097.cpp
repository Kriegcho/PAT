#include <iostream>
#include <set>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct node
{
	string s, ns;
	int k;
};

int main()
{
	string head;
	int N;
	cin >> head >> N;
	map<string, node*> m;
	for (int i = 0; i < N; i++)
	{
		node* p = new node;
		cin >> p->s >> p->k >> p->ns;
		m[p->s] = p;
	}
	vector<node*> ans, rem;
	set<int> sk;
	while (m.find(head) != m.end())
	{
		int t = m[head]->k >= 0 ? m[head]->k : -m[head]->k;
		if (sk.find(t) != sk.end()) rem.push_back(m[head]);
		else
		{
			ans.push_back(m[head]);
			sk.insert(t);
		}
		head = m[head]->ns;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]->s << " " << ans[i]->k << " ";
		if (i < ans.size() - 1) cout << ans[i + 1]->s << endl;
		else cout << "-1" << endl;
	}
	for (int i = 0; i < rem.size(); i++)
	{
		cout << rem[i]->s << " " << rem[i]->k << " ";
		if (i < rem.size() - 1) cout << rem[i + 1]->s << endl;
		else cout << "-1" << endl;
	}

	system("pause");
	return 0;
}