#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> f(N + 1);
	for (int i = 1; i <= N; i++) cin >> f[i];
	for (int i = 1; i <= N; i++)
		for (int j = i + 1; j <= N; j++)
		{
			vector<int> lie, ans(N + 1, 1);
			ans[i] = ans[j] = -1; // 枚举，假设i和j是狼，判断说谎的情况是否符合要求。-1为狼，1为平民。
			for (int k = 1; k <= N; k++) if (f[k] * ans[abs(f[k])] < 0) lie.push_back(k);
			if (lie.size() == 2 && ans[lie[0]] + ans[lie[1]] == 0)
			{
				cout << i << " " << j;
				goto final;
			}
		}
	cout << "No Solution";
final:
	system("pause");
	return 0;
}