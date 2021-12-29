#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
using namespace std;

bool isPrime(int n)
{
	if (n == 0 || n == 1)
	{
		return false;
	}
	else
	{
		int nTemp = sqrt(n);
		for (int i = 2; i <= nTemp; i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}
		return true;
	}
}

int main()
{
	int nInput;
	while (cin >> nInput, nInput > 0)
	{
		int nRadix;
		cin >> nRadix;
		if (!isPrime(nInput))
		{
			cout << "No" << endl;
		}
		else
		{
			vector<int> vctDigit;
			vctDigit.push_back(nInput % nRadix);
			while (nInput / nRadix > 0)
			{
				nInput /= nRadix;
				vctDigit.push_back(nInput % nRadix);
			}
			int nReverse = 0;
			int nDigit = vctDigit.size();
			for (int i = 0; i < nDigit; i++)
			{
				nReverse += vctDigit[nDigit - 1 - i] * pow(nRadix, i);
			}
			if (isPrime(nReverse))
			{
				cout << "Yes" << endl;
			}
			else
			{
				cout << "No" << endl;
			}
		}
	}
	system("pause");
	return 0;
}