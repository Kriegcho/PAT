#include <cstdio>
#include <iostream>
#include <climits>
#include <cstring>
using namespace std;

const int maxN = 510;
int nDistanceArr[maxN][maxN];
int city[maxN];
bool bVisitArr[maxN];
int nCity, nRoad, nBegin, nEnd;
long long nMinLength = LLONG_MAX;
int nPathCount, nAnsTeams = 0;

void DFS(int nLength, int nTeams, int nCurCity)
{
	if (nCurCity == nEnd)
	{
		if (nLength > nMinLength)
		{
			return;
		}
		else if (nLength < nMinLength)
		{
			nPathCount = 1;
			nMinLength = nLength;
			nAnsTeams = nTeams;
		}
		else
		{
			nPathCount++;
			if (nAnsTeams < nTeams)
			{
				nAnsTeams = nTeams;
			}
		}
		return;
	}

	if (nLength > nMinLength)
	{
		return;
	}
	for (int i = 0; i < nCity; i++)
	{
		if (nDistanceArr[nCurCity][i] == -1 || bVisitArr[i])
		{
			continue;
		}
		else
		{
			bVisitArr[i] = true;
			DFS(nLength + nDistanceArr[nCurCity][i], nTeams + city[i], i);
			bVisitArr[i] = false;
		}
	}
}

int main()
{
	cin >> nCity;
	cin >> nRoad;
	cin >> nBegin >> nEnd;
	int road1, road2, nLength;
	for (int i = 0; i < nCity; i++)
	{
		cin >> city[i];
	}
	memset(nDistanceArr, -1, sizeof(nDistanceArr));
	memset(bVisitArr, false, sizeof(bVisitArr));
	for (int i = 0; i < nRoad; i++)
	{
		cin >> road1 >> road2 >> nLength;
		nDistanceArr[road1][road2] = nDistanceArr[road2][road1] = nLength;
	}
	bVisitArr[nBegin] = true;
	DFS(0, city[nBegin], nBegin);
	cout << nPathCount << " " << nAnsTeams;
	system("pause");
	return 0;
}