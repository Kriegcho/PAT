#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

struct node
{
	int d;
	string addr, naddr;
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
		cin >> p->addr >> p->d >> p->naddr;
		m[p->addr] = p;
	}
	vector<node*> ans1, ans2, ans3;
	string t = head, tk, tl;
	while (t != "-1")
	{
		if (m[t]->d < 0) ans1.push_back(m[t]);
		else if (m[t]->d >= 0 && m[t]->d <= K) ans2.push_back(m[t]);
		else ans3.push_back(m[t]);
		t = m[t]->naddr;
	}
	string s1 = ans2.empty() ? ans3.empty() ? "-1" : ans3[0]->addr : ans2[0]->addr;
	string s2 = ans3.empty() ? "-1" : ans3[0]->addr;
	for (int i = 0; i < ans1.size(); i++) cout << ans1[i]->addr << " " << ans1[i]->d << " " << (i == ans1.size() - 1 ? s1 : ans1[i + 1]->addr) << endl;
	for (int i = 0; i < ans2.size(); i++) cout << ans2[i]->addr << " " << ans2[i]->d << " " << (i == ans2.size() - 1 ? s2 : ans2[i + 1]->addr) << endl;
	for (int i = 0; i < ans3.size(); i++) cout << ans3[i]->addr << " " << ans3[i]->d << " " << (i == ans3.size() - 1 ? "-1" : ans3[i + 1]->addr) << endl;

	system("pause");
	return 0;
}