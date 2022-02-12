#include <iostream>
#include <set>
#include <string>
using namespace std;

int main()
{
	int N, M, c = 0;
	cin >> N;
	set<string> s;
	for (int i = 0; i < N; i++)
	{
		string t;
		cin >> t;
		s.insert(t);
	}
	cin >> M;
	string age = "", iage = "", id, iid;
	for (int i = 0; i < M; i++)
	{
		string t;
		cin >> t;
		if (s.find(t) != s.end())
		{
			c++;
			if (iage.empty())
			{
				iage = t.substr(6, 8);
				iid = t;
			}
			else if (iage > t.substr(6, 8))
			{
				iage = t.substr(6, 8);
				iid = t;
			}
		}
		else if (iage.empty())
		{
			if (age.empty())
			{
				age = t.substr(6, 8);
				id = t;
			}
			else if (age > t.substr(6, 8))
			{
				age = t.substr(6, 8);
				id = t;
			}
		}
	}
	cout << c << endl;
	cout << (c ? iid : id);

	system("pause");
	return 0;
}