#include <iostream>
#include <string>
using namespace std;

bool cmp(string s1, string s2)
{
	if (s1[0] == '-' && s2[0] == '-') return cmp(s2.substr(1, s2.length()), s1.substr(1, s1.length()));
	else if (s1[0] == '-' && s2[0] != '-') return false;
	else if (s1[0] != '-' && s2[0] == '-') return true;
	else
	{
		if (s1.length() == s2.length())
		{
			if (s1 == s2) return false;
			else for (int i = 0; i < s1.length(); i++) if (s1[i] < s2[i]) return false;
			return true;
		}
		else return s1.length() > s2.length();
	}
}

string subs(string s1, string s2)
{
	int c = 0, len1 = s1.length(), len2 = s2.length();
	if (cmp(s2, s1)) return "-" + subs(s2, s1);
	string s;
	s.resize(len1);
	for (int i = 0; i < len1 && i < len2; i++)
	{
		int t = s1[s1.length() - i - 1] - '0' - (s2[s1.length() - i - 1] - '0') + c;
		if (t >= 0)
		{
			s[s.length() - i - 1] = '0' + t;
			c = 0;
		}
		else
		{
			s[s.length() - i - 1] = '0' + 10 + t;
			c = -1;
		}
	}
	if (len1 > len2)
	{
		for (int i = len2; i < len1; i++)
		{
			int t = s1[i] - '0' + c;
			if (t >= 0)
			{
				s[i] = '0' + t;
				c = 0;
			}
			else
			{
				s[i] = '0' + 10 + t;
				c = -1;
			}
		}
	}
	while (s[0] == '0') s = s.substr(1, s.length());
	return s;
}

string adds(string s1, string s2)
{
	if (s1[0] == '-' && s2[0] == '-') return "-" + adds(s1.substr(1, s1.length()), s2.substr(1, s2.length()));
	else if ((s1[0] == '-' && s2[0] != '-')) return subs(s2, s1.substr(1, s1.length()));
	else if ((s1[0] != '-' && s2[0] == '-')) return subs(s1, s2.substr(1, s2.length()));
	else
	{
		int c = 0, len1 = s1.length(), len2 = s2.length();
		string s;
		s.resize(len1 > len2 ? len1 : len2);
		for (int i = 0; i < len1 && i < len2; i++)
		{
			s[s.length() - i - 1] = '0' + (s1[s1.length() - i - 1] - '0' + s2[s2.length() - i - 1] - '0' + c) % 10;
			if ((s1[s1.length() - i - 1] - '0' + s2[s2.length() - i - 1] - '0' + c) > 10) c = 1;
			else c = 0;
		}
		if (len1 > len2)
		{
			for (int i = len2; i < len1; i++)
			{
				s[s.length() - i - 1] = '0' + (s1[s1.length() - i - 1] - '0' + c) % 10;
				if (s1[s1.length() - i - 1] - '0' + c > 10) c = 1;
				else c = 0;
			}
		}
		else if (len1 < len2)
		{
			for (int i = len1; i < len2; i++)
			{
				s[s.length() - i - 1] = '0' + (s2[s2.length() - i - 1] - '0' + c) % 10;
				if (s2[s2.length() - i - 1] - '0' + c > 10) c = 1;
				else c = 0;
			}
		}
		if (c == 1) return "1" + s;
		else return s;
	}
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		string a, b, c;
		cin >> a >> b >> c;
		cout << "Case #" << i << ": ";
		if (cmp(adds(a, b), c)) cout << "true" << endl;
		else cout << "false" << endl;
	}

	system("pause");
	return 0;
}