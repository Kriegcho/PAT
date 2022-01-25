#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct r
{
	long int a = 0, b = 0, c = 0;
};

void sim(r& t)
{
	bool f = true;
	if (t.a < 0)
	{
		f = false;
		t.a = -t.a;
	}
	while (t.a >= t.b)
	{
		if (f) t.c++;
		else t.c--;
		t.a -= t.b;
	}
	long int p = 2;
	while (p <= t.a)
	{
		if (t.a % p == 0 && t.b % p == 0)
		{
			t.a /= p;
			t.b /= p;
		}
		else p++;
	}
	if (!f) t.a = -t.a;
}

r add(r r1, r r2)
{
	r ret;
	ret.c = r1.c + r2.c;
	ret.a = r1.a * r2.b + r1.b * r2.a;
	ret.b = r1.b *r2.b;
	sim(ret);
	return ret;
}

int main()
{
	int N;
	cin >> N;
	r ans;
	for (int i = 0; i < N; i++)
	{
		string st;
		cin >> st;
		r rt;
		int pos = st.find('/');
		if (pos == -1) rt.a = stol(st);
		else
		{
			rt.a = stol(st.substr(0, pos));
			rt.b = stol(st.substr(pos + 1));
		}
		sim(rt);
		if (i == 0) ans = rt;
		else ans = add(ans, rt);
	}
	if (ans.c)
	{
		cout << ans.c;
		if (ans.a) cout << " " << ans.a << "/" << ans.b;
	}
	else
	{
		if (ans.a) cout << ans.a << "/" << ans.b;
		else cout << "0";
	}

	system("pause");
	return 0;
}