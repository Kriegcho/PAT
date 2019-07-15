#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

const int nTotalTime = 540;
const int maxN = 1010;
int arrFinishTime[maxN] = { 0 }; // ��¼ÿ�������ʱ��

int GetMinTime(vector<int> vct)
{
	int nMinTime = INT_MAX;
	for (int i = 0; i < vct.size(); i++)
	{
		if ((vct[i] != 0) && (vct[i] < nMinTime)) // 0��ʾ�ô��������˵ȴ�
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
	vector<int> vctTimeCost; // ÿ�������ĵ�ʱ��
	queue<int> qWait; // ȫ��ȴ�����
	vector<bool> vctFinish; // ����ɶ���
	for (int i = 0; i < nCustoms; i++)
	{
		int nTimeCost;
		scanf("%d", &nTimeCost);
		vctTimeCost.push_back(nTimeCost);
		vctFinish.push_back(false);
		qWait.push(i);
	}
	vector<queue<int>> vctLines; // ÿһ���ڵĵȴ�����
	for (int i = 0; i < nWindows; i++)
	{
		queue<int> qLines;
		vctLines.push_back(qLines);
	}
	// �ʼ�����ڶ���
	for (int i = 0; i < min(nWindows*nLineLength, nCustoms); i++)
	{
		vctLines[i%nWindows].push(i);
		qWait.pop();
	}
	// ���������Ϊ0�����
	if (nLineLength == 0)
	{
		for (int i = 0; i < min(nWindows, nCustoms); i++)
		{
			vctLines[i%nWindows].push(i);
			qWait.pop();
		}
	}
	// ���ִμ��㣬ÿһ���ҵ���һ�����ʱ�䣬�������ȴ��߰��Ų���
	int nFinishCustoms = 0; // ���������
	vector<int> vctServeTime; // ÿ�����ڵ�һ���˵ķ���ʱ��
	for (int i = 0; i < min(nWindows, nCustoms); i++) // Ҫע��˿���С�ڴ����������
	{
		vctServeTime.push_back(vctTimeCost[vctLines[i].front()]);
	}
	// �ȱ�������
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
	// ���������ʵ���Ͻ�����Ϊ�պõ���ʱ�������Ŷӵ��˵�����ʹ����ˣ�Ӧ�����ж�
	{
		int nTime = GetMinTime(vctServeTime);
		nCostTime += nTime;
		// ����ʣ���˵�ʱ��
		for (int j = 0; j < nCustoms; j++)
		{
			if (!vctFinish[j])
			{
				arrFinishTime[j] += nTime;
			}
		}
		// ���ڽ���
		for (int i = 0; i < nWindows; i++)
		{
			if (vctLines[i].empty()) // �˴����ѿ�
			{
				continue;
			}
			vctServeTime[i] -= nTime;
			// ��ʱ���˴�������һ�����
			if (vctServeTime[i] == 0)
			{
				vctFinish[vctLines[i].front()] = true;
				vctLines[i].pop();
				nFinishCustoms++;
				// �����µ��˽���
				if (!qWait.empty())
				{
					vctLines[i].push(qWait.front());
					qWait.pop();
				}
				// ���õ�һ��ʱ��
				if (!vctLines[i].empty())
				{
					vctServeTime[i] = vctTimeCost[vctLines[i].front()];
				}
			}
		}
	}
	// ���������ⰸ�����պõ��㣬������û������
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