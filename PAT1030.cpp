#include <iostream>
#include <vector>
using namespace std;

struct road
{
	int dis, c;
};

int N, M, S, D;
int minl = INT32_MAX, minc = INT32_MAX;
vector<bool> flag; // 访问标志
vector<vector<road*>> adjMatrix; // 邻接矩阵
vector<int> path, temp;

void DFS(int b, int len, int cost)
{
	if (b == D)
	{
		if (len < minl || (len == minl && cost < minc))
		{
			minl = len;
			minc = cost;
			path = temp;
		}
		return;
	}
	for (int i = 0; i < N; i++)
	{
		if (flag[i] == false && adjMatrix[b][i])
		{
			flag[i] = true;
			temp.push_back(i);
			DFS(i, len + adjMatrix[b][i]->dis, cost + adjMatrix[b][i]->c);
			flag[i] = false;
			temp.pop_back();
		}
	}
}

int main()
{
	cin >> N >> M >> S >> D;
	adjMatrix.assign(N, vector<road*>(N));
	flag.assign(N, false);
	for (int i = 0; i < M; i++)
	{
		int b, e;
		cin >> b >> e;
		road* r = new road;
		cin >> r->dis >> r->c;
		adjMatrix[b][e] = r;
		adjMatrix[e][b] = r;
	}
	
	flag[S] = true;
	DFS(S, 0, 0);

	cout << S;
	for (int i = 0; i < path.size(); i++)
	{
		cout << " " << path[i];
	}
	cout << " " << minl << " " << minc;

	system("pause");
	return 0;
}