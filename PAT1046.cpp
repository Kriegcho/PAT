#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> dis(N + 1, 0);
	int sum = 0;
	for (int i = 1; i <= N; i++)
	{
		int t;
		cin >> t;
		sum += t;
		dis[i] = sum;
	}
	int M;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int b, e;
		cin >> b >> e;
		int t = 0;
		if (b < e) t = dis[e - 1] - dis[b - 1];
		else if (b > e) for (int j = e; j < b; j++) t = dis[b - 1] - dis[e - 1];
		if (t < sum / 2) cout << t << endl;
		else cout << sum - t << endl;
	}

	system("pause");
	return 0;
}