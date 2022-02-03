#include <iostream>
#include <string>
using namespace std;

bool judge(string s)
{
	int l = 0, h = s.length() - 1;
	while (l <= h)
	{
		if (s[l] != s[h]) return false;
		l++;
		h--;
	}
	return true;
}

string op(string s)
{
	string r = s, rev = s;
	int c = 0;
	for (int i = 0; i < s.length(); i++)
	{
		rev[s.length() - i - 1] = s[i];
		int t = s[i] - '0' + s[s.length() - i - 1] - '0' + c;
		if (t >= 10)
		{
			t -= 10;
			c = 1;
		}
		else c = 0;
		r[s.length() - i - 1] = t + '0';
	}
	if (c) r = "1" + r;
	cout << s << " + " << rev << " = " << r << endl;
	return r;
}

int main()
{
	string N;
	cin >> N;
	int i = 0;
	while (!judge(N) && i < 10)
	{
		N = op(N);
		i++;
	}
	if (judge(N)) cout << N << " is a palindromic number.";
	else cout << "Not found in 10 iterations.";

	system("pause");
	return 0;
}