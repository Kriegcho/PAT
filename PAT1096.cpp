#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	int ans = 1, ansb = N;
	for (int i = 2; i <= sqrt(N); i++) // 这里一开始写的i*i<=N，导致超时（错误）。因为N足够大时，i*i超过了int的范围。
	{
		int t = N, c = 0;
		if (t % i > 0) continue;
		int j = i;
		if (j > ansb && j <= ansb + ans - 1)
		{
			for (int k = j; k <= ansb + ans - 1; k++) t /= k;
			c = ansb + ans - j;
			j = ansb + ans;
		}
		while (t % j == 0 && j <= t)
		{
			t /= j;
			j++;
			c++;
		}
		if (c == 1 && ansb == N) ansb = i;
		else if (c > ans)
		{
			ans = c;
			ansb = i;
		}
	}
	cout << ans << endl;
	cout << ansb;
	for (int i = 1; i < ans; i++) cout << "*" << ansb + i;

	system("pause");
	return 0;
}