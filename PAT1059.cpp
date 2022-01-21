#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isprime(long int n)
{
	long int t = sqrt(n);
	for (long int i = 2; i <= t; i++)
	{
		if (n % i == 0) return false;
	}
	return true;
}

int main()
{
	long int N;
	cin >> N;
	long int t = sqrt(N);
	long int M = N;
	if (M == 1) cout << "1=1"; // 测试点3
	else
	{
		vector<long int> ans(t + 1, 0);
		for (long int i = 2; i <= t; i++)
		{
			if (isprime(i))
			{
				while (N % i == 0)
				{
					N = N / i;
					ans[i]++;
				}
			}
		}
		cout << M << "=";
		bool f = false;
		for (long int i = 2; i <= t; i++)
		{
			if (ans[i])
			{
				if (f) cout << "*";
				cout << i;
				if (ans[i] > 1) cout << "^" << ans[i];
				f = true;
			}
		}
		if (N > 1) // 测试点4
		{
			if (f) cout << "*";
			cout << N;
		}
	}

	system("pause");
	return 0;
}