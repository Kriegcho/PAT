#include <iostream>
#include <vector>
using namespace std;

bool isprime(int n)
{
	if (n == 1) return false;
	for (int i = 2; i*i <= n; i++) if (n % i == 0) return false;
	return true;
}

int main()
{
	int Ms, N, M;
	cin >> Ms >> N >> M;
	while (!isprime(Ms)) Ms++;
	vector<int> h(Ms, -1);
	for (int i = 0; i < N; i++)
	{
		int t, tm;
		cin >> t;
		bool f = true;
		for (int j = 0; j < Ms; j++)
		{
			tm = (t + j * j) % Ms;
			if (h[tm] == -1)
			{
				h[tm] = t;
				f = false;
				break;
			}
		}
		if (f) cout << t << " cannot be inserted." << endl;
	}
	int TST = 0;
	for (int i = 0; i < M; i++)
	{
		int sl = 0, t, tm;
		cin >> t;
		for (int j = 0; j <= Ms; j++)
		{
			sl++;
			tm = (t + j * j) % Ms;
			if (h[tm] == t || h[tm] == -1) break;
		}
		TST += sl;
	}
	double AST = 1.0 * TST / M;
	printf("%.1f", AST);

	system("pause");
	return 0;
}