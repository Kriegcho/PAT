#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

const int maxN = 2010;
double arrMulti[maxN] = { 0 };

int main()
{
	int n1, n2;
	vector<int> exp1, exp2;
	vector<double> coe1, coe2;
	cin >> n1;
	for (int i = 0; i < n1; i++)
	{
		int nExp1;
		cin >> nExp1;
		double dCoe1;
		cin >> dCoe1;
		exp1.push_back(nExp1);
		coe1.push_back(dCoe1);
	}
	cin >> n2;
	for (int i = 0; i < n2; i++)
	{
		int nExp2;
		cin >> nExp2;
		double dCoe2;
		cin >> dCoe2;
		exp2.push_back(nExp2);
		coe2.push_back(dCoe2);
	}

	for (int i = 0; i < n1; i++)
	{
		for (int j = 0; j < n2; j++)
		{
			arrMulti[exp1[i] + exp2[j]] += coe1[i] * coe2[j];
		}
	}

	int nCount = 0;
	for (int i = 0; i < maxN; i++)
	{
		if (arrMulti[maxN - 1 - i] != 0)
		{
			nCount++;
		}
	}
	cout << nCount;
	for (int i = 0; i < maxN; i++)
	{
		if (arrMulti[maxN - 1 - i] != 0)
		{
			printf(" %d %.1f", maxN - i - 1, arrMulti[maxN - 1 - i]);
		}
	}
	system("pause");
	return 0;
}