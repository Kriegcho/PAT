#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> ds(N);
	for (int i = 0; i < N; i++) cin >> ds[i];
	sort(ds.begin(), ds.end());
	int ans = 0;
	for (int i = 0; i < N; i++)
		if (ds[i] > N - i) // 不要求N-i和大于N-i的数个数严格相等。。一开始想多了。这样就AC了。
		{
			ans = N - i;
			break;
		}
	cout << ans;

	system("pause");
	return 0;
}