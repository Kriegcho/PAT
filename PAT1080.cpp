#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct stu
{
	vector<int> pref;
	int ind, ge, gi;
};

bool cmp(stu s1, stu s2)
{
	if (s1.ge + s1.gi == s2.ge + s2.gi) return s1.ge > s2.ge;
	else return s1.ge + s1.gi > s2.ge + s2.gi;
}

int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	vector<int> q(M);
	vector<vector<int>> ans(M);
	vector<stu> sts(N);
	for (int i = 0; i < M; i++) cin >> q[i];
	for (int i = 0; i < N; i++)
	{
		cin >> sts[i].ge >> sts[i].gi;
		sts[i].ind = i;
		for (int j = 0; j < K; j++)
		{
			int t;
			cin >> t;
			sts[i].pref.push_back(t);
		}
	}
	vector<stu> ori = sts; // 保存一份原始数据
	sort(sts.begin(), sts.end(), cmp);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			if (q[sts[i].pref[j]] > 0)
			{
				ans[sts[i].pref[j]].push_back(sts[i].ind);
				q[sts[i].pref[j]]--;
				break;
			}
			else if (!ans[sts[i].pref[j]].empty()
				&& sts[i].ge == ori[ans[sts[i].pref[j]][ans[sts[i].pref[j]].size() - 1]].ge
				&& sts[i].gi == ori[ans[sts[i].pref[j]][ans[sts[i].pref[j]].size() - 1]].gi) // 比较同分时要注意下标问题。。测试点1、2
			{
				ans[sts[i].pref[j]].push_back(sts[i].ind); // 同分录取
				break;
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		sort(ans[i].begin(), ans[i].end());
		for (int j = 0; j < ans[i].size(); j++)
		{
			if (j > 0) cout << " ";
			cout << ans[i][j];
		}
		cout << endl;
	}

	system("pause");
	return 0;
}