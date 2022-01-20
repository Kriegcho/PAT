#include <iostream>
#include <cmath>
using namespace std;

int cnt[31] = {0};

int cnt1(int t) // 计算从1到99..99(t位)的1个数
{
	if (cnt[t]) return cnt[t];
	else
	{
		if (t == 1) cnt[t] = 1;
		else
		{
			cnt[t] = pow(10, t - 1) + cnt1(t - 1) * 10;
		}
	}
	return cnt[t];
	// 其实算完了可以找到规律，输出结果是t00..00(t-1个0)
}

int geth(int t, int& h)
{
	int r = 0;
	while (t)
	{
		h = t;
		r++;
		t = t / 10;
	}
	return r;
}

int calc1(int s)
{
	if (s < 10)
	{
		if (s > 0) return 1;
		else return 0;
	}
	else
	{
		int h;
		int l = geth(s, h);
		if (h == 1)
		{
			return cnt1(l - 1) + 1 + s - pow(10, l - 1) + calc1(s - pow(10, l - 1));
		}
		else
		{
			return pow(10, l - 1) + cnt1(l - 1) * h + calc1(s - h * pow(10, l - 1));
		}
	}
}

int main()
{
	int s;
	cin >> s;
	int ans = calc1(s);
	cout << ans;

	system("pause");
	return 0;
}