#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;

struct rec
{
	string ar;
	int time;
	int vip;
};

struct tb
{
	string occ;
	int ind;
};

int geth(string s)
{
	return stoi(s.substr(0, 2));
}

int getm(string s)
{
	return stoi(s.substr(3, 2));
}

int gets(string s)
{
	return stoi(s.substr(6, 2));
}

bool cmptime(string s1, string s2)
{
	return geth(s1) != geth(s2) ? geth(s1) < geth(s2) : (getm(s1) != getm(s2) ? getm(s1) < getm(s2) : gets(s1) < gets(s2));
}

bool cmp(rec* r1, rec* r2)
{
	return cmptime(r1->ar, r2->ar);
}

bool cmptb(tb* t1, tb* t2)
{
	return cmptime(t1->occ, t2->occ);
}

string addtime(string s, int m)
{
	if (getm(s) + m >= 60)
	{
		return ((geth(s) + (getm(s) + m) / 60) > 10 ? to_string(geth(s) + (getm(s) + m) / 60) : "0" + to_string(geth(s) + (getm(s) + m) / 60)) + ":" + ((getm(s) + m) % 60 > 10 ? to_string((getm(s) + m) % 60) : "0" + to_string((getm(s) + m) % 60)) + ":" + s.substr(6, 2);
	}
	else
	{
		return s.substr(0, 3) + (getm(s) + m > 10 ? to_string(getm(s) + m) : "0" + to_string(getm(s) + m)) + s.substr(5, 3);
	}
}

int calctime(string t1, string t2)
{
	return ((geth(t2) - geth(t1)) * 3600 + (getm(t2) - getm(t1)) * 60 + gets(t2) - gets(t1) + 30) / 60;
}

int main()
{
	int N;
	cin >> N;
	vector<rec*> recs;
	for (int i = 0; i < N; i++)
	{
		rec* r = new rec;
		cin >> r->ar >> r->time >> r->vip;
		if (r->time > 120) r->time = 120;
		recs.push_back(r);
	}
	sort(recs.begin(), recs.end(), cmp);
	int K, M;
	cin >> K >> M;
	set<int> vipt; // vip桌子集合
	for (int i = 0; i < M; i++)
	{
		int t;
		cin >> t;
		vipt.insert(t);
	}
	vector<int> cnt;
	cnt.assign(K, 0);
	queue<int> q;
	queue<int> qv;
	vector<tb*> tbs; // 正在使用的桌子
	int min = 1; // 最小可用桌号
	for (int i = 0; i < N; i++)
	{
		if (!cmptime(recs[i]->ar, "21:00:00"))
		{
			break;
		}
		// 更新桌子状态
		if (!tbs.empty())
		{
			do {
				vector<tb*>::iterator it = tbs.begin();
				while (it != tbs.end())
				{
					if (!cmptime(recs[i]->ar, (*it)->occ))
					{
						// 空出来VIP桌子
						if (vipt.find((*it)->ind) != vipt.end())
						{
							if (!qv.empty())
							{
								cout << recs[qv.front()]->ar << " " << (*it)->occ << " " << calctime(recs[qv.front()]->ar, (*it)->occ) << endl;
								// 分配给等待中的VIP
								(*it)->occ = addtime((*it)->occ, recs[qv.front()]->time);
								qv.pop();
								cnt[(*it)->ind - 1]++;
							}
							else if (!q.empty())
							{
								cout << recs[q.front()]->ar << " " << (*it)->occ << " " << calctime(recs[q.front()]->ar, (*it)->occ) << endl;
								// 分配给队列中的用户
								(*it)->occ = addtime((*it)->occ, recs[q.front()]->time);
								q.pop();
								cnt[(*it)->ind - 1]++;
							}
							else
							{
								// 移除记录
								if ((*it)->ind < min) min = (*it)->ind;
								it = tbs.erase(it);
								continue;
							}
						}
						else
						{
							if (!q.empty())
							{
								cout << recs[q.front()]->ar << " " << (*it)->occ << " " << calctime(recs[q.front()]->ar, (*it)->occ) << endl;
								// 分配给队列中的用户
								(*it)->occ = addtime((*it)->occ, recs[q.front()]->time);
								q.pop();
								cnt[(*it)->ind - 1]++;
							}
							else
							{
								// 移除记录
								if ((*it)->ind < min) min = (*it)->ind;
								it = tbs.erase(it);
								continue;
							}
						}
					}
					it++;
				}
				sort(tbs.begin(), tbs.end(), cmptb);
			} while (!tbs.empty() && !cmptime(recs[i]->ar, tbs[0]->occ));
		}

		if (tbs.size() == K)
		{
			// 没位置了，加入队列
			(recs[i]->vip ? qv : q).push(i);
		}
		else
		{
			vector<bool> b;
			b.assign(K, false);
			for (int j = 0; j < tbs.size(); j++)
			{
				b[tbs[j]->ind - 1] = true;
			}
			// 此时肯定有空位置
			tb* t = new tb;
			t->occ = addtime(recs[i]->ar, recs[i]->time);
			if (recs[i]->vip)
			{
				bool f = true;
				for (set<int>::iterator it = vipt.begin(); it != vipt.end(); it++)
				{
					if (!b[*it - 1]) 
					{
						t->ind = *it;
						f = false;
						break;
					}
				}
				if (f) t->ind = min;
			}
			else t->ind = min;
			b[t->ind - 1] = true;
			cnt[t->ind - 1]++;
			tbs.push_back(t);
			cout << recs[i]->ar << " " << recs[i]->ar << " 0" << endl;
			// 找到下一张最小序号
			for (int j = 0; j < K; j++)
			{
				if (!b[j])
				{
					min = j + 1;
					break;
				}
			}
		}
		sort(tbs.begin(), tbs.end(), cmptb);
		if (tbs.size() == K && !cmptime(tbs[0]->occ, "21:00:00")) break;
	}
	// 最后一趟循环后，仍有可能存在队列中还在等待的情况，要将队列处理掉
	do {
		vector<tb*>::iterator it = tbs.begin();
		while (it != tbs.end())
		{
			if (!cmptime("21:00:00", (*it)->occ))
			{
				// 空出来VIP桌子
				if (vipt.find((*it)->ind) != vipt.end())
				{
					if (!qv.empty())
					{
						cout << recs[qv.front()]->ar << " " << (*it)->occ << " " << calctime(recs[qv.front()]->ar, (*it)->occ) << endl;
						// 分配给等待中的VIP
						(*it)->occ = addtime((*it)->occ, recs[qv.front()]->time);
						qv.pop();
						cnt[(*it)->ind - 1]++;
					}
					else if (!q.empty())
					{
						cout << recs[q.front()]->ar << " " << (*it)->occ << " " << calctime(recs[q.front()]->ar, (*it)->occ) << endl;
						// 分配给队列中的用户
						(*it)->occ = addtime((*it)->occ, recs[q.front()]->time);
						q.pop();
						cnt[(*it)->ind - 1]++;
					}
					else
					{
						// 移除记录
						if ((*it)->ind < min) min = (*it)->ind;
						it = tbs.erase(it);
						continue;
					}
				}
				else
				{
					if (!q.empty())
					{
						cout << recs[q.front()]->ar << " " << (*it)->occ << " " << calctime(recs[q.front()]->ar, (*it)->occ) << endl;
						// 分配给队列中的用户
						(*it)->occ = addtime((*it)->occ, recs[q.front()]->time);
						q.pop();
						cnt[(*it)->ind - 1]++;
					}
					else
					{
						// 移除记录
						if ((*it)->ind < min) min = (*it)->ind;
						it = tbs.erase(it);
						continue;
					}
				}
			}
			it++;
		}
		sort(tbs.begin(), tbs.end(), cmptb);
	} while (!tbs.empty() && !cmptime("21:00:00", tbs[0]->occ));

	for (int i = 0; i < K; i++)
	{
		if (i != 0)
		{
			cout << " ";
		}
		cout << cnt[i];
	}

	system("pause");
	return 0;
}