#include <iostream>
#include <set>
using namespace std;

int main()
{
	int N;
	cin >> N;
	set<int> s;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if (t > 0) s.insert(t);
	}
	set<int>::iterator it = s.begin();
	int ans = 1;
	while (it != s.end())
	{
		if (*it != ans) break;
		ans++;
		it++;
	}
	cout << ans;

	system("pause");
	return 0;
}