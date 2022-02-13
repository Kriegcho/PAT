#include <iostream>
#include <vector>
#include <set>
using namespace std;
// 本题跟1142一样。。只多要求输出缺少的最小元素
int main()
{
	int N, M, K;
	cin >> N >> M;
	vector<vector<int>> adj(N + 1, vector<int>(N + 1, 0));
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		adj[a][b] = adj[b][a] = 1;
	}
	cin >> K;
	for (int i = 1; i <= K; i++)
	{
		int L, fir, type = 0; // 0 OK 1 more 2 help;
		cin >> L;
		set<int> ms, fs;
		cin >> fir;
		for (int j = 1; j <= N; j++)
		{
			if (adj[fir][j])
			{
				ms.insert(j);
				fs.insert(j);
			}
			else if (j == fir) ms.insert(j);
		}
		for (int j = 1; j < L; j++)
		{
			int t;
			cin >> t;
			if (ms.find(t) == ms.end()) type = 2; // 不在集合中则不满足关系
			else if (type != 2)
			{
				fs.erase(fs.find(t));
				set<int>::iterator it = ms.begin();
				while (it != ms.end())
				{
					if (j == 1)
					{
						if (t != *it && !adj[t][*it])
						{
							fs.erase(fs.find(*it));
							it = ms.erase(it); // 去掉不满足关系的点
						}
						else it++;
					}
					else if (t != *it && !adj[t][*it])
					{
						type = 2;
						break;
					}
					else it++;
				}
			}
		}
		if (type != 2 && !fs.empty()) type = 1;
		if (type == 0) cout << "Area " << i << " is OK." << endl;
		else if (type == 1) cout << "Area " << i << " may invite more people, such as " << *fs.begin() << "." << endl;
		else if (type == 2) cout << "Area " << i << " needs help." << endl;
	}

	system("pause");
	return 0;
}