#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 这题有点意思，初看起来是遍历的题，找到度的关系就好做了
// 思路：满足题目要求的一个序列，其特征：序列中所有结点的度之和（要减掉重复计算的度，即序列中两两相邻的边）等于图的边数。
// 注意：本题时间、空间要求，使用邻接矩阵会超内存，后面计算度的时候直接遍历肯定超时了。
int main()
{
	int N, M;
	cin >> N >> M;
	vector<vector<int>> adj(N); // 一开始为了方便查找是否重复边，使用了邻接矩阵，超内存
	for (int i = 0; i < M; i++)
	{
		int v1, v2;
		cin >> v1 >> v2;
		adj[v1].push_back(v2);
		adj[v2].push_back(v1);
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int n, degree = 0;
		cin >> n;
		vector<int> q(n);
		map<int, int> m;
		for (int j = 0; j < n; j++)
		{
			cin >> q[j];
			degree += adj[q[j]].size(); // 下面去除重复边时，一开始两两循环判断，果断超时了
			if (m.find(q[j]) != m.end()) degree -= m[q[j]]; // 这里计算重复度的方法是使用map记录需要减掉的边数
			for (int k = 0; k < adj[q[j]].size(); k++) // 计算需要减掉的重复边。
				if (m.find(adj[q[j]][k]) != m.end()) m[adj[q[j]][k]]++;
				else m[adj[q[j]][k]] = 1;
		}
		if (degree == M) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	system("pause");
	return 0;
}