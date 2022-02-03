#include <iostream>
#include <string>
using namespace std;

string getd(int D, string s)
{
	if (s.empty())
	{
		string r = "11";
		r[0] = '0' + D;
		return r;
	}
	else
	{
		char t = s[0];
		int c = 0;
		string r;
		for (int i = 0; i < s.length(); i++)
		{
			if (s[i] == t) c++;
			else
			{
				r += t;
				r += to_string(c);
				t = s[i];
				c = 1;
			}
		}
		r += t;
		r += to_string(c);
		return r;
	}
}

int main()
{
	int D, N;
	cin >> D >> N;
	string ans;
	if (N == 1) ans = to_string(D);
	for (int i = 0; i < N - 1; i++)
	{
		ans = getd(D, ans);
	}
	cout << ans;

	system("pause");
	return 0;
}