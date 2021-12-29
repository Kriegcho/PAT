#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct TimeRecord
{
	string strTime;
	bool bOnline;
};
int arrCost[24];
typedef vector<TimeRecord*> VctTimeRecord;
typedef map<string, VctTimeRecord> MapUserRecordVct;
MapUserRecordVct mapUserRecord;

double GetDayBill(int nHour, int nMin = 0)
{
	double dDayBill = 0;
	for (int i = 0; i < nHour; i++)
	{
		dDayBill += 60 * arrCost[i];
	}
	if (nHour < 24)
	{
		dDayBill += nMin * arrCost[nHour];
	}
	return dDayBill / 100;
}

int GetTimeInt(string str)
{
	return stoi(str.substr(3, 2)) * 1440
		+ stoi(str.substr(6, 2)) * 60
		+ stoi(str.substr(9, 2));
}

double GetBill(string strBegin, string strEnd)
{
	int nD1, nH1, nM1, nD2, nH2, nM2;
	nD1 = stoi(strBegin.substr(3, 2));
	nH1 = stoi(strBegin.substr(6, 2));
	nM1 = stoi(strBegin.substr(9, 2));
	nD2 = stoi(strEnd.substr(3, 2));
	nH2 = stoi(strEnd.substr(6, 2));
	nM2 = stoi(strEnd.substr(9, 2));
	double dDayBill = GetDayBill(24, 0);
	double dBill = (nD2 - nD1) * dDayBill + GetDayBill(nH2, nM2) - GetDayBill(nH1, nM1);
	return dBill;
}

bool RecordCmp(TimeRecord* a, TimeRecord* b)
{
	return GetTimeInt(a->strTime) < GetTimeInt(b->strTime);
}

int main()
{
	for (int i = 0; i < 24; i++)
	{
		cin >> arrCost[i];
	}
	int nRecords, nMonth;
	cin >> nRecords;
	for (int i = 0; i < nRecords; i++)
	{
		string strUser, strBillTime, strStatus;
		cin >> strUser >> strBillTime >> strStatus;
		nMonth = stoi(strBillTime.substr(0, 2));
		TimeRecord* pRecord = new TimeRecord;
		pRecord->strTime = strBillTime;
		pRecord->bOnline = false;
		if (strStatus.find("on") != -1)
		{
			pRecord->bOnline = true;
		}
		MapUserRecordVct::iterator itr = mapUserRecord.find(strUser);
		if (itr != mapUserRecord.end())
		{
			itr->second.push_back(pRecord);
		}
		else
		{
			VctTimeRecord vctRecord;
			vctRecord.push_back(pRecord);
			mapUserRecord.insert(make_pair(strUser, vctRecord));
		}
	}
	for (MapUserRecordVct::iterator itr = mapUserRecord.begin(); itr != mapUserRecord.end(); itr++)
	{
		sort(itr->second.begin(), itr->second.end(), RecordCmp);
		// 剔除不合格的记录
		VctTimeRecord::iterator vctItr = itr->second.begin();
		while (vctItr != itr->second.end())
		{
			if (!(*vctItr)->bOnline)
			{
				if (*vctItr)
				{
					delete (*vctItr);
					(*vctItr) = NULL;
				}
				vctItr = itr->second.erase(vctItr);
			}
			else
			{
				VctTimeRecord::iterator itrTemp = vctItr + 1;
				if (itrTemp == itr->second.end())
				{
					if (*vctItr)
					{
						delete (*vctItr);
						(*vctItr) = NULL;
					}
					vctItr = itr->second.erase(vctItr);
				}
				else
				{
					if ((*itrTemp)->bOnline)
					{
						if (*vctItr)
						{
							delete (*vctItr);
							(*vctItr) = NULL;
						}
						vctItr = itr->second.erase(vctItr);
					}
					else
					{
						vctItr += 2;
					}
				}
			}
		}
		// 计算账单
		if (!itr->second.empty())
		{
			cout << itr->first << " ";
			printf("%02d\n", nMonth);
			vctItr = itr->second.begin();
			VctTimeRecord::iterator itrNext = vctItr + 1;
			double dTotal = 0;
			while (vctItr != itr->second.end())
			{
				cout << (*vctItr)->strTime.substr(3, 8) << " " << (*itrNext)->strTime.substr(3, 8) << " ";
				int nLastTime = GetTimeInt((*itrNext)->strTime) - GetTimeInt((*vctItr)->strTime);
				cout << nLastTime << " ";
				double dBill = GetBill((*vctItr)->strTime, (*itrNext)->strTime);
				printf("$%.2f\n", dBill);
				dTotal += dBill;
				vctItr += 2;
				if (vctItr != itr->second.end())
				{
					itrNext += 2;
				}
			}
			printf("Total amount: $%.2f\n", dTotal);
		}
		vctItr = itr->second.begin();
		while (vctItr != itr->second.end())
		{
			if (*vctItr)
			{
				delete (*vctItr);
				(*vctItr) = NULL;
			}
			vctItr = itr->second.erase(vctItr);
		}
	}
	system("pause");
	return 0;
}