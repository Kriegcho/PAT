#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

struct rec
{
	string id;
	int gp = 0, gm = -1, gf = 0, fs = 0;
	void calcgf()
	{
		if (gf < gm)
		{
			double d = 0.4 * gm + 0.6* gf + 0.5; // +0.5处理四舍五入
			fs = d;
		}
		else fs = gf;
	}
	bool pass()
	{
		if (gp >= 200 && fs >= 60) return true;
		else return false;
	}
};

bool cmp(rec* r1, rec* r2)
{
	if (r1->fs == r2->fs) return r1->id < r2->id;
	return r1->fs > r2->fs;
}

int main()
{
	map<string, rec*> m;
	vector<rec*> ans;
	int P, M, N;
	cin >> P >> M >> N;
	for (int i = 0; i < P; i++)
	{
		string id;
		int s;
		cin >> id >> s;
		if (m.find(id) == m.end())
		{
			rec* p = new rec;
			p->id = id;
			p->gp = s;
			m[id] = p;
		}
	}
	for (int i = 0; i < M; i++)
	{
		string id;
		int s;
		cin >> id >> s;
		if (m.find(id) == m.end())
		{
			rec* p = new rec;
			p->id = id;
			p->gm = s;
			m[id] = p;
		}
		else m[id]->gm = s;
	}
	for (int i = 0; i < N; i++)
	{
		string id;
		int s;
		cin >> id >> s;
		if (m.find(id) == m.end())
		{
			rec* p = new rec;
			p->id = id;
			p->gp = s;
			m[id] = p;
		}
		else m[id]->gf = s;
		m[id]->calcgf();
		if (m[id]->pass()) ans.push_back(m[id]);
	}
	sort(ans.begin(), ans.end(), cmp);
	for (int i = 0; i < ans.size(); i++) cout << ans[i]->id << " " << ans[i]->gp << " " << ans[i]->gm << " " << ans[i]->gf << " " << ans[i]->fs << endl;

	system("pause");
	return 0;
}