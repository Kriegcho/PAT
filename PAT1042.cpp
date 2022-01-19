#include <iostream>
#include <string>
using namespace std;

string conv(int i)
{
	if (i >= 1 && i <= 13) return "S" + to_string(i);
	else if (i >= 14 && i <= 26) return "H" + to_string(i - 13);
	else if (i >= 27 && i <= 39) return "C" + to_string(i - 26);
	else if (i >= 40 && i <= 52) return "D" + to_string(i - 39);
	else return "J" + to_string(i - 52);
}

int main()
{
	int N;
	cin >> N;
	int a[55], b[55], c[55];
	for (int i = 1; i <= 54; i++)
	{
		cin >> a[i];
		c[i] = b[i] = i;
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 1; j < 55; j++) c[a[j]] = b[j];
		for (int j = 1; j < 55; j++) b[j] = c[j];
	}
	for (int i = 1; i <= 54; i++)
	{
		if (i == 1) cout << conv(c[i]);
		else cout << " " << conv(c[i]);
	}

	system("pause");
	return 0;
}