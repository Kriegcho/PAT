#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct rs
{
	int i, s;
};

bool cmp(rs r1, rs r2)
{
	return r1.s > r2.s;
}

void round(vector<int> v, const vector<int>& w, vector<int>& s, int ng)
{
	vector<int> temp;
	for (int i = 0; i < v.size(); i += ng)
	{
		if (i + ng >= v.size()) // 最后一组了
		{
			int mw = w[v[i]];
			int c = v[i];
			for (int j = i + 1; j < v.size(); j++)
			{
				if (w[v[j]] > mw)
				{
					mw = w[v[j]];
					c = v[j];
				}
			}
			s[c]++;
			temp.push_back(c);
		}
		else
		{
			int mw = w[v[i]];
			int c = v[i];
			for (int j = i + 1; j < i + ng; j++)
			{
				if (w[v[j]] > mw)
				{
					mw = w[v[j]];
					c = v[j];
				}
			}
			s[c]++;
			temp.push_back(c);
		}
	}
	if (temp.size() > 1)
	{
		round(temp, w, s, ng);
	}
}

int main()
{
	int np, ng;
	cin >> np >> ng;
	vector<int> w(np), o(np), s(np, 0); // s为得分，每赢一轮得一分
	for (int i = 0; i < np; i++) cin >> w[i];
	for (int i = 0; i < np; i++) cin >> o[i];
	round(o, w, s, ng);
	vector<rs> r(np);
	vector<int> ans(np);
	for (int i = 0; i < np; i++)
	{
		r[i].i = i;
		r[i].s = s[i];
	}
	sort(r.begin(), r.end(), cmp);
	ans[r[0].i] = 1;
	for (int i = 1; i < np; i++)
	{
		if (r[i].s == r[i - 1].s) ans[r[i].i] = ans[r[i - 1].i];
		else ans[r[i].i] = i + 1;
	}
	for (int i = 0; i < np; i++)
	{
		if (i > 0) cout << " ";
		cout << ans[i];
	}

	system("pause");
	return 0;
}