#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 思路：先把输入的字符串一一对应为数字ID，然后深度遍历

struct rec
{
	int ind, time;
};

struct ans
{
	string s;
	int c;
};

set<string> ns;
map<int, string> nm1;
map<string, int> nm2;
vector<vector<rec*>> recs; // 邻接表
vector<int> ts; // 总时间
vector<bool> flag; // 访问标志

vector<ans*> as; // 输出
bool cmp(ans* a1, ans* a2)
{
	return a1->s < a2->s;
}

void DFS(int pos, int& c, int& ind, int& maxt, int& total)
{
	for (int i = 0; i < recs[pos].size(); i++)
	{
		if (flag[recs[pos][i]->ind] == false)
		{
			flag[recs[pos][i]->ind] = true;
			c++;
			total += ts[recs[pos][i]->ind];
			if (ts[recs[pos][i]->ind] > maxt)
			{
				maxt = ts[recs[pos][i]->ind];
				ind = recs[pos][i]->ind;
			}
			DFS(recs[pos][i]->ind, c, ind, maxt, total);
		}
	}
}

int main()
{
	int N, K;
	cin >> N >> K;
	int ind = 0;
	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		int len;
		cin >> s1 >> s2 >> len;
		if (ns.find(s1) == ns.end())
		{
			ns.insert(s1);
			nm1.insert(make_pair(ind, s1));
			nm2.insert(make_pair(s1, ind));
			ind++;
			ts.push_back(0);
			flag.push_back(false);
			recs.resize(ts.size());
		}
		if (ns.find(s2) == ns.end())
		{
			ns.insert(s2);
			nm1.insert(make_pair(ind, s2));
			nm2.insert(make_pair(s2, ind));
			ind++;
			ts.push_back(0);
			flag.push_back(false);
			recs.resize(ts.size());
		}
		ts[nm2[s1]] += len;
		ts[nm2[s2]] += len;
		rec* p = new rec;
		p->ind = nm2[s2];
		p->time = len;
		recs[nm2[s1]].push_back(p);
		p = new rec;
		p->ind = nm2[s1];
		p->time = len;
		recs[nm2[s2]].push_back(p);
	}

	int cnt = 0;
	for (int i = 0; i < ts.size(); i++)
	{
		if (flag[i] == false)
		{
			flag[i] = true;
			int c = 1, maxt = ts[i], ind = i, total = ts[i];
			DFS(i, c, ind, maxt, total);
			if (total / 2 > K && c > 2)
			{
				cnt++;
				ans* p = new ans;
				p->s = nm1[ind];
				p->c = c;
				as.push_back(p);
			}
		}
	}

	cout << cnt << endl;
	sort(as.begin(), as.end(), cmp);
	for (int i = 0; i < cnt; i++)
	{
		cout << as[i]->s << " " << as[i]->c << endl;
	}

	system("pause");
	return 0;
}