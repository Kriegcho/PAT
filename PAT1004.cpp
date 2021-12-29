#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int maxN = 110;
int nLayer = 0;
vector<int> childNodeArr[maxN];
int nodeLevel[maxN] = { 0 };
int noChildNode[maxN] = { 0 };

void BFS(int nRoot)
{
	queue<int> q;
	q.push(nRoot);
	int lastNode = nRoot;
	int newLastNode;
	while (!q.empty())
	{
		int nTempNode = q.front();
		q.pop();
		if (!childNodeArr[nTempNode].empty())
		{
			for (int i = 0; i < childNodeArr[nTempNode].size(); i++)
			{
				q.push(childNodeArr[nTempNode][i]);
				nodeLevel[childNodeArr[nTempNode][i]] = nodeLevel[nTempNode] + 1;
			}
			newLastNode = childNodeArr[nTempNode][childNodeArr[nTempNode].size() - 1];
		}
		else
		{
			noChildNode[nodeLevel[nTempNode]]++;
		}

		if (nTempNode == lastNode)
		{
			lastNode = newLastNode;
			nLayer++;
		}
	}
}

int main()
{
	int nNodes, nNonLeafNodes;
	cin >> nNodes;
	cin >> nNonLeafNodes;
	for (int i = 0; i < nNonLeafNodes; i++)
	{
		int nFather, nChildNodes;
		cin >> nFather >> nChildNodes;
		for (int j = 0; j < nChildNodes; j++)
		{
			int nChild;
			cin >> nChild;
			childNodeArr[nFather].push_back(nChild);
		}
	}
	BFS(1);
	for (int i = 0; i < nLayer; i++)
	{
		if (i == 0)
		{
			cout << noChildNode[i];
		}
		else
		{
			cout << " " << noChildNode[i];
		}
	}
	system("pause");
	return 0;
}