#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<set<int>> adjv(N + 1); // 将有向图反向保存，判断拓扑序列只需判断其反向集合是否为空
	for (int i = 0; i < M; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		adjv[t2].insert(t1);
	}
	int K;
	bool f = false;
	cin >> K;
	vector<int> ans;
	for (int i = 0; i < K; i++)
	{
		vector<set<int>> adjtv = adjv;
		bool f = true;
		for (int j = 0; j < N; j++)
		{
			int t;
			cin >> t;
			if (f)
				if (!adjtv[t].empty()) f = false;
				else for (int k = 1; k <= N; k++) if (adjtv[k].find(t) != adjtv[k].end()) adjtv[k].erase(adjtv[k].find(t)); // 每过一个点就去掉这个点为起点的边
		}
		if (!f) ans.push_back(i);
	}
	for (int i = 0; i < ans.size(); i++)
	{
		if (i > 0) cout << " ";
		cout << ans[i];
	}

	system("pause");
	return 0;
}