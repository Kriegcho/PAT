#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> d(N), ma(N), mi(N);
	int max = 0, min = INT32_MAX;
	for (int i = 0; i < N; i++)
	{
		cin >> d[i];
		if (d[i] > max) max = d[i];
		ma[i] = max;
	}
	for (int i = N - 1; i >= 0; i--)
	{
		if (d[i] < min) min = d[i];
		mi[i] = min;
	}
	vector<int> ans;
	for (int i = 0; i < N; i++)
		if (d[i] >= ma[i] && d[i] <= mi[i]) ans.push_back(d[i]);
	cout << ans.size() << endl;
	if (!ans.empty())
	{
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++)
		{
			if (i > 0) cout << " ";
			cout << ans[i];
		}
	}
	else cout << endl; // 测试点2。。不输出这个换行格式错误。。

	system("pause");
	return 0;
}