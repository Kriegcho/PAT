#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

vector<int> hp;
void adjust(int ind) // 调整堆
{
	if (ind >= hp.size()) return;
	int mc = hp[ind], mi = ind;
	bool f = false;
	if (ind * 2 + 1 < hp.size() && hp[ind * 2 + 1] > mc)
	{
		mc = hp[ind * 2 + 1];
		mi = ind * 2 + 1;
		f = true;
	}
	if (ind * 2 + 2 < hp.size() && hp[ind * 2 + 2] > mc)
	{
		mc = hp[ind * 2 + 2];
		mi = ind * 2 + 2;
		f = true;
	}
	if (f)
	{
		swap(hp[ind], hp[mi]);
		adjust(mi);
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> ori(N), seq(N);
	for (int i = 0; i < N; i++) cin >> ori[i];
	for (int i = 0; i < N; i++) cin >> seq[i];
	hp = ori;
	for (int i = N / 2 - 1; i >= 0; i--) adjust(i);
	bool f = true;
	int step = 0;
	for (int i = 0; i < N; i++)
	{
		if (seq[N - i - 1] == hp[0])
		{
			step++;
			swap(hp[0], hp[hp.size() - 1]);
			hp.pop_back();
			adjust(0);
		}
		else break;
	}
	if (step)
	{
		for (int i = 0; i < N - step; i++)
			if (seq[i] != hp[i])
			{
				f = false;
				break;
			}
	}
	else f = false;
	vector<int> ans;
	if (f)
	{
		cout << "Heap Sort" << endl;
		swap(seq[0], seq[N - step - 1]);
		swap(hp[0], hp[hp.size() - 1]);
		hp.pop_back();
		adjust(0);
		ans = hp;
		for (int i = N - step - 1; i < N; i++) ans.push_back(seq[i]);
	}
	else
	{
		cout << "Insertion Sort" << endl;
		for (int i = 1; i < N; i++)
			if (seq[i] < seq[i - 1])
			{
				step = i;
				break;
			}
		for (int i = step - 1; i >= 0; i--)
		{
			set<int> s1, s2;
			for (int j = 0; j <= i; j++)
			{
				s1.insert(ori[j]);
				s2.insert(seq[j]);
			}
			step = i + 1;
			if (s1 == s2) break;
		}
		for (int i = 0; i < step; i++) ans.push_back(seq[i]);
		for (int i = step - 1; i >= 0; i--)
		{
			if (seq[i] <= seq[step])
			{
				ans.insert(ans.begin() + i + 1, seq[step]);
				break;
			}
		}
		if (ans.size() == step) ans.insert(ans.begin(), seq[step]);
		for (int i = step + 1; i < N; i++) ans.push_back(seq[i]);
	}
	for (int i = 0; i < N; i++)
	{
		if (i > 0) cout << " ";
		cout << ans[i];
	}

	system("pause");
	return 0;
}