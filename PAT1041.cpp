#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
	int N;
	cin >> N;
	map<int, int> m;
	vector<int> ns;
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		ns.push_back(t);
		if (m.find(t) == m.end()) m[t] = 1;
		else m[t]++;
	}

	bool f = true;
	for (int i = 0; i < N; i++)
	{
		if (m[ns[i]] == 1)
		{
			cout << ns[i];
			f = false;
			break;
		}
	}
	if (f) cout << "None";

	system("pause");
	return 0;
}