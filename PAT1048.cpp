#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> cnt(501, 0);
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		cnt[t]++;
	}
	bool f = false;
	for (int i = 1; i <= M / 2; i++)
	{
		if (cnt[i] && M - i < 501 && cnt[M - i]) // 注意边界
		{
			if (i == M - i && cnt[i] == 1) break;
			cout << i << " " << M - i;
			f = true;
			break;
		}
	}
	if (!f) cout << "No Solution";

	system("pause");
	return 0;
}