#include "iostream"
#include "vector"
#include "queue"
#include "string"
#include "cstdio"
#include "algorithm"
using namespace std;

struct Custom
{
	int nArriveTime;
	int nProcessTime;
	int nLeftTime;
};

typedef vector<Custom*> VectorCustom;
typedef queue<Custom*> QueueCustom;

int GetTimeInt(string strTime)
{
	return stoi(strTime.substr(0, 2)) * 3600 + stoi(strTime.substr(3, 2)) * 60 + stoi(strTime.substr(6, 2));
}

bool timeCmp(Custom* pCustom1, Custom* pCustom2)
{
	return pCustom1->nArriveTime < pCustom2->nArriveTime;
}

int GetVectorMin(vector<int> vct)
{
	int nMin = vct[0], nIndex = 0;
	for (int i = 1; i < vct.size(); i++)
	{
		if (vct[i] < nMin)
		{
			nMin = vct[i];
			nIndex = i;
		}
	}
	return nIndex;
}

const int nStartTime = 8 * 3600;
const int nEndTime = 17 * 3600;

int main()
{
	int nCustoms, nWindows;
	cin >> nCustoms >> nWindows;
	VectorCustom vctCustom;
	int nTotalTime = 0;
	for (int i = 0; i < nCustoms; i++)
	{
		Custom* pCustom = new Custom;
		string strTime;
		int nTime;
		cin >> strTime >> nTime;
		pCustom->nArriveTime = GetTimeInt(strTime);
		pCustom->nProcessTime = nTime * 60;
		pCustom->nLeftTime = pCustom->nProcessTime + max(pCustom->nArriveTime, nStartTime);
		if (pCustom->nArriveTime <= nEndTime)
		{
			vctCustom.push_back(pCustom);
		}
		if (pCustom->nArriveTime < nStartTime)
		{
			nTotalTime += nStartTime - pCustom->nArriveTime;
		}
	}
	if (vctCustom.size() > nWindows)
	{
		sort(vctCustom.begin(), vctCustom.end(), timeCmp);
		QueueCustom qCustom;
		vector<int> vctFinishTime;
		for (int i = 0; i < vctCustom.size(); i++)
		{
			qCustom.push(vctCustom[i]);
		}
		for (int i = 0; i < nWindows; i++)
		{
			vctFinishTime.push_back(vctCustom[i]->nLeftTime);
			qCustom.pop();
		}
		if (nWindows > 0)
		{
			while (!qCustom.empty())
			{
				int nIndex = GetVectorMin(vctFinishTime);
				if (qCustom.front()->nArriveTime < vctFinishTime[nIndex])
				{
					nTotalTime += vctFinishTime[nIndex] - max(qCustom.front()->nArriveTime, nStartTime);
					qCustom.front()->nLeftTime = vctFinishTime[nIndex] + qCustom.front()->nProcessTime;
				}
				vctFinishTime[nIndex] = qCustom.front()->nLeftTime;
				qCustom.pop();
			}
		}
	}
	int nSize = vctCustom.size();
	for (int i = 0; i < nSize; i++)
	{
		if (vctCustom[i])
		{
			delete vctCustom[i];
			vctCustom[i] = NULL;
		}
	}
	vctCustom.clear();
	double dMin = double(nTotalTime) / 60;
	if (nSize > 0)
	{
		printf("%.1f", dMin / nSize);
	}
	else
	{
		cout << "0.0";
	}
	system("pause");
	return 0;
}