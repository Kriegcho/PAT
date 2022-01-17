#include <iostream>
#include <string>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int len = s.length();
	int n1 = (len + 2) / 3;
	int n2 = len + 2 - n1 * 2;

	for (int i = 0; i < n1 - 1; i++)
	{
		cout << s[i];
		for (int j = 0; j < n2 - 2; j++)
		{
			cout << " ";
		}
		cout << s[len - 1 - i] << endl;
	}
	cout << s.substr(n1 - 1, n2) << endl;

	system("pause");
	return 0;
}