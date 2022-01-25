#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
	int N, p;
	cin >> N >> p;
	int max = 0;
	vector<int> d(N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &d[i]);
		if (d[i] > max) max = d[i];
	}
	int t = 0, ans = 0;
	sort(d.begin(), d.end());
	map<int, int> m;
	for (int i = 0; i < N; i++) if (m.find(d[i]) == m.end()) m.insert(make_pair(d[i], i));
	for (int i = N - 1; i >= 0; i--)
	{
		bool f = false;
		t = d[i] / p;
		if (d[i] % p > 0) t++;
		while (m.find(t) == m.end()) t++;
		if (i - m[t] + 1 > ans) ans = i - m[t] + 1;
		if (ans >= i) break;
	}
	cout << ans;

	system("pause");
	return 0;
}