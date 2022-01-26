#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <cmath>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> ori(N), seq(N);
	for (int i = 0; i < N; i++) cin >> ori[i];
	for (int i = 0; i < N; i++) cin >> seq[i];
	int step = 0;
	for (int i = 1; i < N; i++) 
		if (seq[i] < seq[i - 1])
		{
			step = i;
			break;
		}
	set<int> t1, t2;
	for (int i = step - 1; i > 0; i--)
	{
		t1.clear();
		t2.clear();
		for (int j = 0; j <= i; j++)
		{
			t1.insert(ori[j]);
			t2.insert(seq[j]);
		}
		if (t1 == t2)
		{
			step = i + 1;
			break;
		}
	}
	bool f = true;
	int logs = log(step) / log(2);
	int stepm;
	for (int i = 1; i <= logs; i++) // 测试点6：略恶心，插入排序取最大步长，归并取最小符合的步长
	{
		stepm = pow(2, i);
		int t = stepm;
		f = true;
		while (t < N) // 先确认每个归并段都递增
		{
			for (int i = t + 1; i < t + stepm && i < N; i++)
				if (seq[i] < seq[i - 1])
				{
					f = false;
					break;
				}
			if (!f) break;
			else t += step;
		}
		t = 0;
		while (f && t < N) // 再确认每个归并段都与原数据内容相同
		{
			t1.clear();
			t2.clear();
			for (int i = t; i < t + step && i < N; i++)
			{
				t1.insert(ori[i]);
				t2.insert(seq[i]);
			}
			if (t1 != t2) f = false;
			else t += stepm;
		}
		if (f) break;
	}
	
	if (f) cout << "Merge Sort" << endl;
	else cout << "Insertion Sort" << endl;
	vector<int> ans;
	if (f)
	{
		step = stepm;
		int t = 0;
		while (t < N)
		{
			int l1 = t, l2 = t + step;
			while ((l1 < t + step && l1 < N) || (l2 < t + step * 2 && l2 <N))
			{
				if (l1 >= N && l2 >= N) break;
				else if (l1 >= N || l1 >= t + step)
				{
					ans.push_back(seq[l2]);
					l2++;
				}
				else if (l2 >= N || l2 >= t + step * 2)
				{
					ans.push_back(seq[l1]);
					l1++;
				}
				else
				{
					if (seq[l1] < seq[l2])
					{
						ans.push_back(seq[l1]);
						l1++;
					}
					else
					{
						ans.push_back(seq[l2]);
						l2++;
					}
				}
			}
			t += 2 * step;
		}
	}
	else
	{
		for (int i = 0; i < step; i++) ans.push_back(seq[i]);
		for (int i = step - 1; i >= 0; i--)
			if (ans[i] <= seq[step])
			{
				ans.insert(ans.begin() + i + 1, seq[step]);
				break;
			}
		if (ans.size() == step) ans.insert(ans.begin(), seq[step]); // 如果上面没有插入，则说明比所有的数都小
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