#include <iostream>
#include <set>
#include <map>
#include <string>
using namespace std;

int main()
{
	int N;
	cin >> N;
	map<string, string> m;
	for (int i = 0; i < N; i++)
	{
		string s1, s2;
		cin >> s1 >> s2;
		m[s1] = s2;
		m[s2] = s1;
	}
	int M;
	cin >> M;
	set<string> ans;
	for (int i = 0; i < M; i++)
	{
		string t;
		cin >> t;
		if (m.find(t) != m.end())
		{
			if (ans.find(m[t]) != ans.end()) ans.erase(ans.find(m[t]));
			else ans.insert(t);
		}
		else ans.insert(t);
	}
	cout << ans.size() << endl;
	set<string>::iterator it = ans.begin();
	while (it != ans.end())
	{
		if (it != ans.begin()) cout << " ";
		cout << *it;
		it++;
	}

	system("pause");
	return 0;
}