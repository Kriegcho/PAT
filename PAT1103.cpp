#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N, K, P, maxs = 0;
vector<int> pi, ans, temp;
void DFS(int ind, int sum, int fs, int dep)
{
	if (sum == N)
	{
		if (dep == K && fs > maxs)
		{
			maxs = fs;
			ans = temp;
		}
		temp.pop_back();
		return;
	}
	else
	{
		for (int i = ind; i >= 1; i--)
			if (sum + pi[i] <= N && dep + 1 <= K)
			{
				temp.push_back(i);
				DFS(i, sum + pi[i], fs + i, dep + 1);
			}
		if (!temp.empty()) temp.pop_back();
	}
}

int main()
{
	cin >> N >> K >> P;
	for (int i = 0; pow(i, P) <= N; i++)
	{
		pi.push_back(pow(i, P));
	}
	DFS(pi.size() - 1, 0, 0, 0);
	if (ans.empty()) cout << "Impossible";
	else
	{
		printf("%d = %d^%d", N, ans[0], P);
		for (int i = 1; i < ans.size(); i++)
			printf(" + %d^%d", ans[i], P);
	}

	system("pause");
	return 0;
}