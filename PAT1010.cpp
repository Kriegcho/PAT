#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int DoCharToInt(char c)
{
	if (c - 'a' >= 0)
	{
		return c - 'a' + 10;
	}
	else
	{
		return c - '0';
	}
}

long long DoStringToInt(string str, long long nRadix)
{
	long long nSum = 0;
	for (int i = 0; i < str.size(); i++)
	{
		nSum += DoCharToInt(str[i]) * pow(nRadix, str.size() - 1 - i);
	}
	if (nSum < 0)
	{
		return -1;
	}
	return nSum;
}

int SearchRadix(long long nEqual, long long nL, int nR, string str)
{
	while (nL >= nR)
	{
		long long nMid = (nL + nR) / 2;
		if (nEqual == DoStringToInt(str, nMid))
		{
			return nMid;
		}
		else if (nEqual < DoStringToInt(str, nMid) || DoStringToInt(str, nMid) < 0)
		{
			nL = nMid - 1;
		}
		else 
		{
			nR = nMid + 1;
		}
	}
	return -1;
}

int main()
{
	string str1, str2;
	cin >> str1 >> str2;
	int nTag;
	cin >> nTag;
	int nRadix;
	cin >> nRadix;
	
	if (nTag == 1)
	{
		long long nEqual = DoStringToInt(str1, nRadix);
		int nMaxDigitNum = 0;
		for (int i = 0; i < str2.size(); i++)
		{
			int nDigit = DoCharToInt(str2[i]);
			if (nDigit > nMaxDigitNum)
			{
				nMaxDigitNum = nDigit;
			}
		}
		bool bEqual = false;
		if (nEqual == 0 && nMaxDigitNum < 1)
		{
			cout << 1;
			bEqual = true;
		}
		if (!bEqual)
		{
			long long nTemp = SearchRadix(nEqual, nEqual>nMaxDigitNum + 1 ? nEqual : nMaxDigitNum + 1, nMaxDigitNum + 1, str2);
			if (nTemp == -1)
			{
				cout << "Impossible";
			}
			else
			{
				cout << nTemp;
			}
		}
	}
	else if (nTag == 2)
	{
		long long nEqual = DoStringToInt(str2, nRadix);
		int nMaxDigitNum = 0;
		for (int i = 0; i < str1.size(); i++)
		{
			int nDigit = DoCharToInt(str1[i]);
			if (nDigit > nMaxDigitNum)
			{
				nMaxDigitNum = nDigit;
			}
		}
		bool bEqual = false;
		if (nEqual == 0 && nMaxDigitNum < 1)
		{
			cout << 1;
			bEqual = true;
		}
		if (!bEqual)
		{
			long long nTemp = SearchRadix(nEqual, nEqual>nMaxDigitNum + 1? nEqual: nMaxDigitNum + 1, nMaxDigitNum + 1, str1);
			if (nTemp == -1)
			{
				cout << "Impossible";
			}
			else
			{
				cout << nTemp;
			}
		}
	}
	system("pause");
	return 0;
}