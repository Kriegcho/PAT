#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

bool isprime(int n)
{
	if (n <= 2) return false;
	for (int i = 2; i <= sqrt(n); i++) if (n % i == 0) return false;
	return true;
}

int getds(int n)
{
	int r = 0;
	while (n)
	{
		r += n % 10;
		n /= 10;
	}
	return r;
}

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
	if (p1.first == p2.first) return p1.second < p2.second;
	return p1.first < p2.first;
}

void DFS(string& s, int ind, int dig, int sum, int K, int m, vector<pair<int, int>>& ans)
{
	if (ind >= K || sum > m) return;
	if (sum + 9 * (K - ind - 1) < m) return; // 后续位全9都达不到m
	s[ind] = dig + '0';
	if (sum == m && ind == K - 1)
	{
		int A = stoi(s);
		int n = getds(A + 1);
		if (isprime(gcd(m, n))) ans.push_back(make_pair(n, A));
		return;
	}
	for (int i = 0; i < 10; i++) DFS(s, ind + 1, i, sum + i, K, m, ans);
}

int main()
{
	int N;
	cin >> N;
	for (int i = 1; i <= N; i++)
	{
		cout << "Case " << i << endl;
		int K, m;
		cin >> K >> m;
		vector<pair<int, int>> ans;
		string s(K, '0');
		for (int j = 1; j < 10; j++) DFS(s, 0, j, j, K, m, ans);
		sort(ans.begin(), ans.end(), cmp);
		if (ans.empty()) cout << "No Solution" << endl;
		for (int i = 0; i < ans.size(); i++) cout << ans[i].first << " " << ans[i].second << endl;
	}
	
	system("pause");
	return 0;
}