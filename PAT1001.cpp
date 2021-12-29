#include <cstdio>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int sum = a + b;
	char ans[12];

	if (abs(sum) > 999999)
	{
		sprintf(ans, "%d,%03d,%03d", sum / 1000000, (abs(sum) % 1000000) / 1000, abs(sum) % 1000);
	}
	else if (abs(sum) > 999)
	{
		sprintf(ans, "%d,%03d", sum / 1000, abs(sum % 1000));
	}
	else
	{
		sprintf(ans, "%d", sum);
	}
	cout << ans;
	system("pause");
	return 0;
}