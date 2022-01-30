#include <iostream>
#include <map>
#include <string>
using namespace std;

bool isprime(int n)
{
	for (int i = 2; i*i <= n; i++) if (n % i == 0) return false;
	return true;
}

int main()
{
	int N;
	cin >> N;
	map<string, int> m;
	map<string, bool> mf;
	for (int i = 0; i < N; i++)
	{
		string t;
		cin >> t;
		m[t] = m.size() + 1;
		mf[t] = false;
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++)
	{
		string t;
		cin >> t;
		if (m.find(t) != m.end())
		{
			if (mf[t]) cout << t << ": Checked" << endl;
			else {
				mf[t] = true;
				switch (m[t])
				{
				case 1:
					cout << t << ": Mystery Award" << endl;
					break;
				default:
					if (isprime(m[t])) cout << t << ": Minion" << endl;
					else cout << t << ": Chocolate" << endl;
				}
			}
		}
		else cout << t << ": Are you kidding?" << endl;
	}

	system("pause");
	return 0;
}