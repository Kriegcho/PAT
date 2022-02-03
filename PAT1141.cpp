#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
using namespace std;

struct rec
{
	rec(string sid) { id = sid; c = 0; s = 0; ds = 0; }
	void updates() { s = ds; }
	string id;
	double ds;
	int c, s;
};

bool cmp(rec* r1, rec* r2)
{
	if (r1->s == r2->s)
		if (r1->c == r2->c) return r1->id < r2->id;
		else return r1->c < r2->c;
	else return r1->s > r2->s;
}

int main()
{
	int N;
	cin >> N;
	map<string, rec*> m;
	vector<rec*> ans;
	for (int i = 0; i < N; i++)
	{
		string t, id;
		int s;
		cin >> t >> s >> id;
		transform(id.begin(), id.end(), id.begin(), ::tolower);
		if (m.find(id) == m.end())
		{
			rec* p = new rec(id);
			m[id] = p;
			ans.push_back(p);
		}
		switch (t[0])
		{
		case 'A':
			m[id]->ds += s;
			break;
		case 'B':
			m[id]->ds += 1.0 * s / 1.5;
			break;
		case 'T':
			m[id]->ds += 1.5 * s;
			break;
		}
		m[id]->c++;
		m[id]->updates();
	}
	sort(ans.begin(), ans.end(), cmp);
	cout << ans.size() << endl;
	int r = 1;
	for (int i = 0; i < ans.size(); i++)
	{
		if (i > 0 && ans[i]->s != ans[i - 1]->s) r = i + 1;
		cout << r << " " << ans[i]->id << " " << ans[i]->s << " " << ans[i]->c << endl;
	}

	system("pause");
	return 0;
}