#include <iostream>
#include <string>
using namespace std;

long int maxg(long int a, long int b) // 求最大公约数
{
	if (a > b)
	{
		if (a % b == 0) return b;
		else return maxg(a - b, b);
	}
	else if (a < b)
	{
		if (b % a == 0) return a;
		else return maxg(a, b - a);;
	}
	else return a;
}

struct d
{
	d(string s)
	{
		long int pos = s.find('/');
		if (pos == -1) c = stoi(s);
		else
		{
			a = stoi(s.substr(0, pos));
			b = stoi(s.substr(pos + 1));
		}
		sim();
	}
	void sim()
	{
		bool f = a < 0;
		if (f)
		{
			a = -a;
			c -= a / b;
		}
		else c += a / b;
		a = a % b;
		if (a != 0)
		{
			long int t = maxg(a > 0 ? a : -a, b);
			a /= t;
			b /= t;
		}
		if (f) a = -a;
		if (s != "Inf")
		{
			if (c == 0 && a == 0) s = "0";
			else if (a == 0) s = to_string(c);
			else if (c == 0) s = to_string(a) + "/" + to_string(b);
			else
			{
				s = to_string(c) + " ";
				if (c < 0 && a < 0) s += to_string(-a) + "/" + to_string(b);
				else s += to_string(a) + "/" + to_string(b);
			}
		}
		if (s[0] == '-') s = "(" + s + ")";
	}
	void op(long int type, d t)
	{
		switch (type)
		{
			case 1: // +
			{
				c += t.c;
				a = a * t.b + b * t.a;
				b = b * t.b;
				if (c * a < 0)
				{
					if (c > 0)
					{
						c--;
						a += b;
					}
					else
					{
						c++;
						a -= b;
					}
				}
			}
			break;
			case 2: // -
			{
				t.c = -t.c;
				t.a = -t.a;
				op(1, t);
			}
			break;
			case 3: // *
			{
				a = (c * b + a) * (t.c * t.b + t.a);
				b = b * t.b;
				c = 0;
			}
			break;
			case 4: // /
			{
				if (t.c == 0 && t.a == 0) s = "Inf";
				else
				{
					a = (c * b + a) * t.b;
					b = (t.c * t.b + t.a) * b;
					if (b < 0)
					{
						b = -b;
						a = -a;
					}
				}
				c = 0;
			}
			break;
		}
		sim();
	}
	long int a = 0, b = 1, c = 0;
	string s;
};

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	d d1(s1), d2(s2);
	d t = d1;
	t.op(1, d2);
	cout << d1.s << " + " << d2.s << " = " << t.s << endl;
	t = d1;
	t.op(2, d2);
	cout << d1.s << " - " << d2.s << " = " << t.s << endl;
	t = d1;
	t.op(3, d2);
	cout << d1.s << " * " << d2.s << " = " << t.s << endl;
	t = d1;
	t.op(4, d2);
	cout << d1.s << " / " << d2.s << " = " << t.s << endl;

	system("pause");
	return 0;
}