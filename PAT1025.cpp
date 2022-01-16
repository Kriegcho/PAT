#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct rec
{
	int ns;
	long long id;
	int ln;
	int fr;
	int lr;
};

bool cmp(rec* r1, rec* r2)
{
	return r1->ns == r2->ns ? r1->id < r2->id : r1->ns > r2->ns;
}

int main()
{
	int N;
	cin >> N;
	vector<rec*> all;
	for (int i = 0; i < N; i++)
	{
		vector<rec*> l;
		int K;
		cin >> K;
		for (int j = 0; j < K; j++)
		{
			rec* t = new rec;
			cin >> t->id >> t->ns;
			t->ln = i + 1;
			l.push_back(t);
			all.push_back(t);
		}
		sort(l.begin(), l.end(), cmp);
		l[0]->lr = 1;
		for (int j = 1; j < l.size(); j++)
		{
			if (l[j]->ns == l[j - 1]->ns) l[j]->lr = l[j - 1]->lr;
			else l[j]->lr = j + 1;
		}
	}
	sort(all.begin(), all.end(), cmp);
	all[0]->fr = 1;
	for (int i = 1; i < all.size(); i++)
	{
		if (all[i]->ns == all[i - 1]->ns) all[i]->fr = all[i - 1]->fr;
		else all[i]->fr = i + 1;
	}

	cout << all.size() << endl;
	for (int i = 0; i < all.size(); i++)
	{
		printf("%013lld ", all[i]->id);
		cout << all[i]->fr << " " << all[i]->ln << " " << all[i]->lr << endl;
	}

	system("pause");
	return 0;
}