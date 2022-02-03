#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> pre(N), ino(N);
	for (int i = 0; i < N; i++) cin >> pre[i];
	for (int i = 0; i < N; i++) cin >> ino[i];
	int pl = 0, ph = N - 1, ol = 0, oh = N - 1;
	while (1)
	{
		if (pl == ph && ol == oh) break;
		int ind = ol;
		for (int i = ol; i <= oh; i++)
			if (ino[i] == pre[pl])
			{
				ind = i;
				break;
			}
		if (ind == ol)
		{
			ol++;
			pl++;
		}
		else
		{
			pl++;
			oh = ind - 1;
			ph = pl + oh - ol;
		}
	}
	cout << pre[pl];

	system("pause");
	return 0;
}