#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> d(N);
	for (int i = 0; i < N; i++) cin >> d[i];
	sort(d.begin(), d.end());
	int m, n = sqrt(N);
	while (N % n > 0) n--;
	m = N / n;
	vector<vector<int >> ans(m, vector<int>(n));
	int ind = N - 1;
	for (int i = m, j = n; i >= 1 && j >= 1; i -= 2, j -= 2)
	{
		if (i == 1 && j == 1)
		{
			ans[(m - i) / 2][(n - j) / 2] = d[ind];
			break;
		}
		for (int k = 0; k < j - 1; k++)
		{
			ans[(m - i) / 2][(n - j) / 2 + k] = d[ind];
			ind--;
			if (ind < 0) break;
		}
		if (ind < 0) break;
		for (int k = j - 1; k < i + j - 2; k++)
		{
			ans[(m - i) / 2 + k - (j - 1)][(n - j) / 2 + j - 1] = d[ind];
			ind--;
			if (ind < 0) break;
		}
		if (ind < 0) break;
		for (int k = i + j - 2; k < i + j * 2 - 3; k++)
		{
			ans[m - 1 - (m - i) / 2][n - 1 - (n - j) / 2 - (k - (i + j - 2))] = d[ind];
			ind--;
			if (ind < 0) break;
		}
		if (ind < 0) break;
		for (int k = i + j * 2 - 3; k < i * 2 + j * 2 - 4; k++)
		{
			ans[m - 1 - (m - i) / 2 - (k - (i + j * 2 - 3))][(n - j) / 2] = d[ind];
			ind--;
			if (ind < 0) break;
		}
		if (ind < 0) break;
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j > 0) cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}