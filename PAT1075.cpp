#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct rec
{
	int s[6] = { -1,-1,-1,-1,-1,-1 };
	int id, pn = 0, sum = 0;
	bool f = false;
};
int ms[6] = { 0 };
rec* rs[10001] = { NULL };
int N, K, M;

bool cmp(rec* r1, rec* r2)
{
	if (r1->sum == r2->sum)
	{
		if (r1->pn == r2->pn) return r1->id < r2->id;
		else return r1->pn > r2->pn;
	}
	else return r1->sum > r2->sum;
}

int main()
{
	cin >> N >> K >> M;
	for (int i = 1; i <= K; i++) scanf("%d", &ms[i]);
	vector<rec*> ans;
	for (int i = 0; i < M; i++)
	{
		int ind, a, b;
		scanf("%d %d %d", &ind, &a, &b);
		if (ind > N) continue;
		if (rs[ind])
		{
			if (b > rs[ind]->s[a])
			{
				if (rs[ind]->s[a] > 0) rs[ind]->sum -= rs[ind]->s[a];
				rs[ind]->s[a] = b;
				rs[ind]->sum += b;
				rs[ind]->f = true;
				if (b == ms[a]) rs[ind]->pn++;
			}
			else if (rs[ind]->s[a] == -1) rs[ind]->s[a] = 0;
		}
		else
		{
			rec* p = new rec;
			p->id = ind;
			p->s[a] = b > -1 ? b : 0;
			p->sum += p->s[a];
			if (b > -1) p->f = true;
			if (b == ms[a]) p->pn++;
			rs[ind] = p;
			ans.push_back(p);
		}
	}
	sort(ans.begin(), ans.end(), cmp);
	int r = 1;
	for (int i = 0; i < ans.size(); i++)
	{
		if (!ans[i]->f) continue;
		if (i > 0 && ans[i]->sum < ans[i - 1]->sum) r = i + 1;
		printf("%d %05d %d", r, ans[i]->id, ans[i]->sum);
		for (int j = 1; j <= K; j++)
		{
			cout << " ";
			if (ans[i]->s[j] > -1) cout << ans[i]->s[j];
			else cout << "-";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}