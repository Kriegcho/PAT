#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> flag, ord, seq;

int main()
{
	int N, M, L;
	cin >> N >> M;
	flag.assign(N, 0);
	ord.resize(M);
	for (int i = 0; i < M; i++)
	{
		cin >> ord[i];
		flag[ord[i] - 1]++;
	}
	cin >> L;
	for (int i = 0; i < L; i++)
	{
		int t;
		cin >> t;
		if (flag[t - 1]) seq.push_back(t);
	}
	// dp[i][j]表示在ord中以i为下标的颜色结尾，在seq[<=j]中满足ord[<=i]序列的子串长度
	// 状态转移方程： dp[i][j] = max(dp[i-1][j]， dp[i]][j-1]]);
	// dp[i-1][j]表示在seq[<=j]中相等的情况下，ord的下标向后移动一位，可能使子串长度发生改变
	// dp[i][j-1]表示在ord[<=i]中相等的情况下，seq的下标向后移动一位，可能使子串长度发生改变
	vector<vector<int>> dp(M + 1, vector<int>(seq.size() + 1, 0));
	for (int i = 1; i <= M; ++i)
	{
		for (int j = 1; j <= seq.size(); ++j)
		{
			dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			if (ord[i - 1] == seq[j - 1]) dp[i][j]++; // 子串长度改变
		}
	}
	cout << dp[M][seq.size()] << endl;

	system("pause");
	return 0;
}