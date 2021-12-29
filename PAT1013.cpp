#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
using namespace std;

const int maxN = 1010;

int main()
{
	int nCity, nRoads, nConcernCitys;
	cin >> nCity >> nRoads >> nConcernCitys;
	int arrOrigin[maxN][maxN] = { 0 };
	bool bVisited[maxN] = { false };
	for (int i = 0; i < nRoads; i++)
	{
		int nL, nR;
		scanf("%d%d", &nL, &nR);
		arrOrigin[nL - 1][nR - 1] = arrOrigin[nR - 1][nL - 1] = 1;
	}
	for (int i = 0; i < nConcernCitys; i++)
	{
		int nConcern;
		cin >> nConcern;
		int arr[maxN][maxN];
		memcpy((char*)arr,(char*)arrOrigin, maxN*maxN * sizeof(int));
		bVisited[nConcern - 1] = true;
		for (int j = 0; j < nCity; j++)
		{
			arr[nConcern - 1][j] = arr[j][nConcern - 1] = 0;
		}
		int nCount = 0;
		for (int j = 0; j < nCity; j++)
		{
			if (!bVisited[j])
			{
				queue<int> q;
				q.push(j);
				bVisited[j] = true;
				while (!q.empty())
				{
					int nNode = q.front();
					q.pop();
					for (int k = 0; k < nCity; k++)
					{
						if (arr[nNode][k] == 1 && (!bVisited[k]))
						{
							q.push(k);
							bVisited[k] = true;
						}
					}
				}
			}
			else
			{
				continue;
			}
			nCount++;
		}
		cout << nCount - 1 << endl;
		memset(bVisited, false, sizeof(bVisited));
	}
	system("pause");
	return 0;
}