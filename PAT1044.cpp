#include <iostream>
#include <vector>
using namespace std;
// 思路：类似于KMP查找子串的算法，子串起点pos只往增加的方向移动。题目限时300ms，测试点3花了210ms，cin换成scanf也要204ms，否则应该超时了。
int main()
{
	int N, M;
	cin >> N >> M;
	vector<int> ns(N);
	for (int i = 0; i < N; i++) cin >> ns[i];
	int pos = 0, sum = 0, mins = 100000010;
	bool f = false;
	vector<int> a1, a2;
	for (int i = 0; i < N; i++)
	{
		sum += ns[i];
		if (sum == M)
		{
			cout << pos + 1 << "-" << i + 1 << endl;
			f = true;
		}
		else if (sum > M)
		{
			while (sum > M)
			{
				if (!f)
				{
					if (sum < mins)
					{
						mins = sum;
						a1.clear();
						a2.clear();
						a1.push_back(pos + 1);
						a2.push_back(i + 1);
					}
					else if (sum == mins)
					{
						a1.push_back(pos + 1);
						a2.push_back(i + 1);
					}
				}
				sum -= ns[pos];
				pos++;
				if (sum == M)
				{
					cout << pos + 1 << "-" << i + 1 << endl;
					f = true;
				}
			}
		}
	}
	if (!f)
	{
		for (int i = 0; i < a1.size(); i++)
		{
			cout << a1[i] << "-" << a2[i] << endl;
		}
	}

	system("pause");
	return 0;
}