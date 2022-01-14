#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	string sN, sM;
	cin >> sN;
	sM = sN;

	int f = 0;
	for (int i = sN.length() - 1; i >= 0; i--)
	{
		sM[i] = '0' + ((sN[i] - '0') * 2 + f) % 10;
		if ((sN[i] - '0') * 2 + f >= 10) f = 1;
		else f = 0;
	}
	if (sN[0] >= '5')
	{
		cout << "No" << endl;
		
		cout << "1" << sM << endl;
	}
	else
	{
		vector<int> m, n;
		m.assign(10, 0);
		n.assign(10, 0);

		for (int i = 0; i < sN.length(); i++)
		{
			n[sN[i] - '0']++;
		}
		for (int i = 0; i < sM.length(); i++)
		{
			m[sM[i] - '0']++;
		}

		bool flag = true;
		for (int i = 0; i < 10; i++)
		{
			if (m[i] != n[i])
			{
				flag = false;
			}
		}

		if (flag) cout << "Yes" << endl;
		else cout << "No" << endl;
		cout << sM << endl;
	}

	system("pause");
	return 0;
}