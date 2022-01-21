#include <iostream>
using namespace std;

int main()
{
	int M, N;
	cin >> M >> N;
	int cnt = 0, cur = 0;
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int t;
			cin >> t;
			if (t == cur) cnt++;
			else
			{
				if (cnt > 0) cnt--;
				else cur = t;
			}
		}
	}
	cout << cur;

	system("pause");
	return 0;
}