#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;

struct rec 
{
	rec(int i, int nc) { ind = i; c = nc; }
	int ind, c;
};
auto cmp = [](rec* r1, rec* r2)
{
	if (r1->c == r2->c) return r1->ind < r2->ind;
	return r1->c > r2->c;
};

int main()
{
	int N, K;
	cin >> N >> K;
	set<rec*, decltype(cmp)> rs(cmp);
	map<int, rec*> m;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if (i > 0)
		{
			cout << t << ":";
			int c = 0;
			for (set<rec*>::iterator it = rs.begin(); it != rs.end() && c < K; it++)
			{
				cout << " " << (*it)->ind;
				c++;
			}
			cout << endl;
		}
		if (m.find(t) == m.end())
		{
			rec* p = new rec(t, 1);
			m[t] = p;
			rs.insert(p);
		}
		else
		{
			rs.erase(rs.find(m[t]));
			m[t]->c++; // 这一行不能在erase之前，否则rs.find返回的是end。
			rs.insert(m[t]);
		}
	}

	system("pause");
	return 0;
}