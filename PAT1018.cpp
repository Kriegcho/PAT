﻿#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int C, N, S, M;
vector<int> current;	//每个车站当前拥有车辆数
vector<vector<int> > adjMatrix;	//邻接矩阵
vector<bool> reach; //是否已经遍历过该点
int minTake, minBack, minLen;	//最少带出的，最少带回的，最短路程
vector<int> ans, temp;	//ans代表最终的最短路程，temp用于暂存每次遍历的路程并计算出ans

void DFS(int s, int take, int back, int length)
{
	if (s == S)	//遍历到出问题的站点
	{
		if (length < minLen || (length == minLen && take < minTake) ||
			(length == minLen && take == minTake && back < minBack))	//满足题目中给出的最短路径条件
		{
			ans = temp;	//记录当前经过的路程为结果路程
			minLen = length;	//更新各项指标
			minTake = take;
			minBack = back;
		}
		return;
	}
	for (int i = 1; i < N + 1; i++)
	{
		if (reach[i] == false && adjMatrix[s][i] != 0)  //没有遍历过i点且s和i有路连接
		{
			reach[i] = true;
			temp.push_back(i);	//将i点计入路程经过的点
			int addTake = max(C / 2 - current[i], 0);	//需要增加的带出的车辆数量。如果i点数量比C/2大，则不用增加，如果比C/2下，则需要增加
			if (back > 0)
				addTake = max(0, addTake - back);	//如果有带回的，则和带出的相抵消。如果带回的比带出的多，则新增带出为0
			int newBack = max(back + current[i] - C / 2, 0);	//新增带回的车数量
			DFS(i, take + addTake, newBack, length + adjMatrix[s][i]);  //对i点进行深度遍历
			reach[i] = false;   //遍历完成后删除i点的访问记录
			temp.pop_back();	//弹出当前经过路径中的i点，准备遍历下一个点
		}
	}
}

int main()
{
	cin >> C >> N >> S >> M;
	current.resize(N + 1);
	adjMatrix.assign(N + 1, vector<int>(N + 1));
	reach.assign(N + 1, false);
	for (int i = 1; i < N + 1; i++)
	{
		cin >> current[i];
	}
	for (int i = 0; i < M; i++)
	{
		int s1, s2, time;
		cin >> s1 >> s2 >> time;
		adjMatrix[s1][s2] = adjMatrix[s2][s1] = time;
	}
	minTake = minBack = minLen = 100000000;
	DFS(0, 0, 0, 0);
	printf("%d 0", minTake);
	for (int i = 0; i < ans.size(); i++) {
		printf("->%d", ans[i]);
	}
	printf(" %d", minBack);
	system("pause");
	return 0;
}