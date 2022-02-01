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
	double ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans += ds[i];
		if (i > 0) ans /= 2;
	}
	int ansd = ans;
	cout << ansd;

	system("pause");
	return 0;
}