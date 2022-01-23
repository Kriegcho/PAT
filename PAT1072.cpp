#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N, M, K, D;
	cin >> N >> M >> K >> D;
	vector<vector<int>> adj(N + M + 1, vector<int>(N + M + 1, 0)); // 邻接矩阵
	vector<vector<int>> mind(M + 1, vector<int>(N + M + 1, 0)); // 最短路径
	for (int i = 0; i < K; i++)
	{
		string s1, s2;
		int n1, n2, d;
		cin >> s1 >> s2 >> d;
		if (s1 != s2)
		{
			if (s1[0] == 'G') n1 = N + stoi(s1.substr(1, s1.length())); // 站点下标+N
			else n1 = stoi(s1);
			if (s2[0] == 'G') n2 = N + stoi(s2.substr(1, s2.length()));
			else n2 = stoi(s2);
			if (adj[n1][n2] > 0 && d > adj[n1][n2]) continue;
			adj[n1][n2] = adj[n2][n1] = d;
		}
	}
	vector<double> mindis(M + 1, INT32_MAX);
	vector<double> sum(M + 1, 0);
	int cnt = 0;
	for (int i = 1; i <= M; i++)
	{
		int ind = i + N, cur = 0;
		vector<bool> f(N + M + 1, false);
		f[ind] = true;
		for (int j = 1; j <= N + M; j++)
		{
			for (int k = 1; k <= N + M; k++)
				if (!f[k] && adj[ind][k])
					if (mind[i][k] == 0 || adj[ind][k] + cur < mind[i][k])
						mind[i][k] = adj[ind][k] + cur;
			int min = INT32_MAX;
			for (int k = 1; k <= N + M; k++)
			{
				if (!f[k] && mind[i][k] > 0 && mind[i][k] < min)
				{
					ind = k;
					min = mind[i][k];
				}
			}
			f[ind] = true;
			cur = min;
		}
		double min = INT32_MAX;
		for (int j = 1; j <= N; j++)
		{
			if (mind[i][j] > 0 && mind[i][j] <= D)
			{
				if (mind[i][j] < mindis[i]) mindis[i] = mind[i][j];
				sum[i] += mind[i][j];
			}
			else
			{
				cnt++;
				mindis[i] = 0;
				sum[i] = 0;
				break;
			}
		}
	}
	if (cnt == M) cout << "No Solution";
	else
	{
		int t = 1;
		for (int i = 1; i <= M; i++)
		{
			if (mindis[i] > mindis[t]) t = i;
			else if (mindis[i] == mindis[t]) if (sum[i] && sum[i] < sum[t]) t = i;
		}
		printf("G%d\n", t);
		double avg = 1.0 * sum[t] / N;
		printf("%.1f %.1f", mindis[t], avg);
	}

	system("pause");
	return 0;
}