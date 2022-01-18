#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 思路：将所有输入视为字符串，类字典序(不是完全字典序，要注意前后的顺序)排序即可
string rem0(string s)
{
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) if (s[i] == '0') cnt++; else break;
	return s.substr(cnt, s.length());
}

bool cmp(string s1, string s2) // bool cmp(const string& a, const string& b) { return a + b < b + a; } 妙啊
{
	if (s1 == s2) return s1 < s2;
	else
	{
		for (int i = 0; i < s1.length() && i < s2.length(); i++)
		{
			if (s1[i] != s2[i]) return s1[i] - s2[i] < 0;
		}
		int l1 = s1.length(), l2 = s2.length();
		if (l1 < l2) return cmp(s1, s2.substr(l1, l2));
		else return cmp(s1.substr(l2, l1), s2);
	}
}

int main()
{
	int N;
	cin >> N;
	vector<string> s;
	for (int i = 0; i < N; i++)
	{
		string t;
		cin >> t;
		if (!rem0(t).empty()) s.push_back(t); // 除去纯零
	}
	sort(s.begin(), s.end(), cmp);
	string ans;
	for (int i = 0; i < s.size(); i++)
	{
		ans += s[i];
	}
	ans = rem0(ans);
	if (!ans.empty()) cout << ans;
	else cout << "0"; // 测试点2一直不过，尝试全0输出0过了。。题目又要求第一位不为0，挺迷惑的

	system("pause");
	return 0;
}