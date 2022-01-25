#include <iostream>
#include <string>
#include <cctype>
#include <set>
using namespace std;

char toup(char c)
{
	if (c >= 'a' && c <= 'z') return 'A' + c - 'a';
	return c;
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	bool f[37] = {false};
	for (int i = 0; i < s2.length(); i++)
	{
		if (isalpha(s2[i]))
		{
			char t = toup(s2[i]);
			f[10 + t - 'A'] = true;
		}
		else if (isdigit(s2[i])) f[s2[i] - '0'] = true;
		else if (s2[i] == '_') f[36] = true;
	}
	set<char> ans;
	for (int i = 0; i < s1.length(); i++)
	{
		if (isalpha(s1[i]))
		{
			char t = toup(s1[i]);
			if (!f[10 + t - 'A'] && ans.find(t) == ans.end())
			{
				cout << t;
				ans.insert(t);
			}
		}
		else if (isdigit(s1[i]) && !f[s1[i] - '0'] && ans.find(s1[i]) == ans.end())
		{
			cout << s1[i];
			ans.insert(s1[i]);
		}
		else if (s1[i] == '_' && !f[36] && ans.find(s1[i]) == ans.end())
		{
			cout << s1[i];
			ans.insert(s1[i]);
		}
	}
	system("pause");
	return 0;
}