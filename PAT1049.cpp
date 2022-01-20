#include <iostream>
#include <string>
using namespace std;

string cnt[31] = { "" };

// 使用1037中的字符串计算函数adds,mulc
string adds(string s1, string s2)
{
	int c = 0;
	int len1 = s1.length(), len2 = s2.length();
	string r = len1 > len2 ? s1 : s2;
	for (int i = 0; i < r.length(); i++)
	{
		if (i < len1 && i < len2)
		{
			r[r.length() - i - 1] = '0' + (s1[len1 - i - 1] - '0' + s2[len2 - i - 1] - '0' + c) % 10;
			if (s1[len1 - i - 1] - '0' + s2[len2 - i - 1] - '0' + c >= 10) c = 1;
			else c = 0;
		}
		else
		{
			if (i < len1)
			{
				r[r.length() - i - 1] = '0' + (s1[len1 - i - 1] - '0' + c) % 10;
				if (s1[len1 - i - 1] - '0' + c >= 10) c = 1;
				else c = 0;
			}
			if (i < len2)
			{
				r[r.length() - i - 1] = '0' + (s2[len2 - i - 1] - '0' + c) % 10;
				if (s2[len2 - i - 1] - '0' + c >= 10) c = 1;
				else c = 0;
			}
		}
	}
	if (c == 1) return "1" + r;
	else return r;
}

string mulc(string s, char c)
{
	string r = s;
	int ca = 0;
	for (int i = 0; i < s.length(); i++)
	{
		int t = (s[s.length() - i - 1] - '0') * (c - '0') + ca;
		r[s.length() - i - 1] = t % 10 + '0';
		ca = t / 10;
	}
	if (ca == 0) return r;
	else
	{
		string t;
		t.resize(1);
		t[0] = '0' + ca;
		return t + r;
	}
}

string cnt1(int t) // 计算从1到99..99(t位)的1个数
{
	if (!cnt[t].empty()) return cnt[t];
	else
	{
		if (t == 0) cnt[t] = "0";
		else if (t == 1) cnt[t] = "1";
		else
		{
			string s;
			s.assign(t, '0');
			s[0] = '1';
			cnt[t] = adds(s, cnt1(t - 1) + "0");
		}
	}
	return cnt[t];
	// 其实算完了可以找到规律，输出结果是t00..00(t-1个0)
}

string calc1(string s)
{
	if (s.length() == 1)
	{
		if (s[0] > '0') return "1";
		else return "0";
	}
	else
	{
		if (s[0] == '0') return calc1(s.substr(1, s.length()));
		else if (s[0] == '1')
		{
			string t = adds(cnt1(s.length() - 1), "1");
			t = adds(t, s.substr(1, s.length()));
			return adds(t, calc1(s.substr(1, s.length())));
		}
		else
		{
			string t;
			t.assign(s.length(), '0');
			t[0] = '1';
			t = adds(mulc(cnt1(s.length() - 1), s[0]), t);
			return adds(t, calc1(s.substr(1, s.length())));
		}
	}
}

int main()
{
	string s;
	cin >> s;
	string ans = calc1(s);
	cout << ans;

	system("pause");
	return 0;
}