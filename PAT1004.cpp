#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	map<int, vector<int>> m;
	for (int i = 0; i < M; i++)
	{
		int id, K;
		cin >> id >> K;
		m[id] = vector<int>(K);
		for (int j = 0; j < K; j++) cin >> m[id][j];
	}
	queue<int> q;
	q.push(1);
	bool f = false;
	while (1)
	{
		queue<int> temp;
		int c = 0;
		while (!q.empty())
		{
			if (m.find(q.front()) == m.end()) c++;
			for (int i = 0; i < m[q.front()].size(); i++) temp.push(m[q.front()][i]);
			q.pop();
		}
		if (f) cout << " ";
		f = true;
		cout << c;
		if (temp.empty()) break;
		q = temp;
	}
	system("pause");
}