#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct node
{
	string s, n;
	int k;
};

bool cmp(node n1, node n2)
{
	return n1.k < n2.k;
}

int main()
{
	int N;
	cin >> N;
	vector<node> ns(N), sn;
	map<string, node> m;
	string head;
	cin >> head;
	for (int i = 0; i < N; i++)
	{
		string t;
		cin >> ns[i].s >> ns[i].k >> ns[i].n;
		m.insert(make_pair(ns[i].s, ns[i]));
	}
	string t = head;
	while (t != "-1")
	{
		sn.push_back(m[t]);
		t = m[t].n;
	}
	sort(sn.begin(), sn.end(), cmp);
	if (sn.empty()) cout << "0 -1";
	else
	{
		cout << sn.size() << " " << sn[0].s << endl;
		for (int i = 0; i < sn.size(); i++)
		{
			cout << sn[i].s << " " << sn[i].k << " ";
			if (i < sn.size() - 1) cout << sn[i + 1].s << endl;
			else cout << "-1" << endl;
		}
	}

	system("pause");
	return 0;
}