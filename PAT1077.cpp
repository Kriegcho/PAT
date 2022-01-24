#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	cin.ignore();
	int nlen = 0;
	vector<string> s;
	for (int i = 0; i < N; i++)
	{
		string t;
		getline(cin, t);
		if (nlen == 0) nlen = t.length();
		else if (t.length() < nlen) nlen = t.length();
		s.push_back(t);
	}
	int c = 0;
	for (int i = 0; i < nlen; i++)
	{
		bool f = true;
		for (int j = 1; j < N; j++)
		{
			if (s[j][s[j].length() - i - 1] != s[j - 1][s[j - 1].length() - i - 1] && s[j][s[j].length() - i - 1] != ' ')
			{
				f = false;
				break;
			}
		}
		if (f) c++;
		else break;
	}
	if (c == 0) cout << "nai";
	else cout << s[0].substr(s[0].length() - c);

	system("pause");
	return 0;
}