#include <iostream>
#include <string>
#include <map>
#include <cctype>
using namespace std;

string ds1[13] = { "tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec" };
string ds2[13] = { "t","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };

int main()
{
	int N;
	cin >> N;
	map<string, int> m;
	for (int i = 0; i < 13; i++)
	{
		m[ds1[i]] = i;
		m[ds2[i]] = 13 * i;
	}
	cin.ignore();
	for (int i = 0; i < N; i++)
	{
		string s;
		getline(cin, s);
		if (isdigit(s[0]))
		{
			int t = stoi(s);
			if (t >= 13)
			{
				if (t % 13 > 0) cout << ds2[t / 13] << " " << ds1[t % 13] << endl; // 整除时后面不加tret
				else cout << ds2[t / 13] << endl;
			}
			else cout << ds1[t] << endl;
		}
		else
		{
			int pos = s.find(' ');
			if (pos == -1) cout << m[s] << endl;
			else cout << m[s.substr(0, pos)] + m[s.substr(pos + 1)] << endl;
		}
	}

	system("pause");
	return 0;
}