#include <iostream>
#include <vector>
using namespace std;

// 有意思的一道题
// 思路：①当0不在首位时，每做一次交换，要将一个数换到其最终位置。
// ②若交换若干次后，0到达首位，找到第一个不在最终位置的元素，0与其交换。重复①②，直到完成排序。
int main()
{
	int N, c = 0;
	cin >> N;
	vector<int> d(N); // 记录初始数据
	vector<int> p(N); // 记录数据位置
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &d[i]);
		p[d[i]] = i;
	}
	int pos = 0; // pos的作用是去掉无用循环，否则测试点1、2就超时了
	while (1)
	{
		while (p[0] != 0)
		{
			int t = p[p[0]];
			d[t] = 0;
			d[p[0]] = p[0];
			p[p[0]] = p[0];
			p[0] = t;
			c++;
		}
		bool f = false;
		for (int i = pos; i < N; i++)
		{
			if (d[i] != i)
			{
				d[0] = d[p[i]];
				d[p[i]] = 0;
				int t = p[i];
				p[i] = 0;
				p[0] = t;
				c++;
				f = true;
				pos = i + 1;
				break;
			}
		}
		if (f) continue;
		else break;
	}
	cout << c;

	system("pause");
	return 0;
}