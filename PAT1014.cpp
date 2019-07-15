#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

const int nTotalTime = 540;
const int maxN = 1010;
int arrFinishTime[maxN] = { 0 }; // 记录每个人完成时间

int GetMinTime(vector<int> vct)
{
	int nMinTime = INT_MAX;
	for (int i = 0; i < vct.size(); i++)
	{
		if ((vct[i] != 0) && (vct[i] < nMinTime)) // 0表示该窗口已无人等待
		{
			nMinTime = vct[i];
		}
	}
	return nMinTime;
}

int main()
{
	int nWindows, nLineLength, nCustoms, nAsks;
	cin >> nWindows >> nLineLength >> nCustoms >> nAsks;
	vector<int> vctTimeCost; // 每个人消耗的时间
	queue<int> qWait; // 全体等待队列
	vector<bool> vctFinish; // 已完成队列
	for (int i = 0; i < nCustoms; i++)
	{
		int nTimeCost;
		scanf("%d", &nTimeCost);
		vctTimeCost.push_back(nTimeCost);
		vctFinish.push_back(false);
		qWait.push(i);
	}
	vector<queue<int>> vctLines; // 每一窗口的等待队列
	for (int i = 0; i < nWindows; i++)
	{
		queue<int> qLines;
		vctLines.push_back(qLines);
	}
	// 最开始黄线内队列
	for (int i = 0; i < min(nWindows*nLineLength, nCustoms); i++)
	{
		vctLines[i%nWindows].push(i);
		qWait.pop();
	}
	// 处理队容量为0的情况
	if (nLineLength == 0)
	{
		for (int i = 0; i < min(nWindows, nCustoms); i++)
		{
			vctLines[i%nWindows].push(i);
			qWait.pop();
		}
	}
	// 按轮次计算，每一轮找到第一排最短时间，将后续等待者安排插入
	int nFinishCustoms = 0; // 已完成人数
	vector<int> vctServeTime; // 每个窗口第一个人的服务时间
	for (int i = 0; i < min(nWindows, nCustoms); i++) // 要注意顾客数小于窗口数的情况
	{
		vctServeTime.push_back(vctTimeCost[vctLines[i].front()]);
	}
	// 先保存输入
	vector<int> vctAsk;
	for (int i = 0; i < nAsks; i++)
	{
		int nAskIndex;
		scanf("%d", &nAskIndex);
		vctAsk.push_back(nAskIndex - 1);
	}
	int nCostTime = 0;
	while (nFinishCustoms < nCustoms && (nCostTime < nTotalTime))
	// nFinishCustoms < nCustoms && (nCostTime < nTotalTime) 
	// 这个条件其实不严谨，因为刚好到点时还有在排队的人的输出就错误了，应该再判断
	{
		int nTime = GetMinTime(vctServeTime);
		nCostTime += nTime;
		// 结算剩余人的时间
		for (int j = 0; j < nCustoms; j++)
		{
			if (!vctFinish[j])
			{
				arrFinishTime[j] += nTime;
			}
		}
		// 窗口结算
		for (int i = 0; i < nWindows; i++)
		{
			if (vctLines[i].empty()) // 此窗口已空
			{
				continue;
			}
			vctServeTime[i] -= nTime;
			// 此时，此窗口已有一人完成
			if (vctServeTime[i] == 0)
			{
				vctFinish[vctLines[i].front()] = true;
				vctLines[i].pop();
				nFinishCustoms++;
				// 安排新的人进入
				if (!qWait.empty())
				{
					vctLines[i].push(qWait.front());
					qWait.pop();
				}
				// 重置第一排时间
				if (!vctLines[i].empty())
				{
					vctServeTime[i] = vctTimeCost[vctLines[i].front()];
				}
			}
		}
	}
	// 这里是特殊案例，刚好到点，还有人没处理完
	if (nCostTime == nTotalTime)
	{
		for (int i = 0; i < nWindows; i++)
		{
			if (vctLines[i].empty())
			{
				continue;
			}
			if (vctServeTime[i] < vctTimeCost[vctLines[i].front()])
			{
				vctFinish[vctLines[i].front()] = true;
				arrFinishTime[vctLines[i].front()] += vctServeTime[i];
			}
		}
	}
	for (int i = 0; i < nAsks; i++)
	{
		if (vctAsk[i] < nCustoms && vctFinish[vctAsk[i]])
		{
			int nHours = arrFinishTime[vctAsk[i]] / 60;
			int nMinutes = arrFinishTime[vctAsk[i]] % 60;
			printf("%02d:%02d\n", 8 + nHours, nMinutes);
		}
		else
		{
			cout << "Sorry" << endl;
		}
	}
	system("pause");
	return 0;
}