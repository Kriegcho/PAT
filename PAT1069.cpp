#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int rev(int n)
{
	int r = 0;
	for (int i = 0; i < 4; i++)
	{
		r *= 10;
		r += n % 10;
		n = n / 10;
	}
	return r;
}

int main()
{
	int N;
	cin >> N;
	int M = rev(N);
	if (M == N) cout << N << " - " << N << " = 0000";
	else
	{
		bool f = true;
		int last = 0;
		while (f)
		{
			string sN = to_string(N);
			sort(sN.begin(), sN.end());
			N = stoi(sN);
			M = rev(N);
			int t = M > N ? M - N : N - M;
			if (t == last) break;
			else last = t; 
			if (M > N) printf("%04d - %04d = %04d\n", M, N, t);
			else printf("%04d - %04d = %04d\n", N, M, t);
			N = t;
		}
	}

	system("pause");
	return 0;
}