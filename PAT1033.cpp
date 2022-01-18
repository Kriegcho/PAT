#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 贪心思想：将所有价格排序后，从低到高尽可能地加更多油，可以使总价格最小。
// 判断加油量时采用区间判断和合并的策略

struct sta
{
	double p;
	int d;
};

struct part
{
	int b;
	int e;
};
bool cmpp(part* p1, part* p2)
{
	return p1->b < p2->b;
}
vector<part*> ps;
int allocp(int s, int d, int dis)
{
	if (s + d > dis) d = dis - s;
	sort(ps.begin(), ps.end(), cmpp);
	for (int i = 0; i < ps.size(); i++)
	{
		if (s >= ps[i]->b && s <= ps[i]->e)
		{
			if (s + d > ps[i]->e)
			{
				int t = s + d - ps[i]->e;
				int temp = ps[i]->e;
				ps[i]->e = s + d;
				if (i < ps.size() - 1 && ps[i]->e > ps[i + 1]->b)
				{
					t = ps[i + 1]->b - temp;
					ps[i]->e = ps[i + 1]->e;
					ps.erase(ps.begin() + i + 1);
				}
				return t;
			}
			else return 0;
		}
	}
	for (int i = 0; i < ps.size(); i++)
	{
		if (s < ps[i]->b && s + d >= ps[i]->b)
		{
			int t = ps[i]->b - s;
			ps[i]->b = s;
			return t;
		}
	}
	part* p = new part;
	p->b = s;
	p->e = s + d;
	ps.push_back(p);
	return d;
}

bool cmp(sta s1, sta s2)
{
	return s1.p < s2.p;
}

int main()
{
	int C, Dis, Avg, N;
	cin >> C >> Dis >> Avg >> N;
	vector<sta> stas;
	stas.resize(N);
	for (int i = 0; i < N; i++)
	{
		cin >> stas[i].p >> stas[i].d;
	}
	sort(stas.begin(), stas.end(), cmp);

	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		int da = allocp(stas[i].d, C * Avg, Dis);
		sum += da * stas[i].p / Avg;
		if (ps.size() == 1 && ps[0]->b == 0 && ps[0]->e == Dis) break;
	}

	sort(ps.begin(), ps.end(), cmpp);
	if (ps.size() == 1 && ps[0]->b == 0 && ps[0]->e == Dis) printf("%.2f", sum);
	else
	{
		if (ps[0]->b > 0) printf("The maximum travel distance = 0.00");
		else
		{
			double d = ps[0]->e;
			printf("The maximum travel distance = %.2f", d);
		}
	}

	system("pause");
	return 0;
}