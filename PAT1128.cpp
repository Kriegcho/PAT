#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int N;
		cin >> N;
		bool flag = true;
		vector<vector<bool>> f(N, vector<bool>(N, false));
		for (int j = 0; j < N; j++)
		{
			int t;
			cin >> t;
			if (f[j][t - 1]) flag = false;
			if (flag)
				for (int k = j + 1; k < N; k++)
				{
					f[k][t - 1] = true;
					if ((k - j) + t - 1 < N) f[k][(k - j) + t - 1] = true;
					if (t - 1 - (k - j) >= 0) f[k][t - 1 - (k - j)] = true;
				}
		}
		cout << (flag ? "YES" : "NO") << endl;
	}

	system("pause");
	return 0;
}