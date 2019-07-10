#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	double dOdd = 1.0;
	char c[3] = { 'W', 'T', 'L' };
	for (int i = 0; i < 3; i++)
	{
		double a[3];
		cin >> a[0] >> a[1] >> a[2];
		double dMaxOdd = 0;
		int nMaxIndex = 0;
		for (int j = 0; j < 3; j++)
		{
			if (a[j] > dMaxOdd)
			{
				dMaxOdd = a[j];
				nMaxIndex = j;
			}
		}
		cout << c[nMaxIndex] << " ";
		dOdd *= a[nMaxIndex];
	}
	double dSum = (dOdd*0.65 - 1) * 2;
	printf("%.2f", dSum);
	system("pause");
	return 0;
}