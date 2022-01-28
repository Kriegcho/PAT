#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct stu
{
	string n;
	int h;
};

bool cmp(stu s1, stu s2)
{
	if (s1.h == s2.h) return s1.n < s2.n;
	else return s1.h > s2.h;
}

int main()
{
	int N, K;
	cin >> N >> K;
	vector<stu> ds(N);
	for (int i = 0; i < N; i++) cin >> ds[i].n >> ds[i].h;
	sort(ds.begin(), ds.end(), cmp);
	int r = N / K, m = N % K, ind = 0;
	for (int i = 0; i < K; i++)
	{
		vector<stu> row;
		int beg = (i == 0 ? 0 : m + i * r);
		row.push_back(ds[beg]);
		bool f = true;
		for (int j = 1; j < (i == 0 ? r + m : r); j++)
			if (f)
			{
				row.insert(row.begin(), ds[beg + j]);
				f = false;
			}
			else
			{
				row.push_back(ds[beg + j]);
				f = true;
			}
		for (int j = 0; j < row.size(); j++)
		{
			if (j > 0) cout << " ";
			cout << row[j].n;
		}
		cout << endl;
	}

	system("pause");
	return 0;
}