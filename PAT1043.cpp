#include <iostream>
#include <vector>
using namespace std;

vector<int> ns;
vector<int> ans;

bool judge(int l, int h, bool f) // f=true表示正向
{
	if (l == h)
	{
		ans.push_back(ns[l]);
		return true;
	}
	else if (l < h) // 没加这个条件导致超时（或者说段错误）。。因为当正向只有右子树或镜像只有左子树时，l + 1 > pos - 1。这种情况直接return true就好了。
	{
		int pos = -1;
		bool t = false;
		for (int i = l + 1; i <= h; i++)
		{
			if (t)
			{
				if (f && ns[i] < ns[l]) return false;
				if (!f && ns[i] >= ns[l]) return false;
			}
			else
			{
				if (f && ns[i] >= ns[l])
				{
					t = true;
					pos = i;
				}
				else if (!f && ns[i] < ns[l])
				{
					t = true;
					pos = i;
				}
			}
		}
		if (pos == -1)
		{
			bool b = judge(l + 1, h, f);
			ans.push_back(ns[l]);
			return b;
		}
		else
		{
			bool b1 = judge(l + 1, pos - 1, f);
			bool b2 = judge(pos, h, f);
			ans.push_back(ns[l]);
			return b1 && b2;
		}
	}
	else return true;
}

int main()
{
	int N;
	cin >> N;
	ns.resize(N);
	for (int i = 0; i < N; i++) cin >> ns[i];
	if (judge(0, N - 1, true))
	{
		cout << "YES" << endl;
		for (int i = 0; i < N; i++)
		{
			if (i == 0) cout << ans[i];
			else cout << " " << ans[i];
		}
	}
	else
	{
		ans.clear();
		if (judge(0, N - 1, false))
		{
			cout << "YES" << endl;
			for (int i = 0; i < N; i++)
			{
				if (i == 0) cout << ans[i];
				else cout << " " << ans[i];
			}
		}
		else cout << "NO";
	}

	system("pause");
	return 0;
}