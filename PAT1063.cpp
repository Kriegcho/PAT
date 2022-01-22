#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
	int N, K;
	cin >> N;
	vector<set<int>> s(N);
	for (int i = 0; i < N; i++)
	{
		int M;
		scanf("%d", &M);
		for (int j = 0; j < M; j++)
		{
			int t;
			scanf("%d", &t);
			s[i].insert(t);
		}
	}
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		int a, b, nc = 0, nt;
		cin >> a >> b;
		set<int> t, p = s[b - 1];
		for (set<int>::iterator it = s[a - 1].begin(); it != s[a - 1].end(); it++)
		{
			p.insert(*it);
			if (t.find(*it) == t.end() && s[b - 1].find(*it) != s[b - 1].end())
			{
				nc++;
				t.insert(*it);
			}
		}
		nc = t.size();
		nt = p.size();
		double d = 100.0 * nc / nt;
		printf("%.1f%", d);
		cout << "%" << endl;
	}

	system("pause");
	return 0;
}