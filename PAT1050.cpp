#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string s1, s2;
	getline(cin, s1);
	getline(cin, s2);
	int a[128] = { 0 };
	for (int i = 0; i < s2.length(); i++)
	{
		a[s2[i]]++;
	}
	vector<char> ans;
	for (int i = 0; i < s1.length(); i++)
	{
		if (!a[s1[i]]) ans.push_back(s1[i]);
	}
	for (int i = 0; i < ans.size(); i++) cout << ans[i];

	system("pause");
	return 0;
}