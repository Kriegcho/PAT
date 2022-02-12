#include <iostream>
#include <string>
#include <cmath>
using namespace std;

bool isprime(int n)
{
	if (n < 2)return false;
	for (int i = 2; i <= sqrt(n); i++)
		if (n % i == 0) return false;
	return true;
}

int main()
{
	int L, K;
	string s;
	cin >> L >> K >> s;
	bool f = false;
	for (int i = 0; i <= L - K; i++)
		if (isprime(stoi(s.substr(i, K))))
		{
			f = true;
			cout << s.substr(i, K);
			break;
		}
	if (!f) cout << "404";

	system("pause");
	return 0;
}