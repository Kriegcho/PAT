#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

struct rec
{
	string s1; 
	string s2;
};

int main()
{
	int N;
	cin >> N;
	vector<rec> rs;
	set<int> is;
	rs.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> rs[i].s1 >> rs[i].s2;
		bool f = false;
		for (int j = 0; j < rs[i].s2.length(); j++)
		{
			if (rs[i].s2[j] == '1')
			{
				rs[i].s2[j] = '@';
				f = true;
			}
			if (rs[i].s2[j] == '0')
			{
				rs[i].s2[j] = '%';
				f = true;
			}
			if (rs[i].s2[j] == 'l')
			{
				rs[i].s2[j] = 'L';
				f = true;
			}
			if (rs[i].s2[j] == 'O')
			{
				rs[i].s2[j] = 'o';
				f = true;
			}
		}
		if (f) is.insert(i);
	}
	if (is.empty())
	{
		if (N > 1) printf("There are %d accounts and no account is modified", N);
		else printf("There is %d account and no account is modified", N);
	}
	else
	{
		cout << is.size() << endl;
		for (set<int>::iterator it = is.begin(); it != is.end(); it++)
		{
			cout << rs[*it].s1 << " " << rs[*it].s2 << endl;
		}
	}

	system("pause");
	return 0;
}