#include <iostream>
#include <vector>
#include <string>
using namespace std;

int GetRank(vector<int> vct, int n)
{
	int nRank = 1;
	for (int i = 0; i < vct.size(); i++)
	{
		if (vct[i] > n)
		{
			nRank++;
		}
	}
	return nRank;
}

int GetStuIndex(vector<int> vct, int nID)
{
	for (int i = 0; i < vct.size(); i++)
	{
		if (vct[i] == nID)
		{
			return i;
		}
	}
	return -1;
}

int main()
{
	vector<int> cGrades, mGrades, eGrades, aGrades;
	vector<int> vctStudentID;
	int nGrades, nStudents;
	cin >> nGrades >> nStudents;
	for (int i = 0; i < nGrades; i++)
	{
		int nID;
		cin >> nID;
		vctStudentID.push_back(nID);
		int nC, nM, nE;
		cin >> nC >> nM >> nE;
		cGrades.push_back(nC);
		mGrades.push_back(nM);
		eGrades.push_back(nE);
		int nA = (nC + nM + nE) / 3;
		aGrades.push_back(nA);
	}
	for (int i = 0; i < nStudents; i++)
	{
		int nID;
		cin >> nID;
		int nIndex = GetStuIndex(vctStudentID, nID);
		if (nIndex == -1)
		{
			cout << "N/A" << endl;
		}
		else
		{
			char cCourse[4] = { 'A', 'C', 'M', 'E' };
			int nBestRankCourse = 3;
			int nBestRank = 1;
			nBestRank = GetRank(eGrades, eGrades[nIndex]);
			int nTempRank = GetRank(mGrades, mGrades[nIndex]);
			if (nTempRank <= nBestRank)
			{
				nBestRank = nTempRank;
				nBestRankCourse = 2;
			}
			nTempRank = GetRank(cGrades, cGrades[nIndex]);
			if (nTempRank <= nBestRank)
			{
				nBestRank = nTempRank;
				nBestRankCourse = 1;
			}
			nTempRank = GetRank(aGrades, aGrades[nIndex]);
			if (nTempRank <= nBestRank)
			{
				nBestRank = nTempRank;
				nBestRankCourse = 0;
			}
			cout << nBestRank << " " << cCourse[nBestRankCourse] << endl;
		}
	}
	system("pause");
	return 0;
}