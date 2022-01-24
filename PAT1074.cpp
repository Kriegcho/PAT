#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <vector>
using namespace std;

struct node
{
	string add, nadd;
	int data;
};

int main()
{
	string head;
	int N, K;
	cin >> head >> N >> K;
	map<string, node*> m;
	for (int i = 0; i < N; i++)
	{
		node* p = new node;
		cin >> p->add >> p->data >> p->nadd;
		m.insert(make_pair(p->add, p));
	}
	int len = 0; // ±í³¤
	string t = head;
	while (t != "-1")
	{
		if (m.find(t) != m.end())
		{
			len++;
			t = m[t]->nadd;
		}
	}
	stack<node*> st;
	vector<node*> ans;
	for (int i = 0; i < len / K; i++)
	{
		for (int i = 0; i < K; i++)
		{
			if (m.find(head) != m.end())
			{
				st.push(m[head]);
				head = m[head]->nadd;
			}
			else break;
		}
		while (!st.empty())
		{
			ans.push_back(st.top());
			st.pop();
		}
	}
	
	while (head != "-1")
	{
		if (m.find(head) != m.end())
		{
			ans.push_back(m[head]);
			head = m[head]->nadd;
		}
		else break;
	}
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]->add << " " << ans[i]->data << " ";
		if (i < ans.size() - 1) cout << ans[i + 1]->add << endl;
		else cout << "-1" << endl;
	}

	system("pause");
	return 0;
}