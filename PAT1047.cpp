#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<vector<string>> cs(K, vector<string>(0));
	for (int i = 0; i < N; i++)
	{
		string s;
		s.resize(4);
		int C;
		scanf("%s %d", &s[0], &C);
		for (int j = 0; j < C; j++)
		{
			int t;
			scanf("%d", &t);
			cs[t - 1].push_back(s);
		}
	}
	for (int i = 0; i < K; i++)
	{
		sort(cs[i].begin(), cs[i].end());
		cout << i + 1 << " " << cs[i].size() << endl;
		for (int j = 0; j < cs[i].size(); j++)
		{
			printf("%s\n", cs[i][j].c_str()); // 使用cout超时
		}
	}

	system("pause");
	return 0;
}