#include <iostream>
using namespace std;

bool isprime(int n)
{
	if (n <= 1) return false;
	for (int i = 2; i*i <= n; i++) if (n % i == 0) return false;
	return true;
}

int main()
{
	int N;
	cin >> N;
	if (isprime(N) && (isprime(N - 6) || isprime(N + 6)))
	{
		cout << "Yes" << endl;
		cout << (isprime(N - 6) ? N - 6 : N + 6);
	}
	else
	{
		while (!isprime(N) || !(isprime(N - 6) || isprime(N + 6))) N++;
		cout << "No" << endl;
		cout << N;
	}

	system("pause");
	return 0;
}