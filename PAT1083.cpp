#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct rec
{
	string n, c;
	int g;
};

bool cmp(rec r1, rec r2) { return r1.g > r2.g; }

int main()
{
	int N;
	cin >> N;
	vector<rec> rs(N);
	for (int i = 0; i < N; i++) cin >> rs[i].n >> rs[i].c >> rs[i].g;
	sort(rs.begin(), rs.end(), cmp);
	int l, h;
	cin >> l >> h;
	bool f = true;
	for (int i = 0; i < N; i++)
	{
		if (rs[i].g <= h)
		{
			if (rs[i].g >= l)
			{
				cout << rs[i].n << " " << rs[i].c << endl;
				f = false;
			}
			else break;
		}
	}
	if (f) cout << "NONE";

	system("pause");
	return 0;
}