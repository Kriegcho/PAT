#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct rec 
{
	double a, p, o;
};

bool cmp(rec r1, rec r2)
{
	return r1.o > r2.o;
}

int main()
{
	int N, D;
	cin >> N >> D;
	vector<rec> rs(N);
	for (int i = 0; i < N; i++) cin >> rs[i].a;
	for (int i = 0; i < N; i++) cin >> rs[i].p;
	for (int i = 0; i < N; i++) rs[i].o = 1.0 * rs[i].p / rs[i].a;
	sort(rs.begin(), rs.end(), cmp);
	double ans = 0;
	int t = 0;
	for (int i = 0; i < N; i++)
	{
		if (t + rs[i].a < D)
		{
			ans += rs[i].p;
			t += rs[i].a;
		}
		else
		{
			ans += 1.0 * rs[i].p * (D - t) / rs[i].a;
			break;
		}
	}
	printf("%.2f", ans);

	system("pause");
	return 0;
}