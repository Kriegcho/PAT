#include <iostream>
#include <vector>
using namespace std;

vector<int> vct;

int main()
{
	int nCount;
	cin >> nCount;
	for (int i = 0; i < nCount; i++)
	{
		int nTemp;
		cin >> nTemp;
		vct.push_back(nTemp);
	}
	int nMax = -1, nTempSum = 0, nLeft = 0, nRight = nCount - 1, nTempLeft = 0;
	for (int i = 0; i < nCount; i++)
	{
		nTempSum += vct[i];
		if (nTempSum < 0)
		{
			nTempSum = 0;
			nTempLeft = i + 1;
		}
		else if (nTempSum > nMax)
		{
			nMax = nTempSum;
			nLeft = nTempLeft;
			nRight = i;
		}
	}
	if (nMax < 0)
	{
		nMax = 0;
	}
	cout << nMax << " " << vct[nLeft] << " " << vct[nRight];
	system("pause");
	return 0;
}