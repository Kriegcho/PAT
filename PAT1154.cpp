#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int N, M;
	cin >> N >> M;
	vector<pair<int, int>> edge;
	for (int i = 0; i < M; i++)
	{
		int t1, t2;
		cin >> t1 >> t2;
		edge.push_back(make_pair(t1, t2));
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		vector<int> color(N);
		set<int> s;
		for (int j = 0; j < N; j++)
		{
			cin >> color[j];
			s.insert(color[j]);
		}
		bool f = false;
		for(int j=0;j<M;j++)
			if (color[edge[j].first] == color[edge[j].second])
			{
				f = true;
				break;
			}
		if (f) cout << "No" << endl;
		else cout << s.size() << "-coloring" << endl;
	}

	system("pause");
	return 0;
}