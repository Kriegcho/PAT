#include <iostream>
#include <string>
using namespace std;

int c[62] = { 0 };

int conv(char c)
{
	if (c >= '0' && c <= '9') return c - '0';
	else if (c >= 'a' && c <= 'z') return 10 + c - 'a';
	else if (c >= 'A' && c <= 'Z') return 36 + c - 'A';
}

int main()
{
	string s1, s2;
	cin >> s1 >> s2;
	for (int i = 0; i < s2.length(); i++) c[conv(s2[i])]++;
	int e = 0;
	for (int i = 0; i < s1.length(); i++)
	{
		if (c[conv(s1[i])]) c[conv(s1[i])]--;
		else e++;
	}
	int l = 0;
	for (int i = 0; i < 62; i++) l += c[i];
	if (l) cout << "No " << l;
	else cout << "Yes " << e;

	system("pause");
	return 0;
}