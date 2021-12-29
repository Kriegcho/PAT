#include <iostream>
#include <string>
#include <vector>
using namespace std;

int GetIntSecond(string strTime)
{
	string strH = strTime.substr(0, 2);
	string strM = strTime.substr(3, 2);
	string strS = strTime.substr(6, 2);
	return stoi(strH) * 3600 + stoi(strM) * 60 + stoi(strS);
}

int main()
{
	int nRecord;
	cin >> nRecord;
	int minIn, maxOut;
	int nIn, nOut = 0;
	vector<string> vctID;
	for (int i = 0; i < nRecord; i++)
	{
		string strID, strIn, strOut;
		cin >> strID >> strIn >> strOut;
		vctID.push_back(strID);
		if (i == 0)
		{
			minIn = GetIntSecond(strIn);
			maxOut = GetIntSecond(strOut);
		}
		else
		{
			if (GetIntSecond(strIn) < minIn)
			{
				minIn = GetIntSecond(strIn);
				nIn = i;
			}
			if (GetIntSecond(strOut) > maxOut)
			{
				maxOut = GetIntSecond(strOut);
				nOut = i;
			}
		}
	}
	cout << vctID[nIn] << " " << vctID[nOut];
	system("pause");
	return 0;
}