#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s, ans;
	cin >> s;
	int pos = s.find('E');
	string e = s.substr(pos + 1);
	int ne = stoi(e.substr(1));
	string d = s.substr(0, pos);
	int pd = d.find('.');
	if (pd == -1)
	{
		if (e[0] == '+')
		{
			string t;
			t.assign(ne, '0');
			ans = d + t;
			if (d[0] == '+') ans = ans.substr(1);
		}
		else if (e[0] == '-')
		{
			string sd = d.substr(1);
			if (ne >= sd.length())
			{
				string t;
				t.assign(ne - sd.length(), '0');
				ans = "0." + t + d.substr(1);
				if (d[0] == '-') ans = "-" + ans;
			}
		}
	}
	else
	{
		if (e[0] == '+')
		{
			int tl = d.length() - pd - 1;
			if (ne >= tl)
			{
				string t;
				t.assign(ne - tl, '0');
				ans = d.substr(0, pd) + d.substr(pd + 1) + t;
				if (d[0] == '+') ans = ans.substr(1);
			}
			else
			{
				ans = d.substr(0, pd) + d.substr(pd + 1, ne) + "." + d.substr(pd + 1 + ne);
				if (d[0] == '+') ans = ans.substr(1);
			}
		}
		else
		{
			if (ne >= pd - 1)
			{
				string t;
				t.assign(ne - pd + 1, '0');
				ans = "0." + t + d.substr(1, pd - 1) + d.substr(pd + 1);
				if (d[0] == '-') ans = "-" + ans;
			}
			else
			{
				ans = d.substr(0, pd - ne - 1) + "." + d.substr(pd - ne, ne) + d.substr(pd + 1);
				if (d[0] == '+') ans = ans.substr(1);
			}
		}
	}
	cout << ans;

	system("pause");
	return 0;
}