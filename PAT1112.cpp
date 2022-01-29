#include <iostream>
#include <string>
#include <set>
#include <vector>
using namespace std;

int main()
{
	int k;
	string s;
	cin >> k >> s;
	char t = s[0];
	int c = 1;
	set<char> cs, csf, cst;
	vector<char> ans;
	for (int i = 1; i < s.length(); i++)
	{
		if (s[i] == t)
		{
			c++;
			if (c == k && csf.find(t) == csf.end())
			{
				cs.insert(t);
				ans.push_back(t);
				c = 0;
			}
		}
		else
		{
			if (c > 0 && c != k)
			{
				if (cs.find(t) != cs.end()) cs.erase(cs.find(t));
				csf.insert(t);
			}
			c = 1;
			t = s[i];
		}
	}
	cst = cs;
	for (int i = 0; i < ans.size(); i++)
	{
		if (cs.find(ans[i]) != cs.end())
		{
			cout << ans[i];
			cs.erase(cs.find(ans[i]));
		}
	}
	cout << endl;
	int ind = 0;
	while (ind < s.length())
	{
		cout << s[ind];
		if (cst.find(s[ind]) != cst.end()) ind += k;
		else ind++;
	}

	system("pause");
	return 0;
}