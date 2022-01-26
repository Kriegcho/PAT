#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct rec
{
	rec(string ss, string st, string sst)
	{
		s = ss;
		t = st;
		f = (sst == "in");
	}
	string s, t;
	bool f; // in为true
};

int geth(string s) { return stoi(s.substr(0, 2)); }
int getm(string s) { return stoi(s.substr(3, 2)); }
int gets(string s) { return stoi(s.substr(6, 2)); }

int calct(string s1, string s2)
{
	return (geth(s1) - geth(s2)) * 3600 + (getm(s1) - getm(s2)) * 60 + gets(s1) - gets(s2);
}

bool cmpr(rec* r1, rec* r2)
{
	return r1->t < r2->t;
}

int main()
{
	int N, K;
	cin >> N >> K;
	map<string, vector<rec*>*> m;
	for (int i = 0; i < N; i++)
	{
		string s, t, st;
		cin >> s >> t >> st;
		rec* r = new rec(s, t, st);
		if (m.find(s) == m.end())
		{
			vector<rec*>* v = new vector<rec*>;
			v->push_back(r);
			m.insert(make_pair(s, v));
		}
		else m[s]->push_back(r);
	}
	int maxl = 0;
	vector<string> ans;
	map<string, vector<rec*>*>::iterator it = m.begin();
	while (it != m.end()) // 除去无效记录，同时计算总的停车时间
	{
		sort(it->second->begin(), it->second->end(), cmpr);
		vector<rec*>::iterator itr = it->second->begin();
		vector<rec*>::iterator t;
		bool f = true; // 期望下一个是:in true/out false
		int temp = 0;
		while (itr != it->second->end())
		{
			if (f)
			{
				if ((*itr)->f)
				{
					t = itr;
					f = false;
					itr++;
				}
				else itr = it->second->erase(itr);
			}
			else
			{
				if ((*itr)->f)
				{
					itr = it->second->erase(t);
					t = itr;
					itr++;
				}
				else // 配对成功
				{
					temp += calct((*itr)->t, (*t)->t); // 计算配对的记录的时间
					f = true;
					itr++;
				}
			}
		}
		if (temp > maxl)
		{
			ans.clear();
			ans.push_back(it->first);
			maxl = temp;
		}
		else if (temp == maxl) ans.push_back(it->first);
		if (!f) it->second->erase(t);
		it++;
	}
	// 处理时间段:将所有记录放在一起，按时间排好序，计算每个时间点的汽车数量
	vector<rec*> total;
	it = m.begin();
	while (it != m.end())
	{
		vector<rec*>::iterator itr = it->second->begin();
		while (itr != it->second->end())
		{
			total.push_back(*itr);
			itr ++;
		}
		it++;
	}
	sort(total.begin(), total.end(), cmpr);
	map<string, int> mc;
	int c = 0;
	for (int i = 0; i < total.size(); i++)
	{
		if (total[i]->f) c++;
		else c--;
		mc[total[i]->t] = c;
	}

	for (int i = 0; i < K; i++)
	{
		string t;
		cin >> t;
		int c = 0;
		if (mc.find(t) != mc.end()) c = mc[t];
		else
		{
			mc[t] = 0;
			map<string, int>::iterator itf = mc.find(t);
			if (itf == mc.begin()) c = 0;
			else // 这里利用map特性，提高查找效率。一开始全搜遍历，超时。
			{
				itf--;
				c = itf->second;
				itf++;
				mc.erase(itf);
			}
		}
		cout << c << endl;
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
	int dh = maxl / 3600;
	int dm = (maxl % 3600) / 60;
	int ds = maxl % 60;
	printf("%02d:%02d:%02d", dh, dm, ds);

	system("pause");
	return 0;
}