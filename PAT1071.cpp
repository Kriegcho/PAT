#include <iostream>
#include <string>
#include <cctype>
#include <map>
using namespace std;

char tolow(char c)
{
	if (c >= 'A' && c <= 'Z') return 'a' + c - 'A';
	else return c;
}

int main()
{
	char c = getchar();
	string t;
	bool f = false;
	map<string, int> m;
	while (c != '\n')
	{
		if (isalpha(c) || isdigit(c))
		{
			if (!f) f = true;
			t += tolow(c);
		}
		else
		{
			if (!t.empty())
			{
				if (m.find(t) != m.end()) m[t]++;
				else m.insert(make_pair(t, 1));
			}
			t.clear();
			f = false;
		}
		c = getchar();
	}
	if (m.find(t) != m.end()) m[t]++;
	else m.insert(make_pair(t, 1));
	int maxl = 0;
	map<string, int>::iterator it = m.begin();
	while (it != m.end())
	{
		if (it->second > maxl)
		{
			t = it->first;
			maxl = it->second;
		}
		else if (it->second == maxl) if (it->first < t) t = it->first;
		it++;
	}
	cout << t << " " << maxl;

	system("pause");
	return 0;
}