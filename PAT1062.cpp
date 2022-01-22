#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct rec
{
	int id, vg, tg;
};

bool cmp(rec* r1, rec* r2)
{
	if (r1->tg + r1->vg == r2->tg + r2->vg)
	{
		if (r1->vg == r2->vg) return r1->id < r2->id;
		else return r1->vg > r2->vg;
	}
	else return r1->tg + r1->vg > r2->tg + r2->vg;
}

int main()
{
	int N, L, H, cnt = 0;
	cin >> N >> L >> H;
	vector<rec*> s, n, f, o;
	for (int i = 0; i < N; i++)
	{
		rec* p = new rec;
		cin >> p->id >> p->vg >> p->tg;
		if (p->tg >= L && p->vg >= L)
		{
			if (p->tg >= H && p->vg >= H) s.push_back(p);
			else if (p->vg >= H) n.push_back(p);
			else if (p->vg >= p->tg) f.push_back(p);
			else o.push_back(p);
			cnt++;
		}
	}
	sort(s.begin(), s.end(), cmp);
	sort(n.begin(), n.end(), cmp);
	sort(f.begin(), f.end(), cmp);
	sort(o.begin(), o.end(), cmp);
	cout << cnt << endl;
	for (int i = 0; i < s.size(); i++) cout << s[i]->id << " " << s[i]->vg << " " << s[i]->tg << endl;
	for (int i = 0; i < n.size(); i++) cout << n[i]->id << " " << n[i]->vg << " " << n[i]->tg << endl;
	for (int i = 0; i < f.size(); i++) cout << f[i]->id << " " << f[i]->vg << " " << f[i]->tg << endl;
	for (int i = 0; i < o.size(); i++) cout << o[i]->id << " " << o[i]->vg << " " << o[i]->tg << endl;

	system("pause");
	return 0;
}