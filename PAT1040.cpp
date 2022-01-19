#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

bool judges(string s)
{
	int l = 0, h = s.length() - 1;
	while (l < h)
	{
		if (s[l] != s[h]) return false;
		l++;
		h--;
	}
	return true;
}

int getml(string s)
{
	if (s.length() == 1) return 1;
	char c = s[s.length() - 1];
	int l = 0;
	for (int i = 0; i < s.length() - 1; i++)
	{
		if (s[i] == c)
		{
			if (judges(s.substr(i, s.length())))
			{
				l = s.length() - i;
				break;
			}
		}
	}
	if (l) return max(l, getml(s.substr(0, s.length() - 1)));
	else return getml(s.substr(0, s.length() - 1));
}

int main()
{
	string s;
	getline(cin, s);
	cout << getml(s);

	system("pause");
	return 0;
}