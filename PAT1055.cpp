#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct p
{
	string s;
	int a, n;
};

bool cmp(p p1, p p2)
{
	if (p1.n == p2.n)
	{
		if (p1.a == p2.a) return p1.s < p2.s;
		else return p1.a < p2.a;
	}
	else return p1.n > p2.n;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<p> ps(N);
	for (int i = 0; i < N; i++)
	{
		cin >> ps[i].s >> ps[i].a >> ps[i].n;
	}
	sort(ps.begin(), ps.end(), cmp);
	for (int i = 0; i < K; i++)
	{
		int M, la, ha;
		cin >> M >> la >> ha;
		cout << "Case #" << i + 1 << ":" << endl;
		int c = 0;
		for (int j = 0; j < N; j++)
		{
			if (c == M) break;
			if (ps[j].a >= la && ps[j].a <= ha)
			{
				cout << ps[j].s << " " << ps[j].a << " " << ps[j].n << endl;
				c++;
			}
		}
		if (c == 0) cout << "None" << endl;
	}

	system("pause");
	return 0;
}