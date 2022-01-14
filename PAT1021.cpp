#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N;
int maxl = 1;
vector<vector<int>> adjMatrix;
vector<bool> flag; // 遍历标志
set<int> temp;
set<int> ret; // 结果

void DFS(int pos, int depth, set<int>& s)
{
	flag[pos] = true;
	for (int i = 0; i < adjMatrix[pos].size(); i++)
	{
		if (flag[adjMatrix[pos][i]] == false)
		{
			flag[adjMatrix[pos][i]] = true;
			if (depth > 0)
			{
				DFS(adjMatrix[pos][i], depth + 1, s);
			}
			else
			{
				DFS(adjMatrix[pos][i], -1, s);
			}
		}
	}

	if (depth > maxl)
	{
		maxl = depth;
		s.clear();
		s.insert(pos);
	}
	else if (depth == maxl)
	{
		s.insert(pos);
	}
}

int main()
{
	cin >> N;
	adjMatrix.resize(N);
	flag.assign(N, false);
	for (int i = 0; i < N - 1; i++)
	{
		int s, e;
		cin >> s >> e;
		adjMatrix[s - 1].push_back(e - 1);
		adjMatrix[e - 1].push_back(s - 1);
	}

	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		if (flag[i] == false)
		{
			flag[i] = true;
			DFS(i, -1, temp);
			cnt++;
		}
	}

	if (cnt == 1)
	{
		temp.clear();
		flag.assign(N, false);
		DFS(0, 1, temp);
		flag.assign(N, false);
		DFS(*(temp.begin()), 1, ret);
		for (set<int>::iterator it = temp.begin(); it != temp.end(); it++)
		{
			ret.insert(*it);
		}
		for (set<int>::iterator it = ret.begin(); it != ret.end(); it++)
		{
			cout << *it + 1 << endl;
		}
	}
	else
	{
		cout << "Error: " << cnt << " components";
	}

	system("pause");
	return 0;
}