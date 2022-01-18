#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 思路：实现整数字符串的相加和相乘即可
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

string muls(string s1, string s2)
{
	int len2 = s2.length();
	string r = "0";
	for (int i = 0; i < len2; i++)
	{
		string t = mulc(s1, s2[s2.length() - i -1]);
		string z;
		z.assign(i, '0');
		r = adds(r, t + z);
	}
	return r;
}

bool cmp(string s1, string s2)
{
	if (s1[0] == '-' && s2[0] == '-')
	{
		return cmp(s2.substr(1, s2.length()), s1.substr(1, s1.length()));
	}
	else if (s1[0] == '-' && s2[0] != '-') return true;
	else if (s1[0] != '-' && s2[0] == '-') return false;
	else
	{
		if (s1.length() == s2.length())
		{
			for (int i = 0; i < s1.length(); i++)
			{
				if (s1[i] != s2[i]) return s1[i] - s2[i] < 0;
			}
			return false;
		}
		else
		{
			return s1.length() < s2.length();
		}
	}
}

int main()
{
	int N1;
	cin >> N1;
	vector<string> v1, v2;
	v1.resize(N1);
	for (int i = 0; i < N1; i++)
	{
		cin >> v1[i];
	}
	int N2;
	cin >> N2;
	v2.resize(N2);
	for (int i = 0; i < N2; i++)
	{
		cin >> v2[i];
	}
	sort(v1.begin(), v1.end(), cmp);
	sort(v2.begin(), v2.end(), cmp);
	
	string ans = "0";
	for (int i = 0; i < v1.size() && i < v2.size(); i++)
	{
		if (v1[i][0] == '-' && v2[i][0] == '-') ans = adds(ans, muls(v1[i].substr(1, v1[i].length()), v2[i].substr(1, v2[i].length())));
		else if (v1[i][0] != '-' || v2[i][0] != '-') break;
	}
	for (int i = 0; i < v1.size() && i < v2.size(); i++)
	{
		if (v1[v1.size() - i - 1][0] != '-' && v2[v2.size() - i - 1][0] != '-') ans = adds(ans, muls(v1[v1.size() - i - 1], v2[v2.size() - i - 1]));
		else if (v1[v1.size() - i - 1][0] == '-' || v2[v2.size() - i - 1][0] == '-') break;
	}
	cout << ans;

	system("pause");
	return 0;
}