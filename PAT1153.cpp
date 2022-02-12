#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

struct rec
{
	string id, date, ssite;
	int s;
};
struct site
{
	string id;
	int nt;
};
bool cmp1(rec* r1, rec* r2) { return (r1->s == r2->s ? r1->id < r2->id : r1->s > r2->s); }
bool cmp3(site* r1, site* r2) { return (r1->nt == r2->nt ? r1->id < r2->id : r1->nt > r2->nt); }

int main()
{
	int N, M;
	cin >> N >> M;
	vector<rec*> ds(N);
	for (int i = 0; i < N; i++)
	{
		ds[i] = new rec;
		cin >> ds[i]->id >> ds[i]->s;
		ds[i]->date = ds[i]->id.substr(4, 6);
		ds[i]->ssite = ds[i]->id.substr(1, 3);
	}
	sort(ds.begin(), ds.end(), cmp1);
	map<string, vector<site*>> m3;
	for (int i = 1; i <= M; i++)
	{
		int type;
		string term;
		cin >> type >> term;
		cout << "Case " << i << ": " << type << " " << term << endl;
		switch (type)
		{
		case 1:
		{
			bool f = false;
			for (int j = 0; j < N; j++)
				if (ds[j]->id.substr(0, 1) == term)
				{
					f = true;
					cout << ds[j]->id << " " << ds[j]->s << endl;
				}
			if (!f) cout << "NA" << endl;
		}
			break;
		case 2:
		{
			int ts = 0, c = 0;
			for (int j = 0; j < N; j++)
				if (ds[j]->ssite == term)
				{
					ts += ds[j]->s;
					c++;
				}
			if (c) cout << c << " " << ts << endl;
			else cout << "NA" << endl;
		}
			break;
		case 3:
		{
			map<string, site*> m;
			vector<site*> ans3;
			if (m3.find(term) == m3.end())
			{
				for (int j = 0; j < N; j++)
					if (ds[j]->date == term)
						if (m.find(ds[j]->ssite) == m.end())
						{
							site* p = new site;
							p->id = ds[j]->ssite;
							p->nt = 1;
							m[ds[j]->ssite] = p;
							ans3.push_back(p);
						}
						else m[ds[j]->ssite]->nt++;
						m3[term] = ans3;
			}
			else ans3 = m3[term];
			sort(ans3.begin(), ans3.end(), cmp3);
			for (int j = 0; j < ans3.size(); j++) cout << ans3[j]->id << " " << ans3[j]->nt << endl;
			if (ans3.empty()) cout << "NA" << endl;
		}
			break;
		}
	}

	system("pause");
	return 0;
}