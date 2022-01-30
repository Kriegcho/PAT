#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> ans(10001, -1); // 保存鸟对应的树ID，判断题中问句时判断值即可
	vector<vector<int>> adj(N);
	vector<vector<int>> btp(10001);
	for (int i = 0; i < N; i++)
	{
		int K;
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			int t;
			cin >> t;
			adj[i].push_back(t);
			btp[t].push_back(i);
		}
	}
	vector<bool> vp(N, false), vb(10001, false);
	int ind = 0, c = 0; // 其实是统计连通图的数量。广搜即可。
	for (int i = 0; i < N; i++)
	{
		if (!vp[i])
		{
			vp[i] = true;
			queue<int> qp;
			qp.push(i);
			while (!qp.empty())
			{
				for (int j = 0; j < adj[qp.front()].size(); j++)
				{
					if (!vb[adj[qp.front()][j]])
					{
						vb[adj[qp.front()][j]] = true;
						ans[adj[qp.front()][j]] = ind;
						c++;
						for (int k = 0; k < btp[adj[qp.front()][j]].size(); k++)
							if (!vp[btp[adj[qp.front()][j]][k]])
							{
								vp[btp[adj[qp.front()][j]][k]] = true;
								qp.push(btp[adj[qp.front()][j]][k]);
							}
					}
				}
				qp.pop();
			}
			ind++;
		}
	}
	cout << ind << " " << c << endl;
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		if (ans[t1] == ans[t2] && ans[t1] != -1) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	system("pause");
	return 0;
}