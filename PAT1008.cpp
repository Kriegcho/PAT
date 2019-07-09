#include "iostream"
using namespace std;

const int nUp = 6, nDown = 4, nStop = 5;

int main()
{
	int nReq;
	cin >> nReq;
	int nLastReq = 0;
	int nTotalTime = 0;
	for (int i = 0; i < nReq; i++)
	{
		int nCurReq;
		cin >> nCurReq;
		if (nCurReq > nLastReq)
		{
			nTotalTime += nStop + (nCurReq - nLastReq) * nUp;
		}
		else if (nCurReq <= nLastReq)
		{
			nTotalTime += nStop + (nLastReq - nCurReq) * nDown;
		}
		nLastReq = nCurReq;
	}
	cout << nTotalTime;
	system("pause");
	return 0;
}