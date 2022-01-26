#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string s, t = "PAT";
	cin >> s;
	vector<int> P(s.length() + 1, 0), T(s.length() + 1, 0);
	vector<int> ap;
	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] == 'P') P[i + 1] = P[i] + 1;
		else P[i + 1] = P[i];
		if (s[s.length() - i - 1] == 'T') T[i + 1] = T[i] + 1;
		else T[i + 1] = T[i];
		if (s[i] == 'A') ap.push_back(i);
	}
	long long ans = 0;
	for (int i = 0; i < ap.size(); i++)
		ans += P[ap[i] + 1] * T[s.length() - ap[i]];
	ans %= 1000000007;
	cout << ans;

	system("pause");
	return 0;
}