#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

bool isprime(int n)
{
	if (n == 1) return false; // 测试点1
	int t = sqrt(n);
	for (int i = 2; i <= t; i++) if (n % i == 0) return false;
	return true;
}

int main()
{
	int M, N;
	cin >> M >> N;
	int T = M;
	while (!isprime(T)) T++;
	vector<bool> f(T, false);
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		if (i > 0) cout << " ";
		int ind = t % T;
		int temp;
		bool flag = true;
		for (int j = 0; j < T; j++)
		{
			temp = (ind + j * j) % T;
			if (!f[temp])
			{
				f[temp] = true;
				flag = false;
				cout << temp;
				break;
			}
		}
		if (flag) cout << "-"; 
	}

	system("pause");
	return 0;
}