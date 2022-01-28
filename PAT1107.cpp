#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> hobp(1001);
vector<vector<int>> phob;
vector<bool> vh(1001, false);
vector<bool> vp;

void DFS(int pos, int& c)
{
	vh[pos] = true;
	for (int i = 0; i < hobp[pos].size(); i++)
		if (!vp[hobp[pos][i]])
		{
			c++;
			vp[hobp[pos][i]] = true;
			for (int j = 0; j < phob[hobp[pos][i]].size(); j++)
				if (!vh[phob[hobp[pos][i]][j]]) DFS(phob[hobp[pos][i]][j], c);
		}
}

int main()
{
	int N;
	cin >> N;
	phob.resize(N);
	vp.assign(N, false);
	for (int i = 0; i < N; i++)
	{
		int K;
		scanf("%d:", &K);
		for (int j = 0; j < K; j++)
		{
			int t;
			scanf("%d", &t);
			hobp[t].push_back(i);
			phob[i].push_back(t);
		}
	}
	int c = 0;
	vector<int> ans;
	for (int i = 1; i <= 1000; i++)
	{
		if (!vh[i])
		{
			int cnt = 0;
			DFS(i, cnt);
			if (cnt)
			{
				ans.push_back(cnt);
				c++;
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << endl;
	for (int i = ans.size() - 1; i >= 0; i--)
	{
		if (i < ans.size() - 1) cout << " ";
		cout << ans[i];
	}

	system("pause");
	return 0;
}