#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct rec
{
	int id;
	string name;
	int g;
};

bool cmp1(rec r1, rec r2)
{
	return r1.id < r2.id;
}

bool cmp2(rec r1, rec r2)
{
	return r1.name == r2.name ? r1.id < r2.id : r1.name < r2.name;
}

bool cmp3(rec r1, rec r2)
{
	return r1.g == r2.g ? r1.id < r2.id : r1.g < r2.g;
}

int main()
{
	int N, C;
	cin >> N >> C;
	vector<rec> rs(N);
	for (int i = 0; i < N; i++)
	{
		cin >> rs[i].id >> rs[i].name >> rs[i].g;
	}

	switch (C)
	{
	case 1:
		sort(rs.begin(), rs.end(), cmp1);
		break;
	case 2:
		sort(rs.begin(), rs.end(), cmp2);
		break;
	case 3:
		sort(rs.begin(), rs.end(), cmp3);
		break;
	}

	for (int i = 0; i < N; i++)
	{
		printf("%06d", rs[i].id);
		cout << " " << rs[i].name << " " << rs[i].g << endl;
	}

	system("pause");
	return 0;
}