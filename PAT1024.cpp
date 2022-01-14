#include <iostream>
#include <string>
using namespace std;

string addreverse(string s)
{
	string ret = s;
	bool f = false;
	int c = 0;
	for (int i = 0; i < s.length(); i++)
	{
		ret[s.length() - 1 - i] = '0' + (s[i] - '0' + s[s.length() - 1 - i] - '0' + c) % 10;
		if ((s[i] - '0' + s[s.length() - 1 - i] - '0') + c > 9)
		{
			c = 1;
		}
		else
		{
			c = 0;
		}
	}
	if (c == 1) return "1" + ret;
	else return ret;
}

bool judgeS(string s)
{
	int l = 0, h = s.length() - 1;
	bool f = true;
	while (l <= h)
	{
		if (s[l] == s[h])
		{
			l++;
			h--;
		}
		else
		{
			f = false;
			break;
		}
	}
	return f;
}

int main()
{
	string sN;
	int K;
	cin >> sN >> K;
	string sM = sN;
	bool f = true;
	if (judgeS(sN))
	{
		cout << sN << endl;
		cout << "0" << endl;
	}
	else
	{
		for (int i = 0; i < K; i++)
		{
			sM = addreverse(sM);
			if (judgeS(sM))
			{
				cout << sM << endl;
				cout << i + 1 << endl;
				f = false;
				break;
			}
		}
		if (f)
		{
			cout << sM << endl;
			cout << K << endl;
		}
	}
	system("pause");
	return 0;
}