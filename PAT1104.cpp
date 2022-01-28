#include <iostream>
using namespace std;

int main()
{
	int N;
	cin >> N;
	long double ans = 0;
	for (int i = 0; i < N; i++)
	{
		long double t;
		cin >> t;
		ans += t * (i + 1) * (N - i);
	}
	printf("%.2Lf", ans);

	system("pause");
	return 0;
}