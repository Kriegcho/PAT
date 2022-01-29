#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N;
	cin >> N;
	vector<int> d(N);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> d[i];
		sum += d[i];
	}
	sort(d.begin(), d.end());
	cout << N % 2 << " ";
	int sum1 = 0;
	for (int i = 0; i < N / 2; i++) sum1 += d[i];
	cout << sum - sum1 * 2;

	system("pause");
	return 0;
}