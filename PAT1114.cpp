#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

struct pep
{
	pep() { mc = 0; ma = 0; }
	string id;
	vector<string> ids;
	double mc, ma;
};

struct st
{
	vector<string> ms;
	double c, t, a;
};

bool cmp(st* s1, st* s2)
{
	if (s1->a == s2->a)
		return s1->ms[0] < s2->ms[0];
	return s1->a > s2->a;
}

map<string, int> idti;
vector<string> itid;
map<string, pep*> idtp;
vector<pep*> ps;
void addp(string s)
{
	if (idti.find(s) == idti.end())
	{
		idti[s] = itid.size();
		itid.push_back(s);
		pep* p = new pep;
		p->id = s;
		ps.push_back(p);
		idtp[s] = p;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		string id, f, m;
		int k;
		double mc, ma;
		cin >> id >> f >> m >> k;
		addp(id);
		pep* p = idtp[id];
		if (f != "-1") // 这里忽略父子关系，将所有关系都存成无向图
		{
			addp(f);
			p->ids.push_back(f);
			idtp[f]->ids.push_back(p->id);
		}
		if (m != "-1")
		{
			p->ids.push_back(m);
			addp(m);
			idtp[m]->ids.push_back(p->id);
		}
		for (int j = 0; j < k; j++)
		{
			string t;
			cin >> t;
			addp(t);
			p->ids.push_back(t);
			idtp[t]->ids.push_back(p->id);
		}
		cin >> p->mc >> p->ma;
		ps.push_back(p);
		idtp[p->id] = p;
	}
	vector<st*> ans;
	vector<bool> v(itid.size(), false);
	for (int i = 0; i < ps.size(); i++)
		if (!v[idti[ps[i]->id]])
		{
			v[idti[ps[i]->id]] = true;
			vector<string> temp;
			queue<pep*> q;
			q.push(ps[i]);
			temp.push_back(ps[i]->id);
			double fc = 0, ft = 0;
			while (!q.empty())
			{
				for (int j = 0; j < q.front()->ids.size(); j++)
				{
					if (!v[idti[q.front()->ids[j]]])
					{
						v[idti[q.front()->ids[j]]] = true;
						temp.push_back(q.front()->ids[j]);
						q.push(idtp[q.front()->ids[j]]);
					}
				}
				ft += q.front()->ma;
				fc += q.front()->mc;
				q.pop();
			}
			st* p = new st;
			sort(temp.begin(), temp.end());
			p->ms = temp;
			p->c = fc;
			p->t = ft;
			p->a = ft / p->ms.size();
			ans.push_back(p);
		}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++)
	{
		cout << ans[i]->ms[0] << " " << ans[i]->ms.size() << " ";
		double t = ans[i]->c / ans[i]->ms.size();
		printf("%.3f %.3f\n", t, ans[i]->a);
	}

	system("pause");
	return 0;
}